#include <stdio.h>
#include <TXLib.h>
#include <math.h>

// TODO: split this in multiple files by purpose!

void data_input(float* a_address, float* b_address, float* c_address);

int solve(float a, float b , float c, float* ans1_address, float* ans2_address, int* nomber_of_roots);

void print_welcome_message();

int check_that_number_is_zero(float num);

int print_answer(int nomber_of_roots, float ans1, float ans2);

int main(void)
{

    print_welcome_message(); //приветсвие

    float a = NAN;  /* инициализация переменных*/
    float b = NAN;
    float c = NAN;

    data_input( &a, &b,  &c);  //ввод

    float ans1 = NAN;
    float ans2 = NAN;

    int nomber_of_roots = NAN;

    solve(a,b,c, &ans1, &ans2, &nomber_of_roots);   //решение

    print_answer(nomber_of_roots, ans1, ans2);   //вывод ответа

    return 0;
}

void data_input(float* a_address, float* b_address, float* c_address)
{

    while(isfinite(*a_address) == 0 || isfinite(*b_address) == 0 || isfinite(*c_address) == 0)  /*проверка на верный ввод(проверяем, что вводят числа)*/
    {
        fflush(stdin); // TODO: Don't do this
        printf("Введиете коэффиценты a b c через пробел \n");
        scanf("%f %f %f", a_address, b_address, c_address);
    }
}

int check_that_number_is_zero(float num)
{
    const float allowable_comparison_error = (float) 0.0001;  //допустимая погрешность при сравнении
    return((num + allowable_comparison_error > 0) & (num - allowable_comparison_error < 0));
}

int solve(float a, float b, float c, float* ans1_address, float* ans2_address, int* nomber_of_roots)
{
    if (check_that_number_is_zero(a))
    {
        if (check_that_number_is_zero(b))
        {
            *nomber_of_roots = 10;
            return 0;

        }

        else
        {
            *ans1_address = (float) (- c) / b;
            if (check_that_number_is_zero(*ans1_address))
                *ans1_address = 0;
            *nomber_of_roots = 1;
            return 0;
        }
    }

    float D = b*b - 4*a*c;

    if (D<0)
    {
        *nomber_of_roots = 0;
        return 0;
    }
    else if(D>0)
    {
        *ans1_address = (float) (-b + sqrt(D)) / (2*a);
        *ans2_address = (float) (-b - sqrt(D)) / (2*a);
        if (check_that_number_is_zero(*ans1_address))
                *ans1_address = 0;
        if (check_that_number_is_zero(*ans2_address))
                *ans2_address = 0;
        *nomber_of_roots = 2;
        return 0;
    }
    else
    {
        *ans1_address = (-b) / (2*a);
        if (check_that_number_is_zero(*ans1_address))
                *ans1_address = 0;
        *nomber_of_roots = 1;
        return 0;
    }
}

void print_welcome_message()
{
    printf("Вас приветсвует программа для поиска решений квадратных уравнений \n");

    printf("Квадратное уравнение имеет вид: \n");

    printf("ax^2 + bx + c = 0 \n");
}

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
        printf("Ошибка!"); // TODO: read about asserts, can you apply here?
        break;
    }
    }

    return 0;
}
