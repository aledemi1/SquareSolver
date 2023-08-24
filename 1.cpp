#include <stdio.h>
#include <TXLib.h>
#include <math.h>
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
//! @code
//! int main(void)
//! {
//!     print_welcome_message();
//!
//!     float a = NAN;
//!     float b = NAN;
//!     float c = NAN;
//!
//!
//!
//!     input_of_quadratic_equation_coefficients( &a, &b,  &c);  //ввод
//!
//!     float ans1 = NAN;
//!     float ans2 = NAN;
//!
//!     int nomber_of_roots = NAN;
//!
//!     nomber_of_roots = solve(a,b,c, &ans1, &ans2);
//!
//!     print_answer(nomber_of_roots, ans1, ans2);
//!
//!     return 0;
//! }
//! @endcode
//!
//! @note Operation logic:
//! @note 1 initialization: coefficients of the quadratic equation
//! @note 2 function (input_of_quadratic_equation_coefficients) get entering variables from the keyboard
//! @note 3 initialization: roots of the quadratic equation and number of roots
//! @note 4 function(solve) for counting the number of real roots
//! @note 5 function(print_answer) print correct roots
//}-



int main(void)
{
    print_welcome_message();


    float a = NAN;
    float b = NAN;
    float c = NAN;


    input_of_quadratic_equation_coefficients( &a, &b,  &c);  //ввод


    float ans1 = NAN;
    float ans2 = NAN;

    int nomber_of_roots = NAN;

    nomber_of_roots = solve(a,b,c, &ans1, &ans2);

    print_answer(nomber_of_roots, ans1, ans2);

    return 0;
}

//! print welcome message and kind of quadratic equation
//{---------------------------------------------------------------------------------------------
//!
//!
//! @code
//!void print_welcome_message()
//!{
//!    printf("Вас приветсвует программа для поиска решений квадратных уравнений \n");
//!
//!    printf("Квадратное уравнение имеет вид: \n");
//!
//!    printf("ax^2 + bx + c = 0 \n");
//!}
//! @endcode
//! @see input_of_quadratic_equation_coefficients(), solve(), print_answer()
//}-
void print_welcome_message()
{
    printf("Вас приветсвует программа для поиска решений квадратных уравнений \n");

    printf("Квадратное уравнение имеет вид: \n");

    printf("ax^2 + bx + c = 0 \n");
}



