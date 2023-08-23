#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "input_of_quadratic_equation_coefficients.h"
#include "solve.h"
#include "print_answer.h"

void print_welcome_message();

int main(void)
{
    print_welcome_message(); //приветсвие

    float a = NAN;  /* инициализация переменных*/
    float b = NAN;
    float c = NAN;

    input_of_quadratic_equation_coefficients( &a, &b,  &c);  //ввод

    float ans1 = NAN;
    float ans2 = NAN;

    int nomber_of_roots = NAN; //количество корней

    nomber_of_roots = solve(a,b,c, &ans1, &ans2);   //решение

    print_answer(nomber_of_roots, ans1, ans2);   //вывод ответа

    return 0;
}

void print_welcome_message()
{
    printf("Вас приветсвует программа для поиска решений квадратных уравнений \n");

    printf("Квадратное уравнение имеет вид: \n");

    printf("ax^2 + bx + c = 0 \n");
}



