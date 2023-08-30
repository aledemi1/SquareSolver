#include <math.h>
#include <stdio.h>
#include <TXLib.h>

#include "solve.h"

#define RED_OUT \033[01;31m
#define GREEN_OUT \033[01;32m
#define WHITE_OUT \033[0;37m

//#define d data_for_tests.txt

struct data_for_test
{
        double a;
        double b;
        double c;

        double x1;
        double x2;

        int number_of_roots;

};

int Test_solve(const struct data_for_test* data);
//{---------------------------------------------------------------------------------------------
//!
//! @note Program do following:
//! @note 1) start tests
//! @note 2) if all tests passed successfully ... actions
//!
//! @see input_of_quadratic_equation_coefficients(), solve(), print_answer(), main()
//}-


int main(void)
{
    printf("Начинается проведение тестов \n");
    int number_of_passed_test = 0;
    const int max_n_tests = 100;

    FILE *file = nullptr;

    int n_tests = 0;

    struct data_for_test all_data[max_n_tests] = {};

    if((file = fopen("data_for_tests.txt", "r")) == NULL)
    {
        printf("В файле data_for_tests.txt отсутвуют данные для тестов");
        return 0;

    }

    if((file = fopen("data_for_tests.txt", "r")) == NULL)
    {
        printf("В файле data_for_tests.txt отсутвуют данные для тестов");
        return 0;

    }

    while (fscanf(file, "%lf%lf%lf%lf%lf%d",
    &(all_data[n_tests].a), &(all_data[n_tests].b), &(all_data[n_tests].c),  //coefficients of the quadratic equation
    &(all_data[n_tests].x1), &(all_data[n_tests].x2), //roots
    &(all_data[n_tests].number_of_roots))       //number of roots
    != EOF)
    {
        assert(max_n_tests > n_tests && "Количество тестов в файле превысило максимальное");
        ///printf("%lf %lf %lf %lf %lf %d \n", all_data[a].a, all_data[a].b, all_data[a].c, all_data[a].x1, all_data[a].x2, all_data[a].number_of_roots);
        n_tests++;
    }
    //printf("%d\n", n_tests);
    assert( isfinite(all_data[n_tests-1].number_of_roots)  && "Ошбка при прочтении файла");

    fclose (file);

    for (int i = 0; i < n_tests; i++)
    {
        number_of_passed_test += Test_solve(&all_data[i]);
    }

    if (number_of_passed_test == n_tests)
        printf("\033[01;32m Все тесты пройдены успешно \033[0;37m\n");
    else
        printf("\033[01;31m Не все тесты были пройдены успешно\033[0;37m\n");

    return 0;
}

/*!
\param a, b,c, first_answer, second_answer (coefficients of the quadratic equation and corrrect roots)
\return 0(if the program did not work correctly) or 1(the program did not work correctly)
*/

//{---------------------------------------------------------------------------------------------
//!
//! @brief Test_solve is checking function solve
//! @param data - data for testing
//! @return return 1 if test is successful
//!
//! @note Program do following
//! @note 1) initialization: answers and number of roots
//! @note 2) get value of number of roots (function solve)
//! @note 3) finding mistake while testing and return 0(if program can find mistake) or return 1(if not)
//!
//! @see solve(), print_answer()
//}-

int Test_solve(const struct data_for_test* data)
{

    double ans1 = 0;
    double ans2 = 0;

    int number_of_roots = solve_quadratic_equation(data->a, data->b, data->c, &ans1, &ans2);

    /// if the calculated roots do not correspond to known regular horses
    if (!equal_numbers(ans1, data->x1) ||
        !equal_numbers(ans2, data->x2) ||
        number_of_roots != data->number_of_roots)
    {
        printf("Ошибка при решении квадратного уравнения. Получено: ans1=%lf, ans2=%lf, number_of_roots = %d.\n"
               "Ожидалось: ans1_ref=%lf, ans2_ref=%lf, nomber_of_roots_ref=%d\n",
               ans1, ans2, number_of_roots,
               data->x1, data->x1, data->number_of_roots);

        return 0;

    }
    else
    {
        printf("Тест пройден \n");
        return 1;
    }

}



