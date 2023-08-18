#include <stdio.h>
#include <TXLib.h>
#include <math.h>
int main(void)
{
    float a;
    float b;
    float c;
    float ans1;
    float ans2;

    printf("Вас приветсвует программа для решения квадратных уравнений\n");

    printf("Квадратное уравнение имеет вид: \n");

    printf("ax^2 + bx + c = 0 \n");

    printf("Введиете коэффицент a \n");
    scanf("%f", &a);

    printf("Введиете коэффицент b \n");
    scanf("%f", &b);

    printf("Введиете коэффицент c \n");
    scanf("%f", &c);

    if (a >= 0.0 and a <= 0.0 and b >= 0.0 and b <= 0.0)
    {
        printf("Сработала защита от дурака");
    }


    else if(a >= 0.0 and a <= 0.0)
    {
        printf("Это уравнение является линейным, а не квадратным \n");
        ans1 = - c / b;
        printf("Решение этого уравнения: %f", ans1);
    }

    else
    {

        float D;
        D = (float) pow(b,2.0) - 4*a*c;

        if (D<0)
        {
         printf("Решений нет!");

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
         printf(" и %f", ans2);

        }


    }



    return 0;
}
