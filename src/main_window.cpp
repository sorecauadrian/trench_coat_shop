#include "main_window.h"


MainWindow::MainWindow(QWidget *parent) : service(Service(FileRepository(FILENAME), new CSV_Repository("../basket.csv")))
{
    auto* toolbar = new QToolBar(this);
    addToolBar(toolbar);

    auto* actionAdmin = new QAction("admin mode", this);
    auto* actionUser = new QAction("user mode", this);

    toolbar->addAction(actionAdmin);
    toolbar->addAction(actionUser);

    this->setWindowTitle("trench coat shopping app");

    auto* adminWidget = new GUI(service);
    auto* userWidget = new UserWidget(service);

    auto* welcomeLabel = new QLabel("welcome! please select the credentials for the application!");
    auto* stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(welcomeLabel);
    stackedLayout->addWidget(adminWidget);
    stackedLayout->addWidget(userWidget);

    this->setLayout(stackedLayout);
    this->resize(INITIAL_WIDTH, INITIAL_HEIGHT);

    connect(actionAdmin, &QAction::triggered, this, [=]() {
        this->resize(ADMIN_WIDTH, ADMIN_HEIGHT);
        stackedLayout->setCurrentIndex(ADMIN_LAYOUT_INDEX);
    });

    connect(actionUser, &QAction::triggered, this, [=]() {
        this->resize(USER_WIDTH, USER_HEIGHT);
        stackedLayout->setCurrentIndex(USER_LAYOUT_INDEX);
    });

}
