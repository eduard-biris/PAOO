#include "StudentService.h"
#include <vector>
#include <memory>

int main() {
    const int numStudents = 5;
    std::vector<std::unique_ptr<std::thread>> studentThreads;

    // Names of the students
    std::vector<std::string> studentNames = {"Ion", "Marinel", "Ana", "David", "Antonio"};

    // Create an instance of the StudentRegistrar
    StudentService studentService;

    // Create threads for each student
    for (int i = 0; i < numStudents; ++i) {
        studentThreads.push_back(std::make_unique<std::thread>(&StudentService::writeNameOnAttendanceSheet, &studentService, i + 1, studentNames[i]));
    }

    // Wait for all threads to finish
    for (auto& thread : studentThreads) {
        thread->join();
    }

    // Display the final attendance sheet
    studentService.displayAttendanceSheet();

    return 0;
}
