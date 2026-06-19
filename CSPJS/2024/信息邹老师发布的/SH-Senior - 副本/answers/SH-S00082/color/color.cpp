#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long c=1,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			c=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9){
		write(x/10);
	}
	putchar('0'+x%10);
	return;
}
const long long N=2e5+5;
const long long M=1e6+5;
const long long inf=1e18;
long long t,n,a[N],f[M][2],res[2],maxn,ans,s[N];
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--){
		n=read();res[0]=res[1]=maxn=ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			maxn=max(maxn,a[i]);
			s[i]=s[i-1];
			if(a[i]==a[i-1]){
				s[i]+=a[i];
			}
		}
		for(int i=1;i<=maxn;i++){
			f[i][0]=f[i][1]=-1*inf;
		}
		for(int i=1;i<=n;i++){
			long long temp1=0,temp2=0;
			temp1=max(res[1],f[a[i+1]][1]+a[i+1])+s[i];
			ans=max(ans,temp1);
			temp2=max(res[0],f[a[i+1]][0]+a[i+1])+s[i];
			ans=max(ans,temp2);
			f[a[i]][0]=max(f[a[i]][0],temp1-s[i+1]);
			res[0]=max(res[0],f[a[i]][0]);
			f[a[i]][1]=max(f[a[i]][1],temp2-s[i+1]);
			res[1]=max(res[1],f[a[i]][1]);
		}
		write(ans);putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
