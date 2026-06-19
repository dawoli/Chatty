#include<bits/stdc++.h>
using namespace std;
long long f[20005],a[15][10005],n,m,k;
bool flag[15];
struct line{
	long long u,v,w;
	bool operator < (const line& a) const{
		return a.w<w;
	}
}p[2000005];
long long find(long long x){
	if(f[x]==x)	return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
long long solve(long long x){
	//cout<<x<<endl;
	long long ans=0,cnl=m,cnn=n;
	for(long long i=1;i<=k;i++){
		if(flag[i]){
			ans+=a[i][0];
			cnn++;
			for(long long j=1;j<=n;j++){
				cnl++;
				p[cnl].u=cnn;
				p[cnl].v=j;
				p[cnl].w=a[i][j];
			}
		}
	}
	for(long long i=1;i<=cnn;i++)	f[i]=i;
	priority_queue<line> a;
	for(long long i=1;i<=cnl;i++)	a.push(p[i]);
	long long d=1;
	while(!a.empty()){
		line c=a.top();
		a.pop();
		if(find(c.u)!=find(c.v)){
			f[f[c.u]]=f[c.v];
			ans+=c.w;
			d++;
		}
		if(d==cnn)	break;
	}
	if(x!=-1 && ans>=x)	return ans;
	long long anss=ans;
	for(long long i=1;i<=k;i++){
		if(flag[i]==0){
			flag[i]=1;
			anss=min(anss,solve(ans));
			flag[i]=0;
		}
	}
	return anss;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	for(long long i=1;i<=k;i++){
		cin>>a[i][0];
		for(long long j=1;j<=n;j++)	cin>>a[i][j];
	}
	cout<<solve(-1);
	return 0;
}

