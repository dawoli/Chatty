#include <bits/stdc++.h>
using namespace std;
int n,a,b,x[15][25],cnt;
char aa,bb;
int main(){
	freopen("poker.in ","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("\n%c%c",&aa,&bb);
		if(aa=='D'){
			a=1;
		}
		if(aa=='C'){
			a=2;
		}
		if(aa=='H'){
			a=3;
		}
		if(aa=='S'){
			a=4;
		}
		if(bb>='0'&&bb<='9'){
			b=bb-'0';
		}
		else if(bb=='A'){
			b=1;
		}
		else if(bb=='T'){
			b=10;
		}
		else if(bb=='J'){
			b=11;
		}
		else if(bb=='Q'){
			b=12;
		}
		else{
			b=13;
		}
		x[a][b]=1;
	}
	for(int i=1;i<5;++i){
		for(int j=1;j<14;++j){
			if(!x[i][j]){
				++cnt;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
