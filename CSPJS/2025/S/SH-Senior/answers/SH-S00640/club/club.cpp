#include<bits/stdc++.h>
#define N ((int)(1e5)+10)
#define fir first
#define sec second
using namespace std;
typedef long long ll;
struct node{
	int vald;
	pair<int,int> val1,val2;
};
int T;
int n;
pair<int,int> a[N][5];
int cnt[N];
node res[N];
int ans;
inline bool operator > (node x,node y){
	return x.vald>y.vald;
}
inline int read(){
	int res=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')res=res*10+(c-'0'),c=getchar();
	return res;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j].fir=read();
				a[i][j].sec=j;
			}
			sort(a[i]+1,a[i]+3+1,greater<pair<int,int> >());
			res[i]={a[i][1].fir-a[i][2].fir,a[i][1],a[i][2]};
		}
		sort(res+1,res+n+1,greater<node>());
		for(int i=1;i<=n;i++){
			auto val1=res[i].val1,val2=res[i].val2;
			if(cnt[val1.sec]<n/2)ans+=val1.fir,cnt[val1.sec]++;
			else ans+=val2.fir,cnt[val2.sec]++;
		}
		printf("%d\n",ans);
	}
}

