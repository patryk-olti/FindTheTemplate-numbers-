#include <iostream>
#include <cstdlib>

using namespace std;

int potega(int wartosc, int waga)
{
    int tmp = 1;
    for(int i=0; i<waga; i++){
        tmp = tmp * wartosc;}

    return tmp;
}

void znajdz(int A, int B)
{
    unsigned long int permA = A;
    unsigned long int permB = B;

    if(A > B){
        cout<<"Brak wzorca";
        exit(0);   }

    int rozmiarA = 1, rozmiarB = 1;
    int tmp;

    while(A/10){
        rozmiarA++;
        A = A/10;    }

    while(B/10){
        rozmiarB++;
        B = B/10;    }

    int tabA[rozmiarA];
    int tabB[rozmiarB];
    A = permA;
    B = permB;
    cout<<"rozmiar liczby "<<A<<" : "<<rozmiarA<<endl;
    cout<<"rozmiar liczby "<<B<<" : "<<rozmiarB<<endl;

    int x=0;

    for(int i=1; i<=rozmiarA; i++){
        x = potega(10,rozmiarA-i);
        tmp = A / x;
        A = A - (tmp*x);
        tabA[i-1] = tmp;
    }

    for(int i=1; i<=rozmiarB; i++){
        x = potega(10,rozmiarB-i);
        tmp = B / x;
        B = B - (tmp*x);
        tabB[i-1] = tmp;
    }

    cout<<"A: ";
    for(int i=0; i<rozmiarA; i++){
        cout<<tabA[i];
    }
    cout<<endl<<"B: ";
    for(int i=0; i<rozmiarB; i++){
        cout<<tabB[i];
    }

    // POSZUKIWANIA WZORCA
    int pozycja = 0;
    x = 0;
    for(int i=0; i<rozmiarB; i++)
    {
        if(tabB[i] == tabA[x]){
            pozycja = i-x;
            x++;
        }
        else{
            x = 0;
        }

        if(x == rozmiarA){
            cout<<endl<<"Znaleziono wzorzec! Jest on na pozycji: "<<pozycja;
            x = 0;
        }
    }
    cout<<endl;
}



int main()
{
    int A, B;

    cout<<"Podaj wartosc A: ";
    cin>>A;

    if(A >= 2147483647){
        cout<<"Wartosc A jest za duza. Nowa wartosc A to 29.";
        A = 29;
    }


    cout<<"Podaj wartosc B: ";
    cin>>B;

    if(B >= 2147483647){
        cout<<"Wartosc B jest za duza. Nowa wartosc A to 961129.";
        A = 961129;
    }


    znajdz(A,B);

    return 0;
}




