#include <iostream> 
#include <vector>
#include <cstdlib>
#include <ctime>

int main(){
    //seed random number generator to get various numbers
    srand(static_cast<unsigned>(time(0)));

    std::vector<int> originalArray;
    std::vector<int> evenValues;
    std::vector<int> oddValues;

    //create array of 20 random integers between 1-100
    for (int i = 0; i< 20; i++){
        int randomNum = (rand()% 100) + 1; //to generate numbers 1 - 100
        originalArray.push_back(randomNum);
    }

    //sort into even and odd numbers
    for (int num : originalArray) {
        if (num % 2 ==0){
            evenValues.push_back(num);
        } else {
            oddValues.push_back(num);
        }
    }

    //results display
    std::cout << "originalArray: ";
    for (int n : originalArray) std ::cout << n <<" ";

    std::cout << "\n\nEven values: ";
    for (int n : evenValues) std ::cout << n <<" ";

    std::cout << "\nOdd values: ";
    for (int n : oddValues) std ::cout << n <<" ";
       
    return 0;
}