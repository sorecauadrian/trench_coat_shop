#ifndef A89_SORECAUADRIAN_ADMIN_WIDGET_H
#define A89_SORECAUADRIAN_ADMIN_WIDGET_H

#include <qwidget.h>
#include <qtablewidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <vector>
#include "trench_coat.h"

const int DEFAULT_SPACING_ADMIN = 20;
const int TABLE_COLUMN_COUNT = 5;
const int SIZE_COLUMN = 0;
const int COLOUR_COLUMN = 1;
const int PRICE_COLUMN = 2;
const int QUANTITY_COLUMN = 3;
const int PHOTOGRAPH_COLUMN = 4;
const int SIZE_COLUMN_WIDTH = 300;

class AdminWidget : public QWidget
{
    Q_OBJECT
    private:
        std::vector<TrenchCoat> trench_coats;
    public:
        explicit AdminWidget(QWidget *parent = nullptr, const std::vector<TrenchCoat>& trench_coats = {});
        QTableWidget* createTableWidget();
        ~AdminWidget() override = default;
        QHBoxLayout* createButtonsForManagingTrenchCoats();
        QHBoxLayout* createTrenchCoatSize();
        QHBoxLayout* createTrenchCoatColour();
        QHBoxLayout* createTrenchCoatPrice();
        QHBoxLayout* createTrenchCoatQuantity();
        QHBoxLayout* createTrenchCoatPhotograph();
};

#endif //A89_SORECAUADRIAN_ADMIN_WIDGET_H
