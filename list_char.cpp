/**
@file list_char.cpp
@author Luis Garcia
*/
#include <list_char.h>

/**
@brief Constructor por defecto
*/
c_list_char::c_list_char(){
	this->head = 0;
	this->tail = 0;
}

/**
@brief Destructor
*/
c_list_char::~c_list_char() {
	while( !this->pop_front() );
		return;
}

/**
@brief Busca un elemento en la lista
@param Letter elemento a buscar
@return -1 Si la lista esta vacia
@return 0 Si el elemento esta en la lista
@return 1 Si el elemento no esta en la lista
*/
int c_list_char::find(char letter) {
	if( this->empty() )
		return -1;

	else if (this->get_first() == letter || this->get_last() == letter)
		return 0;

	else {
		c_node_char *aux = new c_node_char;
		aux->change_next( this->head );

		while(aux->get_next() != 0) {		
			aux->change_key( aux->get_next() -> get_key() );
			aux->change_next( aux->get_next() -> get_next() );

			if(aux->get_key() == letter) 
				return 0;
		}

		return 1;
	}
}

/**
@brief Coloca un elemento al principio de la lista
@param Letter elemento a colocar
@return 0 Luego de colocar el elemento
*/
int c_list_char::push_front(char letter) {
	c_node_char *aux = new c_node_char;
	aux->change_key( letter );

	if( this->empty() ) {
		this->tail = aux;
		this->head = aux;
	}
	else {
		aux->change_next( this->head );
		this->head = aux;
	}

	return 0;
}

/**
@brief Elimina el primer elemento de la lista
@return -1 Si la lista esta vacia
@return 0 Luego de eliminar el elemento
*/
int c_list_char::pop_front() {
	if ( this->empty() )
		return -1;

	else if (this->head == this->tail) {
		delete this->head;
		this->head = 0;
		this->tail = 0;
	}

	else{
		c_node_char *aux = this->head;
		this->head = this->head->get_next();
		delete aux;
	}
	return 0;
}

/**
@brief Coloca un elemento al final de la lista
@param Letter elemento a colocar
@return 0 Luego de colocar el elemento
*/
int c_list_char::push_back(char letter) {
	c_node_char *aux = new c_node_char;
	aux->change_key( letter );

	if( this->empty() ) {
		this->tail = aux;
		this->head = aux;
	}
	else {
		this->tail->change_next(aux);
		this->tail = aux;
	}
	return 0;
}

/**
@brief Elimina el primer elemento de la lista
@return -1 Si la lista esta vacia
@return 0 Luego de eliminar el elemento
*/
int c_list_char::pop_back() {
	if( this->empty() )
		return -1;

	else if(this->tail == this->head) {
		delete this->tail;
		this->tail = 0;
		this->head = 0;
	}

	else {
		c_node_char *aux = this->head;

		while(aux->get_next()->get_next() != 0)
			aux->change_next( aux->get_next()->get_next() );

		this->tail = aux;
		this->tail->change_next(0);
		aux = this->tail->get_next();
		delete aux;
	}
	return 0;
}

/**
@brief Elimina un elemento dado de la lista
@param Elemento a eliminar
@return -1 Si la lista esta vacia, o si el elemento no se encuentra
@return 0 Luego de eliminar el elemento
*/
int c_list_char::erase(char letter) {
	if( this->empty() )
		return -1;

	else if( this->find( letter ) != 0 )
		return -1;

	else if(this->get_first() == letter) {
		this->pop_front();
	}

	else if(this->get_last() == letter) {
		this->pop_back();
	}

	else {
		c_node_char *aux, *aux2;
		aux = this->head;

		while( aux->get_next()->get_key() != letter )
			aux->change_next( aux->get_next()->get_next() );
		
		aux2 = aux->get_next();

		delete aux2;

		aux->change_next( aux->get_next()->get_next() );
	}
	return 0;
}

/**
@brief Encuentra el nro de elementos de la lista
@return 0 Si la lista esta vacia
@return 1 Si la lista tiene un solo elemento
@return i El tamaño de la lista
*/
int c_list_char::size() {
	if( this->empty() )
		return 0;

	else if (this->head == this->tail) 
		return 1;

	else {
		int i = 1;
		c_node_char *aux = this->head;

		while(aux->get_next() != 0 && aux != 0) {
			aux = aux->get_next();
			i++;
		}

		return i;
	}
}