#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <algorithm>
#include <fstream>

using namespace std;

struct Mahasiswa {
	string nama;;
};

int main(){
	fstream dDatabase;
    
	dDatabase.open("data.bin", ios::in | ios::binary);

    Mahasiswa mhs;

    // mhs.nama = "boris";

    dDatabase.read(reinterpret_cast<char*>(&mhs), sizeof(Mahasiswa));
    
    cout << mhs.nama << endl;

	return 0;
}