#include <iostream>
#include <iomanip> //Potrzebuje tej biblioteki do uzycia setprecision przy wypisywaniu wyniku
using namespace std;

double czynnik();
double skladnik();
double wyrazenie();

double czynnik()
{
    char nastepny=cin.peek();
    double zmienna1;
    if(nastepny=='+')
    {
        cin.ignore(1);
        return czynnik();
    }
    if (nastepny=='-')
    {
        cin.ignore(1);
        return czynnik()*(-1);
    }
    if(nastepny=='(')
    {
        cin.ignore(1);
        zmienna1=wyrazenie();
        cin.ignore(1);
        return zmienna1;
    }
    if(isdigit(nastepny))
    {
        cin >> zmienna1;
        return zmienna1;
    }
    return 0;
}
double skladnik()
{
    double zmienna1=czynnik();
    double zmienna2;
    while(true)
    {
        char nastepny=cin.peek();
        if(nastepny=='*')
        {
            cin.ignore(1);
            zmienna2=czynnik();
            return (zmienna1*zmienna2);
        }
        if(nastepny=='/')
        {
            cin.ignore(1);
            zmienna2=czynnik();
            return (zmienna1/zmienna2);
        }
        else
        {
            break;
        }
    }
    return zmienna1;
}
double wyrazenie()
{
    double zmienna=skladnik();
    double zmienna2;
    while(true)
    {
        char nastepny=cin.peek();
        if(nastepny=='+')
        {
            cin.ignore(1);
            zmienna2=skladnik();
            return (zmienna+zmienna2);
        }
        if(nastepny=='-')
        {
            cin.ignore(1);
            zmienna2=skladnik();
            return (zmienna-zmienna2);
        }
        else
        {
            break;
        }
    }
    return zmienna;
}
int main()
{
    cout<<setprecision(2)<<fixed<<wyrazenie();
    return 0;
}
