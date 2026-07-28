#include <iostream>
#include <string>
using namespace std;


class OperaArte{
    private:
        int codice;
        string titolo;
        double valore;
    public:
        OperaArte() : codice(0),titolo(""),valore(0){}

        OperaArte(int codice,string titolo,double valore) : codice(codice),titolo(titolo),valore(valore){}

        void setCodice(int codice){
            this->codice = codice;
        }
        void setTitolo(string titolo){
            this->titolo = titolo;
        }
        void setValore(double valore){
            this->valore = valore;
        }

        int getCodice(){
            return codice;
        }
        string getTitolo(){
            return titolo;
        }
        double getValore(){
            return valore;
        }

        void stampa(){
            cout<<"Codice: "<<codice<<" Titolo: "<<titolo<<" Valore: "<<valore<<endl;
        }

        friend ostream& operator<<(ostream& os, OperaArte& op){
            os<<"Codice: "<<op.codice<<" Titolo: "<<op.titolo<<" Valore: "<<op.valore<<endl;
            return os;
        }
        
};

class Pittura : public OperaArte{
    private:
        string tecnica;
        string periodo;
    public:
        Pittura(int codice,string titolo,double valore,string tecnica,string periodo) : OperaArte(codice,titolo,valore),tecnica(tecnica),periodo(periodo){}

        void stampa(){
            OperaArte::stampa();
            cout<<" Tecnica usata: "<<tecnica<<" Periodo Storico: "<<periodo<<endl;
        }

};

class Scultura : public OperaArte{
    private:
        double altezza;
        string materiale;
    public:
        Scultura(int codice,string titolo,double valore,double altezza,string materiale) : OperaArte(codice,titolo,valore), altezza(altezza),materiale(materiale){}

        void stampa(){
            OperaArte::stampa();
            cout<<"Altezza: "<<altezza<<"Materiale usato: "<<materiale<<endl;
        }

};

class Artista{
    private:
        int id;
        string nome;
        OperaArte **arr;
        int nOpere;
        int cont = 0;
    public:
        Artista(int id,string nome,int nOpere) : id(id),nome(nome),nOpere(nOpere){
            arr = new OperaArte*[nOpere];
        }

        Artista() : id(0),nome(""),nOpere(0){}

        void AggiungiOpera(OperaArte* opera){
            if(cont == nOpere){
                cout<<"impossibile aggiungere un altra opera"<<endl;
                return;
            }
            

            arr[cont] = opera;
            cont++;
        }

        void stampaOpere(){
            for(int i=0;i<cont;i++){
                arr[i]->stampa();
            }
        }

        void stampaArtista(){
            cout<<"id: "<<id<<" nome: "<<nome<<" "<<" numero opere: "<<nOpere<<endl;
        }

        friend ostream& operator<<(ostream& os, Artista& a){
            os <<"id: "<< a.id <<" nome: "<<a.nome<<" "<<" numero opere: "<<a.nOpere<<endl;
            for(int i=0;i<a.cont;i++){
                os << *(a.arr[i])<<endl;
            }
            return os;
        }

        double calcolaValoreOpere(){
            double somma = 0;
            for(int i=0;i<cont;i++){
                somma+=arr[i]->getValore();
            }
            return somma;
        }

        void filtraOpere(double valoreMinimo){
            for(int i=0;i<cont;i++){
                if(arr[i]->getValore() > valoreMinimo){
                    cout<<"Questa opera "<<*(arr[i]) <<"ha un valore maggiore di "<<valoreMinimo<<endl;
                }
            }
        }
};

class Galleria{
    private:
        Artista **arrA;
        int nArtisti;
        int contA = 0;
    public:
        Galleria(int nArtisti) : nArtisti(nArtisti){
            arrA = new Artista*[nArtisti];
        }

        int getContA(){
            return contA;
        }

        bool isEmpty(){
            return contA==0;
        }

        void aggiungiArtista(Artista* artista){
            if(contA == nArtisti){
                
                cout<<"impossibile aggiungere un artista"<<endl;
                return;
            }
            
            

            arrA[contA] = artista;
            contA++;
        }

        void stampaGalleria(){
            for(int i=0;i<contA;i++){
                arrA[i]->stampaArtista();
                arrA[i]->stampaOpere();
            }
        }

        friend ostream& operator<<(ostream& os, Galleria& g){
            for(int i=0;i<g.contA;i++){
                os <<*(g.arrA[i])<<endl;
                
            }
            return os;
        }

        

        
};
        













int main(){
Artista* a1 = new Artista(123,"Paolo",3);
Artista* a2 = new Artista(578,"Marco",2);

OperaArte* o1 = new OperaArte(9242,"Opera1",12.99);
OperaArte* o2 = new OperaArte(2381,"Opera2",39.99);
OperaArte* o3 = new OperaArte(1875,"Opera3",99.99);

OperaArte* oa21 = new OperaArte(9987,"Opera4", 50.89);
OperaArte* oa22 = new OperaArte(1143,"Opera5", 18.99);

//OPERE DI ARTISTA 1
a1->AggiungiOpera(o1);
a1->AggiungiOpera(o2);
a1->AggiungiOpera(o3);

//OPERE DI ARTISTA2
a2->AggiungiOpera(oa21);
a2->AggiungiOpera(oa22);






Galleria* g = new Galleria(10);
int scelta;
int continuare;
while(scelta != 5 && continuare != 0){

cout<<"Benvenuto nella galleria d'arte, fai la tua scelta"<<endl;
cout<<"1. Aggiungi un artista"<<endl;
cout<<"2. Visualizza galleria"<<endl;
cout<<"3. Calcola il valore totale della galleria"<<endl;
cout<<"4. Filtra opere per valore minimo"<<endl;
cout<<"5. Esci"<<endl;
cin>>scelta;

switch(scelta){
    case 1:{
        cout<<"hai scelto: Aggiungi un artista"<<endl;
        
        if(g->isEmpty()){
            g->aggiungiArtista(a1);
        }
        else{
            g->aggiungiArtista(a2);
        }
        
        cout<<"Artista aggiunto con successo"<<endl;
        
        break;
    }
    case 2:{
        cout<<"hai scelto: Visualizza Galleria"<<endl;
        cout<<*g<<endl;
        break;
    }
    case 3:{
        cout<<"hai scelto: calcolo valore opere nella galleria"<<endl;
        if(g->getContA() == 1){
            cout<<"il valore totale delle opere della galleria è:"<<a1->calcolaValoreOpere()<<endl;
        }
        else{
            double totale = a1->calcolaValoreOpere() + a2->calcolaValoreOpere();
            cout<<"il valore totale delle opere della galleria è:"<<totale<<endl;
        
        }
        break;
    }
    case 4:{
        cout<<"hai scelto: Filtra opere per valore minimo"<<endl;
        if(g->getContA() == 1){
            a1->filtraOpere(40.0);
        }
        else{
            a1->filtraOpere(40.0);
            a2->filtraOpere(40.0);
        }
    }
    

    }

    
    cout<<"vuoi continuare a svolgere altre operazioni? 1 per continuare, 0 per uscire"<<endl;
    cin>>continuare;
    
    



}

}