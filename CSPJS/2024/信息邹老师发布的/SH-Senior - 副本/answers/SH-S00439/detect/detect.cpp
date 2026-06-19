#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const ll MaxN=100010;
ll sttx,h;
bool stty;
ll T,n,m,vl,vv;
ll ansa,ansb,visl;
ll a[MaxN];
ll b[MaxN];
ll ra[MaxN];
ll rb[MaxN];
ll sd[MaxN];
ll sv[MaxN];
ll ac[MaxN];
ll lft[MaxN];
ll rgt[MaxN];
bitset<MaxN>vis;
ll&readw(){
	char c;
	while((((c=getchar())<'0')||(c>'9'))&&(c!='-'));
	stty=(c=='-');
	if(stty)
		c=getchar();
	sttx=c-'0';
	while(('0'<=(c=getchar()))&&(c<='9'))
		sttx=sttx*10+c-'0';
	if(stty)
		sttx*=-1;
	return sttx;
}
bool cmp(ll rx,ll ry){
	return lft[rx]<=ry;
}
bool lcmp(ll rx,ll ry){
	return lft[rx]<lft[ry];
}
bool rcmp(ll rx,ll ry){
	return rgt[rx]<rgt[ry];
}
inline lf fow(ll rx,ll ry){
	return (lf)(vv*vv-rx*rx)/(2*ry);
}
int main(){
	ll rx,ry;
	//*/
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	//*/
	T=readw();
	while(T-->0){
		ansa=0;ansb=0;visl=1;
		vis.reset();
		n=readw();m=readw();vl=readw();vv=readw();
		for(ll i=1;i<=n;i++){
			sd[i]=readw();sv[i]=readw();ac[i]=readw();
		}
		for(ll i=1;i<=m;i++)
			b[i]=readw();
		for(ll i=1;i<=n;i++){
			if((sv[i]<=vv)&&(ac[i]<=0))
				continue;
			if(sd[i]>b[m])
				continue;
			if(sv[i]>vv){
				rx=lower_bound(b+1,b+m+1,sd[i])-b;
				if(ac[i]<0){
					ry=lower_bound(b+1,b+m+1,sd[i]+fow(sv[i],ac[i]))-b;
					if(rx<ry){
						ansa++;
						lft[ansa]=rx;
						rgt[ansa]=ry-1;
					}
				}else{
					ansa++;
					lft[ansa]=rx;
					rgt[ansa]=m;
				}
			}else{
				rx=upper_bound(b+1,b+m+1,sd[i]+fow(sv[i],ac[i]))-b;
				if(rx<=m){
					ansa++;
					lft[ansa]=rx;
					rgt[ansa]=m;
				}
			}
		}
		for(ll i=1;i<=ansa;i++){
			ra[i]=i;
			rb[i]=i;
		}
		sort(ra+1,ra+ansa+1,lcmp);
		sort(rb+1,rb+ansa+1,rcmp);
		for(ll i=1;i<=ansa;i++) if(!vis[rb[i]]){
			ansb++;
			rx=lower_bound(ra+1,ra+ansa+1,rgt[rb[i]],cmp)-ra-1;
			for(ll i=visl;i<=rx;i++)
				vis[ra[i]]=1;
			visl=rx+1;
		}
		printf("%lld %lld\n",ansa,m-ansb);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
