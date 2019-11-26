#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace Romain {
    class Person {
    private:
        // Propri�t�s des instances de la classe
        string firstName;
        string lastName;
        int age;
        bool gender;

    public:
        // Objet contenqnt les r�f�rences vers toutes les instances de la classe
        static vector<Person*> objects;

        // Constantes permettant d'abstraire le sexe des personnes
        static const bool GENDER_MALE = true;
        static const bool GENDER_FEMALE = false;

        // Constructeur
        Person(
            // Param�tres pass�s � la cr�ation de chaque instance
            string _firstName = "",
            string _lastName = "",
            int _age = 0,
            bool _gender = GENDER_FEMALE
        ) :
            // Assignation automatique des param�tres aux propri�t�s de l'instance
            firstName(_firstName),
            lastName(_lastName),
            age(_age),
            gender(_gender)
        {
            // LOrsqu'une nouvelle instance est cr��e, elle s'ajoute � l'objet contenant toutes les r�f�rences
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

        // Autres m�thodes
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

    // Initialisation de l'objet contenant les r�f�rences aux instances
    vector<Person*> Person::objects;
}

void display(Romain::Person* person) {
    cout << "'" << person->getFirstName() << "' stored at " << person << endl;
}

int main()
{
    // Int�gre l'espace de nommage pour �viter d'avoir � pr�fixer les membres de cet espace
    using namespace Romain;

    // Cr�e des instances
    Person robert("Robert", "Duchesne", 35, Person::GENDER_MALE);
    Person juliette("Juliette", "Martin", 37, Person::GENDER_FEMALE);
    Person anonyme;

    // Appelles les m�thodes des instances
    robert.sayName();
    robert.sayHello(&juliette);

    anonyme.sayName();

    // Parcourt l'ensemble des instances de la classe
    vector<Person*>* v = &Person::objects;

    for_each(v->begin(), v->end(), display);

    return 0;
}
