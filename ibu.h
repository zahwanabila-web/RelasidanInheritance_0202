#ifndef IBU_H
#define IBU_H


class anak;

class ibu {
public:

    string nama;
    vector<anak*> daftar_anak;

    ibu(string pNama) :nama(pNama) {
        cout << "Ibu \"" << nama << "\" ada\n";
    };

    ~Ibu() {
        cout << "Ibu\"" << nama << "\" tidak ada\n";
    };

    void tambahAnak(anak* pAnak);
    void cetakAnak();
};

void ibu::tambahAnak(anak*pAnak) {
    daftar_anak.push_back(pAnak);
}

void ibu::cetakAnak() {
    cout << "Daftar Anak dari ibu \"" << this->nama << "\":\n";
    for (auto& a : daftar_anak)
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}
#endif