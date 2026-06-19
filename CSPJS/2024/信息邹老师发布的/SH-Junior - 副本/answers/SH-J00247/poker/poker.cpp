#include<bits/stdc++.h>
using namespace std;
int n; 
bool a[100];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char x,y;
		int ans=0;
		cin>>x>>y;
		if(x=='C') ans+=13;
		if(x=='H') ans+=26;
		if(x=='S') ans+=39;
		if(y>='2'&&y<='9')
		{
			ans+=(y-'0');
		}
		if(y=='A') ans+=1;
		if(y=='T') ans+=10;
		if(y=='J') ans+=11;
		if(y=='Q') ans+=12;
		if(y=='K') ans+=13;
		a[ans]=1;
	}
	int cnt=0;
	for(int i=1;i<=52;i++)
	{
		if(a[i]==0)
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
