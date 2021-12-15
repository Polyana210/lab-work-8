#include "processing.h"

#include <cstring>
#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>


using namespace std;

double process(catalog* array[], int size, string cat)
{

	double sum = 0;

	for (int i = 0; i < size; i++) {
		if (array[i]->category == cat) {

			sum = sum + array[i]->cost * array[i]->quan;
		}
	}

	return sum;

}