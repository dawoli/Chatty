#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a1[100005],a2[100005],a3[100005];
int cnt1,cnt2,cnt3;
bool flag = true;
int maxn,minn,minn12,minn13,minn23,minn21,minn31,minn32;
int ans = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans = 0;
		minn12=1e9,minn13=1e9,minn23=1e9;
		minn21=1e9,minn31=1e9,minn32=1e9;
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		for(int i = 1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0||a3[i]!=0){
				flag = false;
			}
		}
		if(flag){
			sort(a1+1,a1+n+1);
			for(int i = n;i>=n/2+1;i--){
				ans+=a1[i];
			}
		}
		else{
			for(int i = 1;i<=n;i++){
				maxn=max({a1[i],a2[i],a3[i]});
				if(maxn==a1[i]){
					minn12=min(minn12,a1[i]-a2[i]);
					minn13=min(minn13,a1[i]-a3[i]);
					if(cnt1>=n/2){
						minn=min(minn12,minn13);
						if(minn==minn12){
							cnt2++;
						}
						else{
							cnt3++;
						}
						ans-=minn;
					}
					else{
						cnt1++;
					}
				}
				else if(maxn==a2[i]){
					minn21=min(minn21,a2[i]-a1[i]);
					minn23=min(minn23,a2[i]-a3[i]);
					if(cnt2>=n/2){
						minn=min(minn21,minn23);
						if(minn==minn21){
							cnt1++;
						}
						else{
							cnt3++;
						}
						ans-=minn;
					}
					else{
						cnt2++;
					}
				}
				else if(maxn==a3[i]){
					minn31=min(minn31,a3[i]-a1[i]);
					minn32=min(minn32,a3[i]-a2[i]);
					if(cnt3>=n/2){
						minn=min(minn31,minn32);
						if(minn==minn31){
							cnt1++;
						}
						else{
							cnt2++;
						}
						ans-=minn;
					}
					else{
						cnt3++;
					}
				}
				ans+=maxn;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
