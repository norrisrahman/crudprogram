#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <algorithm>
#include <fstream>

using namespace std;

struct Mahasiswa {
	string NIM;
	std::string nama;
    float ipk;
};

void checkDatabase(fstream &Database){
	Database.open("data.bin", ios::out | ios::in | ios::binary);

	// check file ada atau tidak
	if (Database.is_open()){
		cout << "database ditemukan" << endl;
	} else {
		cout << "database tidak ditemukan, buat database baru" << endl;
		Database.close();
		Database.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}
}

void printErr () {
    cout << "\n\nKeyword Invalid / Data Tidak Ada\n\n"<< endl;
}

void printSearch (Mahasiswa array) {
    cout << "\nHasil Pencarian Data Mahasiswa :\n" << endl;
    cout << "Nama\t: " << array.nama <<" "<< endl;
    cout << "NIM\t: " << array.NIM <<" "<< endl;
    cout << "IPK\t: " << array.ipk <<" "<< endl;
    cout << endl; 
}

void searchData (Mahasiswa array[], int n) {
    string keyword;
    cout<<"Masukkan NIM : ";
    cin >> keyword;
    for(int i=0;i<n;i++) {
        if(array[i].NIM==keyword) {
            printSearch(array[i]);
            return;
        }
    }
    printErr();
}

void sortDesc(struct Mahasiswa arr[], int n){
    int i, j;
    struct Mahasiswa key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;        
        while (j >= 0 && arr[j].NIM < key.NIM) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
            arr[j + 1] = key;
    }
}
void printData (struct Mahasiswa array[], int n) {
    int i;
    cout << "\nHasil Pengurutan Data Mahasiswa :\n" << endl;
        for (i=0;i<n;i++) {
            cout << "Nama\t: " << array[i].nama <<" "<< endl;
            cout << "NIM\t: " << array[i].NIM <<" "<< endl;
            cout << "IPK\t: " << array[i].ipk <<" "<< endl;
            cout << endl;   
	} 
}

void saveData (fstream &Database, Mahasiswa writeMahasiswa) {
    
}

int main() {
	long int n, i, arr, d;
    string x;
    fstream Database;

    checkDatabase(Database);

	cout<<"Masukan Banyak Data : ";
	cin >> n;	

	Mahasiswa*  array = new Mahasiswa[n];

	for(i=0; i<n; i++) {
        cout << "Masukan data mahasiswa ke "<< i+1 << " : " << endl;
        cout << "Nama\t : ";
		std::getline(cin >> std::ws, (array[i].nama));
        cout << "NIM\t : ";
		cin >> array[i].NIM;
        cout << "IPK\t : ";
        cin >> array[i].ipk;
        cout << endl;

	}

    menu:
    cout << "Pilih Jenis Operasi :" << endl;
    cout << "1. Urutkan Data Secara Descending" << endl;
    cout << "2. Pencarian Data Mahasiswa" << endl;
    cout << "3. Save" << endl;
    cout << endl;

    cout << "Pilih Menu [1-3]: ";
    cin >> x;

    if (x == "1"){
        sortDesc (array, n);
        printData (array, n);
        goto menu;
    }
    else if ( x=="2"){
        searchData (array, n);
        goto menu;
    }
    else if (x =="3" ) {
        Database.write(reinterpret_cast<char*>(&array), sizeof(Mahasiswa));
        Database.close();
    }
    else {
        cout << "\nInput Tidak Valid !!! \n" << endl;
        goto menu;
    }
	return 0;
}