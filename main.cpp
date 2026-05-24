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

    // ќператори пор≥вн€нн€ Ч потр≥бн≥ дл€ mergeSorted
    bool operator<(const Student& other) const { return grade < other.grade; }
    bool operator>(const Student& other) const { return grade > other.grade; }
    bool operator==(const Student& other) const { return grade == other.grade; }

    // ќператор виведенн€ Ч потр≥бен дл€ printContainer
    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << s.name << "(" << s.grade << ")";
        return os;
    }
};