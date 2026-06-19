#include<bits/stdc++.h>
#define HohleFeuerwerke using namespace std
#define int long long
HohleFeuerwerke;
inline int read(){
	int s=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s*f;
}
const int MAXN=1e6+5;
int n,ans,a[MAXN];
inline int ksm(int a,int b){
	if(b==0) return 1;
	else if(b%2==1) return a*ksm(a,b-1);
	else{int tmp=ksm(a,b/2);return tmp*tmp;}
}
namespace subtask1{
	inline void solve(){
		for(int status=0;status<ksm(2,n-1);status++){
			int new0=0,new1=0,cur,curans=0;
			for(int i=1;i<=n;i++){
				if(status&(1<<(i-1))) cur=1;
				else cur=0;
				if(cur==1){
					if(new1==0) curans+=0;
					else if(a[new1]==a[i]) curans+=a[i];
					else curans+=0;
					new1=i;
				}
				else if(cur==0){
					if(new0==0) curans+=0;
					else if(a[new0]==a[i]) curans+=a[i];
					else curans+=0;
					new0=i;
				}
			}
//			cout<<curans<<" "<<status<<endl;
			ans=max(ans,curans);
		}
		printf("%lld\n",ans);
	}
}
namespace subtask2{
	inline void solve(){
		for(int status=0;status<(1e6/n);status++){
			int new0=0,new1=0,cur,curans=0;
			for(int i=1;i<=n;i++){
				cur=rand()%2;
				if(cur==1){
					if(new1==0) curans+=0;
					else if(a[new1]==a[i]) curans+=a[i];
					else curans+=0;
					new1=i;
				}
				else if(cur==0){
					if(new0==0) curans+=0;
					else if(a[new0]==a[i]) curans+=a[i];
					else curans+=0;
					new0=i;
				}
			}
			ans=max(ans,curans);
		}
		printf("%lld\n",ans);
	}
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T=read();
	srand(time(0));
	while(T--){
		n=read(),ans=0;
		for(int i=1;i<=n;i++) a[i]=read();
		if(n<=15) subtask1::solve();
		else subtask2::solve();
	}
}
