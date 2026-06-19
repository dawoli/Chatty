#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
int d[100001],v[100001],a[100001],r[100001];
double l[100001];int ans;
bool b[100001];//该车被测过速吗 
int ci[100001];//被测过几次 
vector<int> p[100001];//每个测速测过哪几辆 
int num;
bool ov[100001]; //测速仪开关 
void dfs(int depth,int mm){
	for(int i=0;i<p[mm].size();i++){
		ci[p[mm][i]]--;
	}
	for(int i=1;i<=n;i++){
		if(!ci[i]&&b[i]){
			for(int i=0;i<p[mm].size();i++){
		ci[p[mm][i]]++;
	}
		}
		return;
	}
	for(int i=1;i<=m;i++){
		if(ov[m])continue;
		ov[m]=1;dfs(depth+1,m); ov[m]=0;
	}
	
	if(num<depth)num=depth;
}
int main(){
	//freopen("detect.in","r",stdin);
	//freopen("detect.out","w",stdout);
	int T;cin>>T;
	while(T--){
		
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			double t=(double(V*V-v[i]*v[i])/(double)(a[i]*2));if(t==(double)((int)t))t--;
			if(a[i]>=0&&v[i]>V){
				l[i]=d[i];
				r[i]=L;
			}else if(a[i]<0&&v[i]>V){
				l[i]=d[i];
				r[i]=d[i]+t;
			}else if(a[i]>0&&v[i]<V){
				l[i]=d[i]+t;
				r[i]=L;
			}
		}
		for(int i=1;i<=m;i++){
			int t;cin>>t;
			for(int j=1;j<=n;j++){
				if(t>=l[j]&&t<=r[j]){
					if(!b[j]){
						ans++;b[j]=1;
					}ci[j]++;
					p[i].push_back(j);//j车被第i个探测器测速 
					
				}
			}
		}
		dfs(0,0);
		cout<<ans<<' '<<num<<'\n';
		ans=num=0;
	}
	return 0;
} 
