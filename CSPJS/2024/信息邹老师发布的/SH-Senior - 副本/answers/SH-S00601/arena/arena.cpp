#include<bits/stdc++.h>
#define N 100002
#define K 19
#define POW2K 131074
using namespace std;
typedef long long ll;
ll n,m,a1[N],x[4],a[N],logx[POW2K],k,t,ans,mem[K],person[POW2K];
bool d[K][POW2K],A=1,B=1;
struct query{
	ll c,id;
	bool operator<(const query&p)const{
		return c<p.c;
	}
}q[N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	for(ll i=2;i<POW2K;++i)logx[i]=logx[i/2]+1;
	cin>>n>>m;
	for(ll i=1;i<=n;++i)cin>>a1[i];
	for(ll i=1;i<=m;++i){
		cin>>q[i].c;
		q[i].id=i;
		if((1<<logx[q[i].c])!=q[i].c)A=0;
	}
	sort(q+1,q+m+1);
	q[0].c=0;
	if((1<<logx[n])!=n)k=logx[n]+1;
	else k=logx[n];
	for(ll i=1;i<=k;++i){
		string s;
		cin>>s;
		ll p=s.size();
		for(ll j=0;j<p;++j){
			d[i][j+1]=(s[j]=='1');
			if(d[i][j+1])B=0;
		}
	}
	cin>>t;
	for(ll p=1;p<=t;++p){
		ans=0;
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(ll i=1;i<=n;++i)a[i]=a1[i]^x[i%4];
		if(A){
			ll l=1;
			mem[0]=1;
			while(q[l].c==1){
				ans^=q[l].id;
				++l;
			}
			for(ll i=1;i<=logx[q[m].c];++i){
				ll y=1<<i-1,cnt=1,winnerid=n+1;
				for(ll j=y+1;j<=y*2;++j)person[j]=j;
				while(y>1){
					for(ll j=(1<<i-1)+1;j<=y+(1<<i-1);j+=2){
						ll winner;
						if(d[cnt][j/2+1]&&a[person[j+1]]>=cnt||(!d[cnt][j/2+1])&&a[person[j]]<cnt)winner=person[j+1];
						else winner=person[j];
						person[j/2+1]=winner;
						winnerid=min(winnerid,j/2+1);
					}
					++cnt;
					y>>=1;
				}
				if(d[cnt][1]&&a[person[winnerid]]>=cnt||(!d[cnt][1])&&a[mem[i-1]]<cnt)mem[i]=person[winnerid];
				else mem[i]=mem[i-1];
				while(l<=m&&q[l].c==(1<<i)){
					ans^=q[l].id*mem[i];
					++l;
				}
				if(l>m)break;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
