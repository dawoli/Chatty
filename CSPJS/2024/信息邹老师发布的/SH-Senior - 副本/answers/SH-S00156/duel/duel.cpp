#include<bits/stdc++.h>
using namespace std;
int n,p,ans,dead,rest,r[100005],cnt[100005],num[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>r[i];
	sort(r,r+n);
	num[0]=r[0],r[n]=r[n-1]+1;
	for(int i=0;i<=n;i++){
		if(num[p]!=r[i]){
			if(p){
				if(cnt[p]-cnt[p-1]>=0){
					dead+=cnt[p-1];
					if(cnt[p]-cnt[p-1]>=rest){
						dead+=rest;
						rest=0;
					}
					else{
						dead+=cnt[p]-cnt[p-1];
						rest-=cnt[p]-cnt[p-1];
					}
				}
				else{
					rest+=cnt[p-1]-cnt[p];
					dead+=cnt[p];
				}
			}
			p++;
			num[p]=r[i];
		}
		cnt[p]++;
	}
	ans=n-dead;
	cout<<ans;
	return 0;
}
