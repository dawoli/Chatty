#include<iostream>
using namespace std;
int n,a[5][20],ans=0;	
string s[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","out",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		int k;
		int j;
		if(s[i][0]=='D')
			k=1;
		else if(s[i][0]=='C')
			k=2;
		else if(s[i][0]=='H')
			k=3;
		else if(s[i][0]=='S')
			k=4;
		if(s[i][1]=='T')
			j=10;
		else if(s[i][1]=='J')
			j=11;		
		else if(s[i][1]=='Q')
			j=12;
		else if(s[i][1]=='K')
			j=13;
		else if(s[i][1]=='A')
			j=1;
		else
			j=s[i][1]-48;	
		a[k][j]=1;		
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(a[i][j]==0)
				ans++;
		}
	} 
	cout<<ans;
	return 0;
} 
