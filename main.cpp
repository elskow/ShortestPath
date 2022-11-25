// The main source file for the program.
// this project gotta be an application of plane ticket booking system, that estimate the weight distribution of the plane

#include <bits/stdc++.h>

using namespace std;
int MAX_W = 5000
int MAX_p = 40;
struct data {
    string nama;
    int berat_b;
    int berat_t;
    int harga;

}
vector <data> ingfo;

void clearscreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void display_kursi(){
    cout << "Posisi kursi penumpang pesawat : " << endl;
    cout  << "=======================" << endl;
    cout << "| 1 | 2 |      | 3 | 4 |" << endl;
    cout << "| 5 | 6 |      | 7 | 8 |" << endl;
    cout << "| 9 | 10|      | 11| 12|" << endl;
    cout << "| 13| 14|      | 15| 16|" << endl;
    cout << "| 17| 18|      | 19| 20|" << endl;
    cout << "| 21| 22|      | 23| 24|" << endl;
    cout << "| 25| 26|      | 27| 28|" << endl;
    cout << "| 29| 30|      | 31| 32|" << endl;
    cout << "| 33| 34|      | 35| 36|" << endl;
    cout << "| 37| 38|      | 39| 40|" << endl;
    cout  << "=======================" << endl;

}
void informasi(){
    cout << "########################## INFORMASI ##########################" << endl;
    cout << "1. Harga kursi Ekonomiu Rp. 1.000.000" << endl;
    cout << "2. Harga kursi VIP Rp. 1.500.000" << endl;
    cout << "3. Harga kursi VVIP Rp. 2.000.000" << endl;
    cout << "Apabila Kursi sudah penuh saat pemesanan tiket akan dihubungi sebelum penerbangan " << endl;

}

void pemesanan(){
    cout << "=================Pemesanan Tiket=================" << endl;
    cout << "Silahkan pilih menu dibawah ini :       " << endl;
    cout << "1. Pemesanan Kuris Ekonomi" << endl;
    cout << "2. Pemesanan Kursi VIP" << endl;
    cout << "3. Pemesanan Kursi VVIP" << endl;
    cout << "4. Kembali" << endl;
    cout << "================================================" << endl;
    int temp;
    cin >> temp;

    if(temp == 1){
        cout << "Pemesanan Kursi Ekonomi" << endl;
        cout << "Masukkan nama anda : " << endl;
        string a;
        cin >> a;
        ingfo.nama.push_back(a);
        cout << "Masukkan berat barang anda : " << endl;
        int b;
        cin >> b;
        ingfo.berat_b.push_back(b);
        cout << "Masukkan berat tubuh anda : " << endl;
        int c;
        cin >> c;
        ingfo.berat_t.push_back(c);
        cout << "Masukkan harga barang anda : " << endl;
        int d = 1000000;
        
        ingfo.harga.push_back(c);
        cout << "Pemesanan berhasil" << endl;
        cout << "Nama : " << a << endl;
        cout << "Berat Bawaan : " << b << endl;
        cout << "Harga : " << d << endl;
        cout << "Untuk kursi anda akan kami hubungi sebelum penerbangan" << endl;
       
    }
    else if(temp == 2){
        cout << "Pemesanan Kursi VIP" << endl;
        cout << "Masukkan nama anda : " << endl;
        string a;
        cin >> a;
        ingfo.nama.push_back(a);
        cout << "Masukkan berat barang anda : " << endl;
        int b;
        cin >> b;
        ingfo.berat_b.push_back(b);
        cout << "Masukkan berat tubuh anda : " << endl;
        int c;
        cin >> c;
        ingfo.berat_t.push_back(c);
        cout << "Masukkan harga barang anda : " << endl;
        int d = 1500000;
        
        ingfo.harga.push_back(c);
        cout << "Pemesanan berhasil" << endl;
        cout << "Nama : " << a << endl;
        cout << "Berat Bawaan : " << b << endl;
        cout << "Harga : " << d << endl;
        cout << "Untuk kursi anda akan kami hubungi sebelum penerbangan" << endl;
       
    }else if(temp == 3){
        
    }else if(temp == 4){
        menu();
    }else{
        cout << "Inputan salah" << endl;
    }
    
}
void menu(){
    cout << "============Selamat Datang di Pesawat===========" << endl;
    cout << "=================PT. Angkasa====================" << endl;
    cout << "\n";
    cout << "Silahkan pilih menu dibawah ini :       " << endl;
    cout << "1. Pemesanan Tiket Pesawat" << endl;
    cout << "2. Informasi" << endl;
    cout << "3. Posisi Kursi Pesawat" << endl;
    cout << "4. Keluar" << endl;
    cout << "================================================" << endl;
    int temp;
    cin >> temp;
    if(temp == 1){
        pemesanan();
    }else if(temp == 2){
        informasi();
    }else if(temp == 3){
        display_kursi();
    }else if(temp == 4){
        exit(0);
    }else{
        cout << "Inputan salah" << endl;
    }
}


int main(){
      
        clearscreen();
        return 0;
    }

