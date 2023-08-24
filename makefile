all: 1

1: 1.o print_answer.o solve.o input_of_quadratic_equation_coefficients.o
	g++ 1.o print_answer.o solve.o input_of_quadratic_equation_coefficients.o -o result_main

1.o: 1.cpp
	g++ -c 1.cpp

print_answer.o: print_answer.cpp
	g++ -c print_answer.cpp

solve.o: solve.cpp
	g++ -c solve.cpp

input_of_quadratic_equation_coefficients.o: input_of_quadratic_equation_coefficients.cpp
	g++ -c input_of_quadratic_equation_coefficients.cpp

clean:
	rm -rf *.o hello
