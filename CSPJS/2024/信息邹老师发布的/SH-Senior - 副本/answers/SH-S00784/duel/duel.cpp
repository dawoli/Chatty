#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int n,t[N];
int f[N],ans;
map<int,int> m;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		m[x]++;
	} 
	int cnt=0;
	for(auto x=m.begin();x!=m.end();x++){
		if(x->first==0) continue;
		t[++cnt]=x->second;
		f[cnt]=x->second;
	} 
	for(int i=1;i<=cnt;i++){
		int j=i+1;
		while(t[i]>0&&j<=cnt){
			int x=min(t[i],f[j]);
			ans-=x;
			t[i]-=x;
			f[j]-=x;
			if(f[j]==0) j++;
		}
	}
	cout<<ans<<endl;
}
