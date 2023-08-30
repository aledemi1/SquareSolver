#include <stdio.h>
#include <TXLib.h>
#include <math.h>

#include "input_of_quadratic_equation_coefficients.h"



//{---------------------------------------------------------------------------------------------
//!
//! @brief the user enters values until he enters them correctly
//!
//! @note Program do following
//! @note 1) check nullptr problem
//! @note 2) initialization
//! @note 3) program read coefficients and sets the value of the variables if the user enters them correctly
//! @note 4) line cleaning
//!
//!
//! @param a_address, b_address, c_address (address of coefficients of the quadratic equation)
//!
//! @return a, b, c coefficients of the quadratic equation
//!
//! @see solve(), print_answer(), main()
//}-


void input_of_quadratic_equation_coefficients(double* a_address, double* b_address, double* c_address)
{
    assert( a_address != nullptr &&
            b_address != nullptr &&
            c_address != nullptr );


    double a = NAN;
    double b = NAN;
    double c = NAN;

    while(!isfinite(a) ||
          !isfinite(b) ||
          !isfinite(c))  //проверка на верный ввод(проверяем, что вводят числа)
    {


        printf("Введите коэффиценты a b c \n");

        fscanf(stdin, "%lf %lf %lf", &a, &b, &c);

        int check_char =  getchar();
        if (!(check_char == '\n' || check_char == EOF ))
        {

            while (!(check_char == '\n' || check_char == EOF ))
            {
                check_char =  getchar();
            }
            a = NAN;
            b = NAN;
            c = NAN;

        }



        assert(check_char != EOF && "Программа так не работает!!! Она не считывает данные через echo!!!!");
    }

    *a_address = a;
    *b_address = b;
    *c_address = c;

}

