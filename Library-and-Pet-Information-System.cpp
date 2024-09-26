#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * ADTs
*******************************************************************************/

struct Dog {
    string furColor;
    int age;
    string breed;
    string name;
    bool sex;
};

struct Person {
    string name;
    int age;
    Dog pet;
};

struct Book {
    string title;
    Person author;
    string genre;
    double price;
};

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void printInfo(const Dog&);
void printInfo(const Person&);
void printInfo(const Book&);
Dog createDog();
Person createPerson();
Book createBook();

/*******************************************************************************
 * Description:
 * Starting point of the program. Creates a `Book` object and prints out its
 * information via functions.
 * 
 * Input:
 * N/A
 * 
 * Output:
 * An integer that signals the exit code to the operating system (OS)
*******************************************************************************/

int main() {
    // create an array
    const int SIZE = 3;
    Book myLibrary[SIZE];

    // let the user create the library
    for (Book& elem : myLibrary) {
        elem = createBook();
        cin.ignore();
    }

    // print a report of the books in the library
    for (int i = 0; i < SIZE; i++) {
        printInfo(myLibrary[i]);
    }

    // terminate
    return 0;
}

/*******************************************************************************
 * Description:
 * Prints out the information packed inside `d` to the screen.
 * 
 * Input:
 * d - a constant reference to a `Dog` object
 * 
 * Output:
 * N/A
*******************************************************************************/

void printInfo(const Dog& d) {
    cout << "Fur Color: " << d.furColor << endl;
    cout << "Age: " << d.age << endl;
    cout << "Breed: " << d.breed << endl;
    cout << "Name: " << d.name << endl;
    cout << "Sex: " << (d.sex ? "female" : "male") << endl;
}

/*******************************************************************************
 * Description:
 * Prints out the information packed inside `p` to the screen.
 * 
 * Input:
 * p - a constant reference to a `Person` object
 * 
 * Output:
 * N/A
*******************************************************************************/

void printInfo(const Person& p) {
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
    cout << "\nPet's information:\n";
    printInfo(p.pet);
}

/*******************************************************************************
 * Description:
 * Prints out the information packed inside `b` to the screen.
 * 
 * Input:
 * b - a constant reference to a `Book` object
 * 
 * Output:
 * N/A
*******************************************************************************/

void printInfo(const Book& b) {
    cout << "\n********** BOOK REPORT **********\n";
    cout << "Title: " << b.title << endl;
    cout << "Genre: " << b.genre << endl;
    cout << "Price: $" << b.price << endl;
    cout << "\nAuthor's information:\n";
    printInfo(b.author);
    cout << "********** BOOK REPORT **********\n";
}

/*******************************************************************************
 * Description:
 * Gathers the necessary information from the user and creates a `Dog` instance.
 * 
 * Input:
 * N/A
 * 
 * Output:
 * A `Dog` instance containing the user's information
*******************************************************************************/

Dog createDog() {
    // create a local `Dog` variable
    Dog userDog;

    // get information for the dog
    cout << "Enter the dog's fur color: ";
    getline(cin, userDog.furColor);
    cout << "Enter the dog's age: ";
    cin >> userDog.age;
    cout << "Enter the dog's breed: ";
    cin.ignore();
    getline(cin, userDog.breed);
    cout << "Enter the dog's name: ";
    getline(cin, userDog.name);
    cout << "For the dog's sex, enter 0 for male or 1 for female: ";
    cin >> userDog.sex;

    // return the instance
    return userDog;
}

/*******************************************************************************
 * Description:
 * Gathers the necessary information from the user and creates a `Person`
 * instance.
 * 
 * Input:
 * N/A
 * 
 * Output:
 * A `Person` instance containing the user's information
*******************************************************************************/

Person createPerson() {
    // create a local `Person` variable
    Person userPerson;

    // get information for the person
    cout << "Enter the person's name: ";
    getline(cin, userPerson.name);
    cout << "Enter the person's age: ";
    cin >> userPerson.age;
    cout << "Now getting the person's pet information!\n";
    cin.ignore();
    userPerson.pet = createDog();

    // return the instance
    return userPerson;
}

/*******************************************************************************
 * Description:
 * Gathers the necessary information from the user and creates a `Book`
 * instance.
 * 
 * Input:
 * N/A
 * 
 * Output:
 * A `Book` instance containing the user's information
*******************************************************************************/

Book createBook() {
    // create a local `Book` variable
    Book userBook;

    // get information for the book
    cout << "Enter the title: ";
    getline(cin, userBook.title);
    cout << "Enter the genre: ";
    getline(cin, userBook.genre);
    cout << "Enter the price: $";
    cin >> userBook.price;
    cout << "Now getting the author's information!\n";
    cin.ignore();
    userBook.author = createPerson();

    // return the instance
    return userBook;
}
