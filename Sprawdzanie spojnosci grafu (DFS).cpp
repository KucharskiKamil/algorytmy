#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100];
char kolor[100];
void dfsvisit(int n)
{
    kolor[n] = 'c';
    int aktualny;
    for(int i=0; i < v[n].size() ;i++)
    {
        aktualny = v[n][i];
        if(kolor[aktualny] == 'b')
        {
            dfsvisit(aktualny);
        }
    }
}
int dfs(int n)
{
    int ile = 0;
    for(int i = 0; i <= n ;i++)
    {
        kolor[i] = 'b';
    }
    for(int i = 0; i < n ;i++)
    {
        if(kolor[i]== 'b')
        {
            dfsvisit(i);
            ile++;
        }
    }
    return ile;
}
int main()
{
    int a,b,n,m;
    cin >> n;
    cin >> m;
    for(int i = 0 ; i < m ;i++)
    {
        cin >> a;
        cin >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int temp = dfs(n);
    if (temp > 1)
    {
        cout << "graf niespojny" << endl;
    }
    else
    {
        cout << "graf spojny" << endl;
    }
    
    return 0;
}