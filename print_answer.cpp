#include <stdio.h>
#include <assert.h>
#include  "print_answer.h"

//! print correct answers or error
/*!
\param nomber_of_roots, first_answer, second_answer
\return print answer
*/

#define SS_ZERO_ROOTS 0
#define SS_ONE_ROOT 1
#define SS_TWO_ROOTS 2
#define SS_INFINITY_ROOTS -1

//{---------------------------------------------------------------------------------------------
//!
//! @note Program do following
//! @note 1 function get number of roots
//! @note 2 if numbers of roots = 0 then print it
//! @note 3 if numbers of roots = 1 then print correct answer
//! @note 4 if numbers of roots = 2 then print correct answers
//! @note 5 if another situation:  ERROR!
//!
//! @see input_of_quadratic_equation_coefficients(), solve(), main()
//}-


int print_answer(int number_of_roots, double ans1, double ans2 )
{
    switch(number_of_roots)
    {

    case SS_ZERO_ROOTS:

        printf("Отсутствуют вещественные корни");
        break;

    case SS_ONE_ROOT:

        printf("Единственный корень %g", ans1);
        break;

    case SS_TWO_ROOTS:

        printf("Первый корень %g \n", ans1);
        printf("Второй корень %g", ans2);
        break;

    case SS_INFINITY_ROOTS:

        printf("Имеется бесконечное количество корней \n");
        break;


    default:

        assert(0 && "Получено неверное количество корней \n");
        break;

    }

    return 0;
}
