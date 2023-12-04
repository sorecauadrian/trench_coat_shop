#ifndef A6_SORECAUADRIAN_1_TRENCH_COAT_H
#define A6_SORECAUADRIAN_1_TRENCH_COAT_H

#include <string>

class TrenchCoat
{
private:
    std::string size;
    std::string colour;
    unsigned long price;
    unsigned long quantity;
    std::string photograph;
public:
    TrenchCoat();
    TrenchCoat(const std::string&, const std::string&, const unsigned long&, const unsigned long&, const std::string&);
    TrenchCoat(const TrenchCoat&);
    ~TrenchCoat();

    std::string get_size() const;
    std::string get_colour() const;
    unsigned long get_price() const;
    unsigned long get_quantity() const;
    std::string get_photograph() const;

    TrenchCoat &operator=(const TrenchCoat &);
    bool operator==(const TrenchCoat&);

    friend std::ostream& operator<<(std::ostream&, TrenchCoat&);
    friend std::istream& operator>>(std::istream&, TrenchCoat&);
};

#endif //A6_SORECAUADRIAN_1_TRENCH_COAT_H
