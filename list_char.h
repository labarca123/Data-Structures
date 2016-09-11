/**
@file list_char.h
@author Luis Garcia
*/
#ifndef LIST_CHAR_H_INCLUDED
#define LIST_CHAR_H_INCLUDED

#include <node_char.h>

class c_list_char {
	private:
		c_node_char *head;
		c_node_char *tail;
	public:
		c_list_char();
		~c_list_char();

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
		inline char get_first() const {
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
		inline char get_last() const {
			if( this->empty() ) 
				return 0;
			
			else
				return this->tail->get_key();
		}

		int find(char);

		int push_front(char);

		int pop_front();

		int push_back(char);

		int pop_back();

		int erase(char);

		int size();
};

#endif