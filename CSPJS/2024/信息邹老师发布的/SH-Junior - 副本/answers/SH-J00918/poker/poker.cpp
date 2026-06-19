#include<bits/stdc++.h>
using namespace std;

int n,cnt;
bool vis[10][20];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c,num;
		int cc,x;
		cin>>c>>num;
		if(c=='D')cc=1;
		if(c=='C')cc=2;
		if(c=='H')cc=3;
		if(c=='S')cc=4;
		
		if(num=='A')x=1;
		else if(num=='T')x=10;
		else if(num=='J')x=11;
		else if(num=='Q')x=12;
		else if(num=='K')x=13;
		else x=num-'0';
		
		vis[cc][x]=true;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(vis[i][j]==false)cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
