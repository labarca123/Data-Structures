/**
@file list_char.h
@author Luis Garcia
*/
#ifndef LIST_CHAR_H_INCLUDED
#define LIST_CHAR_H_INCLUDED

#include <node.h>
#include <string>

template <class T>
class c_list {
	private:
		c_node<T> *head;
		c_node<T> *tail;
	public:
		c_list();
		~c_list();

		/**
		@brief Verifica si la lista esta vacia
		@return true si esta vacia
		@return false si no esta vacia
		*/
		inline bool empty() const {
			if(this->head == 0)
				return true;

			else
				return false;
		}

		/**
		@brief Obtiene el primer elemento de la lista
		@return 0 si la lista esta vacia
		@return primer elemento si existe
		*/
		inline T get_first() const {
			if( this->empty() ) 
				return 0;
			
			else
				return this->head->get_key();
		}

		/**
		@brief Obtiene el ultimo elemento de la lista
		@return 0 si la lista esta vacia
		@return ultimo elemento si existe
		*/
		inline T get_last() const {
			if( this->empty() ) 
				return 0;
			
			else
				return this->tail->get_key();
		}

		int find(const T&);
		int push_front(const T&);
		int pop_front();
		int push_back(const T&);
		int pop_back();
		int erase(const T&);
		int size();
		void to_string(std::string&);
};

/**
@brief Constructor por defecto
*/
template <class T> c_list<T>::c_list() {
	this->head = 0;
	this->tail = 0;
}

/**
@brief Destructor
*/
template <class T> c_list<T>::~c_list() {
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
template <class T> int c_list<T>::find(const T& letter) {
	if( this->empty() )
		return -1;

	else if (this->get_first() == letter || this->get_last() == letter)
		return 0;

	else {
		c_node<T> *aux = this->head->get_next();
		int i = 1;
		while(aux->get_next() != 0) {				
			if(aux->get_key() == letter) {
				return 0;
			}

			aux = aux->get_next();
		}
		return 1;
	}
}

/**
@brief Coloca un elemento al principio de la lista
@param Letter elemento a colocar
@return 0 Luego de colocar el elemento
*/
template <class T> int c_list<T>::push_front(const T& letter) {
	c_node<T> *aux = new c_node<T>;
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
template <class T> int c_list<T>::pop_front() {
	if ( this->empty() )
		return -1;

	else if (this->head == this->tail) {
		delete this->head;
		this->head = 0;
		this->tail = 0;
	}

	else{
		c_node<T> *aux = this->head;
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
template <class T> int c_list<T>::push_back(const T& letter) {
	c_node<T> *aux = new c_node<T>;
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
template <class T> int c_list<T>::pop_back() {
	if( this->empty() )
		return -1;

	else if(this->tail == this->head) {
		delete this->tail;
		this->tail = 0;
		this->head = 0;
	}

	else {
		c_node<T> *aux = this->head;

		while(aux->get_next()->get_next() != 0)
			aux = aux->get_next();

		this->tail = aux;
		this->tail->change_next(0);
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
template <class T> int c_list<T>::erase(const T& letter) {
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
		c_node<T> *aux, *aux2;
		aux = this->head;

		while( aux->get_next()->get_key() != letter )
			aux = aux->get_next();
		
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
template <class T> int c_list<T>::size() {
	if( this->empty() )
		return 0;

	else if (this->head == this->tail) 
		return 1;

	else {
		int i = 1;
		c_node<T> *aux = this->head;

		while(aux->get_next() != 0 && aux != 0) {
			aux = aux->get_next();
			i++;
		}

		return i;
	}
}

template <class T> void c_list<T>::to_string(std::string& s) {
	c_node<T> *aux;
	aux = this->head;

	while(aux != 0) {
		s += aux->get_key() ;
		aux = aux->get_next();
	}
}

#endif
