#include <iostream>
#include <algorithm>
#include <iomanip>

int main()
{
    std::cout << "Welcome to GPA Calculator!" << std::endl;
    std::string status = "y";
    std::string courseList[550], gradeList[550];
    int creditList[550];
    double GPAList[550];
    int numCourses = 0;
    double cumulativeCredits = 0, cumulativeGradePoints = 0, GPA;
    while (status == "y" || status == "Y")
    {
        numCourses++;

        int credit;

        std::cout << "Add your Course " << numCourses << ": ";
        std::cin.ignore(); // 忽略之前的换行符
        std::getline(std::cin, courseList[numCourses]);

        std::cout << "Add your course credit hours: ";
        std::cin >> credit;
        if (std::cin.fail())
        {
            std::cout << "Invalid input for credit hours. Please enter a valid number." << std::endl;
            std::cin.clear();                                                   // 清除错误状态
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空缓冲区
            numCourses--;
            continue; // 重新开始当前课程的输入
        }
        creditList[numCourses] = credit;
        cumulativeCredits += credit;

        std::cout << "Add your grade of this course: ";
        std::cin >> gradeList[numCourses];

        if (gradeList[numCourses] == "A+")
        {
            GPAList[numCourses] = 4.3;
        }
        else if (gradeList[numCourses] == "A")
        {
            GPAList[numCourses] = 4.0;
        }
        else if (gradeList[numCourses] == "A-")
        {
            GPAList[numCourses] = 3.7;
        }
        else if (gradeList[numCourses] == "B+")
        {
            GPAList[numCourses] = 3.3;
        }
        else if (gradeList[numCourses] == "B")
        {
            GPAList[numCourses] = 3.0;
        }
        else if (gradeList[numCourses] == "B-")
        {
            GPAList[numCourses] = 2.7;
        }
        else if (gradeList[numCourses] == "C+")
        {
            GPAList[numCourses] = 2.3;
        }
        else if (gradeList[numCourses] == "C")
        {
            GPAList[numCourses] = 2.0;
        }
        else if (gradeList[numCourses] == "C-")
        {
            GPAList[numCourses] = 1.7;
        }
        else if (gradeList[numCourses] == "D+")
        {
            GPAList[numCourses] = 1.3;
        }
        else if (gradeList[numCourses] == "D")
        {
            GPAList[numCourses] = 1.0;
        }
        else if (gradeList[numCourses] == "E")
        {
            GPAList[numCourses] = 0.0;
        }
        else
        {
            std::cout << "Invalid grade. Please enter a valid grade." << std::endl;
            numCourses--;
        }
        std::cout << "Press any key to calculate the GPA. Press Y to continue. Press P to print." << std::endl;
        std::cin >> status;
        if (!(status == "y" || status == "Y" || status == "p" || status == "P"))
        {
            for (int i = 1; i <= numCourses; i++)
            {
                cumulativeGradePoints += creditList[i] * GPAList[i];
            }
            GPA = cumulativeGradePoints / cumulativeCredits;
            std::cout << std::fixed << std::setprecision(2) << "Your GPA is: " << GPA << std::endl;
            break;
        }
    }
    if (status == "p" || status == "P")
    {
        std::cout << std::endl;
        for (int i = 1; i <= numCourses; i++)
        {
            std::cout << "Course " << i << ": " << courseList[i] << std::endl;
            std::cout << "Credit hours: " << creditList[i] << std::endl;
            std::cout << "Grade: " << gradeList[i] << std::endl;
            std::cout << std::endl;
        }
        for (int i = 1; i <= numCourses; i++)
        {
            cumulativeGradePoints += creditList[i] * GPAList[i];
        }
        GPA = cumulativeGradePoints / cumulativeCredits;
        std::cout << std::fixed << std::setprecision(2) << "Your GPA is: " << GPA << std::endl;
    }

    return 0;
}