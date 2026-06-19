#include<bits/stdc++.h>
using namespace std;
//define int long long
typedef long long ll;
#define fr(asd,fgh,i) for(int i=asd,i##end=fgh;i<=i##end;++i)
#define rf(asd,fgh,i) for(int i=asd,i##end=fgh;i>=i##end;--i)
#define maxn 100007
struct p{
	int d1,d2,d3,ij;
	int op=0;int der;
}a[maxn];
bool cmpp(p x,p y){
	return x.der<y.der;
}

int t,n,lim;
struct qqq{int ij;int val;}w[5];bool cmp(qqq x,qqq y){return x.val>y.val;}

int all[5];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	
	cin>>t;
	while(t--){
		fr(1,3,i) all[i]=0;
		cin>>n;lim=n/2;
		ll ans=0;
		fr(1,n,i){a[i].ij=i;
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			w[1].ij=1,w[2].ij=2,w[3].ij=3;
			w[1].val=a[i].d1,w[2].val=a[i].d2,w[3].val=a[i].d3;
			sort(w+1,w+4,cmp);
			a[i].der=w[1].val-w[2].val;ans+=w[1].val;
			all[w[1].ij]++;a[i].op=w[1].ij;
			
		}int c=0;
		if(all[1]>lim) c=1;
		if(all[2]>lim) c=2;
		if(all[3]>lim) c=3;
		if(!c){
			printf("%lld\n",ans);continue;
		}
		sort(a+1,a+n+1,cmpp);
		fr(1,n,i){
			if(a[i].op==c){
				ans-=a[i].der;all[c]--;
			}
			if(all[c]<=lim) break;
		}printf("%lld\n",ans);
	}
	
	return 0;
} 
