#include <iostream>

using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    int age;
    bool gender;

public:
    // Constructeur
    Person(string _firstName = "") : firstName(_firstName) {
        cout << "Creating new Person" << endl;
    }

    // Destructeur
    ~Person() {
        cout << "Destroying Person" << endl;
    }

    // Accesseur (getter)
    string getFirstName() {
        return firstName;
    }

    // Mutateur (setter)
    void setFirstName(string _firstName) {
        firstName = _firstName;
    }

    void sayName() {
        if (firstName == "") {
            cout << "Je n'ai pas de nom" << endl;
        } else {
            cout << "Je m'appelle " << firstName << endl;
        }
    }

    void sayHello(Person* otherPerson) {
        cout << firstName << " dit: Bonjour " << otherPerson->firstName << endl;
    }
};


int main()
{
    Person robert("Robert");
    Person juliette("Juliette");
    Person anonyme;

    robert.sayName();
    robert.sayHello(&juliette);

    anonyme.sayName();

    return 0;
}
