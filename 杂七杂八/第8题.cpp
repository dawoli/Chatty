#include <iostream>
using namespace std;

class MoreData
{
	int *__data;
	int head,tail,capacity;
public:
	MoreData(int cap)
	{
		capacity=cap;
		__data=new int[capacity];
		head=tail=0;
	}
	MoreData &push(int val)
	{
		__data[tail++]=val;
		return *this;
	}
	int pop()
	{
		return __data[head++];
	}
	int size()
	{
		return tail-head;
	}
};

int main()
{
	auto myData=MoreData(100);
	myData.push(1);
	myData.push(2);
	myData.push(3);
	myData.push(11).push(12).push(13);
	cout<<myData.pop()<<endl;
	return 0;
}