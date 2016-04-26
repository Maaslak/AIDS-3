#include <iostream>
#include <fstream>

int n=11;

using namespace std;

int main(){
fstream plik;
plik.open("Grafy-ListaKrawedzi.txt", ios_base::out);
plik<<n<<' '<<(n*(n-1))/2<<'\n';
for(int i=1; i<n; i++)
    for(int j=i+1; j<=n; j++)
        plik<<i<<' '<<j<<'\n';
plik.close();
return 0;
}
