#include<iostream>
using namespace std;
int main(){
	int a[5];
	for(int i=0;i<=4;i++)
		cin>>a[i];
	int id;
	cin>>id;
	cout<<a[id-1]<<endl;
	return 0;
}
