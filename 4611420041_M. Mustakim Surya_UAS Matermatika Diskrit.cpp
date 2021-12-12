#include <iostream>
using namespace std;
#define INF 9999

int main()
{
    int i, j, source, target, start, minimum, m, update, ver, min_distance;
    cout << "Aplikasi Penerapan Algoritma Dijkstra\n\n";
    cout << "Masukkan banyaknya simpul : ";
	cin >> ver; ver++;
	cout << "\n";
	
    int distance[ver][ver], buff[ver], path[ver], prev[ver], visited[ver]={0};
    cout << "Masukkan jarak dari simpul yang ada\n";
	cout << "(masukkan 9999 jika simpul tidak bersisian)\n\n";
    for(i = 1; i < ver; i++)
	{
        buff[i] = INF;
        prev[i] = -1;
        path[i] = 0;
        for(int j = 1;j < ver; j++)
		{
            distance[i][j] = INF;
        }
    }
    for(i = 1;i < ver; i++)
	{
        for(j = i+1; j < ver; j++)
        {
            cout << "Masukkan jarak simpul ke-" << i << " menuju simpul ke-" << j << " : ";
			cin >> distance[i][j];
            distance [j][i] = distance[i][j];
        }
		cout << "\n";
    }

    cout << "Simpul awalnya ialah simpul ke-";
	cin >> source;
    cout << "Simpul akhirnya ialah simpul ke-";
	cin >> target;
    
    start = source;
    visited[start]=1;
    buff[start] = 0;

    while(visited[target] == 0)
	{
        minimum = INF;
        m = 0;
        for(i=1;i< ver;i++)
		{
            update = buff[start] + distance[start][i];

            if(update < buff[i] && visited[i]==0)
			{
                buff[i] = update;
                prev[i] = start;
            }
            if(minimum > buff[i] && visited[i]==0)
			{
                minimum = buff[i];
                m = i;
            }
        } 
        start = m;
        visited[start] = 1;
    }

    min_distance = buff[target];
    start = target;
    j = 0;

    while(start != -1)
	{
        path[j] = start;
        start = prev[start];
        j++;
    }

    cout << "\nJarak terkecil yang dilalui ialah sebesar : " << min_distance << "\n";
    cout << "Jalur yang ditempuh ialah : ";
    for (int i = ver-1; i >= 0; i--) {
        if (path[i] != 0) {
            cout << "\nSimpul ke-" << path[i];
        }
    }
	cout << "\n";
}
