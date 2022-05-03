//
// Created by jonathan on 03/05/2022.
//

#include "exceptions.h"

FileNotFoundException::FileNotFoundException(const std::string &filename) noexcept : filename(filename){
    this->message_ = "File not found: " + filename;
}

FileNotOpenedException::FileNotOpenedException(const std::string &filename) noexcept {
    this->message_ = "File did not open correctly: " + filename;
}