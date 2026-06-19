#include<bits/stdc++.h>
using namespace std;
bool d[15];
bool c[15];
bool h[15];
bool s[15];
int n,ans=52;
void solve(bool x[],char y){
	int z;
	if(int(y-'0')>=2&&int(y-'0')<=9){
		z=int(y-'0');
	}
	else if(y=='A'){
		z=1;
	}
	else if(y=='T'){
		z=10;
	}
	else if(y=='J'){
		z=11;
	}
	else if(y=='Q'){
		z=12;
	}
	else if(y=='K'){
		z=13;
	}
	if(x[z]){
		x[z]=false;
		ans--;
	}
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i = 1;i<= 13;i++){
		d[i]=true;
	}
	for(int i = 1;i<= 13;i++){
		c[i]=true;
	}
	for(int i = 1;i<= 13;i++){
		h[i]=true;
	}
	for(int i = 1;i<= 13;i++){
		s[i]=true;
	}
	for(int i= 1;i<= n;i++){
		char cha,chh;
		cin>>cha>>chh;
		if(cha=='D'){
			solve(d,chh);
		}
		if(cha=='C'){
			solve(c,chh);
		}
		if(cha=='H'){
			solve(h,chh);
		}
		if(cha=='S'){
			solve(s,chh);
		}
	}
	cout<<ans;
	return 0;
}
