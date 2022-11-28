#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    int x , y;

    Node(int id , int x , int y) : id(id) , x(x) , y(y) {}
};

vector<Node> nodes;

struct Node {
    int id;
    int x , y;

    Node(int id , int x , int y) : id(id) , x(x) , y(y) {}
};

vector<Node> nodes;

void clearscreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void inputKoordinat(int n){
    int x , y;
    for(int i = 0 ; i < n ; i++){
        cout << "Masukkan koordinat penerima paket ke-" << i + 1 << " : ";
        cin >> x >> y;
        nodes.push_back(Node(i + 1 , x , y));
    }
}

=======
void informasi(){
    cout << "########################## INFORMASI ##########################" << endl;
    cout << "1. Harga kursi Ekonomiu Rp. 1.000.000" << endl;
    cout << "2. Harga kursi VIP Rp. 1.500.000" << endl;
    cout << "3. Harga kursi VVIP Rp. 2.000.000" << endl;
    cout << "Apabila Kursi sudah penuh saat pemesanan tiket akan dihubungi sebelum penerbangan " << endl;


int main() {
    clearscreen();


    cout << "\t\tSelamat Datang di Aplikasi Navigasi PergiMakanan" << endl;
    cout << "\t\t==============================================" << endl;


    int startingnodesx, startingnodesy;

    cout << "Silahkan masukkan koordinat awal anda : ";
    cin >> startingnodesx >> startingnodesy;

    cout << "Masukkan jumlah alamat paket yang akan anda kirimkan : ";
    int n;
    cin >> n;

    nodes.push_back(Node(0, startingnodesx, startingnodesy));

    inputKoordinat(n);

    nodes.push_back(Node(n + 1, startingnodesx, startingnodesy));

    vector<bool> visited(nodes.size(), false);
    visited[0] = true;
    int current = 0;
    int totaldistance = 0;

    vector<int> path;
    
    while (true) {
        int next = -1;
        int mindistance = INT_MAX;

        // Find the nearest node
        for (int i = 0; i < nodes.size(); i++) {
            if (visited[i]) continue;

            int distance = abs(nodes[current].x - nodes[i].x) + abs(nodes[current].y - nodes[i].y);
            if (distance < mindistance) {
                mindistance = distance;
                next = i;
            }
        }
        if (next == -1) break;
        totaldistance += mindistance;
        path.push_back(next);
        visited[next] = true;
        current = next;
    }

    totaldistance += abs(nodes[current].x - nodes[nodes.size() - 1].x) + abs(nodes[current].y - nodes[nodes.size() - 1].y);

    cout << "Jarak total yang harus ditempuh : " << totaldistance << endl;
    cout << "Rute yang harus ditempuh : " << endl;
=======
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

    nodes.push_back(Node(n + 1, startingnodesx, startingnodesy));

    vector<bool> visited(nodes.size(), false);
    visited[0] = true;
    int current = 0;
    int totaldistance = 0;

    vector<int> path;
    
    while (true) {
        int next = -1;
        int mindistance = INT_MAX;

        // Find the nearest node
        for (int i = 0; i < nodes.size(); i++) {
            if (visited[i]) continue;

            int distance = abs(nodes[current].x - nodes[i].x) + abs(nodes[current].y - nodes[i].y);
            if (distance < mindistance) {
                mindistance = distance;
                next = i;
            }
        }
        if (next == -1) break;
        totaldistance += mindistance;
        path.push_back(next);
        visited[next] = true;
        current = next;
    }

    totaldistance += abs(nodes[current].x - nodes[nodes.size() - 1].x) + abs(nodes[current].y - nodes[nodes.size() - 1].y);

    cout << "Jarak total yang harus ditempuh : " << totaldistance << endl;
    cout << "Rute yang harus ditempuh : " << endl;

    for (int i = 0; i < path.size(); i++) {
        if (i == 0) {
            cout << "Titik keberangkatan" << " (" << nodes[path[i]].x << ", " << nodes[path[i]].y << ")" << endl;
        } else {
            cout << "Paket ke - " << nodes[path[i]].id << " (" << nodes[path[i]].x << ", " << nodes[path[i]].y << ")" << endl;
        }
    }
}


int main(){
      
        clearscreen();
        return 0;
    }



    for (int i = 0; i < path.size(); i++) {
        if (i == 0) {
            cout << "Titik keberangkatan" << " (" << nodes[path[i]].x << ", " << nodes[path[i]].y << ")" << endl;
        } else {
            cout << "Paket ke - " << nodes[path[i]].id << " (" << nodes[path[i]].x << ", " << nodes[path[i]].y << ")" << endl;
        }
    }

    return 0;
}
