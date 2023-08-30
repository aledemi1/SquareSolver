#include <math.h>
#include <assert.h>

#include "solve.h"

//! function to check, what number is zero or not
/*!
\param number
\return 1(if users entered number equal 0) or 0(if users entered number equal 1)
*/
#define allowable_comparison_error 0.000000000000001

#define SS_ZERO_ROOTS 0
#define SS_ONE_ROOT 1
#define SS_TWO_ROOTS 2
#define SS_INFINITY_ROOTS -1
//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 initialization of allowable error in comparison
//! @note 2 return 0(if users entered number1 - number2 smaller then allowable error or number2 - number1 smaller then allowable error) or return 1(if not)
//!
//! @see solve(), print_answer()
//}-


/*!
\param number1, number2 address of coefficients of the quadratic equation
\return 0(if the program did not work correctly) or 1(the program did not work correctly)
*/
int equal_numbers(double num1, double num2)
{
    return(fabs(num1 - num2) < allowable_comparison_error);

}

int equal_zero(double num1)
{
    return(fabs(num1) < allowable_comparison_error);

}



//! @brief function to solve linear a quadratic equation

int solve_linear_equation(double a, double b, double* ans1_address)
    {
        if (equal_zero(a))
        {
            return SS_INFINITY_ROOTS;

        }

        else
        {
            double ans1 = (- b) / a;
            if (equal_zero(ans1))
                ans1 = 0;

            *ans1_address = ans1;
            return SS_ONE_ROOT;
        }


    }

//! @brief function to determine the type of equation and solve a quadratic equation

//{---------------------------------------------------------------------------------------------
//!
//! @note Program do following
//! @note 1) determine the type of equation
//! @note 2) type: 0x^2 + 0x + c = 0 => return 0(numbers of roots)
//! @note 3) type: 0x^2 + bx + c = 0 (linear equation) =>  count answer = (-c)/b =>  checking that the answer is 0 =>return 1(numbers of roots)
//! @note 4) type: ax^2 + bx + c = 0 => initialization and count the discriminant
//! @note 4.a) if discriminant < 0 => return 0(numbers of roots) due to the lack of real roots
//! @note 4.b) if discriminant > 0 => count roots = (-b +-sqrt(discriminant)) / (2*a) =>checking that the answers is 0 =>return 2(numbers of roots)
//! @note 4.c) if discriminant = 0 => count root = ( -b ) / (2*a) => checking that the answers is 0 => return 1(numbers of roots)
//! @note 5) if another situation:  ERROR!
//!
//! @param ans1_address, ans2_address address of roots
//! @param b, c  coefficients of the quadratic equation
//!
//! @return number of roots
//! @see input_of_quadratic_equation_coefficients(), print_answer()
//}-
int solve_quadratic_equation(double a, double b, double c, double* ans1_address, double* ans2_address)
{
    if (equal_zero(a))
    {
        return solve_linear_equation(b, c, ans1_address);
    }

    else
    {
        double D = b*b - (double) 4*a*c;

        if(equal_zero(D))
        {
            double ans1 = (-b) / (2*a);

            if (equal_zero(ans1))
                ans1 = 0;

            *ans1_address = ans1;

            return SS_ONE_ROOT;
        }

        if (D<0)
        {
            return SS_ZERO_ROOTS;
        }

        else if(D>0)
        {
            double ans1 = (double) (-b + (double) sqrt(D)) / (2*a);
            double ans2 = (double) (-b - (double) sqrt(D)) / (2*a);

            if (equal_zero(ans1))
                ans1 = 0;

            if (equal_zero(ans2))
                ans2 = 0;

            *ans1_address = ans1;
            *ans2_address = ans2;

            if(equal_numbers(ans1, ans2))
                return SS_ONE_ROOT;
            return SS_TWO_ROOTS;
        }


        else
        {
            assert(!"Неправильное значение дискриминанта");
            return SS_ZERO_ROOTS;
        }
    }

}




