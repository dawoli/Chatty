#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x^=x;
	int f=1;
	char a=getchar();
	while('0'>a||a>'9'){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}
const int SIZE=1e5+9,INF=0x3f3f3f3f;
int t,n,ans;
int a[SIZE][3],as[SIZE][3];

int dic[SIZE];
void checkBF(){
	int i,res=0;
	for(i=0;i<n;i++){
		res+=a[i][dic[i]];
	}
	ans=max(ans,res);
	return ;
}
void dfs(int x,int a,int b,int c){
	if(x==n+1){
		checkBF();
		return ;
	}
	if(a!=0){dic[x]=0;a--;dfs(x+1,a,b,c);a++;}
	if(b!=0){dic[x]=1;b--;dfs(x+1,a,b,c);b++;}
	if(c!=0){dic[x]=2;c--;dfs(x+1,a,b,c);c++;}
	return ;
}
void solveBF(){
	dfs(0,n/2,n/2,n/2);
	printf("%d\n",ans);
}
void solveA(){
	int x[SIZE],i,res=0;
	for(i=0;i<n;i++)x[i]=a[i][0];
	sort(x,x+n);
	for(i=n/2;i<n;i++){
		res+=x[i];
	}
	printf("%d\n",res);
	return ;
}
int d[2][1009][1009];
void solve200(){
	int i,j,k,p=0;
	for(i=0;i<2;i++)for(j=0;j<=n/2;j++)for(k=0;k<=n/2;k++)d[i][j][k]=-1;
	d[0][0][0]=0;
	for(i=0;i<n;i++){
		for(j=0;j<=n/2;j++){
			for(k=0;k<=n/2;k++){
				if(d[p][j][k]==-1)continue;
				d[p^1][j+1][k]=max(d[p][j][k]+a[i][0],d[p^1][j+1][k]);
				d[p^1][j][k+1]=max(d[p][j][k]+a[i][1],d[p^1][j][k+1]);
				if(i-j-k<=n/2)d[p^1][j][k]=max(d[p][j][k]+a[i][2],d[p^1][j][k]);
			}
		}
		p^=1;
	}
	for(j=0;j<=n/2;j++){
		for(k=0;k<=n/2;k++){
			ans=max(ans,d[p][j][k]);
		}
	}
	printf("%d\n",ans);
}
queue<int>q;
struct node{
	int x,id;
	bool operator < (const node&a)const{return x<a.x;}
};
priority_queue<node>a1[3];
void solve(){
	int i,j,maxn,minn;
	for(i=0;i<n;i++)q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(i=2;i>=0;i--){
			if(a1[as[u][i]].size()<n/2){
				a1[as[u][i]].push((node){a[u][as[u][i]],u});
				break;
			}
			else{
				if(a[u][as[u][i]]>a1[as[u][i]].top().x){
					q.push(a1[as[u][i]].top().id);
					a1[as[u][i]].pop();
					a1[as[u][i]].push((node){a[u][as[u][i]],u});
				}
			}
		}
	}
	int cnt=0;
	for(i=0;i<3;i++){
		while(!a1[i].empty()){
			cnt+=a1[i].top().x;
			a1[i].pop();
		}
	}
	printf("%d\n",cnt);
}
bool modA=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	int i,j;
	while(t--){
		ans^=ans;
		read(n);
		for(i=0;i<n;i++){
			read(a[i][0]);
			read(a[i][1]);
			read(a[i][2]);	
			node temp[3];
			for(j=0;j<3;j++)temp[j]=(node){a[i][j],j};
			sort(temp,temp+2);
			for(j=0;j<3;j++)as[i][j]=temp[j].id;
			if(a[i][1]!=0||a[i][2]!=0)modA=0;
		}
		if(n<=10)solveBF();
		else if(modA)solveA();
		else if(n<=2000)solve200();
		else solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
