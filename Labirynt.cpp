#include <iostream>
using namespace std;
const int N = 60;
int maze[N][N];
int n, m;
int sx, sy;
int ex, ey;

//funkcja sprawdzajaca czy nasze miejsce jest w labiryncie oraz czy nie jest sciana czyli 1
bool isValid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != 1;
}

// dfs aby znalezc najkrotsza droge z (x,y) do (ex,ey)
int dfs(int x, int y) {
  if (x == ex && y == ey) return 0;
  // oznacz miejsce jako odwiedzone
  maze[x][y] = 1;
  //wszystkie z czterech mozliwosci poruszania sie
  int min_steps = N;
  static const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (isValid(nx, ny)) {
      min_steps = min(min_steps, dfs(nx, ny) + 1);
    }
  }
  maze[x][y] = 0;
  return min_steps;
}
int main() {

    //Zakladam, ze sciana to 1 a kazda inna liczba oznacza przejscie
    string c;
    cin>>n>>m;
    for(int i=0;i<60;i++)
    {
        for(int j=0;j<60;j++)
        {
            maze[i][j]=1;
        }
    }
    getline(cin,c);
    for(int i=0;i<n;i++)
    {
        getline(cin,c);
        for(int j=0;j<m;j++)
        {
            if(c[j]==' ') maze[i][j]=2;
            if(c[j]=='#') maze[i][j]=1;
            if(c[j]=='A')
            {
                maze[i][j]=2;
                sx=i;
                sy=j;
            }
            if(c[j]=='B')
            {
                maze[i][j]=2;
                ex=i;
                ey=j;
            };
        }
    }

  int steps = dfs(sx, sy);
  if (steps == N) {
    cout<<"-1"<<endl;
  } else {
    cout<<steps<<endl;
  }
  return 0;
}
