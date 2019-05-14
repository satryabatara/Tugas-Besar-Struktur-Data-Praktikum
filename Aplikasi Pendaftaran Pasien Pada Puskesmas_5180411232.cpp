#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>

#define POLI 8
#define MAX 14

//NAMA : ANDI SATRYA BATARA AGUNG
//NIM : 5180411232



using namespace std;

typedef string infotype;
//Data Pasien
typedef struct tNode *address;
typedef bool status;
typedef struct tNode{
	infotype NoPaasien;
	infotype NamaPS;
	infotype JenisKMR;
	infotype Tahun;
	int biayaSewa;
	status sewa;
	address Next;
}Pasien;
typedef Pasien *List;

//Data Poli
typedef int pos;
typedef struct{
	pos Head;
	pos Tail;
	infotype noPoliPasien[POLI];
	infotype Nama[POLI];
	infotype Keahlian[POLI];
	infotype Usia[POLI];
	
}Queue;

//Data Transaksi Pendaftaran
typedef struct{
	pos Head;
	pos Tail;
	infotype noPoliPasien[MAX];
	infotype TanggalPendaftaran[MAX];
	infotype DataPasienTransaksiPendaftaran[MAX];
	
}TransaksiP;

//Tanggal
struct waktu{
	int Tanggal;
	int Bulan;
	int Tahun;
}Date;

void printwaktu (waktu waktumu);
	


//ADT Pasien
typedef Pasien *List;
void CreateEmpty(List &L);
bool IsEmpty(List L);
bool IsOneElement(List L);

void updateTarif(List &L,int biayaSewa,int select,int no);

void insertFirst(List &L,address P);
void insertAfter(List &L,address Prec,address P);
address alokasi(infotype nomorPS,infotype NamaPS,infotype JenisKMR,infotype tahun,int biaya);
void addPasien(List &L,address P);
void delFirst(List &L);
void delPasien(List &L,int select,int no);

void printPasien(List L,int no);
void availablePasien(List L,int no);
void inisialisasiPasien(List &L,infotype nomorPS);

//ADT Poli
void CreateEmpty(Queue *D);
bool isEmpty(Queue D);
bool isFull(Queue D);
bool isTask(Queue D);
bool isOneElement(Queue D);
void addPoli(Queue *D,infotype polii,infotype nama,infotype alamat);
void Task(Queue *D,infotype *nama);
void updatePoli(Queue *D,infotype update,pos select);
void delPoli(Queue *D,pos select);
void printPoli(Queue D);
void inisialisasiPoli(Queue *D,infotype nama);

//ADT Transaksi Pendaftaran
void CreateEmpty(TransaksiP *K);
bool isEmpty(TransaksiP K);
bool isFull(TransaksiP K);
bool isOneElement(TransaksiP K);
void addTransaksiPendaftaran(TransaksiP *K,infotype polii,infotype tanggalpendaftaran,infotype datapasientranksasi);
void printTransaksiP(TransaksiP K);
void delTransaksiP(TransaksiP *K,pos select);
void delTransaksiP(TransaksiP *K,infotype *nama,infotype *alamat);

int main(){

	Queue Poli;
	TransaksiP transaksipendaftaran;	
	List pasien;
	address data;
	infotype nomorPS,NamaPS,JenisKMR,tahun;
	int biayasewa = 0;
	int denda = 0;
	int totbiaya = 0;
	infotype nama,polii,alamat,umur,nama_driver;
	int no=0;
	int pilih;
	int select;
	char opsi;


	CreateEmpty(&Poli);
	CreateEmpty(pasien);
	CreateEmpty(&transaksipendaftaran);

	//Pasien
	data = alokasi("901","Yusril","VIP","2019",350000);
	addPasien(pasien,data);
	data = alokasi("901","Robi","Bangsal","2018",500000);
	addPasien(pasien,data);
	//Poli
	addPoli(&Poli,"233223213","Dr.Satrya","Ahli Bedah");
	addPoli(&Poli,"827232124","Dr.Fiona","Penyakit Dalam");	
	addPoli(&Poli,"922124233","Dr.Chyntia","Psikiater");
	

	
	do{
		cout<<"---------------------------------------------------------------------"<<endl;
		cout<<"\t\t\"Aplikasi Pendaftaran Pasien Pada Puskesmas\""<<endl;
		cout<<"---------------------------------------------------------------------"<<endl;
		cout<<" 1. Data Pasien"<<endl;
		cout<<" 2. Data Poli"<<endl;
		cout<<" 3. Tranksaksi Pendaftaran"<<endl;
		cout<<" 0. Keluar"<<endl;
		cout<<"---------------------------------------------------------------------"<<endl;
		cout<<"Pilih Menu : ";
		cin>>pilih;
		system("clear");
		switch(pilih){
			case 1:
				do{
					cout<<"-----------------------------------------"<<endl;
					cout<<"\t\t\"DATA PASIEN\""<<endl;
					cout<<"-----------------------------------------"<<endl;
					cout<<" 1. Tampilkan Data Pasien"<<endl;
					cout<<" 2. Tambah Data Pasien"<<endl;
					cout<<" 3. Update Tarif Sewa"<<endl;
					cout<<" 4. Hapus Data Pasien"<<endl;
					cout<<" 9. Kembali"<<endl;
					cout<<"-----------------------------------------"<<endl;
					cout<<"Pilih Menu : ";
					cin>>pilih;
					system("clear");
					switch(pilih){
						case 1:
							cout<<"0. Kembali"<<endl;
							cout<<"-----------------------------------------------------------------------------------------"<<endl;
							cout<<"| No |"<<"   No Pasien |"<<"     Nama Pasien |"<<"    Jenis Kamar   |"<<"  Tahun  |"
							<<"   Biaya   |"<<endl;
							cout<<"-----------------------------------------------------------------------------------------"<<endl;
							printPasien(pasien,no);
							cout<<"-----------------------------------------------------------------------------------------"<<endl;
							cin>>pilih;
							system("clear");

							break;
						case 2:
							cout<<"Masukkan No Pasien\t: ";
							cin.ignore();
							getline(cin,nomorPS);
							cout<<"Masukkan Nama Pasien\t: ";
							getline(cin,NamaPS);
							cout<<"Masukkan Jenis Kamar Pasien\t: ";
							getline(cin,JenisKMR);
							cout<<"Masukkan Tahun\t\t: ";
							cin>>tahun;
							cout<<"Masukkan Biaya Pengobatan\t: ";
							cin>>biayasewa;

							data = alokasi(nomorPS,NamaPS,JenisKMR,tahun,biayasewa);
							addPasien(pasien,data);
							system("clear");

							break;
							case 3:
							cout<<"0. Kembali"<<endl;
							cout<<"-----------------------------------------------------------------------------------------"<<endl;
							cout<<"| No |"<<"   No Pasien |"<<"     Nama Pasien |"<<"    Jenis Kamar   |"<<"  TAHUN  |"
							<<"   BIAYA   |"<<endl;
							cout<<"-----------------------------------------------------------------------------------------"<<endl;
							printPasien(pasien,no);
							cout<<"-----------------------------------------------------------------------------------------"<<endl;
							cout<<"Pilih Pasien : ";
							cin>>select;
							cout<<"Masukkan Tarif Biaya Pasien : ";
							cin>>biayasewa;
							updateTarif(pasien,biayasewa,select,no);

							
							system("clear");
							break;
						case 4:
							cout<<"0. Kembali"<<endl;
							cout<<"-----------------------------------------------------------------------------------------"<<endl;
							cout<<"| No |"<<"   No Pasien |"<<"     Nama Pasien |"<<"    Jenis Kamar   |"<<"  TAHUN  |"
							<<"   BIAYA   |"<<endl;
							cout<<"-----------------------------------------------------------------------------------------"<<endl;
							printPasien(pasien,no);
							cout<<"-----------------------------------------------------------------------------------------"<<endl;
							cout<<"Pilih Pasien : ";
							cin>>select;

							delPasien(pasien,select,no);
							system("clear");
							break;
							
							case 9:
							system("clear");
							break;
						default:
							cout<<"Menu yang anda pilih tidak tersedia"<<endl;
					}
				}while(pilih!=9);
				break;
				
					case 2:
				do{
					cout<<"-----------------------------------------"<<endl;
					cout<<"\t\t\"DATA POLI\"\t\t"<<endl;
					cout<<"-----------------------------------------"<<endl;
					cout<<" 1. Tampilkan Data Poli"<<endl;
					cout<<" 2. Tambah Data Poli"<<endl;
					cout<<" 3. Update Umur Poli"<<endl;
					cout<<" 4. Hapus Data Poli"<<endl;
					cout<<" 9. Kembali"<<endl;
					cout<<"-----------------------------------------"<<endl;
					cout<<"Pilih Menu : ";
					cin>>pilih;
					system("clear");
					switch(pilih){
						case 1:
							cout<<"0. Kembali"<<endl;

							printPoli(Poli);
							cin>>pilih;
							system("clear");

							break;
						case 2:
							cout<<"0. Kembali"<<endl;
							cout<<"Masukkan Nama Dokter\t\t: ";
							cin.ignore();
							getline(cin,nama);
							cout<<"Masukkan No Poli\t\t: ";
							getline(cin,polii);
							cout<<"Masukkan Keahlian Dokter Dalam Poli\t\t: ";
							getline(cin,alamat);
						

							addPoli(&Poli,polii,nama,alamat);
							system("clear");

							break;
						case 3:
							cout<<"0. Kembali"<<endl;

							printPoli(Poli);
							cout<<"Pilih Data Poli : ";
							cin>>select;

							cout<<"Masukkan Keahlian Dokter Poli : ";
							cin>>alamat;

							updatePoli(&Poli,alamat,select);
							system("clear");

							break;
						case 4:
							cout<<"0. Kembali"<<endl;

							printPoli(Poli);
							cout<<"Pilih Data Poli : ";
							cin>>select;
							delPoli(&Poli,select);
							system("clear");

							break;
						case 9:
							system("clear");
							break;
						default:
							cout<<"Menu yang anda pilih tidak tersedia"<<endl;
					}
				}while(pilih!=9);
				
				break;
				
				case 3:
				do{
					cout<<"-----------------------------------------"<<endl;
					cout<<"\t\t\"TRANSAKSI PENDAFTARAN\""<<endl;
					cout<<"-----------------------------------------"<<endl;
					cout<<" 1. Tampilkan Data Transaksi Pendaftaran"<<endl;
					cout<<" 2. Tambah Data Transaksi Pendaftaran"<<endl;
					cout<<" 3. Hapus Data Transaksi Pendaftaran"<<endl;
					cout<<" 9. Kembali"<<endl;
					cout<<"-----------------------------------------"<<endl;
					cout<<"Pilih Menu : ";
					cin>>pilih;
					system("clear");
					switch(pilih){
						case 1:
							cout<<"0. Kembali"<<endl;
							printTransaksiP(transaksipendaftaran);
							cin>>pilih;
							system("clear");

							break;
						case 2:
							cout<<"0. Kembali"<<endl;
							
							cout<<"Masukkan Tanggal Pendaftaran [dd-mm-yyyy] \t: ";
							cin.ignore();
							getline(cin,nama);
							cout<<"Masukkan Data Pasien (Nama Pasien) \t: ";
							getline(cin,alamat);
							cout<<"Masukkan No Poli Pasien \t: ";
							getline(cin,polii);
							

							addTransaksiPendaftaran(&transaksipendaftaran,polii,nama,alamat);
							
							
							cin>>pilih;
							system("clear");

							break;
						case 3:
							printTransaksiP(transaksipendaftaran);
							cin>>select;
							delTransaksiP(&transaksipendaftaran,select);
							system("clear");
							break;
						case 9:
							system("clear");
							break;
						default:
							cout<<"Menu yang anda pilih tidak tersedia"<<endl;
					}
				}while(pilih!=9);
				
				break;
			case 0:
				cout<<"================================================"<<endl;
				cout<<"Terimah Kasih , dan Jangan Lupa Jaga Kesehatan"<<endl;
				cout<<"================================================"<<endl;
				break;
			default:
				cout<<"Menu yang anda pilih tidak tersedia"<<endl;
		}
	}while(pilih != 0);
	
	return 0;
}
void CreateEmpty(List &L){
	L = NULL;	
}

bool IsEmpty(List L){
	return (L == NULL);
}

bool IsOneElement(List L){
	return (IsEmpty(L->Next));
}

bool isRent(List L){
	return (L->sewa == 1);
}

void insertFirst(List &L,address P){
	P->Next = L;
	L = P;
}

void insertAfter(List &L,address Prec,address P){
	P->Next = Prec->Next;
	Prec->Next = P;
}

address alokasi(infotype nomorPS,infotype NamaPS,infotype JenisKMR,infotype tahun,int biaya){
	address P = new(Pasien);

	if(P == NULL)
		return NULL;
	else{
		P->NoPaasien = nomorPS;
		P->NamaPS = NamaPS;
		P->JenisKMR = JenisKMR;
		P->Tahun = tahun;
		P->biayaSewa = biaya;
		P->sewa = 0;
		P->Next = NULL;
		return P;
	}
}

void addPasien(List &L,address P){
	if(IsEmpty(L)){
		insertFirst(L,P);
	}else if(IsOneElement(L)){
		insertAfter(L,L,P);
	}else{
		addPasien(L->Next,P);
	}	
}

void delFirst(List &L){
	address P;
	P = L;
	L = L->Next;
	delete(P);
}

void delPasien(List &L,int select,int no){
	if(!IsEmpty(L)){
		no++;
		if(no == select)
			delFirst(L);
		else
			delPasien(L->Next,select,no);
	}else{}
}

void updateTarif(List &L,int biaya,int select,int no){
	if(!IsEmpty(L)){
		no++;
		if(no == select)
			L->biayaSewa = biaya;
		else
			updateTarif(L->Next,biaya,select,no);
	}else{}
}



void printPasien(List L,int no){
	if(IsEmpty(L)){
		// cout<<"-----------------------------------------------------------------------------------------"<<endl;
	}else{
		no++;
		cout<<"|"<<setw(4)<<no<<"|"<<setw(12)<<L->NoPaasien<<"|"<<setw(17)<<L->NamaPS<<"|"<<setw(12)<<L->JenisKMR<<"|"
		<<setw(9)<<L->Tahun<<"|"<<setw(11)<<L->biayaSewa<<"|";
		if(L->sewa==0)
			cout<<setw(17)<<""<<endl;
		else
			cout<<setw(17)<<""<<endl;
		printPasien(L->Next,no);
	
						
						
	}
}

void availablePasien(List L,int no){
	if(IsEmpty(L)){
		// cout<<"-----------------------------------------------------------------------------------------"<<endl;
	}else{
		if(L->sewa == 0){
			no++;
			cout<<"|"<<setw(4)<<no<<"|"<<setw(12)<<L->NoPaasien<<"|"<<setw(17)<<L->NamaPS<<"|"<<setw(12)<<L->JenisKMR<<"|"
			<<setw(9)<<L->Tahun<<"|"<<setw(11)<<L->biayaSewa<<"|"<<endl;		
		}else{}

		availablePasien(L->Next,no);
	}
}

void inisialisasiPasien(List &L,infotype nomorPS){
	if(IsEmpty(L)){

	}else{
		if(L->NoPaasien == nomorPS)
			L->sewa = 0;
		inisialisasiPasien(L->Next,nomorPS);
	}
}

//Poli
void CreateEmpty(Queue *D){
	(*D).Head = (*D).Tail = -1;
}

bool isEmpty(Queue D){
	return (D.Head == -1 && D.Tail == -1);
}

bool isFull(Queue D){
	return (D.Head < D.Tail && D.Tail - D.Head == POLI-1||
		D.Head > D.Tail && D.Head - D.Tail == 1);
}

bool isOneElement(Queue D){
	return (D.Head == D.Tail && D.Head != -1);
}



void addPoli(Queue *D,infotype polii,infotype nama,infotype alamat){
	if(!isFull(*D)){
		if(isEmpty(*D)){ //jika masih kosong
			(*D).Head = (*D).Tail = 0;
			(*D).noPoliPasien[(*D).Head] = polii;
			(*D).Nama[(*D).Head] = nama;
			(*D).Keahlian[(*D).Head] = alamat;
			
		
		}else{
			if((*D).Tail == POLI-1){ //jika sirkuler
				(*D).Tail = 0;
			}else{
				(*D).Tail++;
			}
			//pengisian 
			(*D).noPoliPasien[(*D).Tail] = polii;
			(*D).Nama[(*D).Tail] = nama;
			(*D).Keahlian[(*D).Tail] = alamat;
			
			
		}
	}
}

void updatePoli(Queue *D,infotype update,pos select){
	int element = 0;
	if((*D).Head <= (*D).Tail)
		(*D).Keahlian[(*D).Head + select - 1] = update;
	else{ //sirkuler
		//count element head to MAX element
		for(pos i = (*D).Head; i <= POLI-1;i++)
			element++;

		if(select<=element)
			(*D).Keahlian[(*D).Head + select - 1] = update;
		else
			(*D).Keahlian[element - select - 1] = update;
	}
}

void delPoli(Queue *D,pos select){
	int element = 0;

	if(select>=1 && select<=POLI){
		if((*D).Head <= (*D).Tail){
			for(pos i = (*D).Head+select-1; i < (*D).Tail;i++){
				(*D).Nama[i] = (*D).Nama[i+1];
				(*D).noPoliPasien[i] = (*D).noPoliPasien[i+1];
				(*D).Keahlian[i] = (*D).Keahlian[i+1];
				(*D).Usia[i] = (*D).Usia[i+1];
			
			}
			(*D).Tail--;

		}else{

			for(pos i = (*D).Head; i <= POLI-1;i++)
				element++;

			if(select<=element){ //jika masih normal
				for(pos i = (*D).Head; i < POLI-1;i++){
					(*D).Nama[i] = (*D).Nama[i+1];
					(*D).noPoliPasien[i] = (*D).noPoliPasien[i+1];
					(*D).Keahlian[i] = (*D).Keahlian[i+1];
					(*D).Usia[i] = (*D).Usia[i+1];
					
				}

				for(pos i = 0; i < (*D).Tail;i++){
					(*D).Nama[i] = (*D).Nama[i+1];
					(*D).noPoliPasien[i] = (*D).noPoliPasien[i+1];
					(*D).Keahlian[i] = (*D).Keahlian[i+1];
					(*D).Usia[i] = (*D).Usia[i+1];
				
				}
				(*D).Tail--;

			}else{//sirkuler

				if((*D).Tail == 0)
					(*D).Tail = POLI-1;

				else{
					for(pos i = element - select-1; i < (*D).Tail;i++){
						(*D).Nama[i] = (*D).Nama[i+1];
						(*D).noPoliPasien[i] = (*D).noPoliPasien[i+1];
						(*D).Keahlian[i] = (*D).Keahlian[i+1];
						(*D).Usia[i] = (*D).Usia[i+1];
						
					}
					(*D).Tail--;
				}
			}
		}
	}else{
		cout<<"Pilihan yang anda masukkan tidak tersedia"<<endl;
	}
}

void Task(Queue *D,infotype *nama){
	Queue temp; 
	if(!isEmpty(*D)){
		*nama = (*D).Nama[(*D).Head];
		
		temp = *D;

		(*D).Head++;
		if(++(*D).Tail == MAX)
			(*D).Tail = 0;
		else
			(*D).Tail;

		(*D).noPoliPasien[(*D).Tail] = temp.noPoliPasien[temp.Head];
		(*D).Nama[(*D).Tail] = temp.Nama[temp.Head];
		(*D).Keahlian[(*D).Tail] = temp.Nama[temp.Head];
		(*D).Usia[(*D).Tail] = temp.Usia[temp.Head];
		

	}else{
		cout<<"Belum ada data yang tersimpan"<<endl;
	}
}

void printPoli(Queue D){
	pos no = 0;
	if(isEmpty(D)){
		cout<<"Belum ada data driver yang tersimpan"<<endl;
	}else{
		cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"|No |"<<"\t No.Poli \t|"<<"\t  Nama Dokter\t|"<<"\t        Keahlian\t|"<<endl;
		cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
		if(D.Head <= D.Tail){
			for(pos i = D.Head; i <= D.Tail;i++){
				no++;
				cout<<"|"<<setw(4)<<no<<"|"<<setw(19)<<D.noPoliPasien[i]<<"|"<<setw(23)<<D.Nama[i]<<"|"
				<<setw(29)<<D.Keahlian[i]<<"|";
				
			}
		}else{ //sirkuler
			for(pos i = D.Head; i <= POLI-1;i++){
				no++;
				cout<<"|"<<setw(3)<<no<<"|"<<setw(19)<<D.noPoliPasien[i]<<"|"<<setw(23)<<D.Nama[i]<<"|"
				<<setw(29)<<D.Keahlian[i]<<"|";
			
			}

			for(pos i = 0; i <= D.Tail;i++){
				no++;
				cout<<"|"<<setw(3)<<no<<"|"<<setw(19)<<D.noPoliPasien[i]<<"|"<<setw(23)<<D.Nama[i]<<"|"
				<<setw(29)<<D.Keahlian[i]<<"|";
			
			}
		}
		cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
	}
}

void inisialisasiPoli(Queue *D,infotype nama){
	if(isEmpty(*D)){

	}else{
		if((*D).Head <= (*D).Tail){
			for(pos i = (*D).Head; i <= (*D).Tail;i++){
				if((*D).Nama[i] == nama){
					
					break;
				}
			}
		}else{
			for(pos i = (*D).Head; i <= POLI-1;i++){
				if((*D).Nama[i] == nama){
				
					break;
				}
			}

			for(pos i = 0; i <= (*D).Tail;i++){
				if((*D).Nama[i] == nama){
				
					break;
				}
			}
		}
	}
}

//TransaksiP
void CreateEmpty(TransaksiP *K){
	(*K).Head = (*K). Tail = -1;
}

bool isEmpty(TransaksiP K){
	return (K.Head == -1 && K.Tail == -1);
}

bool isFull(TransaksiP K){
	return (K.Head < K.Tail && K.Tail - K.Head == MAX-1 ||
		K.Head > K.Tail && K.Head - K.Tail ==1);
}

bool isOneElement(TransaksiP K){
	return (K.Head == K.Tail && K.Head != -1);
}

void addTransaksiPendaftaran(TransaksiP *K,infotype polii,infotype tanggalpendaftaran,infotype datapasientranksasi){
	if(!isFull(*K)){
		if(isEmpty(*K)){ //jika masih kosong
			(*K).Head = (*K).Tail = 0;
			(*K).noPoliPasien[(*K).Head] = polii;
			(*K).TanggalPendaftaran[(*K).Head] = tanggalpendaftaran;
			(*K).DataPasienTransaksiPendaftaran[(*K).Head] = datapasientranksasi;
		}else{
			if((*K).Tail == MAX-1){ //jika sirkuler
				(*K).Tail = 0;
			}else{
				(*K).Tail++;
			}
			//pengisian 
			(*K).noPoliPasien[(*K).Tail] = polii;
			(*K).TanggalPendaftaran[(*K).Tail] = tanggalpendaftaran;
			(*K).DataPasienTransaksiPendaftaran[(*K).Tail] = datapasientranksasi;
		}
	}else
		cout<<"Tranksaksi  Pendaftaran Berhasil"<<endl;	
}



void printTransaksiP(TransaksiP K){
	pos no = 0;
	if(isEmpty(K)){
		cout<<"Belum Ada Transaksi Pendaftaran"<<endl;
	}else{
		cout<<"---------------------------------------------------------------------------------"<<endl;
		cout<<"|"<<" No |"<<"\tNo Poli Pasien\t|"<<"\tTanggal Pendaftaran\t|"<<"\tNama Pasien\t|"<<endl;
		cout<<"---------------------------------------------------------------------------------"<<endl;
		
		if(K.Head <= K.Tail){
			for(pos i = K.Head; i <= K.Tail;i++){
				no++;
				cout<<"|"<<setw(4)<<no<<"|"<<setw(18)<<K.noPoliPasien[i]<<"|"<<setw(23)<<K.TanggalPendaftaran[i]
				<<"|"<<setw(31)<<K.DataPasienTransaksiPendaftaran[i]<<"|"<<endl;
			}
		}else{ //sirkuler
			for(pos i = K.Head; i <= MAX-1;i++){
				no++;
				cout<<"|"<<setw(4)<<no<<"|"<<setw(18)<<K.noPoliPasien[i]<<"|"<<setw(23)<<K.TanggalPendaftaran[i]
				<<"|"<<setw(31)<<K.DataPasienTransaksiPendaftaran[i]<<"|"<<endl;
			}

			for(pos i = 0; i <= K.Tail;i++){
				no++;
				cout<<"|"<<setw(4)<<no<<"|"<<setw(18)<<K.noPoliPasien[i]<<"|"<<setw(23)<<K.TanggalPendaftaran[i]
				<<"|"<<setw(31)<<K.DataPasienTransaksiPendaftaran[i]<<"|"<<endl;
			}
		}
		cout<<"---------------------------------------------------------------------------------"<<endl;
		
	}	
}

void delTransaksiP(TransaksiP *K,pos select){
	int element = 0;

	if(select>=1 && select<=MAX){
		if((*K).Head <= (*K).Tail){
			for(pos i = (*K).Head+select-1; i < (*K).Tail;i++){
				(*K).TanggalPendaftaran[i] = (*K).TanggalPendaftaran[i+1];
				(*K).noPoliPasien[i] = (*K).noPoliPasien[i+1];
				(*K).DataPasienTransaksiPendaftaran[i] = (*K).DataPasienTransaksiPendaftaran[i+1];

			}
			(*K).Tail--;

		}else{

			for(pos i = (*K).Head; i <= MAX-1;i++)
				element++;

			if(select<=element){ //jika masih normal
				for(pos i = (*K).Head; i < MAX-1;i++){
					(*K).TanggalPendaftaran[i] = (*K).TanggalPendaftaran[i+1];
					(*K).noPoliPasien[i] = (*K).noPoliPasien[i+1];
					(*K).DataPasienTransaksiPendaftaran[i] = (*K).DataPasienTransaksiPendaftaran[i+1];
				}

				for(pos i = 0; i < (*K).Tail;i++){
					(*K).TanggalPendaftaran[i] = (*K).TanggalPendaftaran[i+1];
					(*K).noPoliPasien[i] = (*K).noPoliPasien[i+1];
					(*K).DataPasienTransaksiPendaftaran[i] = (*K).DataPasienTransaksiPendaftaran[i+1];
				}
				(*K).Tail--;

			}else{//sirkuler

				if((*K).Tail == 0)
					(*K).Tail = POLI-1;

				else{
					for(pos i = element - select-1; i < (*K).Tail;i++){
						(*K).TanggalPendaftaran[i] = (*K).TanggalPendaftaran[i+1];
						(*K).noPoliPasien[i] = (*K).noPoliPasien[i+1];
						(*K).DataPasienTransaksiPendaftaran[i] = (*K).DataPasienTransaksiPendaftaran[i+1];
					}
					(*K).Tail--;
				}
			}
		}
	}else{
		cout<<"Pilihan yang anda masukkan tidak tersedia"<<endl;
	}
}

void delTransaksiP(TransaksiP *K,infotype *tanggalpendaftaran,infotype *datapasienTP){
	if(isEmpty(*K))
		cout<<"Belum ada data konsumen yang tersimpan"<<endl;
	else{
		*tanggalpendaftaran = (*K).TanggalPendaftaran[(*K).Head];
		*datapasienTP = (*K).DataPasienTransaksiPendaftaran[(*K).Head];
		if(isOneElement(*K))
			CreateEmpty(&(*K));
		else{
			if((*K).Head == MAX-1)
				(*K).Head = 0;
			else
				(*K).Head++;
		}
			
	}
}
