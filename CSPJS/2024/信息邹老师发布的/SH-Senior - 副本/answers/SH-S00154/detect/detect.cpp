#include<bits/stdc++.h>
using namespace std;
long long la[100010],d[100010],v[100010],a[100010],p[100010],b[100010];
double eps=1e-5;
int main(){
	freopen("detect2.in","r",stdin);
	freopen("detect.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		long long n,m,l,V,ans1=0,ans2;
		cin>>n>>m>>l>>V;
		ans2=m;
		for(long long i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(long long i=1;i<=m;i++)cin>>p[i];
		for(long long i=1;i<=n;i++){
			if(a[i]==0 && v[i]>=V){
				if(d[i]<=p[m])ans1++,la[i]=m;
			}
			else if(a[i]>0){
				if(v[i]<=V){
					double so=((V+eps)*(V+eps)-v[i]*v[i])/(2*a[i])+d[i];
					if(so<=p[m])ans1++,la[i]=m;
				}
				else {
					if(d[i]<=p[m])ans1++,la[i]=m;
				}
			}
			else if(a[i]<0){
				if(v[i]>V){
					double eo=(V*V-v[i]*v[i])/(2.0*a[i])+d[i];
					long long t1=lower_bound(p+1,p+n+1,d[i])-p,t2=lower_bound(p+1,p+n+1,(long long)eo)-p;
					if((t1<t2 && p[t2]>eo))ans1++,la[i]=t2-1;
					if((t1<=t2 && p[t2]<=eo))ans1++,la[i]=t2;
					//cout<<la[i]<<" "<<t<<endl;
				}
			}
		}
		for(long long i=1;i<=n;i++){
			if(b[la[i]]==0){
				ans2--;
			}
			b[la[i]]++;
		}
		cout<<ans1<<" "<<ans2<<endl;
		memset(la,0,sizeof(la));
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(b,0,sizeof(b));
	}
	return 0;
}
