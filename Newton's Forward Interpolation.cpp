#include <stdio.h>
int main() 
{
    int n, i, j;
    float x[20], y[20][20], xp, h, u, sum;
    // Input number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);
    // Input x and y values
    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);
    printf("Enter y values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i][0]);
    // Construct forward difference table
    for (j = 1; j < n; j++)
        for (i = 0; i < n - j; i++)
            y[i][j] = y[i+1][j-1] - y[i][j-1];
    printf("\nForward Difference Table:\n");
    for (i = 0; i < n; i++) {
        printf("%0.2f", x[i]);
        for (j = 0; j < n - i; j++)
            printf("\t%0.2f", y[i][j]);
        printf("\n");
    }
    printf("\nEnter value of x to interpolate: ");
    scanf("%f", &xp);
    // Newton's Forward Interpolation Formula
    h = x[1] - x[0];
    u = (xp - x[0]) / h;
    sum = y[0][0];
    float term = 1;
    for (i = 1; i < n; i++) {
        term = term * (u - (i - 1)) / i;
        sum = sum + term * y[0][i];
    }
    printf("\nInterpolated value at x = %.2f is %.6f\n", xp, sum);
    return 0;
}
