#include<bits/stdc++.h>
#include<set>
using namespace std;
int T,k;
bool z,f,zero;
int n,m,l,V,ans;
int d,v,a;
int p[100005];
struct car{
	int d,v,a;
}cars[100005];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	ans=0;
	while(T--){
		cin>>n>>m>>l>>V;
		for(int i=0;i<n;i++){
			cin>>cars[i].d>>cars[i].v>>cars[i].a;
			if(cars[i].a<0) z=1;
			if(cars[i].a>0) f=1;
			if(cars[i].a!=0) zero=1;
		}
		for(int i=0;i<m;i++) cin>>p[i];
		for(int i=0;i<n;i++){
			if(zero==0){
				if(cars[i].d<=p[m-1] and cars[i].v>V){
					ans++;
				}
				continue;
			}
			double v0=cars[i].v;
			double a_2=2*cars[i].a;
			double s=p[m-1]-cars[i].d;
			
			if(cars[i].d<=p[m-1] and cars[i].v>V){
				ans++;

			}else if(cars[i].d<=p[m-1] and sqrt(v0*v0+a_2*s)>V){
				ans++;
				continue;
			}
			
		}
	    cout<<ans<<" ";
	    ans=0;
	    if(z==0 or zero==0){
			printf("%d\n",m-1);
			continue;
		}
	}
	return 0;
}
