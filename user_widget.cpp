#include "user_widget.h"

UserWidget::UserWidget(Service &service): service(service)
{
    this -> init_UserWidget();
    this -> connect_signals_and_slots();
}

void UserWidget::init_UserWidget()
{
    this -> filtered_trench_coats = this -> service.get_list();
    this -> index = 0;
    this -> size_filter = new QLineEdit{};
    this -> filter = new QPushButton("filter by size");
    this -> size_line_edit = new QLineEdit{};
    this -> colour_line_edit = new QLineEdit{};
    this -> price_line_edit = new QLineEdit{};
    this -> quantity_line_edit = new QLineEdit{};
    this -> add_button = new QPushButton("add");
    this -> next_button = new QPushButton("next");
    this -> export_button = new QPushButton("export");
    this -> main_layout = new QVBoxLayout;
    this -> basket_type = new QListWidget;
    this -> basket_type->addItem("csv");
    this -> basket_type->addItem("html");
    this -> file_type = "notepadqq file:../basket.csv";
    this -> setLayout(main_layout);

    this -> main_layout-> addWidget(this -> basket_type);
    this -> main_layout ->addWidget(this -> size_filter);
    this -> main_layout ->addWidget(this -> filter);

    auto* trench_coat_details_layout = new QFormLayout{};
    trench_coat_details_layout->addRow("size", this->size_line_edit);
    trench_coat_details_layout->addRow("colour", this->colour_line_edit);
    trench_coat_details_layout->addRow("price", this->price_line_edit);
    trench_coat_details_layout->addRow("quantity", this->quantity_line_edit);

    this -> main_layout->addLayout(trench_coat_details_layout);

    auto* buttons_layout = new QGridLayout{};
    buttons_layout->addWidget(this->add_button, 0, 0);
    buttons_layout->addWidget(this->next_button, 0, 1);
    buttons_layout->addWidget(this->export_button, 0, 2);

    main_layout->addLayout(buttons_layout);

    this -> service.set_mode("user");
}

void UserWidget::connect_signals_and_slots()
{
    QObject::connect(this->basket_type, &QListWidget::itemSelectionChanged, [this]() {
        int selected_index = this->get_selected_index();
        if (selected_index == 0)
            this -> file_type = "notepadqq file:../basket.csv";
        else
            this -> file_type = "firefox file:../basket.html";
    });
    QObject::connect(this->filter, &QPushButton::clicked, this, &UserWidget::filter_trench_coat);//connection
    QObject::connect(this->add_button, &QPushButton::clicked, this, &UserWidget::add_trench_coat);//connection
    QObject::connect(this->next_button, &QPushButton::clicked, this, &UserWidget::next_trench_coat);//connection
    QObject::connect(this->export_button, &QPushButton::clicked, this, &UserWidget::export_trench_coat);//connection
}

int UserWidget::get_selected_index() const
{
    QModelIndexList selected_indexes = this->basket_type->selectionModel()->selectedIndexes();
    int selected_index = selected_indexes.at(0).row();

    return selected_index;
}

void UserWidget::filter_trench_coat()
{
    if (!this -> size_filter->text().toStdString().empty())
        this -> filtered_trench_coats = this -> service.get_list_with_specified_size(this -> size_filter->text().toStdString());
    else
        this -> filtered_trench_coats = this -> service.get_list();
    TrenchCoat trench_coat = this->filtered_trench_coats[0];
    this->size_line_edit->setText(QString::fromStdString(trench_coat.get_size()));
    this->colour_line_edit->setText(QString::fromStdString(trench_coat.get_colour()));
    this->price_line_edit->setText(QString::fromStdString(std::to_string(trench_coat.get_price())));
    this->quantity_line_edit->setText(QString::fromStdString(std::to_string(trench_coat.get_quantity())));
    this->index = 1;
}

void UserWidget::next_trench_coat()
{
    if (index == this -> filtered_trench_coats.size() - 1)
        index = 0;
    TrenchCoat trench_coat = this -> filtered_trench_coats[index++];
    this->size_line_edit->setText(QString::fromStdString(trench_coat.get_size()));
    this->colour_line_edit->setText(QString::fromStdString(trench_coat.get_colour()));
    this->price_line_edit->setText(QString::fromStdString(std::to_string(trench_coat.get_price())));
    this->quantity_line_edit->setText(QString::fromStdString(std::to_string(trench_coat.get_quantity())));
}

void UserWidget::add_trench_coat()
{
    TrenchCoat trench_coat = this -> filtered_trench_coats[index - 1];
    if (index == 0)
        trench_coat = this -> filtered_trench_coats[this -> filtered_trench_coats.size() - 1];
    this -> service.add_trench_coat_basket(trench_coat);
}

void UserWidget::export_trench_coat()
{
    system(this -> file_type);
}


