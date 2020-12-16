#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class Complex {
  private:
    float real;
    float imaginary;
     
  public:
    Complex (float, float);
    Complex operator= (const Complex& rhs);
    Complex operator+ (const Complex& rhs) const;
    Complex operator- (const Complex& rhs) const;
    Complex operator* (const Complex& rhs) const;
    Complex operator/ (const Complex& rhs) const;
    Complex operator|(const Complex& obj);
    string toString() const;
};

Complex::Complex (float r, float i){
  real = r;
  imaginary = i;
}

Complex Complex::operator= (const Complex& rhs){
    real = rhs.real;
    imaginary = rhs.imaginary;
    return *this;
}

Complex Complex::operator+ (const Complex& rhs) const{
    //addition: (a + bi) + (c + di) = (a + c) + (b + d)i
    Complex result = *this;
    result.real += rhs.real;
    result.imaginary += rhs.imaginary;
    return result;
}

Complex Complex::operator- (const Complex& rhs) const{
    //subtraction: (a + bi) - (c + di) = (a - c) + (b - d)i
    Complex result = *this;
    result.real -= rhs.real;
    result.imaginary -= rhs.imaginary;
    return result;
}

Complex Complex::operator* (const Complex& rhs) const{
    //multiplication: (a + bi) x (c + di) = (ac - bd) + (bc + ad)i
    Complex result = *this;
    result.real = real * rhs.real - imaginary * rhs.imaginary;
    result.imaginary = (real * rhs.imaginary) + (rhs.real * imaginary);
    return result;
}

Complex Complex::operator/ (const Complex& rhs) const
{
    //division: (a + bi) / (c + di) = [(a + bi) x (c - di)] / [(c + di) x (c - di)] =
    //\frac{\left(ac+bd\right)+\left(bc-ad\right)i}{c^2+d^2}
    
   Complex result = *this;
    result.real = (real*rhs.real + imaginary*rhs.imaginary)/((rhs.real*rhs.real)+(rhs.imaginary*rhs.imaginary));
    result.imaginary = (imaginary*rhs.real - real*rhs.imaginary)/((rhs.real*rhs.real)+(rhs.imaginary*rhs.imaginary));
    return result;
}

Complex Complex::operator|(const Complex& obj)
{
    //inverse
    //https://www.symbolab.com/solver/complex-numbers-calculator/%5Cleft(5%2B6i%5Cright)%5E%7B-1%7D
   Complex result = *this;
   // result.real = real/(real*real+imaginary*imaginary);
   // result.imaginary = (imaginary/(real*real+imaginary*imaginary))*-1;
   result.real = 1/real;
   result.imaginary = 1/imaginary;
    return result;
}

string Complex::toString() const {
  stringstream ss;
  if (imaginary > 0){
    ss << real << " + " << imaginary << "i";
  }
  else {
    ss << real << " " << imaginary << "i";
  }
  return ss.str();
}

int main () {
  Complex a(5, 6);
  Complex b(-1, -4);

  Complex sum = a + b;
  Complex dif = a - b;
  Complex pro = a * b;
  Complex division = a / b;
  Complex inverseA = a|a;
  Complex inverseB = b|b;

  cout << "sum: " << sum.toString() << "\n";
  cout << "difference: " << dif.toString() << "\n";
  cout << "product: " << pro.toString() << "\n";
  cout << "division: " << division.toString() << "\n";
  cout << "inverse of a: " << inverseA.toString() << "\n";
  cout << "inverse of b: " << inverseB.toString() << "\n";

  return 0;
}
