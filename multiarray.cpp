#include <stdlib.h>

#include <iostream>

#include "multiarray.h"
#include "mode.h"
#include "student.h"

using std::cout;

//implicitly works because arr is taken as
//a pointer to the first array element.
double average( int arr[], int arrSize )
{
    double sum = 0.0;

    for( int i = 0; i < arrSize; i++ )
    {
        sum += arr[i];
    }

    double average = sum / arrSize;

    return average;
}

double median( int arr[], int arrSize )
{
    double median = 0;
    int middle = 0;

    if( arrSize % 2 != 0 )
    {
        middle = (arrSize - 1) / 2;

        median = arr[ middle ];
    }
    else
    {
        int avg[2];

        middle = (arrSize / 2);
        avg[0] = arr[ middle - 1 ];

        middle = (arrSize / 2) + 1;
        avg[1] = arr[ middle - 1 ];

        median = average( avg, 2 );
    }

    return median;
}

void multiArray()
{
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;

    int sales[NUM_AGENTS][NUM_MONTHS] =
    {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    for( int agent = 0; agent < NUM_AGENTS; agent++ )
    {
        qsort( sales[agent], NUM_MONTHS, sizeof(int), &diffFunc );
    }

    TopAgent topAgent;

    double highestMedian = median( sales[0], NUM_MONTHS );

    topAgent.agent = 1;
    topAgent.highestMedian = highestMedian;

    //this is possible because we set the sales array as
    //agent x months and not months x agent. So we have
    //a contiguous sequence which allows to processe
    //each single dimension array individually.
    for( int agent = 1; agent < NUM_AGENTS; agent++ )
    {
        highestMedian = median( sales[agent], NUM_MONTHS );

        if( highestMedian > topAgent.highestMedian )
        {
            topAgent.highestMedian = highestMedian;
            topAgent.agent = agent + 1;
        }
    }

    cout << "Highest median : " << topAgent.highestMedian << "\n";
    cout << "Top sales agent : " << topAgent.agent << "\n";
}
