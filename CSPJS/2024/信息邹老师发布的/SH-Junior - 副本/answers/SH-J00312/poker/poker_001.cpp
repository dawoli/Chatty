#include<bits/stdc++.h>
using namespace std;

bool arr[10][20];
string s;
int n;
int num;
int a,b;

int main()
{
	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		
		if(s[0]=='D') a=1;
		else if(s[0]=='C') a=2;
		else if(s[0]=='H') a=3;
		else			   a=4;
		
		if(s[1]=='A') b=1;
		else if(s[1]=='T') b=10;
		else if(s[1]=='J') b=11;
		else if(s[1]=='Q') b=12;
		else if(s[1]=='K') b=13;
		else 			   b=s[1]-'0';
		
		if(!arr[a][b]) num++;
		arr[a][b]=1;
	}
	num=52-num;
	cout<<num<<endl;
	return 0;
}
