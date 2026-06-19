#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][6],x,y,z,b[20005],c;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(b,0,sizeof(b));
		x=0;y=0;z=0;ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				x++;
				a[i][4]=a[i][1]-max(a[i][2],a[i][3]);
				a[i][5]=1;
			}
			else if(a[i][1]<a[i][2]&&a[i][2]>=a[i][3]){
				y++;
				a[i][4]=a[i][2]-max(a[i][1],a[i][3]);
				a[i][5]=2;
			}
			else if(a[i][1]<a[i][3]&&a[i][2]<a[i][3]){
				z++;
				a[i][4]=a[i][3]-max(a[i][2],a[i][1]);
				a[i][5]=3;
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(x>n/2){
			c=x-n/2;
			for(int i=1;i<=n;i++){
				if(a[i][5]==1)b[a[i][4]]++;
			}
		}
		else if(y>n/2){
			c=y-n/2;
			for(int i=1;i<=n;i++){
				if(a[i][5]==2)b[a[i][4]]++;
			}
		}
		else if(z>n/2){
			c=z-n/2;
			for(int i=1;i<=n;i++){
				if(a[i][5]==3)b[a[i][4]]++;
			}
		}
		for(int i=0;i<=20002;i++){
			if(b[i]>=c){
				ans-=c*i;
				c=0;
				break;
			}
			else{
				ans-=b[i]*i;
				c-=b[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
