class MyComplex:
    def __init__(self, re = 0, im =0):
        self.re = re
        self.im = im
    
    def __eq__(self, n):
        self.re = n.re
        self.im = n.im
        return self
        
    def __str__(self):
        return "{} {} {}i".format(self.re, '+' if self.im >= 0 else '-', abs(self.im))
    
    def __add__(self, other):
        return MyComplex(self.re + other.re, self.im + other.im)
    
    def __sub__(self,other):
        return MyComplex(self.re - other.re, self.im - other.im)
        
    def __neg__(self):
        return MyComplex(-self.re, -self.im)
        
    def conjugate(self):
        return MyComplex(self.re, -self.im)
    
    def __mul__(self, other):
        re = self.re * other.re - self.im * other.im
        im = self.im * other.re + self.re * other.im
        return MyComplex(re,im)
    
    def __truediv__(self,other):
        conj = other.conjugate()
        den = other * conj
        den = den.re
        
        num = self * conj
        return MyComplex(round(num.re/den,3), round(num.im/den,3))

    def __invert__(self):
        re = 1 / self.re
        im = 1 / self.im
        return MyComplex(round(re,3), round(im,3))

a = MyComplex(5,6)
b = MyComplex(-1,-4)
c = ~MyComplex(5,6)
print("Addition: ",a+b)
print("Subtration: ",a-b)
print("Product: ",a*b)
print("Division: ",a/b)
print("Inverse: ",c)

