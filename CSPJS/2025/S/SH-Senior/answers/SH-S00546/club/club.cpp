#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		long long ans=0;
		cin>>n;
		int a[100005][3];
		int b[100005];
		int c[100005];
		int d[100005];
		int shu1=0,shu2=0,shu3=0;
		for(int i=1;i<=n;i++){b[i]=100000;c[i]=100000;d[i]=100000;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				shu1++;ans+=a[i][1];
				b[i]=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				shu2++;ans+=a[i][2];
				c[i]=a[i][2]-max(a[i][1],a[i][3]);
			}
			else{
				shu3++;ans+=a[i][3];
				d[i]=a[i][3]-max(a[i][2],a[i][1]);
			}
		}
		if(shu1<=n/2&&shu2<=n/2&&shu3<=n/2){
			cout<<ans<<endl;
		}
		else if(shu1>n/2){
			sort(b+1,b+1+n);
			for(int i=1;i<=shu1-n/2;i++){
				ans-=b[i];
			}
			cout<<ans<<endl;
		}
			else if(shu2>n/2){
			sort(c+1,c+1+n);
			for(int i=1;i<=shu2-n/2;i++){
				ans-=c[i];
			}
			cout<<ans<<endl;
		}
			else if(shu3>n/2){
			sort(d+1,d+1+n);
			for(int i=1;i<=shu3-n/2;i++){
				ans-=d[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
