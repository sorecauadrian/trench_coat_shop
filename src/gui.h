#ifndef A89_SORECAUADRIAN_GUI_H
#define A89_SORECAUADRIAN_GUI_H

#include "qwidget.h"
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QVBoxLayout>
#include <qformlayout.h>
#include <qmessagebox.h>
#include <qapplication.h>
#include <QtCore>
#include "service.h"

class GUI : public QWidget
{
    private:
        Service service;
    public:
        explicit GUI(Service &service);
        ~GUI() override = default;
        QVBoxLayout* main_layout;
        QListWidget* trench_coat_list_widget;
        QLineEdit* size_line_edit;
        QLineEdit* colour_line_edit;
        QLineEdit* price_line_edit;
        QLineEdit* quantity_line_edit;
        QLineEdit* photograph_line_edit;
        QPushButton* add_button;
        QPushButton* remove_button;
        QPushButton* update_button;


    private:
        void init_GUI();
        void populate_list();
        void connect_signals_and_slots();

        [[nodiscard]] int get_selected_index() const;

        void add_trench_coat();
        void remove_trench_coat();
        void update_trench_coat();
};

#endif //A89_SORECAUADRIAN_GUI_H
