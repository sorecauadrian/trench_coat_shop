#include "ui.h"
#include "gui.h"
#include "main_window.h"

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
/*
    FileRepository repository("../repository.txt", validator);
    repository.read_from_file();
    repository.prepare_photographs();


    HTML_Repository basket("../basket.html");
    basket.read_from_file();

    Service service(repository, &basket);
    GUI gui(service);
    gui.show();
*/
    MainWindow w;
    w.show();
    //QTimer::singleShot(0, &application, SLOT(quit()));
    return application.exec();
}