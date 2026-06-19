#include<bits/stdc++.h>
using namespace std;
bool vis[7][20];
int sum=52;
int n,type,num;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D')
			type=1;
		else if(s[0]=='C')
			type=2;
		else if(s[0]=='H')
			type=3;
		else if(s[0]=='S')
			type=4;
		
		if(s[1]>='0'&&s[1]<='9')
			num=(s[1]-'0');
		else if(s[1]=='A')
			num=1;
		else if(s[1]=='T')
			num=10;
		else if(s[1]=='J')
			num=11;
		else if(s[1]=='Q')
			num=12;
		else if(s[1]=='K')
			num=13;
		
		if(!vis[type][num])
			sum--;
		vis[type][num]=1;	
	}
	cout<<sum<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
