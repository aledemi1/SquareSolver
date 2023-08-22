#include <stdio.h>
#include <TXLib.h>
#include <math.h>

int main(void)
{
    float a = INFINITY;  /* задаём такое значение чтобы отличить его от нормального*/
    float b = INFINITY;
    float c = INFINITY;
    float ans1;
    float ans2;

    printf("Вас приветсвует программа для поиска решений квадратных уравнений \n");

    printf("Квадратное уравнение имеет вид: \n");

    printf("ax^2 + bx + c = 0 \n");

    while(isfinite(a) == 0 or isfinite(b) == 0 or isfinite(c) == 0)  /* проверка на верный ввод(проверяем, что вводят числа) */
    {
        fflush(stdin);
        printf("Введиете коэффиценты a b c через пробел \n");
        scanf("%f %f %f", &a, &b, &c);
    }

    if (a >= 0.0 and a <= 0.0 and b >= 0.0 and b <= 0.0)    /* проверка на вариант 0x^2 + 0x + 7 = 0 */
    {
        printf("Сработала защита от дурака");
    }


    else if(a >= 0.0 and a <= 0.0)
    {
        if (c <= 0 and c>=0)
            printf("Ответ 0, это же очевидно!"); /* проверка на вариант 0x^2 + 7x + 0 = 0 => 7x = 0 => x= 0*/
        else
        {
            printf("Это уравнение является линейным, а не квадратным \n");
            ans1 = - c / b;
            printf("Решение этого уравнения: %f", ans1);
        }
    }

    else
    {

        float D;
        D = (float) pow(b,2.0) - 4*a*c;

        if (D<0)
        {
            printf("Вещественных корней нет! \n");
            printf("Но есть комплексные \n");
            float ans1_comp;
            float ans2_comp;
            ans1 = (float) - b / (2*a);
            ans2 = ans1;

            ans1_comp = (float) sqrt(-D)/(2*a);
            ans2_comp = - ans1_comp;

            if (ans1 >= 0 and ans1 <= 0)
                printf("Первый комплексный корень: ");
            else
                printf("Первый комплексный корень: %f", ans1);
            if (ans1_comp < 0)
                printf(" %f i", ans1_comp);
            else
                printf(" + %f i \n", ans1_comp);

            if (ans2 >= 0 and ans2 <= 0)
                printf("Второй комплексный корень: ");
            else
                printf("Второй комплексный корень: %f", ans2);
            if (ans2_comp < 0)
                printf(" %f i", ans2_comp);
            else
                printf(" + %f i", ans2_comp);

        }

        else if(D>=0 and D<=0)
        {
            ans1 = - b / (2 * a);
            printf("Решение этого уравнения только одно: %f", ans1);
        }

        else
        {
         ans1 = (float) (- b  + pow(D, 1 / 2.0)) / (2 * a);
         ans2 = (float) (- b  - pow(D, 1 / 2.0)) / (2 * a);

         printf("Решения этого уравнения: %f ", ans1);
         printf(" и  %f", ans2);

        }


    }



    return 0;
}
