#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "math.hpp"

#define PI 3.14159265354
#define MAX_EXPRESSION_SIZE 2048

/* 后缀表达式项类型 */
enum item_type {
	ITEM_NONE,
	ITEM_VALUE,
	ITEM_OPERATOR,
};

/* 后缀表达式项值 双浮点数或运算符 */
union value_t {
	double val;
	char opa;
};

/* 后缀表达式项结构体 */
struct item {
 	value_t value;
	unsigned char type;
};

/* 运算符类型 */
enum operator_type {
	OPERATOR_ADD = 0,
	OPERATOR_SUB,
	OPERATOR_MUL,
	OPERATOR_DIV,
	OPERATOR_LEFT,
	OPERATOR_RIGHT,
	OPERATOR_SIN,
	OPERATOR_COS,
	OPERATOR_TAN,
	OPERATOR_ASIN,
	OPERATOR_ACOS,
	OPERATOR_ATAN,
	OPERATOR_POW,
	OPERATOR_SQRT,
	OPERATOR_STOP,
	OPERATOR_NONE,
};

enum rule {
	RULE_NONE = 0,
	RULE_BIG,
	RULE_SMALL,
	RULE_EQUAL,
};

/* 储存后缀表达式的数组 */
static struct item items[MAX_EXPRESSION_SIZE];
static int item_length;
static unsigned char operators[256];
/* 优先级查询表 */
static unsigned char rule[15][15] = 
{	//   +         -         *  	     /           (           )         sin         cos         tan         asin        acos        atan        power       evolution   #
	{RULE_BIG, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_BIG}, // +
	{RULE_BIG, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_BIG}, // -
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL,RULE_BIG}, // *
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL,RULE_SMALL, RULE_SMALL, RULE_BIG}, // /
	{RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_EQUAL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_NONE}, // (
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_NONE, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG}, // )
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_BIG}, // sin
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_BIG}, // cos
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_BIG}, // tan
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_BIG}, // asin
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_BIG}, // acos
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_SMALL, RULE_BIG}, // atan
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG}, // pow
	{RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_SMALL, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG, RULE_BIG}, // sqrt
	{RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_NONE, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_SMALL, RULE_EQUAL}, // #
};

/**
 *	是否是合法的后缀表达式项类型
 * */
#define ISITEMTYPE(type) (type == ITEM_VALUE || type == ITEM_OPERATOR)

/**
 *	是否是数字或者小数点和负号
 * */
#define ISDIGIT(c) (isdigit(c) || c == '.')

/**
 *	运算是否只需要一个数字
 * */ 
#define ISONEOPERATOR(opa) (opa == 's' || opa == 'c' || opa == 't' \
		|| opa == 'S' || opa == 'C' || opa == 'T' || opa == 'e')


/**
 *	初始化
 * */
void
MathExpression::Init(void)
{
	item_length = 0;
	memset(operators, OPERATOR_NONE, 256);
	operators[(int)'+'] = OPERATOR_ADD;
	operators[(int)'-'] = OPERATOR_SUB;
	operators[(int)'*'] = OPERATOR_MUL;
	operators[(int)'/'] = OPERATOR_DIV;
	operators[(int)'('] = OPERATOR_LEFT;
	operators[(int)')'] = OPERATOR_RIGHT;
	operators[(int)'s'] = OPERATOR_SIN;
	operators[(int)'c'] = OPERATOR_COS;
	operators[(int)'t'] = OPERATOR_TAN;
	operators[(int)'S'] = OPERATOR_ASIN;
	operators[(int)'C'] = OPERATOR_ACOS;
	operators[(int)'T'] = OPERATOR_ATAN;
	operators[(int)'^'] = OPERATOR_POW;
	operators[(int)'e'] = OPERATOR_SQRT;
	operators[(int)'#'] = OPERATOR_STOP;
}

/**
 *	添加后缀表达式项
 * */
static void
append_item(unsigned char type, value_t value)
{
	if (item_length == MAX_EXPRESSION_SIZE || !ISITEMTYPE(type))
		return;

	items[item_length].type = type;
	if (type == ITEM_VALUE) {
		items[item_length].value.val = value.val;
	} else { 
		items[item_length].value.opa = value.opa;
	}
	item_length++;
}

/**
 *	比较两个运算符的优先级
 * */
static int
operator_cmp(char first, char second)
{
	int ftype,stype;

	ftype = operators[(int)first];
	stype = operators[(int)second];
	if (ftype == OPERATOR_NONE || stype == OPERATOR_NONE) return 0;
	else return rule[ftype][stype];
}

/**
 *	转换中缀表达式为后缀表达式
 * */
int
MathExpression::expressionTranslation(const char *src)
{
	int i, len, top;
	char *digit_start;
	static char tmpstack[MAX_EXPRESSION_SIZE], expression[MAX_EXPRESSION_SIZE];
	value_t tmp;
	bool digit = false;
	
	if ((len = strlen(src)) >= MAX_EXPRESSION_SIZE) return 1;
	strncpy(expression, src, len);
	expression[len] = '#'; expression[len + 1] = '\0';
	tmpstack[0] = '#'; top = 1;
	item_length = 0;
	for (i = 0; i <= len; i++)
	{
		if (ISDIGIT(expression[i]) || (!digit && expression[i] == '-')) {
			if (digit) continue;
			digit = true;
			digit_start = (char *)&expression[i];
		} else {
			if (digit) {
				tmp.val = strtod(digit_start, nullptr);
				append_item(ITEM_VALUE, tmp);
				digit = false;
			}

			if (ISONEOPERATOR(expression[i]) && i > 0 &&
					ISDIGIT(expression[i - 1]))
				return 1;
deal_operator:
			switch (operator_cmp(tmpstack[top - 1], expression[i])) {
				case RULE_SMALL:
					tmpstack[top] = expression[i];
					if (top < MAX_EXPRESSION_SIZE) top += 1;
					continue;
				case RULE_BIG:
					if (top > 0) top -= 1;
					tmp.opa = tmpstack[top];
					append_item(ITEM_OPERATOR, tmp);
					goto deal_operator;
				case RULE_EQUAL:
					if (expression[i] == '#') return 0;
					else if (top > 0) top-= 1;
					continue;
				case RULE_NONE:
				default:
					return 1;
			} 
		}
	}
	return 1;
}

/**
 *	计算后缀表达式的结果
 * */
int
MathExpression::expressionResult(const char *src, double *res)
{
	*res = 0;
	if (expressionTranslation(src)) return 1;

	static double tmpstack[MAX_EXPRESSION_SIZE];
	int i, top = 0;
	
	for (i = 0; i < item_length; i++) {
		if (items[i].type == ITEM_VALUE) {
			tmpstack[top] = items[i].value.val;
			if (top < MAX_EXPRESSION_SIZE ) top += 1;
		} else {
			double x1, x2 = 0;

			if (ISONEOPERATOR(items[i].value.opa)) {
				if (top - 1 < 0) return 1;
				top -= 1;
				x1 = tmpstack[top];
			} else {
				if (top - 2 < 0) return 1;
				top -= 1;
				x2 = tmpstack[top];
				top -= 1;
				x1 = tmpstack[top];
			}

			switch(items[i].value.opa){
				case '+':
					x1 = x1 + x2;
					break;
				case '-':
					x1 = x1 - x2;
					break;
				case '*':
					x1 = x1 * x2;
					break;
				case '/':
					if (x2 == 0) return 1;
					x1 = x1 / x2;
					break;
				case 's':
					x1 = sin(x1 / 180 * PI);
					break;
				case 'c':
					x1 = cos(x1 / 180 * PI);
					break;
				case 't':
					x1 = tan(x1 / 180 * PI);
					break;
				case 'S':
					x1 = asin(x1);
					break;
				case 'C':
					x1 = acos(x1);
					break;
				case 'T':
					x1 = atan(x1);
					break;
				case '^':
					x1 = pow(x1, x2);
					break;
				case 'e':
					x1 = sqrt(x1);
					break;
				default:
					return 1;
			}
			tmpstack[top] = x1; top += 1;
		}
	}

	if (top != 1) return 1;
	*res = tmpstack[0]; return 0;
}
