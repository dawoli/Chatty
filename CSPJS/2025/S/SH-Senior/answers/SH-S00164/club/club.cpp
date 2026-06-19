#include<bits/stdc++.h>
using namespace std;
int t,a[100005][4];
int ad[100005];
int ans,rt1,rt2,rt3,cnt; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
    cin>>t;
    while(t--){
    	ans=0,rt1=0;
		rt2=0;rt3=0;
		cnt=0; 
    	int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			int mx=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=mx;
			if(mx==a[i][1]) rt1++;
			else if(mx==a[i][2]) rt2++;
			else rt3++;
		}
		int mx=max(max(rt1,rt2),rt3);
		if(mx<=n/2){
			cout<<ans<<endl;
			continue;
		}
		int nd=mx-n/2,tp;
		if(mx==rt1) tp=1;
		else if(mx==rt2) tp=2;
		else tp=3;
		for(int i=1;i<=n;i++){
			if(a[i][tp]<max(a[i][(tp+1)%3+1],a[i][(tp+2)%3+2])){
				continue;
			} 
			else if(a[i][tp]==max(a[i][(tp+1)%3+1],a[i][(tp+2)%3+2])){
				if(tp==2&&a[2]==a[3]||tp==1) nd--;
			}
			else ad[++cnt]=a[i][tp]-max(a[i][(tp+1)%3+1],a[i][(tp+2)%3+2]);
		}
		sort(ad+1,ad+cnt+1);
		for(int i=1;i<=nd;i++){
			ans-=ad[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
