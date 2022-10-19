#include <fstream>
#include <iostream>
#include "common\Catalog.cpp"
#include "common\Program.cpp"
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#define GREEN 2
#define WHITE 15
using namespace std;
vector<Catalog_oferte> oferte;
vector<Catalog_oferte> oferte_actuale;
Program P;
void set_color(int color_code) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color_code);
}
void adaugare_oferta( ) {

    cout << "Nume oferta: ";
    string Nume_oferta;getline(cin, Nume_oferta);
    string Pret;cout<<"\nPret: ";getline(cin, Pret);
    cout << "\nDurata: ";
    double Durata; cin >> Durata;
    Catalog_oferte x=Catalog_oferte(Nume_oferta,Pret,Durata);
    oferte_actuale.push_back(x);
}
void scriere_catalog(vector<Catalog_oferte>scriere){
ofstream fout;
    fout.open("common/frizerie.txt.save-failed", ios_base::app);
     //for (auto& oferte: oferte)
            //fout<<"---------------"<<oferte;
    //fout <<"---------------\n"<< x.getNume_oferta() << '\n'<< x.getPret() << '\n' << x.getDurata() << '\n';

    for (auto& scriere: scriere) {
        fout <<"---------------\n";
        fout << scriere.getNume_oferta() << '\n';
        fout <<scriere.getPret() << '\n';
        fout <<scriere.getDurata() << "\n";
    }
    fout.close();
}
void clear_catalog(){
    std::ofstream ofs;
    ofs.open("common/frizerie.txt.save-failed", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
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
            oferte_actuale.push_back(Catalog_oferte(Nume_oferta, Pret , Durata));
        }

    }
    fin.close();
}
void modificare_oferte(int n){
    system("cls");
    cout<<("[==  MODIFICA OFERTE  ==]\n\n");
    cout<<"Ce dorest sa modifici?\n";
    cout<<oferte_actuale[n];
    cout<<"1. Nume     2. Pret     3. Durata\n";
    int rasp;
    cout<<"Selecteaza optiunea: ";
    cin>>rasp;
    cout<<'\n';
    cin.ignore();
    if(rasp==1){
        cout<<"\nNoul nume: ";
        string nume;
        getline(cin,nume);
        oferte_actuale[n].setNume_oferta(nume);
    }
    else if(rasp==2){
        cout<<"\nNoul pret: ";
        string pret;
        getline(cin,pret);
        oferte_actuale[n].setPret(pret);
    }
    else{
        cout<<"\nNoua durata: ";
        int durata;
        cin>>durata;
        oferte_actuale[n].setDurata(durata);
    }
    cout<<"\nDoresti sa mai modifici oferta?\n";
    string ok;
    cin>>ok;
    if(ok=="da"){
    modificare_oferte(n);
    }

}
void sterge_oferte(int n){
    system("cls");
    cout<<("[==  STERGE OFERTE  ==]\n\n");
    cout<<oferte_actuale[n];
    cout<<"\nSigur doresti sa stergi oferta?\n";
    string rasp;
    cin>>rasp;
    if(rasp=="da"){
       oferte_actuale.erase(oferte_actuale.begin()+n);
        cout<<"\nOferta a fost stearsa cu succes\n";
    }
}
void afisare_oferte() {
    cout << "\nOferte curente: \n";
    int countx=1;
    for (auto& oferte_actuale: oferte_actuale) {
        cout<<'\n'<<'*'<<countx++<<oferte_actuale;
    }
}
void vizualizeaza_dis(){
    cout<<"\nAlege o zi pentru a vedea programul:\n";
    string ziua;
    cin>>ziua;
    ifstream fin;
    fin.open("teste.in", ios_base::app);
    vector<Zi>Prog;
    string in,sf;
     while(!fin.eof()){
        string s;
        getline(fin,s);
        if(s==ziua){

            getline(fin,in);getline(fin,sf);
            vector<vector<string>> interval;
            for(int i=0;i<11;i++){
                string str;
                getline(fin,str);
                vector<string>aux;
                for(int j=0;j<4;j++){
                    size_t found =str.find(' ');
                    size_t found1=str.find(' ',found);
                    aux.push_back(str.substr(found+1,found1+1));
                }
                interval.push_back(aux);
            }
            Zi x=Zi(ziua, 10, 21, interval);
            Prog.push_back(x);
            P=Program(Prog);
    }

    }

    cout<<P;
    fin.close();

}
int main() {

    string rasp;
    int choice = 0;
    citire_oferte();
   while ( choice != -1) {
        cout<<("[==  MENIU PRINCIPAL  ==]\n");
        cout<<("1. Adauga oferte\n");
        cout<<("2. Modifica oferte\n");
        cout<<("3. Sterge oferte\n");
        cout<<("4. Vizualizeaza ofertele curente\n");
        cout<<("5. Vizualizeaza disponibilitatea frizeriei\n");
        cout<<("6. EXIT");
        while (choice < 1 || choice > 6) {
            cout<<"\n\nIntrodu optiunea dorita: ";
            cin>>choice;
            cin.ignore();
        }
        system("cls");
        if (choice == 1) {
            cout<<("[==  ADAUGA OFERTE  ==]\n\n");
            adaugare_oferta();
            cout<<"\n*Doresti sa mai adaugi oferte?\n";
            cin>>rasp;
            cin.ignore();
            while(rasp=="da"){
                cout<<"\n";
                adaugare_oferta();
                cout<<"\n*Doresti sa mai adaugi oferte?\n";
                cin>>rasp;
                cin.ignore();
            }
            if(rasp=="nu"){
                    choice=7;
                    system("cls");
                }
        }
        if(choice==2){
            cout<<("[==  MODIFICA OFERTE  ==]\n\n");
            set_color(GREEN);
            cout<<"\n*Doresti sa modifici oferte?\n";
            set_color(WHITE);
            cin>>rasp;
            cin.ignore();
            while(rasp=="da"){
                system("cls");
                cout<<("[==  MODIFICA OFERTE  ==]\n\n");
                afisare_oferte();
                cout<<"\n";
                int m;
                cout<<"Selecteaza oferta pe care doresti sa o modifici: ";
                cin>>m;
                modificare_oferte(m-1);
                set_color(GREEN);
                cout<<"\n*Doresti sa mai modifici oferte?\n";
                set_color(WHITE);
                cin>>rasp;
                cin.ignore();
            }
            if(rasp=="nu"){
                    choice=7;
                    system("cls");
                }
        }
        if(choice==3){
            cout<<("[==  STERGE OFERTE  ==]\n\n");
            set_color(GREEN);
            cout<<"\n*Doresti sa stergi oferte?\n";
            set_color(WHITE);
            cin>>rasp;
            cin.ignore();
            while(rasp=="da"){
                system("cls");
                cout<<("[==  STERGE OFERTE  ==]\n\n");
                afisare_oferte();
                cout<<"\n";
                int m;
                cout<<"Selecteaza oferta pe care doresti sa o stergi: ";
                cin>>m;
                sterge_oferte(m-1);
                set_color(GREEN);
                cout<<"\n*Doresti sa stergi alte oferte?\n";
                set_color(WHITE);
                cin>>rasp;
                cin.ignore();
            }
            if(rasp=="nu"){
                    choice=7;
                    system("cls");
                }


        }
        if(choice==4){
            rasp="da";
            system("cls");
            while(rasp=="da"){
                cout<<("[==  VIZULIZEAZA OFERTELE ACTUALE  ==]\n\n");
                afisare_oferte();
                set_color(GREEN);
                cout<<"\nDoresti sa mergi la meniul principal?\n";
                set_color(WHITE);
                cin>>rasp;
                cin.ignore();
                if(rasp=="da"){
                    choice=7;
                    rasp="nu";
                    system("cls");
                }
            }
        }
        if(choice==5){
            rasp="da";
            system("cls");
            while(rasp=="da"){
                cout<<("[==  VIZULIZEAZA DISPONIBILITATEA FRIZERIEI ==]\n\n");
                vizualizeaza_dis();
                cout<<"\nDoresti sa mergi la meniul principal?\n";
                cin>>rasp;
                cin.ignore();
                if(rasp=="da"){
                    choice=7;
                    rasp="nu";
                    system("cls");
                }
            }
        }
        system("cls");
        if(choice==6){
            clear_catalog();
            scriere_catalog(oferte_actuale);
            break;
        }
        }

  return 0;
}

