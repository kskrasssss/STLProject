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
    bool operator<(const Student& other) const { return grade < other.grade; }
    bool operator>(const Student& other) const { return grade > other.grade; }
    bool operator==(const Student& other) const { return grade == other.grade; }
    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << s.name << "(" << s.grade << ")";
        return os;
    }
};

// Задача 1: об'єднати два відсортованих std::array в один
template <typename T, std::size_t N1, std::size_t N2>
std::array<T, N1 + N2> mergeSorted(
    const std::array<T, N1>& a,
    const std::array<T, N2>& b)
{
    std::array<T, N1 + N2> result{};

    auto itA = a.begin();
    auto itB = b.begin();
    auto itR = result.begin();

    while (itA != a.end() && itB != b.end()) {
        if (*itA < *itB) {
            *itR = *itA;
            ++itA;
        }
        else {
            *itR = *itB;
            ++itB;
        }
        ++itR;
    }

    while (itA != a.end()) {
        *itR = *itA;
        ++itA;
        ++itR;
    }

    while (itB != b.end()) {
        *itR = *itB;
        ++itB;
        ++itR;
    }

    return result;
}