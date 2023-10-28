#include <iostream>
#include <vector>
#include<string>

class Animal {
protected:
    std::string name;
    std::string gender;
    int age;
    int weight;
    int legs;
    
public:
    Animal(std::string n, std::string g, int a, int s, int l) : name(n), gender(g), age(a), weight(s), legs(l) {}
    virtual void printInfo() = 0;
};

class Koala : public Animal {
private:
    int furLength;
    int treeClimbingAbility;
    int sleepHours;
public:
    Koala(std::string n, std::string g, int a, int s, int l, int f, int t, int sh) : Animal(n, g, a, s, l), furLength(f), treeClimbingAbility(t), sleepHours(sh) {}
    void printInfo() {
        std::cout << "Koala: " << name << "\nGender: "<< gender << "\nAge: " << age << "\nWeight: " << weight << "\nLegs: " << legs << "\nFur Length: " << furLength << "\nTree Climbing Ability: " << treeClimbingAbility << "\nSleep Hours: " << sleepHours << std::endl << std::endl;
    }
};

class Panda : public Animal {
private:
    int bambooEatingAbility;
    int flipPerHour;
    int playfulness;
public:
    Panda(std::string n, std::string g, int a, int s, int l, int b, int fph, int p) : Animal(n, g, a, s, l), bambooEatingAbility(b), flipPerHour(fph), playfulness(p) {}
    void printInfo() {
        std::cout << "Panda: " << name << "\nGender: " << gender <<"\nAge: " << age << "\nWeight: " << weight << "\nLegs: " << legs << "\nBamboo Eating Ability: " << bambooEatingAbility << "\nFLip per hour: " << flipPerHour << "\nPlayfulness: " << playfulness << std::endl <<  std::endl;
    }
};

class Anteater : public Animal {
private:
    int tongueLength;
    int insectEatingAbility;
    int diggingAbility;
public:
    Anteater(std::string n, std::string g, int a, int s, int l, int t, int ie, int d) : Animal(n, g, a, s, l), tongueLength(t), insectEatingAbility(ie), diggingAbility(d) {}
    void printInfo() {
        std::cout << "Anteater: " << name << "\nGender: " << gender << "\nAge:" << age << "\nWeight: " << weight << "\nLegs: " << legs << "\nTongue Length: " << tongueLength << "\nInsect Eating Ability: " << insectEatingAbility << "\nDigging Ability: " << diggingAbility << std::endl << std::endl;
    }
};

int main() {
    std::vector<Animal*> animals;

    animals.push_back(new Koala("Koko", "female", 10, 5, 4, 3, 9, 14));
    animals.push_back(new Panda("Popo", "male", 14, 110, 4, 10, 1, 0));
    animals.push_back(new Anteater("Akak", "female", 9, 30, 4, 58, 8, 7));

    int choice;
    while (true) {
        std::cout << "Welcome to the zoo! What would you like to do?" << std::endl;
        std::cout << "1. Add an animal" << std::endl;
        std::cout << "2. Remove an animal" << std::endl;
        std::cout << "3. Feed an animal" << std::endl;
        std::cout << "4. Exit" << std::endl << std::endl;
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "What kind of animal would you like to add?" << std::endl;
            std::cout << "1. Koala" << std::endl;
            std::cout << "2. Panda" << std::endl;
            std::cout << "3. Anteater" << std::endl << std::endl;
            int animalChoice;
            std::cin >> animalChoice;
            int age = 0;
            int weight = 0;
            int legs= 0;
            std::string name;
            std::string gender;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter the gender: ";
            std::cin >> gender;
            std::cout << "Enter age: ";
            std::cin >> age;
            std::cout << "Enter weight: ";
            std::cin >> weight;
            std::cout << "Enter number of legs: ";
            std::cin >> legs;
            if (animalChoice == 1) {
                int furLength, treeClimbingAbility, sleepHours;
                std::cout << "Enter fur length: ";
                std::cin >> furLength;
                std::cout << "Enter tree climbing ability: ";
                std::cin >> treeClimbingAbility;
                std::cout << "Enter sleep hours: ";
                std::cin >> sleepHours;
                animals.push_back(new Koala(name, gender, age, weight, legs, furLength, treeClimbingAbility, sleepHours));
            }
            else if (animalChoice == 2) {
                int bambooEatingAbility, blackAndWhiteFur, playfulness;
                std::cout << "Enter bamboo eating ability: ";
                std::cin >> bambooEatingAbility;
                std::cout << "Enter black and white fur: ";
                std::cin >> blackAndWhiteFur;
                std::cout << "Enter playfulness: ";
                std::cin >> playfulness;
                animals.push_back(new Panda(name, gender, age, weight, legs, bambooEatingAbility, blackAndWhiteFur, playfulness));
            }
            else if (animalChoice == 3) {
                int tongueLength, insectEatingAbility, diggingAbility;
                std::cout << "Enter tongue length: ";
                std::cin >> tongueLength;
                std::cout << "Enter insect eating ability: ";
                std::cin >> insectEatingAbility;
                std::cout << "Enter digging ability: ";
                std::cin >> diggingAbility;
                animals.push_back(new Anteater(name, gender, age, weight, legs, tongueLength, insectEatingAbility, diggingAbility));
            }
        }
        else if (choice == 2) {
            if (animals.size() == 0) {
                std::cout << "There are no animals to remove." << std::endl;
            }
            else {
                std::cout << "Which animal would you like to remove?" << std::endl;
                for (int i = 0; i < animals.size(); i++) {
                    std::cout << i + 1 << ". ";
                    animals[i]->printInfo();
                }
                int removeChoice;
                std::cin >> removeChoice;
                animals.erase(animals.begin() + removeChoice - 1);
            }
        }
        else if (choice == 3) {
            if (animals.size() == 0) {
                std::cout << "There are no animals to feed." << std::endl << std::endl;
            }
            else {
                std::cout << "Which animal would you like to feed?" << std::endl << std::endl;
                for (int i = 0; i < animals.size(); i++) {
                    std::cout << i + 1 << ". ";
                    animals[i]->printInfo();
                }
                int feedChoice;
                std::cin >> feedChoice;
                std::cout << "Thank you!\nYou fed the animal." << std::endl << std::endl;
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
        }
    }
    return 0;
}