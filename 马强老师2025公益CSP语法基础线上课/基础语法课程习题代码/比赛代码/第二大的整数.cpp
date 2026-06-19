#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[3]={};
	cin>>a[0];
	cin>>a[1];
	cin>>a[2];
	sort(a+0,a+3);
	cout<<a[1];
	return 0;
}
