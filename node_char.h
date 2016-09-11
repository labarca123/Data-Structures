/**
@file node_char.h
@author Luis Garcia
*/
#ifndef NODE_CHAR_H_INCLUDED
#define NODE_CHAR_H_INCLUDED

class c_node_char {
	private:
		char key;
		c_node_char* next;
	public:
		c_node_char() {
			this->next = 0;
		}
		~c_node_char() {
			
		}

		inline char get_key() const {
			return this->key;
		}

		inline c_node_char* get_next() const {
			return this->next;
		}

		int change_key(char l) {
			this->key = l;
			return 0;
		}

		int change_next(c_node_char* n) {
			this->next = n;
			return 0;
		}
};

#endif