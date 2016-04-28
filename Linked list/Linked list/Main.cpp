
#include "Linked list.h"

int main(){
	
	Node<int> test(5);
	
	List<int> listTest(&test);
	bool emptyTest = listTest.empty();
	unsigned int sizeTest = listTest.size();
	Node<int>* endTest = listTest.end();

	listTest.pushback(endTest);

	return 0;
}