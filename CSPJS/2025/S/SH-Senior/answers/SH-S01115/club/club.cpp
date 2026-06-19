#include<bits/stdc++.h>
using namespace std;
int T,n,cnt1,cnt2,cnt3,a[3][1000005],d[3][1000005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=cnt1=cnt2=cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			if(a[0][i]>a[1][i]&&a[0][i]>a[2][i]) d[0][++cnt1]=a[0][i]-max(a[1][i],a[2][i]);
			if(a[1][i]>a[0][i]&&a[1][i]>a[2][i]) d[1][++cnt2]=a[1][i]-max(a[0][i],a[2][i]);
			if(a[2][i]>a[1][i]&&a[2][i]>a[0][i]) d[2][++cnt3]=a[2][i]-max(a[1][i],a[0][i]);
			ans+=max(a[0][i],max(a[1][i],a[2][i]));
		}
		if(cnt1>n/2){
		    sort(d[0]+1,d[0]+cnt1+1);
		    for(int i=1;i<=cnt1-n/2;i++) ans-=d[0][i];
		}
		else if(cnt2>n/2){
			sort(d[1]+1,d[1]+cnt2+1);
			for(int i=1;i<=cnt2-n/2;i++) ans-=d[1][i];
		}
		else if(cnt3>n/2){
			sort(d[2]+1,d[2]+cnt3+1);
			for(int i=1;i<=cnt3-n/2;i++) ans-=d[2][i];
		}
		cout<<ans<<endl;
	}
}
