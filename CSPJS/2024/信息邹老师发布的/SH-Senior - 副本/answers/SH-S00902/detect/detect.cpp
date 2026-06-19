#include<bits/stdc++.h>

using namespace std;

ifstream fin("detect.in");
ofstream fout("detect.out");
#define cin fin
#define cout fout

#define int long long
const int N=1e6+9;
const int inf=1e18;

int d[N],v[N],a[N],b[N],n,m,len,lim,ans,cnt;
vector<int> qry[N];
void Insert(int x,int y){
	int l=lower_bound(b+1,b+m+1,x)-b;
	int r=upper_bound(b+1,b+m+1,y)-b-1;
	if(l>r) return ;
	qry[r].push_back(l);
	ans++;
//	cout<<x<<' '<<y<<" : "<<l<<' '<<r<<endl;
}

signed main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>len>>lim;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		sort(b+1,b+m+1);
		
		ans=0;
		for(int i=1;i<=n;i++){
			if(!a[i]){
				if(v[i]<=lim) continue ;
				Insert(d[i],inf);
			}else if(a[i]>0){
				int dis=lim*lim-v[i]*v[i];
				if(v[i]>lim) Insert(d[i],inf);	
				else{
					dis=dis/(2*a[i])+d[i]+1;
					Insert(dis,inf);
				}
			}else{
				int dis=v[i]*v[i]-lim*lim;
				a[i]=-a[i];
				if(v[i]<=lim) continue ;
				else{
					dis=(dis+2*a[i]-1)/(2*a[i])+d[i]-1;
//					cout<<dis-d[i]<<endl;
					Insert(d[i],dis);
				}
			}
		}
		cout<<ans<<' ';
		
		cnt=0;
		for(int i=1,pos=0;i<=m;i++){
			for(int j:qry[i]) if(pos<j) pos=i,cnt++;
			qry[i].clear();
		}
		cout<<m-cnt<<endl;
	}
	
	return 0;
} 
