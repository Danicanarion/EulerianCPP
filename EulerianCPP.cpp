#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Eulerian.h"

using namespace std;
int main(int argc, char* argv[]) {
    auto *en = new Eulerian();
    bool flagm = false;
    bool flagt = false;

    for (int i = 0; i < argc; i++){
        string str(argv[i]);
        if(str == "-t"){
            if (flagt){
                cout << "Flag -t repetida." << endl;
                exit(1);
            } else flagt = true;
        } else if (str == "-m"){
            if(flagm){
                cout << "Flag -m repetida." << endl;
                exit(1);
            } else flagm = true;
        } else if (str.substr(0,1) == "-"){
            cout << "La flag "<<str<<"no es válida"<<endl;
            cout << "Uso: eulerian [tm] ruta" << endl;
            exit(1);
        }
    }

    !flagm ? cout<<"Se va a calcular mediante tabulation"<<endl:cout<<"Se va a calcular mediante memoization"<<endl;

    clock_t t0, t1;

    if (flagt) t0=clock();

    int n,m;
    string line;
    ifstream f (argv[argc-1]);
    if (f.is_open())
    {
        while ( getline (f,line) )
        {
            n = stoi(line.substr(0, line.find(' ')));
            m = stoi(line.substr(line.find(' ')));

            if(m >= n){
                printf("No se puede hacer la operación porque en n=%d y m=%d n < m",n,m);
                cout << endl;
            } else if (m <0){
                printf("No se puede hacer la operación con números negativos");
                cout << endl;
            } else {
                if(flagm){
                    int aux = en->eulerianmem(n,m);
                    printf("n=%d, m=%d ;Eulerian Number=%d",n,m,aux);
                    cout << endl;
                } else {
                    int aux = en->euleriantab(n,m);
                    printf("n=%d, m=%d ;Eulerian Number=%d",n,m,aux);
                    cout << endl;
                }
            }
        }
        f.close();
        t1 = clock();
    }
    if (flagt){
        double time = (double(t1 - t0)/CLOCKS_PER_SEC);
        cout<<"Ejecución terminada en "<<time<<"s"<<endl;
    }
}