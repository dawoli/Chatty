#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=100015;
int read(){
	int w=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return w*ret;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n;
int a[N][3];
int cnt[3],idc[N],maxx[N];
vector<int>vec;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		n=read();
		vec.clear();
		memset(cnt,0,sizeof cnt);
		int ans=0;
		for(int i=1;i<=n;i++){
			maxx[i]=-1e18,idc[i]=-1;
			for(int j=0;j<=2;j++){
				a[i][j]=read();
				if(maxx[i]<a[i][j]){
					maxx[i]=a[i][j],idc[i]=j;
				}
			}
			ans+=maxx[i],cnt[idc[i]]++;
		}
		bool flag=1;
		int idt=0;
		for(int j=0;j<=2;j++){
			if(cnt[j]>n/2){
				flag=0,idt=j;
				break;
			}
		}
		if(flag){
			write(ans);
			puts("");
		}
		else{
			for(int i=1;i<=n;i++){
			 	if(idc[i]!=idt)continue;
			 	int rim=-1e18;
			 	for(int j=0;j<=2;j++){
			 		if(j==idt)continue;
			 		rim=max(rim,a[i][j]-maxx[i]);
				}
				vec.push_back(rim);
			}
			sort(vec.begin(),vec.end(),cmp);
			for(int i=0;i<cnt[idt]-n/2;i++){
				ans+=vec[i];
			}
			write(ans);
			puts("");
		}
	}
	return 0;
}
