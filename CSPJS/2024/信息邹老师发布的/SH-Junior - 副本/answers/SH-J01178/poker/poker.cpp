#include<bits/stdc++.h>
using namespace std;
bool s[6][16];
int n=0,ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char a=0,b=0;
		cin>>a>>b;
		if(a=='D'){
			a=1;
		}if(a=='C'){
			a=2;
		}if(a=='H'){
			a=3;
		}if(a=='S'){
			a=4;
		}
		if(b=='1'){
			b=1;
		}if(b=='2'){
			b=2;
		}if(b=='3'){
			b=3;
		}if(b=='4'){
			b=4;
		}if(b=='5'){
			b=5;
		}if(b=='6'){
			b=6;
		}if(b=='7'){
			b=7;
		}if(b=='8'){
			b=8;
		}if(b=='9'){
			b=9;
		}
		if(b=='T'){
			b=10;
		}if(b=='J'){
			b=11;
		}if(b=='Q'){
			b=12;
		}if(b=='K'){
			b=13;
		}
		if(s[a][b]==false){
			ans--;
			s[a][b]=true;
		}
	}
	if(ans<0){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
