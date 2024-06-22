#include <stdio.h>

struct Mahasiswa{
	char nama[50];
	char NIM[9];
	char tanggalLahir[11];
	float IPK;
};

void inputDataMahasiswa(struct Mahasiswa *mhs){
	printf("Masukkan nama: ");
	scanf("%[^\n]s", mhs->nama);
	printf("Masukkan Nim: ");
	scanf("%s", mhs->NIM);
	printf("Masukkan tanggal lahir: ");
	scanf("%s", mhs->tanggalLahir);
	printf("Masukkan IPK: ");
	scanf("%f", &mhs->IPK);
}

void tampilDataMahasiswa(struct Mahasiswa *mhs){
	printf("\n=====Data Mahasiswa=====\n");
	printf("Nama mahasiswa: %s\n", mhs->nama);
	printf("NIM: %s\n", mhs->NIM);
	printf("Tanggal lahir: %s\n", mhs->tanggalLahir);
	printf("IPK: %.2f\n", mhs->IPK);
}

int main(){
    struct Mahasiswa mhs;
    
    inputDataMahasiswa(&mhs);
    tampilDataMahasiswa(&mhs);
    
    return 0;
}