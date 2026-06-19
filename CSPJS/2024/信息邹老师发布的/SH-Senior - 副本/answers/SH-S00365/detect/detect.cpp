#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int T,n,m,a[N],v[N],s[N],lim,L,p[N],cnt,ans;
struct node{int l,r;}lines[N];
bool cmp(node a,node b){
	return a.r==b.r?a.l<b.l:a.r<b.r;
}
void func(){
	cnt=0;
	scanf("%d%d%d%d",&n,&m,&L,&lim);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&s[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(v[i]>lim){
				int l=lower_bound(p+1,p+m+1,s[i])-p;
				while(p[l]<s[i])l++;
				if(l>m)continue;
				lines[++cnt]={l,m};
			}
		}
		else if(a[i]<0){
			if(v[i]>lim){
				int ed=s[i]+(lim*lim-v[i]*v[i])/(2*a[i]);
				if((ed-s[i])*(2*a[i])==lim*lim-v[i]*v[i])ed--;
				int l=lower_bound(p+1,p+m+1,s[i])-p,r=lower_bound(p+1,p+m+1,ed)-p;
				while(p[l]<s[i])l++;
				while(p[r]>ed)r--;
				if(l>r)continue;
				lines[++cnt]={l,r};
			}
		}
		else if(a[i]>0){
			if(v[i]>lim){
				int l=lower_bound(p+1,p+m+1,s[i])-p;
				while(p[l]<s[i])l++;
				if(l>m)continue;
				lines[++cnt]={l,m};
			}
			else if(v[i]==lim){
				int l=lower_bound(p+1,p+m+1,s[i]+1)-p;
				while(p[l]<s[i]+1)l++;
				if(l>m)continue;
				lines[++cnt]={l,m};
			}
			else if(v[i]<lim){
				int st=s[i]+(lim*lim-v[i]*v[i])/(2*a[i]),l=lower_bound(p+1,p+m+1,st+1)-p;
				while(p[l]<st+1)l++;
				if(l>m)continue;
				lines[++cnt]={l,m};
			}
		}
	}
	sort(lines+1,lines+cnt+1,cmp);
	ans=m;
	for(int r=0,i=1;i<=cnt;i++){
		if(lines[i].l>r)r=lines[i].r,ans--;
		//printf("<%d %d %d %d>",lines[i].l,lines[i].r,r,ans);
	}
	printf("%d %d\n",cnt,ans);
	
	
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	//T=1;
	while(T--)func();
	return 0;
}
