#include<bits/stdc++.h>
#define N 1000009
using namespace std;
typedef long long ll;
inline ll read(){
	char c=getchar();ll x=0,f=1;
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
ll T,n,lst[N],a[N],lst_a[N],f[N][2],m,b[N],res;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=read();
	while(T--){
		memset(lst,0,sizeof(lst));
		n=read(),m=0,res=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]!=a[i-1]) b[++m]=a[i];
			else res+=a[i];
		}
		n=m;for(int i=1;i<=n;i++) a[i]=b[i];
		for(int i=1;i<=n;i++){
			lst_a[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(lst_a[i]==0){
				f[i][0]=max(f[i-1][0],f[i-1][1]);
				f[i][1]=0;
				continue;
			}
			if(lst_a[i]==i-1){
				f[i][0]=max(f[i-1][0],f[i-1][1]);
				f[i][1]=max(f[i-1][0],f[i-1][1])+a[i];
			}
			else{
				f[i][0]=max(f[i-1][0],f[i-1][1]);
				f[i][1]=max(f[lst_a[i]+1][0],f[lst_a[i]+1][1])+a[i];
			}
		}
		printf("%lld\n",res+max(f[n][0],f[n][1]));
	}
	return 0;
}
//Believe the RAINBOW!!
