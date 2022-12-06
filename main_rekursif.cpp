//Tugas UAS Pemrogaman Dasar
//Jurusan Teknik Informatika Universitas Negeri Surabaya


#include <bits/stdc++.h>

using namespace std;

struct Node {
    string id;
    int x , y;

    Node(string id , int x , int y) : id(id) , x(x) , y(y) {}
};

vector<Node> nodes;
vector<int> path;
void clearscreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void output(int n){
    if(n == -1){cout << "Kembali ke " << "(" << nodes[0].x << ", " << nodes[0].y << ")" << endl;
    }
    else 
    {cout << "Paket Untuk " << nodes[path[n]].id << " dengan koordinat (" << nodes[path[n]].x << ", " << nodes[path[n]].y << ")" << endl;
    output(n-1);
    }
    
}

void inputKoordinat(int n){
    int x , y;
    for(int i = 0 ; i < n ; i++){
        cout << "Masukkan nama penerima paket ke -" <<i +1 << " : ";
        string temp;
        getline(cin, temp);
        cout << "Masukkan koordinat penerima paket ke-" << i + 1 << " : ";
        cin >> x >> y;
        cin.ignore(999999,'\n');
        nodes.push_back(Node(temp , x , y));
    }
}

int main() {
    clearscreen();

    cout << "\t\tSelamat Datang di Aplikasi Navigasi PergiMakanan" << endl;
    cout << "\t\t==============================================" << endl;


    int startingnodesx, startingnodesy;

    cout << "Silahkan masukkan koordinat awal anda : ";
    cin >> startingnodesx >> startingnodesy;
cin.ignore(999999,'\n');
    cout << "Masukkan jumlah alamat paket yang akan anda kirimkan : ";
    int n;
    cin >> n;
cin.ignore(999999,'\n');
    nodes.push_back(Node("Kurir", startingnodesx, startingnodesy));

    inputKoordinat(n);
    
    vector<bool> visited(nodes.size(), false);
    visited[0] = true;
    int current = 0;
    int totaldistance = 0;

    
    
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
    totaldistance += abs(nodes[0].x - nodes[nodes.size() - 1].x) + abs(nodes[0].y - nodes[nodes.size() - 1].y);
    cout << "Jarak total yang harus ditempuh : " << totaldistance << endl;
     
    
    

    
    cout << "Rute yang harus ditempuh : " << endl;
    cout << "Titik keberangkatan" << " (" << nodes[0].x << ", " << nodes[0].y << ")" << endl;
    output(path.size()-1);

    return 0;
}
