#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt[4][14],ans=52;
string s;
ll work1(char ch){
	if(ch=='D'){
		return 0;
	}
	else if(ch=='C'){
		return 1;
	}
	else if(ch=='H'){
		return 2;
	}
	else{
		return 3;
	}
}
ll work2(char ch){
	if(ch=='A'){
		return 1;
	}
	else if(ch=='T'){
		return 10;
	}
	else if(ch=='J'){
		return 11;
	}
	else if(ch=='Q'){
		return 12;
	}
	else if(ch=='K'){
		return 13;
	}
	else{
		return ch-'0';
	}
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s;
		ll x=work1(s[0]),y=work2(s[1]);
		cnt[x][y]++;
		if(cnt[x][y]==1){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}

