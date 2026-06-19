#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 1e3;
int T,n,a[N][4],s[4],b[N],ans;
int maxx(int a,int b){
	return a>b?a:b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(s,0,sizeof(s));
		memset(b,0,sizeof(b));
		scanf("%d",&n);ans=0;
		for(int i=1;i<=n;i++){
			int maxj=0,maxx=-1;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>maxx){
					maxx=a[i][j];
					maxj=j;
				}
			}
			ans+=a[i][maxj];
			a[i][0]=maxj;
			s[maxj]++;
		}
		int maxs=-1,maxj=0;
		for(int j=1;j<=3;j++){
			if(maxs<s[j]){
				maxs=s[j];
				maxj=j;
			}
		}
		if(maxs>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][0]==maxj){
					b[++b[0]]=a[i][maxj]-maxx(a[i][maxj%3+1],a[i][(maxj+1)%3+1]);
				}
			}
			sort(b+1,b+1+b[0]);
			for(int i=1;i<=s[maxj]-n/2;i++){
				ans-=b[i];
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
