
#include "Linked list.h"

int main(){
	
	Node<int> test(5);
	
	List<int> listTest(&test);
	bool emptyTest = listTest.empty();
	unsigned int sizeTest = listTest.size();
	Node<int>* endTest = listTest.end();

	listTest.pushfront(4);
	listTest.pushback(6);

	bool pop1 = listTest.pop_back();
	bool pop2 = listTest.pop_back();

	return 0;
}