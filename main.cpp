#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include <math.h>
#include <errno.h>
#include "input_of_quadratic_equation_coefficients.h"
#include "solve.h"
#include "print_answer.h"





void print_welcome_message();
//! initializing variables and calling necessary functions


//{---------------------------------------------------------------------------------------------
//!
//!
//! @param a first coefficient of the quadratic equation
//! @param b second coefficient of the quadratic equation
//! @param c third coefficient of the quadratic equation
//! @param ans1 first root of the quadratic equation
//! @param ans2 second root  of the quadratic equation
//! @param nomber_of_roots number of roots of the quadratic equation
//!
//! @note coefficient of the quadratic equation gets in function: input_of_quadratic_equation_coefficients
//! @note the roots of the equation and their number are considered in the function: solve
//! @note the output of the correct roots occurs as a result of the function: print_answer
//!
//!
//!
//! @note Operation logic:
//! @note 1 initialization: coefficients of the quadratic equation
//! @note 2 function (input_of_quadratic_equation_coefficients) get entering variables from the keyboard
//! @note 3 initialization: roots of the quadratic equation and number of roots
//! @note 4 function(solve) for counting the number of real roots
//! @note 5 function(print_answer) print correct roots
//}-



int main(int argc, char* argv[])
{
    print_welcome_message();

    float a = NAN;
    float b = NAN;
    float c = NAN;

    if(argc == 4 )
    {
        printf("Введённые вами коэффиценты через командную строку %s %s %s \n", argv[1], argv[2], argv[3]);
        char arg_error[20] = " ";
        char* arg_error_address = arg_error;
        int flag = 0;

        // echo "1 2 12fdsfsd" | result_main
        // 1000000000000 1 0
        a = (float) strtod(argv[1], &arg_error_address);
        if (arg_error_address == argv[1]) flag = 1;

        b = (float) strtod(argv[2], &arg_error_address);
        if (arg_error_address == argv[2]) flag = 1;

        c = (float) strtod(argv[3], &arg_error_address);
        if (arg_error_address == argv[3]) flag = 1;

        printf("Прочитано как: a = %f, b = %f, c = %f \n", a, b, c);

        if (( errno == ERANGE ) || flag ||
         ( a == HUGE_VAL ) || ( a == -HUGE_VAL ) ||
         ( b == HUGE_VAL ) || ( b == -HUGE_VAL ) ||
         ( c == HUGE_VAL ) || ( c == -HUGE_VAL ))
        {
            printf("Вы не смогли правильно ввести коэффиценты через командную строку \n \n \n");
            a = NAN;
            b = NAN;
            c = NAN;
            input_of_quadratic_equation_coefficients( &a, &b,  &c);

        }
    }

    else
        input_of_quadratic_equation_coefficients( &a, &b,  &c);  //ввод



    float ans1 = NAN;
    float ans2 = NAN;

    int nomber_of_roots = solve(a, b, c, &ans1, &ans2);


    print_answer(nomber_of_roots, ans1, ans2);

    return 0;
}

//! print welcome message and kind of quadratic equation
//{---------------------------------------------------------------------------------------------
//!
//!
//! @see input_of_quadratic_equation_coefficients(), solve(), print_answer()
//}-
void print_welcome_message()
{
    printf("Вас приветсвует программа для поиска решений квадратных уравнений \n");

    printf("Квадратное уравнение имеет вид: \n");

    printf("ax^2 + bx + c = 0 \n");
}



