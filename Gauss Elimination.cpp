#include<stdio.h>
int main() 
{
    float a[10][10], x[10], ratio;
    int n, i, j, k;
    // Step 1: Input
    printf("Enter number of equations: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix [A|B]:\n");
    for(i = 0; i < n; i++) 
	{
        for(j = 0; j <= n; j++) 
		{
            scanf("%f", &a[i][j]);
        }
    }
    // Step 2: Forward Elimination
    for(i = 0; i < n-1; i++) 
	{
        for(j = i+1; j < n; j++) 
		{
            ratio = a[j][i] / a[i][i];
            for(k = i; k <= n; k++) 
			{
                a[j][k] = a[j][k]- ratio * a[i][k];
            }
        }
    }
    // Step 3: Back Substitution
    x[n-1] = a[n-1][n] / a[n-1][n-1];
    for(i = n-2; i >= 0; i--) 
	{
        x[i] = a[i][n];
        for(j = i+1; j < n; j++) 
		{
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    // Step 4: Display
    printf("\nSolution:\n");
    for(i = 0; i < n; i++) 
	{
        printf("x%d = %.3f\n", i+1, x[i]);
    }
    return 0;
}
