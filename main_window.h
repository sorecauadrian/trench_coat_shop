#ifndef A89_SORECAUADRIAN_MAIN_WINDOW_H
#define A89_SORECAUADRIAN_MAIN_WINDOW_H

#include "gui.h"
#include "admin_widget.h"
#include "user_widget.h"
#include "service.h"
#include "file_repository.h"
#include "exceptions.h"
#include <qmainwindow.h>
#include <qaction.h>
#include <qtoolbar.h>
#include <qstackedlayout.h>

const std::string FILENAME = "../repository.txt";
const int INITIAL_WIDTH = 300;
const int INITIAL_HEIGHT = 300;
const int ADMIN_WIDTH = 1500;
const int ADMIN_HEIGHT = 400;
const int USER_WIDTH = 800;
const int USER_HEIGHT = 400;
const int ADMIN_LAYOUT_INDEX = 1;
const int USER_LAYOUT_INDEX = 2;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    private:
        Service service;
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override = default;
};

#endif //A89_SORECAUADRIAN_MAIN_WINDOW_H
