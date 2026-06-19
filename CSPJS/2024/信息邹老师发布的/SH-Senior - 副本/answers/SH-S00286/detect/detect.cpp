#include<bits/stdc++.h>
using namespace std;
const int N=100007;
int n,m,L,V;
int d[N],v[N],a[N],p[N];
int l[N],r[N],s[N],last[N];
bool catched[N];
vector<int> c[N];
void solve(){
	for(int i=0;i<=N;i++)
		c[i].clear();
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++)
		cin>>d[i]>>v[i]>>a[i];
	for(int i=1;i<=m;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			if(v[i]>V){//全程超速 
				l[i]=d[i];
				r[i]=L;
			}
			else{
				double deltax=1.0*(V*V-v[i]*v[i])/(a[i]*2);
				int delx=(int)deltax;
				if(deltax-delx!=0) delx+=1;
				else if(deltax-delx==0) delx++;
				l[i]=d[i]+delx;
				r[i]=L;
			} 
		}
		else if(a[i]==0){
			if(v[i]>V){//全程超速 
				l[i]=d[i];
				r[i]=L;
			}
			else{
				l[i]=-1;
				r[i]=-1;
			}
		}
		else{
			if(v[i]<=V){//全程不超速 
				l[i]=-1;
				r[i]=-1;
			}
			else{
				double deltax=1.0*(V*V-v[i]*v[i])/(a[i]*2);
				int delx=(int)deltax;
				if(deltax-delx==0) delx--;
				l[i]=d[i];
				r[i]=d[i]+delx;
				if(r[i]>L) r[i]=L;
			}
		}
	}
	int ans=0,ans2=0;
	for(int i=1;i<=n;i++){
		bool rp=0;
		for(int j=1;j<=m;j++){
			if(l[i]<=p[j]&&r[i]>=p[j]){
				if(rp==0){
					ans++;
					rp=1;
				}
				c[j].push_back(i);
				last[i]=j;
			}
		}
	}
		
	memset(catched,0,N);
	for(int i=1;i<=m;i++){
		for(int j=0;j<c[i].size();j++){
			if(i==last[c[i][j]]&&catched[c[i][j]]==0){//这次是最后一个关卡 
				for(int j=0;j<c[i].size();j++){
					catched[c[i][j]]=1;
				}
				ans2++;
			}
		}
	}
	cout<<ans<<" "<<m-ans2<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
		solve();
	return 0;
}
