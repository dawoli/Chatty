#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b)
		cout<<"YES";
	else if(b==c)
		cout<<"YES";
	else if(a==c)
		cout<<"YES";
	else
		cout<<"NO";
}

