#include <math.h>
#include <stdio.h>
#include <TXLib.h>
#include "solve.h"

int Test_solve(float a, float b, float c, float ans1_ref, float ans2_ref, int nomber_of_roots_ref);
int not_equal_numbers(float num1, float num2);

//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 start tests
//! @note 2 if all tests passed successfully => good. else => bad
//!
//! @code
//!int main(void)
//!{
//!    printf("Начинается проведение тестов \n");
//!    int number_of_passed_test = 0;
//!    number_of_passed_test += Test_solve(1, 1, 1, 0, 0, 0);
//!    number_of_passed_test += Test_solve(1, 2, 1, -1, 0, 1);
//!    number_of_passed_test += Test_solve(1, 0, -1, 1, -1, 2);
//!    number_of_passed_test += Test_solve(1, 1, 1, 0, 0, 0);
//!    number_of_passed_test += Test_solve(4, 4, 1, -0.5, 0, 1);
//!
//!    if (number_of_passed_test == 5)
//!        printf("Все тесты пройдены успешно \n");
//!   else
//!        printf("Не все тесты были пройдены успешно \n");
//!
//!    return 0;
//!}
//! @endcode
//! @see input_of_quadratic_equation_coefficients(), solve(), print_answer()
//}-



int main(void)
{
    printf("Начинается проведение тестов \n");
    int number_of_passed_test = 0;
    number_of_passed_test += Test_solve(1, 1, 1, 0, 0, 0);
    number_of_passed_test += Test_solve(1, 2, 1, -1, 0, 1);
    number_of_passed_test += Test_solve(1, 0, -1, 1, -1, 2);
    number_of_passed_test += Test_solve(1, 1, 1, 0, 0, 0);
    number_of_passed_test += Test_solve(4, 4, 1, -0.5, 0, 1);

    if (number_of_passed_test == 5)
        printf("Все тесты пройдены успешно \n");
   else
        printf("Не все тесты были пройдены успешно \n");

    return 0;
}

/*!
\param a, b,c first answer, second answer (coefficients of the quadratic equation and corrrect roots)
\return 0(if the program did not work correctly) or 1(the program did not work correctly)
*/

//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 initialization: answers and number of roots
//! @note 2 get value of number of roots (function solve)
//! @note 3 finding mistake while testing and return 0(Data_for_test All_data[number_of_tests]if program can find mistake) or return 1(if not)
//!
//! @code
//!int Test_solve(float a, float b, float c, float ans1_ref, float ans2_ref, int nomber_of_roots_ref)
//!{
//!
//!    float ans1 = 0;
//!    float ans2 = 0;
//!
//!    int number_of_roots = solve(a,b,c, &ans1, &ans2);
//!
//!    if (not_equal_numbers(ans1, ans1_ref) ||  not_equal_numbers(ans2, ans2_ref) || number_of_roots != nomber_of_roots_ref) /// if the calculated roots do not correspond to known regular horses
//!    {
//!        printf("Ошибка при решении квадратного уравнения. Получено: ans1=%f, ans2=%f, number_of_roots = %d. \nОжидалось: ans1_ref=%f, ans2_ref=%f, nomber_of_roots_ref=%d \n", ans1, ans2, nomber_of_roots, ans1_ref, ans2_ref, nomber_of_roots_ref);
//!        return 0;
//!
//!   }
//!   else
//!   {
//!       printf("Тест пройден \n");
//!      return 1;
//!    }
//!
//!}
//! @endcode
//! @see solve(), print_answer()
//}-

int Test_solve(float a, float b, float c, float ans1_ref, float ans2_ref, int number_of_roots_ref)
{

    float ans1 = 0, ans2 = 0;

    int number_of_roots = solve(a,b,c, &ans1, &ans2);

    if (not_equal_numbers(ans1, ans1_ref) ||  not_equal_numbers(ans2, ans2_ref) || number_of_roots != number_of_roots_ref) /// if the calculated roots do not correspond to known regular horses
    {
        printf("Ошибка при решении квадратного уравнения. Получено: ans1=%f, ans2=%f, number_of_roots = %d. \nОжидалось: ans1_ref=%f, ans2_ref=%f, nomber_of_roots_ref=%d \n", ans1, ans2, number_of_roots, ans1_ref, ans2_ref, number_of_roots_ref);
        return 0;

    }
    else
    {
        printf("Тест пройден \n");
        return 1;
    }

}

/*!
\param number1, number2 address of coefficients of the quadratic equation
\return 0(if the program did not work correctly) or 1(the program did not work correctly)
*/

//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 initialization of allowable error in comparison
//! @note 2 return 0(if users entered number1 - number2 smaller then allowable error or number2 - number1 smaller then allowable error) or return 1(if not)
//!
//! @code
//!int not_equal_numbers(float num1, float num2)
//!{
//!    const float allowable_comparison_error = (float) 0.0001;
//!
//!    return !(num1 - num2 <= allowable_comparison_error || num2 - num1 <= allowable_comparison_error);
//!
//!}
//! @endcode
//! @see solve(), print_answer()
//}-

int not_equal_numbers(float num1, float num2)
{
    const float allowable_comparison_error = (float) 0.0001;

    return !(num1 - num2 <= allowable_comparison_error || num2 - num1 <= allowable_comparison_error);

}
