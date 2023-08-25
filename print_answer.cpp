#include <stdio.h>
#include <assert.h>
#include  "print_answer.h"

//! print correct answers or error
/*!
\param nomber_of_roots, first_answer, second_answer
\return print answer
*/

//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 function get number of roots
//! @note 2 if numbers of roots = 0 then print it
//! @note 3 if numbers of roots = 1 then print correct answer
//! @note 4 if numbers of roots = 2 then print correct answers
//! @note 5 if another situation:  ERROR!
//!
//! @see input_of_quadratic_equation_coefficients(), solve(), main()
//}-






int print_answer(int number_of_roots, float ans1, float ans2 )
{
    switch(number_of_roots)
    {

    case 0:
    {
        printf("Отсутствуют вещественные корни");
        break;
    }

    case 1:
    {
        printf("Единственный корень %.4f", ans1);
        break;
    }

    case 2:
    {
        printf("Первый корень %.4f \n", ans1);
        printf("Второй корень %.4f", ans2);
        break;
    }
    default:
    {
        assert(0);
        break;
    }
    }

    return 0;
}
