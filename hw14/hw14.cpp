#include <iostream>
#include <algorithm>

constexpr int marksCount{ 4 };

struct Student
{
    const char* name;
    int marks[marksCount];
};

double avgMark(const Student &student)
{
    double sum = 0;

    for (int i = 0; i < marksCount; i++) 
    {
        sum += student.marks[i];
    }

    return sum / marksCount;
}

bool sortStudents(const Student& left, const Student& right)
{
    return avgMark(left) > avgMark(right);
}

void sortStudentByAvgMarks(Student students[],const int size)
{
    return std::sort(students, students + size, sortStudents);
}

Student* bestStudent(Student students[], const int size) {
    Student* bestStudent = &students[0];

    for (int i = 0; i < size; i++)
    {
        if (avgMark(*bestStudent) < avgMark(students[i]))
        {
            bestStudent = &students[i];
        }
    }

    return bestStudent;
}

int topStudents(Student students[], const int size) {
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (avgMark(students[i]) > 75)
        {
            count++;
        }
    }

    return count;
}

void printMarks(const int marks[])
{
    std::cout << " marks: ";
    for (int i = 0; i < marksCount; i++)
    {
        std::cout << marks[i] << ' ';
    }
}

void printStudents(const Student student)
{   
    std::cout << student.name;
    printMarks(student.marks);
    std::cout << std::endl;
}

void printStudents(const Student *student)
{
    std::cout << student->name;
    printMarks(student->marks);
    std::cout << std::endl;
}

void printStudents(const Student students[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << students[i].name;
        printMarks(students[i].marks);
        std::cout << std::endl;
    }
}

int main()
{
    Student student{ "Mike", {42, 65, 99, 23}};
    Student students[] = {
       { "Mike", { 42, 65, 99, 23} },
       { "Piter", {32, 55, 1, 23} },
       { "Jhon", {82, 65, 99, 73} },
       { "Rick", {82, 61, 94, 83} }
    };
    
    std::cout << "The " << student.name << " AVG mark is " << avgMark(student) << std::endl << std::endl;

    std::cout << "Unsorted list of students:" << std::endl;
    printStudents(students, sizeof(students) / sizeof(Student));
    sortStudentByAvgMarks(students, sizeof(students) / sizeof(Student));
    std::cout << std::endl << "Sorted list of students by AVG:" << std::endl;
    printStudents(students, sizeof(students) / sizeof(Student));
    
    Student* topStudent = bestStudent(students, sizeof(students) / sizeof(Student));    
    std::cout << std::endl << "Best student: ";
    printStudents(topStudent);
    topStudent->marks[0] = 100; // Let's make them perfect
    topStudent->marks[1] = 100;
    topStudent->marks[2] = 100;
    topStudent->marks[3] = 100;
    printStudents(students, sizeof(students) / sizeof(Student)); // New reting

    std::cout << std::endl << "The number of students whose grades are better than 75%: " << topStudents(students, sizeof(students) / sizeof(Student)) << std::endl;
}