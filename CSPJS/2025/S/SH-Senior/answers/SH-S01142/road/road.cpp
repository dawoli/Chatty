#include<bits/stdc++.h>
using namespace std;
#define int long long
//想到做法了，写一下 
//假做法，浪费1.5h，炸了，心态也炸了 
//T2搞这么难啊，还没部分分拿，我搞这么久干啥呢，感觉T34都比T2简单啊 
//早知道去思考T34说不定还能多点分，T2代码又难调还是错的，绝望了 
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,m,k;
struct node{
	int to,nxt,w;
}e[2000005];
int head[1000005];
int cnt;
void add(int x,int y,int z){
	e[++cnt].to=y;
	e[cnt].nxt=head[x];
	e[cnt].w=z;
	head[x]=cnt;
}
int c;
struct rd{
	int a,id;
}a[10005];
int s[10005];
bool cmp(rd x,rd y){
	return x.a>y.a;
}
bool v[2000005];
int ans=1e18;
int get(int x){
	return (x+1)/2;
}
signed main(){//road
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);
	}
	while(k--){
		for(int i=1;i<=cnt;i++)v[i]=0;
		c=read();
		int res=c;
		for(int i=1;i<=n;i++){
			a[i].a=read();
			s[i]=a[i].a;
			a[i].id=i;
			res+=a[i].a;
		}
		sort(a+1,a+n+1,cmp);
		int sum=0;
		for(int j=1;j<=n;j++){
			int mi,id=0,x=a[j].id;
			mi=s[x];
			for(int i=head[x];i;i=e[i].nxt){//找最小修复路 
				int y=e[i].to,z=e[i].w;
				if(v[get(i)])continue;
				if(z==mi){
					if(s[y]<s[e[id].to]){
						mi=z;
						id=i;
					}
				}
				else if(z<mi){
					mi=z;
					id=i;
				}
			}
			if(id!=0){//有边被替换 
				sum++;
				res-=s[x];
				res+=e[id].w;
				v[get(id)]=1;
//				cout<<j<<" "<<get(id)<<"\n";
			}
		}
		if(sum==n)res-=c;
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}


