#include<iostream>
using namespace std;
int **szachownica;
int N,M,X;
int licznik=0;
bool czyDobreMiejsce(int IO,int JO)
{
    int i,j;

    for(i=0; i<IO; i++)
    {
        if(szachownica[i][JO] == 1) return false;
    }
    for(i=0; i<JO; i++)
    {
        if(szachownica[IO][i] == 1) return false;
    }

    for (i=IO, j=JO; i>=0 && j>=0; i--, j--)
    {
        if (szachownica[i][j]==1)
        {
            return false;
        }
    }

    for (i=IO, j=JO; i<N && j<M; i++, j++)
    {
        if (szachownica[i][j]==1)
        {
            return false;
        }
    }

    for (i=IO, j=JO; i>=0 && j<M; i--, j++)
    {
        if (szachownica[i][j]==1)
        {
            return false;
        }
    }
    for (i=IO, j=JO; i<N && j>=0; i++, j--)
    {
        if (szachownica[i][j]==1)
        {
            return false;
        }
    }
    return true;
}
void wypisz()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout<<szachownica[i][j]<<" ";

        }
        cout<<endl;
    }
}
int dzialanie(int IO,int JO, int liczbaDam)
{
    if(liczbaDam==0) return 1;
    if(IO==N) return 0;
    if(JO==M) return dzialanie(IO+1,0,liczbaDam);
    int licznik = 0;
    if(czyDobreMiejsce(IO,JO))
    {
        szachownica[IO][JO]=1;
        licznik += dzialanie(IO, JO+1, liczbaDam-1);
        szachownica[IO][JO]=0;
    }
    licznik += dzialanie(IO, JO+1, liczbaDam);
    return licznik;
}
int main()
{

    cin>>N;
    cin>>M;
    cin>>X;
    szachownica=new int*[N];
    for(int i=0; i<N; i++)
    {
        szachownica[i]=new int[M];
        for(int j=0; j<M; j++)
        {
            szachownica[i][j]=0;
        }
    }
    int licznik = dzialanie(0,0,X);
    cout<<licznik;
    return 0;
}
