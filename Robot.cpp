#include<iostream>
using namespace std;
int przemiesc(char A, int r)
{
    if((A=='N')||(A=='E'))
        return r;
    if((A=='S')||(A=='W'))
        return ((-1)*r);

    return 0;
}
int main()
{
    int x,y;
    int ile;
    char A;
    int r;
    cin>>y;
    cin>>x;
    cin>>ile;
    for(int i=0;i<ile;i++)
    {
        cin>>A;
        cin>>r;
        if((A=='N')||(A=='S'))
        {
            x=x+przemiesc(A,r);
        }
        if((A=='W')||(A=='E'))
        {
            y=y+przemiesc(A,r);
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
