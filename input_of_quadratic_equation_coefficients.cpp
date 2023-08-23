#include <stdio.h>
#include <TXLib.h>
#include <math.h>
void input_of_quadratic_equation_coefficients(float* a_address, float* b_address, float* c_address);


void input_of_quadratic_equation_coefficients(float* a_address, float* b_address, float* c_address)
{

    while(isfinite(*a_address) == 0 || isfinite(*b_address) == 0 || isfinite(*c_address) == 0)  /*проверка на верный ввод(проверяем, что вводят числа)*/
    {

        printf("Введите коэффиценты a b c \n");
        scanf("%f%f%f", a_address, b_address, c_address);
        while (getchar() != '\n');

    }
}

