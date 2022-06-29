#include <stdio.h>
#include <math.h>


int my_power(double x, double y)
{
    double p;
    p = x;
    if(y == 1)
        return(x);
    while(y > 1)
    {
        x *= p;
        y--;
    }
return(x);
}

double Sum1(int n)
{
double i;
double sum;
double k;

i = 1;
sum = 0;
k = 0;
 while(i <= n)
 {
    k =  my_power(-1,i) * ( i / (my_power(i,4) + 1 ));
    sum += k;
    printf("%.0lf %lf\n",i,k); // debug
    i++;
 }
return (sum);
}

double Sum2(double eps)
{
double i;
double sum;
double k;


i = 1;
k = 0;
k =  my_power(-1,i) * ( i / (my_power(i,4) + 1 ));
sum = k;
printf("%f\n",k); // debug
i++;
 while(fabs(k) >= eps)
 {
    
    k = my_power(-1,i) * ( i / (my_power(i,4) + 1 ));
    if(fabs(k) <= eps)
        return(sum);
    sum += k;
    printf("%f\n",k); // debug
    i++;
 }
return (sum);
 }

int main()
{   
    int n;
    double eps;
    double line;

    eps = 0;
    n = 0;
    printf("Input n ");
    scanf("%i", &n);
    line = Sum1(n);
    printf("sum = %.10f\n",line);
    printf("Input eps ");
    scanf("%lf", &eps);
    line = Sum2(eps);
    printf(" sum = %lf\n",line);
    return (0);
}
