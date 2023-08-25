#include <math.h>
#include <assert.h>
#include "solve.h"

//! function to check, what number is zero or not
/*!
\param number
\return 1(if users entered number equal 0) or 0(if users entered number equal 1)
*/

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
int not_equal_numbers(float num1, float num2)
{
    const float allowable_comparison_error = (float) 0.0001;
    if (num1>=num2)
        return !(num1 - num2 < allowable_comparison_error);
    else
        return !(num2 - num1 < allowable_comparison_error);

}

/*!
\param a, b, c  coefficients of the quadratic equation
\param ans1_address, ans2_address address of roots
\return roots
*/

//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 determine the type of equation
//! @note 2 type: 0x^2 + 0x + c = 0 => return 0(numbers of roots)
//! @note 3 type: 0x^2 + bx + c = 0 (linear equation) =>  count answer = (-c)/b =>  checking that the answer is 0 =>return 1(numbers of roots)
//! @note 4 type: ax^2 + bx + c = 0 => initialization and count the discriminant
//! @note 4.a if discriminant < 0 => return 0(numbers of roots) due to the lack of real roots
//! @note 4.b if discriminant > 0 => count roots = (-b +-sqrt(discriminant)) / (2*a) =>checking that the answers is 0 =>return 2(numbers of roots)
//! @note 4.c if discriminant = 0 => count root = ( -b ) / (2*a) => checking that the answers is 0 => return 1(numbers of roots)
//! @note 5 if another situation:  ERROR!
//!
//! @see input_of_quadratic_equation_coefficients(), print_answer()
//}-

//! function to linear a quadratic equation

int solve_linear_equation(float a, float b, float* ans1_address)
    {
        if (!not_equal_numbers(b, 0))
        {
            return 0;

        }

        else
        {

            *ans1_address = (float) (- b) / a;
            if (!not_equal_numbers(*ans1_address, 0))
                *ans1_address = 0;
            return 1;
        }


    }

//! function to solve a quadratic equation
int solve_quadratic_equation(float a, float b, float c,  float* ans1_address, float* ans2_address)
{
    float D = b*b - 4*a*c;

    if (D<0)
    {
        return 0;
    }

    else if(D>0)
    {

        *ans1_address = (float) (-b + sqrt(D)) / (2*a);
        *ans2_address = (float) (-b - sqrt(D)) / (2*a);

        if (!not_equal_numbers(*ans1_address, 0))
                *ans1_address = 0;
        if (!not_equal_numbers(*ans2_address, 0))
                *ans2_address = 0;

        return 2;
    }

    else if(!not_equal_numbers(D, 0))
    {
        *ans1_address = (-b) / (2*a);

        if (!not_equal_numbers(*ans1_address, 0))
                *ans1_address = 0;

        return 1;
    }

    else
    {
        assert(0);
        return 0;
    }


}



//! function to determine the type of equation
int solve(float a, float b, float c, float* ans1_address, float* ans2_address)
{
    if (!not_equal_numbers(a, 0))
    {
        return solve_linear_equation(b, c, ans1_address);


    }

    else
    {
        return solve_quadratic_equation(a, b, c,  ans1_address,  ans2_address);



    }

}




