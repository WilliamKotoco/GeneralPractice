#include <iostream>
#include <string>

class Person {

private:
    std::string name;
    int age;

public:
    Person(std::string name_, int age_) : name(name_), age(age_) {}

    /// you cannot change attributes within a const function 
    void showInfo() const {

      /// age = 14  will cause error
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {

    Person person("John", 25);

    person.showInfo();

    return 0;
}

