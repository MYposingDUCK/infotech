#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define A 1
#define B 30

int	ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	if (!(s = malloc(sizeof(*s) * len + 1)))
		return (NULL);
	while (i < len)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static size_t	ft_intlen(int n)
{
	size_t	l;

	if (n == 0)
		return (1);
	l = 0;
	if (n < 0)
		l++;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	size_t	len;
	size_t	m;
	char	*rtrn;

	m = 0;
	len = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(rtrn = (char *)malloc(len + 1)))
		return (NULL);
	rtrn[len] = '\0';
	if (n < 0)
	{
		rtrn[0] = '-';
		n *= -1;
		m = 1;
	}
	while (len-- > m)
	{
		rtrn[len] = '0' + n % 10;
		n /= 10;
	}
	return (rtrn);
}


int	ft_isdigit(char *c)
{
	
    if (*c > 47 && *c < 58)
		return (1);
	return (0);
}

void t_search(int *arr)
{
 int i;
 int b;

 i = 0;
 while(i < 30)
 {
    if(arr[i]%2 == 0 || arr[i]%3 == 0 || arr[i]%5 == 0 || arr[i]%7 == 0 ||
     arr[i]%11 == 0 || arr[i]%11 == 13)
    {
        b = 0; 
        while( arr[i] > 0) 
        { 
            b = 10 * b + (arr[i] % 10); 
            arr[i] /= 10; 
        } 
        arr[i] = b;
    }
    i++;
 }
}

int q_search(int *arr)
{
    int i;
    int q;
    int min;
    char *str;
    char *p;
    
    i = 0;
    min = 0;
    while(i < 30)
    {   
       str = ft_itoa(arr[i]); 
       p = str; 
        while(*str != '\0')
        {
            if(*str == 51)
            {   
                if(min == 0)
                    min = arr[i];
                q = arr[i];
                if(q < min)
                    min = q;              
            }
            str++;
        }
        i++;
        free(p);
        if(i == 30 && min == 0)
            return(1);
    }
    printf("min = %d \n\n",min);
    return(0);
}

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
    printf("\n\n\n");
}

void bubble_sort(int *arr)
{
    int     i;
    int   tmp;
    int  sort;
    
    sort = 1;

    while(sort)
    {
        sort = 0;
        i = 1;
        while(i < 30)
            {
                if(arr[i] < arr[i - 1])
                {
                    tmp = arr[i - 1];
                    arr[i - 1] = arr[i];
                    arr[i] = tmp;
                    sort = 1; 
                }
                i++;
            }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int      array[30];
    char         a[15];
    char         b[15];
    char       var[15];

    printf("-----Лабораторная работа номер 6-----\n\n");
    printf("Привет! Эта программа работает с массивами!.\nВам будет предложено задать некоторые параметры!");
    printf("Если вы хотите задать диапазон значений элементов массива нажмите 1.\nВ других случаях это значение будет по умолчанию!\n");
    scanf("%s", &var);
    if(ft_isdigit(var) == 0 || ft_strlen(var) > 15)
     return (1);
    if(atoi(var) == 1)
    {
        //  min max value array 
        printf("Введите минимальное значение элемента\n");
        scanf("%s", &a);
        if(ft_isdigit(a) == 0 || ft_strlen(a) > 15) 
            return (1);
        printf("Введите максимальное значения элмента\n");
        scanf("%s", &b);
        if(ft_isdigit(b) == 0 || ft_strlen(a) > 15)
            return (1);
        printf(" Диапазон значений: %s %s \n", a, b);
        init_auto_array(array, atoi(a), atoi(b));
        q_search(array);
        print_array(array);
        bubble_sort(array);
        print_array(array);
        t_search(array);
        print_array(array);
    }
    else
    {
     init_array(array);
     q_search(array);
     print_array(array);
     bubble_sort(array);
     print_array(array);
     t_search(array);
     print_array(array);
    }

    return(0);
}