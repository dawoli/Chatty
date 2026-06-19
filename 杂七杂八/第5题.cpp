#include <iostream>
#include <string>
using namespace std;

class MyStr
{
	string data;
public:
	MyStr(string _data): data(_data) {}
};

int main()
{
	MyStr st("ABC");
	//cout<<st<<endl;
	cout<<st.data<<endl;
	return 0;
}