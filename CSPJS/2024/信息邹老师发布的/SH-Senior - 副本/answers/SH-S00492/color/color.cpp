#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200009;
ll n,a[N],ans=0;
bool b[N];
void print(){
	ll sum=0,red=-1,blue=-1;
	for(ll i=1;i<=n;i++){
		if(b[i]==0){
			if(red==-1){
				red=i;
			}
			else{
				if(a[red]==a[i])
					sum+=a[i];
				red=i;
			}
		}
		else{
			if(blue==-1){
				blue=i;
			}
			else{
				if(a[blue]==a[i])
					sum+=a[i];
				blue=i;
			}
		}
	}
	ans=max(ans,sum);
}
void dfs(ll now){
	if(now>n){
		print();
		return;
	}
	b[now]=1;
	dfs(now+1);
	b[now]=0;
	dfs(now+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++)
			cin>>a[i];
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
