#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define FOR(n) for(int i=1;i<=n;i++)
#define FORj(n) for(int j=1;j<=n;j++)
#define For(n) for(int i=0;i<n;i++)
#define Forj(n) for(int j=0;j<n;j++)
#define ci(x) cin>>x;
#define ci2(x,y) cin>>x>>y;
#define ci3(x,y,z) cin>>x>>y>>z;
#define cr(x) cout<<x<<endl;
#define cr2(x,y) cout<<x<<' '<<y<<endl;
#define cr3(x,y,z) cout<<x<<' '<<y<<' '<<z<<endl;
#define INF (100000000000000009ll)
const int N=1e5+9;
int a[N][4];
int ah[N],bh[N],ch[N];
int n; 
int as,bs,cs,ans;
void h0peakioi() {
	as=bs=cs=ans=0;
	ci(n)
	FOR(n)ah[i]=bh[i]=ch[i]=INF;
	FOR(n) {
		ci3(a[i][1],a[i][2],a[i][3])
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			as++;
			ah[i]=(a[i][1]-max(a[i][2],a[i][3]));
			ans+=a[i][1];
		}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			bs++;
			ans+=a[i][2];
			bh[i]=(a[i][2]-max(a[i][1],a[i][3]));
		}else{
			cs++;
			ans+=a[i][3];
			ch[i]=(a[i][3]-max(a[i][2],a[i][1]));
		}
	}
//	cr3(as,bs,cs)
//	cr2("tx",ans)
	sort(ah+1,ah+n+1);
	sort(bh+1,bh+n+1);
	sort(ch+1,ch+n+1);
//	FOR(n){
//		cr3(ah[i],bh[i],ch[i])
//	}
	if(as>n/2){
		FOR(n){
			ans-=ah[i];
			as--;
			if(as<=n/2){
				cr(ans)
				return;
			}
		}
	}else if(bs>n/2){
		FOR(n){
			ans-=bh[i];
			bs--;
			if(bs<=n/2){
				cr(ans)
				return;
			}
		}
	}else if(cs>n/2){
		FOR(n){
			ans-=ch[i];
//			cr3("ans-=",i,ch[i])
			cs--;
			if(cs<=n/2){
				cr(ans)
				return;
			}
		}
	}else{
		cr(ans)
		return;
	}
	
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int TOT=1;
	ci(TOT)
// 多册吗 清空了吗
// 文件开了吗
	while(TOT--)h0peakioi();
}
