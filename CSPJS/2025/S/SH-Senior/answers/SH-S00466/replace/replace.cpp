#include<bits/stdc++.h>
#define compchar(rca,rcb) (((rca)-'a')*26)+(rcb)-'a'+1
using namespace std;
typedef long long ll;
const ll MaxN=5000010;
ll n,m,sn,nn,ans;
ll cl[MaxN];
ll nfil[MaxN];
ll pe[MaxN];
ll qe[MaxN];
ll cnt[MaxN];
ll dis[MaxN];
char sa[MaxN];
char sb[MaxN];
queue<ll>dq;
unordered_map<ll,ll>sun;
int main(){
	ll rx,ry;
	//*/
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//*/
	scanf("%lld%lld",&n,&m);
	for(ll u,i=1;i<=n;i++){
		scanf("%s%s",sa+1,sb+1);
		if(!strcmp(sa+1,sb+1))
			continue;
		u=0;
		for(ll j,i=1;sa[i];i++){
			j=(u*680)+compchar(sa[i],sb[i]);
			if(!sun[j]){
				sun[j]=++nn;
				pe[nn]=u;
				cl[nn]=compchar(sa[i],sb[i]);
				dis[nn]=dis[u]+1;
			}
			u=sun[j];
		}
		cnt[u]++;
	}
	for(ll c=1;c<=679;c++)
		if(sun.count(c))
			dq.push(sun[c]);
	for(ll u,j;!dq.empty();){
		u=dq.front();dq.pop();
		if(pe[u]>0)
			nfil[u]=sun[(nfil[pe[u]]*680)+cl[u]];
		cnt[u]+=cnt[nfil[u]];
		for(ll c=1;c<=679;c++){
			j=(u*680)+c;
			if(sun[j]>0){
				dq.push(sun[j]);
			}else{
				sun[j]=sun[(nfil[u]*680)+c];
			}
		}
	}
	for(ll u;m-->0;){
		ans=0;
		scanf("%s%s",sa+1,sb+1);
		sn=strlen(sa+1);
		if(sn!=((ll)strlen(sb+1))){
			puts("0");
			continue;
		}
		for(rx=1;sa[rx]==sb[rx];rx++);
		for(ry=sn;sa[ry]==sb[ry];ry--);
		u=0;
		for(ll i=1;i<=sn;i++){
			u=sun[(u*680)+compchar(sa[i],sb[i])];
			if((i>=ry)&&(i-dis[u]<=rx))
				ans+=cnt[u];
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
