#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Person
{
protected:
    string person_name;
    int person_age;
    int person_id;
    char person_gender;
public:
    // Default constructor
    Person()
    {
        person_name = "";
        person_age = 0;
        person_id = 0;
        person_gender = '\0';
    }

    // Parameterized constructor
    Person(string name, int age, int id, char gen)
    {
        person_name = name;
        person_age = age;
        person_id = id;
        person_gender = gen;
    }

    // Setters and getters
    void set_person_name(string name)
    {
        person_name = name;
    }
    void set_person_age(int age)
    {
        person_age = age;
    }
    void set_person_id(int id)
    {
        person_id = id;
    }
    void set_person_gender(char gen)
    {
        person_gender = gen;
    }
    string get_person_name()
    {
        return person_name;
    }
    int get_person_age()
    {
        return person_age;
    }
    int get_person_id()
    {
        return person_id;
    }
    char get_person_gender()
    {
        return person_gender;
    }
};
class Department
{
protected:
    string department_name;
    int department_capacity;
    float department_require_gpa;
public:
    // Default constructor
    Department()
    {
        department_name = "";
        department_capacity = 0;
        department_require_gpa = 0.0;
    }

    // Parameterized constructor
    Department(string name, int capacity, float reg_gpa)
    {
        department_name = name;
        department_capacity = capacity;
        department_require_gpa = reg_gpa;
    }

    // Setters and getters
    void set_department_name(string name)
    {
        department_name = name;
    }
    void set_department_capacity(int capacity)
    {
        department_capacity = capacity;
    }
    void set_department_require_gpa(float reg_gpa)
    {
        department_require_gpa = reg_gpa;
    }
    string get_department_name()
    {
        return department_name;
    }
    int get_department_capacity()
    {
        return department_capacity;
    }
    float get_department_require_gpa()
    {
        return department_require_gpa;
    }
};

class Student: public Person
{
private:
    float student_gpa;
    int student_level;
public:
    // Default constructor
    Student()
    {
        student_gpa = 0.0;
        student_level = 0;
    }

    // Parameterized constructor
    Student(string name, int age, int id, char gen, float gpa, int lvl)

    : Person(name, age, id, gen)
    {
        student_gpa = gpa;
        student_level = lvl;
    }

    // Setters and getters
    void set_student_gpa (float gpa)
    {
        student_gpa = gpa;
    }
    void set_student_level (int lvl)
    {
        student_level = lvl;
    }
    float get_student_gpa()
    {
        return student_gpa;
    }
    int get_student_level()
    {
        return student_level;
    }
};

class Professor : public Person
{
private:
    string degree;
    int salary;
    Department *dept;

public:
    // Default constructor
     Professor() : Person(), degree(""), salary(0), dept(nullptr)
    {
    }



    // Parameterized constructor
    Professor(string s, int a, int id, char ge, string dg, int sl, Department* dep)
        : Person(s, a, id, ge), degree(dg), salary(sl), dept(dep)
    {
    }
 // Setters and getters
    void set_degree (string dg)
    {
        degree = dg;
    }
    void set_salary (int sl)
    {
        salary = sl;
    }
    string get_degree()
    {
        return degree;
    }
    int get_salary()
    {
        return salary;
    }

};



class Course
{
private:
    string course_name;
    string course_code;
    int course_hours;
    vector <Course*> prerequisites;
    Professor* professor;
    vector <Student*> students;

public:

    Course(string name, string code, int hours, vector<Course*> pre, Professor* prof, vector <Student*> student)
    {
        this->course_name = name;
        this->course_code = code ;
        this->course_hours = hours;
        this->prerequisites = pre;
        this->professor = prof;
        this->students = student;

    }


    ~Course()
    {

    }


    string get_course_name()
    {
        return course_name;
    }

    string get_course_code()
    {
        return course_code;
    }

    int get_course_hours()
    {
        return course_hours;
    }

    vector<Course*> get_prerequisites()
    {
        return prerequisites;
    }

    Professor* get_professor()
    {
        return professor;
    }

    vector<Student*> get_students()
    {
        return students;
    }

    void set_course_name(string name)
    {
        course_name = name;
    }

    void set_course_code(string code)
    {
        course_code = code;
    }

    void set_course_hours(int hours)
    {
        course_hours = hours;
    }

    void set_prerequisites(vector<Course*> prereqs)
    {
        prerequisites = prereqs;
    }

    void set_professor(Professor* prof)
    {
        professor = prof;
    }

    void set_student(Student* student)
    {
        students.push_back(student);
    }
};


class University
{
private:
    static University *instancePtr;
    vector<Department> department_vector;
    vector <Student> students;
    vector <Professor> profs;
    vector<Course> course_vector;

    University() {
        addData();
    }
public:
    University(const University& obj) = delete;
    static University *getInstance()
    {
        if(instancePtr == NULL)
        {
            instancePtr = new University();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }

    //add student
    void add_student(string name, int age, int id, char gen, float gpa, int lvl)
    {
        Student s ( name,age, id, gen, gpa, lvl);
        students.push_back(s);
    }
    //add professor
    void add_professor(string s, int a, int id, char ge, string dg, int sl,Department* dep )
    {
        Professor p (s, a, id, ge, dg, sl,dep);
        profs.push_back(p);
    }

    //update professor
    bool update_prof_salary(int professor_id, int salary)
    {
        bool check =true;
        for(int i=0; i<profs.size(); i++)
        {
            if(professor_id == profs[i].get_person_id())
            {
                profs[i].set_salary(salary);
                break;
            }
            else
            {
                check= false;
            }

        }
        return check;
    }
    //add student
    bool update_student_gpa(int id, int gpa)
    {
        bool check =true;
        for(int i=0; i<students.size(); i++)
        {
            if(id==students[i].get_person_id())
            {
                students[i].set_student_gpa(gpa);
                break;
            }
            else
            {
                check= false;
            }
        }
        return check;
    }
    //delete student
    bool delete_student(int id)
    {
        bool check =true;
        for(int i=0; i<students.size(); i++)
        {
            if(id==students[i].get_person_id())
            {
                students.erase (students.begin()+i);
                break;
            }
            else
            {
                check= false;
            }
        }
        return check;

    }
    // delete prof
    bool delete_prof(int id)
    {
        bool check =true;
        for(int i=0; i<profs.size(); i++)
        {
            if(id==profs[i].get_person_id())
            {
                profs.erase (profs.begin()+i);
                break;
            }
            else
            {
                check= false;
            }
        }
        return check;

    }

    // add department information
    void add_department(string name, int capacity, float reg_gpa)
    {
        Department department(name,capacity,reg_gpa);
        department_vector.push_back(department);
    }
//Update department information
    void update_department(string name, float new_reg_gpa)
    {
        for (auto& department : department_vector)
        {
            if (department.get_department_name() == name)
            {
                department.set_department_require_gpa(new_reg_gpa);
                break;
            }
        }
    }

    // Delete department by name
    void delete_department(string name)
    {
        for (int i = 0; i < department_vector.size(); i++)
        {
            if (department_vector[i].get_department_name() == name)
            {
                department_vector.erase(department_vector.begin()+i);
                break;
            }
        }
    }

    // add course
    void add_course(string name, string code, int hours, vector<Course*> pre, Professor* prof, vector<Student*> student)
    {
        Course course( name,  code,  hours, pre,  prof,  student);


        course_vector.push_back(course);

    }
    //update course
    bool update_course(string code, int hours)
    {
        bool check = false ;

        for(int i = 0 ; i < course_vector.size() ; i++)
        {
            if(code == course_vector[i].get_course_code())
            {
                course_vector[i].set_course_hours(hours);
                check = true;
                break;
            }
        }

        return check;
    }
    // delete course
    bool delete_course(string code)
    {
        bool check = false ;


        for(int i = 0 ; i < course_vector.size() ; i++)
        {
            if(code == course_vector[i].get_course_code())
            {
                course_vector.erase(course_vector.begin()+i);
                check = true;
                break;
            }

        }
        return check;
    }

    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        department_vector.push_back(d1);
        Department d5("computer engineering", 22, 3.2);
        department_vector.push_back(d5
                                    );
        Department d2("Cyber Security", 33, 3.5);
        department_vector.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        department_vector.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        department_vector.push_back(d4);

        Student s1("aya", 12,1, 'F', 4, 3.2);
        students.push_back(s1);
        Student s2("Mirna Hussein", 22,2, 'F', 3.68, 4);
        students.push_back(s2);
        Student s3("Hamada Hossam", 28,3, 'M', 2.37, 3);
        students.push_back(s3);
        Student s4("Taghreed Mohsen", 20,4, 'F', 3, 3);
        students.push_back(s4);
        Student s5("Yasmin Belal", 18,5, 'F', 3.71, 1);
        students.push_back(s5);
        Student s6("Amr Diab", 50,6, 'M', 2.01, 4);
        students.push_back(s6);
        Student s7("Tamer Hosny", 30,7, 'M', 2.02, 3);
        students.push_back(s7);
        Student s8("Ahmed Alaa", 21,8, 'M', 2.49, 2);
        students.push_back(s8);

        Professor p1("Mohamed Ali", 56,1, 'M', "Masters", 12000, &d1);
        profs.push_back(p1);
        Professor p2("Ehsan Ahmed", 43, 2, 'M', "Masters", 8500, &d2);
        profs.push_back(p2);
        Professor p3("Ahmed Mohsen", 68,3, 'M', "Masters", 19380, &d3);
        profs.push_back(p3);
        Professor p4("Abdelhady", 61,4, 'M', "Masters", 22728, &d4);
        profs.push_back(p4);
        Professor p5("Taghreed Mohsen", 49,5, 'F', "Masters", 11068, &d2);
        profs.push_back(p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        course_vector.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1,&p3, st2);
        course_vector.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        course_vector.push_back(c3);
    }

    void printAll()
    {
        for(int i=0; i<department_vector.size(); i++)
        {
            cout<<"Department: "<<department_vector[i].get_department_name()<<endl;
        }
        for(int i=0; i<profs.size(); i++)
        {
            cout<<"Professor Name: "<<profs[i].get_person_name()<<endl;
        }
        for(int i=0; i<students.size(); i++)
        {
            cout<<"Student Name: "<<students[i].get_person_name()<<endl;
        }
        for (int i = 0; i < course_vector.size(); i++)
        {
            cout << "Course Name: " << course_vector[i].get_course_name() << endl;
        }
    }
};



University* University::instancePtr = NULL;

int main()
{
    University* uni = University::getInstance();
    uni->printAll();
    uni->delete_course("Net521");
    uni->printAll();

    return 0;
}
