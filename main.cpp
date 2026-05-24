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

template <typename Container>
void printContainer(const std::string& label, const Container& c) {
    std::cout << label << ": [ ";
    for (auto it = c.begin(); it != c.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != c.end()) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

int main() {
    try {
        // ===== Задача 1: mergeSorted =====
        std::cout << "=== Task 1: mergeSorted ===" << std::endl;

        std::array<int, 4> a1 = { 1, 3, 5, 7 };
        std::array<int, 4> b1 = { 2, 4, 6, 8 };
        auto merged1 = mergeSorted(a1, b1);
        printContainer("a1", a1);
        printContainer("b1", b1);
        printContainer("merged", merged1);

        std::cout << std::endl;
        std::array<Student, 3> a2 = {
            Student("Anna", 75),
            Student("Bob",  85),
            Student("Carl", 95)
        };
        std::array<Student, 3> b2 = {
            Student("Dana", 70),
            Student("Eve",  80),
            Student("Frank",90)
        };
        auto merged2 = mergeSorted(a2, b2);
        printContainer("a2", a2);
        printContainer("b2", b2);
        printContainer("merged students", merged2);

        // ===== Задача 2: splitEvenOdd =====
        std::cout << "\n=== Task 2: splitEvenOdd ===" << std::endl;

        std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::vector<int> evens, odds;
        splitEvenOdd(nums, evens, odds);
        printContainer("input", nums);
        printContainer("evens", evens);
        printContainer("odds", odds);

        std::cout << std::endl;
        std::vector<long> lnums = { 100L, 201L, 302L, 403L, 504L };
        std::vector<long> levens, lodds;
        splitEvenOdd(lnums, levens, lodds);
        printContainer("input long", lnums);
        printContainer("evens long", levens);
        printContainer("odds  long", lodds);

        // ===== Задача 3: isPalindrome =====
        std::cout << "\n=== Task 3: isPalindrome ===" << std::endl;

        std::deque<int> d1 = { 1, 2, 3, 2, 1 };
        std::deque<int> d2 = { 1, 2, 3, 4, 5 };
        std::deque<int> d3 = { 7 };
        std::deque<int> d4 = {};

        printContainer("d1", d1);
        std::cout << "isPalindrome: " << (isPalindrome(d1) ? "yes" : "no") << std::endl;
        printContainer("d2", d2);
        std::cout << "isPalindrome: " << (isPalindrome(d2) ? "yes" : "no") << std::endl;
        printContainer("d3", d3);
        std::cout << "isPalindrome: " << (isPalindrome(d3) ? "yes" : "no") << std::endl;
        std::cout << "d4 (empty) isPalindrome: "
            << (isPalindrome(d4) ? "yes" : "no") << std::endl;

        std::cout << std::endl;
        std::deque<std::string> ds1 = { "abc", "def", "abc" };
        std::deque<std::string> ds2 = { "abc", "def", "ghi" };
        printContainer("ds1", ds1);
        std::cout << "isPalindrome: " << (isPalindrome(ds1) ? "yes" : "no") << std::endl;
        printContainer("ds2", ds2);
        std::cout << "isPalindrome: " << (isPalindrome(ds2) ? "yes" : "no") << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Fatal: " << e.what() << std::endl;
        return 1;
    }

    std::cin.get();
    return 0;
}