#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
 
int main(int argc, char *argv[])
{
    int n,i;
    printf("Introduce la precision del calculo (n > 0): ");
    scanf( "%i", &n);
    double PI25DT = 3.141592653589793238462643;
    double h = 1.0 / (double) n;
    double sum = 0.0;
 
    #pragma omp parallel for shared( sum )
    for (i = 1; i <= n; i++) {
        double x = h * ((double)i - 0.5);
        sum += (4.0 / (1.0 + x*x));
    }
 
    double pi = sum * h;
    printf("El valor aproximado de PI es: %.4lf , con un error de %.4lf\n\n", pi, fabs(pi -PI25DT));
    return 0;
}