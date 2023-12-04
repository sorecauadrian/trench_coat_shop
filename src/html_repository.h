#ifndef A7_SORECAUADRIAN_1_HTML_REPOSITORY_H
#define A7_SORECAUADRIAN_1_HTML_REPOSITORY_H

#include "repository.h"

#include <fstream>
#include <iostream>
#include <utility>

class HTML_Repository : public Repository
{
    private:
        std::string file_location;
    public:
        explicit HTML_Repository(std::string  file_location): file_location(std::move(file_location)) {};
        ~HTML_Repository() = default;

        std::vector<TrenchCoat> read_from_file() const;
        void write_to_file(std::vector<TrenchCoat>& trench_coats);
        bool add_trench_coat(const std::string&, const std::string&, const unsigned long&, const unsigned long&, const std::string&) override;
        bool remove_trench_coat(const std::string&) override;
        bool update_trench_coat(const std::string&, const std::string&, const unsigned long&, const unsigned long&, const std::string&) override;
        unsigned long get_length_repository() override;
        bool is_in_list_repository(const std::string& photograph) override;
        std::vector<TrenchCoat> get_data_repository() override;

};

#endif //A7_SORECAUADRIAN_1_HTML_REPOSITORY_H
