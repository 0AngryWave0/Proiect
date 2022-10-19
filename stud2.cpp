#include <fstream>
#include <iostream>
#include <vector>
#include "common/Catalog.cpp"
using namespace std;
vector<Catalog_oferte> oferte;

void citire_oferte() {

    ifstream fin;
    fin.open("common/frizerie.txt.save-failed", ios_base::app);
    while(!fin.eof()){
        string s;
        getline(fin,s);
        if(s=="---------------"){
            string Nume_oferta;getline(fin, Nume_oferta);
            string Pret;getline(fin, Pret);
            double Durata; fin >> Durata;
            oferte.push_back(Catalog_oferte(Nume_oferta, Pret , Durata));
        }

    }
    fin.close();
}

void afisare_oferte() {
    cout << "Oferte curente: \n";
    for (auto& oferte: oferte) {
        cout<<oferte;
    }
}
void logo(){

cout<<"\t   .-.             .-.            .--.         .-.  .-.    .---.        .-.            ";cout<<endl;
cout<<"\t   : :             : :.-.        : .-'         : :  : :    : .--'       : :            ";cout<<endl;
cout<<"\t _ : : .--.   .--. : `'.'   .--. : `;    .--.  : :  : :    : `;.--.   .-' : .--.  .--. ";cout<<endl;
cout<<"\t: :; :' .; ; '  ..': . `.  ' .; :: :    ' .; ; : :_ : :_   : :' .; ; ' .; :' '_.'`._-.'";cout<<endl;
cout<<"\t`.__.'`.__,_;`.__.':_;:_;  `.__.':_;    `.__,_;`.__;`.__;  :_;`.__,_;`.__.'`.__.'`.__.'";cout<<endl;



}
int main() {
    citire_oferte();
    afisare_oferte();
    string rasp;
    int choice = 0;
   /*while ( choice != -1) {
        printf("\n");
    printf("\t    *************************************MENIU CREARE CONT*************************************\n\n\n\n");


    printf("\t\t\t\t\t   [1] Am cont\n\t\t\t\t\t   [2] Nu am cont\n\t\t\t\t\t   [3] Am uitat parola\n\t\t\t\t\t   [4] Am uitat numele de utilizator\n\n\n");

        while (choice < 1 || choice > 4) {
            cout<<"\n\nIntrodu optiunea dorita: ";
            cin>>choice;
            cin.ignore();
        }
        if (choice == 1) {
            choice=7;
        }
   }*/
   //logo();
    return 0;
}

