#include<bits/stdc++.h>
using namespace std;
int f[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		int c,d;
		if(a=='D')c=0;
		if(a=='C')c=1;
		if(a=='H')c=2;
		if(a=='S')c=3;
		if(b=='A')d=0;
		if(b=='2')d=1;
		if(b=='3')d=2;
		if(b=='4')d=3;
		if(b=='5')d=4;
		if(b=='6')d=5;
		if(b=='7')d=6;
		if(b=='8')d=7;
		if(b=='9')d=8;
		if(b=='T')d=9;
		if(b=='J')d=10;
		if(b=='Q')d=11;
		if(b=='K')d=12;
		f[13*c+d]=1;
	}
	int cnt=0;
	for(int i=0;i<=51;i++){
		if(f[i]==0)cnt++;
	}
	cout<<cnt;
	return 0;
}
