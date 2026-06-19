#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x*w;
}
const int MAXN=1e5+10;

int n,m,L,V;
int d[MAXN],a[MAXN],v[MAXN],p[MAXN];
int ans_num=0,ans_clo=0;
int cnt;
pair<int,int> x[MAXN];
//.first->Right .second->Left
void init(){
	ans_num=0;ans_clo=0;cnt=0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T=read();
	while(T--){
		init();
		n=read();m=read();L=read();V=read();
		for(int i=1;i<=n;i++){
			d[i]=read();v[i]=read();a[i]=read();
		}
		for(int i=1;i<=m;i++){
			p[i]=read();
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V){
					int num=lower_bound(p+1,p+m+1,d[i])-p;
					if(num>m)continue;
					else{
						ans_num++;
						cnt++;
						x[cnt]=make_pair(m,num);
					}
				}
			}else if(a[i]>0){
				if(v[i]>V){
					int num=lower_bound(p+1,p+m+1,d[i])-p;
					if(num>m)continue;
					else{
						ans_num++;
						cnt++;
						x[cnt]=make_pair(m,num);
					}
				}else{
					int pos;
					if((V*V-v[i]*v[i])%(2*a[i])==0){
						pos=ceil((V*V-v[i]*v[i])*1.0/2/a[i])+d[i]+1;
					}else pos=ceil((V*V-v[i]*v[i])*1.0/2/a[i])+d[i];
					if(pos>L)continue;
					int num=lower_bound(p+1,p+m+1,pos)-p;
					if(num>m)continue;
					else{
						ans_num++;
						cnt++;
						x[cnt]=make_pair(m,num);
					}
				}
			}else{
				if(v[i]>V){
					int lnum=lower_bound(p+1,p+m+1,d[i])-p;
					if(lnum>m)continue;
					int pos;
					if((V*V-v[i]*v[i])%(-2*a[i])==0){
						pos=d[i]+floor((v[i]*v[i]-V*V)*1.0/2/(-a[i]))-1;
					}
					else pos=d[i]+floor((v[i]*v[i]-V*V)*1.0/2/(-a[i]));
					int rnum=upper_bound(p+1,p+m+1,pos)-p-1;
					if(rnum<=0)continue;
					if(lnum>rnum)continue;
					
					ans_num++;
					cnt++;
					x[cnt]=make_pair(rnum,lnum);
				}
			}
		}
		printf("%d ",ans_num);
//		cout<<endl;
//		for(int i=1;i<=cnt;i++){
//			cout<<x[i].second<<" "<<x[i].first<<endl;
//		}
		sort(x+1,x+cnt+1);
//		for(int i=1;i<=m;i++)cout<<p[i]<<" ";cout<<endl;
		int t=1,lst=-1;
		ans_clo=m;
		for(int i=1;i<=m;i++){
			while(x[t].second<=lst&&lst<=x[t].first&&t<=cnt)t++;
			if(t>cnt)break;
			if(i<=x[t].first&&i+1>x[t].first){
				ans_clo--;lst=i;t++;
			}
			if(t>cnt)break;
		}
		printf("%d\n",ans_clo);
	}
	return 0;
} 
