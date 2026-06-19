#include<bits/stdc++.h>
using namespace std;
int n;
int r[100010],cnt[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	int cnt1=0,cnt2=0;
	r[n+1]=1000000;
	for(int i=1;i<=n;i++){
		cnt1++;
		if(r[i]<r[i+1]){
			cnt2++;
			cnt[cnt2]=cnt1;
			cnt1=0;
		}
	}
	for(int i=2;i<=cnt2;i++){
		int left=cnt[i];
		for(int j=i;j>1;j--){
			if(left==0){
				break;
			}
			
			if(cnt[j-1]>=cnt[i]){
				cnt[j-1]-=left;
				left=0;
			}else if(cnt[j-1]<cnt[i]){
				if(left>=cnt[j-1]){
					left-=cnt[j-1];
					cnt[j-1]=0;
					
				}else if(left<cnt[j-1]){
					cnt[j-1]-=left;
					left=0;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=cnt[i];
	}
	cout<<ans;
	return 0;
}
