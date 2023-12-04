#include "service.h"
#include "exceptions.h"

void Service::add_to_total_sum(unsigned long price) {this -> total_sum += price;}

unsigned long Service::get_total_sum() const {return this -> total_sum;}

std::string Service::get_mode() const {return this -> mode;}

void Service::set_mode(const std::string &new_mode) {this -> mode = new_mode;}

unsigned long Service::get_size() {return this -> repository.get_length_repository();}

void Service::add_trench_coat(const std::string &size, const std::string &colour, const unsigned long &price, const unsigned long &quantity, const std::string &photograph)
{
    if (this -> get_mode() != "administrator")
        throw PermissionError("you are not in administrator mode!\n");

    if (this->repository.is_in_list_repository(photograph))
        throw ValidatorError("specified trench coat already in the list!\n");

    Validator::validate_data(size, colour, price, quantity, photograph);

    this -> repository.add_trench_coat(size, colour, price, quantity, photograph);
}

void Service::remove_trench_coat(const std::string &photograph)
{
    if (this -> get_mode() != "administrator")
        throw PermissionError("you are not in administrator mode!\n");

    if (!this->repository.is_in_list_repository(photograph))
        throw ValidatorError("specified trench coat doesn't exist!\n");

    this -> repository.remove_trench_coat(photograph);
}

void Service::update_trench_coat(const std::string &size, const std::string &colour, const unsigned long &price, const unsigned long &quantity, const std::string &photograph)
{
    if (this -> get_mode() != "administrator")
        throw PermissionError("you are not in administrator mode!\n");

    if (!this->repository.is_in_list_repository(photograph))
        throw ValidatorError("specified trench coat doesn't exist!\n");

    Validator::validate_data(size, colour, price, quantity, photograph);

    this -> repository.update_trench_coat(size, colour, price, quantity, photograph);
}

std::vector<TrenchCoat> Service::get_list() {return this -> repository.get_data_repository();}

std::vector<TrenchCoat> Service::get_basket()
{
    if (this -> get_mode() != "user")
        throw PermissionError("you are not in user mode!\n");
    return this -> basket -> get_data_repository();
}

std::vector<TrenchCoat> Service::get_list_with_specified_size(const std::string &size)
{
    std::vector<TrenchCoat> resulted_vector;
    for (auto& trench_coat : this -> repository.get_data_repository())
        if (trench_coat.get_size() == size)
            resulted_vector.push_back(trench_coat);
    return resulted_vector;
}

void Service::add_trench_coat_basket(const TrenchCoat &trench_coat)
{
    if (this -> get_mode() != "user")
        throw PermissionError("you are not in user mode!\n");

    this -> basket -> add_trench_coat(trench_coat.get_size(), trench_coat.get_colour(), trench_coat.get_price(), trench_coat.get_quantity(), trench_coat.get_photograph());
}