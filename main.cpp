#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/*Base Class: Student*/
class student{
    protected:
    // variables for all students
    std::string firstName;
    std::string lastName;
    double gpa;
    int graduationYear;
    std::string graduationSemester;
    int enrolledYear;
    std::string enrolledSemester;
    std::string degreeLevel;            // "Undergrad" or "Graduate"

    public:
    // contructor and decontructor 
    student(): firstName("Jane"), lastName("Doe"), gpa(0.0),
            graduationYear(2030), graduationSemester("Spring"),
            enrolledYear(2026), enrolledSemester("Fall"), degreeLevel("Undergrad") {}
    ~student() {}

    // getters and setters
    std::string getFirstName() const { return firstName; }
    void setFirstName(const std::string& first) { firstName = first; }

    std::string getLastName() const { return lastName; }
    void setLastName(const std::string& last) { lastName = last; }

    double getGPA() const { return gpa; }
    void setGPA(double GPA) { gpa = GPA; }

    int getGraduationYear() const { return graduationYear; }
    void setGraduationYear(int gradyear) { graduationYear = gradyear; }

    std::string getGraduationSemester() const { return graduationSemester; }
    void setGraduationSemester(const std::string& gradsem) { graduationSemester = gradsem; }

    int getEnrolledYear() const { return enrolledYear; }
    void setEnrolledYear(int year) { enrolledYear = year; }

    std::string getEnrolledSemester() const { return enrolledSemester; }
    void setEnrolledSemester(const std::string& sem) { enrolledSemester = sem; }

    std::string getDegreeLevel() const { return degreeLevel; }
    void setDegreeLevel(const std::string& level) { degreeLevel = level; }
    
    // saves basic student info to output file
    void baseInfo(std::ofstream& outFile) const {
        outFile << "Name: " << firstName << " " << lastName << "\n"
                << "GPA: " << gpa << "\n"
                << "Enrolled: " << enrolledSemester << " " << enrolledYear << "\n"
                << "Graduation: " << graduationSemester << " " << graduationYear << "\n"
                << "Level: " << degreeLevel << "\n";
    }
};

/*Derived Class: Art Student*/
class Art_Student: public student {
    private:
    // art emphasis
    // art studio, art history or art education
    std::string artEmphasis;

    public:
    // contructor and decontructor 
    Art_Student() : student(), artEmphasis("General") {}
    ~Art_Student() {}

    // getter and setter
    std::string getArtEmphasis() const { return artEmphasis; }
    void setArtEmphasis(const std::string& emphasis) { artEmphasis = emphasis; }

    // saves art student into to output file
    void artStudentInfo(std::ofstream& outFile) const {
        baseInfo(outFile);  // calls to base class
        outFile << "Major: Art\n"
                << "Emphasis: " << artEmphasis << "\n"
                << "---------------------------\n";
    }
};

/*Derived Class: Physics Student*/
class Physics_Student : public student {
    private:
    // physics concentrations: 
    // biophysics, earth and planetary sciences, or astrophysics
    std::string concentration;       

    public:
    // contructor and decontructor 
    Physics_Student() : student(), concentration("General") {}
    ~Physics_Student() {}

    // getter and setter
    std::string getConcentration() const { return concentration; }
    void setConcentration(const std::string& conc) { concentration = conc; }

    // saves physics student info to output file
    void physStudentInfo(std::ofstream& outFile) const {
        baseInfo(outFile);  // calls to base class
        outFile << "Major: Physics\n"
                << "Concentration: " << concentration << "\n"
                << "---------------------------\n";
    }
};

int main() {
    // allocating space for 5 art students
    std::vector<Art_Student*> arts;
    for (int i = 0; i < 5; ++i) {
        arts.push_back(new Art_Student());
    }

    // allocating space for 5 physics student
    std::vector<Physics_Student*> physics;
    for (int i = 0; i < 5; ++i) {
        physics.push_back(new Physics_Student());
    }
    
    // art students
    arts[0]->setFirstName("Alice"); arts[0]->setLastName("Cullen");    
    arts[0]->setGPA(3.8);

    arts[1]->setFirstName("Bella"); arts[1]->setLastName("Swan");
    arts[1]->setEnrolledSemester("Fall"); arts[1]->setEnrolledYear(2023);
    arts[1]->setGraduationYear(2027);    
    arts[1]->setGPA(3.4); arts[1]->setArtEmphasis("Art Education");

    arts[2]->setFirstName("Jasper"); arts[2]->setLastName("Hale");    
    arts[2]->setGPA(2.7);

    arts[3]->setFirstName("Renee"); arts[3]->setLastName("Dwyer");   
    arts[3]->setEnrolledSemester("Fall"); arts[3]->setEnrolledYear(2020);
    arts[3]->setGraduationSemester("Fall"); arts[3]->setGraduationYear(2026);
    arts[3]->setDegreeLevel("Graduate");   
    arts[3]->setGPA(1.8); arts[3]->setArtEmphasis("Art Studio");

    arts[4]->setFirstName("Emily"); arts[4]->setLastName("Uley");
    arts[4]->setEnrolledSemester("Spring"); arts[4]->setEnrolledYear(2022);
    arts[4]->setGraduationSemester("Fall"); arts[4]->setGraduationYear(2026);    
    arts[4]->setGPA(3.6); arts[4]->setArtEmphasis("Art History");

    // physics students
    physics[0]->setFirstName("Edward"); physics[0]->setLastName("Cullen");  
    physics[0]->setEnrolledSemester("Fall"); physics[0]->setEnrolledYear(2023);
    physics[0]->setGraduationYear(2027);
    physics[0]->setGPA(3.95);

    physics[1]->setFirstName("Rosalie"); physics[1]->setLastName("Hale");
    physics[1]->setEnrolledSemester("Fall"); physics[1]->setEnrolledYear(2023);
    physics[1]->setGraduationYear(2027);  
    physics[1]->setGPA(4.0);  physics[1]->setConcentration("Astrophysics");

    physics[2]->setFirstName("Jacob");  physics[2]->setLastName("Black");
    physics[2]->setEnrolledSemester("Fall"); physics[2]->setEnrolledYear(2023);
    physics[2]->setGraduationYear(2027);     
    physics[2]->setGPA(3.1);  physics[2]->setConcentration("Earth and Planetary Sciences");

    physics[3]->setFirstName("Seth");   physics[3]->setLastName("Clearwater");  
    physics[3]->setGPA(2.9);  physics[3]->setConcentration("Biophysics");

    physics[4]->setFirstName("Bree");  physics[4]->setLastName("Tanner");
    physics[4]->setGPA(1.9);


    // creating output file for student info 
    std::ofstream outFile;
    outFile.open("student_info.dat", std::ios::out); 

    while (outFile.is_open()) {
        outFile << "=== ART STUDENTS ===\n\n";
        for (size_t i = 0; i < arts.size(); i++) {
            arts[i]->artStudentInfo(outFile);
        }

        outFile << "\n=== PHYSICS STUDENTS ===\n\n";
        for (size_t i = 0; i < physics.size(); i++) {
            physics[i]->physStudentInfo(outFile);
        }
        outFile.close();
        std::cout << "\nData successfully written to student_info.dat\n\n";
    }

    return 0;
}