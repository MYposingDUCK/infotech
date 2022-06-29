#include <stdio.h>
#include <math.h>
#include <locale.h>

#define A -5
#define B 5
#define H 0.1

double func_sol(double x)
{
return (x * exp(x) + 2 * sin(x) - sqrt(fabs(pow(x,3) - pow(x,2))));
}

void func_sol2(double x)
{
double y;
int i;

y = 0;
i = 0;
 while(x < B)
 {
    y = (x * exp(x) + 2 * sin(x) - sqrt(fabs(pow(x,3) - pow(x,2))));
    if(x > -1 && x < 1 && y < fabs(x) && y > -fabs(x))
    {
        printf("%f %f",x,y);
        i ++;
    }
   x += H;     
 }
if(i == 0)
    printf("Такие значения отсутствуют!\n");
}

double remainder_sum(double x)
{
    double sum;
    double remd;
    double remc;

    sum = 0;
    remd = (x * exp(x) + 2 * sin(x) - sqrt(fabs(pow(x,3) - pow(x,2))));
    remc = modf(remd,&remd);
    if(remc > 0.3 && remc < 0.7)
        sum += remc;
    printf("%d\n",remc);
}

int main()
{
    setlocale(LC_ALL, "Rus");

    double digit;
    double counter;
    double remc;
    double sum;
  
    printf("-----Лабораторная работа номер 1-----\n\n");
    digit = 0;
    counter = A;
    sum = 0;
    while(counter < B)
    {
    digit = func_sol(counter);
    printf("%.1f   %.4f\n",counter,digit);
    remc = modf(digit,&digit);
    if(remc > 0.3 && remc < 0.7)
        sum += remc;
    counter += H;
    }
    printf("\n%.4f\n",sum);
    printf("\n\n-----Лабораторная работа номер 2-----\n\n");
    counter = A;
    func_sol2(counter);

 return(0);   
}