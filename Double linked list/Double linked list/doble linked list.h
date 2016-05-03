#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

template <class TYPE>
struct Node
{
	TYPE data;
	Node* next = nullptr;
	Node* previous = nullptr;

	Node(const TYPE& data) : data(data){};
	~Node(){};
};


//TODO double DList
template <class	TYPE>
class DList
{
public:
	Node<TYPE>* first = nullptr;

public:

	DList(){};
	DList(TYPE data){
		first = new Node<TYPE>(data);
	};
	DList(Node<TYPE>* first) : first(first){};
	~DList(){};


	bool empty() const{
		return (first == nullptr);
	}

	unsigned int size() const{
		unsigned int ret = 0;
		Node<TYPE>* temp = first;
		while (temp != nullptr){
			temp = temp->next;
			ret++;
		}
		return ret;
	}

	Node<TYPE>* end()const{
		Node<TYPE>* temp = first;
		if (empty() == false){
			while (temp->next != nullptr)
				temp = temp->next;
		}
		return temp;
	}

	void pushback(const TYPE& data){
		Node<TYPE>* it = end();
		if (it != nullptr){
			it->next = new Node<TYPE>(data);
			it->next->previous = it;
		}
		else{
			first = new Node<TYPE>(data);
		}
	}
	void pushfront(const TYPE& data){
			Node<TYPE>* temp = first;
			first = new Node<TYPE>(data);
			first->next = temp;
			if (temp != nullptr)
				temp->previous = first;
			
	}




	bool pop_back(){
		if (first != nullptr){
			Node<TYPE>* last = end();
			if (last->previous != nullptr)
				last->previous->next = nullptr;		
			if (last == first)
				first = nullptr;
			delete last;
			return true;
		}
		return false;
	}


	bool pop_front(){
		if (first != nullptr){
			Node<TYPE>* temp = first;
			first = first->next;
			if (first != nullptr)
				first->previous = nullptr;
			delete temp;
			return true;
		}
		return false;
	}


	//TODO erase && insert
	bool erase(Node<TYPE>* tokill){
		//NEED AN ITERATOR, would be useful to have a doube direction List
		if (tokill != nullptr){
			if (tokill->previous != nullptr)
				tokill->previous->next = tokill->next;
			else first = tokill->next;
			if (tokill->next != nullptr)
				tokill->next->previous = tokill->previous;
			else tokill->previous = nullptr;

			delete tokill;
			tokill = nullptr;
			return true;
		}
		return false;
	}


};


#endif // !__DOUBLE_LINKED_LIST_H__
