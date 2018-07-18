#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int index = -1;

struct data_mobil{
	char mobil[12];
	char type[35];
	char customer[15];
	
}; data_mobil psn[10];

bool IsEmpty(){	//mengecek apakah stock kosong
	if (index == -1){
		return true;
	}
	return false;
}

bool IsFull(){	//mengecek apakah stock ada
	if (index == 10){
		return true;
	}
	return false;
}

void display(){
	int i;
	if (!IsEmpty()){ //menampilkan data yang sudah di inputkan
		system("cls");
		cout<<("-------------------------Aplikasi Showroom Mobil-------------------------\n");
		for (int i = 0; i <= index; i++){
			cout << "\nNama Customer : " << psn[i].customer;
			cout << "\nJenis Mobil yang akan Dibeli	  : " << psn[i].mobil;
			cout << "\nType Mobil yang akan Dibeli : " << psn[i].type;

		}
	}
	else {
		cout << "Stock Habis\n";
	}
}

void antrian(){	// Queue dimana kondisi ini untuk menambahkan data custemer
	if (!IsFull()){
		index++;
		
		cin.ignore();
		system("cls");
		cout<<("-------------------------Aplikasi Showroom Mobil-------------------------\n");
		cout << "No Antrian Anda adalah : " << index+1 << endl;
		cout << "\nMasukkan Nama Customer : "; cin.getline(psn[index].customer, 15);
		cout << "\nJenis Mobil yang akan Dibeli : "; cin.getline(psn[index].mobil, 20);
		cout << "\nType Mobil yang akan Dibeli : "; cin.getline(psn[index].type, 12);
	}
	else{
		cout << "Stock Tersedia\n";
	}
}

void mobil_laku(){ // memanggil antrean atau menghapus antrean
	string a,b,c;
	if (!IsEmpty()){
		for (int i = 0; i < index; i++){
			a=strcpy(psn[i].customer, psn[i+1].customer);
			b=strcpy(psn[i].mobil, psn[i+1].mobil);
			c=strcpy(psn[i].type, psn[i+1].type);

		} 
		cout << "\nMobil Telah Dibeli"<<endl;
	 	index--;
	}
	else {
		cout << "Stock Kosong\n";
	}
}

int main (){ // menu utama
	int pilih;
	while(pilih != 4){
		system("cls");
		cout<<"-------------------------------------------------------------------\n";
		cout<<("-------------------------Aplikasi Showroom Mobil------------------\n");
		cout<<"-------------------------------------------------------------------\n\n";
			cout<<"Menu :\n\n";
			cout<<"1. Masukkan Mobil\n\n";
			cout<<"2. Daftar Mobil Pesanan\n\n";
			cout<<"3. Lihat Jenis dan Type Mobil\n\n";
			cout<<"4. Exit\n\n";
			cout<<"Silahkan Masukkan Pilihan (1-4) : ";
			cin >> pilih;
			if (pilih == 1) {
				antrian();
				cout << "\nData Disimpan";
				getch();
			}
			else if (pilih == 2){
				mobil_laku();
				getch();
			}
			else if (pilih == 3){
				display();
				getch();
			}
	}
	cout << "Terimakasih Telah Menggunakan Aplikasi Ini";
	getch();

}
