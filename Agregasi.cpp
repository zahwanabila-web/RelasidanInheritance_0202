#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "anak.h"
#include "ibu.h"
int main()
{
    ibu* varIbu = new ibu("rani");
    ibu* varIbu2 = new ibu("sari");
    anak* varAnak1 = new anak("tono");
    anak* varAnak2 = new anak("tiara");
    anak* varAnak3 = new anak("dini");

    varIbu->cetakAnak();
    varIbu2->cetakAnak();

    return 0;

}