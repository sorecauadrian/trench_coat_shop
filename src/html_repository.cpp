#include "html_repository.h"

std::vector<TrenchCoat> HTML_Repository::read_from_file() const {
    std::ifstream fin(this -> file_location);

    unsigned long useless_lines = 14, position;
    std::string line, size, colour, price_string, quantity_string, photograph;
    unsigned long price, quantity;

    while (useless_lines != 0)
    {
        getline(fin, line);
        useless_lines--;
    }

    std::vector<TrenchCoat> trench_coats;
    TrenchCoat trench_coat;
    while (getline(fin, line))
    {
        if (*(line.begin() + 3) == 'a')
        {
            break;
        }

        getline(fin, line);
        position = line.find('>');
        line.erase(0, position + 1);
        position = line.find('<');
        size = line.substr(0, position);

        getline(fin, line);
        position = line.find('>');
        line.erase(0, position + 1);
        position = line.find('<');
        colour = line.substr(0, position);

        getline(fin, line);
        position = line.find('>');
        line.erase(0, position + 1);
        position = line.find('<');
        price = stoul(line.substr(0, position));

        getline(fin, line);
        position = line.find('>');
        line.erase(0, position + 1);
        position = line.find('<');
        quantity = stoul(line.substr(0, position));

        getline(fin, line);
        position = line.find('>');
        line.erase(0, position + 1);
        position = line.find('<');
        photograph = line.substr(0, position);

        trench_coat = TrenchCoat(size, colour, price, quantity, photograph);

        trench_coats.push_back(trench_coat);
        getline(fin, line);
    }
    fin.close();
    return trench_coats;
}

void HTML_Repository::write_to_file(std::vector<TrenchCoat> &trench_coats)
{
    std::ofstream fout(this->file_location);

    fout << "<!doctype html>\n";
    fout << "<html>\n";
    fout << "<head>\n";
    fout << "<title>my list</title>\n";
    fout << "</head>\n";
    fout << "<body>\n";
    fout << "<table border = '1'>\n";
    fout << "<tr>\n";
    fout << "<td>size</td>\n";
    fout << "<td>colour</td>\n";
    fout << "<td>price</td>\n";
    fout << "<td>quantity</td>\n";
    fout << "<td>photograph</td>\n";
    fout << "</tr>\n";

    for (auto& trench_coat : trench_coats)
    {
        fout << "<tr>\n";
        fout << "<td>" << trench_coat.get_size() << "</td>\n";
        fout << "<td>" << trench_coat.get_colour() << "</td>\n";
        fout << "<td>" << trench_coat.get_price() << "</td>\n";
        fout << "<td>" << trench_coat.get_quantity() << "</td>\n";
        fout << "<td>" << trench_coat.get_photograph() << "</td>\n";
        fout << "</tr>\n";
    }

    fout << "</table>\n";
    fout << "</body>\n";
    fout << "</html>\n";

    fout.close();
}

bool HTML_Repository::add_trench_coat(const std::string &size, const std::string &colour, const unsigned long &price, const unsigned long &quantity, const std::string &photograph)
{
    std::vector<TrenchCoat> trench_coats = this -> read_from_file();
    trench_coats.emplace_back(size, colour, price, quantity, photograph);
    this ->write_to_file(trench_coats);
    return true;
}

bool HTML_Repository::remove_trench_coat(const std::string &photograph)
{
    std::vector<TrenchCoat> trench_coats = this->read_from_file();
    int index = 0;
    this->validator.remove_from_photographs(photograph);
    for (auto& trench_coat : trench_coats)
    {
        if (trench_coat.get_photograph() == photograph)
        {
            trench_coats.erase(trench_coats.begin() + index);
            this->write_to_file(trench_coats);
            return true;
        }
        index++;
    }
    return false;
}

bool HTML_Repository::update_trench_coat(const std::string &size, const std::string &colour, const unsigned long &price, const unsigned long &quantity, const std::string &photograph)
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

unsigned long HTML_Repository::get_length_repository() {return this -> read_from_file().size();}

bool HTML_Repository::is_in_list_repository(const std::string &photograph)
{
    std::vector<TrenchCoat> trench_coats = this -> read_from_file();
    if (std::any_of(trench_coats.begin(), trench_coats.end(), [photograph](TrenchCoat &trench_coat) {return trench_coat.get_photograph() == photograph;}))
        return true;
    return false;
}

std::vector<TrenchCoat> HTML_Repository::get_data_repository() {
    return this -> read_from_file();
}
