#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "input_of_quadratic_equation_coefficients.h"

//! the user enters values until he enters them correctly

    /*!
\param a_address, b_address, c_address (address of coefficients of the quadratic equation)
\return a, b, c coefficients of the quadratic equation
*/

//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 start cycle(while coefficients of the quadratic equation have not correct values)
//! @note 2 user enter coefficients
//! @note 3 program read their and sets the value of the variables if the user enters them correctly
//! @note 4 line cleaning
//! @note 5 end cycle
//!
//! @see solve(), print_answer(), main()
//}-


void input_of_quadratic_equation_coefficients(float* a_address, float* b_address, float* c_address)
{
    while(!isfinite(*a_address) || !isfinite(*b_address) || !isfinite(*c_address))  /*проверка на верный ввод(проверяем, что вводят числа)*/
    {
        printf("Введите коэффиценты a b c \n");
        scanf("%f%f%f", a_address, b_address, c_address);
        while (getchar() != '\n');

    }

}

