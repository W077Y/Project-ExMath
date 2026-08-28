
#include "exmath-polynomial.hpp"

#include <exmath.hpp>
#include <iostream>

int main()
{
  std::cout << "Hello, World!" << std::endl << std::endl;

  exmath::polynomial::polynomial_t<float, 2> poly = { 1.0, 1.0, 0.1 };

  for (auto v : { 0.0, 0.1, 1.0, 2.0 })
  {
    std::cout << "f(" << v << ") = " << poly(v) << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Bye bye, World!" << std::endl;
  return 0;
}
