#include "file_reader.h"
#include <cstring>
#include <iostream>

catalog** filter(catalog* array[], int size, bool (*check)(catalog* element), int& result_size)
{
	catalog** result = new catalog * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_book_promtovary(catalog* element)
{

	return strcmp(element->category, "Промтовары") == 0;

}

bool check_book_cost(catalog* element)
{
	return element->cost >100;
}
