#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int l,r,b[4],a;
	cin>>l>>r;
	for(int m=0;m<4;m++)
	{
		cin>>b[m];
	}
	a = b[0]+b[1]+b[2]+b[3];
	if(a/3>r||a/3<l)
	{
		cout<<a/3;
	}
	else{
		cout<<a%3;
	}
	return 0;
}
