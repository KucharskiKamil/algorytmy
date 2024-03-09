#include<iostream>
using namespace std;
void dzialaj(int *tab, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1;
   nr = r-m;
   int lewy[nl], prawy[nr];
   for(i=0;i<nl;i++)
      lewy[i]=tab[l+i];
   for(j=0;j<nr;j++)
      prawy[j]=tab[m+1+j];
   i=0;
   j=0;
   k=l;
   while(i<nl&&j<nr)
   {
      if(lewy[i]<=prawy[j])
      {
         tab[k]=lewy[i];
         i++;
      }
      else
      {
         tab[k]=prawy[j];
         j++;
      }
      k++;
   }
   while(i<nl)
   {
      tab[k]=lewy[i];
      i++;
      k++;
   }
   while(j<nr)
   {
      tab[k]=prawy[j];
      j++;
      k++;
   }
}
void funkcja(int *tab, int l, int r) {
   int m;
   if(l < r)
   {
      int m = l+(r-l)/2;
      funkcja(tab, l, m);
      funkcja(tab, m+1, r);
      dzialaj(tab, l, m, r);
   }
}
int main() {
   int n;
   cin >> n;
   int tab[n];
   for(int i = 0; i<n; i++) {
      cin >> tab[i];
   }
   funkcja(tab, 0, n-1);
   for(int i=0;i<n;i++)
   {
       if(i<n-1)
       {
           cout<<tab[i]<<", ";
       }
       else
       {
           cout<<tab[i];
       }
   }
}