#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[5010];
const int Mod=998244353;
void find(int p,int maxn,int tot){
	if(p>n){
		if(tot>2*maxn) cnt=(cnt+1)%Mod;
		return;
	}
	find(p+1,max(maxn,a[p]),tot+a[p]);
	find(p+1,maxn,tot);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	find(1,0,0);
	cout<<cnt<<endl;
	return 0;
} 
