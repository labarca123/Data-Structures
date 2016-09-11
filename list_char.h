/**
@file list_char.h
@author Luis Garcia
*/
#ifndef LIST_CHAR_H_INCLUDED
#define LIST_CHAR_H_INCLUDED

#include "node_char.h"
#include <iostream>

class c_list_char {
	private:
		c_node_char* head;
		c_node_char* tail;
	public:
		c_list_char(){
			head = 0;
			tail = 0;
		}
		~c_list_char(){}

		inline bool empty() const {
			if(this->head == 0)
				return true;
			else
				return false;
		}

		inline char get_first() const {
			if( this->empty() ) 
				return 0;
			
			else
				return this->head->get_key();
		}

		inline char get_last() const {
			if( this->empty() ) 
				return 0;
			
			else
				return this->tail->get_key();
		}

		inline bool find_key(char l) const {
			if( this->empty() )
				return false;
			else {
				c_node_char* aux = new c_node_char;
				aux->change_key(l);
				aux->change_next(head);	

				while(aux->get_key() != l && aux->get_next() != 0) {
					aux->change_next( aux->get_next() );
					aux->change_key( aux->get_next() -> get_key() );
				}
				if(aux->get_next() != 0)
					return true;
				else
					return false;
			}
		}

		int push_front(char l) {
			c_node_char* aux = new c_node_char;
			aux->change_key( l );

			if( this->empty() ) {
				this->tail = aux;
				this->head = aux;
				return 0;
			}
			else {
				aux->change_next( head );
				this->head = aux;
				return 1;
			}
		}

		int pop_front() {
			if ( this->empty() )
				return 1;

			else if (this->head->get_next() == 0) {
				delete this->head;
				this->head = 0;
				this->tail = 0;
				return 0;
			}

			else{
				c_node_char* aux = head;
				this->head = this->head->get_next();
				delete aux;
				return -1;
			}
		}

		int push_back(char l) {
			c_node_char* aux = new c_node_char;
			aux->change_key( l );

			if( this->empty() ) {
				this->tail = aux;
				this->head = aux;
				return 0;
			}
			else {
				this->tail->change_next(aux);
				this->tail = aux;
				return 1;
			}
		}

		int pop_back() {
			c_node_char* aux = head;

			while(aux->get_next() != 0) {
				aux->change_next(aux->get_next());
			}


		}
};

#endif