#include <math.h>
#include <stdio.h>
#include <TXLib.h>
#include "solve.h"

struct data_for_test
    {
        float a, b, c;
        float x1, x2;
        int number_of_roots;

    };

int Test_solve(const struct data_for_test* data);
//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 start tests
//! @note 2 if all tests passed successfully => good. else => bad
//!
//! @see input_of_quadratic_equation_coefficients(), solve(), print_answer(), main()
//}-


int main(void)
{
    printf("Начинается проведение тестов \n");
    int number_of_passed_test = 0;
    const int max_number_of_tests = 100;

    FILE *file;

    int number_of_tests = 0;

    struct data_for_test all_data[max_number_of_tests] = {};

    if((file = fopen("data_for_tests.txt", "r")) == NULL)
    {
        printf("В файле data_for_tests.txt отсутвуют данные для тестов");
        return 0;

    }
    ///нужно добавить считывание количества строк в файле



    while (fscanf(file, "%f%f%f%f%f%d",
     &(all_data[number_of_tests].a), &(all_data[number_of_tests].b), &(all_data[number_of_tests].c),  //coefficients of the quadratic equation
     &(all_data[a].x1), &(all_data[a].x2), //roots
    &(all_data[a].number_of_roots))       //number of roots
    != EOF)
    {

        ///printf("%f %f %f %f %f %d \n", all_data[a].a, all_data[a].b, all_data[a].c, all_data[a].x1, all_data[a].x2, all_data[a].number_of_roots);
        number_of_tests++;
    }

    fclose (file);

/*
    struct data_for_test all_data[number_of_tests] =   {{.a =1, .b=1, .c=1, .x1 = 0,    .x2=0,  .number_of_roots = 0},
                                                        {.a =1, .b=2, .c=1, .x1 = -1,   .x2=0,  .number_of_roots = 1},
                                                        {.a =1, .b=0, .c=-1, .x1 = 1,    .x2=-1, .number_of_roots = 2},
                                                        {.a =1, .b=1, .c=1, .x1 = 0,    .x2=0,  .number_of_roots = 0},
                                                        {.a =4, .b=4, .c=1, .x1 = -0.5, .x2=0,  .number_of_roots = 1}};

  */
    for (int i = 0; i < number_of_tests ; i++)
    {
        number_of_passed_test += Test_solve(&all_data[i]);
    }

    if (number_of_passed_test == number_of_tests)
        printf("\033[01;32mВсе тесты пройдены успешно \033[0;37m\n");
    else
        printf("\033[01;31mНе все тесты были пройдены успешно \033[0;37m\n");

    return 0;
}

/*!
\param a, b,c, first_answer, second_answer (coefficients of the quadratic equation and corrrect roots)
\return 0(if the program did not work correctly) or 1(the program did not work correctly)
*/

//{---------------------------------------------------------------------------------------------
//!
//! @note Operation logic:
//! @note 1 initialization: answers and number of roots
//! @note 2 get value of number of roots (function solve)
//! @note 3 finding mistake while testing and return 0(if program can find mistake) or return 1(if not)
//!
//! @see solve(), print_answer()
//}-

int Test_solve(const struct data_for_test* data)
{

    float ans1 = 0;
    float ans2 = 0;

    int number_of_roots = solve(data->a, data->b, data->c, &ans1, &ans2);

     if (not_equal_numbers(ans1, data->x1) ||  not_equal_numbers(ans2, data->x2) || number_of_roots != data->number_of_roots) /// if the calculated roots do not correspond to known regular horses
    {
        printf("Ошибка при решении квадратного уравнения. Получено: ans1=%f, ans2=%f, number_of_roots = %d. \nОжидалось: ans1_ref=%f, ans2_ref=%f, nomber_of_roots_ref=%d \n", ans1, ans2, number_of_roots, data->x1, data->x1, data->number_of_roots);

        return 0;

    }
    else
    {
        printf("Тест пройден \n");
        return 1;
    }

}



