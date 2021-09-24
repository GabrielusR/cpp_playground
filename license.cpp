#include <iostream>

#include "license.h"

using std::cout;
using std::cin;


float license()
{
    float grossSales = 0.0;
    cout << "Enter the gross sales : ";
    cin >> grossSales;

    const int NUM_CATEGORIES = 4;

    const float salesThreshold[NUM_CATEGORIES] = {0.0, 50000.0, 150000.0, 500000.0};
    const float licenseCost[NUM_CATEGORIES] = {25.0, 200.0, 1000.0, 5000.0};

    int category = 0;

    while( category < NUM_CATEGORIES &&
           salesThreshold[category] <= grossSales )
        {
            category += 1;
        }

    return licenseCost[ category - 1 ];
}
