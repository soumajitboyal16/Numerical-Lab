#include<stdio.h>
#include<math.h>
double f(double x) 
{
    return x * x;
}
int main() 
{
    double a,b;  
    int n;        
    double h,sum = 0.0;
    printf("Enter lower limit a: ");
    scanf("%lf",&a);
    printf("Enter upper limit b: ");
    scanf("%lf",&b);
    printf("Enter number of subintervals n: ");
    scanf("%d",&n);
    h=(b-a)/n;  
    sum=f(a)+f(b);
    for(int i=1;i<n;i++) 
	{
        double x=a+i*h;
        sum +=2*f(x);
    }
    sum=(h/2)*sum;
    printf("Approximate value of integral = %lf\n",sum);
    return 0;
}
