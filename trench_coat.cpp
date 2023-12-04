#include "trench_coat.h"
#include <iostream>

TrenchCoat::TrenchCoat()
{
    this -> size = "";
    this -> colour = "";
    this -> price = 0;
    this -> quantity = 0;
    this -> photograph = "";
}

TrenchCoat::TrenchCoat(const std::string &size, const std::string &colour, const unsigned long &price, const unsigned long &quantity, const std::string &photograph)
{
    this -> size = size;
    this -> colour = colour;
    this -> price = price;
    this -> quantity = quantity;
    this -> photograph = photograph;
}

TrenchCoat::TrenchCoat(const TrenchCoat &TrenchCoatToBeCopied)
{
    this -> size = TrenchCoatToBeCopied.size;
    this -> colour = TrenchCoatToBeCopied.colour;
    this -> price = TrenchCoatToBeCopied.price;
    this -> quantity = TrenchCoatToBeCopied.quantity;
    this -> photograph = TrenchCoatToBeCopied.photograph;
}

std::string TrenchCoat::get_size() const {return this -> size;}

std::string TrenchCoat::get_colour() const {return this -> colour;}

unsigned long TrenchCoat::get_price() const {return this -> price;}

unsigned long TrenchCoat::get_quantity() const {return this -> quantity;}

std::string TrenchCoat::get_photograph() const {return this -> photograph;}

TrenchCoat& TrenchCoat::operator=(const TrenchCoat &new_coat)
{
    if (this == &new_coat)
        return *this;
    this -> size = new_coat.size;
    this -> colour = new_coat.colour;
    this -> price = new_coat.price;
    this -> quantity = new_coat.quantity;
    this -> photograph = new_coat.photograph;
    return *this;
}

bool TrenchCoat::operator==(const TrenchCoat& other) {return (this -> size == other.size && this -> colour == other.size && this -> photograph == other.photograph);}

std::ostream& operator<<(std::ostream& output, TrenchCoat& trench_coat)
{
    output << trench_coat.get_size() << ',' << trench_coat.get_colour() << ',' << trench_coat.get_price() << ',' << trench_coat.get_quantity() << ',' << trench_coat.get_photograph() << '\n';
    return output;
}

std::istream& operator>>(std::istream& input, TrenchCoat& trench_coat)
{
    std::string line;
    getline(input, line);
    if (line.empty())
        return input;

    unsigned long position = line.find(',');
    std::string size = line.substr(0, position);
    line.erase(0, position + 1);

    position = line.find(',');
    std::string colour = line.substr(0, position);
    line.erase(0, position + 1);

    position = line.find(',');
    std::string string_price = line.substr(0, position);
    unsigned long price = stoul(string_price);
    line.erase(0, position + 1);

    position = line.find(',');
    std::string string_quantity = line.substr(0, position);
    unsigned long quantity = stoul(string_quantity);
    line.erase(0, position + 1);

    std::string photograph = line;

    trench_coat = TrenchCoat(size, colour, price, quantity, photograph);

    return input;
}

TrenchCoat::~TrenchCoat() = default;

