#include <stdio.h>
#include <stdlib.h>

#define YEAR_COUNT 5
#define MONTH_COUNT 12

int main(int argc, char **argv) {
    float Precipitation[YEAR_COUNT][MONTH_COUNT] = {
        {118.0, 82.5, 135.0, 109.5, 124.5, 146.0, 122.5, 37.5, 161.6, 51.0, 99.0, 110.5},
        {249.5, 323.5, 1066.5, 256.0, 977.5, 412.5, 210.0, 117.5, 46.0, 319.5, 262.5, 31.0},
        {421.5, 256.0, 564.0, 288.0, 683.0, 179.0, 81.5, 18.5, 81.0, 160.5, 197.5, 10.0},
        {116.5, 97.0, 329.0, 122.0, 221.0, 461.0, 116.5, 178.5, 85.0, 905.0, 352.5, 47.5},
        {393.0, 489.5, 2180.0, 449.5, 2426.0, 1044.6, 251.0, 878.9, 170.5, 1201.5, 780.0, 5.5},
    };
    
    float yearSumArray[YEAR_COUNT];
    float monthSumArray[MONTH_COUNT];
    for(int yearIndex = 0; yearIndex < YEAR_COUNT; ++yearIndex ) {
        float thisYear = 0.0;
        
        for (int monthIndex = 0 ; monthIndex < MONTH_COUNT ; ++monthIndex) {
            monthSumArray[monthIndex] += Precipitation[yearIndex][monthIndex];
            thisYear += Precipitation[yearIndex][monthIndex];
        }
        
        yearSumArray[yearIndex] = thisYear;
    }
    
    printf("The Average of Precipitation\n");
    
    float allYearsSum = 0.0;
    for(int i = 0 ; i < YEAR_COUNT; ++i ) {
        allYearsSum += yearSumArray[i];
    }
    printf("for %d year%sis:\n%.1f\n\n", YEAR_COUNT, YEAR_COUNT > 1 ? "s " : " ",  allYearsSum /5);
    
    printf("for each month in %d year%s:\n",YEAR_COUNT, YEAR_COUNT > 1 ? "s" : "");
    float singleMonthAverage[MONTH_COUNT];
    for (int i = 0; i < MONTH_COUNT; ++i) {
        float average = monthSumArray[i] / YEAR_COUNT ;
        singleMonthAverage[i] = average;
        printf("%.1f ", average);
        
        if (i == MONTH_COUNT-1) printf("\n\n");
    }
    
	return 0;
}
