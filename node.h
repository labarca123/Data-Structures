/**
@file node.h
@author Luis Garcia
*/
#ifndef NODE_CHAR_H_INCLUDED
#define NODE_CHAR_H_INCLUDED

template <class T>
class c_node {
	private:
		T key;
		c_node<T> *next;
	public:
		c_node() {
			this->next = 0;
		}
		~c_node() {}

		T& get_key() const {
			return this->key;
		}

		inline c_node<T>* get_next() const {
			return this->next;
		}

		int change_key(char l) {
			this->key = l;
			return 0;
		}

		int change_next(c_node<T> *n) {
			this->next = n;
			return 0;
		}
};

#endif
