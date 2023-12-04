#ifndef A6_SORECAUADRIAN_1_SERVICE_H
#define A6_SORECAUADRIAN_1_SERVICE_H

#include <utility>
#include "file_repository.h"
#include "csv_repository.h"
#include "html_repository.h"

class Service
{
private:
    FileRepository repository;
    Repository* basket;
    unsigned long total_sum;
    std::string mode;
    Validator validator;
public:
    Service(const FileRepository& repository, Repository* basket): repository{repository}, basket{basket}, total_sum{0}, mode{"undefined"}, validator{this -> repository.validator} {};
    ~Service() = default;

    [[nodiscard]] std::string get_mode() const;
    void set_mode(const std::string &new_mode);

    unsigned long get_size();
    std::vector<TrenchCoat> get_list();

    void add_trench_coat(const std::string&, const std::string&, const unsigned long&, const unsigned long&, const std::string&);
    void remove_trench_coat(const std::string&);
    void update_trench_coat(const std::string&, const std::string&, const unsigned long&, const unsigned long&, const std::string&);

    std::vector<TrenchCoat> get_basket();
    std::vector<TrenchCoat> get_list_with_specified_size(const std::string&);
    void add_trench_coat_basket(const TrenchCoat &);

    void add_to_total_sum(unsigned long price);
    [[nodiscard]] unsigned long get_total_sum() const;

};


#endif //A6_SORECAUADRIAN_1_SERVICE_H
