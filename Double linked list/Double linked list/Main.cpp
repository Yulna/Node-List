#include "SimpleUnitTest.h"
#include "doble linked List.h"


int main(){

	DList<int> DListTest;

	int sizeTest = DListTest.size();
	bool emptyTest = DListTest.empty();
	TEST("Empty true", emptyTest);
	Node<int>* endTest = DListTest.end();

	DListTest.pushback(6);
	DListTest.pushback(7);
	DListTest.pushfront(4);
	DListTest.pushfront(3);

	emptyTest = DListTest.empty();
	TEST("Empty false", emptyTest == false);
	endTest = DListTest.end();
	//TEST("End:", endTest == 7);
	sizeTest = DListTest.size();
	TEST("Size:", sizeTest == 4);
	

	bool pop;
	
	TEST("First pop", DListTest.pop_back());
	pop = DListTest.pop_back();
	pop = DListTest.pop_back();
	pop = DListTest.pop_back();
	TEST("Empty pop", DListTest.pop_back() == false);

	DListTest.pushfront(3);
	DListTest.pushfront(4);
	TEST("Pop front", DListTest.pop_front());
	TEST("Pop front 1 element", DListTest.pop_front());
	TEST("Empty Pop front", DListTest.pop_front()==false);

	DListTest.pushback(1);
	DListTest.pushback(2);
	DListTest.pushback(3);
	DListTest.pushback(4);

	Node<int>* it = DListTest.first;
	it = it->next;
	TEST("Erase midle", DListTest.erase(it));
	it = DListTest.end();
	TEST("Erase last", DListTest.erase(it));
	it = DListTest.first;
	TEST("Erase first", DListTest.erase(it));
	it = DListTest.first;
	TEST("Erase one", DListTest.erase(it));



	PRINT_TEST_REPORT();
	return 0;
}