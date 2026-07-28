#include <iostream>
#include <string>

using namespace std;


class Studente{
    private:
        string matricola;
        string nome;
        string cognome;
        float media;
    public:
        Studente(string matricola,string nome,string cognome,float media) : matricola(matricola),nome(nome),cognome(cognome),media(media){}

        Studente() : matricola(0),nome(""),cognome(""),media(0.0){}

        string getMatricola(){
            return matricola;
        }
        string getNome(){
            return nome;
        }
        string getCognome(){
            return cognome;
        }
        float getMedia(){
            return media;
        }

        void stampa(){
            cout<<matricola<<", "<<nome<<", "<<cognome<<", "<<media;
        }
};

class BorsaDiStudio{
    private:
        int importo;
        int durata;
    public:
        BorsaDiStudio(int importo,int durata) : importo(importo),durata(durata){}

        int getImporto(){
            return importo;
        }
        int getDurata(){
            return durata;
        }

};

class StudenteBorsista : public Studente{
    private:
        BorsaDiStudio* borsa;
    public:
        StudenteBorsista(string matricola,string nome,string cognome,float media,BorsaDiStudio* borsa) : Studente(matricola,nome,cognome,media),borsa(borsa){}

        int getImportoBorsa(){
            if(borsa == nullptr){
                return 0;
            }
            else{
                return borsa->getImporto();
            }
                
            
        }

        void stampa(){
            if(borsa != nullptr){
                Studente::stampa();
                cout<<", ["<<getImportoBorsa()<<"]"<<endl;
            }
            else{
                Studente::stampa();
                cout<<endl;
            }

        }
};

class Node{
    public:
        StudenteBorsista studente;
        Node* next;
    public:
        Node(StudenteBorsista studente) : studente(studente),next(nullptr){}
};

class Queue{
    private:
        Node* head;
        Node* tail;
    public:
        Queue() : head(nullptr),tail(nullptr){}

        ~Queue(){
            while(head != nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        bool isEmpty(){
            return head == nullptr;
        }

        void enqueue(StudenteBorsista studente){
            Node* nuovo = new Node(studente);
            
            if(isEmpty()){
                head = nuovo;
                tail = nuovo;
            }
            else{
                tail->next = nuovo;
                tail = nuovo;
            }
        }

        StudenteBorsista dequeue(){
            if(isEmpty()){
                throw out_of_range("coda vuota");
            }

            StudenteBorsista rimosso = head->studente;
            Node* temp = head;
            head = head->next;
            delete temp;
            return rimosso;
            
        }

        void stampa(){
            Node* current = head;
            while(current != nullptr){
                current->studente.stampa();
                current = current->next;
            }
        }

        

        void rimuoviStudenti(){
            Node* current = head;
            Node* prev = nullptr;
            while(current != nullptr){
                if(current->studente.getMedia() < 25){
                    cout<<"Studente rimosso: "<<current->studente.getMatricola()<<" "<<current->studente.getNome()<<endl;

                    if(current == head){
                        head = head->next;
                        delete current;
                        current = head;
                    }
                    else{
                        
                        prev->next = current->next;
                        delete current;
                        current =  prev->next;
                        
                    }

                    
                
                }else{
                    prev = current;
                    current = current->next;
                }
            }
            
        }

        int totBorse(){
            Node* current = head;
            int somma;
            while(current != nullptr){
                if(current->studente.getImportoBorsa() != 0){
                    somma += current->studente.getImportoBorsa();
                    current = current->next;
                }
                else{
                    current = current->next;
                }
            }
            return somma;
        }
        
};



int main(){
Queue queue;

BorsaDiStudio Anna(880,12);
BorsaDiStudio Marco(500,12);
BorsaDiStudio Laura(600,12);

StudenteBorsista studente1("1001","Mario","Rossi",25.5,nullptr);
StudenteBorsista studente2("1002","Anna","Rossi",28.0,&Anna);
StudenteBorsista studente3("1003","Luca","Verdi",26.0,nullptr);
StudenteBorsista studente4("1004","Sara","Bianchi",27.5,nullptr);
StudenteBorsista studente5("1005","Marco","Neri",24,&Marco);
StudenteBorsista studente6("1006","Laura","Marroni",29.0,&Laura);

queue.enqueue(studente1);
queue.enqueue(studente2);
queue.enqueue(studente3);
queue.enqueue(studente5);
queue.enqueue(studente4);
queue.enqueue(studente6);

queue.dequeue();
queue.dequeue();

queue.enqueue(studente1);
queue.enqueue(studente2);

queue.rimuoviStudenti();

queue.stampa();
cout<<"totale borse di studio"<<queue.totBorse();



}