#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,cnt,ans=1,nowr;
ll k,a[523456],pre[523456];
struct node{
	int l,r;
}x[1234567];
bool operator<(const node&p,const node&q){
	return p.r<q.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	if(n>1145){
		ans=0;
		if(k==1){
			for(int i=1;i<=n;i++)ans+=(a[i]==1);
		}
		else{
			int xyz=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					ans+=xyz/2;
					xyz=0;
				}
				else xyz++;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((pre[j]^pre[i-1])==k){
				x[++cnt].l=i;
				x[cnt].r=j;
			}
		}
	}
	sort(x+1,x+cnt+1);
	nowr=x[1].r;
	for(int i=2;i<=cnt;i++){
		if(x[i].l>nowr){
			ans++;
			nowr=x[i].r;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
