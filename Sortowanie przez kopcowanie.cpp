#include <iostream>
using namespace std;
int main()
{
  int N =0;
  int elementpomocniczy=0;
  cin>>N;
  int d[N+1];
  int i,j,k,m,x;
  for(i=1;i<=N;i++)
  {
    cin>>d[i];
  }
  for(i=2;i<=N;i++)
  {
    j=i;
    k=j/2;
    x=d[i];
    while((k>0)&&(d[k]<x))
    {
      d[j]=d[k];
      j=k;
      k=j/2;
    }
    d[j]=x;
  }
  for(i=N;i>1;i--)
  {
    elementpomocniczy=d[1];
    d[1]=d[i];
    d[i]=elementpomocniczy;
    j=1;
    k=2;
    while(k<i)
    {
      if((k+1<i)&&(d[k+1]>d[k]))
        m=k+1;
      else
        m=k;
      if(d[m]<=d[j]) break;
      elementpomocniczy=d[j];
      d[j]=d[m];
      d[m]=elementpomocniczy;
      j=m;k=j+j;
    }
  }
  for(i=1;i<=N;i++) cout<<d[i]<<" ";
  return 0;
}