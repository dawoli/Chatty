#include <bits/stdc++.h>
using namespace std;
int n,f[60][4],x,y,cnt;
char a,b;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		a=s[0],b=s[1];
		
		if(a=='D')x=1;
		if(a=='C')x=2;
		if(a=='H')x=3;
		if(a=='S')x=4;
		if(b=='A')y=1;
		else if(b=='T')y=10;
		else if(b=='J')y=11;
		else if(b=='Q')y=12;
		else if(b=='K')y=13;
		else y=int(b)-48;
		f[y][x]++;
	}
	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(f[j][i]==0)cnt++;
		}
	}
	cout<<cnt; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
