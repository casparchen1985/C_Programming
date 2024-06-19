#include <stdio.h>

#define BASICPAYDOLLAR 12.00
#define OVERTIMEPAYDOLLAR BASICPAYDOLLAR * 1.5
#define BASICPAYHOURS 40
#define FIRSTTAXSTAGE 300  // $ 0 ~ 300
#define FIRSTTAXRATE 0.15
#define SECONDTAXSTAGE 150  // $ 301 ~ 450
#define SECONDTAXRATE 0.20
#define RESTTAXRATE 0.25

int main(int argc, char **argv)
{ 
    int maxWorkHours = 24 * 7;
    int totalHours = 0;
    double grossPay = 0.0;
    double firstTaxAmount = 0.0;
    double secondTaxAmount = 0.0;
    double restTaxAmount = 0.0;
    // double taxAmount = 0.0;
    
    // user input
	printf("How much hour do you work every week?: ");
    scanf("%d", &totalHours);

    // validate work hours
    if (totalHours < 0 || totalHours > maxWorkHours) totalHours = 0;
    
    // calculate grossPay
    if (totalHours <= BASICPAYHOURS) {
        grossPay = totalHours * BASICPAYDOLLAR;
    } else {
        int overtimeHours = totalHours - BASICPAYHOURS;
        printf("overtimePayDoallar=%.2f,\novertimeHours=%d, overtimePay=%.2f\n", OVERTIMEPAYDOLLAR, overtimeHours, overtimeHours * OVERTIMEPAYDOLLAR);
        grossPay = (BASICPAYHOURS * BASICPAYDOLLAR) + (overtimeHours * OVERTIMEPAYDOLLAR);
    }
    
    printf("totalHours=%d, grossPay=%.2f\n", totalHours, grossPay);
    
    if (grossPay <= FIRSTTAXSTAGE) {
        firstTaxAmount = grossPay * FIRSTTAXRATE;
    } else if (grossPay <= SECONDTAXSTAGE) {
        firstTaxAmount = FIRSTTAXSTAGE * FIRSTTAXRATE;
        secondTaxAmount = (grossPay - FIRSTTAXSTAGE) * SECONDTAXRATE;
    } else if (grossPay > SECONDTAXSTAGE) {
        firstTaxAmount = FIRSTTAXSTAGE * FIRSTTAXRATE;
        secondTaxAmount = SECONDTAXSTAGE* SECONDTAXRATE;
        restTaxAmount = (grossPay - FIRSTTAXSTAGE - SECONDTAXSTAGE) * RESTTAXRATE;
    }
    
     printf("taxAmount=%.2f + %.2f + %.2f, netPay=%.2f\n\n", 
            firstTaxAmount, 
            secondTaxAmount, 
            restTaxAmount, 
            grossPay - firstTaxAmount- secondTaxAmount - restTaxAmount
    );

	return 0;
}
