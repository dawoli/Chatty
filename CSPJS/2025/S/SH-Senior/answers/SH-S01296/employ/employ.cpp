#include<algorithm>
#include<cstdio>
using namespace std;
const int SIZI=(1<<16)-1;
char bufi[SIZI];	char *Si=bufi,*Ti=bufi;
#define load() (Ti=bufi+fread(Si=bufi,1,SIZI,stdin))
#define gc() ((__builtin_expect(Si==Ti,false)&&(load(),Si==Ti))?EOF:(*Si++))
inline int read(){
	int x=0,f=1;	char ch=gc();
	for(;(ch<'0')||(ch>'9');ch=gc())
		(ch=='-')&&(f=-1);
	for(;(ch>='0')&&(ch<='9');ch=gc())
		x=x*10+ch-'0';
	return x*f;
}
const int N=510,P=998244353;
#define pls(x,y) ((x+=y)>=P)&&(x-=P)
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read();	int m=read();
	static bool s[N];
	char ch=gc();
	for(;(ch<'0')||(ch>'1');ch=gc());
	for(int i=1;i<=n;i++){
		s[i]=(ch=='1');	ch=gc();
	}
	static int c[N];
	for(int i=1;i<=n;i++)
		c[i]=read();
	sort(c+1,c+n+1);
	if(m==n){
		for(int i=1;i<=n;i++)
			if(!s[i]){
				puts("0");	return 0;
			}
		for(int i=1;i<=n;i++)
			if(!c[i]){
				puts("0");	return 0;
			}
		int res=1;
		for(int i=1;i<=n;i++)
			res=1ll*res*i%P;
		printf("%d\n",res);	return 0;
	}
	if(n<=22){
		static int f[1<<22][22];
		f[0][0]=1;
		for(int i=0,fij;i<(1<<n);i++)
			for(int j=0;j<n;j++){
				if(!(fij=f[i][j]))
					continue;
				int cnt=__builtin_popcount(i)+1;
				bool flag=!s[cnt];
				int s=(1<<n)-1;	s^=i;
				for(;s;s&=s-1){
					int k=__builtin_ctz(s&(-s));
					pls(f[i|(1<<k)][j+(flag||(j>=c[k+1]))],fij);
				}
			}
		int res=0;
		for(int i=0;i<=n-m;i++)
			pls(res,f[(1<<n)-1][i]);
		printf("%d\n",res);	return 0;
	}
	puts("0");	return 0;
}
