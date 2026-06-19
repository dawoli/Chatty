#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int n,m,q,p,d;
}a[100009];
int n,r,t,w,e;
long long sum;
bool cmp(Edge x,Edge y){
	return x.p<y.p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		r=0,t=0,w=0,sum=0,e=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].m>>a[i].n>>a[i].q;
			if(a[i].m>=a[i].n&&a[i].m>=a[i].q) a[i].d=a[i].m;
			else if(a[i].n>=a[i].q) a[i].d=a[i].n;
			else a[i].d=a[i].q;
			int o;
			if(a[i].m<=a[i].n&&a[i].m<=a[i].q) o=a[i].m;
			else if(a[i].n<=a[i].q) o=a[i].n;
			else o=a[i].q;
			a[i].p=2*a[i].d+o-a[i].m-a[i].n-a[i].q;
			if(a[i].m==a[i].d) r++;
			if(a[i].n==a[i].d) t++;
			if(a[i].q==a[i].d) w++;
			sum+=a[i].d;
		}
		sort(a,a+n,cmp);
		if(r>(n/2)){
			while(r>(n/2)){
				if(a[e].m==a[e].d){
					r-=1;
					sum-=a[e].p;
				}
				e++;
			}
		}
		else if(t>(n/2)){
			while(t>(n/2)){
				if(a[e].n==a[e].d){
					t-=1;
					sum-=a[e].p;
				}
				e++;
			}
		}
		else if(w>(n/2)){
			while(w>(n/2)){
				if(a[e].q==a[e].d){
					w-=1;
					sum-=a[e].p;
				}
				e++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 

