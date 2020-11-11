//TRABALHO DE ESTRUTURA DE DADOS 1
//NOME:IVO AGUIAR PIMENTA

#include <iostream>

using namespace std;

int const MAXTAM = 25;

class Pilha{
	private :
		int vetor[MAXTAM]; //pilha
        int topo; // topo da pilha
	
   	public:
   		//Construtor da Classe
		Pilha(){
			this->topo= -1;
		}
		
		//Método que Apaga a Pilha
		void Clear(){
		     this ->topo = -1;
		}
		
		//Método que verifica se a pilha esta vazia
		bool isEmpty(){
			if(topo == -1){
				return true;
			} else{
				return false;
			}
		}
		
		//Método queverifica se a Pilha esta cheia
		bool isFull(){
			if(topo == MAXTAM-1){
				return true;
			} else{
				return false;
			}
		}
		
		//Método que insere um elemento na Pilha
		void Push( int info){
			if(isFull()){
				cout<<"Erro: A Pilha esta cheia. "<<endl;
			}else{
			   vetor[topo+1] = info;
			    topo ++;	
			}
        }
        
        //Método que Remove algum elemento da Pilha e retorna o elemento que foi removido
        int Pop(){
         int guarda;
		 if(isEmpty()){
           cout<<"Erro: A Pilha esta Vazia, nao ha elementos para remover."<<endl<<endl;
			} else{
			  guarda = vetor[topo];
			  vetor[topo] == NULL;
			  topo --;	
			}
			return guarda;
		}
        
        //Método que retorna o Topo da Pilha
        int Top(){
			if(isEmpty()){
				cout<<"Erro: A Pilha esta vazia."<<endl;
			} else{
				return vetor[topo];
			}
		}
		
		//Métodod que retorna o tamnho da Pilha
		int Size(){
			return topo + 1;
		}
		
	
		//Método que realiza a Busca na Pilha
		int Search(int elemento){
		   int status = 0; // Variável que irá guardar se o elemento está ou nao na Pilha
		   int guarda;
		   Pilha aux;
		   //Caso a pilha esteja vazia 
		   if(topo == -1){
			   status = 0; 
		   }
		   //Caso a Pilha só tenha um elemento
		   if(topo == 0){
			   guarda = Pop();
			   if(guarda == elemento){
				   status  = 1;
				   Push(guarda);
			   } else{
				   status = 0;
				   Push(guarda);
			   }
		   }
		   //Caso a Pilha tenha mais de um elemento
		   if(topo > 0){
           int cont = topo;
		   guarda = Pop();
		   //Compara se o elemento que se está buscando é o primeiro da Pilha
		    if(guarda == elemento){
			  status =1;
			  Push(elemento); 
           // Caso o elemento não esteja na 1º Posição*/
		   } else{
		   	 aux.Push(guarda);
		   	 // Processo que desempilha até achar o elemento e caso não esteja status continua com 0
			  while(topo > -1){
				  guarda = Pop();
				  aux.Push(guarda);
				  cont --;
				  if(guarda == elemento){
					  status = 1;
					  break;
				  }
				  if(cont == 0){
					  break;
				  }
			  } 
			  //Processo que irá empilhar na Pilha novamente
			  while(aux.topo!=-1){
				  Push(aux.Pop());
			  }
		    }  
		   }
		  
		   
		   return status;	
		}
			
		
	
};

int main(int argc, char** argv){
   Pilha p1;
   int item;
   do{
	     cout<<"======================== MENU PRINCIPAL ============================= "<<endl<<endl;
	   cout<<"OPERACOES DA PILHA: "<<endl;
	   cout<<"|1| - Pilha Vazia "<<endl;
	   cout<<"|2| - Pilha Cheia "<<endl;
	   cout<<"|3| - Tamanho da Pilha "<<endl;
	   cout<<"|4| - Empilhar"<<endl;
	   cout<<"|5| - Desempilhar"<<endl;
	   cout<<"|6| - Elemento do Topo da Pilha "<<endl;
	   cout<<"|7| - Buscar Elemento "<<endl;
	   cout<<"|8| - Apagar Pilha"<<endl;
	   cout<<"|9| - Sair"<<endl<<endl;
	   cout<<"Insira o numero referente a operacao que deseja realizar: ";
	   cin>>item;
	   cout<<endl<<endl;
	   
	      if(item == 1){
		   if(p1.isEmpty()){
			   cout<<"A  Pilha esta vazia"<<endl<<endl;
		   } else{
			  cout<<"A  Pilha nao esta vazia"<<endl<<endl; 
		   }
	   }
	   
	    else if(item ==  2){
		   if(p1.isFull()){
			   cout<<"A Pilha esta cheia."<<endl<<endl;
		   } else{
			  cout<<"A Pilha nao esta cheia."<<endl<<endl ;
		   }
	   }
	   
	    else if(item ==  3){
		   cout<<"O tamanho da Pilha e: "<<p1.Size()<<"."<<endl<<endl;
	   }
	   
	    else if(item == 4){
		   cout<<"Insira o elemento que dejeja inserir na Pilha: ";
		   int elemento;
		   cin>>elemento;
		   p1.Push(elemento);
		   cout<<endl<<endl;
	   }
	    else if(item == 5){
  	      if(!p1.isEmpty()){
		    cout<<"Elemento: "<<p1.Pop()<<" "<<"foi removido da Pilha"<<endl<<endl;
          } else{
			  p1.Pop();
		  }
	   }
	   
	   else if(item == 6){
	   	    if(!p1.isEmpty()){
		   cout<<"O elemento no topo da Pilha e: "<<p1.Top()<<"."<<endl<<endl;
		    } else{
				p1.Top();
			}
	   }
	   else if(item == 7){
		   cout<<"Insira o elemento que deseja buscar na Pilha: ";
		   int elemento;
		   cin>>elemento;
		   cout<<endl<<endl;
		   if(p1.Search(elemento) == 1){
			   cout<<"O elemento esta na Pilha."<<endl<<endl;
		   } else{
			   cout<<"O elemento nao esta na Pilha."<<endl<<endl;
		   }
	   }
	   
	   else if(item == 8){
		   p1.Clear();
	   }
	       else if(item<1 || item>9){
		   cout<<"Opcao Invalida."<<endl<<endl;
	   }
	   
	   
   }while(item!=9);
}