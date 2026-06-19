#include<iostream>
#include<algorithm>
struct node{
	int dl;
	int jc,ji;//需要dl元钱改造第ji个乡镇 
}a[10001][10001];//(i<j)
struct node2{
	int i1,j1,num;
}b[50000001];
bool v[10001][10001];//第i个与第j个城市是否联通(i<j)
bool f[11];//第f[i]个乡镇是否被改造过
int xxx[10001];
bool cmp(node2 x,node2 y){return x.num<y.num;}
int main(){
	f[0]=true;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	std::cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		std::cin>>u>>v>>w;
		if(u>v){int t=u;u=v,v=t;}
		a[u][v].dl=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		std::cin>>c;
		for(int j=0;j<n;j++)std::cin>>xxx[j];
		for(int j=0;j<n;j++)
			for(int d=j+1;d<n;d++)
				if(a[j][d].dl>=xxx[j]+xxx[d]+c){
					a[j][d].dl=xxx[j]+xxx[d];
					a[j][d].jc=c;
					a[j][d].ji=i;
				}
	}
	int d=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)std::cout<<a[i][j].dl<<" ";
		std::cout<<"\n";
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			b[d].i1=i;
			b[d].j1=j;
			b[d++].num=a[i][j].dl;
		}
	std::sort(b,b+n*(n-1)/2,cmp);
	int ans=0;
	for(int i=0;i<d;i++){
		int ii=b[i].i1,jj=b[i].j1;
		if(!v[ii][jj]){
			node x=a[ii][jj];
			ans+=x.dl;
			if(!f[x.ji])ans+=x.jc;
			f[x.ji]=true;
			for(int j=0;j<n;j++)
				if(v[std::min(ii,j)][std::max(ii,j)])
					v[std::min(jj,j)][std::max(jj,j)]=1;
			for(int j=0;j<n;j++)
				if(v[std::min(jj,j)][std::max(jj,j)])
					v[std::min(ii,j)][std::max(ii,j)]=1;		
		}
	}
	std::cout<<ans;
	return 0;
}
//0'(错在什么奇奇怪怪的地方了，虽然写的也很奇怪）
//(名字太随意，都不知道哪对哪了)  
