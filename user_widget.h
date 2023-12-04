#ifndef A89_SORECAUADRIAN_USER_WIDGET_H
#define A89_SORECAUADRIAN_USER_WIDGET_H

#include <qwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qformlayout.h>
#include "service.h"

const int DEFAULT_SPACING_USER = 20;

class UserWidget : public QWidget
{
private:
    Service service;
public:
    explicit UserWidget(Service &service);
    ~UserWidget() override = default;
    QVBoxLayout* main_layout;
    QListWidget* basket_type;
    QLineEdit* size_filter;
    QPushButton* filter;
    QLineEdit* size_line_edit;
    QLineEdit* colour_line_edit;
    QLineEdit* price_line_edit;
    QLineEdit* quantity_line_edit;
    QPushButton* add_button;
    QPushButton* next_button;
    QPushButton* export_button;
    std::vector<TrenchCoat> filtered_trench_coats;
    int index = 0;
    const char *file_type;

private:
    void init_UserWidget();
    void connect_signals_and_slots();
    int get_selected_index() const;

    void filter_trench_coat();
    void add_trench_coat();
    void next_trench_coat();
    void export_trench_coat();
};

#endif //A89_SORECAUADRIAN_USER_WIDGET_H
