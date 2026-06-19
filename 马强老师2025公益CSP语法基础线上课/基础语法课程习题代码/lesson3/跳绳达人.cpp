#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	if(a>b)
		cout<<"Tongtong"<<endl;
	else//a<=b bug
		cout<<"Meimei"<<endl;
	return 0;
}
