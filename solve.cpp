#include <math.h>
#include <assert.h>
int check_that_number_is_zero(float num);
int solve(float a, float b, float c, float* ans1_address, float* ans2_address);

//! function to check, what number is zero or not
/*!
\param number
\return 1(if users entered number equal 0) or 0(if users entered number equal 1)
*/

//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 initialization of allowable error in comparison
//! @note 2 return 1(if users entered number bigger then minus allowable error and smaller then allowable error) or return 0(if not)
//!
//! @code
//!int check_that_number_is_zero(float num)
//!{
//!    const float allowable_comparison_error = (float) 0.0001;
//!    return((num > - allowable_comparison_error) & (num < allowable_comparison_error));
//!}
//! @endcode
//! @see solve(), print_answer()
//}-

int check_that_number_is_zero(float num)
{
    ///< initialization of allowable error in comparison
    const float allowable_comparison_error = (float) 0.0001;
    return((num > - allowable_comparison_error) & (num < allowable_comparison_error));  /// return 1(if users entered number bigger then minus allowable error and smaller then allowable error) or return 0(if not)
}

//! function to solve a quadratic equation

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
//! @code
//!int solve(float a, float b, float c, float* ans1_address, float* ans2_address)
//!{
//!    if (check_that_number_is_zero(a))   ///determine the type of equation
//!    {
//!        if (check_that_number_is_zero(b)) ///type: 0x^2 + 0x + c = 0
//!        {
//!            return 0;///return 0(numbers of roots)
//!
//!        }
//!
//!        else
//!        {
//!            ///type: 0x^2 + bx + c = 0 (linear equation)
//!            *ans1_address = (float) (- c) / b; /// count answer = (-c)/b
//!            if (check_that_number_is_zero(*ans1_address))   ///checking that the answer is 0
//!                *ans1_address = 0;
//!            return 1; ///return 1(numbers of roots)
//!        }
//!    }
    ///initialization and count the discriminant
//!    float D = b*b - 4*a*c;
//!
//!    if (D<0)        ///if discriminant < 0 then return 0(numbers of roots) due to the lack of real roots
//!    {
//!        return 0;
//!    }
//!
//!    else if(D>0)     /// if discriminant > 0
//!    {
//!
//!        *ans1_address = (float) (-b + sqrt(D)) / (2*a); ///count roots = (-b +-sqrt(discriminant)) / (2*a)
//!        *ans2_address = (float) (-b - sqrt(D)) / (2*a);
//!
//!        if (check_that_number_is_zero(*ans1_address))///checking that the answers is 0
//!                *ans1_address = 0;
//!        if (check_that_number_is_zero(*ans2_address))
//!                *ans2_address = 0;
//!
//!        return 2;///return 2(numbers of roots)
//!    }
//!
//!    else if(check_that_number_is_zero(D)) ///if discriminant = 0
//!    {
//!        *ans1_address = (-b) / (2*a);
//!           ///count root = ( -b ) / (2*a)
//!        if (check_that_number_is_zero(*ans1_address))///checking that the answers is 0
//!                *ans1_address = 0;
//!
//!        return 1;///return 1(numbers of roots)
//!    }
//!
//!    else
//!    {
//!        assert(0);   ///if another situation:  ERROR!
//!        return 0;
//!    }
//!}
//! @endcode
//! @see input_of_quadratic_equation_coefficients(), print_answer()
//}-





int solve(float a, float b, float c, float* ans1_address, float* ans2_address)
{
    if (check_that_number_is_zero(a))
    {
        if (check_that_number_is_zero(b))
        {
            return 0;

        }

        else
        {

            *ans1_address = (float) (- c) / b;
            if (check_that_number_is_zero(*ans1_address))
                *ans1_address = 0;
            return 1;
        }
    }

    float D = b*b - 4*a*c;

    if (D<0)
    {
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

        return 2;
    }

    else if(check_that_number_is_zero(D))
    {
        *ans1_address = (-b) / (2*a);

        if (check_that_number_is_zero(*ans1_address))
                *ans1_address = 0;

        return 1;
    }

    else
    {
        assert(0);
        return 0;
    }
}


