#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
}
const int MAXN=1e5+10;
int t,n,m,l,sum,V,ans;
long long d[MAXN],v[MAXN],a[MAXN],p[MAXN];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
		n=read();
		m=read();
		l=read();
		V=read();
		for(int j=1;j<=n;j++){
			d[j]=read();
			v[j]=read();
			a[j]=read();
		}
		for(int j=1;j<=m;j++){
			p[j]=read();
		}      										   //以上输入 
		int speed[MAXN],stop[MAXN];
		memset(speed,0,sizeof(speed));
		memset(stop,m,sizeof(stop));
		int cnt[MAXN];
		memset(cnt,0,sizeof(cnt));
		int num=0,start[MAXN];
		for(int j=1;j<=n;j++){
			for(int k=1;k<m;k++){
				if(d[j]>p[k]&&d[j]<=p[k+1])
				start[j]=k+1;
				if(d[j]<=p[1]) start[j]=1;
			}
		}
		ans=0;
		for(int j=1;j<=n;j++){		  //如果这辆车超速 
				for(int k=start[j];k<=m;k++){
					if(a[j]>=0){
						if(V*V<(p[k]-d[j])*a[j]*2+v[j]*v[j]){//超第k个测速仪 
							cnt[k]++; 
						}
					}								//超了的话就不能忽略 只有全部可以忽略的才留着 
					if(a[j]<0){
						if((p[k]-d[j])*a[j]*2+v[j]*v[j]>0){
							if(V*V<(p[k]-d[j])*a[j]*2+v[j]*v[j])
							cnt[k]++;//超速 
						}
						else{
							stop[j]=k;
						}
					} 
				}
				
				if(a[j]>=0&&cnt[start[j]]){
					ans++;
					speed[j]=1;
				}
				if(a[j]<0&&cnt[stop[j]]) {
					ans++;
					speed[j]=1;
				}
				if(stop[j]<=start[j]) {
				speed[j]=0;
				ans--;
				}
			}
		cout<<ans<<" "<<m-2<<endl;
		} 
		return 0;
	}
