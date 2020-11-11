//TRABALHO DE ESTRUTURA DE DADOS 1
//NOME: Ivo Aguiar Pimenta
#include <iostream>
#include <vector>

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

class Lista{
	private:
		No* cabeca; // Primeiro elemento da lista
		No* cauda; // Último elemento da lista
		
    public:
    	Lista(){
			this -> cabeca = NULL;
			this -> cauda = NULL;
		}
		
		
					
		//Método que verifica se a Lista está vazia
		bool Vazia(){
			if(cabeca ==  NULL){
				return true;
			} else{
				return false;
			}
		}
		
			//Método que irá retornar o tamnho da lista
		int Tamanho(){
			if(Vazia()){ // Verifica se a lista está vazia
				return 0;
			}
			No* c = cabeca; //Elemento que irá percorrer a lista
			int tam = 0; // variável que será incrementada e no final guardará o tamnho da lista
			do{
				c = c->getProx(); 
				tam ++;
			} while(c != NULL);
			
			return tam;
		}
		
		//Método que irá imprimir a Lista
		void Imprimir(){
			No* c = cabeca; //Variavel que irá percorrer a lista
			//Verifica se a Lista esta vazia
		    if(Vazia()){
				cout<<"A lista nao possui elementos!!"<<endl;
            //Caso a lista não esteja vazia, c ira percorrer a lista e imprimir cada elemento
			} else{
				while(c){
					//Imprime o valor de c
					cout<<c->getValor()<<" ";
					//Agora a variavel c recebe o proximo Nó da lista
					c = c->getProx();
				}
				
				cout<<endl<<endl;
			}
		}
		    //Concatena duas Listas
			Lista LinkarLista(Lista l1, Lista l2){
		    Lista l3;
		    if(l2.Vazia() and !l1.Vazia()){
				l3.cabeca = l1.cabeca;
				l3.cauda = l1.cauda;
				return l3;
			}
			
			if(l1.Vazia() && !l2.Vazia()){
				l3.cabeca = l2.cabeca;
				l3.cauda = l2.cauda;
				return l3;
			}
			if(l1.Vazia() && l2.Vazia()){
				return l3;
			}
			l3.cabeca = l1.cabeca;
            l3.cauda = l1.cauda;
            No*c = l2.cabeca;
            while(c){
			     
				l3.Inserir(c->getValor());
				c = c->getProx();
			}
			return l3;
		}
		
		bool EqList(Lista l1, Lista l2){
			bool status = true;
			//Caso o tamanho de Lista 1 e Lista 2 estejam diferente
			if(l1.Tamanho() != l2.Tamanho()){
				status =  false;
			}
			//Caso o tamnho das Listas seja igual
			else{
				No* p1 = l1.cabeca; //No que percorre a Lista 1
				No* p2 = l2.cabeca;  //No que percorre a Lista 2
				int cont = 1;
				//Caso as duas Listas estejam Vazia
				if(l1.Tamanho() == 0 && l2.Tamanho() == 0){
					status = true;
                 //Caso as duas Listas so tenham 1 elemento cada
				} else if( l1.Tamanho() == 1 && l2.Tamanho()== 1){
					if( p1->getValor() == p2->getValor()){
						status = true;
					} else{
						status = false;
					}
                //Caso as duas Listas so tenham mais de 1 elemento cada
				}else{
                  while(cont < Tamanho()){
				   if(p1->getValor() != p2->getValor()){
					   status = false;
					   cont = Tamanho();
				   }
				   p1 = p1->getProx();
				   p2 = p2->getProx();
				   cont++;	
				}
				}
           }
			return status;
		}
		
		//Método que irá inserir no início da Lista
	    void InserirInicio(int elemento){
			No* novo = new No(elemento); //Cria um novo nó co o elemento passado por parametro
			novo->setProx(cabeca); 
			cabeca = novo;
        }
        
        //Metodo que irá inserir o elemento no final da Lista
        void Inserir(int elemento){
			No* novo = new No(elemento);
			//Verifica se a lista esta vazia e depois insere o eleemnto na lista
			if(Vazia()){
				cabeca = novo;
				cauda = novo;
             //Caso a lista não esteja vazia o elemento será inserido no final da lista
			} else{
				cauda->setProx(novo);
				cauda = novo;
			}
		}
		  
		  //Método que irá Inserir na Lista de forma que la se mantenha em ordem crescente
		  void InserirOrdenado(int elemento){
		  	//Condição caso a Lista não esteja em ordem crescente, ou seja o elemento não pode ser inserido em ordem
			if(Vazia()){
			   Inserir(1,elemento);
			} else{
				int cont =0;
				//Caso o elemento va ser inserido na primeira posição
				if(elemento < cabeca->getValor()){
					Inserir(1,elemento);
				}
				//Caso o elemento vaser inserido na última posição
				else if(elemento > cauda->getValor()){
					Inserir(elemento);
                //Caso o elemento vá ser Inserido no meio da Lista
				} else{
					No* p = cabeca;
					while(elemento > p->getValor()){
						p = p->getProx();
						cont++;
					}
					Inserir(cont+1,elemento);
				}
			}
		}
		
		int Busca( int elemento){
			No* c = cabeca; //Variavel que ira percorrer a lista
			int posicao = NULL; // Varialvel que ira armazenar a posicao da lista
			int tam = 1;
            while(c){
            	// Se o valor respectivo de c corresponde ao elemento buscado, posicao recebe o tamanho da lisa
				if(c->getValor() == elemento){
					posicao = tam;
					break;
				//Caso não seja c recebe o valor do próximo Nó
				} else{
					c = c->getProx();
					tam++;
				}
			}
			if(posicao != NULL){
				return posicao;
			} else{ return NULL;}
		}

           
          //Método que Verifica se a Lista está em ordem Crescente
          int Ordenado(){
			  int status = 1; // Variável que recebeo status da ordenação e e inicializada com 1
			  int cont = 2; 
			  //Condicao para caso o tamanho da Lista seja 0 ou 1
			  if(Tamanho() == 0 || Tamanho() == 1){
                  status = 1;
			  }
			  // Caso o tamanho da Lista seja 2
			  if(Tamanho() == 2){
				  if(cabeca->getValor()< cauda->getValor()){
					  status = 1;
				  } else{
					 status = 0; 
				  }
			  }
			  //Caos o tamanho da Lista seja maior que 2
			  if( Tamanho() > 2){
				  No* p = cabeca;//Recebe o 1 elemento da Lista
				  No* prox = p->getProx();// Recebe o elemento seguinte de p
				 while( cont<Tamanho()){
                        if(prox->getValor() < p->getValor()){
						  status = 0;
		        	  }	
		        	  //Passo que percorre a Lista
					   p = prox;
		               prox = prox->getProx();
		               cont++;           
               }	
           }
          //Status recebe 1 caso a Lista esteja Ordenada e 0 caso não esteja Ordenada
          return status;
       } 
           
      
			//Método que Remove o elemento da Lista
       void Remover( int index){
		    No* anterior = NULL;  // Nó que irá receber o elemento anterior
		    No* p = cabeca; // Nó que irá percorrer a lista
		    int cont = 1;
		    
		    if(index > Tamanho() || index <=0 ){
				cout<<"Erro: Posicao da Lista Invalida."<<endl<<endl;
			} else{
			   // Remove o 1 elemento da Lista caso o index seja 1
		       if(index == 1){
		    	 cabeca = p->getProx();
		    	 p->setProx(p);
		    	 delete p;
			   }
			//Casso o index seja maior que 1
			   if(index>1){
				while(cont<index){
					anterior = p;
					p = p->getProx();
					cont ++;
				}
				if(cont == index){
					anterior->setProx(p->getProx());
                    p->setProx(p);
                    delete p;
				}
              }	
			}
		    
    }
        
           //Método que Insere o Elemento em qualquer posição da lista com base no Índice passado
        void Inserir(int indice, int elemento){
			int tam = Tamanho(); // Variavel que vai receber o tamanho da lista
			int posicao = 0; //Variavel que sera incrementada para quando indicer for igual ao passado pelo usuario
			No* novo = new No(elemento); // No criado que irá armazenar o novo elemento
			No* p = cabeca; //No que ira percorrer a lista
			No* anterior = NULL; // No que recebe o No anterior de p
			
			//Condição para caso o usuario passe no indice um valor inválido ou que nao pode ser usado
			if(indice>tam+1){
				cout<<"Posicao Invalida."<<endl;
				cout<<"So podemos inserir elementos nas posicaoes de "<<tam<<" a "<<tam+1<<endl;
			}
			//Caso o indice seja valido 
			else if(indice <= tam+1){
				//Percorre a lista até a posicaoser igual ao indice - 1 pois a lista se inicia na posicao 0
				while(posicao!= indice-1){
					anterior = p;
					p = p->getProx();
				    posicao ++;
				}
				//Caso o elemnto vá ser inserido na 1 posicao
				if(anterior == NULL){
				  novo->setProx(cabeca);
				  cabeca = novo;
                //Caso o elemento va ser inserido no meio ou no final da lista
				}else{
					anterior->setProx(novo);
					novo->setProx(p);
				}
			}
		}
		
	
};

int main(int argc, char** argv)

{ 
   Lista L3,L4,L5,L6;
   L3.Inserir(4);
   L3.Inserir(5);
   L3.Inserir(6);
   L4.Inserir(3);
   L4.Inserir(2);
   L4.Inserir(1);
   cout << "LISTA3:\n";
   L3.Imprimir();
    cout << "LISTA4:\n";
   L4.Imprimir();
   L5 = L3.LinkarLista(L3,L4);
   L5.Imprimir();
  
   
   Lista l1,l2;
   int item;
   do{
	  cout<<"================================= MENU PRINCIPAL ================================= "<<endl<<endl;
	  cout<<"|1| - Lista 1 "<<endl;
	  cout<<"|2| - Lista 2 "<<endl;
	  cout<<"|3| - Sair "<<endl;
	  cout<<"Insira um item referente a operacão que vai realizar: ";
	  cin>>item;
	  cout<<endl<<endl;
	  if(item == 1){
		  int opcao;
		  do{
		  cout<<"============================== OPERACOES COM A LISTA 1 =============================="<<endl<<endl;
		  cout<<"|1| - Insercao Aleatoria "<<endl;
	      cout<<"|2| - Insercão Ordenada "<<endl;
	      cout<<"|3| - Voltar "<<endl<<endl;
	      cout<<"Insira um item referente a operacao que vai realizar: ";
	      cin>>opcao;
	      if( opcao == 1){
	       	int op;
	       	do{
			 cout<<"============================== LISTA 1 INSERCAO ALEATORIA  =============================="<<endl<<endl;
             cout<<"|1| - Vazia "<<endl;
             cout<<"|2| - Inserir no Final da Lista "<<endl;
             cout<<"|3| - Inserir em uma Posicao Valida da Lista "<<endl; 
             cout<<"|4| - Tamanho Lista "<<endl; 
             cout<<"|5| - Busca"<<endl; 
             cout<<"|6| - Remocao"<<endl; 
             cout<<"|7| - Imprimir"<<endl; 
             cout<<"|8| - Compara se Lista l1 e igual a Lista l2"<<endl; 
             cout<<"|9| - Voltar"<<endl<<endl;
             cout<<"Insira um item referente a operacao que vai realizar: ";
	         cin>>op;
	         cout<<endl<<endl;
	         
	        if(op == 1){
				if(l1.Vazia()){
					cout<<"A lista esta Vazia. "<<endl<<endl;
				} else{
					cout<<"A lista nao esta Vazia. "<<endl<<endl;
				}
			 }
			 
			 else if(op == 2){
				 cout<<"Digite o numero que deseja Inserir na Lista: ";
				 int num;
				 cin >> num;
				 l1.Inserir(num);
				 cout<<endl;
			 }
			 
			 else if(op == 3){
                 cout<<"Digite a posicao que deseja Inserir um numero na Lista: ";
				 int posicao;
				 cin >> posicao; 
                 cout<<"Digite o numero que deseja Inserir na Lista:";
				 int num;
				 cin >> num; 
				 l1.Inserir(posicao,num);
                 cout<<endl;
			 }
			 
			 else if(op == 4){
			    cout<<"O tamanho da Lista e: ";
				cout<<l1.Tamanho();
				cout<<"."<<endl<<endl;	 
			 }
			 
			 else if(op == 5){
			 	int num;
				 cout<<"Insira o elemento que deseja buscar na Lista: ";
				 cin >> num;
				 if(l1.Busca(num) != NULL){
					 cout<<num<<" esta na posicao " << l1.Busca(num) <<endl<<endl;
				 } else{
					 cout<<num<<"O elemento nao esta na Lista. "<<endl<<endl; 
				 }
			 }
			 
			 else if(op == 6){
				int posicao;
				cout<<"Insira a posicao a qual deseja remover o elemento da Lista: ";
				cin>>posicao;
				l1.Remover(posicao); 
			 }
			 
			 else if(op == 7){
				 l1.Imprimir();
			 }
			 
			 else if(op == 8){
				 if(l1.EqList(l1,l2) == true){
					 cout<<"As listas sao iguais. "<<endl<<endl;
				 } else{
					 cout<<"As listas nao sao iguais. "<<endl<<endl;
				 }
			 }
			 
			 
			 else if(item <1 || item>9){
		      cout<<"Opcao Invalida."<<endl<<endl;
	         }
	         
	        
	         
           }while(op!=9);
		  }
		  
		  else if(opcao == 2){
		  	int op;
	       	do{
			 cout<<"============================== LISTA 1 INSERCAO ORDENADA =============================="<<endl<<endl;
             cout<<"|1| - Vazia "<<endl;
             cout<<"|2| - Insercao Ordenada "<<endl;
             cout<<"|3| - Tamanho Lista "<<endl; 
             cout<<"|4| - Busca"<<endl; 
             cout<<"|5| - Remocao"<<endl; 
             cout<<"|6| - Imprimir"<<endl; 
             cout<<"|7| - Compara se Lista l1 e igual a Lista l2"<<endl; 
             cout<<"|8| - Voltar"<<endl<<endl;
             cout<<"Insira um item referente a operacao que vai realizar: ";
	         cin>>op;
	         cout<<endl<<endl;
	         if(op == 1){
				if(l1.Vazia()){
					cout<<"A lista esta Vazia. "<<endl<<endl;
				} else{
					cout<<"A lista nao esta Vazia. "<<endl<<endl;
				}
			 }
			 
			else  if(op == 2){
				 cout<<"Digite o numero que deseja Inserir na Lista: ";
				 int num;
				 cin >> num;
				 l1.InserirOrdenado(num);
				 cout<<endl;
			 }
			 
			 
			else  if(op == 3){
			    cout<<"O tamanho da Lista e: ";
				cout<<l1.Tamanho();
				cout<<"."<<endl<<endl;	 
			 }
			 
			else  if(op == 4){
			 	int num;
				 cout<<"Insira o elemento que deseja buscar na Lista: ";
				 cin >> num;
				 if(l1.Busca(num) != NULL){
					 cout<<num<<" esta na posicao " << l1.Busca(num) <<endl<<endl;
				 } else{
					 cout<<num<<"O elemento nao esta na Lista. "<<endl<<endl; 
				 }
			 }
			 
            else  if(op == 5){
				int posicao;
				cout<<"Insira a posicao a qual deseja remover o elemento da Lista: ";
				cin>>posicao;
				l1.Remover(posicao); 
			 }
			 
			else  if(op == 6){
				 l1.Imprimir();
			 }
			 
			else  if(op == 7){
				 if(l1.EqList(l1,l2) == true){
					 cout<<"As listas sao iguais. "<<endl<<endl;
				 } else{
					 cout<<"As listas nao sao iguais. "<<endl<<endl;
				 }
			 }
            else if(item <1 || item>8){
		      cout<<"Opcao Invalida."<<endl<<endl;
	         }
           }while(op!=8);
		  }
		   else if(item <1 || item >3){
		      cout<<"Opcao Invalida."<<endl<<endl;
	         }
			  
		  }while(opcao != 3);
	  }
	  
	 else  if(item == 2){
		  int opcao;
		  do{
		  cout<<"============================== OPERACOES COM A LISTA 2 =============================="<<endl<<endl;
		  cout<<"|1| - Insercao Aleatoria "<<endl;
	      cout<<"|2| - Insercao Ordenada "<<endl;
	      cout<<"|3| - Voltar "<<endl;
	      cout<<"Insira um item referente a operacao que vai realizar: ";
	      cin>>opcao;
	      if( opcao == 1){
	       	int op;
	       	do{
			 cout<<"============================== LISTA 2 INSERCAO ALEATORIA  =============================="<<endl<<endl;
             cout<<"|1| - Vazia "<<endl;
             cout<<"|2| - Inserir no Final da Lista "<<endl;
             cout<<"|3| - Inserir em uma Posicao Valida da Lista "<<endl; 
             cout<<"|4| - Tamanho Lista "<<endl; 
             cout<<"|5| - Busca"<<endl; 
             cout<<"|6| - Remocao"<<endl; 
             cout<<"|7| - Imprimir"<<endl; 
             cout<<"|8| - Compara se Lista l1 e igual a Lista l2"<<endl; 
             cout<<"|9| - Voltar"<<endl<<endl;
             cout<<"Insira um item referente a operacao que vai realizar: ";
	         cin>>op;
             cout<<endl<<endl;
	         
	         if(op == 1){
				if(l2.Vazia()){
					cout<<"A lista esta Vazia. "<<endl<<endl;
				} else{
					cout<<"A lista nao esta Vazia. "<<endl<<endl;
				}
			 }
			 
			else if(op == 2){
				 cout<<"Digite o numero que deseja Inserir na Lista: ";
				 int num;
				 cin >> num;
				 l2.Inserir(num);
				 cout<<endl;
			 }
			 
			else if(op == 3){
                 cout<<"Digite a posicao que deseja Inserir um numero na Lista: ";
				 int posicao;
				 cin >> posicao; 
                 cout<<"Digite o numero que deseja Inserir na Lista:";
				 int num;
				 cin >> num; 
				 l2.Inserir(posicao,num);
                 cout<<endl;
			 }
			 
			else if(op == 4){
			    cout<<"O tamanho da Lista e: ";
				cout<<l2.Tamanho();
				cout<<"."<<endl<<endl;	 
			 }
			 
			else if(op == 5){
			 	int num;
				 cout<<"Insira o elemento que deseja buscar na Lista: ";
				 cin >> num;
				 if(l2.Busca(num) != NULL){
					 cout<<num<<" esta na posicao " << l2.Busca(num) <<endl<<endl;
				 } else{
					 cout<<num<<"O elemento nao esta na Lista. "<<endl<<endl; 
				 }
			 }
			 
			else if(op == 6){
				int posicao;
				cout<<"Insira a posicao a qual deseja remover o elemento da Lista: ";
				cin>>posicao;
				l2.Remover(posicao); 
			 }
			 
			else if(op == 7){
				 l2.Imprimir();
			 }
			 
			else if(op == 8){
				 if(l2.EqList(l1,l2) == true){
					 cout<<"As listas sao iguais. "<<endl<<endl;
				 } else{
					 cout<<"As listas nao sao iguais. "<<endl<<endl;
				 }
			 }
			 
			  else if(item <1 || item >9){
		      cout<<"Opcao Invalida."<<endl<<endl;
	         }
	         
           }while(op!=9);
		  }
		  
		  else if(opcao == 2){
		  	int op;
	       	do{
			 cout<<"============================== LISTA 2 INSERCAO ORDENADA =============================="<<endl<<endl;
             cout<<"|1| - Vazia "<<endl;
             cout<<"|2| - Insercao Ordenada "<<endl;
             cout<<"|3| - Tamanho Lista "<<endl; 
             cout<<"|4| - Busca"<<endl; 
             cout<<"|5| - Remocao"<<endl; 
             cout<<"|6| - Imprimir"<<endl; 
             cout<<"|7| - Compara se Lista l1 e igual a Lista l2"<<endl; 
             cout<<"|8| - Voltar"<<endl<<endl;
             cout<<"Insira um item referente a operacao que vai realizar: ";
	         cin>>op;
	         cout<<endl<<endl;
	         
	         if(op == 1){
				if(l2.Vazia()){
					cout<<"A lista esta Vazia. "<<endl<<endl;
				} else{
					cout<<"A lista nao esta Vazia. "<<endl<<endl;
				}
			 }
			 
			 else if(op == 2){
				 cout<<"Digite o numero que deseja Inserir na Lista: ";
				 int num;
				 cin >> num;
				 l2.InserirOrdenado(num);
				 cout<<endl;
			 }
			 
			 
			else if(op == 3){
			    cout<<"O tamanho da Lista e: ";
				cout<<l2.Tamanho();
				cout<<"."<<endl<<endl;	 
			 }
			 
			else if(op == 4){
			 	int num;
				 cout<<"Insira o elemento que deseja buscar na Lista: ";
				 cin >> num;
				 if(l2.Busca(num) != NULL){
					 cout<<num<<" esta na posicao " << l2.Busca(num) <<endl<<endl;
				 } else{
					 cout<<num<<"O elemento nao esta na Lista. "<<endl<<endl; 
				 }
			 }
			 
			else  if(op == 5){
				int posicao;
				cout<<"Insira a posicao a qual deseja remover o elemento da Lista: ";
				cin>>posicao;
				l2.Remover(posicao); 
			 }
			 
			else if(op == 6){
				 l2.Imprimir();
			 }
			 
			else if(op == 7){
				 if(l2.EqList(l1,l2) == true){
					 cout<<"As listas sao iguais. "<<endl<<endl;
				 } else{
					 cout<<"As listas nao sao iguais. "<<endl<<endl;
				 }
			 }
			 
			   else if(item <1 || item >8){
		      cout<<"Opcao Invalida."<<endl<<endl;
	         }
           }while(op!=8);
		  }
		  
		    else if(item <1 || item >3){
		      cout<<"Opcao Invalida."<<endl<<endl;
	         }
			  
       }while(opcao != 3);  
   } 
   
     else if(item <1 || item >3){
		      cout<<"Opcao Invalida."<<endl<<endl;
	         } 
	  
   }while(item != 3);
}