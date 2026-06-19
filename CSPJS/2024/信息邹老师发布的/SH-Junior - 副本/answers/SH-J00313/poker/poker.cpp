#include<bits/stdc++.h>
using namespace std;
int n,co,nu,cnt;
char c1,c2;
int b[5][20]; //1fang 2cao 3hong 4hei
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c1>>c2;
		
		if(c1=='D')co=1;
		else if(c1=='C')co=2;
		else if(c1=='H')co=3;
		else if(c1=='S')co=4;
		
		if(c2>='0'&&c2<='9')nu=c2-'0';
		else if(c2=='T')nu=10;
		else if(c2=='J')nu=11;
		else if(c2=='Q')nu=12;
		else if(c2=='K')nu=13;
		
		if(!b[co][nu])
			cnt++,b[co][nu]=1;
	}
	printf("%d",52-cnt);
	return 0;
}
