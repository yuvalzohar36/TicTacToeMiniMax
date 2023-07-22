//
// Created by yuvalzo on 7/21/23.
//




#include <cstdlib>
#include "../include/Utils.h"

Utils::Utils(){};

int Utils::getRandomNumber(int min, int max) {
    return min + std::rand() % (max - min + 1);
}