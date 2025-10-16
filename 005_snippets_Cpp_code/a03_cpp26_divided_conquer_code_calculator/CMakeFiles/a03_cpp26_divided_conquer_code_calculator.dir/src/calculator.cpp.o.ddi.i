# 0 "/home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/005_snippets_Cpp_code/a03_cpp26_divided_conquer_code_calculator/src/calculator.cpp"
# 1 "/home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/005_snippets_Cpp_code/a03_cpp26_divided_conquer_code_calculator//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/005_snippets_Cpp_code/a03_cpp26_divided_conquer_code_calculator/src/calculator.cpp"
# 1 "/home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/005_snippets_Cpp_code/a03_cpp26_divided_conquer_code_calculator/src/./headers/Calculator.h" 1
       
class Calculator {
public:
    double Calculate(double x, char oper, double y);
};
# 2 "/home/y/my_project/Rust_Lang/9999/C_Programming_Kernigan_and_Ritchie/005_snippets_Cpp_code/a03_cpp26_divided_conquer_code_calculator/src/calculator.cpp" 2

double Calculator::Calculate(double x, char oper, double y)
{
    switch (oper) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        return 0.0;
    }
}
