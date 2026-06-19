#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=100010;
ll T,n,ans;
ll a[3][MaxN];
priority_queue<ll>dq[3];
inline ll readi(){
	char rc;ll rx;
	for(rc=getchar();(rc<'0')||('9'<rc);rc=getchar());
	for(rx=0;('0'<=rc)&&(rc<='9');rc=getchar())
		rx=rx*10+(rc^'0');
	return rx;
}
int main(){
	ll rx,ry,rz;
	//*/
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//*/
	T=readi();
	while(T-->0){
		ans=0;
		for(ll i=0;i<=2;i++)
			while(!dq[i].empty())
				dq[i].pop();
		n=readi();
		for(ll i=1;i<=n;i++){
			a[0][i]=readi();a[1][i]=readi();a[2][i]=readi();
			rx=max(a[0][i],max(a[1][i],a[2][i]));
			ry=0;
			if(a[1][i]==rx)
				ry=1;
			if(a[2][i]==rx)
				ry=2;
			ans+=rx;
			rz=-0x3f3f3f3f3f3f3f3f;
			if(ry!=0)
				rz=max(rz,a[0][i]-rx);
			if(ry!=1)
				rz=max(rz,a[1][i]-rx);
			if(ry!=2)
				rz=max(rz,a[2][i]-rx);
			dq[ry].push(rz);
		}
		ry=-1;
		if(((ll)dq[0].size())>(n>>1))
			ry=0;
		if(((ll)dq[1].size())>(n>>1))
			ry=1;
		if(((ll)dq[2].size())>(n>>1))
			ry=2;
		if(ry!=-1){
			while(((ll)dq[ry].size())>(n>>1)){
				ans+=dq[ry].top();
				dq[ry].pop();
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
