#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,m,L,V;
int d[N],v[N],a[N];
double l[N],r[N];
int ll[N],rr[N];
int add[N];
int cnt;
int vis[N];
int base[N];
int Time[N];//车被time个监控拍到 
vector<int>G[N];
bool cmp(int a,int b){
	return vis[a]<vis[b];
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(base,0,sizeof(base));
		cnt=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=m;i++){
			base[i]=i;
		} 
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]==0){
				if(v[i]>V){
					l[i]=d[i];
					r[i]=L;
				}
				else{
					r[i]=-1;
				}
			}
			else if(a[i]>0){
				double t;
				t=(V-v[i])*1.0/a[i];
				double s=v[i]*t+a[i]*t*t/2;
				l[i]=s+d[i];
				r[i]=L+1;
			}
			else{
				if(v[i]>V){
					double t;
					t=(V-v[i])*1.0/a[i];
					double s=v[i]*t+a[i]*t*t/2;
					l[i]=d[i];
					r[i]=s+d[i];
				}
				else r[i]=-1;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>add[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V&&d[i]<=add[m]){
					ll[i]=lower_bound(add+1,add+1+m,d[i])-add;
					rr[i]=m;
				}
			}
			else if(a[i]>0){
				if(l[i]<=add[m]){
					ll[i]=upper_bound(add+1,add+1+m,l[i])-add;
					rr[i]=m;
				}
			}
			else{
				if(l[i]<=add[m]&&r[i]>=add[1]){
					ll[i]=lower_bound(add+1,add+1+m,l[i])-add;
					rr[i]=lower_bound(add+1,add+1+m,r[i])-add-1;
				}
			}
			if(rr[i]<ll[i]){
				rr[i]=ll[i]=0;
			}
		}
		int MinL=L+1,MaxR=-1;
		for(int i=1;i<=n;i++){
			if(ll[i]==0&&rr[i]==0){
				continue;
			}
			cnt++;
			for(int j=ll[i];j<=rr[i];j++){
				vis[j]++;
				G[j].push_back(i);//j能抓到i车 
			}
			Time[i]=rr[i]-ll[i]+1;
		}
		sort(base+1,base+1+m,cmp);
		int j=0;
		for(int i=1;i<=n;i++){//删掉第base[i]个监控 
			bool flag=0;
			for(int v:G[base[i]]){
				Time[v]--;
				if(Time[v]==0){
					flag=1;
				}
			}
			if(flag==1){
				for(int v:G[base[i]]){
					Time[v]++;
				}
			}
			if(flag==0){
				j++;
			}
		}
		cout<<cnt<<' '<<j<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
