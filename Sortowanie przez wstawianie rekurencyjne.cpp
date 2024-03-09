#include <iostream>
using namespace std;
void dzialaj(int tab[], int n)
{
    if (n <= 1)
        return;
    dzialaj(tab,n-1);
    int last=tab[n-1];
    int j=n-2;
    while(j>=0&&tab[j]>last)
    {
        tab[j+1]=tab[j];
        j--;
    }
    tab[j+1]=last;
}
int main()
{
    int n;
    cin>>n;
    int tab[n];
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }
    dzialaj(tab, n);
    for(int i=0;i<n;i++)
    {
        if(i<n-1)
        {
            cout<<tab[i]<<","<<" ";
        }
        else
        {
            cout<<tab[i];
        }
    }
    return 0;
}