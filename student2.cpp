#include <fstream>
#include <iostream>
#include <vector>
#include "common\Catalog.cpp"
#include "common\Program.cpp"
using namespace std;
vector<Catalog_oferte> oferte;
Program P;
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
    cout << "\t\t\t\tOferte curente: \n";
    int countx=1;
    for (auto& oferte: oferte) {
     cout<<"\t\t\t   "<<'['<<countx++<<']'<<" Nume: "<<oferte.getNume_oferta()<<"     Pret: "<<oferte.getPret()<<"     Durata: "<<oferte.getDurata()<<"\n\n";
    }
}
void logo(){

cout<<"\t   .-.             .-.            .--.         .-.  .-.    .---.        .-.            ";cout<<endl;
cout<<"\t   : :             : :.-.        : .-'         : :  : :    : .--'       : :            ";cout<<endl;
cout<<"\t _ : : .--.   .--. : `'.'   .--. : `;    .--.  : :  : :    : `;.--.   .-' : .--.  .--. ";cout<<endl;
cout<<"\t: :; :' .; ; '  ..': . `.  ' .; :: :    ' .; ; : :_ : :_   : :' .; ; ' .; :' '_.'`._-.'";cout<<endl;
cout<<"\t`.__.'`.__,_;`.__.':_;:_;  `.__.':_;    `.__,_;`.__;`.__;  :_;`.__,_;`.__.'`.__.'`.__.'";cout<<endl;



}
void logo_catalog(){
cout<<"\t .--.        .-.       .-.              ";cout<<endl;
cout<<"\t: .--'      .' `.      : :              ";cout<<endl;
cout<<"\t: :    .--. `. .'.--.  : :   .--.  .--. ";cout<<endl;
cout<<"\t: :__ ' .; ; : :' .; ; : :_ ' .; :' .; :";cout<<endl;
cout<<"\t`.__.'`.__,_;:_;`.__,_;`.__;`.__.'`._. ;";cout<<endl;
cout<<"\t                                   .-. :";cout<<endl;
cout<<"\t                                  `._.' ";cout<<endl;
cout<<"\t****************************************";cout<<endl;


}
void programare(int n){

}
void creare_program(){
    string cuv;
    vector<Zi>Prog;
    for(int i=0;i<5;i++){
        vector<vector<string>> interval;
        if(i==0){cuv="Luni";}
        else if(i==1){cuv="Marti";}
            else if(i==2){cuv="Miercuri";}
                else if(i==3){cuv="Joi";}
                    else{cuv="Vineri";}

        for (int i=0; i<11; i++){
            vector<string>aux;
            for(int j=0; j<4; j++){
                aux.push_back("neocupat");
            }
            interval.push_back(aux);
        }
        /*for (int i=0; i<11; i++){
            vector<string>aux;
            for(int j=0; j<4; j++){
                cout<<interval[i][j]<<" ";
            }
            cout<<endl;
        }*/
        Zi x=Zi(cuv, 10, 21, interval);
        Prog.push_back(x);
    }
        P=Program(Prog);
}
void clear_program(){
    std::ofstream ofs;
    ofs.open("teste.in", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
void scriere_program(){
clear_program();
ofstream fout("teste.in", ios_base::app);
fout <<"---------------";
fout<<P;
}
int main() {
    creare_program();
   string rasp;
    int choice = 0;
    citire_oferte();
   while ( choice != -1) {
    logo();
    cout<<"\t    ********************************************************************************\n\n\n\n";
    cout<<"\t\t\t\t   [1] Vizualizeaza catalogul cu oferte\n\t\t\t\t   [2] Programeaza o sedinta \n\t\t\t\t   [3] Vezi istoricul\n\t\t\t\t   [4] Exit\n\n\n";
        while (choice < 1 || choice > 4) {
            cout<<"\n\nIntrodu optiunea dorita: ";
            cin>>choice;
            cin.ignore();
        }
        if (choice == 1) {
            system("cls");
            rasp="da";
            while(rasp=="da"){
                logo_catalog();
                afisare_oferte();
                cout<<"\n\t\t\t\tDoresti sa mergi la meniul principal?\n";
                cin>>rasp;
                cin.ignore();
                if(rasp=="da"){
                    choice=5;
                    rasp="nu";
                    system("cls");
                }
            }
        }
        if (choice == 2) {
            system("cls");
            rasp="da";
            while(rasp=="da"){
                logo_catalog();
                afisare_oferte();
                cout<<"\n\t\t\t\tDoresti sa te programezi?\n";
                cin>>rasp;
                cin.ignore();
                if(rasp=="da"){
                 cout<<"\n\t\t\t\tIntrodu oferta aleasa: \n";
                 int ofe;
                 cin>>ofe;
                 programare(ofe);
                }
                cout<<"\n\t\t\t\tDoresti sa mergi la meniul principal?\n";
                cin>>rasp;
                cin.ignore();
                if(rasp=="da"){
                    choice=5;
                    rasp="nu";
                    system("cls");
                }
            }
        }
        system("cls");
         if(choice==4){
            break;
        }
   }
    scriere_program();
    return 0;
}
