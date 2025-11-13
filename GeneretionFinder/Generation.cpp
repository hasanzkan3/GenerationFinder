#include "Generation.h"
#include <ctime>
//#include <iostream>

Generation::Generation(){}

Generation::Generation(std::string name_p, int age_p){
    name = name_p;
    age = age_p;
    calculateBirthYear();
    specifyGeneration();
}

int Generation::presentDate(){
    time_t present = time(0);
    tm* time = localtime(&present);
    return time->tm_year + 1900;
}

void Generation::specifyGeneration(){
    if(birthYear >= 1901 && birthYear <= 1927){
        generationName = "The Greatest Generation (GI Generation)";
    }else if(birthYear >= 1928 && birthYear <= 1945){
        generationName = "The lost Generation";
    }else if(birthYear >= 1946 && birthYear <= 1964){
        generationName = "Baby Boomers";
    }else if(birthYear >=1965 && birthYear <= 1980){
        generationName = "X";
    }else if(birthYear >= 1981 && birthYear<=1996){
        generationName = " Milennial (Y)";
    }else if(birthYear >= 1997 && birthYear <= 2010){
        generationName = "Z";
    }else if(birthYear >= 2010 && birthYear <= 2024){
        generationName = "Alpha";
    }else if (birthYear >= 2025 && birthYear <= 2039) {
        generationName = "Beta";
    }
}

void Generation::calculateBirthYear(){
   birthYear = presentDate() - age;
}

void Generation::printInfo(){
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Birth Year: " << birthYear << std::endl;
    std::cout << "Generation: " << generationName <<std::endl;
    std::cout << "╚════════════════════════════════════════╝\n";
}

std::string Generation::getName() const { return name; }
int Generation::getAge() const { return age; }
int Generation::getBirthYear() const { return birthYear; }
std::string Generation::getGenerationName() const { return generationName; }
