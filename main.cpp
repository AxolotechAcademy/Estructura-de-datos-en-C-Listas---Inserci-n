#include <iostream>
using namespace std;
class Personas{
public:
	char Nombre[50];
	int Edad;
	void Pedir_datos();
	void Imprime_Datos();
};
class Nodo{
public:
	Personas registros;
	Nodo *sig;
};
class Lista{
private:
	Nodo *primero;
	Nodo *ultimo;
public:
	void Insercion_Final();
	void Mostrar_Todo();
};
void Personas::Pedir_datos()
{
	cout<<"Inserte el Nombre de la Persona: ";
	cin.ignore();
	cin.getline(Nombre,50);
	cout<<endl;
	cout<<"Inserte la edad de la Persona: ";
	cin>>Edad;
	cout<<endl;
}
void Personas::Imprime_Datos()
{
	cout<<"Mostrar Datos"<<endl;
	cout<<"Nombre: "<<Nombre<<endl;
	cout<<"Edad: "<<Edad<<endl;
}
void Lista::Insercion_Final()
{
	Nodo* nuevo = new Nodo();
	nuevo->registros.Pedir_datos();
	if (primero == NULL)
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{
		Nodo *aux = primero;
		while (aux != ultimo)
		    aux = aux->sig;
		aux->sig = nuevo;
		nuevo->sig = ultimo;
		ultimo = nuevo;
	}
	ultimo->sig = NULL;
}
void Lista::Mostrar_Todo()
{
	Nodo *actual = new Nodo();
	actual = primero;
	if (primero != NULL)
	{
		while (actual != NULL)
		{
			actual->registros.Imprime_Datos();
			actual = actual->sig;
		}
	}
	else
	    cout<<"Lista sin Registros"<<endl;
}
int main()
{
	Lista escoge;
	int opc;
	do
	{
		cout<<"Menu principal"<<endl;
		cout<<"1.- Inserta al Final"<<endl;
		cout<<"2.- Mostrar Todos los Registros"<<endl;
		cout<<"3.- Salir"<<endl;
		cout<<"Seleccione alguna opcion (1-3)"<<endl;
		cin>>opc;
		switch(opc)
		{
			case 1:
				escoge.Insercion_Final();
				break;
			case 2:
				escoge.Mostrar_Todo();
				break;
		}
	}
	while(opc != 3);
	return 0;
}