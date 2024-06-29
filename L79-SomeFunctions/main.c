#include <stdio.h>
#include <math.h>


float findSquareRoot(float input);
float absoluteValue(float input);
int gcd(int x, int y);

int main(int argc, char **argv){
    int gcd_a = 0;
    int gcd_b = 0;
    float powered = 0.0;
    printf("Find great common divisor:\nFirst = ");
    scanf("%d", &gcd_a);
    printf("Second = ");
    scanf("%d", &gcd_b);
    printf("GCD is: %d\n\n", gcd(gcd_a, gcd_b));
    
    printf("Find square root of ");
    scanf("%f", &powered);
    printf("The answer is %f\n", findSquareRoot(powered));
	return 0;
}


float findSquareRoot(float input) {
//    const float epsilon = 0.00001;
//    float guess = 1.0;
    float result = 0.0;
    
    if (input < 0) {
        printf("Illeagal number: Negative Number\n");
        result = -1.0;
    } else {
//        while (absoluteValue( guess * guess - input) >= epsilon) {
//            guess = ( input / guess + guess) /  2.0;
//        }
        result = sqrtf(input);
    }
    return result;
}

float absoluteValue(float input) {
    if (input < 0)  input *= -1 ;
//    printf("[abs] absValue:%.1f\n", input);
    return input;
}

int gcd(int x, int y) {
//    printf("[gcd] x:%d, y:%d\n", x, y);
    int absX = (x < 0) ? absoluteValue((float)x) : x;
    int absY = (y < 0) ? absoluteValue((float)y) : y;
    if (absY == 0) return absX;
    return gcd(absY, absX % absY);
}