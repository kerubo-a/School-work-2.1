#include <iostream>
using namespace std;
struct fraction{
    int numerator;
    int denominator;

    //Decimal compuation function
    double value() const {
        return static_cast <double>(numerator)/denominator;
    }
};
// Function to find largest function using the return by reference
fraction& largestFraction(fraction &f1, fraction &f2, fraction &f3 ){
 fraction *largest = &f3; //assuming f3 is initially the largest

 if (f2.value()> largest->value()){
    largest = &f2;
 }
if (f1.value() > largest->value()){
    largest = &f1;
}
return  *largest; //return the reference t the largest fraction
}
//pass by reference ensures that fractions are passed by reference and thus no copies are made
int main(){
    fraction f1 = {5, 7};
    fraction f2 = {6, 8};
    fraction f3 = {1, 5};
    
    fraction &largest = largestFraction(f1,f2,f3);
    cout<< "Largest fraction is: "
    << largest.numerator <<"/"<< largest.denominator << endl;

    return 0;
}
