#include <bits/stdc++.h>
using namespace std;
int D[14],C[14],H[14],S[14];
char a,b;
int c;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		
		if(b=='A'){
			c=1;
		}
		if(b=='2'){
			c=2;
		}
		if(b=='3'){
			c=3;
		}
		if(b=='4'){
			c=4;
		}
		if(b=='5'){
			c=5;
		}
		if(b=='6'){
			c=6;
		}
		if(b=='7'){
			c=7;
		}
		if(b=='8'){
			c=8;
		}
		if(b=='9'){
			c=9;
		}
		if(b=='T'){
			c=10;
		}
		if(b=='J'){
			c=11;
		}
		if(b=='Q'){
			c=12;
		}
		if(b=='K'){
			c=13;
		}
		
		if(a=='D'){
			D[c]=1;
		}
		if(a=='C'){
			C[c]=1;
		}
		if(a=='H'){
			H[c]=1;
		}
		if(a=='S'){
			S[c]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=13;i++){
		if(D[i]==1){
			ans++;
		}
		if(C[i]==1){
			ans++;
		}
		if(H[i]==1){
			ans++;
		}
		if(S[i]==1){
			ans++;
		}
	}
	cout<<52-ans;
	return 0;
}
