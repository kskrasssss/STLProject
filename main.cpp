#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <stdexcept>
#include <string>

class Student {
private:
    std::string name;
    int grade;
public:
    Student(std::string n, int g) : name(n), grade(g) {}
    int getGrade() const { return grade; }
    std::string getName() const { return name; }
};