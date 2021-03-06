#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

int n;

using namespace std;
//Lista Nastepnikow!!!!
vector <int>* KonstListaNastepnikow(int n, int m){
vector <int>* ListaNast=new vector <int>[n+1];
return ListaNast;
}

void WyczyscListe(vector <int>* ListaNast,int n){
for(int i=0; i<n+1; i++){
 delete(ListaNast);
}
}

void ListaDodajKrawedz(vector <int>* ListaNast, int k, int l){
 ListaNast[k].push_back(l);
}

void WyswietlListeNastepnikow(vector <int>* ListaNast, int n){
for(int i=1; i<n+1; i++){
    cout<<i<<' ';
    for(int j=0; j<ListaNast[i].size(); j++)
        cout<<ListaNast[i][j]<<' ';
    cout<<'\n';
}
cout<<'\n';
}

//Macierz Sasiedztwa!!!

void MacierzSasDodajKrawedz(short int** Macierz, int k, int l){
Macierz[k][l]=1;
Macierz[l][k]=-1;
}

void MacierzGrafDodajKrawedz(int** Macierz, int k, int l){
if(Macierz[k][0]==0){
Macierz[k][0]=l;
Macierz[k][l]=l;
}
else{
int cur=Macierz[k][0];
while(cur!=Macierz[k][cur])
cur=Macierz[k][cur];
Macierz[k][cur]=l;
Macierz[k][l]=l;
}

if(Macierz[l][n+1]==0){
Macierz[l][n+1]=k+n;
Macierz[l][k]=k+n;
}
else{
int cur=Macierz[l][n+1]-n;
while(cur+n!=Macierz[l][cur])
cur=Macierz[l][cur]-n;
Macierz[l][cur]=k+n;
Macierz[l][k]=k+n;
}
}

void WyswietlMacierzSas(short int** Macierz, int n){
for(int i=1; i<n+1; i++){
    for(int j=1; j<n+1; j++)
        cout<<Macierz[i][j]<<' ';
    cout<<'\n';
}
cout<<'\n';
}

void WyswietlMacierzGraf(int** Macierz, int n){
for(int i=0; i<n+1; i++){
    for(int j=0; j<n+2; j++)
        cout<<Macierz[i][j]<<' ';
    cout<<'\n';
}
cout<<'\n';
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> parent of de9db24... 1.4
enum Odwiedz{ODWIEDZ, PRZETWO, NIEODWIE};

Odwiedz* CzyOdwiedzone;
stack <int> DoDfsa;

bool ZerujTabCzyOdwiedzone(int n){
for(int i=0; i<n+1; i++)
    CzyOdwiedzone[i]=NIEODWIE;
}

bool DFSSortTopList(vector <int>* ListaNast, int cur){
 if(CzyOdwiedzone[cur]==ODWIEDZ){
    cout<<"Jest cykl, nie da sieposortowac topologicznie\n";
    return false;
 }
 if(CzyOdwiedzone[cur]==NIEODWIE){
     CzyOdwiedzone[cur]=ODWIEDZ;
        for(int i=0; i<ListaNast[cur].size(); i++)
        if(!DFSSortTopList(ListaNast, ListaNast[cur][i]))return false;
     CzyOdwiedzone[cur]=PRZETWO;
     DoDfsa.push(cur);
 }
 return true;
}

bool DFSSortTopMacSas(short int** Macierz, int n, int cur){
 if(CzyOdwiedzone[cur]==ODWIEDZ){
    cout<<"Jest cykl, nie da sieposortowac topologicznie\n";
    return false;
 }
 if(CzyOdwiedzone[cur]==NIEODWIE){
     CzyOdwiedzone[cur]=ODWIEDZ;
        for(int i=0; i<n+1; i++)
        if(Macierz[cur][i]==1 && !DFSSortTopMacSas(Macierz, n, i))return false;
     CzyOdwiedzone[cur]=PRZETWO;
     DoDfsa.push(cur);
 }
 return true;
}

bool DFSSortTopMacGraf(int** Macierz, int n, int cur){
 if(CzyOdwiedzone[cur]==ODWIEDZ){
    cout<<"Jest cykl, nie da sie posortowac topologicznie\n";
    return false;
 }
 if(CzyOdwiedzone[cur]==NIEODWIE){
     CzyOdwiedzone[cur]=ODWIEDZ;
        int temp=Macierz[cur][0];
        //cout<<temp<<' ';
        while(temp!=Macierz[cur][temp]){
        if(!DFSSortTopMacGraf(Macierz, n, temp))return false;
        temp=Macierz[cur][temp];
        }
        if(temp!=0)if(!DFSSortTopMacGraf(Macierz, n, temp))return false;
     CzyOdwiedzone[cur]=PRZETWO;
     DoDfsa.push(cur);
 }
 return true;
}

void UsunWezelMacSas(short int** Macierz, int ktory){
for(int i=1;i<=n;i++)
    Macierz[ktory][i]=Macierz[i][ktory]=0;
}

void DELSortTopMacSas(short int** Macierz, int n)
{
    cout<<"Sortowanie topologiczne macierzy sasiedztwa przez usuwanie wezla: ";
    bool czywykr[n+1];
    int ilewykr=0;
    for (int i=1;i<=n;i++)
        czywykr[i]=0;
    while(ilewykr!=n)
    {
        for(int i=1;i<=n;i++)
        {
            if(!czywykr[i]){
                bool temp=true;
                for(int j=1;j<=n;j++)
                    if(Macierz[i][j]==-1){
                        temp=false;
                        break;
                        }
                if(temp){
                ilewykr++;
                UsunWezelMacSas(Macierz, i);
                czywykr[i]=true;
                cout<<i<<' ';
                }
            }
        }
    }
    cout<<'\n';
}

void UsunWezelListaNast(vector <int>* ListaNast, int ktory){
ListaNast[ktory].clear();
}

void DelSortTopListaNast(vector <int>* ListaNast,int n){
cout<<"Sortowanie topologiczne listy nastepnikow przez usuwanie wezla: ";
    bool czywykr[n+1];
    int ilewykr=0;
    for (int i=1;i<=n;i++)
        czywykr[i]=0;
<<<<<<< HEAD
    while(ilewykr<n)
    {
        for(int i=1;i<=n;i++)
        {
            if(!czywykr[i]){
=======
    while(ilewykr!=n)
    {
        for(int i=1;i<=n;i++)
        {
>>>>>>> parent of de9db24... 1.4
            bool temp=1;
            for(int j=1;j<=n;j++)
            {
                if(i!=j && !czywykr[j]){
                    for(int k=0; k<ListaNast[j].size(); k++){
                        if(ListaNast[j][k]==i){
                            temp=0;
                            break;
                        }
                    }
                }
                if(temp==0)break;
            }
            if(temp){
                UsunWezelListaNast(ListaNast, i);
                cout<<i<<' ';
                czywykr[i]=true;
                ilewykr++;
            }
<<<<<<< HEAD
            }
=======
>>>>>>> parent of de9db24... 1.4
        }
    }
    cout<<'\n';
}

void UsunWezelMacGraf(int** Macierz, int ktory){
<<<<<<< HEAD

for(int i=0; i<=n+1; i++)
    Macierz[ktory][i]=0;
for(int i=1; i<n+1; i++){
    if(i!=ktory && Macierz[i][n+1]!=0 && Macierz[i][ktory]>0){
=======
for(int i=0; i<=n+1; i++)
    Macierz[ktory][i]=0;
for(int i=1; i<n+1; i++){
    if(i!=ktory && Macierz[i][n+1]!=0){
>>>>>>> parent of de9db24... 1.4
            //cout<<'\n'<<i<<' '<<Macierz[i][n+1]<<'\n';
            int przed=Macierz[i][n+1]-n, za=Macierz[i][ktory]-n;
            if(przed==ktory && za==ktory)
                Macierz[i][n+1]=0;
            else if(przed==ktory)
                Macierz[i][n+1]=za+n;
<<<<<<< HEAD
            if(przed!=ktory && za!=ktory){
            while(Macierz[i][przed]!=ktory+n || Macierz[i][przed]!=przed+n)
=======
            else{
            while(Macierz[i][przed]!=ktory)
>>>>>>> parent of de9db24... 1.4
                przed=Macierz[i][przed]-n;
            if(za==ktory)
                Macierz[i][przed]=przed+n;
            else
                Macierz[i][przed]=za+n;
            }
            Macierz[i][ktory]=0;
            }
    }
}

void DelSortTopMacGraf(int ** Macierz, int n){
    cout<<"Sortowanie topologiczne macierzy grafu przez usuwanie wezla: ";
    bool czywykr[n+1];
    int ilewykr=0;
    for (int i=1;i<=n;i++)
        czywykr[i]=0;
    while(ilewykr!=n)
    {
        for(int i=1;i<=n;i++)
        {
            if(!czywykr[i]){
                if(Macierz[i][n+1]==0){
                ilewykr++;
                UsunWezelMacGraf(Macierz, i);
                czywykr[i]=true;
                cout<<i<<' ';
                }
            }
        }
    }
    cout<<'\n';
<<<<<<< HEAD
=======
=======
void DFSSortTopList(vector <int>* ListaNast, int n){
>>>>>>> refs/remotes/origin/Maaslak-patch-1
>>>>>>> parent of de9db24... 1.4

}

int main(){
fstream plik;
plik.open("Grafy-ListaKrawedzi.txt", ios_base::in);


int m;
plik>>n>>m;

vector <int>* ListaNast;
ListaNast=KonstListaNastepnikow(n, m);
//Macierz Sasiedztwa konstruktor - glupie problemy jezykowe!!!
short int** MacierzSas=new short int*[n+1];
for(int i=1; i<n+1; i++)
    MacierzSas[i]=new short int[n+1];
for(int i=1; i<n+1; i++)
    for(int j=0; j<n+1; j++)
    MacierzSas[i][j]=0;
//Macierz Grafu konstruktor -,-
int** MacierzGrafu=new int*[n+1];
for(int i=0; i<n+1; i++)
    MacierzGrafu[i]=new int[n+2];
for(int i=0; i<n+1; i++)
    for(int j=0; j<n+2; j++)
    MacierzGrafu[i][j]=0;




int k, l;
for(int i=1; i<m+1; i++){
 plik>>k>>l;
 ListaDodajKrawedz(ListaNast, k, l);
 MacierzSasDodajKrawedz(MacierzSas, k, l);
 MacierzGrafDodajKrawedz(MacierzGrafu, k, l);
}
WyswietlListeNastepnikow(ListaNast, n);
WyswietlMacierzSas(MacierzSas, n);
WyswietlMacierzGraf(MacierzGrafu, n);

CzyOdwiedzone=new Odwiedz[n+1];
ZerujTabCzyOdwiedzone(n);
for(int i=1; i<n+1; i++)
    if(CzyOdwiedzone[i]==NIEODWIE)
        if(!DFSSortTopList(ListaNast, i))break;
cout<<"Sortowanie topologiczne listy nastepnikow DFS: ";
while(!DoDfsa.empty()){
    cout<<DoDfsa.top()<<' ';
    DoDfsa.pop();
}
cout<<'\n';
<<<<<<< HEAD

=======
getchar();
>>>>>>> parent of de9db24... 1.4

ZerujTabCzyOdwiedzone(n);
for(int i=1; i<n+1; i++)
    if(CzyOdwiedzone[i]==NIEODWIE)
        if(!DFSSortTopMacSas(MacierzSas, n, i))break;
cout<<"Sortowanie topologiczne macierzy sasiedztwa DFS: ";
while(!DoDfsa.empty()){
    cout<<DoDfsa.top()<<' ';
    DoDfsa.pop();
}
cout<<'\n';
<<<<<<< HEAD

=======
getchar();
>>>>>>> parent of de9db24... 1.4

ZerujTabCzyOdwiedzone(n);
for(int i=1; i<n+1; i++)
    if(CzyOdwiedzone[i]==NIEODWIE)
        if(!DFSSortTopMacGraf(MacierzGrafu, n, i))break;
cout<<"Sortowanie topologiczne macierzy grafu DFS: ";
while(!DoDfsa.empty()){
    cout<<DoDfsa.top()<<' ';
    DoDfsa.pop();
}
cout<<'\n';
<<<<<<< HEAD
DELSortTopMacSas(MacierzSas, n);
DelSortTopListaNast(ListaNast, n);

DelSortTopMacGraf(MacierzGrafu, n);

=======
getchar();
DELSortTopMacSas(MacierzSas, n);
getchar();
//DelSortTopListaNast(ListaNast, n);
//getchar();
DelSortTopMacGraf(MacierzGrafu, n);
getchar();
>>>>>>> parent of de9db24... 1.4

delete (CzyOdwiedzone);
WyczyscListe(ListaNast, n);
//Czyszczenie Macierzy sasiedztwa
for(int i=1; i<n+1; i++)
    delete(MacierzSas[i]);
delete MacierzSas;
//Czyszczenie Macierzy grafu
for(int i=0; i<n+1; i++)
    delete(MacierzGrafu[i]);
delete MacierzGrafu;
plik.close();
return 0;
}
