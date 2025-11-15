#include<stdio.h>
float f(float x,float y)
{
    return (x+y);
}
int main()
{
    float x0, y0, xn, h, yn;
    int n, i;
    printf("Enter initial values of x and y: ");
    scanf("%f %f",&x0,&y0);
    printf("Enter step size (h): ");
    scanf("%f",&h);
    printf("Enter value of x at which y is required: ");
    scanf("%f",&xn);
    n = (xn - x0)/h; 
    for(i=0;i<n;i++) 
	{
        yn=y0 + h * f(x0,y0);
        x0=x0 + h;
        y0=yn;
        printf("At x = %.4f, y = %.4f\n",x0,y0);
    }
    printf("\nApproximate value of y at x = %.4f is %.4f\n",xn,yn);
    return 0;
}
