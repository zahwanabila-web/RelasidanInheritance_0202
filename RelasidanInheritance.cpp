#include <iostream>
using namespace std;


class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->nama = nama;
        this->email = email;
        id = generateId();
    }


    int generateId() {
        globalId++;
        return globalId;
    }
};


int User::globalId = 0;

//CLASS MEMBER 
class Member : public User {
private:
    bool status;

public:

    Member(string nama, string email, bool status)
        : User(nama, email) {

        this->status = status;
    }


    void showProfile() {
        cout << "PROFILE MEMBER" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;

        if (status == true) {
            cout << "Status : Aktif" << endl;
        } else {
            cout << "Status : Nonaktif" << endl;
        }

        cout << endl;
    }

    bool getStatus() {
        return status;
    }


    void setStatus(bool status) {
        this->status = status;
    }
};


class Admin : public User {
public:
    Admin(string nama, string email)
        : User(nama, email) {
    }


    void showAllMember(Member m1, Member m2) {
        cout << "DATA MEMBER" << endl;
        m1.showProfile();
        m2.showProfile();
    }

    // mengubah status member
    void toggleActivationMember(Member &m) {
        if (m.getStatus() == true) {
            m.setStatus(false);
        } else {
            m.setStatus(true);
        }
    }
};

int main() {


    Member member1("Budi", "budi@gmail.com", true);
    Member member2("Siti", "siti@gmail.com", false);

    Admin admin1("Admin", "admin@gmail.com");

    admin1.showAllMember(member1, member2);

    admin1.toggleActivationMember(member2);

    cout << "Setelah status diubah:" << endl;
    member2.showProfile();

    return 0;
}