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
		f=f*10+ch-'0';ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');write(-1*x);return;
	}
	if(x>=10){
		write(x/10);
	}
	putchar('0'+x%10);return;
}
const long long N=100005;
const long long inf=-1e18;
long long t,n,ans,a[N][5],id[N],cnt[5],b[N],len;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();ans=len=0;cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			id[i]=b[i]=a[i][0]=a[i][1]=a[i][2]=0;
		}
		for(int i=1;i<=n;i++){
			a[i][0]=read();a[i][1]=read();a[i][2]=read();
			if(a[i][1]>a[i][id[i]]){
				id[i]=1;
			}
			if(a[i][2]>a[i][id[i]]){
				id[i]=2;
			}
			cnt[id[i]]++;ans+=a[i][id[i]];
		}
		for(int i=0;i<3;i++){
			if(cnt[i]*2<=n){
				continue;
			}
			for(int j=1;j<=n;j++){
				if(id[j]==i){
					len++;b[len]=inf;
					for(int k=0;k<3;k++){
						if(i==k){
							continue;
						}
						b[len]=max(b[len],a[j][k]-a[j][i]);
					}
				}
			}
			sort(b+1,b+len+1);
			for(int j=len;j>=1;j--){
				cnt[i]--;ans+=b[j];
				if(cnt[i]*2<=n){
					break;
				}
			}
		}
		write(ans);putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
