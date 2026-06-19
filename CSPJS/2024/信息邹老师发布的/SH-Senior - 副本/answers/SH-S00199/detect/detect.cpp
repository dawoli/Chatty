#include<bits/stdc++.h>
using namespace std;
long long n,m,L,V,t;
long long d[1000010],v[1000010],a[1000010],p[1000010],sudu[1000010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(long long tt=1;tt<=t;tt++){
		long long ansc=0,ansg=0,cntg=0;
		cin>>n>>m>>L>>V;
		for(long long i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			
		}
		if(a[1]==0){
			for(long long i=1;i<=m;i++)cin>>p[i];
			for(long long i=1;i<=n;i++){
				if(v[i]>V && d[i]<=p[m]){
					ansc++;
						
				}
			}
			if(ansc!=0)ansg=m-1;
			else ansg=m;
			cout<<ansc<<" "<<ansg<<endl;
		}else{
			for(long long i=1;i<=m;i++)cin>>p[i];
			for(long long i=1;i<=n;i++){
				sudu[i]=v[i]*v[i]+2*a[i]*(p[m]-d[i]);
				if(sudu[i]>V*V && d[i]<=p[m]){
					ansc++;
				}
			}
			if(ansc!=0)ansg=m-1;
			else ansg=m;
			cout<<ansc<<" "<<ansg<<endl;
			
		}
		
	}
	
	return 0;
}
