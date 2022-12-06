//Tugas UAS Pemrogaman Dasar
//Jurusan Teknik Informatika Universitas Negeri Surabaya



#include <bits/stdc++.h>
#include <math.h>

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

void header(){
    cout << "\t\tSelamat Datang di Aplikasi Navigasi PergiMakanan" << endl;
    cout << "\t\t==============================================" << endl;
}

void inputKoordinat(int n){
    int x , y;
    for(int i = 0 ; i < n ; i++){
        cout << "\nMasukkan Nama penerima paket ke -" <<i +1 << " : ";
        string temp;
        getline(cin, temp);

        cout << "Masukkan koordinat penerima paket ke-" << i + 1 << " : ";
        cin >> x >> y;
        cin.ignore(999999,'\n');
        nodes.push_back(Node(temp , x , y));
    }
}

void dijkstra(vector<bool> &visited, vector<Node> &nodes, int current, float &totaldistance);


int main() {
    clearscreen();
    header();
    
    int startingnodesx, startingnodesy;

    cout << "\nSilahkan masukkan koordinat awal anda : ";
    cin >> startingnodesx >> startingnodesy;

    cin.ignore(999999,'\n');
    cout << "Masukkan jumlah alamat paket yang akan anda kirimkan : ";
    int n;
    cin >> n;

    cin.ignore(999999,'\n');
    nodes.push_back(Node("Kurir", startingnodesx, startingnodesy));

    clearscreen();
    header();
    inputKoordinat(n);
    
    vector<bool> visited(nodes.size(), false);
    visited[0] = true;
    float totaldistance = 0;
    int current = 0;
   
    clearscreen();
    header();

    dijkstra(visited, nodes, current, totaldistance);

    cout << "Rute yang harus ditempuh : " << endl;

    for (int i = 0; i < path.size(); i++) {
        if (i == 0) {
            cout << "Titik keberangkatan" << " (" << nodes[i].x << ", " << nodes[i].y << ")" << endl;
        }

        cout << "Paket Untuk " << nodes[path[i]].id << " dengan koordinat (" << nodes[path[i]].x << ", " << nodes[path[i]].y << ")" << endl;
    }
    cout << "Kembali ke " << "(" << nodes[0].x << ", " << nodes[0].y << ")" << endl;

    if ((int(ceil(totaldistance)) % int(floor(totaldistance))) == 0){
        cout << "Jarak total yang harus ditempuh : " << int(totaldistance) << endl;
        return 0;
    } 

    cout << "Jarak total yang harus ditempuh : " << fixed << setprecision(2) << totaldistance << endl;

    return 0;
}

void dijkstra(vector<bool> &visited, vector<Node> &nodes, int current, float &totaldistance)
{
    while (true)
    {
        int next = -1;
        float mindistance = INT_MAX;

        // Find the nearest node
        for (int i = 0; i < nodes.size(); i++)
        {
            if (visited[i])
                continue;

            float distance = sqrt((abs(nodes[current].x - nodes[i].x))^2 + (abs(nodes[current].y - nodes[i].y))^2);
            if (distance < mindistance)
            {
                mindistance = distance;
                next = i;
            }
        }
        if (next == -1)
            break;
        
        // cout << "mindistance : " << mindistance << endl;
        totaldistance += mindistance;

        path.push_back(next);
        visited[next] = true;
        current = next;
        // totaldistance += abs(nodes[current].x - nodes[nodes.size() - 1].x) + abs(nodes[current].y - nodes[nodes.size() - 1].y);
        // cout << "totaldistance : " << totaldistance << endl;
    }

    totaldistance += sqrt((abs(nodes[0].x - nodes[current].x))^2 + (abs(nodes[0].y - nodes[current].y))^2);
    // cout << "totaldistance : " << totaldistance << endl;
}