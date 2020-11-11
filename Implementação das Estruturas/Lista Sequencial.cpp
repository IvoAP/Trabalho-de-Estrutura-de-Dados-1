//TRABALHO DE ESTRUTURA DE DADOS 1
//NOMES: IVO AGUIAR PIMENTA


#include <iostream>

using namespace std;
const int MAXTAM = 2;

class Lista{
	private:
		int frente;
		int tras;
		int* vetor;
		int tamanho;
     
     public:
     	//Construtor
     	Lista(){
			this->tras = -1;
            this->frente =0;
            this-> vetor = new int [MAXTAM];
			this->tamanho = MAXTAM;	 
        }
        //Método que Altera o Tmanho do vetor caso a Lista esteja Cheia
        void AlteraTamanhoVetor(int* vetor, int tam){
        	int v [tam+1];
        	for(int i =0; i<tam ;i++){
				v[i] = vetor[i];
			}
			delete vetor;
			vetor = v;
			tamanho= tam+1;
			
        
		}
	    //Método que Verifica se a Lista está Vazia
        bool Vazia(){
			if(frente>tras){
		    	return true;
			}else{
			  return false;		
			}
       }
       //Método que verifica se a Lista está Cheia
       bool Cheia(){
		   if(tras == tamanho - 1){
			   return true;
		   } else{
			   return false;
		   }
	   }
	    
	    //Método que retorna o tamanho da lista
	    int Tamanho(){
		   return tras+1;
		}
        
        //Método que Insere no Final
		void Inserir(int elemento){
           //Condição para caso a Lista esteja Cheia
		   if(Cheia()){
		   	int item;
	     	do{
   		    cout<<endl<<endl;
            cout<<"A lista esta Cheia. E preciso criar um novo vetor para inserir o novo elemento."<<endl;
	     	cout<<"Nao se preocupe pois todos os seus dados serao copiados nesse novo vetor para que nao haja nenhuma perca."<<endl;
	     	cout<<endl;
            cout<<"Deseja criar a nova Lista:"<<endl<<endl;
	     	cout<<"|1| Criar novo Vetor               |2|Cancelar "<<endl;
	     	cout<<"Insira sua opcao: ";
	     	cout<<endl;
	     	cin>>item;
	     	if(item == 1){
				 AlteraTamanhoVetor(vetor, Tamanho());//Chamada do Método que altera o tamanho da Lista
		         Inserir(elemento);	
		       	 cout<<" Criado novo vetor e novo valor Inserido na  Lista"<<endl<<endl;
				 break;  
			 }
		   
			 } while(item!=2);
	     
             } else{
			   vetor[tras+1] = elemento;//Inserção do elemento na última posição
			   tras++;//Incrementa a última posição do vetor
		   }
	   }
	   //Método que insere um elemento com base na posição
	    void Inserir(int elemento, int posicao){
          int tam = Tamanho(); // variável que recebe o tamanho da Lista
		  //Condiçaõ para Caso a Lista esteja Cheia	
  	      if(Cheia()){
            int item;
	     	do{
            cout<<endl<<endl;
   		    cout<<"A lista esta Cheia. E preciso criar um novo vetor para inserir o novo elemento."<<endl;
	     	cout<<"Nao se preocupe pois todos os seus dados serao copiados nesse novo vetor para que nao haja nenhuma perca."<<endl;
	     	cout<<endl;
            cout<<"Deseja criar a nova Lista:"<<endl<<endl;
	     	cout<<"|1| Criar novo Vetor               |2|Cancelar "<<endl;
	     	cout<<"Insira sua opcao: ";
	     	cout<<endl;
	     	cin>>item;
	     	if(item == 1){
				 AlteraTamanhoVetor(vetor, Tamanho());//Chamada do Método que altera o tamanho da Lista
		         Inserir(elemento,posicao);	
		       	 cout<<" Criado novo vetor e novo valor Inserido na  Lista"<<endl<<endl;
				 break;  
			 }
		   
           } while(item!=2);
           } else if(posicao<=0 ||  posicao>tam+2){
			   cout<<"Erro: Posicao da Lista Invalida."<<endl<<endl;
		   }
		   //Inserção caso a Lista não esteja cheia
		   else{
  	         tras++; //Incrementa tras 
  	         tam = Tamanho();
		     int aux = tam-1; // Variável que recebe o índice da ultima posição do vetor
		      //Loop que irá passar copiar para o vetor as posições a esquerda
		     while(aux!= posicao -1){
			 vetor[aux] = vetor[aux-1];
			  aux--;
		   }
		   vetor[posicao - 1] = elemento;
           } 
       }
       //Método que ordena a Lista
       void Ordenar(){
       	   int j,aux;
		   for(int i = 1; i< Tamanho(); i++){
			 j =i;
			 while(vetor[j]<vetor[j-1]&& j>0){
				 aux = vetor[j];
				 vetor[j] = vetor[j-1];
				 vetor[j -1] =aux;
				 j--;
			 }
		   }
	 }
	   //Método que verifica se a Liste está ordenada
	   int Ordenado(){
	   	  int inicio = vetor[0];
	   	  int tam = Tamanho();
	   	  int status = 1; // A variável é inicializada com 1 caso caso o vetor sótenha um elemento ou esteja vazio
	   	  //Verifica se o vetor está ordenado caso tenha 2 elementos
	   	  if(tam == 2){
				 if(inicio> vetor[1]){
				    status = 0;	 
				 } else{
					 status = 1;
				 }
			 }
           //Verifica se o vetor está ordenado caso o vetor tenha mais de 2 elementos
           if(tam>2){
			 for(int i =0; i<tam; i++){
			   for(int j = i+1; j<tam; j++){
				   if(vetor[i]>vetor[j]){
					   status = 0;
				   }
			   }	
		   }
          
	   }
	    return status;
    }
     //Método que irá Inserir um elemento caso a Lista esteja em ordem Crescente
     void InserirOrdenado(int elemento){
         if (Vazia()){
          vetor[tras+1] = elemento;
          tras++;
	     } else if(Cheia()){
	     	int item;
	     	do{
   		    cout<<endl<<endl;
            cout<<"A lista esta Cheia. E preciso criar um novo vetor para inserir o novo elemento."<<endl;
	     	cout<<"Nao se preocupe pois todos os seus dados serao copiados nesse novo vetor para que nao haja nenhuma perca."<<endl;
	     	cout<<endl;
            cout<<"Deseja criar a nova Lista:"<<endl<<endl;
	     	cout<<"|1| Criar novo Vetor               |2|Cancelar "<<endl;
	     	cout<<"Insira sua opcao: ";
	     	cout<<endl;
	     	cin>>item;
	     	if(item == 1){
				 AlteraTamanhoVetor(vetor, Tamanho());
		         InserirOrdenado(elemento);	
		         cout<<" Criado novo vetor e novo valor Inserido na  Lista"<<endl<<endl;
				 break;  
			 }
		   
			 } while(item!=2);
	     
		 }else{
			//Caso do elemento deva ser Inserido na 1º posição do vetor
			if(elemento<vetor[0]){
				Inserir(elemento,1);
			}
			//Caso do elemento deva ser Inserido na última posição do vetor
			else if(elemento>vetor[Tamanho()-1]){
			    Inserir(elemento);
			//Caso do elemento deva ser Inserido no meio do vetor	
			} else{
				int posicao;
				for(int i =0; i<Tamanho(); i++){
					for(int j =i+1; j<Tamanho(); j++){
						if(elemento>=vetor[i] && elemento <=vetor[j]){
							posicao = j+1;
							break;
						}
					}
				}
				cout<<posicao<<endl;
				Inserir(elemento, posicao);
			}
		}
	  }
    
     void Remover(int posicao){
		   int tam = Tamanho();
		   //Condição caso a Lista esteja vazia
		   if(Vazia()){
			   cout<<"Erro: A lista esta vazia."<<endl<<endl;
           // Condição para caso a posicao seja negativa ou maior que qualquer posição maior que o tamanho da Lista
		   } else if(posicao <=0 || posicao>tamanho){
			  cout<<"Erro: Posicao da Lista Invalida."<<endl<<endl; 
           // Remoção da Lista
		   } else{
			   int aux = posicao -1; // Auxiliar que recebe a posição do vetor -1
			   while(aux!= tam-1){
			   	   //Remoção do valor passando o elemento a frente para a posição anterior
				   vetor[aux] = vetor[aux+1];
				   aux++;
			   }
			   tras --;
		   }
    }  
       //Método que irá Imprimir a Lista
         void Imprimir(){
         int tam = Tamanho();
	     for(int i =0; i<tam; i++){
		   cout<<vetor[i]<< " ";
	     }
	     cout<<endl<<endl;
       }
    
};
	   



int main(int argc, char** argv){ 
   Lista l1,l1ord;
   int opcao;
   do{
	   cout<<"=================================== MENU PRINCIPAL ==================================== "<<endl<<endl;
	   cout<<"|1| - Insercao Aleatoria "<<endl;
       cout<<"|2| - Insercao Ordenada "<<endl;
       cout<<"|3| - Sair "<<endl<<endl;
       cout<<"Insira o numero referente a operacao que deseja realizar: ";
	   cin>>opcao;
	   cout<<endl;
	   
    if(opcao == 1){
	   	int item;
	   	do{
		  cout<<"=================================== Insercao Aleatoria ==================================== "<<endl<<endl;  
	      cout<<"|1| - Vazia "<<endl;
          cout<<"|2| - Cheia "<<endl;
          cout<<"|3| - Inserir no Final da Lista "<<endl;
          cout<<"|4| - Inserir em uma Posicao Valida da Lista "<<endl; 
          cout<<"|5| - Tamanho Lista "<<endl; 
          cout<<"|6| - Remocao"<<endl; 
          cout<<"|7| - Imprimir"<<endl; 
          cout<<"|8| - Voltar"<<endl<<endl;
          cout<<"Insira um item referente a operacao que vai realizar: ";
          cin>>item;
          cout<<endl<<endl;
	   
	      if(item == 1){
		   if(l1.Vazia()){
			   cout<<"A lista esta vazia"<<endl<<endl;
		   } else{
			  cout<<"A lista nao esta vazia"<<endl<<endl; 
		   }
	    }
	    
	    else if(item == 2){
			if(l1.Cheia()){
				cout<<"A lista esta cheia. "<<endl<<endl;
			} else{
				cout<<"A lista nao esta cheia. "<<endl<<endl;
			}
		}
	   
	   	 else if(item == 3){
				 cout<<"Digite o numero que deseja Inserir na Lista: ";
				 int num;
				 cin >> num;
				 l1.Inserir(num);
				 cout<<endl;
			 }
	   
	 	 else if(item == 4){
                 cout<<"Digite a posicao que deseja Inserir um numero na Lista: ";
				 int posicao;
				 cin >> posicao; 
                 cout<<"Digite o numero que deseja Inserir na Lista:";
				 int num;
				 cin >> num; 
				 l1.Inserir(num,posicao);
                 cout<<endl;
			 }
  	   
        else if(item == 5){
			    cout<<"O tamanho da Lista e: ";
				cout<<l1.Tamanho();
				cout<<"."<<endl<<endl;	 
			 }
	   
	    else if(item == 6){
				int posicao;
				cout<<"Insira a posicao a qual deseja remover o elemento da Lista: ";
				cin>>posicao;
				l1.Remover(posicao); 
			 }
        else if(item == 7){
				 l1.Imprimir();
			 }
        else if(item<1 || item>8){
		   cout<<"Opcao Invalida."<<endl<<endl;
	    }

      }while(item!=8);   
   } 
   else if(opcao == 2){
	 int item;
	   	do{
		  cout<<"=================================== Insercao Ordenada ==================================== "<<endl<<endl;  
	      cout<<"|1| - Vazia "<<endl;
          cout<<"|2| - Cheia "<<endl;
          cout<<"|3| - Inserir Ordenada "<<endl;
          cout<<"|4| - Tamanho Lista "<<endl; 
          cout<<"|5| - Remocao"<<endl; 
          cout<<"|6| - Imprimir"<<endl; 
          cout<<"|7| - Voltar"<<endl<<endl;
          cout<<"Insira um item referente a operacao que vai realizar: ";
          cin>>item;
          
          if(item == 1){
		   if(l1ord.Vazia()){
			   cout<<"A lista esta vazia"<<endl<<endl;
		   } else{
			  cout<<"A lista nao esta vazia"<<endl<<endl; 
		   }
	    }
	    
	    else if(item == 2){
			if(l1ord.Cheia()){
				cout<<"A lista esta cheia. "<<endl<<endl;
			} else{
				cout<<"A lista nao esta cheia. "<<endl<<endl;
			}
		}
	   
	   	 else if(item == 3){
				 cout<<"Digite o numero que deseja Inserir na Lista: ";
				 int num;
				 cin >> num;
				 l1ord.InserirOrdenado(num);
				 cout<<endl;
			 }
  	   
        else if(item == 4){
			    cout<<"O tamanho da Lista e: ";
				cout<<l1ord.Tamanho();
				cout<<"."<<endl<<endl;	 
			 }
	   
	    else if(item == 5){
				int posicao;
				cout<<"Insira a posicao a qual deseja remover o elemento da Lista: ";
				cin>>posicao;
		     	l1ord.Remover(posicao); 
			 }
        else if(item == 6){
				 l1ord.Imprimir();
			 }
           else if(item<1 || item>7){
		   cout<<"Opcao Invalida."<<endl<<endl;
	   }

       
	   }while(item!= 7);  
   } else if(opcao <1 || opcao>3){
	   cout<<"Opcao Invalida."<<endl<<endl;
   }	 	   	
   }while(opcao != 3);

   return 0; 
}