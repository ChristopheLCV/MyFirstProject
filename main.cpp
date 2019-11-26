#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace Romain {
    class Person {
    private:
        // Propriétés des instances de la classe
        string firstName;
        string lastName;
        int age;
        bool gender;

    public:
        // Objet contenqnt les références vers toutes les instances de la classe
        static vector<Person*> objects;

        // Constantes permettant d'abstraire le sexe des personnes
        static const bool GENDER_MALE = true;
        static const bool GENDER_FEMALE = false;

        // Constructeur
        Person(
            // Paramètres passés à la création de chaque instance
            string _firstName = "",
            string _lastName = "",
            int _age = 0,
            bool _gender = GENDER_FEMALE
        ) :
            // Assignation automatique des paramètres aux propriétés de l'instance
            firstName(_firstName),
            lastName(_lastName),
            age(_age),
            gender(_gender)
        {
            // LOrsqu'une nouvelle instance est créée, elle s'ajoute à l'objet contenant toutes les références
            objects.push_back(this);
            cout << "Creating new Person at " << this << endl;
        }

        // Destructeur
        ~Person() {
            cout << "Destroying Person at " << this << endl;
        }

        // Accesseurs (getter)
        string getFirstName() {
            return firstName;
        }

        string getLastName() {
            return lastName;
        }

        int getAge() {
            return age;
        }

        bool getGender() {
            return gender;
        }

        // Mutateur (setter)
        void setAge(int _age) {
            age = _age;
        }

        // Autres méthodes
        void sayName() {
            if (firstName == "") {
                cout << "Je n'ai pas de nom" << endl;
            } else {
                cout << "Je m'appelle " << firstName << " " << lastName << endl;
            }
        }

        void sayHello(Person* otherPerson) {
            cout << firstName << " dit: Bonjour " << otherPerson->fullName() << endl;
        }

        string fullName() {
            return (gender ? "monsieur " : "madame ") + firstName + " " + lastName;
        }
    };

    // Initialisation de l'objet contenant les références aux instances
    vector<Person*> Person::objects;
}

void display(Romain::Person* person) {
    cout << "'" << person->getFirstName() << "' stored at " << person << endl;
}

int main()
{
    // Intègre l'espace de nommage pour éviter d'avoir à préfixer les membres de cet espace
    using namespace Romain;

    // Crée des instances
    Person robert("Robert", "Duchesne", 35, Person::GENDER_MALE);
    Person juliette("Juliette", "Martin", 37, Person::GENDER_FEMALE);
    Person anonyme;

    // Appelles les méthodes des instances
    robert.sayName();
    robert.sayHello(&juliette);

    anonyme.sayName();

    // Parcourt l'ensemble des instances de la classe
    vector<Person*>* v = &Person::objects;

    for_each(v->begin(), v->end(), display);

    return 0;
}
