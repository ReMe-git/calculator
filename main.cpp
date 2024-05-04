#include "ui.hpp"
#include "math.hpp"

int
main(int argc, char *argv[]){
	QApplication app(argc, argv);
	MainWindow *app_window = new MainWindow();
	
	MathExpression::Init();
	app_window->show();
	return app.exec();
}

