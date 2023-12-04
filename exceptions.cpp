#include "exceptions.h"

ValueError::ValueError(const std::string& message) {this -> message = message;}

std::string ValueError::get_message() {return this -> message;}


PermissionError::PermissionError(const std::string& message) {this -> message = message;}

std::string PermissionError::get_message() {return this -> message;}

ValidatorError::ValidatorError(const std::string& message) {this -> message = message;}

std::string ValidatorError::get_message() {return this -> message;}

