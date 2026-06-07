#include <iostream>
#include <vector>
using namespace std;

// Base class Person
class Person {
protected:
    string name;

public:
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }
};

// Student class (inherits Person)
class Student : public Person {
private:
    int roomNo;
    double fee;

public:
    Student() {
        roomNo = -1;
        fee = 0;
    }

    // Assign room to student
    void assignRoom(int r) {
        roomNo = r;
    }

    int getRoom() {
        return roomNo;
    }

    // Add fee
    void addFee(double f) {
        fee += f;
    }

    double getFee() {
        return fee;
    }
};

// Warden class
class Warden : public Person {
public:
    void showMessage() {
        cout << "Warden is managing hostel.\n";
    }
};

// Room base class
class Room {
protected:
    int number;
    bool occupied;

public:
    Room(int n) {
        number = n;
        occupied = false;
    }

    bool isOccupied() {
        return occupied;
    }

    void setOccupied(bool o) {
        occupied = o;
    }

    int getNumber() {
        return number;
    }

    // Virtual function
    virtual void display() {
        cout << "Room: " << number;
    }
};

// Single Room class
class SingleRoom : public Room {
public:
    SingleRoom(int n) : Room(n) {}

    void display() {
        cout << "Single Room: " << number;
    }
};

// Double Room class
class DoubleRoom : public Room {
public:
    DoubleRoom(int n) : Room(n) {}

    void display() {
        cout << "Double Room: " << number;
    }
};

// Payment class
class Payment {
public:
    void pay(Student &s, double amount) {
        s.addFee(amount);
        cout << "Payment added!\n";
    }
};

// Maintenance class
class Maintenance {
public:
    string issue;
    string status;

    void create(string i) {
        issue = i;
        status = "Pending";
    }

    void show() {
        cout << "Issue: " << issue << " | Status: " << status << endl;
    }
};

// Main program
int main() {

    vector<Student> students;
    vector<Room*> rooms;
    vector<Maintenance> requests;
    Payment payment;
    Warden warden;

    int choice;

    do {

        // Menu
        cout << "\n==== HOSTEL SYSTEM ====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Room\n";
        cout << "3. Allocate Room\n";
        cout << "4. Pay Fee\n";
        cout << "5. Add Maintenance Request\n";
        cout << "6. Show Students\n";
        cout << "7. Show Rooms\n";
        cout << "8. Show Requests\n";
        cout << "9. Warden Info\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Add Student
        if (choice == 1) {
            Student s;
            string name;

            cout << "Enter name: ";
            cin >> name;

            s.setName(name);
            students.push_back(s);

            cout << "Student added!\n";
        }

        // Add Room
        else if (choice == 2) {
            int type, num;

            cout << "1. Single Room\n2. Double Room\nChoose: ";
            cin >> type;

            cout << "Enter number: ";
            cin >> num;

            if (type == 1)
                rooms.push_back(new SingleRoom(num));
            else
                rooms.push_back(new DoubleRoom(num));

            cout << "Room added!\n";
        }

        // Allocate Room
        else if (choice == 3) {
            int s, r;

            cout << "Student index: ";
            cin >> s;

            cout << "Room index: ";
            cin >> r;

            if (s < students.size() && r < rooms.size()) {

                if (!rooms[r]->isOccupied()) {

                    students[s].assignRoom(rooms[r]->getNumber());
                    rooms[r]->setOccupied(true);

                    cout << "Room allocated!\n";
                }
                else {
                    cout << "Room already taken!\n";
                }

            } else {
                cout << "Invalid input!\n";
            }
        }

        // Pay Fee
        else if (choice == 4) {
            int s;
            double amount;

            cout << "Student index: ";
            cin >> s;

            cout << "Amount: ";
            cin >> amount;

            if (s < students.size()) {
                payment.pay(students[s], amount);
            }
        }

        // Add Maintenance Request
        else if (choice == 5) {
            Maintenance m;
            string issue;

            cout << "Enter issue: ";
            cin >> issue;

            m.create(issue);
            requests.push_back(m);

            cout << "Request added!\n";
        }

        // Show Students
        else if (choice == 6) {
            for (int i = 0; i < students.size(); i++) {
                cout << i << ". " << students[i].getName();

                if (students[i].getRoom() == -1)
                    cout << " | No Room";
                else
                    cout << " | Room: " << students[i].getRoom();

                cout << " | Fee: " << students[i].getFee();

                cout << endl;
            }
        }

        // Show Rooms
        else if (choice == 7) {
            for (int i = 0; i < rooms.size(); i++) {

                cout << i << ". ";
                rooms[i]->display();

                if (rooms[i]->isOccupied())
                    cout << " (Occupied)";
                else
                    cout << " (Free)";

                cout << endl;
            }
        }

        // Show Requests
        else if (choice == 8) {
            for (int i = 0; i < requests.size(); i++) {
                requests[i].show();
            }
        }

        // Warden Info
        else if (choice == 9) {
            warden.showMessage();
        }

    } while (choice != 0);

    // Free memory
    for (int i = 0; i < rooms.size(); i++) {
        delete rooms[i];
    }

    cout << "Goodbye!\n";
    return 0;
}