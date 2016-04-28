#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

template <class TYPE>
struct Node
{
	TYPE data;
	Node* next = nullptr;

	Node(const TYPE& data) : data(data){};
	~Node(){};
};


template <class	TYPE>
class List
{
private:
	Node<TYPE>* first=nullptr;

public:
	
	List(Node<TYPE>* first) : first(first){};
	~List(){};

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


	//TODO pushback() & pushfront();
	void pushback(TYPE data){
		Node<TYPE>* new_node = end();
		new_node->next = new Node<TYPE>(data);
	}

	void pushfront(TYPE data){
		Node<TYPE>* temp = first;
		first = new Node<TYPE>(data);
		first->next = temp;
	}

};


#endif // !__LINKED_LIST_H__
