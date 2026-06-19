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
const long long N=10005;
const long long M=1000005;
const long long K=15;
struct node{
	long long x;
	long long y;
	long long z;
	bool operator >(node b)const{
		return z>b.z;
	}
	bool operator <(node b)const{
		return z<b.z;
	}
}l[M],a[K][N];
long long n,m,k,f[N],sz[N],cnt,res,ans,len,c[K],now[K];
priority_queue<node,vector<node>,greater<node> >q;
long long fa(long long p){
	if(f[p]==p){
		return p;
	}
	return f[p]=fa(f[p]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++){
		f[i]=i;sz[i]=1;
	}
	for(int i=1;i<=m;i++){
		l[i].x=read();l[i].y=read();l[i].z=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j].x=n+i;a[i][j].y=j;a[i][j].z=read();
		}
		sort(a[i]+1,a[i]+n+1);
	}
	sort(l+1,l+m+1);res=0;
	for(int i=1;cnt!=n-1;i++){
		long long temp1=fa(l[i].x),temp2=fa(l[i].y);
		if(temp1!=temp2){
			if(sz[temp1]>sz[temp2]){
				swap(temp1,temp2);
			}
			f[temp1]=temp2;sz[temp2]+=sz[temp1];cnt++;res+=l[i].z;l[cnt]=l[i];
		}
	}
	ans=res;len=1<<k;
	for(int p=1;p<len;p++){
		while(!q.empty()){
			q.pop();
		}
		res=cnt=0;
		for(int i=1;i<=n;i++){
			f[i]=i;sz[i]=1;
		}
		for(int i=1;i<=k;i++){
			if(p&(1<<(i-1))){
				now[i]=2;q.push(a[i][2]);res+=c[i];res+=a[i][1].z;f[i+n]=a[i][1].y;sz[f[i+n]]++;
			}
		}
		q.push(l[1]);now[0]=1;
		while(cnt!=n-1){
			if(res>ans){
				break;
			}
			node pp=q.top();q.pop();long long temp1=fa(pp.x),temp2=fa(pp.y);
			if(temp1!=temp2){
				if(sz[temp1]>sz[temp2]){
					swap(temp1,temp2);
				}
				f[temp1]=temp2;sz[temp2]+=sz[temp1];cnt++;res+=pp.z;
			}
			if(pp.x>n){
				now[pp.x-n]++;
				if(now[pp.x-n]<=n){
					q.push(a[pp.x-n][now[pp.x-n]]);
				}
			}
			else{
				now[0]++;
				if(now[0]<n){
					q.push(l[now[0]]);
				}
			}
		}
		ans=min(ans,res);
	}
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
