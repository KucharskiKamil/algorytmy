#include<iostream>
#include<cmath>
using namespace std;
class Wektor
{
    friend Wektor operator*(double liczba, const Wektor &w);
    friend istream &operator>>(istream &in, Wektor &w);
    friend ostream &operator<<(ostream &out, const Wektor &w);
private:
    unsigned int wymiar;
    double *wspolczynniki;
public:
    Wektor()
    {
        wymiar=0;
        wspolczynniki=NULL;
    }
    Wektor(unsigned int a, double *b)
    {
        wymiar=a;
        wspolczynniki = new double[sizeof(b)];
        for(int i=0; i<sizeof(b); i++)
        {
            wspolczynniki[i]=b[i];
        }
    }
    ~Wektor()
    {
        if(wspolczynniki!=NULL)
        {
            delete[] wspolczynniki;
        }
    }
    double dlugosc()
    {
        double a=0;
        for(int i=0; i<wymiar; i++)
        {
            a=a+pow(wspolczynniki[i], 2);
        }
        return sqrt(a);
    }
    //mnozenie przez liczbe
    Wektor operator*(double a)
    {
        Wektor w1(wymiar, wspolczynniki);
        for(int i=0; i<wymiar; i++)
        {
            w1.wspolczynniki[i]=w1.wspolczynniki[i]*a;
        }
        return w1;
    }
    virtual void pisz()
    {
        cout<<*this<<endl;
    }
};
istream &operator>>(istream &wej, Wektor &w1)
{
    wej>>w1.wymiar;
    w1.wspolczynniki=new double[w1.wymiar];
    for(int i=0; i<w1.wymiar; i++)
    {
        wej>>w1.wspolczynniki[i];
    }
    return wej;
}
ostream &operator<<(ostream &wyj, const Wektor &w1)
{
    wyj<<w1.wymiar<<" ";
    for(int i=0; i<w1.wymiar; i++)
    {
        wyj<<w1.wspolczynniki[i]<<" ";
    }
    return wyj;
}
//mnozenie przez drugi wektor
Wektor operator*(double liczba, const Wektor &w1)
{
    Wektor w2(w1.wymiar, w1.wspolczynniki);
    for(int i=0; i<w1.wymiar; i++)
    {
        w2.wspolczynniki[i]=w2.wspolczynniki[i]*liczba;
    }
    return w2;
}
class Wektor2 : public Wektor
{
public:
    virtual void pisz()
    {
        cout<<"[Wersja 2]"<<" "<<*this<<endl;
    }
};
int main()
{
    double a, b;
    cin >> a >> b;

    Wektor2 w;
    cin >> w;
    cout << w.dlugosc() << endl;

    Wektor u = a*w;
    cout << u << endl;

    Wektor v = w*b;
    v.pisz();

    Wektor *pw = &w;
    pw->pisz();

    return 0;
}