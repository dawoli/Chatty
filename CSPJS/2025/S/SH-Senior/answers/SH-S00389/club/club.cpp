#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'&&c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct man{
	ll a,b,c;
}m[N];
struct man2{
	ll a,b;
}m2[N];
bool cmp(const man&x,const man&y){
	return x.a>y.a||x.a==y.a&&x.b<y.b||x.a==y.a&&x.b==y.b&&x.c<y.c;
}
bool cmp2(const man2&x,const man2&y){
	return x.a>y.a||x.a==y.a&&x.b<y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	t=read();
	while(t--){
		ll n,ans=0,preans=0,sum1=0,sum2=0,sum3=0;
		n=read();
		for(ll i=1;i<=n;i++){
			m[i].a=read(),m[i].b=read(),m[i].c=read();
			sum1+=m[i].a,sum2+=m[i].b,sum3+=m[i].c;
		}
		if(n==2){
			ans=max(ans,max(m[1].a+max(m[2].b,m[2].c),m[2].a+max(m[1].b,m[1].c)));
			ans=max(ans,max(m[1].b+max(m[2].a,m[2].c),m[2].b+max(m[1].a,m[1].c)));
			ans=max(ans,max(m[1].c+max(m[2].b,m[2].a),m[2].c+max(m[1].b,m[1].a)));
		}
		else if(sum2+sum3==0){
			sort(m+1,m+1+n,cmp);
			for(ll i=1;i<=n/2;i++)
				ans+=m[i].a;
		}
		else if(sum3==0){
			for(ll j=1;j<=n;j++)
				m2[j].a=m[j].a,m2[j].b=m[j].b;
			sort(m2+1,m2+1+n,cmp2);
			ll addans=0,pre[N],suf[N];
			pre[1]=m2[1].a;
			for(ll j=2;j<=n;j++)
				pre[j]=m2[j].a+pre[j-1];
			suf[n]=m2[n].b;
			for(ll j=n-1;j>0;j--)
				suf[j]=m2[j].b+suf[j+1];
			for(int j=1;j<1+n/2;j++)
				addans=max(addans,pre[j]+suf[j+1]);
			ans=max(ans,preans+addans);
		}
		else{
			sort(m+1,m+1+n,cmp);
			for(ll i=1;i<=n/2;i++){
				preans+=m[i].a;
				for(ll j=i+1;j<=n;j++)
					m2[j].a=m[j].b,m2[j].b=m[j].c;
				sort(m2+1+i,m2+1+n,cmp2);
				ll addans=0,pre[N],suf[N];
				pre[i+1]=m2[i+1].a;
				for(ll j=i+2;j<=n;j++)
					pre[j]=m2[j].a+pre[j-1];
				suf[n]=m2[n].b;
				for(ll j=n-1;j>i;j--)
					suf[j]=m2[j].b+suf[j+1];
				for(int j=i+1;j<1+n/2+i;j++)
					addans=max(addans,pre[j]+suf[j+1]);
				ans=max(ans,preans+addans);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
