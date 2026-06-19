#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[100]={};
	for(int i=0;i<n;i++)
		cin>>a[i];
	int id;
	cin>>id;
	cout<<a[id-1]<<endl;
	return 0;
}
