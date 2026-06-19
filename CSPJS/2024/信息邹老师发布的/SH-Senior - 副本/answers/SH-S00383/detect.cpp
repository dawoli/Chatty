#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=30005;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int l[N],r[N],cnt2[N];
		int v,sett[N];
		memset(cnt2,0,sizeof(cnt2));
		memset(sett,1,sizeof(sett));
		int n,m,L,V,cnt=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			int dis,v0,a;
			cin>>dis>>v0>>a;
			if(a<0){
				if(v0<=V){
					l[i]=L+1;r[i]=L+1;
				}
				if(v0>V){
					l[i]=dis;
					double dis2=(double)(V*V-v0*v0)/(2*a);
					int dis3=(int)dis2+1;
					r[i]=dis3+dis;
					sett[l[i]]=2;
					if(sett[r[i]]==1)sett[r[i]]=0;
				}
			}
			if(a==0){
				if(v0>V){
					l[i]=dis,r[i]=L;
					sett[l[i]]=2,sett[r[i]]=2;
				}
				else{
					l[i]=L+1,r[i]=L+1;
				}
			}
			if(a>0){
				if(v0>=V){
					l[i]=dis;	
					if(v0==V){
						if(sett[l[i]]==1)sett[r[i]]=0;
						else sett[l[i]]=2;
					}
					r[i]=L;
					sett[r[i]]=2;
					
				}
				if(v0<V){
					double dis2=(double)(V*V-v0*v0)/(2*a);
					int dis3=(int)dis2+1;
					l[i]=dis+dis3;
					if(sett[l[i]]==1)sett[l[i]]=0;
					if(l[i]<L){
						r[i]=L;
					}
					else r[i]=L+1;
					sett[r[i]]=2;
				}
			}
		}
		int c[N];
		for(int i=1;i<=m;i++){
			cin>>c[i];
		}
		int cnt3=0;
		int pd2[N];
		memset(pd2,0,sizeof(pd2));
		for(int i=1;i<=n;i++){
			int pd=0;
			for(int j=1;j<=m;j++){
				if(c[j]==l[i]&&sett[l[i]]==0)continue;
				if(c[j]==r[i]&&sett[r[i]]==0)continue;
				else if(l[i]<=c[j]&&r[i]>=c[j]){
					pd=1;
					
					if(pd2[i]==0){
						cnt2[j]++;
						pd2[i]=1;
					}
				}
			}
			if(pd==1)cnt++;
		}
		sort(cnt2+1,cnt2+m+1);
		int sum=0;
		for(int i=m;i>=1;i--){
			sum+=cnt2[i];
		}
		cout<<cnt<<" "<<sum<<endl;
	}
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
