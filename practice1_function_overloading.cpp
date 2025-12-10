#include <iostream>
using namespace std;

//functon overloading 
double calculate(double num1, double num2) {
    return num1 + num2;

}

double calculate(double num1, double num2, double num3) {
return num1 + num2 + num3;
}

double calculate(double num1, double num2, char operation) {
  switch (operation)
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/':
      if (num2 != 0) return num1 / num2;
      return 0;
    default: return num1 + num2;
    }
    return num1 + num2;
}

// main fucntion 
int main() {
  double result1 = calculate(8.4, 8.9);
  double result2 = calculate(8.4, 8.9, 9.7);
  double result3 = calculate(8.4, 8.9, '*');

    cout << "Result 1 (sum of 2): " << result1 << endl;
    cout << "Result 2 (sum of 3): " << result2 << endl;
    cout << "Result 3 : " << result3 << endl;

 
  return 0;
}