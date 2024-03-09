#include<iostream>

#define N 8
#define M 8

using namespace std;
int rows[N];
int flag = 0;
int cols[M];
int board[N][N];
int counter;

char numToAlpha(int x)
{
    return 'A'+x;
}
void wypisz()
{
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            if(board[i][j] == 1)
            {
                cout<<numToAlpha(j);
            }
        }
    }
    cout<<endl;
}
int isValidPlace(int col,int row)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        if(board[i][col] == 1) return 0;
    }
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
      if (board[i][j]==1)
      {
          return 0;
      }

   for (i=row, j=col; i>=0 && j<M; i--, j++)
      if (board[i][j]==1)
      {
          return 0;
      }

    return 1;
}
int solveUntil(int row,string opcja)
{
    int i;
    if(row == M)
    {
        counter++;
        if(flag == 0)
        {
            if(opcja[0] == 'u')
            {
                wypisz();
            }
            flag++;
        }

        return 1;
    }
    int res = 0;
    for(i=0;i<N;i++)
    {
        if(isValidPlace(i,row))
        {
            board[row][i] =  1;

            res = solveUntil(row+1,opcja) || res;

            board[row][i] = 0;
        }
    }
    return res;
}
int main()
{
    string opcja;
    cin>>opcja;
    //wybierz "liczba" lub "u" jako ustawienie
    solveUntil(0,opcja);
    if(opcja=="liczba")
    {
        cout<<counter;
    }
    return 0;
}
