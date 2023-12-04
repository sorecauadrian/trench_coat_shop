#ifndef A7_SORECAUADRIAN_1_REPOSITORY_H
#define A7_SORECAUADRIAN_1_REPOSITORY_H

#include <vector>
#include <algorithm>
#include "trench_coat.h"
#include "validator.h"

class Repository
{
    private:
        std::vector<TrenchCoat> trench_coats;
    public:
        Validator validator;
    public:
        Repository() = default;
        ~Repository() = default;
        virtual bool add_trench_coat(const std::string& size, const std::string& colour, const unsigned long& price,  const unsigned long& quantity, const std::string& photograph);
        virtual bool remove_trench_coat(const std::string&);
        virtual bool update_trench_coat(const std::string& size, const std::string& colour, const unsigned long& price,  const unsigned long& quantity, const std::string& photograph);
        virtual unsigned long get_length_repository();
        virtual bool is_in_list_repository(const std::string& photograph);
        virtual std::vector<TrenchCoat> get_data_repository();
};

#endif //A7_SORECAUADRIAN_1_REPOSITORY_H
