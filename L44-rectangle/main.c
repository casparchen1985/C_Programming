#include <stdio.h>

int main(int argc, char **argv)
{
    double width = 0.0;
    double height = 0.0;
    
    printf("Please enter the width of rectangle: ");
    scanf("%le", &width);
    printf("Please enter the height of rectangle: ");
    scanf("%le", &height);
    printf("The width is %.4f, the height is %.4f\n", width, height);
     
    double perimter = 2 * (width + height);
    double area = width * height;
    
	printf("The perimeter is %.4f, the area is %.4f\n\n", perimter, area);
	
    return 0;
}
