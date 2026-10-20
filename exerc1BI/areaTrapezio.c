#include <stdio.h>

int main()
{
    int B,b,h,area;
    
    printf("Qual a base maior do trapezio?");
    scanf("%d",&B);
    
    printf("Qual a base menor do trapezio?");
    scanf("%d",&b);
    
    printf("Qual a altura do trapezio?");
    scanf("%d",&h);
    
    area = (B + b) * h / 2;
    
    printf("Area do trapezio: %d",area);
    

    return 0;
}
