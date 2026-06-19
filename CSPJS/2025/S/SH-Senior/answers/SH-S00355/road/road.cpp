#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,f[20009],cnt,krus,a[12][10009],c[10009],ava[20],ans;
struct fir{
	int x,y,z;
	bool operator<(const fir&aaa)const{
		return aaa.z>z;
	}
}ha[1000009];
struct edge{
	int x,y,z,ok;
	bool operator<(const edge&aaa)const{
		return aaa.z>z;
	}
}h[400009];
void add_edge(int x,int y,int z,int l){
	cnt++;
	h[cnt].x=x;
	h[cnt].y=y;
	h[cnt].z=z;
	h[cnt].ok=l;
	return ;
}
int find(int x){
	if (f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
int read(){
	int x=0;
	char c=getchar();
	while(c==' '||c=='\n') c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		ha[i].x=read();
		ha[i].y=read();
		ha[i].z=read();
	}
	sort(ha+1,ha+m+1);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if (find(ha[i].x)!=find(ha[i].y)){
			f[find(ha[i].x)]=find(ha[i].y);
			add_edge(ha[i].x,ha[i].y,ha[i].z,0);
			krus+=ha[i].z;
		}
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			add_edge(n+i,j,a[i][j],i);
		}
	}
	sort(h+1,h+cnt+1);
	for(int p=0;p<(1<<k);p++){
		int temp=0,tar=0;
		for(int i=1;i<=19;i++) ava[i]=0;
		ava[0]=1;
		for(int i=0;i<k;i++)
			if ((p>>i)&1){
				temp+=c[i+1];
				ava[i+1]=1;
				tar++;
			}
		for(int i=1;i<=n+k;i++) f[i]=i;
		int ok_num=1;
		int pos=0;
		while(ok_num<n+tar){
			pos++;
			if (find(h[pos].x)!=find(h[pos].y)&&ava[h[pos].ok]==1){
				ok_num++;
				f[find(h[pos].x)]=find(h[pos].y);
				temp+=h[pos].z;
			}
		}
		krus=min(krus,temp);
	}
	cout<<krus<<endl;
	return 0;
}
