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
        if (*itA < *itB) { *itR = *itA; ++itA; }
        else { *itR = *itB; ++itB; }
        ++itR;
    }
    while (itA != a.end()) { *itR = *itA; ++itA; ++itR; }
    while (itB != b.end()) { *itR = *itB; ++itB; ++itR; }
    return result;
}

template <typename T>
void splitEvenOdd(
    const std::vector<T>& input,
    std::vector<T>& evens,
    std::vector<T>& odds)
{
    for (auto it = input.begin(); it != input.end(); ++it) {
        if (*it % 2 == 0) evens.push_back(*it);
        else               odds.push_back(*it);
    }
}

// Задача 3: перевірити чи є std::deque паліндромом
template <typename T>
bool isPalindrome(const std::deque<T>& d) {
    if (d.empty()) return true;

    auto front = d.begin();
    auto back = d.end();
    --back;

    while (front < back) {
        if (*front != *back) return false;
        ++front;
        --back;
    }

    return true;
}