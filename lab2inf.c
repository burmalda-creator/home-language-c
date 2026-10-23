#include <stdio.h>

int countDivisors(int num, int d)
{
    if ((long long)d * d > num)
        return 0;
    if (num % d == 0)
        return ((long long)d * d == num ? 1 : 2) + countDivisors(num, d + 1);
    return countDivisors(num, d + 1);
}

int printChain(int cur, int m, int k)
{
    if (cur > m)
        return 0;

    int found = 0;
    if (countDivisors(cur, 2) == k) {
        printf("%d ", cur);
        found = 1;
    }
    return found + printChain(cur + 1, m, k);
}

int main(void)
{
    int n, m, k;

    printf("Введите N, M и K: ");
    if (scanf("%d %d %d", &n, &m, &k) != 3) {
        printf("Ошибка: нужно ввести три целых числа.\n");
        return 1;
    }

    if (n <= 0 || m <= 0 || k <= 0) {
        printf("Ошибка: числа должны быть натуральными (> 0).\n");
        return 1;
    }
    if (n > m) {
        printf("Ошибка: N должно быть не больше M (N <= M).\n");
        return 1;
    }

    printf("Цепочка чисел из диапазона [%d; %d] с %d собственными делителями:\n", n, m, k);
    int cnt = printChain(n, m, k);

    if (cnt == 0)
        printf("таких чисел нет");
    printf("\n");

    return 0;
}


