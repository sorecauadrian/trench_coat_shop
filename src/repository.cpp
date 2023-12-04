#include "repository.h"

bool Repository::add_trench_coat(const std::string& size, const std::string& colour, const unsigned long& price,  const unsigned long& quantity, const std::string& photograph)
{
    this -> trench_coats.emplace_back(size, colour, price, quantity, photograph);
    this -> validator.add_to_photographs(photograph);
    return true;
}

bool Repository::remove_trench_coat(const std::string& photograph)
{
    int index = 0;
    this -> validator.remove_from_photographs(photograph);
    for (auto& trench_coat : this -> trench_coats)
    {
        if (trench_coat.get_photograph() == photograph)
        {
            this -> trench_coats.erase(this -> trench_coats.begin() + index);
            return true;
        }
        index++;
    }
    return false;
}

bool Repository::update_trench_coat(const std::string& size, const std::string& colour, const unsigned long& price,  const unsigned long& quantity, const std::string& photograph)
{
    int index = 0;
    this->validator.add_to_photographs(photograph);
    for (auto &trench_coat: this->trench_coats)
    {
        if (trench_coat.get_photograph() == photograph) {
            this->validator.remove_from_photographs(trench_coat.get_photograph());
            this->trench_coats[index] = TrenchCoat(size, colour, price, quantity, photograph);
            return true;
        }
        index++;
    }
    return false;
}

unsigned long Repository::get_length_repository() {return this -> trench_coats.size();}

std::vector<TrenchCoat> Repository::get_data_repository() {return this -> trench_coats;}

bool Repository::is_in_list_repository(const std::string &photograph)
{
    if (std::any_of(trench_coats.begin(), trench_coats.end(), [photograph](TrenchCoat &trench_coat) {return trench_coat.get_photograph() == photograph;}))
        return true;
    return false;
}
