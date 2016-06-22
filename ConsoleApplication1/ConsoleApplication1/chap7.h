#include <iostream>
using namespace std;

template <typename T> 
class CQueue{
public:
	CQueue(void){}
	~CQueue(void){}
	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> 
void CQueue<T>::appendTail(const T& node){
	stack1.push(node);
}

template<typename T> 
T CQueue<T>::deleteHead(){
	if(stack2.empty()){
		while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	if(stack2.empty())
		throw exception("queue is empty");


	T node;
	node = stack2.top();
	stack2.pop();

	return node;
}

void testchap7(){
	CQueue<int> myqueue;
	try{
		for(int i=0; i<10; i++)
			myqueue.appendTail(i);
		for(int i=0; i<3; i++)
			cout << myqueue.deleteHead() << " ";
		for(int i=10; i<20; i++)
			myqueue.appendTail(i);
		for(int i=3; i<20; i++)
			cout << myqueue.deleteHead() << " ";
	}
	catch(exception){
		cout << endl << "queue is empty" << endl;
	}

}
