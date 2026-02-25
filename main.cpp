#include <iostream>
#include <sstream>
#include <cassert>
#include <stdexcept>
#include <vector>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
using namespace std;

class  Student {
    private:
    static int nextId;
    static int objectCount;
    int id;
    string name;
    string surname;
    int age;
    double finansavimas;

    public:
    Student(string name,string surname, int age, double finansavimas)
    : name(name), surname(surname),finansavimas(finansavimas) {
        setAge(age);
        id = nextId++;
        objectCount++;
    }
    Student(string name,string surname)
        : name(name), surname(surname), age(26), finansavimas(0.0) {
        id = nextId++;
        objectCount++;
    }

    ~Student() {
        objectCount--;
    }
    int getId() const {return id;}
    string getName() const {return name;}
    string getSurname() const {return surname;}
    int getAge() const {return age;}
    double getFinansavimas() const {return finansavimas;}

    void setName(string newName) {
    name = newName;
}
    void setSurname(string newSurname) {
        surname = newSurname;
    }
    void setAge(int newAge) {
        if (newAge <= 0)
            throw invalid_argument("invalid age");
        age = newAge;
    }
    void setFinansavimas(double newFinansavimas) {
        if (newFinansavimas < 0)
            throw invalid_argument("invalid finansavimas");
        finansavimas = newFinansavimas;
    }
    void print() const {
        cout << toString() << endl;
    }

    string toString() const {
        stringstream ss;
        ss << "Student[" << id << "] "
           << name << " " << surname
           << ", age=" << age
           << ", finansavimas=" << finansavimas;
        return ss.str();
    }
    static int getObjectCount() {return objectCount;}



};
int Student :: nextId = 1;
int Student :: objectCount = 0;

int main() {
    // // This statement prints "Hello World"
    // cout << "Hello World";
    //
    Student s1("Ernestas", "K", 26, 100.0);

    assert(s1.getName() == "Ernestas");
    s1.print();
    assert(s1.getSurname() == "K");
    assert(s1.getAge() == 26);
    assert(s1.getFinansavimas() == 100.0);
    string text = s1.toString();
    assert(text.find("Ernestas") != string::npos);

    s1.setName("Anna");
    s1.setSurname("V");
    s1.setAge(25);
    s1.setFinansavimas(200.0);

    assert(s1.getName() == "Anna");
    assert(s1.getSurname() == "V");
    assert(s1.getAge() == 25);
    assert(s1.getFinansavimas() == 200.0);
    try {
        s1.setAge(-5);
        assert(false);
    } catch (invalid_argument&) {}
    Student s2("Martin", "G");
    s2.print();

    Student s3("Ilja", "R");
    s3.print();
    assert(s2.getId() < s3.getId());



    assert(Student::getObjectCount() == 3);

    Student* dyn = new Student("Dynamic", "Student", 30, 300.0);
    assert(Student::getObjectCount() == 4);
    cout << "Count after new "
     << Student::getObjectCount() << endl;

    delete dyn;
    assert(Student::getObjectCount() == 3);
    cout << "Count after delete "
         << Student::getObjectCount() << endl;

    vector<Student*> list;

    for (int i = 0; i < 5; i++) {
        list.push_back(new Student("Name", "Surname"));
    }

    assert(Student::getObjectCount() == 8);

    for (Student* s : list) {
        delete s;
    }

    assert(Student::getObjectCount() == 3);


    cout << "test success" << endl;

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}