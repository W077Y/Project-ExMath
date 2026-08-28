
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <exmath.hpp>

namespace
{
  using exmath::polynomial::polynomial_t;

  constexpr polynomial_t<double, 2> quadratic{ 4.0, 1.0, 0.1 };
  constexpr auto                    linear = quadratic.derivative();

  static_assert(quadratic.at(0) == 4.0);
  static_assert(quadratic.at(1) == 1.0);
  static_assert(quadratic.at(2) == 0.1);
  static_assert(std::same_as<decltype(quadratic.derivative()), polynomial_t<double, 1>>);
  static_assert(linear[0] == 8.0);
  static_assert(linear[1] == 1.0);
  static_assert(quadratic.derivative(2.0) == 17.0);

  constexpr polynomial_t<double, 1> affine{ 4.0, 1.0 };
  constexpr auto                    constant = affine.derivative();

  static_assert(std::same_as<decltype(affine.derivative()), polynomial_t<double, 0>>);
  static_assert(constant[0] == 4.0);
  static_assert(affine.derivative(-10.0) == 4.0);
  static_assert(affine.derivative(0.0) == 4.0);
  static_assert(affine.derivative(10.0) == 4.0);

  constexpr polynomial_t<double, 0> constant_polynomial{ 4.0 };
  constexpr auto                    zero       = constant_polynomial.derivative();
  constexpr auto                    zero_again = zero.derivative();

  static_assert(std::same_as<decltype(constant_polynomial.derivative()), polynomial_t<double, 0>>);
  static_assert(zero[0] == 0.0);
  static_assert(zero_again[0] == 0.0);
  static_assert(constant_polynomial.derivative(-10.0) == 0.0);
  static_assert(constant_polynomial.derivative(0.0) == 0.0);
  static_assert(constant_polynomial.derivative(10.0) == 0.0);
}    // namespace

TEST_CASE("polynomial evaluation and derivatives")
{
  exmath::polynomial::polynomial_t<float, 2> poly = { 4.0, 1.0, 0.1 };

  for (float v : { -10.0F, -1.0F, 0.0F, 1.0F, 10.0F })
  {
    auto const erg = poly(v);
    auto const ref = (4.0f * v + 1.0f) * v + 0.1f;

    REQUIRE(erg == Catch::Approx(ref));
  }

  auto const derivative = poly.derivative();
  REQUIRE(derivative[0] == 8.0F);
  REQUIRE(derivative[1] == 1.0F);
  REQUIRE(poly.derivative(2.0F) == 17.0F);

  auto mutable_poly  = poly;
  mutable_poly.at(0) = 2.0F;
  REQUIRE(mutable_poly.at(0) == 2.0F);

  REQUIRE_THROWS_AS(static_cast<void>(poly.at(poly.number_of_parameter)), std::out_of_range);
}
