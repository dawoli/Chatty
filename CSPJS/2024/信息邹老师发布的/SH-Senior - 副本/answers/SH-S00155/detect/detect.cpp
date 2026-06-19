#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=7010;
int T;
int n,m,l,V;
int d[N],v[N],a[N];
int p[N];
bool used[N]={0};
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		memset(used,0,sizeof(used));
		cin>>n>>m>>l>>V;
		int cnt=0;//counter for overspeed cars
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		bool speciala=0,specialb=0;
		for(int i=1;i<=n;i++){
			if(a[i]<0){
				speciala=specialb=1;
				break;
			}else if(a[i]>0) speciala=1;
		}
		if(!speciala){
			int speed=0;
			for(int i=1;i<=n;i++){
				if(v[i]>V&&d[i]<=p[m]){
					speed++;
					continue;
				}
			}
			if(speed) cout<<speed<<" "<<n-1<<"\n";
			else cout<<speed<<" "<<n<<"\n";
			continue;
		}
		if(!specialb){
			bool speed=0;
			for(int i=1;i<=n;i++){
				if(v[i]*v[i]+2*a[i]*(p[m]-d[i])>V*V&&d[i]<=p[m]){
					speed++;
					continue;
				}
			}
			if(speed) cout<<speed<<" "<<n-1;
			else cout<<speed<<" "<<n;
			continue;
		}
		queue<int> c[N];
		for(int i=1;i<=n;i++){
			int test;
			if(a[i]>=0) test=m;
			else test=lower_bound(p+1,p+1+n,d[i])-p;
			int sp=1.0*v[i]*v[i]+2*a[i]*(p[test]-d[i]);
			if(sp>V*V){
				cnt++;
				for(int j=1;j<=m;j++){
					if(d[i]>p[j]) continue;
					sp=1.0*v[i]*v[i]+2*a[i]*(p[j]-d[i]);
					if(sp>V*V) c[cnt].push(j);
				}
			}
		}
		cout<<cnt<<" ";
		int len[N];
		int pm[N];
		for(int i=1;i<=cnt;i++) len[i]=c[i].size();
		for(int i=1;i<=cnt;i++){
			int x=0,val=1e9;
			for(int j=1;j<=cnt;j++)
				if(len[j]<val) val=len[j],x=j;
			pm[i]=x;
			len[x]=1e9;
		}
//		for(int i=1;i<=n;i++) cout<<pm[i]<<' ';
//		cout<<endl;
		for(int id=1;id<=cnt;id++){
			int i=pm[id];
			int mac[N]={0},count=0;
//			cout<<i<<":";
			while(!c[i].empty()){
//				cout<<c[i].front()<<" ";
				mac[++count]=c[i].front();
				c[i].pop();
			}
			bool val=0;
			for(int j=1;j<=count;j++)
				if(used[mac[j]]==1){
					val=1;
					break;
				}
//			cout<<endl;
			if(val) continue;
			else used[mac[1]]=1;
		}
		cnt=0;
		for(int i=1;i<=m;i++)
			if(used[i]) cnt++;
		cout<<m-cnt<<"\n";
	}
	return 0;
}
/*
1
10 10 25320 235
6591 945 -38
23654 277 -6
12793 859 -39
12032 762 -27
5568 739 -122
8019 774 -21
14198 881 -36
10302 866 -25
23595 868 -209
7864 667 -31
6534 6885 8702 14146 14580 15785 20903 21785 24323 24366
*/
