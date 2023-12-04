#include "csv_repository.h"

std::vector<TrenchCoat> CSV_Repository::read_from_file() const
{
    std::ifstream fin(this -> file_location);
    TrenchCoat trench_coat;
     std::vector<TrenchCoat> trench_coats;
     while (fin >> trench_coat)
         trench_coats.push_back(trench_coat);
     fin.close();
    return trench_coats;
}

void CSV_Repository::write_to_file(std::vector<TrenchCoat> &trench_coats)
{
    std::ofstream fout(this -> file_location);
    for (auto trench_coat : trench_coats)
        fout << trench_coat;
    fout.close();
}

bool CSV_Repository::add_trench_coat(const std::string &size, const std::string &colour, const unsigned long &price, const unsigned long &quantity, const std::string &photograph)
{
    std::vector<TrenchCoat> trench_coats = this -> read_from_file();
    trench_coats.emplace_back(size, colour, price, quantity, photograph);
    this -> validator.add_to_photographs(photograph);
    this -> write_to_file(trench_coats);
    return true;
}

bool CSV_Repository::remove_trench_coat(const std::string &photograph)
{
    std::vector<TrenchCoat> trench_coats = this -> read_from_file();
    int index = 0;
    this -> validator.remove_from_photographs(photograph);
    for (auto& trench_coat : trench_coats)
    {
        if (trench_coat.get_photograph() == photograph)
        {
            trench_coats.erase(trench_coats.begin() + index);
            this ->write_to_file(trench_coats);
            return true;
        }
        index++;
    }
    return false;
}

bool CSV_Repository::update_trench_coat(const std::string &size, const std::string &colour, const unsigned long &price, const unsigned long &quantity, const std::string &photograph)
{
    std::vector<TrenchCoat> trench_coats = this -> read_from_file();
    int index = 0;
    this -> validator.add_to_photographs(photograph);
    for (auto& trench_coat : trench_coats)
    {
        if (trench_coat.get_photograph() == photograph)
        {
            trench_coats[index] = TrenchCoat(size, colour, price, quantity, photograph);
            this -> validator.remove_from_photographs(trench_coat.get_photograph());
            this -> write_to_file(trench_coats);
            return true;
        }
        index++;
    }
    return false;
}

unsigned long CSV_Repository::get_length_repository() {return this -> read_from_file().size();}

bool CSV_Repository::is_in_list_repository(const std::string &photograph)
{
    std::vector<TrenchCoat> trench_coats = this -> read_from_file();
    if (std::any_of(trench_coats.begin(), trench_coats.end(), [photograph](TrenchCoat &trench_coat) {return trench_coat.get_photograph() == photograph;}))
        return true;
    return false;
}

std::vector<TrenchCoat> CSV_Repository::get_data_repository() {return this -> read_from_file();}

