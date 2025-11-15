#include<stdio.h>
#include<math.h>
double f(double x) 
{
    return 1/(1 + x * x);
}
int main() 
{
    int n,i;
    double a,b,h,x,sum=0.0;
    printf("Enter lower limit a: ");
    scanf("%lf",&a);
    printf("Enter upper limit b: ");
    scanf("%lf",&b);
    printf("Enter number of intervals (even number): ");
    scanf("%d",&n);
    if (n%2!=0) 
	{
        printf("Number of intervals must be even!\n");
        return 0;
    }
    h=(b-a)/n;
    sum=f(a)+f(b);
    for (i=1;i<n;i++) 
	{
        x=a+i*h;
        if (i%2==0)
            sum +=2*f(x);
        else
            sum +=4*f(x);
    }
    sum = sum * h /3;
    printf("Approximate value of the integral = %lf\n",sum);
    return 0;
}
