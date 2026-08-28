
#include "exmath-polynomial.hpp"

#include <exmath.hpp>
#include <iostream>

int main()
{
  std::cout << "test polynomial:" << std::endl << std::endl;

  exmath::polynomial::polynomial_t<float, 2> poly = { 4.0, 1.0, 0.1 };

  float max_err = 0.0;
  for (float v = -10.0; v <= 10.0; v += 1E-5)
  {
    auto const erg = poly(v);
    auto const ref = (4.0f * v + 1.0f) * v + 0.1f;
    auto const err = std::abs((erg - ref));

    std::cout << "f(" << v << ") = " << erg << " : " << ref << " : " << err << std::endl;

    if (max_err < err)
    {
      max_err = err;
    }
    if (max_err >= 1E-9)
      return -1;
  }

  std::cout << "max_err = " << max_err << std::endl;

  return 0;
}
