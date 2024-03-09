#include<iostream>
using namespace std;
int sortuj(int tab[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(tab[j]<tab[j+1])
                 swap(tab[j], tab[j+1]);
        }
    }
}
int main()
{
    int kwota;
    cin>>kwota;
    int kwotaA=kwota;
    int n;
    cin>>n;
    int tab[n];
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }
    int ile;
    sortuj(tab,n);

    for(int i=0;i<n;i++)
    {
        while(kwotaA>=tab[i])
        {
            ile++;
            kwotaA=kwotaA-tab[i];
        }
    }
    bool czymozna=true;
    if(kwotaA!=0) czymozna=false;
    if(czymozna==false)
    {
        cout<<"NIE";
    }
    else
    {
        cout<<ile;
    }
    if(czymozna==true)
    {


    cout<<endl;
    for(int i=0;i<n;i++)
    {
        while(kwota>=tab[i])
        {
            cout<<tab[i]<<" ";
            kwota=kwota-tab[i];
        }
    }
    }
    return 0;
}