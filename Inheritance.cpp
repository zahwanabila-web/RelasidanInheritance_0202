#include <iostream>
#include <string>
using namespace std;

class orang {
public:
    string nama;

    orang(string pNama) :nama(pNama) {
        cout << "Orang dibuat\n" << endl;
    }
};