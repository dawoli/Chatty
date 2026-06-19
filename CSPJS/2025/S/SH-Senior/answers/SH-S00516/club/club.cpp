#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll T,n,cnt[9];
struct per{
	ll d1;
	ll d2;
	ll d3;
}a[N];
ll b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ll ans=0,c=0;
		cnt[1]=0; cnt[2]=0;cnt[3]=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			ll maxx=max(a[i].d1,max(a[i].d2,a[i].d3));
			if(a[i].d1==maxx) cnt[1]++;
			else if(a[i].d2==maxx) cnt[2]++;
			else cnt[3]++;
		}
		for(ll i=1;i<=n;i++){
		   	ans+=max(a[i].d1,max(a[i].d2,a[i].d3));
		} 
		//cout<<ans<<endl;
		if(max(cnt[1],max(cnt[2],cnt[3]))<=n/2){
			//这说明一定不存在一个部门被分配多于n/2个新成员
			cout<<ans<<endl;
			//continue;
		}
		else{//至多只有一个部门有大于n/2个满意度最高的成员 
			
			if(cnt[1]>n/2){
				for(ll i=1;i<=n;i++){
					ll maxx=max(a[i].d1,max(a[i].d2,a[i].d3));
					if(a[i].d1==maxx) b[++c]=a[i].d1-max(a[i].d2,a[i].d3);
				}
				sort(b+1,b+c+1);
				//if(c!=cnt[1]) cout<<cnt[1]<<"  no1  "<<c<<endl;
				//cout<<c<<endl;
				//for(ll i=1;i<=c;i++) cout<<b[i]<<endl;
				for(ll i=1;i<=c-(n/2);i++) ans-=b[i];
				cout<<ans<<endl;
			} 
			else if(cnt[2]>n/2){
				for(ll i=1;i<=n;i++){
					ll maxx=max(a[i].d1,max(a[i].d2,a[i].d3));
					if(a[i].d2==maxx) b[++c]=a[i].d2-max(a[i].d1,a[i].d3);
				}
				sort(b+1,b+c+1);
				//if(c!=cnt[2]) cout<<cnt[2]<<"  no2  "<<c<<endl;
				//cout<<c<<endl;
				//for(ll i=1;i<=c;i++) cout<<b[i]<<endl;
				for(ll i=1;i<=c-(n/2);i++) ans-=b[i];
				cout<<ans<<endl;
			} 
			else if(cnt[3]>n/2){
				for(ll i=1;i<=n;i++){
					ll maxx=max(a[i].d1,max(a[i].d2,a[i].d3));
					if(a[i].d3==maxx) b[++c]=a[i].d3-max(a[i].d2,a[i].d1);
				}
				sort(b+1,b+c+1);
				//if(c!=cnt[3]) cout<<cnt[3]<<"  no3  "<<c<<endl;
				//cout<<c<<endl;
				//for(ll i=1;i<=c;i++) cout<<b[i]<<endl;
				for(ll i=1;i<=c-(n/2);i++) ans-=b[i];
				cout<<ans<<endl;
			}  
			
		}
	}
	return 0;
}
