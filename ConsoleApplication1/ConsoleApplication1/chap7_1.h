#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class CStack{
public:
	CStack(){}
	~CStack(){}
	void append(const T& node);
	T del();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template <typename T>
void CStack<T>::append(const T& node){
	while(!queue2.empty()){
		queue1.push(queue2.front());
		queue2.pop();
	}
	queue1.push(node);
}

template <typename T>
T CStack<T>::del(){
	if(queue1.empty())
		throw exception("stack empty");

	while(queue1.size() > 1){
		queue2.push(queue1.front());
		queue1.pop();
	}
	T node = queue1.front();
	queue1.pop();

	while(!queue2.empty()){
		queue1.push(queue2.front());
		queue2.pop();
	}

	return node;
}

void testchap7_1(){
	CStack<int> stack;
	try{
		for(int i=0; i<10; i++)
			stack.append(i);
		for(int i=0; i<3; i++)
			cout << stack.del() << " ";
		for(int i=10; i<20; i++)
			stack.append(i);
		for(int i=3; i<21; i++)
			cout << stack.del() << " ";
	}
	catch(exception){
		cout << endl << "stack is empty" << endl;
	}
}
