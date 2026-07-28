/*Creare una classe Squadra che rappresenta una squadra di calcio e ha come attributi il numero di partite vinte, il numero di partite perse e il numero di partite pareggiate.
Ha opportuni metodi per impostare i parametri e farli visualizzare, 
inoltre ha il metodo punti() che restituisce quanti punti ha in campionato (vittoria:3 punti,pareggiate 1 punto,sconfitte 0 punti) 
e un metodo inizioanno() che resetta il numero di partite vinte, pareggiate e perse portandole a zero.
Creare un main per provare la classe creando due istanze Juventus e Milan 
e si provino ad utilizzare facendo inserire all’utente per entrambe le squadre il numero di partite vinte, perse e pareggiate 
e poi confrontando quale delle due ha più punti in campionato. */

#include <iostream>
#include <string>

class Squadra{
    private:
        int Vinte;
        int Perse;
        int Pareggiate;

    public:
        Squadra(int Vinte,int Perse,int Pareggiate)  : Vinte(Vinte),Perse(Perse),Pareggiate(Pareggiate){}

        void setVinte(int Vinte){
            this->Vinte = Vinte;
        }
        int getVinte(){
            return Vinte;
        }


        void setPerse(int Perse){
            this->Perse = Perse;
        }
        int getPerse(){
            return Perse;
        }


        void setPareggiate(int Pareggiate){
            this->Pareggiate = Pareggiate;
        }
        int getPareggiate(){
            return Pareggiate;
        }
        //METODO PER INSERIRE I PARAMETRI
        void parametri(std::string squad){

            //std::cout<<"inserisci la squadra tra Milan e Juve "<<std::endl;
            //std::cin>>squad;

            std::cout<<"inserisci il numero di partite vinte della squadra "<<squad<<std::endl;
            std::cin>>Vinte;

            std::cout<<"inserisci il numero di partite perse della squadra "<<squad<<std::endl;
            std::cin>>Perse;

            std::cout<<"inserisci il numero di partite pareggiate della squadra "<<squad<<std::endl;
            std::cin>>Pareggiate;

        }
        //METODO PER STAMPARE
        void stampaParametri(){
            std::cout<<"Vinte: "<<Vinte <<std::endl <<"Perse: "<<Perse <<std::endl <<"Pareggiate: "<<Pareggiate<<std::endl;
        }

        //METODO PER CALCOLO PUNTI
        int punti(){
            int pt;
            int ptVinte = Vinte * 3;
            int ptPerse = Perse * 0;
            int ptPareggiate = Pareggiate * 1;

            pt = ptVinte + ptPerse + ptPareggiate;
            return pt;
            }

        //METODO PER RESET PARTITE
        void inizioAnno(){
            Vinte = 0;
            Perse = 0;
            Pareggiate = 0;
        }
};




int main(){

int vinte;
int perse;
int pareggiate;


Squadra milan(vinte,perse,pareggiate);
Squadra juve(vinte,perse,pareggiate);

milan.parametri("Milan");
juve.parametri("Juve");

milan.stampaParametri();
juve.stampaParametri();


std::cout<<"il milan ha totalizzato: "<<milan.punti() <<" punti"<<std::endl;
std::cout<<"la juve ha totalizzato: "<<juve.punti() <<" punti"<<std::endl;

if(milan.punti() > juve.punti()){
    std::cout<<"MILAN CAMPIONE"<<std::endl;
}
else{
    std::cout<<"JUVE CAMPIONE"<<std::endl;
}
std::cout<<"ANNO FINITO"<<std::endl;   
milan.inizioAnno();
juve.inizioAnno();

milan.stampaParametri();
juve.stampaParametri();

}
