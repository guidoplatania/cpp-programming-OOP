#include <iostream>
#include <string>
using namespace std;


class Pianta{
    private:
        string nome;
        string famiglia;
        int anni;
        double altezza;
        bool raro;
    public:
        Pianta() : nome(""),famiglia(""),anni(0),altezza(0.0),raro(false){}

        Pianta(string nome,string famiglia,int anni, double altezza,bool raro) : nome(nome),famiglia(famiglia),anni(anni),altezza(altezza),raro(raro){}

        string getNome(){
            return nome;
        }
        int getAnni(){
            return anni;
        }
        double getAltezza(){
            return altezza;
        }
        string getRaro(){
            if(raro){
                return "SI";
            }
            else{
                return "NO";
            }
        }

        void cura(){
            anni++;
            altezza+=0.50;
        }

        void stampa(){
            cout<<nome<<""<<famiglia<<""<<anni<<""<<altezza<<""<<getRaro()<<endl;
        }

        friend ostream& operator<<(ostream& os, Pianta p){
            os <<"Nome Pianta: "<<p.nome<<endl<<"Famiglia Botanica: "<< p.famiglia<<endl<<"Età: "<< p.anni<<endl<<"Altezza: "<< p.altezza<<endl<<"Rara: "<< p.getRaro()<<endl;
            return os;
        }

        bool operator==(Pianta p){
            if(p.nome == nome && p.famiglia == famiglia){
                return true;
            }
            else{
                return false;
            }
        }
};

class Giardino{
    private:
        string nome;
        Pianta **arr;
        int nPiante; // piante totali( dimensione dell'array);
        int cont=0; // contatore per tenere traccia a che numero di painta siamo arrivati
    public:
        Giardino(string nome,int nPiante) : nome(nome),nPiante(nPiante){
            arr = new Pianta*[nPiante];
        }

        void aggiungiPianta(string nome,string famiglia,int anni, double altezza,bool raro){

            //controlliamo se ce spazio nell'array, se non ce non possiamo aggiungere piante
            if(cont == nPiante){
                return;
            }
            arr[cont] = new Pianta(nome,famiglia,anni,altezza,raro);
            cont++;
        }

        void rimuoviPianta(string nome){
            int i=0;
            for(i;i<cont;i++){
                if(arr[i]->getNome() == nome){
                    delete arr[i];
                    arr[i] = nullptr;
                    break;
                }
            }
            // se non vengono trovate piante da rimuovere, non fa niente
            if(i == cont){
                return;
            }

            cont--;

            for(int j=i;j<cont;j++){
                arr[j] = arr[j+1];
            }
        }

        void stampaGiardino(){
            for(int i=0;i<cont;i++){
                cout<<*(arr[i])<<endl;
            }
        }


      int trovaPianteRare(){
        int contatorePianterare = 0;
        for(int i=0;i<cont;i++){
            if(arr[i]->getRaro() == "SI"){
                contatorePianterare++;
            }
        }
        return contatorePianterare;

      }

      void stampaInfo(){
        cout<<"Informazioni sul giardino: "<<endl<<"Numero Piante : "<<cont<<endl<<"Numero Piante Rare: "<<trovaPianteRare()<<endl;
      }

      void curaPianta(int indice){
        if(indice < 0 || indice > cont){
            cout<<"errore, indice non valido"<<endl;
        }
        else{
            cout<<"curo la pianta...."<<endl;
            arr[indice]->cura();
        }
      }

};

class Giardiniere{
    private:
        string nomeG;
        string cognome;
        string specializzazione;
        int pianteGestite;
    public:
        Giardiniere(string nomeG,string cognome,string specializzazione,int pianteGestite) : nomeG(nomeG),cognome(cognome),specializzazione(specializzazione),pianteGestite(pianteGestite){}

        


};















int main(){


Pianta* p;
Giardino* g = new Giardino("Giardino",5);
g->aggiungiPianta("Pianta1","Crostacei",18,1.26,true);
g->aggiungiPianta("Pianta2","Savoia",33,1.22,true);
g->aggiungiPianta("Pianta3","Balotelli",8,1.89,false);

g->curaPianta(1);
g->stampaGiardino();
cout<<g->trovaPianteRare()<<endl;
g->stampaInfo();


Giardiniere* gg = new Giardiniere("Mario","Rossi","Medicinale",2);







}