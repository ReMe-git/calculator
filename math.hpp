#pragma once

class MathExpression
{
	private:
	public:
		/**
		 *	初始化
		 * */
		static void Init(void);
		
		/**
		 *	转换前缀表达式为后缀表达式
		 * */
		static int expressionTranslation(const char *src);

		/**
		 *	计算后缀表达式
		 * */
		static int expressionResult(const char *src, double *res);
};
