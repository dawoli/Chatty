#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,L,V,d[100005],v[100005],a[100005],p[100005],ans,monitor;
pair<int,int> tf[100005];
bool AB;
int upb(float l){
	int b=l+1;
	return b;
}
int lob(float l){
	int b=l-(float)0.01;
	return b;
}
void solve(){
	ans=0;
	monitor=0;
	AB=1;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++)tf[i]=make_pair(-1,-1);
	for(int i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
		if(a[i]<0)AB=0;
		float len=V*V-v[i]*v[i];
		if(a[i]==0){
			if(v[i]>V){
				tf[i]=make_pair(L,d[i]);
			}
		}
		else{
			len/=(2*a[i]);
			//cout<<len<<endl;
			if(a[i]<0){
				if(len>=0){
					tf[i]=make_pair(lob(len)+d[i],d[i]);
				}
			}
			else{
				if(len>=0&&len+d[i]<=L){
					//cout<<len<<" "<<d[i]<<" "<<upb(len+d[i])<<endl;
					tf[i]=make_pair(L,d[i]+upb(len));
				}
				if(len<0){
					tf[i]=make_pair(L,d[i]);
				}
			}
		}
		//cout<<tf[i].second<<" "<<tf[i].first<<endl;
	}
	sort(tf+1,tf+1+n);
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	if(AB){
		bool ifplus=0;
		for(int i=1;i<=n;i++){
			if(tf[i].first>=p[m]&&tf[i].second<=p[m]){
				ans++;
				ifplus=1;
			}
		}
		if(ifplus)monitor++;
		cout<<ans<<" "<<m-monitor<<endl;
		return;
	}
	int j=1;
	for(int i=1;i<=m;i++){
		while(p[i]>tf[j].first)j++;
		if(p[i+1]>tf[j].first||(i==m&&p[m]<=tf[j].first)){
			//cout<<p[i]<<endl;
			bool ifplus=0;
			for(int o=1;o<=n;o++){
				if(tf[o].first>=p[i]&&tf[o].second<=p[i]){
					ans++;
					//cout<<tf[o].second<<" "<<tf[o].first<<endl;
					ifplus=1;
					tf[o].first=-1;
				}
			}
			if(ifplus)monitor++;
		}
	}
	cout<<ans<<" "<<m-monitor<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)solve();
	return 0;
}
