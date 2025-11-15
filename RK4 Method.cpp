#include<stdio.h>
float f(float x,float y) 
{
    return (x+y);
}
int main() 
{
    float x0,y0,xn,h,x,k1,k2,k3,k4,yn;
    printf("Enter initial values of x and y: ");
    scanf("%f %f",&x0,&y0);
    printf("Enter the step size h: ");
    scanf("%f",&h);
    printf("Enter the value of x at which y is required: ");
    scanf("%f",&xn);
    x=x0;
    while (x<xn) 
	{
        k1=h * f(x,y0);
        k2=h * f(x + h /2, y0 + k1 /2);
        k3=h * f(x + h /2, y0 + k2 /2);
        k4=h * f(x + h, y0 + k3);
        yn=y0 + (k1 + 2 * k2 + 2 * k3 + k4)/6;
        printf("At x = %.4f, y = %.4f\n", x + h,yn);
        x=x+h;
        y0=yn;
    }
    printf("\nValue of y at x = %.4f is %.4f\n",xn,yn);
    return 0;
}
