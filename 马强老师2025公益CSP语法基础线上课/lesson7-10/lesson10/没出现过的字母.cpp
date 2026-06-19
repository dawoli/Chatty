#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	char x;
	bool a[300]={};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;//'c'
		a[x]=1;//a[99]=1;
	}
	for(char i='a';i<='z';i++)
	{
		if(a[i]==0)
		{
			cout<<i<<' ';
		}
	}
	return 0;
}
