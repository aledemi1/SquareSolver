#include <stdio.h>

int print_answer(int nomber_of_roots, float ans1, float ans2 );

int print_answer(int nomber_of_roots, float ans1, float ans2 )
{
    switch(nomber_of_roots)
    {

    case 0:
    {
        printf("Отсутствуют вещественные корни");
        break;
    }

    case 1:
    {
        printf("Единственный корень %f", ans1);
        break;
    }

    case 2:
    {
        printf("Первый корень %f \n", ans1);
        printf("Второй корень %f", ans2);
        break;
    }
    default:
    {
        printf("Ошибка!");
        //assert(0);
        break;
    }
    }

    return 0;
}