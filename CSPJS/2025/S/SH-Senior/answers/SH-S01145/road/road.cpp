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
const int SIZE=1e4+9,MSIZE=1e7+9;
int n,m,k,ans;
int c[19],cts[19][SIZE];
bool modA=1;

int fa[SIZE];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

struct EDGE{
	int u,v,w;
}E[MSIZE];
bool cmp(const EDGE a,const EDGE b){
	return a.w<b.w;
}
void solvek0(){
	int i;
	long long res=0;
	for(i=0;i<n;i++)fa[i]=i;
	sort(E,E+m,cmp);
	for(i=0;i<m;i++){
		EDGE temp=E[i];
		if(find(temp.u)!=find(temp.v)){
			fa[temp.v]=fa[temp.u];
			res+=temp.w;
		}
	}
	printf("%lld",res);
	return ;
}

vector<int>ct0[19];
struct node{
	int cost,id;
};
bool cmp1(const node a,const node b){
	return a.cost<b.cost;
}
void solveA(){
	int i,j,w,stk[SIZE],top;
	node temp[19];
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			temp[j]=(node){cts[j][i],j};
		}
		sort(temp,temp+k,cmp1);
		for(w=0;w<k/2;w++)for(j=0;j<ct0[temp[w].id].size();j++)E[m++]=(EDGE){ct0[temp[w].id][j],i,temp[w].cost};
	}
	solvek0();
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	int i,j,u,v,w;
	for(i=0;i<m;i++){
		read(u);
		read(v);
		read(w);
		E[i]=(EDGE){u,v,w};
	}
	for(i=0;i<k;i++){
		read(c[i]);
		if(c[i]!=0)modA=0;
		bool temp=0;
		for(j=0;j<n;j++){
			read(cts[i][j]);
			if(cts[i][j]==0)temp=1,ct0[i].push_back(j);
		}
		modA=temp;
	}
	if(k==0)solvek0();
	else solveA();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
