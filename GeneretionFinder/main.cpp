#include <exception>
#include <iostream>
#include <string>
#include "Generation.h"

int main(){
    try{
        std::string name;
        int age;

        std::cout << "╔════════════════════════════════════════╗\n";
        std::cout << "║     Generation Finder Program          ║\n";
        std::cout << "╚════════════════════════════════════════╝\n\n";

        std::cout << "Please enter your name: ";
        std::getline(std::cin, name);
        std::cout << "Please enter your age: ";
        std::cin >> age;
        Generation G(name, age);
        G.specifyGeneration();
        G.printInfo();

        char continueChar;
        std::cout << "\nDo you want to add another person? (e/h): ";
        std::cin >> continueChar;
        std::cin.ignore();


        while (continueChar == 'e' ||continueChar == 'E') {
            std::cout <<"\nPlease enter a name: ";
                 std::getline(std::cin, name);

                 std::cout << "Please enter your age: ";
                 std::cin >> age;

                 Generation G1(name, age);
                 G1.specifyGeneration();
                 G1.printInfo();

                 std::cout << "\nDo you want to add another person? (e/h): ";
                 std::cin >> continueChar;
                 std::cin.ignore();
        }
        std::cout << "The program is terminated... Goodbye";
    }catch(std::exception){
        std::cout << "Please enter a valid value";
    }
}
