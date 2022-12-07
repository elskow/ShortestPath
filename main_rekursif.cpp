// Tugas UAS Pemrogaman Dasar
// Jurusan Teknik Informatika Universitas Negeri Surabaya

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

struct Node
{
    string id;
    int x, y;

    Node(string id, int x, int y) : id(id), x(x), y(y) {}
};
vector<Node> nodes;
vector<int> path;

void clearscreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void header()
{
    cout << "\t\tSelamat Datang di Aplikasi Navigasi PergiMakanan" << endl;
    cout << "\t\t==============================================" << endl;
}
void output(int n){
    if(n == -1){cout << "Kembali ke " << "(" << nodes[0].x << ", " << nodes[0].y << ")" << endl;
    }
    else 
    {cout << "Paket Untuk " << nodes[path[n]].id << " dengan koordinat (" << nodes[path[n]].x << ", " << nodes[path[n]].y << ")" << endl;
    output(n-1);
    }
    
}
void inputKoordinat(int n)
{
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cout << "\nMasukkan Nama penerima paket ke -" << i + 1 << " : ";
        string temp;
        getline(cin, temp);

        cout << "Masukkan koordinat penerima paket ke-" << i + 1 << " : ";
        cin >> x >> y;
        cin.ignore(999999, '\n');
        nodes.push_back(Node(temp, x, y));
    }
}

float CalculateDistance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

void dijkstra(vector<bool> &visited, vector<Node> &nodes, int current, float &totaldistance);

int main()
{
    clearscreen();
    header();

    int startingnodesx, startingnodesy;

    cout << "\nSilahkan masukkan koordinat awal anda : ";
    cin >> startingnodesx >> startingnodesy;

    cin.ignore(999999, '\n');
    cout << "Masukkan jumlah alamat paket yang akan anda kirimkan : ";
    int n;
    cin >> n;

    cin.ignore(999999, '\n');
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
    output(path.size()-1);
    
    if ((int(ceil(totaldistance)) % int(floor(totaldistance))) == 0)
    {
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

            float distance = CalculateDistance(nodes[current].x, nodes[current].y, nodes[i].x, nodes[i].y);
            if (distance < mindistance)
            {
                mindistance = distance;
                next = i;
            }
        }
        if (next == -1)
            break;

        totaldistance += mindistance;

        path.push_back(next);
        visited[next] = true;
        current = next;
    }

    totaldistance += CalculateDistance(nodes[current].x, nodes[current].y, nodes[0].x, nodes[0].y);
}
