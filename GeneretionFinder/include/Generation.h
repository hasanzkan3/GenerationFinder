#include <iostream>
#include <string>
#include <ctime>


class Generation{
    public:
    Generation();
    Generation(std::string name_p, int age_p);
    int presentDate();
    void specifyGeneration();
    void calculateBirthYear();
    void printInfo();
    std::string getName() const;
    int getAge() const;
    int getBirthYear() const;
    std::string getGenerationName() const;
    /*
    friend std::ostream& operator<<(std::ostream& output, const Generation& G);
    friend std::istream& operator>>(std::istream& input, const Generation& G);
    */
    protected:
    std::string generationName;
    int age;
    std::string name;
    int birthYear;
};
