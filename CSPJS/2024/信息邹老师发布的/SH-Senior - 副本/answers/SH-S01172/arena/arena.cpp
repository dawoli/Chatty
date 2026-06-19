#include <bits/stdc++.h>
using namespace std;


long long ans,t,n,m,l,V,d[100005],v[100005],a[100005],p[100005],k[100005];


int main(){

	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>V;
		for(long long i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(long long i=0;i<m;i++){
			cin>>p[i];
		}
		sort(p,p+m);
		for(long long i=0;i<n;i++){
			long long flag=0;
			for(long long j=0;j<m;j++){
				if(d[i]<p[j]){
					p[i]=j;
					flag=1;
				}
			}
			if(flag==0){
				p[i]=0;
			}
		}
		for(long long i=0;i<n;i++){
			if(p[i]!=0&&v[i]>V){
				ans++;
			}
			if(p[i]!=0){
				for(long long j=;j<=m;j++){
					k[j]++;
				}
			}
		}
		
		sort(k,k+m);
		
		cout<<ans<<" ";
		if(k[0]>=ans){
			cout<<1<<endl;
		} else {
			cout<<ans-k[0]+1<<endl;
		}
		
	}
	return 0;
}
//记得return 0 
//不开long long见祖宗
//cin换成scanf 
