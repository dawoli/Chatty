#include<iostream>
using namespace std;
int main(){
	int a[10]={1,2,3,5,6,7,8};
	//a[3]增加4
	for(int i=6;i>=3;i--)
		a[i+1]=a[i];
	a[3]=4;
	for(int i=0;i<8;i++)
		cout<<a[i]<<' ';
	return 0;
}
