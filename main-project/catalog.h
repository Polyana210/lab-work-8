#pragma once
#ifndef CATALOG_H
#define CATALOG_H

#include "constants.h"


struct catalog
{
    unsigned double cost;
    unsigned int quan;
    char category[MAX_STRING_SIZE];
    char name[MAX_STRING_SIZE];
};

#endif