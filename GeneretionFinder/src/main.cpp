#include <iostream>
#include <stdexcept>
#include <string>
#include "../include/Generation.h"
#include <cctype>
#include <sys/types.h>

bool isNumber(const std::string& str){
    for(char c : str){
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main(){
    try{

        std::string name;
        int age;
        std::string input;

        std::cout << "╔════════════════════════════════════════╗\n";
        std::cout << "║     Generation Finder Program          ║\n";
        std::cout << "╚════════════════════════════════════════╝\n\n";

        std::cout << "Please enter your name: ";
        std::getline(std::cin, name);
        std::cout << "Please enter your age: ";
        std::cin >> input;
        for(char d : input){
            if(!std::isdigit(d)){
                throw std::invalid_argument("You entered a invalid age (only numbers)!");
            }
        }

        age = std::stoi(input);
        std::cout << "Your age: " << age << std::endl;

        if(isNumber(name)){
            throw std::invalid_argument("Only letter!");
        }
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
    }catch(const std::invalid_argument& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }catch(const std::out_of_range&){
        std::cerr << "Error: The number you entered is too large!" << std::endl;
    }
}
