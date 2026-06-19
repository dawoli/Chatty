#include<bits/stdc++.h>
#define N 100009
using namespace std;
int T,n,m,L,V,p[N],d[N],v[N],a[N],pre[N],nxt[N],cnt,ans;
pair<int,int>r[N];
bool cmp(const pair<int,int>&A,const pair<int,int>&B){
	return A.second<B.second||A.second==B.second&&A.first<B.first;
}
void fread(int&x){
	bool b=0;
	char c=getchar();
	while(c<45||c>57)c=getchar();
	if(c==45)b=1,c=getchar();
	for(x=0;c>44&&c<58;c=getchar())x=x*10+c-48;
	if(b)x=-x;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	for(fread(T);T--;cout<<' '<<ans){
		cnt=0;
		fread(n),fread(m),fread(L),fread(V);
		ans=m;
		for(int i=1;i<=n;++i)fread(d[i]),fread(v[i]),fread(a[i]);
		for(int i=1;i<=m;++i)fread(p[i]);
		for(int i=1;i<=n;++i)
			if(a[i]<0){
				if(V<v[i]){
					r[++cnt]=make_pair(lower_bound(p+1,p+m+1,d[i])-p,upper_bound(p+1,p+m+1,d[i]+(V*V-v[i]*v[i])/(a[i]<<1))-p-1);
					if(r[cnt].second<r[cnt].first)--cnt;
				}
			}else if(!a[i]){
				if(V<v[i]){
					r[++cnt]=make_pair(lower_bound(p+1,p+m+1,d[i])-p,m);
					if(r[cnt].first==m+1)--cnt;
				}
			}else{
				r[++cnt]=make_pair(lower_bound(p+1,p+m+1,d[i]+ceil(0.5*(V*V-v[i]*v[i])/a[i]))-p,m);
				if(r[cnt].first==m+1)--cnt;
			}
		cout<<cnt;
		sort(r+1,r+cnt+1,cmp);
		*nxt=1;
		for(int i=1;i<=cnt;++i)pre[i]=i-1,nxt[i]=i+1;
		for(int i=2;i<=cnt;++i)
			if(r[i].first<=r[pre[i]].first)pre[nxt[i]]=pre[i],nxt[pre[i]]=nxt[i];
		for(int i=*nxt,j;i<=cnt;){
			--ans,j=i;
			while(i<=cnt&&r[i].first<=r[j].second)i=nxt[i];
		}
	}
	return 0;
}
