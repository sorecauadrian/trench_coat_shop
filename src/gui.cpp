#include "gui.h"

GUI::GUI(Service &service): service(service)
{
    this -> init_GUI();
    this -> populate_list();
    this -> connect_signals_and_slots();
}

void GUI::init_GUI()
{
    this -> trench_coat_list_widget = new QListWidget{};
    this -> size_line_edit = new QLineEdit{};
    this -> colour_line_edit = new QLineEdit{};
    this -> price_line_edit = new QLineEdit{};
    this -> quantity_line_edit = new QLineEdit{};
    this -> photograph_line_edit = new QLineEdit{};
    this -> add_button = new QPushButton("add");
    this -> remove_button = new QPushButton("remove");
    this -> update_button = new QPushButton("update");
    this -> main_layout = new QVBoxLayout;
    this ->setLayout(main_layout);

    this -> main_layout ->addWidget(this -> trench_coat_list_widget);

    auto* trench_coat_details_layout = new QFormLayout{};
    trench_coat_details_layout->addRow("size", this->size_line_edit);
    trench_coat_details_layout->addRow("colour", this->colour_line_edit);
    trench_coat_details_layout->addRow("price", this->price_line_edit);
    trench_coat_details_layout->addRow("quantity", this->quantity_line_edit);
    trench_coat_details_layout->addRow("photograph", this->photograph_line_edit);

    this -> main_layout->addLayout(trench_coat_details_layout);

    auto* buttons_layout = new QGridLayout{};
    buttons_layout->addWidget(this->add_button, 0, 0);
    buttons_layout->addWidget(this->remove_button, 0, 1);
    buttons_layout->addWidget(this->update_button, 0, 2);

    main_layout->addLayout(buttons_layout);

    this -> service.set_mode("administrator");
}

void GUI::populate_list()
{
    this -> trench_coat_list_widget-> clear();
    std::vector<TrenchCoat> trench_coats = this -> service.get_list();
    for (auto& trench_coat : trench_coats)
        this -> trench_coat_list_widget ->addItem(QString::fromStdString(trench_coat.get_size() + ", " + trench_coat.get_colour() + ", " + std::to_string(trench_coat.get_price()) + ", " + std::to_string(trench_coat.get_quantity())));
}

void GUI::connect_signals_and_slots()
{
    QObject::connect(this->trench_coat_list_widget, &QListWidget::itemSelectionChanged, [this]() {
        int selected_index = this->get_selected_index();
        if (selected_index < 0)
            return;
        TrenchCoat trench_coat = this->service.get_list()[selected_index];
        this->size_line_edit->setText(QString::fromStdString(trench_coat.get_size()));
        this->colour_line_edit->setText(QString::fromStdString(trench_coat.get_colour()));
        this->price_line_edit->setText(QString::fromStdString(std::to_string(trench_coat.get_price())));
        this->quantity_line_edit->setText(QString::fromStdString(std::to_string(trench_coat.get_quantity())));
        this->photograph_line_edit->setText(QString::fromStdString(trench_coat.get_photograph()));
    });

    QObject::connect(this->add_button, &QPushButton::clicked,this, &GUI::add_trench_coat);//connection
    QObject::connect(this->remove_button, &QPushButton::clicked, this, &GUI::remove_trench_coat);//connection
    QObject::connect(this->update_button, &QPushButton::clicked, this, &GUI::update_trench_coat);//connection
}

int GUI::get_selected_index() const
{
    QModelIndexList selected_indexes = this->trench_coat_list_widget->selectionModel()->selectedIndexes();
    if (selected_indexes.empty())
    {
        this->size_line_edit->clear();
        this->colour_line_edit->clear();
        this->price_line_edit->clear();
        this->quantity_line_edit->clear();
        this->photograph_line_edit->clear();
        return -1;
    }
    int selected_index = selected_indexes.at(0).row();

    return selected_index;
}

void GUI::add_trench_coat()
{
    std::string size = this->size_line_edit->text().toStdString();
    std::string colour = this->colour_line_edit->text().toStdString();
    std::string price_string = this->price_line_edit->text().toStdString();
    std::string quantity_string = this->quantity_line_edit->text().toStdString();
    std::string photograph = this->photograph_line_edit->text().toStdString();
    unsigned int price = stoul(price_string);
    unsigned int quantity = stoul(quantity_string);

    try
    {
        this->service.add_trench_coat(size, colour, price, quantity, photograph);
    }
    catch (PermissionError &pe)
    {
        QMessageBox::critical(this, "error", "you are not in administrator mode!");
        return;
    }
    catch (ValidatorError &ve)
    {
        QMessageBox::critical(this, "error", "trench coat already exists!");
        return;
    }


    this->populate_list();

    int last_element = this->service.get_size()- 1;
    this->trench_coat_list_widget->setCurrentRow(last_element);
}

void GUI::remove_trench_coat()
{
    int selected_index = this->get_selected_index();

    if (selected_index < 0)
    {
        QMessageBox::critical(this, "error", "no trench coat was selected! ");
        return;
    }

    std::string photograph = this->service.get_list()[selected_index].get_photograph();

    try
    {
        this->service.remove_trench_coat(photograph);
    }
    catch (PermissionError &pe)
    {
        QMessageBox::critical(this, "error", "you are not in administrator mode!");
        return;
    }

    this->populate_list();
}

void GUI::update_trench_coat()
{
    int selected_index = this->get_selected_index();

    if (selected_index < 0)
    {
        QMessageBox::critical(this, "error", "no trench coat was selected!");
        return;
    }

    std::string size = this->size_line_edit->text().toStdString();
    std::string colour = this->colour_line_edit->text().toStdString();
    std::string price_string = this->price_line_edit->text().toStdString();
    std::string quantity_string = this->quantity_line_edit->text().toStdString();
    std::string photograph = this->photograph_line_edit->text().toStdString();
    unsigned int price = stoul(price_string);
    unsigned int quantity = stoul(quantity_string);

    try
    {
        this->service.update_trench_coat(size, colour, price, quantity, photograph);

    }
    catch (PermissionError &pe)
    {
        QMessageBox::critical(this, "error", "you are not in administrator mode!");
        return;
    }



    this->populate_list();

}

