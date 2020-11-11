//TRABALHO DE ESTRUTURA DE DADOS 1
//NOME:IVO AGUIAR PIMENTA

#include <iostream>

using namespace std;

class No{
	private:
		int valor;//informação contida no Nó
		No* prox; // Ponteiro que aponta para o próximo Nó
		
    public:
    	No (int valor){
			this-> valor = valor;
			this-> prox = NULL;
		}
		
		int getValor(){
			return valor;
		}
		
		No* getProx(){
			return prox;
		}
		
		void setValor(int elemento){
			valor = elemento;
		}
		
		void setProx( No* p){
			prox = p;
		}
};

class Fila{
	private:
	  No* frente; //Nó que está na frente da Fila
	  No* tras; //Nó que está na frente da Fila
	  
     public:
     	//Construtor
     	Fila(){
		   this->frente = NULL;
		   this->tras = NULL;	 
		 }
       //Método que verifica se a Fila está vazia 
       bool isEmpty(){
		   if(frente == NULL){
			   return true;
		   } else{
			   return false;
		   }
	   }
	   
	   //Método que verifica se a Fila está cheia, como a fila é encadeada sempre retornará falso
	   bool isFull(){
		   return false;
	   }
       
       //Método que insere um elemento na Fila
       void Enqueue(int info){
       	  No* novo = new No(info); // Criando Nó que será inserido
       	  //Condição caso a Fila esteja Vazia
		  if(isEmpty()){
			frente = novo;
			tras = novo;  
          //Condição caso a Fila não esteja vazia
		  } else{
			  tras->setProx(novo);
			  tras = novo;
		  }
	   }
	   
	   //Método que remove o 1 elemento da Fila, pois Fila é FIFO
	   int Dequeue(){
	   	   if(isEmpty()){
			cout<<"Erro: A fila esta vazia, nao ha elementos para remover."<<endl<<endl;	  
           } else{
		     int removido = frente->getValor();
		     frente = frente->getProx();
		     return removido;
          }
	   }
	   
	   //Método que retorna o elemento que está na frente dentro da Fila
	   int FirstEl(){
	   	   if(isEmpty()){
				  return NULL;
			  } else{
				 return frente->getValor(); 
			  }
	   }
	   
	   //Método que busca um elemento da Fila
	   int Search(int info){
	   	   int status = 0; // Variável que guardará o resultado caso o elemnto esteja ou não na Fila
		   //Condição para caso a Fila esteja Vazia
		   if(frente == NULL){
			 status = 0; 
            //Condicao caso a Fila não esteja vazia
		   } else{
			   Fila aux;
			   int guarda; // Variável que irá guardar o valor removido da Fila
			   while(frente!=NULL){
				 guarda = Dequeue();
				 aux.Enqueue(guarda); 
				 if(guarda == info){
					 status = 1;
				 } 
			   }
			   //Recuperação de dados da Fila após a Busca
			   int reeinsere;
			  while(aux.frente!=NULL){
				 reeinsere = aux.Dequeue();
				 Enqueue(reeinsere); 
			  }
		   }
		   return status;
	   }
        
};

int main(int argc, char** argv)
{
	Fila f1;
    int item;
   do{
   cout<<"======================== MENU PRINCIPAL ============================= "<<endl<<endl;
	   cout<<"OPERACOES DA FILA: "<<endl;
	   cout<<"|1| - Vazia "<<endl;
	   cout<<"|2| - Cheia "<<endl;
	   cout<<"|3| - Enfileirar "<<endl;
	   cout<<"|4| - Desenfileirar"<<endl;
	   cout<<"|5| - Primeiro elemento da Fila"<<endl;
	   cout<<"|6| - Buscar "<<endl;
	   cout<<"|7| - Sair"<<endl;
	   cout<<endl;
	   cout<<"Insira o numero referente a operacao que deseja realizar: ";
	   cin>>item;
	   cout<<endl<<endl;
	   
	   if(item == 1){
		   if(f1.isEmpty()){
			   cout<<"A  Fila esta vazia"<<endl<<endl;
		   } else{
			  cout<<"A   Fila nao esta vazia"<<endl<<endl; 
		   }
	   }
	   
	   else if(item ==2){
		   if(f1.isFull()){
			   cout<<"A  Fila esta cheia."<<endl<<endl;
		   } else{
			  cout<<"A  Fila nao esta cheia."<<endl<<endl ;
		   }
	   }
	   
	   else if(item == 3){
		   cout<<"Insira o elemento que dejeja inserir na Fila: ";
		   int elemento;
		   cin>>elemento;
		   f1.Enqueue(elemento);
		   cout<<endl<<endl;
	   }
	   
	   else if(item == 4){
	   	  if(!f1.isEmpty()){
		    cout<<"Elemento: "<<f1.Dequeue()<<" "<<"foi removido da Fila"<<endl<<endl;
          } else{
			  f1.Dequeue();
		  }
	   }
	   
	   else if(item == 5){
	   	  if(!f1.isEmpty()){
		   cout<<"O elemento na frente da Fila e: "<<f1.FirstEl()<<"."<<endl<<endl;
			 } else{
				 cout<<"A fila esta vazia."<<endl<<endl;
			 }
	   }
	   
	   else if(item == 6){
		    cout<<"Insira o elemento que deseja buscar na Fila: ";
		   int elemento;
		   cin>>elemento;
		   cout<<endl<<endl;
		   if(f1.Search(elemento) == 1){
			   cout<<"O elemento esta na Fila."<<endl<<endl;
		   } else{
			   cout<<"O elemento nao esta na Fila."<<endl<<endl;
		   }
	   }
	   else if(item<1 || item>7){
		   cout<<"Opcao Invalida."<<endl<<endl;
	   }
       
    
   }while(item!=7);
   return 0;

}