#include <iostream>
#include <vector>
using namespace std;

class dokter;

class pasien {
public:
    string nama;
    vector<dokter*> daftar_dokter;

    pasien(string pNama) :nama(pNama) {
        cout << "pasien \"" << nama << "\" ada\n";
    };

    void tambahDokter(dokter*);
    void cetakDokter();
};

class dokter {
public:
    string nama;
    vector<pasien*> daftar_pasien;

    dokter(string pNama) :nama(pNama) {
        cout << "Dokter \"" << nama << "\" ada\n";
    }

    ~dokter() {
        cout << "Dokter \"" << nama << "\" tidak ada\n";
    }

    void tambahpasien(pasien*);
    void cetakpasien();

};

void pasien::tambahDokter(dokter* pDokter) {
        daftar_dokter.push_back(pDokter);
};

void pasien::cetakDokter() {
    cout << "daftar Dokter yang menangani pasien \"" << this->nama << "\":\n";
    for (auto& a : daftar_dokter)
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void dokter::tambahpasien(pasien* pPasien) {
    daftar_pasien.push_back(pPasien);
    pPasien->tambahDokter(this);
}

void dokter::cetakpasien() {
    cout << "Daftar pasien dari Dokter \"" << this->nama << "\":\n";
    for (auto& a : daftar_pasien)
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main()
{

    dokter*varDokter1 = new dokter("dr. Budi");
    dokter*varDokter2 = new dokter("dr. Tono");
    pasien*varpasien1 = new pasien("Andi");
    pasien*varpasien2 = new pasien("Lia");

    varDokter1->tambahpasien(varpasien1);
    varDokter1->tambahpasien(varpasien2);
    varDokter2->tambahpasien(varpasien1);

    varDokter1->cetakpasien();
    varDokter2->cetakpasien();
    varpasien1->cetakDokter();
    varpasien2->cetakDokter();

    return 0;
    
}