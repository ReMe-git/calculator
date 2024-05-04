#include "ui.hpp"

MainWindow::MainWindow()
: QMainWindow()
{
	memset(info_string, 0, 1024);
	memset(expression_string, 0, 1024);
	memset(result_string, 0, 1024);
	info_length = 0;
	expression_length = 0;
	res = 0;
	
	this->setStyleSheet(QString::fromUtf8("background-color:black;\ncolor:white;"));
	mainWidget = new QWidget(this);
	mainWidget->setObjectName(QString::fromUtf8("MainWidget"));
	this->setCentralWidget(mainWidget);
	mainWidget->installEventFilter(this);
	/* gridLayout init */
	gridLayout = new QGridLayout(mainWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
	
	QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);

	/* button 0 init */
	pushButton_0 = new QPushButton(mainWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setEnabled(true);
        QSizePolicy sizePolicy_0(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_0.setHorizontalStretch(0);
        sizePolicy_0.setVerticalStretch(0);
        sizePolicy_0.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy_0);
        pushButton_0->setMinimumSize(QSize(0, 0));
        pushButton_0->setFont(font);
        pushButton_0->setText(QCoreApplication::translate("MainWidget", "0", nullptr));
        gridLayout->addWidget(pushButton_0, 7, 0, 1, 1);
	connect(pushButton_0, &QPushButton::clicked, this, &MainWindow::button_0_clicked);

	/* button dot init */
	pushButton_dot = new QPushButton(mainWidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_0->setEnabled(true);
        QSizePolicy sizePolicy_dot(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_dot.setHorizontalStretch(0);
        sizePolicy_dot.setVerticalStretch(0);
        sizePolicy_dot.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy_dot);
        pushButton_dot->setMinimumSize(QSize(0, 0));
        pushButton_dot->setFont(font);
        pushButton_dot->setText(QCoreApplication::translate("MainWidget", "●", nullptr));
        gridLayout->addWidget(pushButton_dot, 7, 1, 1, 1);	
	connect(pushButton_dot, &QPushButton::clicked, this, &MainWindow::button_dot_clicked);

	/* button 1 init */
	pushButton_1 = new QPushButton(mainWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setEnabled(true);
        QSizePolicy sizePolicy_1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_1.setHorizontalStretch(0);
        sizePolicy_1.setVerticalStretch(0);
        sizePolicy_1.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy_1);
        pushButton_1->setMinimumSize(QSize(0, 0));
        pushButton_1->setFont(font);
        pushButton_1->setText(QCoreApplication::translate("MainWidget", "1", nullptr));
        gridLayout->addWidget(pushButton_1, 6, 0, 1, 1);
	connect(pushButton_1, &QPushButton::clicked, this, &MainWindow::button_1_clicked);

	/* button 2 init */
	pushButton_2 = new QPushButton(mainWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        QSizePolicy sizePolicy_2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_2.setHorizontalStretch(0);
        sizePolicy_2.setVerticalStretch(0);
        sizePolicy_2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy_2);
        pushButton_2->setMinimumSize(QSize(0, 0));
        pushButton_2->setFont(font);
        pushButton_2->setText(QCoreApplication::translate("MainWidget", "2", nullptr));
        gridLayout->addWidget(pushButton_2, 6, 1, 1, 1);
	connect(pushButton_2, &QPushButton::clicked, this, &MainWindow::button_2_clicked);
	
	/* button 3 init */
	pushButton_3 = new QPushButton(mainWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(true);
        QSizePolicy sizePolicy_3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_3.setHorizontalStretch(0);
        sizePolicy_3.setVerticalStretch(0);
        sizePolicy_3.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy_3);
        pushButton_3->setMinimumSize(QSize(0, 0));
        pushButton_3->setFont(font);
        pushButton_3->setText(QCoreApplication::translate("MainWidget", "3", nullptr));
        gridLayout->addWidget(pushButton_3, 6, 2, 1, 1);
	connect(pushButton_3, &QPushButton::clicked, this, &MainWindow::button_3_clicked);

	/* button 4 init */
	pushButton_4 = new QPushButton(mainWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(true);
        QSizePolicy sizePolicy_4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_4.setHorizontalStretch(0);
        sizePolicy_4.setVerticalStretch(0);
        sizePolicy_4.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy_4);
        pushButton_4->setMinimumSize(QSize(0, 0));
        pushButton_4->setFont(font);
        pushButton_4->setText(QCoreApplication::translate("MainWidget", "4", nullptr));
        gridLayout->addWidget(pushButton_4, 5, 0, 1, 1);
	connect(pushButton_4, &QPushButton::clicked, this, &MainWindow::button_4_clicked);

	/* button 5 init */
	pushButton_5 = new QPushButton(mainWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(true);
        QSizePolicy sizePolicy_5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_5.setHorizontalStretch(0);
        sizePolicy_5.setVerticalStretch(0);
        sizePolicy_5.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy_5);
        pushButton_5->setMinimumSize(QSize(0, 0));
        pushButton_5->setFont(font);
        pushButton_5->setText(QCoreApplication::translate("MainWidget", "5", nullptr));
        gridLayout->addWidget(pushButton_5, 5, 1, 1, 1);
	connect(pushButton_5, &QPushButton::clicked, this, &MainWindow::button_5_clicked);

	/* button 6 init */
	pushButton_6 = new QPushButton(mainWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setEnabled(true);
        QSizePolicy sizePolicy_6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_6.setHorizontalStretch(0);
        sizePolicy_6.setVerticalStretch(0);
        sizePolicy_6.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy_6);
        pushButton_6->setMinimumSize(QSize(0, 0));
        pushButton_6->setFont(font);
        pushButton_6->setText(QCoreApplication::translate("MainWidget", "6", nullptr));
        gridLayout->addWidget(pushButton_6, 5, 2, 1, 1);
	connect(pushButton_6, &QPushButton::clicked, this, &MainWindow::button_6_clicked);

	/* button 7 init */
	pushButton_7 = new QPushButton(mainWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setEnabled(true);
        QSizePolicy sizePolicy_7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_7.setHorizontalStretch(0);
        sizePolicy_7.setVerticalStretch(0);
        sizePolicy_7.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy_7);
        pushButton_7->setMinimumSize(QSize(0, 0));
        pushButton_7->setFont(font);
        pushButton_7->setText(QCoreApplication::translate("MainWidget", "7", nullptr));
        gridLayout->addWidget(pushButton_7, 4, 0, 1, 1);
	connect(pushButton_7, &QPushButton::clicked, this, &MainWindow::button_7_clicked);

	/* button 8 init */
	pushButton_8 = new QPushButton(mainWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setEnabled(true);
        QSizePolicy sizePolicy_8(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_8.setHorizontalStretch(0);
        sizePolicy_8.setVerticalStretch(0);
        sizePolicy_8.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy_8);
        pushButton_8->setMinimumSize(QSize(0, 0));
        pushButton_8->setFont(font);
        pushButton_8->setText(QCoreApplication::translate("MainWidget", "8", nullptr));
        gridLayout->addWidget(pushButton_8, 4, 1, 1, 1);
	connect(pushButton_8, &QPushButton::clicked, this, &MainWindow::button_8_clicked);

	/* button 9 init */
	pushButton_9 = new QPushButton(mainWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setEnabled(true);
        QSizePolicy sizePolicy_9(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_9.setHorizontalStretch(0);
        sizePolicy_9.setVerticalStretch(0);
        sizePolicy_9.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy_9);
        pushButton_9->setMinimumSize(QSize(0, 0));
        pushButton_9->setFont(font);
        pushButton_9->setText(QCoreApplication::translate("MainWidget", "9", nullptr));
        gridLayout->addWidget(pushButton_9, 4, 2, 1, 1);
	connect(pushButton_9, &QPushButton::clicked, this, &MainWindow::button_9_clicked);

	/* button equal init */
	pushButton_equal = new QPushButton(mainWidget);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        pushButton_equal->setEnabled(true);
        QSizePolicy sizePolicy_equal(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_equal.setHorizontalStretch(0);
        sizePolicy_equal.setVerticalStretch(0);
        sizePolicy_equal.setHeightForWidth(pushButton_equal->sizePolicy().hasHeightForWidth());
        pushButton_equal->setSizePolicy(sizePolicy_equal);
        pushButton_equal->setMinimumSize(QSize(0, 0));
        pushButton_equal->setFont(font);
        pushButton_equal->setText(QCoreApplication::translate("MainWidget", "=", nullptr));
        gridLayout->addWidget(pushButton_equal, 7, 4, 1, 1);
	connect(pushButton_equal, &QPushButton::clicked, this, &MainWindow::button_equal_clicked);

	/* button add init */
	pushButton_add = new QPushButton(mainWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setEnabled(true);
        QSizePolicy sizePolicy_add(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_add.setHorizontalStretch(0);
        sizePolicy_add.setVerticalStretch(0);
        sizePolicy_add.setHeightForWidth(pushButton_add->sizePolicy().hasHeightForWidth());
        pushButton_add->setSizePolicy(sizePolicy_add);
        pushButton_add->setMinimumSize(QSize(0, 0));
        pushButton_add->setFont(font);
        pushButton_add->setText(QCoreApplication::translate("MainWidget", "+", nullptr));
        gridLayout->addWidget(pushButton_add, 6, 3, 1, 1);
	connect(pushButton_add, &QPushButton::clicked, this, &MainWindow::button_add_clicked);

	/* button sub init */
	pushButton_sub = new QPushButton(mainWidget);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setEnabled(true);
        QSizePolicy sizePolicy_sub(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_sub.setHorizontalStretch(0);
        sizePolicy_sub.setVerticalStretch(0);
        sizePolicy_sub.setHeightForWidth(pushButton_sub->sizePolicy().hasHeightForWidth());
        pushButton_sub->setSizePolicy(sizePolicy_sub);
        pushButton_sub->setMinimumSize(QSize(0, 0));
        pushButton_sub->setFont(font);
        pushButton_sub->setText(QCoreApplication::translate("MainWidget", "-", nullptr));
        gridLayout->addWidget(pushButton_sub, 6, 4, 1, 1);
	connect(pushButton_sub, &QPushButton::clicked, this, &MainWindow::button_sub_clicked);

	/* button mul init */
	pushButton_mul = new QPushButton(mainWidget);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setEnabled(true);
        QSizePolicy sizePolicy_mul(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_mul.setHorizontalStretch(0);
        sizePolicy_mul.setVerticalStretch(0);
        sizePolicy_mul.setHeightForWidth(pushButton_mul->sizePolicy().hasHeightForWidth());
        pushButton_mul->setSizePolicy(sizePolicy_mul);
        pushButton_mul->setMinimumSize(QSize(0, 0));
        pushButton_mul->setFont(font);
        pushButton_mul->setText(QCoreApplication::translate("MainWidget", "x", nullptr));
        gridLayout->addWidget(pushButton_mul, 5, 3, 1, 1);
	connect(pushButton_mul, &QPushButton::clicked, this, &MainWindow::button_mul_clicked);

	/* button div init */
	pushButton_div = new QPushButton(mainWidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setEnabled(true);
        QSizePolicy sizePolicy_div(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_div.setHorizontalStretch(0);
        sizePolicy_div.setVerticalStretch(0);
        sizePolicy_div.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
        pushButton_div->setSizePolicy(sizePolicy_div);
        pushButton_div->setMinimumSize(QSize(0, 0));
        pushButton_div->setFont(font);
        pushButton_div->setText(QCoreApplication::translate("MainWidget", "󰇔", nullptr));
        gridLayout->addWidget(pushButton_div, 5, 4, 1, 1);
	connect(pushButton_div, &QPushButton::clicked, this, &MainWindow::button_div_clicked);

	/* button delete init */
	pushButton_del = new QPushButton(mainWidget);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setEnabled(true);
        QSizePolicy sizePolicy_del(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_del.setHorizontalStretch(0);
        sizePolicy_del.setVerticalStretch(0);
        sizePolicy_del.setHeightForWidth(pushButton_del->sizePolicy().hasHeightForWidth());
        pushButton_del->setSizePolicy(sizePolicy_del);
        pushButton_del->setMinimumSize(QSize(0, 0));
        pushButton_del->setFont(font);
        pushButton_del->setText(QCoreApplication::translate("MainWidget", "DEL", nullptr));
        gridLayout->addWidget(pushButton_del, 4, 3, 1, 1);
	connect(pushButton_del, &QPushButton::clicked, this, &MainWindow::button_del_clicked);
	
	/* button reset init */
	pushButton_reset = new QPushButton(mainWidget);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        pushButton_reset->setEnabled(true);
        QSizePolicy sizePolicy_reset(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_reset.setHorizontalStretch(0);
        sizePolicy_reset.setVerticalStretch(0);
        sizePolicy_reset.setHeightForWidth(pushButton_reset->sizePolicy().hasHeightForWidth());
        pushButton_reset->setSizePolicy(sizePolicy_reset);
        pushButton_reset->setMinimumSize(QSize(0, 0));
        pushButton_reset->setFont(font);
        pushButton_reset->setText(QCoreApplication::translate("MainWidget", "AC", nullptr));
        gridLayout->addWidget(pushButton_reset, 4, 4, 1, 1);
	connect(pushButton_reset, &QPushButton::clicked, this, &MainWindow::button_reset_clicked);

	/* button sin init */
	pushButton_sin = new QPushButton(mainWidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setEnabled(true);
        QSizePolicy sizePolicy_sin(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_sin.setHorizontalStretch(0);
        sizePolicy_sin.setVerticalStretch(0);
        sizePolicy_sin.setHeightForWidth(pushButton_sin->sizePolicy().hasHeightForWidth());
        pushButton_sin->setSizePolicy(sizePolicy_sin);
        pushButton_sin->setMinimumSize(QSize(0, 0));
        pushButton_sin->setFont(font);
        pushButton_sin->setText(QCoreApplication::translate("MainWidget", "sin", nullptr));
        gridLayout->addWidget(pushButton_sin, 3, 0, 1, 1);
	connect(pushButton_sin, &QPushButton::clicked, this, &MainWindow::button_sin_clicked);
	
	/* button cos init */
	pushButton_cos = new QPushButton(mainWidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setEnabled(true);
        QSizePolicy sizePolicy_cos(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_cos.setHorizontalStretch(0);
        sizePolicy_cos.setVerticalStretch(0);
        sizePolicy_cos.setHeightForWidth(pushButton_cos->sizePolicy().hasHeightForWidth());
        pushButton_cos->setSizePolicy(sizePolicy_cos);
        pushButton_cos->setMinimumSize(QSize(0, 0));
        pushButton_cos->setFont(font);
        pushButton_cos->setText(QCoreApplication::translate("MainWidget", "cos", nullptr));
        gridLayout->addWidget(pushButton_cos, 3, 1, 1, 1);
	connect(pushButton_cos, &QPushButton::clicked, this, &MainWindow::button_cos_clicked);
	
	/* button tan init */
	pushButton_tan = new QPushButton(mainWidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setEnabled(true);
        QSizePolicy sizePolicy_tan(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_tan.setHorizontalStretch(0);
        sizePolicy_tan.setVerticalStretch(0);
        sizePolicy_tan.setHeightForWidth(pushButton_tan->sizePolicy().hasHeightForWidth());
        pushButton_tan->setSizePolicy(sizePolicy_tan);
        pushButton_tan->setMinimumSize(QSize(0, 0));
        pushButton_tan->setFont(font);
        pushButton_tan->setText(QCoreApplication::translate("MainWidget", "tan", nullptr));
        gridLayout->addWidget(pushButton_tan, 3, 2, 1, 1);
	connect(pushButton_tan, &QPushButton::clicked, this, &MainWindow::button_tan_clicked);

	/* button asin init */
	pushButton_asin = new QPushButton(mainWidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setEnabled(true);
        QSizePolicy sizePolicy_asin(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_asin.setHorizontalStretch(0);
        sizePolicy_asin.setVerticalStretch(0);
        sizePolicy_asin.setHeightForWidth(pushButton_asin->sizePolicy().hasHeightForWidth());
        pushButton_asin->setSizePolicy(sizePolicy_asin);
        pushButton_asin->setMinimumSize(QSize(0, 0));
        pushButton_asin->setFont(font);
        pushButton_asin->setText(QCoreApplication::translate("MainWidget", "asin", nullptr));
        gridLayout->addWidget(pushButton_asin, 2, 0, 1, 1);
	connect(pushButton_asin, &QPushButton::clicked, this, &MainWindow::button_asin_clicked);
	
	/* button acos init */
	pushButton_acos = new QPushButton(mainWidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setEnabled(true);
        QSizePolicy sizePolicy_acos(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_acos.setHorizontalStretch(0);
        sizePolicy_acos.setVerticalStretch(0);
        sizePolicy_acos.setHeightForWidth(pushButton_acos->sizePolicy().hasHeightForWidth());
        pushButton_acos->setSizePolicy(sizePolicy_acos);
        pushButton_acos->setMinimumSize(QSize(0, 0));
        pushButton_acos->setFont(font);
        pushButton_acos->setText(QCoreApplication::translate("MainWidget", "acos", nullptr));
        gridLayout->addWidget(pushButton_acos, 2, 1, 1, 1);
	connect(pushButton_acos, &QPushButton::clicked, this, &MainWindow::button_acos_clicked);
	
	/* button atan init */
	pushButton_atan = new QPushButton(mainWidget);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setEnabled(true);
        QSizePolicy sizePolicy_atan(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_atan.setHorizontalStretch(0);
        sizePolicy_atan.setVerticalStretch(0);
        sizePolicy_atan.setHeightForWidth(pushButton_atan->sizePolicy().hasHeightForWidth());
        pushButton_atan->setSizePolicy(sizePolicy_atan);
        pushButton_atan->setMinimumSize(QSize(0, 0));
        pushButton_atan->setFont(font);
        pushButton_atan->setText(QCoreApplication::translate("MainWidget", "atan", nullptr));
        gridLayout->addWidget(pushButton_atan, 2, 2, 1, 1);
	connect(pushButton_atan, &QPushButton::clicked, this, &MainWindow::button_atan_clicked);

	/* button atan init */
	pushButton_pow = new QPushButton(mainWidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setEnabled(true);
        QSizePolicy sizePolicy_pow(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_pow.setHorizontalStretch(0);
        sizePolicy_pow.setVerticalStretch(0);
        sizePolicy_pow.setHeightForWidth(pushButton_pow->sizePolicy().hasHeightForWidth());
        pushButton_pow->setSizePolicy(sizePolicy_pow);
        pushButton_pow->setMinimumSize(QSize(0, 0));
        pushButton_pow->setFont(font);
        pushButton_pow->setText(QCoreApplication::translate("MainWidget", "^", nullptr));
        gridLayout->addWidget(pushButton_pow, 2, 3, 1, 1);
	connect(pushButton_pow, &QPushButton::clicked, this, &MainWindow::button_pow_clicked);
	
	/* button atan init */
	pushButton_sqrt = new QPushButton(mainWidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setEnabled(true);
        QSizePolicy sizePolicy_sqrt(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_sqrt.setHorizontalStretch(0);
        sizePolicy_sqrt.setVerticalStretch(0);
        sizePolicy_sqrt.setHeightForWidth(pushButton_sqrt->sizePolicy().hasHeightForWidth());
        pushButton_sqrt->setSizePolicy(sizePolicy_sqrt);
        pushButton_sqrt->setMinimumSize(QSize(0, 0));
        pushButton_sqrt->setFont(font);
        pushButton_sqrt->setText(QCoreApplication::translate("MainWidget", "√", nullptr));
        gridLayout->addWidget(pushButton_sqrt, 2, 4, 1, 1);
	connect(pushButton_sqrt, &QPushButton::clicked, this, &MainWindow::button_sqrt_clicked);

	/* button lexpand init */
	pushButton_lexpand = new QPushButton(mainWidget);
        pushButton_lexpand->setObjectName(QString::fromUtf8("pushButton_lexpand"));
        pushButton_lexpand->setEnabled(true);
        QSizePolicy sizePolicy_lexpand(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_lexpand.setHorizontalStretch(0);
        sizePolicy_lexpand.setVerticalStretch(0);
        sizePolicy_lexpand.setHeightForWidth(pushButton_lexpand->sizePolicy().hasHeightForWidth());
        pushButton_lexpand->setSizePolicy(sizePolicy_lexpand);
        pushButton_lexpand->setMinimumSize(QSize(0, 0));
        pushButton_lexpand->setFont(font);
        pushButton_lexpand->setText(QCoreApplication::translate("MainWidget", "(", nullptr));
        gridLayout->addWidget(pushButton_lexpand, 3, 3, 1, 1);
	connect(pushButton_lexpand, &QPushButton::clicked, this, &MainWindow::button_lexpand_clicked);

	/* button lexpand init */
	pushButton_rexpand = new QPushButton(mainWidget);
        pushButton_rexpand->setObjectName(QString::fromUtf8("pushButton_rexpand"));
        pushButton_rexpand->setEnabled(true);
        QSizePolicy sizePolicy_rexpand(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_rexpand.setHorizontalStretch(0);
        sizePolicy_rexpand.setVerticalStretch(0);
        sizePolicy_rexpand.setHeightForWidth(pushButton_rexpand->sizePolicy().hasHeightForWidth());
        pushButton_rexpand->setSizePolicy(sizePolicy_rexpand);
        pushButton_rexpand->setMinimumSize(QSize(0, 0));
        pushButton_rexpand->setFont(font);
        pushButton_rexpand->setText(QCoreApplication::translate("MainWidget", ")", nullptr));
        gridLayout->addWidget(pushButton_rexpand, 3, 4, 1, 1);
	connect(pushButton_rexpand, &QPushButton::clicked, this, &MainWindow::button_rexpand_clicked);

	/* result result init */
        result = new QLabel(mainWidget);
        result->setObjectName(QString::fromUtf8("result"));
        QSizePolicy sizePolicy_result(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_result.setHeightForWidth(result->sizePolicy().hasHeightForWidth());
        result->setSizePolicy(sizePolicy_reset);
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setUnderline(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        result->setFont(font2);
        result->setLayoutDirection(Qt::LeftToRight);
        result->setAutoFillBackground(true);
        result->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        result->setMargin(5);
        result->setIndent(0);
	sprintf(result_string, "%lf", res);
        result->setText(QCoreApplication::translate("MainWidget", result_string, nullptr));
	result->setStyleSheet(QString::fromUtf8("color:lightgreen;"));
        gridLayout->addWidget(result, 1, 0, 1, 5);
	
	/* expression label init */
        expression = new QLabel(mainWidget);
        expression->setObjectName(QString::fromUtf8("expression"));
        QSizePolicy sizePolicy_expression(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_expression.setHeightForWidth(expression->sizePolicy().hasHeightForWidth());
        expression->setSizePolicy(sizePolicy_expression);
        QFont font3;
        font3.setPointSize(36);
        font3.setBold(false);
        font3.setWeight(50);
        expression->setFont(font3);
        expression->setLayoutDirection(Qt::LeftToRight);
        expression->setAutoFillBackground(true);
        expression->setAlignment(Qt::AlignRight|Qt::AlignBottom|Qt::AlignTrailing);
        expression->setWordWrap(false);
        expression->setMargin(5);
        expression->setIndent(0);
        expression->setText(QCoreApplication::translate("MainWidget", "", nullptr));
	expression->setStyleSheet(QString::fromUtf8("color:lightgreen;"));
        gridLayout->addWidget(expression, 0, 0, 1, 5);	
}

MainWindow::~MainWindow(){
}
