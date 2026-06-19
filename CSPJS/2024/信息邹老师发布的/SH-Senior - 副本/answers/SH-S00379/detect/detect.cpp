#include <bits/stdc++.h>
using namespace std;
long long t,n,m,l,vmax,sum,ans;
int d[100005],a[100005],v[100005],p[100005],maxp;
bool cam[1000005],camon[1000005];
struct NODE{
	int si;
	vector<int> g;
}need[100005];

bool cmp(NODE x, NODE y){
	return x.si<y.si;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		sum=0;ans=0,maxp=0;
//		memset(need.si ,sizeof(need.si),0);
		memset(camon,sizeof(camon),0);
		int pos=0;
		cin>>n>>m>>l>>vmax;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			cam[p[i]]=1;
			maxp=max(maxp,p[i]);
		}
		for(int i=1;i<=n;i++){
			if(d[i]<=maxp){
				if(a[i]==0){
					if(v[i]>vmax){
						pos++;
						for(int temp=d[i];temp<=maxp;temp++){
							if(cam[temp]) need[pos].g.push_back(temp);
						}
						if(!need[pos].g.empty()) need[pos].si=need[pos].g.size(),sum++;
						else pos--;
					}
				}else if(a[i]<0){
					if(v[i]>vmax){
						int ri=d[i]+ceil((v[i]*v[i]-vmax*vmax)/(-2*a[i]))-1;
						pos++;
						for(int temp=d[i];temp<=min(ri,maxp);temp++){
							if(cam[temp]) need[pos].g.push_back(temp);
						}
						if(!need[pos].g.empty()) need[pos].si=need[pos].g.size(),sum++;
						else pos--;
					}
				}else if(a[i]>0){
					if(v[i]>=vmax){
						pos++;
						for(int temp=d[i];temp<=maxp;temp++){
							if(cam[temp]) need[pos].g.push_back(temp);
						}
						if(!need[pos].g.empty()) need[pos].si=need[pos].g.size(),sum++;
						else pos--;
					}else{
						int le=d[i]+(vmax*vmax-v[i]*v[i])/(2*a[i])+1;
						pos++;
						for(int temp=le;temp<=maxp;temp++){
							if(cam[temp]) need[pos].g.push_back(temp);
						}
						
						if(!need[pos].g.empty()) need[pos].si=need[pos].g.size(),sum++;
						else pos--;
					}
				}
			}
		}
		cout<<pos<<" ";
		sort(need+1,need+1+pos,cmp);
		for(int i=1;i<=pos;i++){
			bool flag=0;
			for(int j=0;j<need[i].si;j++){
				if(!camon[need[i].g[j]]&&!flag){
					camon[need[i].g[j]]=1;
					ans++;flag=1;
				}
			}
		}
		for(int i=1;i<=pos;i++){
			need[i].si=0;
			need[i].g.clear();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
