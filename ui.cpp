#include "ui.h"

void UI::start(const std::string& file_format)
{
    std::string command;
    while (std::getline(std::cin, command))
    {
        system("clear");
        std::stringstream parser(command);
        std::string argument;
        parser >> argument;
        if (argument == "mode")
        {
            parser >> argument;
            this -> service.set_mode(argument);
        }
        else if (argument == "add")
        {
            std::string size;
            std::string colour;
            int price;
            int quantity;
            std::string photograph;
            try
            {
                parser >> size;
                parser >> colour;
                parser >> price;
                parser >> quantity;
                parser >> photograph;
                this -> service.add_trench_coat(size, colour, price, quantity, photograph);
                std::cout << "successfully added to the database!\n";
            }
            catch (ValueError &ve)
            {
                std::cout << ve.get_message() << '\n';
            }
            catch (PermissionError &pe)
            {
                std::cout << pe.get_message() << '\n';
            }
            catch (ValidatorError &ve)
            {
                std::cout << ve.get_message() << '\n';
            }
        }
        else if (argument == "remove")
        {
            std::string photograph;
            try
            {
                parser >> photograph;
                this -> service.remove_trench_coat(photograph);
                std::cout << "successfully removed from the database!\n";
            }
            catch (ValueError &ve)
            {
                std::cout << ve.get_message() << '\n';
            }
            catch (PermissionError &pe)
            {
                std::cout << pe.get_message() << '\n';
            }
            catch (ValidatorError &ve)
            {
                std::cout << ve.get_message() << '\n';
            }
        }
        else if (argument == "update")
        {
            std::string size;
            std::string colour;
            int price;
            int quantity;
            std::string photograph;
            try
            {
                parser >> size;
                parser >> colour;
                parser >> price;
                parser >> quantity;
                parser >> photograph;
                this -> service.update_trench_coat(size, colour, price, quantity, photograph);
                std::cout << "successfully updated in the repository!\n";
            }
            catch (ValueError &ve)
            {
                std::cout << ve.get_message() << '\n';
            }
            catch (PermissionError &pe)
            {
                std::cout << pe.get_message() << '\n';
            }
            catch (ValidatorError &ve)
            {
                std::cout << ve.get_message() << '\n';
            }
        }
        else if (argument == "list")
        {
            std::string size;
            auto resulted_vector = this -> service.get_list();
            if (parser >> size)
                resulted_vector = this->service.get_list_with_specified_size(size);
            if (this -> service.get_mode() == "administrator")
            {
                std::cout << "there are " << resulted_vector.size() << " coats!\n\n";
                for (auto& trench_coat : resulted_vector)
                    std::cout << trench_coat;
            }
            else if (this -> service.get_mode() == "user")
            {
                if (resulted_vector.empty())
                {
                    std::cout << "there are no coats with the specified size!\n";
                }
                else
                {
                    unsigned long index = 0;
                    std::cout << "the total sum: "<< this -> service.get_total_sum() << "\n";
                    std::cout << resulted_vector[index];
                    std::string user_command;
                    while (std::getline(std::cin, user_command))
                    {
                        system("clear");
                        if (user_command == "add")
                        {
                            this -> service.add_trench_coat_basket(resulted_vector[index]);
                            this -> service.add_to_total_sum(resulted_vector[index].get_price());
                            std::cout << "item successfully added to the basket!\n";
                        }
                        else if (user_command == "next")
                        {
                            index++;
                            if (index >= resulted_vector.size())
                                index = 0;
                        }
                        else if (user_command == "stop")
                            break;
                        else
                            std::cout << "invalid command!\n";
                        std::cout << "the total sum: "<< this -> service.get_total_sum() << "\n";
                        std::cout << resulted_vector[index];
                    }
                }
            }
            else
                std::cout << "choose a mode! administrator/user\n";
        }
        else if (argument == "see_basket")
        {
            if (file_format == "html")
                system("firefox file:../basket.html");
            else if (file_format == "csv")
                system("notepadqq file:../basket.csv");
        }
        else if (argument == "exit")
            break;
        else
            std::cout << "invalid command!\n";
    }
}