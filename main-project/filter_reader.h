#pragma once
#ifndef FILTER_H
#define FILTER_H

#include "catalog.h"

catalog** filter(catalog* array[], int size, bool (*check)(catalog* element), int& result_size);
bool check_book_promtovary(catalog* element);
bool check_book_cost(catalog* element);
#endif
