#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
int t,n,ans;
int a[maxn],c[maxn];
void dfs(int u){
	if(u==n){
		int tot=0;
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(c[j]==c[i]&&a[i]==a[j]){
					tot+=a[i];
				}
			}
		}
		ans=max(ans,tot);
		return ;
	}else{
		c[u+1]=1;
		dfs(u+1);
		c[u+1]=2;
		dfs(u+1);
	}
	return ;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--){
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		c[1]=1;
		dfs(1);
		c[1]=2;
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
