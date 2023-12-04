#ifndef A6_SORECAUADRIAN_1_UI_H
#define A6_SORECAUADRIAN_1_UI_H

#include "service.h"
#include "exceptions.h"
#include <iostream>
#include <sstream>

class UI
{
    private:
        Service service;
    public:
        explicit UI(Service &service) : service(service) {};
        void start(const std::string&);
};


#endif //A6_SORECAUADRIAN_1_UI_H
