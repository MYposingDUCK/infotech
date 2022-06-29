#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define A 1
#define B 30


void init_array(int *arr)
{
    int i;

    i = 0;
    printf("Последовательно введите значения массива\n");
    while(i < 30)
    {   
        printf("Эллемент %d = ", i + 1);
        scanf("%d", &arr[i]);
        i++;
    }
}

void init_auto_array(int *arr, int start, int end)
{
    int i;

    i = 0;
    while(i < 30)
    {
        arr[i] = rand() % end;
        if(arr[i] >= start && arr[i] <= end)
            i++;
    }
}

void print_array(int *arr)
{
    int i;

    i = 0;
    while(i < 30)
    {
        printf("%d, ", arr[i]);
        i++;
    }
}

void array_factors(int *array)
{
int i;
int x;
int j;
int n;

i = 0;
j = 0;
while(i < 30)
{
x = array[i];
j = i + 1;
    while(j < 30)
    {
        if (x/2 < array[j])
            j++;
        else
        {
            n = array[j];
            j = 0;
            if( (n * array[j]) == x )
            {
                printf("%d",n * array[j]);
            }
            j++;
        }    
    }
i++;
}


}


int main()
{
    int array[30];
    int         a;
    int         b;
    int       var;
    
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    var = 1;
    a = 0;
    b = 0;
    printf("Привет! Эта программа работает с массивами!.\nВам будет предложено задать некоторые параметры!\n");
    printf("Если вы хотите заполнить массив автоматически нажмите 1.\nЕсли хотите задать значения в ручную нажмите 2\n");
    scanf("%d", &var);
    if(var == 1)
    {
        printf("Введите минимальное значение элемента\n");
        scanf("%d", &a);
        printf("Введите максимальное значения элмента\n");
        scanf("%d", &b);
        printf(" Диапазон значений: %d %d \n", a, b);
        init_auto_array(array, a, b);


        print_array(array);
        array_factors(array);
    }
    else if( var == 2)
    {
        init_array(array);
        print_array(array);
    }
    else
    {
        printf("Ошибка! Вы ввели не верное значение!\n");
    }
return(0);
}