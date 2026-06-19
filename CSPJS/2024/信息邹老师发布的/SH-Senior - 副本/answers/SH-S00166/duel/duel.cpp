#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int a[maxn],cnt[maxn];
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
//	sort(a+1,a+n+1);
	int ans=n;
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
	}
	int pre=-1,cnts=0;
	for(int i=1;i<=100000;i++){
		if(cnt[i]>0){
			//cout<<i<<" "<<cnt[i]<<" "<<pre<<" "<<cnt[pre]<<endl;
			if(pre==-1){
				pre=i;
				cnts+=cnt[i];
				continue;
			}
			if(cnt[i]>=cnts){
				ans-=cnts;
				cnts=cnt[i];
			//	pre=i;
			}
			else{
				ans-=cnt[i];
			//	pre=i;
			}
		}

	}
	cout<<ans<<endl;
	return 0;
}

