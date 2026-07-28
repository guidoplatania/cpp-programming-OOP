#include <iostream>


class Node{
    private:
        int val;
        Node* next;
        Node* prev;
    public:
        Node(int val) : val(val),next(nullptr),prev(nullptr){}

        void setVal(int val){
            this->val = val;
        }
        int getVal(){
            return val;
        }  

        void setNext(Node* next){
            this->next = next;
        }
        Node* getNext(){
            return next;
        }

        void setPrev(Node* prev){
            this->prev = prev;
        }
        Node* getPrev(){
            return prev;
        }
};

class ListaDoppia{
    private:
        Node* head;
        Node* tail;
    public:
        ListaDoppia() : head(nullptr), tail(nullptr){}

        ~ListaDoppia(){
            Node* current = head;
            while(current != nullptr){
                Node* temp = current;
                current = current->getNext();
                delete temp;
            }
        }


        void AggiungiInCoda(int valore){
            Node* nuovo = new Node(valore);

            if(head == nullptr){
                head = nuovo;
                tail = nuovo;
            }
            else{
                tail->setNext(nuovo);
                nuovo->setPrev(tail);
                tail = nuovo;
            }
        }

        void AggiungiInTesta(int valore){
            Node* nuovo = new Node(valore);
            
            if(head == nullptr){
                head = nuovo;
                tail = nuovo;
            }
            else{
                head->setPrev(nuovo);
                nuovo->setNext(head);
                head = nuovo;
            }
        }


        void rimuovi(int valore){
            if(head == nullptr) return;

            if(head->getVal() == valore){
                Node* temp = head;
                head = head->getNext();
                head->setPrev(nullptr);
                delete temp;
                return;
            }

            if(tail->getVal() == valore){
                Node* temp = tail;
                tail = tail->getPrev();
                tail->setNext(nullptr);
                delete temp;
                return;
            }

            Node* current = head;
            
            while(current != nullptr && current->getVal() != valore){
                current = current->getNext();
            }

            if(current == nullptr){
                std::cout<<"numero non trovato "<<std::endl;
            }
            else{
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
            }
        }


        void stampa(){
            Node* current = head;
            while(current != nullptr){
                std::cout<<current->getVal() <<" -> ";
                current = current->getNext();
            }
            std::cout<<" NULL "<<std::endl;
        }

        Node* cerca(int valore){
            Node* current = head;
            while(current != nullptr && current->getVal() != valore){
                current = current->getNext();
            }
            if(current == nullptr){
                return NULL;
            }
            else{
                std::cout<<"numero "<< valore << "trovato all'indirizzo "<< &current <<std::endl;
                return current;
            }
        }







};






int main(){
ListaDoppia list1;

list1.AggiungiInTesta(10);
list1.AggiungiInCoda(5);
list1.AggiungiInTesta(20);
list1.AggiungiInTesta(30);
list1.AggiungiInCoda(4);
list1.AggiungiInCoda(3);

list1.stampa();

list1.rimuovi(30);
list1.rimuovi(10);
list1.rimuovi(3);

list1.stampa();
list1.cerca(4);

}
