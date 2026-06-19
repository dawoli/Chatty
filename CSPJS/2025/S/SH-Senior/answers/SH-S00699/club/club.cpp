#include <bits/stdc++.h>
using namespace std;
struct node{
	int s1,s2,s3,sf,ss,st,f,s,t;	
}a[20005];
int T,n,ans,f[4];
bool cmp(node x,node y){return (x.sf==y.sf?(x.ss==y.ss?x.st>y.st:x.ss>y.ss):x.sf>y.sf);}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T; 
	while(T--){
		ans=0,f[1]=f[2]=f[3]=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;a[i].sf=max(a[i].s1,max(a[i].s2,a[i].s3));
			if (a[i].s1==a[i].sf){
				a[i].f=1;
				if(a[i].s2>=a[i].s3)a[i].s=2,a[i].t=3,a[i].ss=a[i].s2,a[i].st=a[i].s3;
				if(a[i].s3>a[i].s2)a[i].s=3,a[i].t=2,a[i].ss=a[i].s3,a[i].st=a[i].s2;
			}
			else if (a[i].s2==a[i].sf){
				a[i].f=2;
				if(a[i].s1>=a[i].s3)a[i].s=1,a[i].t=3,a[i].ss=a[i].s1,a[i].st=a[i].s3;
				if(a[i].s3>a[i].s1)a[i].s=3,a[i].t=1,a[i].ss=a[i].s3,a[i].st=a[i].s1;
			}
			else{
				a[i].f=3;
				if(a[i].s2>=a[i].s1)a[i].s=2,a[i].t=1,a[i].ss=a[i].s2,a[i].st=a[i].s1;
				if(a[i].s1>a[i].s2)a[i].s=1,a[i].t=2,a[i].ss=a[i].s1,a[i].st=a[i].s2;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(f[a[i].f]+1>n/2){
				if (a[i].ss>a[i].sf+a[i-1].ss-a[i-1].sf && f[a[i].s]+1<=n/2)f[a[i].s]++,ans+=a[i].ss;
				else if(a[i].ss<=a[i].sf+a[i-1].ss-a[i-1].sf && f[a[i].s]+1<=n/2)f[a[i-1].s]++,f[a[i-1].f]--,f[a[i].f]++,ans+=a[i].sf+a[i-1].ss-a[i-1].sf;
				else f[a[i].t]++,ans+=a[i].st;
			}
			else f[a[i].f]++,ans+=a[i].sf;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
