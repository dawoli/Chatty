#include<bits/stdc++.h>
using namespace std;
int n,ans=52,cnt[10][20];
char a,b; 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a=='D'){
			if('2'<=b&&b<='9') if(1==++cnt[1][b-'0']) ans--;
			if(b=='A') if(1==++cnt[1][1]) ans--;
			if(b=='T') if(1==++cnt[1][10]) ans--;
			if(b=='J') if(1==++cnt[1][11]) ans--;
			if(b=='Q') if(1==++cnt[1][12]) ans--;
			if(b=='K') if(1==++cnt[1][13]) ans--;
		}else if(a=='C'){
			if('2'<=b&&b<='9') if(1==++cnt[2][b-'0']) ans--;
			if(b=='A') if(1==++cnt[2][1]) ans--;
			if(b=='T') if(1==++cnt[2][10]) ans--;
			if(b=='J') if(1==++cnt[2][11]) ans--;
			if(b=='Q') if(1==++cnt[2][12]) ans--;
			if(b=='K') if(1==++cnt[2][13]) ans--;
		}else if(a=='H'){
			if('2'<=b&&b<='9') if(1==++cnt[3][b-'0']) ans--;
			if(b=='A') if(1==++cnt[3][1]) ans--;
			if(b=='T') if(1==++cnt[3][10]) ans--;
			if(b=='J') if(1==++cnt[3][11]) ans--;
			if(b=='Q') if(1==++cnt[3][12]) ans--;
			if(b=='K') if(1==++cnt[3][13]) ans--;
		}else if(a=='S'){
			if('2'<=b&&b<='9') if(1==++cnt[4][b-'0']) ans--;
			if(b=='A') if(1==++cnt[4][1]) ans--;
			if(b=='T') if(1==++cnt[4][10]) ans--;
			if(b=='J') if(1==++cnt[4][11]) ans--;
			if(b=='Q') if(1==++cnt[4][12]) ans--;
			if(b=='K') if(1==++cnt[4][13]) ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

