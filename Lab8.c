#include <stdio.h>
#include <math.h>
#include <locale.h>

int task0(char ch1, char ch2, int count);
int task1(int m, int n);
int task2(double step);
double task3(double a, int n);

int main()
{
    setlocale(LC_ALL, "Ru");
    int count;
    char ch1, ch2;
    printf("Введите количество символов: ");
    if (scanf("%d", &count) != 1 || count < 0)
        return 1;
    printf("Введите первый символ: ");
    scanf(" %c", &ch1);
    printf("Введите второй символ: ");
    scanf(" %c", &ch2);

    task0(ch1, ch2, count);

    int m, n_task1;
    printf("Введите m: ");
    scanf("%d", &m);
    printf("Введите n: ");
    scanf("%d", &n_task1);

    int sum_result = task1(m, n_task1);
    printf("результат %d\n", sum_result);

    int power_n, limit_m;
    printf("Введите максимальную степень n: ");
    scanf("%d", &power_n);
    printf("Введите число m: ");
    scanf("%d", &limit_m);

    for (int i = 0; i <= power_n; i++)
    {
        long long res = (long long)pow(2, i);
        printf("2^%-2d = %10lld\n", i, res);
    }
    long long final_res = (long long)pow(2, power_n);
    if (final_res >= 1024 && final_res % 1024 == 0)
    {
        printf("Результат: %lldK\n", final_res / 1024);
    }
    printf("Степени до числа %d в формате K:\n", limit_m);
    for (int i = 0;; i++)
    {
        double val = pow(2, i);
        if (val > limit_m)
            break;
        printf("2^%d = %.1fK\n", i, val / 1024.0);
    }

    double step;
    printf("Введите шаг табуляции: ");
    if (scanf("%lf", &step) != 1 || step <= 0)
    {
        printf("Некорректный шаг!\n");
        return 1;
    }
    task2(step);

    double a_val;
    int n_task3;
    printf("Введите a: ");
    scanf("%lf", &a_val);
    printf("Введите число: ");
    if (scanf("%d", &n_task3) != 1 || n_task3 < 0)
    {
        printf("Некорректное значение n!\n");
        return 1;
    }

    double product_result = task3(a_val, n_task3);
    printf("Значение выражения: %.4f\n", product_result);

    return 0;
}

int task0(char ch1, char ch2, int count)
{
    putchar('+');
    for (int start = 1; start <= count; start++)
    {
        if (start <= count / 2)
            putchar(ch1);
        else
            putchar(ch2);
        putchar('!');
    }
    putchar('+');
    putchar('\n');
    return 0;
}

int task1(int m, int n)
{
    int s = 0, k = 1;
    for (int i = m; i >= n; i--)
    {
        s += i;
        printf("выполнено %d раз\n", k++);
    }
    return s;
}

int task2(double step)
{
    double start_x = 0.1;
    double end_x = 2.2;
    printf("_______________________\n");
    printf("|    x    |    f(x)   |\n");
    printf("|---------|-----------|\n");
    for (double x = start_x; x <= end_x + 1e-9; x += step)
    {
        double cos_val = cos(x + 1.0);
        double y = (x * x) - (cos_val * cos_val);
        printf("|  %5.2f  |  %8.4f |\n", x, y);
    }
    printf("-----------------------\n");
    return 0;
}

double task3(double a, int n)
{
    double product = 1.0;
    for (int i = 0; i <= n; i++)
    {
        product *= (a - i * n);
    }
    return product;
}