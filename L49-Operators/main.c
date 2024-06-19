#include <stdio.h>

int main(int argc, char **argv)
{
    long inputMinutes = 0;
    int yearCriteria = 60 * 24 * 365;
    double dayCriteria = 60.0 * 24;
    int year = 0;
    double day = 0.0;
    
    printf("How much minute you want to convert?: ");
    scanf("%ld", &inputMinutes);
    
    // validate input
    if (inputMinutes > 0) {
        
        // reach the year criteria
        if (inputMinutes >= yearCriteria) {
            year = inputMinutes / yearCriteria;
            inputMinutes /= yearCriteria;
        };
        
        day = inputMinutes / dayCriteria;
    };
    
    printf("Result is %d year plus %.3f day.\n\n", year, day);
    
	return 0;
}
