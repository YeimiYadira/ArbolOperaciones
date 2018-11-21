#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
// Pila
struct Nodo{
	char dato;
	Nodo *siguiente;
};
 
// Cola
struct Nodo2{
	char dato2;
	Nodo2 *siguiente2;
};

//Resultado
struct Nodo3{
	float dato;
	Nodo3 *siguiente;
};

void menu();
void inPila(Nodo *&,char);
void inPos(Nodo2 *&,Nodo2 *&,char);
void vaciarPila(Nodo *&,Nodo2 *&,Nodo2 *&);
void vaciarCola(Nodo2 *&);
void cambio(Nodo *&,Nodo2 *&,Nodo2 *&,char);
void cambio2(Nodo *&,Nodo2 *&,Nodo2 *&,char);
bool menor(char,int);
void resultado2(Nodo3 *&,float);
void operaciones(Nodo3 *&,float);

int main(){
	Nodo *pila=NULL;
	Nodo *auxPila=NULL;
	Nodo2 *frente=NULL;
	Nodo2 *fin=NULL;
	Nodo *aux=NULL;
	Nodo2 *auxMostrar=NULL;
	Nodo2 *auxMostrar2=NULL;
	Nodo3 *pila3=NULL;
	Nodo2 *ptrFrente=NULL;
	float resultado;
	char opcion;
	int numCaracteres;
	char *caracter;
	char auxCaracter;
	int posicion=0;

	do{
		menu();
		cin>>opcion;
		fflush(stdin);
		switch(opcion){
			case '1':
				cout << "\n1.Insertar datos." << endl;
			    cout << "\nCaracteres a ingresar: ";
				cin >> numCaracteres;
				fflush(stdin);
				caracter = new char[numCaracteres];
				cout<< "Expresion matematica: ";
				cin.getline(caracter,numCaracteres+10,'\n');
				fflush(stdin);
				for(int i=0; i<numCaracteres; i++){
					auxCaracter=caracter[i];
					cout << auxCaracter << " ";
					switch(auxCaracter){
						case '(':
							cout << "\n\t(: Este caracter es invalido" << endl;
							fflush(stdin);
							break;
						case ')':
							cout << "\n\t): Este caracter es invalido" << endl;
							fflush(stdin);
							break;
						case '^':
							cout << "\n\t^: Este caracter es invalido" << endl;
							fflush(stdin);
							break;	
						case '+':
							if(pila==NULL){
								inPila(pila,auxCaracter);
							}else if(pila->dato==auxCaracter){
								inPos(frente,fin,auxCaracter);
							}else{
								cambio(pila,frente,fin,auxCaracter);
							}
							if(pila !=NULL){
								if(pila->siguiente !=NULL){
									switch(pila->siguiente->dato){
										case '-':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '+':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '*':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '/':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
									}
								}
							}
							break;
						case '-':
							if(pila==NULL){
								inPila(pila,auxCaracter);
							}else if(pila->dato==auxCaracter){
								inPos(frente,fin,auxCaracter);
							}else{
								cambio(pila,frente,fin,auxCaracter);
							}
							if(pila !=NULL){
								if(pila->siguiente !=NULL){
									switch(pila->siguiente->dato){
										case '-':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '+':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '*':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '/':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
									}
								}
							}
							break;
						case '*':
							posicion=2;
							if(pila==NULL){
								inPila(pila,auxCaracter);
							}else if(pila->dato==auxCaracter){
								inPos(frente,fin,auxCaracter);
							}else if(menor(auxCaracter,posicion)){
								cambio(pila,frente,fin,auxCaracter);
							}else{
								inPila(pila,auxCaracter);
							}
							if(pila !=NULL){
								if(pila->siguiente !=NULL){
									switch(pila->siguiente->dato){
					            		case '*':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '/':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
									}
								}
							}
							break;
						case '/':
							posicion=3;
							if(pila==NULL){
								inPila(pila,auxCaracter);
							}else if(pila->dato==auxCaracter){
								inPos(frente,fin,auxCaracter);
							}else if(pila->dato=='*'){
								cambio(pila,frente,fin,auxCaracter);
							}else if(menor(auxCaracter,posicion)){
								cambio(pila,frente,fin,auxCaracter);
							}else{
								inPila(pila,auxCaracter);
							}
							if(pila !=NULL){
								if(pila->siguiente !=NULL){
									switch(pila->siguiente->dato){
					            		case '*':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
					            		case '/':
											auxCaracter=pila->siguiente->dato;
					            			cambio2(pila,frente,fin,auxCaracter);
					            			break;
									}
								}
							}
							break;
						default:
							inPos(frente,fin,auxCaracter);
							break;
					}
				}
				while(pila !=NULL){
					vaciarPila(pila,frente,fin);
				}
				break;
			case '2':
				cout << "2. Mostrar datos." << endl;
				cout << "Postorden: " << endl;
				auxMostrar = frente;
				while(auxMostrar !=NULL){
					cout<<auxMostrar->dato2<<" ";
					auxMostrar=auxMostrar->siguiente2;
				}
				break;
			case '3':
				cout << "3. Mostrar resultado." << endl;
				ptrFrente=frente;
				while(ptrFrente !=NULL){
					switch(ptrFrente->dato2){
						case '*':
							resultado=pila3->siguiente->dato*pila3->dato;
							operaciones(pila3,resultado);
							break;
						case '/':
							resultado=pila3->siguiente->dato/pila3->dato;
							operaciones(pila3,resultado);
							break;
						case '+':
							resultado=pila3->siguiente->dato+pila3->dato;
							operaciones(pila3,resultado);
							break;
						case '-':
							resultado=pila3->siguiente->dato-pila3->dato;
							operaciones(pila3,resultado);
							break;
						default:
							char auxCaracter3=ptrFrente->dato2;
							float convertir = auxCaracter3-'0';
							resultado2(pila3, convertir);
							break;
					}
					ptrFrente=ptrFrente->siguiente2;
				}
				cout<< "\nEl resultado es: " << pila3->dato;
				break;
			case '4':
				cout << "\n3.Eliminar datos." << endl;
				while(frente !=NULL){
					vaciarCola(frente);
				}
				break;
			case '5':
				cout << " " << endl;
				break;
			default:
				cout << "\nError" << endl;
				break;
		}
		cout<< " " <<endl;
		getch();
		system("cls");
	}while(opcion != '5');
	return 0;
}

void menu(){
	cout <<"\n\tMENU"<<endl;
	cout <<"1. Insertar caracteres" << endl;
	cout <<"2. Mostrar datos" << endl;
	cout <<"3. Mostrar resultado" << endl;
	cout <<"4. Eliminar datos" << endl;
	cout <<"5. Salir" << endl;
	cout <<"Elige una opcion: ";
}

void inPila(Nodo *&pila,char dato){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = pila;
	pila = nuevoNodo;
}

void inPos(Nodo2 *&frente,Nodo2 *&fin,char dato){
	Nodo2 *nuevoNodo2 = new Nodo2();
	nuevoNodo2->dato2 = dato;
	if(frente==NULL){
		frente=nuevoNodo2;
	}else{
		fin->siguiente2 = nuevoNodo2;
	}
	fin=nuevoNodo2;
}

void cambio(Nodo *&pila,Nodo2 *&frente,Nodo2 *&fin,char auxDato){
	Nodo *aux=pila;
	char auxCaracter;
	auxCaracter = aux->dato;
	inPos(frente,fin,auxCaracter);
	pila = aux->siguiente;
	delete aux;
	inPila(pila,auxDato);
}

bool menor(char caracter,int posicion){
	char signos[]={'*','/','+','-'};
	for(int i=posicion; i<5; i++){
		if(caracter==signos[i]){
			return true;
		}
	}
	return false;
}

void vaciarPila(Nodo *&pila,Nodo2 *&frente,Nodo2 *&fin){
	char auxCaracter;
	Nodo *aux = NULL;
	aux = pila;
	auxCaracter = aux->dato;
	inPos(frente,fin,auxCaracter);
	pila = aux->siguiente;
	delete aux;
}

void vaciarCola(Nodo2 *&frente){
	Nodo2 *aux = new Nodo2();
	aux = frente;
	frente = aux->siguiente2;
	delete aux;
}

void resultado2(Nodo3 *&pila3,float dato){
	Nodo3 *nuevoNodo = new Nodo3();
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = pila3;
	pila3 = nuevoNodo;
}

void operaciones(Nodo3 *&pila3,float dato){
	int auxNum;
	Nodo3 *aux = pila3;

	auxNum = aux->dato;
	pila3 = aux->siguiente->siguiente;
	delete aux;
	resultado2(pila3,dato);
}

void cambio2(Nodo *&pila,Nodo2 *&frente,Nodo2 *&fin,char dato){
	Nodo *aux=pila;
	char auxCaracter;
	auxCaracter = aux->dato;
	inPos(frente,fin,dato);
	pila = aux->siguiente->siguiente;
	delete aux;
	inPila(pila,auxCaracter);
}
