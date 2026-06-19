#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
int nowh[110],base[110];
int query(int l,int r){
	return (nowh[l]-nowh[r]*base[r-l]%mod+mod)%mod;
}
string s="abcabc";
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	nowh[s.size()]=0;
	base[0]=1;
	for(int i=1;i<=100;i++)base[i]=base[i-1]*131%mod;
	for(int i=s.size()-1;i>=0;i--){
		nowh[i]=nowh[i+1]*131+s[i];
	}
	cout<<query(1,3)<<" "<<query(4,6);
}
