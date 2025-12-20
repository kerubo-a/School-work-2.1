class Fraction:
 def __init__(self, numerator, denominator) :
    self.numerator = numerator
    self.denominator = denominator

 def value(self):
    return self.numerator / self. denominator

 def __str__(self):
    return f"{self.numerator}/{self.denominator}"

def largest_fraction(f1,f2, f3):
   largest = f1
   if f2.value() > largest. value() :
      largest = f2
   if f3.value() > largest. value():
      largest = f3

   return largest
   
#usage
f1 = Fraction(3, 15)
f2 = Fraction(7, 35)
f3 = Fraction(9,45)

largest = largest_fraction(f1, f2, f3)
print("Largest fraction is:", largest)
