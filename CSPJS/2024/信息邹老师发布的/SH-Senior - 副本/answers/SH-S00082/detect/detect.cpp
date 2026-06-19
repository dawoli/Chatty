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
const long long N=100005;
const long long inf=1e18;
long long t,n,m,len,limit,d[N],v[N],a[N],p[N],f[N][2],maxn[N],cnt,g[N];
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	while(t--){
		n=read();m=read();len=read();limit=read();
		cnt=0;
		for(int i=1;i<=n;i++){
			d[i]=v[i]=a[i]=0;
		}
		for(int i=1;i<=m;i++){
			maxn[i]=p[i]=0;f[i][0]=f[i][1]=inf;g[i]=0;
		}
		for(int i=1;i<=n;i++){
			d[i]=read();v[i]=read();a[i]=read();
		}
		for(int i=1;i<=m;i++){
			p[i]=read();
		}
		for(int i=1;i<=n;i++){
			long long res1=0,res2=0,l=0,r=0;
			l=lower_bound(p+1,p+m+1,d[i])-p;r=m;
			while(l<=r){
				long long mid=(l+r)>>1;
				if(limit*limit<v[i]*v[i]+2*a[i]*(p[mid]-d[i])){
					res1=mid;
					r=mid-1;
				}
				else{
					if(a[i]>=0){
						l=mid+1;
					}
					else{
						r=mid-1;
					}
				}
			}
			l=lower_bound(p+1,p+m+1,d[i])-p;r=m;
			while(l<=r){
				long long mid=(l+r)>>1;
				if(limit*limit<v[i]*v[i]+2*a[i]*(p[mid]-d[i])){
					res2=mid;
					l=mid+1;
				}
				else{
					if(a[i]>=0){
						l=mid+1;
					}
					else{
						r=mid-1;
					}
				}
			}
			if(res1==0&&res2==0){
				continue;
			}
			cnt++;maxn[res2]=max(maxn[res2],res1);
		}
		write(cnt);putchar(' ');
		for(int i=1;i<=m;i++){
			f[i][1]=min(f[i-1][0],f[i-1][1])+1;
			if(i-1>=maxn[i]){
				f[i][0]=f[i-1][1];g[i]=i-1;
			}
			if(g[i-1]>=maxn[i]){
				if(f[i-1][0]<f[i][0]){
					f[i][0]=f[i-1][0];g[i]=g[i-1];
				}
			}
		}
		write(m-min(f[m][0],f[m][1]));putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
