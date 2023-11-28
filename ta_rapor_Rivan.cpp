#include <iostream>
#include <limits>
#include <fstream>
#include <windows.h>

using namespace std;

class Siswa{
    int noabsen;
    char nama[50]; //array
    int ntugas, npts, npas, nabsen;
    int nakhir;
    char nhuruf;

    public:
        void getData();
        void showData()const; //sebagai tipe pengembalian tidak mempengaruhi tipe fungsi, jadi itu tidak sepenuhnya tidak berarti
        void calculate();
        int retroabsen()const; //sebagai tipe pengembalian tidak mempengaruhi tipe fungsi, jadi itu tidak sepenuhnya tidak berarti
};

//fungsi gotoxy buat penempatan menu
void gotoxy(int x, int y){
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//fungsi perhitungan nilai akhir dan nilai huruf
void Siswa::calculate(){
    nakhir=((ntugas*0.2) + (npts*0.3) + (npas*0.4) + (nabsen*0.1));
    if(nakhir>=93){
        nhuruf='A';
    }else if(nakhir>=84){
        nhuruf='B';
    }else if(nakhir>=75){
        nhuruf='C';
    }else{
        nhuruf='D';
    }
}

//fungsi getdata untuk mendapatkan data yang diinputkan
void Siswa::getData(){

    noabsen:
    cout << "|                No. Absen                  : "; cin >> noabsen;
    while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n'); //untuk enter kebawah
				cout << "NO. ABSEN HARUS BERUPA ANGKA !" << endl;
				getchar();
				goto noabsen;
			}
			if(!cin.fail())
			break;
		}

    nama:
    cout << "|                Nama                       : "; cin.ignore(); cin.getline(nama,50);

    nilaitugas:
    cout << "|                Tugas            (0- 100)  : "; cin >> ntugas;
    if (ntugas > 100 || ntugas < 0){
        cout << "Batasan 0- 100. Inputkan Kembali" << endl;
        goto nilaitugas;
    }else{
        goto tugasw;
    }
    tugasw:
    while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n'); //untuk enter kebawah
				cout<< "NILAI TUGAS HARUS BERUPA ANGKA !" << endl;
				getchar();
				goto nilaitugas;
			}
			if(!cin.fail())
			break;
		}

    nilaipts:
    cout << "|                PTS              (0- 100)  : "; cin >> npts;
    if (npts > 100 || npts < 0){
        cout << "Batasan 0- 100. Inputkan Kembali" << endl;
        goto nilaipts;
    }else{
        goto ptsw;
    }
    ptsw:
    while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n'); //untuk enter kebawah
				cout << "NILAI PTS HARUS BERUPA ANGKA !" << endl;
				getchar();
				goto nilaipts;
			}
			if(!cin.fail())
			break;
		}

    nilaipas:
    cout << "|                PAS              (0- 100)  : "; cin >> npas;
    if (npas > 100 || npas < 0){
        cout << "Batasan 0- 100. Inputkan Kembali" << endl;
        goto nilaipas;
    }else{
        goto pasw;
    }
    pasw:
    while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n'); //untuk enter kebawah
				cout << "NILAI PAS HARUS BERUPA ANGKA !" << endl;
				getchar();
				goto nilaipas;
			}
			if(!cin.fail())
			break;
		}

    absen:
    cout << "|                Absensi          (0- 100)  : "; cin >> nabsen;
    if (nabsen > 100 || nabsen < 0){
        cout << "Batasan 0- 100. Inputkan Kembali" << endl;
        goto absen;
    }else{
        goto absenw;
    }
    absenw:
    while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n'); //untuk enter kebawah
				cout << "ABSENSI HARUS BERUPA ANGKA !" << endl;
				getchar();
				goto absen;
			}
			if(!cin.fail())
			break;
		}

    calculate();
    cout << "|                Nilai Akhir                : " << nakhir << endl;
    cout << "|                Nilai Huruf                : " << nhuruf << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
}

//fungsi tampilan data yang telah diinputkan
void Siswa::showData()const{
    cout << " No. Absen                  :  " << noabsen << endl;
    cout << " Nama                       :  " << nama << endl;
    cout << " Tugas            (0- 100)  :  " << ntugas << endl;
    cout << " PTS              (0- 100)  :  " << npts << endl;
    cout << " PAS              (0- 100)  :  " << npas << endl;
    cout << " Absensi          (0- 100)  :  " << nabsen << endl;
    cout << " Nilai Akhir                :  " << nakhir << endl;
    cout << " Nilai Huruf                :  " << nhuruf << endl;
    cout << endl;
}

//fungsi cari absen
int Siswa::retroabsen()const{
    return noabsen;
}

void tambahdata();
void caridata(int);
void rekapdata();
void editdata(int);
void menu();
void Intro();

//fungsi utama atau main
int main(){
    int pilih;
    int num;

    system("color F0"); //warna layar
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //fullscreen layar

	Intro();

    qiuqiu:
    do{
        system("cls");

        menu();
        gotoxy(73, 28); cin >> pilih;
        while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n'); //untuk enter kebawah
				gotoxy(58, 35); cout << "+--------------------------------------------------+" << endl;
				gotoxy(58, 36); cout << "|             INPUTAN HARUS ANGKA !                |" << endl;
				gotoxy(58, 37); cout << "+--------------------------------------------------+" << endl;
				getchar();
				goto qiuqiu;
			}
			if(!cin.fail())
			break;
		}
        system("cls");
        switch(pilih){
            case 1 :
                system("cls");
                cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                cout << "|                                            I N P U T      D A T A                                              |" << endl;
                cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                tambahdata();
                break;
            case 2 :
                p:
                system("cls");
                cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                cout << "|                                            C A R I        D A T A                                              |" << endl;
                cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                cout << "|      Masukkan No Absen : "; cin >> num;
                gotoxy(113, 3); cout << "|" << endl;
                while(1){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //untuk enter kebawah
                        cout << "NO. ABSEN HARUS BERUPA ANGKA !" << endl;
                        getchar();
                        goto p;
                }
                    if(!cin.fail())
                    break;
                }
                caridata(num);
                break;
            case 3 :
                system("cls");
                cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                cout << "|                                            R E K A P      D A T A                                              |" << endl;
                cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                rekapdata();
                break;
            case 4 :
                q:
                system("cls");
                cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                cout << "|                                            E D I T        D A T A                                              |" << endl;
                cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                cout << "|      Masukkan No Absen : "; cin >> num;
                gotoxy(113, 3); cout << "|" << endl;
                while(1){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //untuk enter kebawah
                        cout << "NO. ABSEN HARUS BERUPA ANGKA !" << endl;
                        getchar();
                        goto q;
                }
                    if(!cin.fail())
                    break;
                }
                editdata(num);
                break;
            case 5 :
                system("cls");
                gotoxy(27, 1); cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                gotoxy(27, 2); cout << "|                                        T E R I M A      K A S I H                                              |" << endl;
                gotoxy(27, 3); cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
                exit(0);
                break;
            default :
                gotoxy(27, 10); cout << "|   |                                         Maaf, inputan salah!                                          |   |" << endl;
                break;
        }
    }while(pilih!=5);
    return 0;
}

//fungsi tambahdata
void tambahdata(){
    Siswa siswa;

    ofstream oFile;
    oFile.open("siswa.txt", ios::binary | ios::app);
    siswa.getData();
    oFile.write(reinterpret_cast<char*>(&siswa),sizeof(Siswa)); //char pointer sizeof tipedata Siswa lha data seng ditulis opo berarti <char*>(&siswa)
    oFile.close();
    cout << "|   |                                         Data Telah Di Rekam                                            |   |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
    cin.ignore();
    cin.get();
}

//fungsi rekapdata
void rekapdata(){
    Siswa siswa;

    ifstream inFile;
    inFile.open("siswa.txt", ios::binary);
    if(!inFile){
        cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|   |                              File could not be open ! Press any key to exit                            |   |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    cout << endl;
    while(inFile.read(reinterpret_cast<char*>(&siswa),sizeof(Siswa))) //char pointer sizeof tipedata Siswa lha data seng ditulis opo berarti <char*>(&siswa)
    {
        siswa.showData();
        cout << endl;
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

//fungsi caridata
void caridata(int n){
    Siswa siswa;

    ifstream iFile;
    iFile.open("siswa.txt", ios::binary);
    if(!iFile){
        cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|   |                              File could not be open ! Press any key to exit                            |   |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    while(iFile.read(reinterpret_cast<char*>(&siswa),sizeof(Siswa))) //char pointer sizeof tipedata Siswa lha data seng ditulis opo berarti <char*>(&siswa)
    {
        if(siswa.retroabsen()==n){
            siswa.showData();
            cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|   |                                             Data      Ditemukan                                        |   |" << endl;
            cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
            goto p;
        }
    }
    cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|   |                                           Data  Tidak Ditemukan                                        |   |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
    p:
    iFile.close();
    cin.ignore();
    cin.get();
}

//fungsi editdata
void editdata(int n){
    bool found=false;
    Siswa siswa;
    fstream fl;
    fl.open("siswa.txt", ios::binary | ios::in | ios::out);
    if(!fl){
        cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|   |                              File could not be open ! Press any key to exit                            |   |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
        cin.ignore();
        cin.get();
        return;
    }while(!fl.eof() && found==false){
        fl.read(reinterpret_cast<char*>(&siswa),sizeof(Siswa)); //char pointer sizeof tipedata Siswa lha data seng ditulis opo berarti <char*>(&siswa)
        if(siswa.retroabsen()==n){
            siswa.showData();
            //cout << "Memasukkan Data Siswa Baru" << endl;
            siswa.getData();
            int pos=(-1)*static_cast<int>(sizeof(siswa));
            fl.seekp(pos, ios::cur);
            fl.write(reinterpret_cast<char*>(&siswa),sizeof(Siswa)); //char pointer sizeof tipedata Siswa lha data seng ditulis opo berarti <char*>(&siswa)
            cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|   |                                         Data Telah Di Rekam                                            |   |" << endl;
            cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
            found=true;
            goto q;
        }
    }
    fl.close();
    if(found==false)
    cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|   |                                           Data Tidak Ditemukan                                         |   |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
    q:
    fl.close();
    cin.ignore();
    cin.get();
}

//fungsi menu
void menu(){
    gotoxy(58, 13); cout << "+--------------------------------------------------+";
    gotoxy(58, 14); cout << "|            N I L A I     S I S W A               |";
    gotoxy(58, 15); cout << "|            SDN PERCOBAAN 1 MALANG                |";
    gotoxy(58, 16); cout << "|--------------------------------------------------|";
    gotoxy(58, 17); cout << "|                                                  |";
	gotoxy(58, 18); cout << "|   +------------------------------------------+   |";
	gotoxy(58, 19); cout << "|   |               Menu Pilihan               |   |";
	gotoxy(58, 20); cout << "|   +------------------------------------------+   |";
	gotoxy(58, 21); cout << "|   |   1. Input Data                          |   |";
	gotoxy(58, 22); cout << "|   |   2. Cari Data                           |   |";
	gotoxy(58, 23); cout << "|   |   3. Rekap Data                          |   |";
	gotoxy(58, 24); cout << "|   |   4. Edit Data                           |   |";
	gotoxy(58, 25); cout << "|   |   5. Exit                                |   |";
	gotoxy(58, 26); cout << "|   |                                          |   |";
	gotoxy(58, 27); cout << "|   +------------------------------------------+   |";
	gotoxy(58, 28); cout << "|   |  Pilih :                                 |   |";
	gotoxy(58, 29); cout << "|   +------------------------------------------+   |";
	gotoxy(58, 30); cout << "|                                                  |";
	gotoxy(58, 31); cout << "+--------------------------------------------------+";
}

//fungsi intro sebelum menu
void Intro(){
     gotoxy(58, 13); cout << "+--------------------------------------------------+" << endl;
     gotoxy(58, 14); cout << "|      A PROGRAM BY RIVAN ADI KURNIAWAN            |" << endl;
     gotoxy(58, 15); cout << "|               220533600710                       |" << endl;
     gotoxy(58, 16); cout << "+--------------------------------------------------+" << endl;
     Sleep(400);
     system("cls");
     for(int i=1;i<=100;++i) //perulangan
     {
         Sleep(1);
         system("cls");
         gotoxy(58, 13); cout << "+--------------------------------------------------+" << endl;
         gotoxy(58, 14); cout << "|                  WELCOME TO                      |" << endl;
         gotoxy(58, 15); cout << "|                   LOADING                        |" << endl;
         gotoxy(58, 16); cout << "|                      " << i << "%"; gotoxy(109, 16); cout << "|" << endl;
         if(i==100){
             Sleep(1);
         }
         gotoxy(58, 17); cout << "+--------------------------------------------------+" << endl;
     }
     system("cls");
     gotoxy(58, 13); cout << "+--------------------------------------------------+" << endl;
     gotoxy(58, 14); cout << "|                    NILAI SISWA                   |" << endl;
     gotoxy(58, 15); cout << "+--------------------------------------------------+" << endl;
     Sleep(400);
     system("cls");
}

