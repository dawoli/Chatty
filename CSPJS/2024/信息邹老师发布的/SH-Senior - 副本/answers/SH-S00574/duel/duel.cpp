#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,ans;
map<int,int>cnt,kick;
void solve(){
	cin>>n;ans=n;
	for(int i=0,r;i<n;++i){
		cin>>r;
		++cnt[r];++kick[r];
	}
	map<int,int>::iterator it1=cnt.begin(),it2=kick.begin();
	int i=1,j=1;
	while(it2!=kick.end()){
		if(it2->second==0||i==j)++it2,++j;
		if(it2==kick.end())break;
		if(it1->second<=it2->second){
			ans-=it1->second;
			it2->second-=it1->second;
			++it1,++i;
		}else{
			ans-=it2->second;
			it1->second-=it2->second;
			++it2,++j;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}

