#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+10;
struct node{
	ll a,b,c,vst,cz;//a=对a的满意度 b=对b的满意度 c=对c的满意度 vst=最想报哪个 cz=差值 
}num[maxn];
ll t,n; 
bool cmp(node x,node y) {
	return x.cz<y.cz;
}
int main(){
	freopen("club5.in","r",stdin);
	freopen("club5.out","w",stdout);
	cin>>t;
	while (t--) {
		cin>>n;ll p1=0,p2=0,p3=0;
		for (ll i=1;i<=n;i++) {
			cin>>num[i].a>>num[i].b>>num[i].c;
			ll A=num[i].a,B=num[i].b,C=num[i].c;
			if (A>B&&A>C) {
				num[i].vst=1,num[i].cz=min(A-B,A-C),p1++;
			}
			else if (B>A&&B>C) num[i].vst=2,num[i].cz=min(B-A,B-C),p2++;
			else num[i].vst=3,num[i].cz=min(C-A,C-B),p3++;
		}
		sort(num+1,num+n+1,cmp);
		if (p1>n/2) {
			for (ll i=1;i<=n&&p1>n/2;i++) {
				if (num[i].vst==1) {
					p1--;
					if (num[i].b>num[i].c&&p2<n/2) p2++,num[i].vst=2;
					else p3++,num[i].vst=3;
				}
			}
		}
		if (p2>n/2) {
			for (ll i=1;i<=n&&p2>n/2;i++) {
				if (num[i].vst==2) {
					p2--;
					if (num[i].a>num[i].c&&p1<n/2) p1++,num[i].vst=1;
					else p3++,num[i].vst=3;
				}
			}
		}
		if (p3>n/2) {
			for (ll i=1;i<=n&&p3>n/2;i++) {
				if (num[i].vst==3) {
					p3--;
					if (num[i].a>num[i].b&&p1<n/2) p1++,num[i].vst=1;
					else p2++,num[i].vst=2;
				}
			}
		}
		ll ans=0;
		for (ll i=1;i<=n;i++) {
			if (num[i].vst==1)ans+=num[i].a;
			else if (num[i].vst==2) ans+=num[i].b;
			else ans+=num[i].c;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
18961      
15344 
16178    
19722       
10557
17976     
13424 
8769
9953      
16441 


*/
