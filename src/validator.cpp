#include "validator.h"

void Validator::validate_size(const std::string &size)
{
    if (size.empty())
        throw ValidatorError("invalid size!");
}

void Validator::validate_colour(const std::string &colour)
{
    if (colour.empty())
        throw ValidatorError("invalid colour!");
}

void Validator::validate_price(const unsigned long &price)
{
    if (!price)
        throw ValidatorError("invalid price!");
}

void Validator::validate_quantity(const unsigned long &quantity)
{
    if (!quantity)
        throw ValidatorError("invalid quantity");
}

void Validator::validate_photograph(const std::string &photograph)
{
    if (photograph.empty())
        throw ValidatorError("invalid photograph!");
}

void Validator::validate_data(const std::string &size, const std::string &colour, const unsigned long &price, const unsigned long &quantity, const std::string &photograph) {
    std::string exception;
    try
    {
        validate_size(size);
    }
    catch (ValidatorError &validator_error)
    {
        exception += validator_error.get_message();
        exception += "\n";
    }

    try
    {
        validate_colour(colour);
    }
    catch (ValidatorError &validator_error)
    {
        exception += validator_error.get_message();
        exception += "\n";
    }

    try
    {
        validate_price(price);
    }
    catch (ValidatorError &validator_error)
    {
        exception += validator_error.get_message();
        exception += "\n";
    }

    try
    {
        validate_quantity(quantity);
    }
    catch (ValidatorError &validator_error)
    {
        exception += validator_error.get_message();
        exception += "\n";
    }

    try
    {
        validate_photograph(photograph);
    }
    catch (ValidatorError &validator_error)
    {
        exception += validator_error.get_message();
        exception += "\n";
    }

    if (!exception.empty())
        throw ValidatorError(exception);
}

void Validator::add_to_photographs(const std::string &photograph) {this -> photographs.push_back(photograph);}

void Validator::remove_from_photographs(const std::string &photograph)
{
    int index = 0;
    for (auto& photograph_from_repository : this -> photographs)
    {
        if (photograph_from_repository == photograph)
            this -> photographs.erase(this -> photographs.begin() + index);
        index++;
    }
}

