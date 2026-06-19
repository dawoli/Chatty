#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
int t,n,a[N],b[N],c[N],y[N],x[5],cnt,summ;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;cnt=0;summ=0;x[1]=0;x[2]=0;x[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				x[1]++;summ+=a[i];
			}
			else if(b[i]>=c[i]&&b[i]>=a[i]){
				x[2]++;summ+=b[i];
			}
			else if(c[i]>=a[i]&&c[i]>=b[i]){
				x[3]++;summ+=c[i];
			}
		}
		if(x[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i]>=b[i]&&a[i]>=c[i]){
					y[++cnt]=a[i]-max(b[i],c[i]);
				}
			}
			sort(y+1,y+cnt+1);
			for(int i=1;i<=x[1]-n/2;i++) summ-=y[i];
		}
		else if(x[2]>n/2){
			for(int i=1;i<=n;i++){
				if(b[i]>=a[i]&&b[i]>=c[i]){
					y[++cnt]=b[i]-max(a[i],c[i]);
				}
			}
			sort(y+1,y+cnt+1);
			for(int i=1;i<=x[2]-n/2;i++) summ-=y[i];
		}
		else if(x[3]>n/2){
			for(int i=1;i<=n;i++){
				if(c[i]>=b[i]&&c[i]>=a[i]){
					y[++cnt]=c[i]-max(b[i],a[i]);
				}
			}
			sort(y+1,y+cnt+1);
			for(int i=1;i<=x[3]-n/2;i++) summ-=y[i];
		}
		cout<<summ<<endl;
	}
	return 0;
}
