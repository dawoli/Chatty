#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,q,l,r,L,R,pos;
struct node{
	string s,t;
}a[123];
bool operator<(const node&x,const node&y){
	return x.s<y.s;
}
string S,T,str;
ll ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].s>>a[i].t;
	sort(a+1,a+n+1);
	while(q--){
		l=0;r=0;ans=0;
		cin>>S>>T;
		ll len=min(S.size(),T.size());
		for(int i=0;i<len;i++){
			if(S[i]==T[i])l++;
			else break;
		}
		for(int i=0;i<len;i++){
			if(S[S.size()-i-1]==T[T.size()-i-1])r++;
			else break;
		}
		if(l+r>=len){
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<=l;i++){
			for(int j=0;j<=r;j++){
				str=S.substr(i,S.size()-i-j);
				L=1;R=n;pos=-1;
				while(L<=R){
					int mid=(L+R)/2;
					if(str==a[mid].s){
						pos=mid;
						break;
					}
					else if(str<a[mid].s)R=mid-1;
					else L=mid+1;
				}
				if(pos!=-1&&a[pos].t==T.substr(i,T.size()-i-j))ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
