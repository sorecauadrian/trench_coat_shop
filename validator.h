#ifndef A7_SORECAUADRIAN_1_VALIDATOR_H
#define A7_SORECAUADRIAN_1_VALIDATOR_H

#include "trench_coat.h"
#include <vector>
#include "exceptions.h"

class Validator
{
    private:
        std::vector<std::string> photographs;
    public:
        Validator() = default;
        ~Validator() = default;
        static void validate_size(const std::string&);
        static void validate_colour(const std::string&);
        static void validate_price(const unsigned long&);
        static void validate_quantity(const unsigned long&);
        static void validate_photograph(const std::string&);
        static void validate_data(const std::string&, const std::string&, const unsigned long&, const unsigned long&, const std::string&);
        void add_to_photographs(const std::string&);
        void remove_from_photographs(const std::string&);
};

#endif //A7_SORECAUADRIAN_1_VALIDATOR_H
