#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#define max 10
    void BubbleSort(double m[], int n)
{
    int i, j;
    double tmp;
    for(i = 0; i < n; i++)
        for(j = 0; j < n-1; j++)
            if(m[j] > m[j+1])
            {
                tmp = m[j];
                m[j] = m[j+1];
                m[j+1] = tmp;
            }
}
int OtriChisla()
{
    int i, n, j, a;
    int g[max];
    srand(time(NULL));
    FILE * file;
    file = fopen("vvod_chisel.txt", "w");
    if (file == NULL)
    {
        printf("ERROR, Bad file");
        return 1;
    }
    else
    {
        for(i = 0; i < max; i++) 
        { 
            a = -100 + rand() % 200;
            fprintf(file, "%d\n", a); 
        }
    }
    fclose(file);
    
        file = fopen("vvod_chisel.txt", "r");
        for(i = 0; i < max || !feof(file); i++) 
        { 
            fscanf(file, "%d", &g[i]); 
        }
        fclose(file);

        printf("Вы ввели такой массив: ");
        for (i = 0; i < max; i++)
            printf("%d ", g[i]);

        printf("\n");
        n = max;
        for (i = 0; i < n; i++)
            if (g[i] < 0)
            {
                n = n - 1;
                for (j = i; j < n; j++)
                    g[j] = g[j + 1];
                i--;
            }
        printf("Результат: ");
        for (i = 0; i < n; i++)

            printf("%d, ", g[i]);

    }

int KorniYravnenia()
{

    double a, b, c, d, x1, x2;
    printf("\nax ^ 2 + bx + c = 0");
    printf("\nЧему равен первый коэффициент? ");
    scanf("%lf", &a);
    printf("Чему равен второй коэффициент? ");
    scanf("%lf", &b);
    printf("Чему равен третий коэффициент? ");
    scanf("%lf", &c);
    d = pow(b, 2) - (4.0 * a * c);
    printf("D = %lf", d);
        if(d < 0)
        {
            printf("\nD < 0");
        }
        else if(d == 0)
        {
            printf("\nD = 0");
            x1 = (-1.0 * b) / (2.0 * a);
        printf("x1,2 = %lf", x1);
        }
        else{
                printf("\nD > 0");
                x1 = ((-1.0 * b) + sqrt(d)) / (2.0 * a);
                x2 = ((-1.0 * b) - sqrt(d)) / (2.0 * a);
                printf("\nx1 = %lf", x1);
                printf("\nx2 = %lf", x2);
            }
}
double AlgSort()
{
    double m[max];
    int i;
    srand(time(NULL));
    for(i = 0;i < max; i++)
    {
        m[i] = rand() % 100 / 10.;
    }
    printf("Сгенерированный массив: ");
    for(i = 0; i < max; i++) printf("%.1lf ", m[i]);
    printf("%.1lf\n", m[i]);
    BubbleSort(m, max);
    printf("Упорядоченный массив: ");
    for(i = 0;i < max; i++) printf("%.1lf ", m[i]);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL , "RUS");
    int VSE;
    printf("[1]Корни квадратного уравнения.\n[2]Алгоритм сортировки массива (Алгоритм пузырька).\n[3]Уничтожение всех отрицательный чисел в массиве.\n");
    printf("Введите значение: ");
    scanf("%d",&VSE);
    switch(VSE)
    {
        case 1: KorniYravnenia();
            break;
        case 2: AlgSort();
            break;
        case 3: OtriChisla();
            break;
        default: printf("ERROR");
    }
    printf("\n");
    return 0;
}

