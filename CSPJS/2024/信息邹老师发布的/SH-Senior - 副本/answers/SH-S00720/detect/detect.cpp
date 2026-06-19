#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

#define ll long long
int read(){
	int x=0,w=0;
	char ch=getchar();
	while(!isdigit(ch))ch=='-'?w=1:0,ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return w?-x:x;
}

int n,m,L,V;
struct node{
	int d,v,a;
}a[100005];
int p[100005];
int d[100005];

struct res{int il,ir;};
res find(int l,int r){
	if(l>10000000)return{1,0};
	int idxl=lower_bound(p+1,p+1+m,l)-p,idxr=lower_bound(p+1,p+1+m,r)-p-1;
	if(p[idxr]==r)
		idxr--;
//	printf("%d %d %d %d\n",l,r,idxl,idxr);
	return {idxl,idxr};
}

res find2(int l,int r){
	if(l>10000000)return{1,0};
	int idxl=lower_bound(p+1,p+1+m,l)-p,idxr=lower_bound(p+1,p+1+m,r)-p-1;
	if(p[idxr]==r)
		idxr--;
//	printf("%d %d %d %d\n",l,r,idxl,idxr);
	return {idxl,idxr};
}

/*
10 10 18708 742
12707 2 -279
4284 983 -4
4851 982 -902
16121 921 -199
5656 996 -21
5804 865 -13
2562 975 -14
1089 903 -12
2846 805 -4
7745 998 -26
1945 4875 5456 5914 11120 12935 16023 16832 16948 17807
*/
 
ll gcd(ll x,ll y){
	if(x<0)x=-x;
	if(y<0)y=-y;
	ll r=x%y;
	while(y){
		x=y;
		y=r;
		if(y)r=x%y;
	}
	return x;
}

res cs[100005];
bool cmp(res x,res y){
	if(x.ir-x.il!=y.ir-y.il)return x.ir-x.il<y.ir-y.il;
	if(x.il==y.il)return x.ir<y.ir;
	return x.il<y.il;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T=read();
	while(T--){
		n=read(),m=read(),L=read(),V=read();
		memset(d,0,sizeof(d));int fab=1;
		for(int i=1;i<=n;i++)a[i].d=read(),a[i].v=read(),a[i].a=read(),a[i].a<0?fab=0:0;
		for(int i=1;i<=m;i++)p[i]=read();
		int cnt=0;
		for(int i=1;i<=n;i++){
			ll fz=1ll*V*V-1ll*a[i].v*a[i].v;
			ll fm=2ll*a[i].a;
			res qujian{1,0};
			if(fm==0){
				if(a[i].v>V){
					qujian=find(a[i].d,L+1);
				}
				goto SSS;
			}
			{
			if(fz<0&&fm<0)fz=-fz,fm=-fm;
//			if(fz<0||fm<0)goto SSS;
			if(fm<0)fm=-fm,fz=-fz;
			ll g=gcd(fz,fm);
			fz/=g;fm/=g;
//			printf("  %lld %lld\n",fz,fm);
			if(a[i].a>0){
				if(fm==1)fz++;
				else fz+=fm-1,fz/=fm;
				qujian=find(min(L+1ll,a[i].d+max(0ll,fz)),L+1);
			}else{
				if(fm==1);
				else fz+=fm-1,fz/=fm;
				qujian=find2(a[i].d,min(L+1ll,a[i].d+fz+1));
			}
			}
			SSS:;
			if(qujian.il<=qujian.ir)cs[++cnt]=qujian;
		}
		printf("%d ",cnt);
		sort(cs+1,cs+1+cnt,cmp);
		int ccn=cnt,ans=0;
//		if(!fab){
//			for(int i=1;i<=cnt;i++){
//				for(int j=1;j<i;j++){
////					printf("%d %d\n",i,j);
//					if(cs[i].il<=cs[j].il&&cs[j].ir<=cs[i].ir){
//						cs[i].il=0,cs[i].ir=-1;
//						break;
//					}
//				}
//			}
//		}
		for(int i=1;i<=cnt;i++){
			d[cs[i].il]++;d[cs[i].ir+1]--;
		}
		while(ccn){
			ans++;
			for(int i=1;i<=cnt;i++){
				d[cs[i].il]++;d[cs[i].ir+1]--;
			}
			int maxi=0;
			for(int i=1;i<=m;i++){
				d[i]+=d[i-1];
//				printf("%d ",d[i]);
				if(d[i]>d[maxi])maxi=i;
			}
			for(int i=1;i<=m+1;i++)d[i]=0;
//			printf("%d\n",maxi);
			for(int i=1;i<=cnt;i++){
				if(cs[i].il<=maxi&&maxi<=cs[i].ir){
					cs[i].il=0;cs[i].ir=-1;
					ccn--;
				}
			}
		}
		printf("%d\n",m-ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
