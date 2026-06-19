#include<bits/stdc++.h>
using namespace std;
bool pokers[4][13];
int cnt=52,n;
int x,y;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		getchar();
		x=getchar();
		if(x=='S') x=0;
		else if(x=='C') x=1;
		else if(x=='D') x=2;
		else x=3;
		y=getchar();
		if(y=='A') y=1;
		else if(y=='T') y=10;
		else if(y=='J') y=11;
		else if(y=='Q') y=12;
		else if(y=='K') y=13;
		else y-='0';
		--y;
		if(!pokers[x][y]){
			pokers[x][y]=true;
			--cnt;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
