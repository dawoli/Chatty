#include<iostream>
using namespace std;
int main(){
	int a[11]={};
	for(int i=1;i<=10;i++)
		cin>>a[i];
	int h;
	cin>>h;
	h+=30;
	int sum=0;
	for(int i=1;i<=10;i++)
		if(h>=a[i])
			sum++;
	cout<<sum;
	return 0;
}
