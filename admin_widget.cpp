#include "admin_widget.h"

AdminWidget::AdminWidget(QWidget *parent, const std::vector<TrenchCoat>& trench_coats)
{
    auto* adminLayout = new QHBoxLayout();
    auto* trenchCoatInformation = new QVBoxLayout();

    auto* trench_coat_size_group = createTrenchCoatSize();
    auto* trench_coat_colour_group = createTrenchCoatColour();
    auto* trench_coat_price_group = createTrenchCoatPrice();
    auto* trench_coat_quantity_group = createTrenchCoatQuantity();
    auto* trench_coat_photograph_group = createTrenchCoatPhotograph();
    auto* buttons = createButtonsForManagingTrenchCoats();

    trenchCoatInformation->setSpacing(DEFAULT_SPACING_ADMIN);
    trenchCoatInformation->addLayout(trench_coat_size_group);
    trenchCoatInformation->addLayout(trench_coat_colour_group);
    trenchCoatInformation->addLayout(trench_coat_price_group);
    trenchCoatInformation->addLayout(trench_coat_quantity_group);
    trenchCoatInformation->addLayout(trench_coat_photograph_group);

    trenchCoatInformation->addLayout(buttons);

    adminLayout->addLayout(trenchCoatInformation);

    QTableWidget *tableWidget = this -> createTableWidget();

    adminLayout ->addWidget(tableWidget);
    this ->setLayout(adminLayout);
}

QTableWidget *AdminWidget::createTableWidget()
{
    auto* tableWidget = new QTableWidget();
    QStringList header = {"size", "colour", "price", "quantity", "photograph"};
    tableWidget->setColumnCount(TABLE_COLUMN_COUNT);
    tableWidget->setColumnWidth(SIZE_COLUMN, SIZE_COLUMN_WIDTH);
    tableWidget->setHorizontalHeaderLabels(header);
    for (const auto& trench_coat : this -> trench_coats)
    {
        int rowCount = tableWidget -> rowCount();
        tableWidget ->insertRow(rowCount);
        tableWidget->setItem(rowCount, SIZE_COLUMN, new QTableWidgetItem(QString::fromStdString((trench_coat.get_size()))));
        tableWidget->setItem(rowCount, COLOUR_COLUMN, new QTableWidgetItem(QString::fromStdString((trench_coat.get_colour()))));
        tableWidget->setItem(rowCount, PRICE_COLUMN, new QTableWidgetItem(QString::number((trench_coat.get_price()))));
        tableWidget->setItem(rowCount, QUANTITY_COLUMN, new QTableWidgetItem(QString::number((trench_coat.get_quantity()))));
        tableWidget->setItem(rowCount, PHOTOGRAPH_COLUMN, new QTableWidgetItem(QString::fromStdString((trench_coat.get_photograph()))));
    }
    return tableWidget;
}

QHBoxLayout *AdminWidget::createButtonsForManagingTrenchCoats() {
    auto *buttons = new QHBoxLayout();
    auto *addTrenchCoat = new QPushButton("add trench coat", this);
    auto *removeTrenchCoat = new QPushButton("remove trench coat", this);
    auto *updateTrenchCoat = new QPushButton("update trench coat", this);

    buttons ->addWidget(addTrenchCoat);
    buttons ->addWidget(removeTrenchCoat);
    buttons ->addWidget(updateTrenchCoat);

    return buttons;
}

QHBoxLayout *AdminWidget::createTrenchCoatSize()
{
    auto* trench_coat_size = new QLabel("size", this);
    auto* trench_coat_size_input = new QLineEdit(this);
    auto* trench_coat_size_group = new QHBoxLayout();
    trench_coat_size_group->addWidget(trench_coat_size);
    trench_coat_size_group->addWidget(trench_coat_size_input);

    return trench_coat_size_group;
}

QHBoxLayout *AdminWidget::createTrenchCoatColour()
{
    auto* trench_coat_colour = new QLabel("colour", this);
    auto* trench_coat_colour_input = new QLineEdit(this);
    auto* trench_coat_colour_group = new QHBoxLayout();
    trench_coat_colour_group->addWidget(trench_coat_colour);
    trench_coat_colour_group->addWidget(trench_coat_colour_input);

    return trench_coat_colour_group;
}

QHBoxLayout *AdminWidget::createTrenchCoatPrice()
{
    auto* trench_coat_price = new QLabel("price", this);
    auto* trench_coat_price_input = new QLineEdit(this);
    auto* trench_coat_price_group = new QHBoxLayout();
    trench_coat_price_group->addWidget(trench_coat_price);
    trench_coat_price_group->addWidget(trench_coat_price_input);

    return trench_coat_price_group;
}

QHBoxLayout *AdminWidget::createTrenchCoatQuantity()
{
    auto* trench_coat_quantity = new QLabel("quantity", this);
    auto* trench_coat_quantity_input = new QLineEdit(this);
    auto* trench_coat_quantity_group = new QHBoxLayout();
    trench_coat_quantity_group->addWidget(trench_coat_quantity);
    trench_coat_quantity_group->addWidget(trench_coat_quantity_input);

    return trench_coat_quantity_group;
}

QHBoxLayout *AdminWidget::createTrenchCoatPhotograph()
{
    auto* trench_coat_photograph = new QLabel("photograph", this);
    auto* trench_coat_photograph_input = new QLineEdit(this);
    auto* trench_coat_photograph_group = new QHBoxLayout();
    trench_coat_photograph_group->addWidget(trench_coat_photograph);
    trench_coat_photograph_group->addWidget(trench_coat_photograph_input);

    return trench_coat_photograph_group;
}