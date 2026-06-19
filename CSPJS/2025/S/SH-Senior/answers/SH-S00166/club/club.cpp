#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt=0;
ll t;
ll n;
ll d;
ll a[100009],b[100009],c[100009];
ll aa[100009];
ll bb[100009];
ll cc[100009];
bool cmp(const int a,const int b){
	return a>b;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	cin>>t;
	while(t--){	
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		memset(cc,0,sizeof(cc));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cnt=0;
		cin>>n;
		d=n/2;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		ll x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			if(a[i]==max(a[i],max(b[i],c[i])))x++,cnt+=a[i],aa[x]=min(a[i]-b[i],a[i]-c[i]);
			else if(b[i]==max(a[i],max(b[i],c[i])))y++,cnt+=b[i],bb[y]=min(b[i]-a[i],b[i]-c[i]);
			else z++,cnt+=c[i],cc[z]=min(c[i]-b[i],c[i]-a[i]);
		}
		if(x>d){
			sort(aa+1,aa+1+x);
			for(int i=1;i<=x-d;i++)cnt-=aa[i];
			cout<<cnt;
		}
		else if(y>d){
			sort(bb+1,bb+1+y);
			for(int i=1;i<=y-d;i++)cnt-=bb[i];
			cout<<cnt;
		}
		else if(z>d){
			sort(cc+1,cc+1+z);
			for(int i=1;i<=z-d;i++)cnt-=cc[i];
			cout<<cnt;
		}
		else cout<<cnt;
		cout<<endl;
	}
	return 0;
}
