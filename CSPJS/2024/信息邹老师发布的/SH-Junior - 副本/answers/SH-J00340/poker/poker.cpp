#include<bits/stdc++.h>
using namespace std;
int n;
string poke[54];
int c[14],d[14],h[14],s[14];
int need=0;
int HCP(char b){
	if(b=='A') return 1;
	else if(b=='2') return 2;
	else if(b=='3') return 3;
	else if(b=='4') return 4;
	else if(b=='5') return 5;
	else if(b=='6') return 6;
	else if(b=='7') return 7;
	else if(b=='8') return 8;
	else if(b=='9') return 9;
	else if(b=='T') return 10;
	else if(b=='J') return 11;
	else if(b=='Q') return 12;
	else return 13;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>poke[i];
	} 
	for(int i=1;i<=n;i++){
		int hcp=HCP(poke[i][1]);
		if(poke[i][0]=='C'){
			c[hcp]++;
		}
		else if(poke[i][0]=='D'){
			d[hcp]++;
		}
		else if(poke[i][0]=='H'){
			h[hcp]++;
		}
		else{
			s[hcp]++;
		}
	}
	for(int i=1;i<=13;i++){
		if(c[i]==0) need++;
	}
	for(int i=1;i<=13;i++){
		if(d[i]==0) need++;
	}
	for(int i=1;i<=13;i++){
		if(h[i]==0) need++;
	}
	for(int i=1;i<=13;i++){
		if(s[i]==0) need++;
	}
	cout<<need;
	return 0;
}
