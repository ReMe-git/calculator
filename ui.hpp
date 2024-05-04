#pragma once

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtGui/QKeyEvent>
#include <cstdio>
#include "math.hpp"



class MainWindow: public QMainWindow
{
	private:
		QWidget *mainWidget;
    		QGridLayout *gridLayout;
		QPushButton *pushButton_0;
		QPushButton *pushButton_1;
		QPushButton *pushButton_2;
		QPushButton *pushButton_3;
		QPushButton *pushButton_4;
		QPushButton *pushButton_5;
		QPushButton *pushButton_6;
		QPushButton *pushButton_7;
		QPushButton *pushButton_8;
		QPushButton *pushButton_9;
		QPushButton *pushButton_add;
		QPushButton *pushButton_sub;
		QPushButton *pushButton_mul;
		QPushButton *pushButton_div;
		QPushButton *pushButton_del;
		QPushButton *pushButton_reset;
		QPushButton *pushButton_dot;
		QPushButton *pushButton_equal;
		QPushButton *pushButton_lexpand;
		QPushButton *pushButton_rexpand;
		QPushButton *pushButton_sin;
		QPushButton *pushButton_cos;
		QPushButton *pushButton_tan;
		QPushButton *pushButton_asin;
		QPushButton *pushButton_acos;
		QPushButton *pushButton_atan;
		QPushButton *pushButton_pow;
		QPushButton *pushButton_sqrt;
		QLabel *expression;
		QLabel *result;
		
		double res;
		char info_string[1024];
		char expression_string[1024];
		char result_string[1024];
		int info_length;
		int expression_length;

		void push_info(char c)
		{
			if (info_length == 1024) return;

			info_string[info_length] = c;
			info_length++;
		}

		void pushstring_info(const char *str)
		{
			int i, len = strlen(str);

			for (i = 0; i < len; i++)
				push_info(str[i]);
		}

		void pop_info(char *ret)
		{
			if (info_length == 0) return;
			
			info_length--;
			if (ret != nullptr)
				*ret = info_string[info_length];
			info_string[info_length] = '\0';
		}


		void push_expression(char c)
		{
			if (expression_length == 1024) return;

			expression_string[expression_length] = c;
			expression_length++;
		}

		void pushstring_expression(const char *str)
		{
			int i, len = strlen(str);

			for (i = 0; i < len; i++)
				push_expression(str[i]);
		}

		void pop_expression(char *ret)
		{
			if (expression_length == 0) return;
			
			expression_length--;
			if (ret != nullptr)
				*ret = expression_string[expression_length];
			expression_string[expression_length] = '\0';
		}

		void button_0_clicked()
		{
			push_expression('0');
			push_info('0');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_1_clicked()
		{
			push_expression('1');
			push_info('1');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_2_clicked()
		{
			push_expression('2');
			push_info('2');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_3_clicked()
		{
			push_expression('3');
			push_info('3');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_4_clicked()
		{
			push_expression('4');
			push_info('4');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_5_clicked()
		{
			push_expression('5');
			push_info('5');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_6_clicked()
		{
			push_expression('6');
			push_info('6');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_7_clicked()
		{
			push_expression('7');
			push_info('7');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_8_clicked()
		{
			push_expression('8');
			push_info('8');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_9_clicked()
		{
			push_expression('9');
			push_info('9');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_dot_clicked()
		{
			push_expression('.');
			push_info('.');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_equal_clicked()
		{
			MathExpression::expressionResult(expression_string, &res);
			sprintf(result_string, "%lf", res);
			result->setText(QCoreApplication::translate("MainWidget", result_string, nullptr));
		}

		void button_add_clicked()
		{
			push_expression('+');
			push_info('+');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_sub_clicked()
		{
			push_expression('-');
			push_info('-');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_mul_clicked()
		{
			push_expression('*');
			push_info('x');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_div_clicked()
		{
			push_expression('/');
			pushstring_info("󰇔");
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_lexpand_clicked()
		{
			push_expression('(');
			push_info('(');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_rexpand_clicked()
		{
			push_expression(')');
			push_info(')');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_sin_clicked()
		{
			push_expression('s');
			pushstring_info("sin");
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_cos_clicked()
		{
			push_expression('c');
			pushstring_info("cos");
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_tan_clicked()
		{
			push_expression('t');
			pushstring_info("tan");
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_asin_clicked()
		{
			push_expression('S');
			pushstring_info("asin");
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_acos_clicked()
		{
			push_expression('C');
			pushstring_info("acos");
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_atan_clicked()
		{
			push_expression('T');
			pushstring_info("atan");
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_pow_clicked()
		{
			push_expression('^');
			push_info('^');
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}
		
		void button_sqrt_clicked()
		{
			push_expression('e');
			pushstring_info("√");
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}
		
		void button_del_clicked()
		{
			char ret = 0;

			pop_expression(&ret);
			if (ret == '/' || ret == 'e') {
				int n = strlen("󰇔");
				while (n--) pop_info(nullptr);
			} else if (ret == 's' || ret == 'c' || ret == 't') {
				pop_info(nullptr);
				pop_info(nullptr);
				pop_info(nullptr);
			} else if (ret == 'S' || ret == 'C' || ret == 'T' ) {
				pop_info(nullptr);
				pop_info(nullptr);
				pop_info(nullptr);
				pop_info(nullptr);
			}else {
				pop_info(nullptr);
			}

			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
		}

		void button_reset_clicked()
		{
			while (expression_length)
				pop_expression(nullptr);
			while (info_length)
				pop_info(nullptr);
			expression->setText(
			QCoreApplication::translate("MainWidget", info_string, nullptr));
			res = 0;
			sprintf(result_string, "%lf", res);
			result->setText(QCoreApplication::translate("MainWidget", result_string, nullptr));
		}

	protected:
		bool eventFilter(QObject *watched, QEvent *event) override
		{
			if (event->type() == QEvent::KeyPress) {
				QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
				if (keyEvent->modifiers() == Qt::ShiftModifier) {
					switch(keyEvent->key()) {
						case Qt::Key_Plus:
							button_add_clicked();
							break;
						case '*':
							button_mul_clicked();
							break;
						case '(':
							button_lexpand_clicked();
							break;
						case ')':
							button_rexpand_clicked();
							break;
						case Qt::Key_S:
							button_asin_clicked();
							break;
						case Qt::Key_C:
							button_acos_clicked();
							break;
						case Qt::Key_T:
							button_atan_clicked();
							break;
						default:
							break;
					}
				} else {
					switch(keyEvent->key()) {
						case Qt::Key_0:
							button_0_clicked();
							break;
						case Qt::Key_1:
							button_1_clicked();
							break;
						case Qt::Key_2:
							button_2_clicked();
							break;
						case Qt::Key_3:
							button_3_clicked();
							break;
						case Qt::Key_4:
							button_4_clicked();
							break;
						case Qt::Key_5:
							button_5_clicked();
							break;
						case Qt::Key_6:
							button_6_clicked();
							break;
						case Qt::Key_7:
							button_7_clicked();
							break;
						case Qt::Key_8:
							button_8_clicked();
							break;
						case Qt::Key_9:
							button_9_clicked();
							break;
						case '.':
							button_dot_clicked();
							break;
						case Qt::Key_Minus:
							button_sub_clicked();
							break;
						case '/':
							button_div_clicked();
							break;
						case Qt::Key_S:
							button_sin_clicked();
							break;
						case Qt::Key_C:
							button_cos_clicked();
							break;
						case Qt::Key_T:
							button_tan_clicked();
							break;
						case Qt::Key_P:
							button_pow_clicked();
							break;
						case Qt::Key_Q:
							button_sqrt_clicked();
							break;
						case Qt::Key_Backspace:
						case Qt::Key_Delete:
							button_del_clicked();
							break;
						case Qt::Key_Enter:
						case Qt::Key_Return:
							button_equal_clicked();
							break;
						case Qt::Key_Escape:
							button_reset_clicked();
							break;
						default:
							break;
					}
				}
			}
			return QObject::eventFilter(watched, event);
		}
	
	public:
		MainWindow();
		~MainWindow();
};

