#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100];
vector<int> pi;
queue<int> q;
char kolor[100];

void BFSvisit(int x)
{
    kolor[x] = 's';
    q.push(x);
    while (!q.empty())
    {
        int x = q.front();
        for(int i =0 ; i<v[x].size() ; i++)
        {
            int aktualny = v[x][i];
            if(kolor[aktualny] == 'b')
            {
                kolor[aktualny] = 's';
                pi[aktualny] = x;
                q.push(aktualny);
            }
        }
        q.pop();
        kolor[x] = 'c';
    }
}
void printpath(int s, int k)
{
    if (s == k)
        cout << v;
    
    else if (pi[k] == NULL)
        cout << "nie ma drogi";
    
    else
    {
        while (k != s)
        {
            cout << k << " ";
            k = pi[k];
        }
        cout << s;
    }
}
int main()
{
    int a,b,n,m,i;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i = 0; i < n; i++)
    {
        kolor[i] = 'b';
        pi.push_back(NULL);
    }
    cin >> a;
    cin >> b;
    if(a > b)
    {
        BFSvisit(b);
        printpath(b,a);
    }
    else
    {
        BFSvisit(a);
        printpath(a,b);
    }
    cout << endl;
    
    return 0;
}