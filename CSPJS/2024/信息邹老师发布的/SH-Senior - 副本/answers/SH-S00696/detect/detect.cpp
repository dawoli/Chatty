#include<bits/stdc++.h>
using namespace std;
int p[100001],N,M,L,V;
struct car{
	int d,v,a;
}c[100001];
int cn;//³¬ËÙµÄ³µ 
int read();
void prepare();
int find(int);
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
int T;cin>>T;
for(int t=1;t<=T;t++){
	prepare();
	cn=0;
	for(int i=1;i<=N;i++){
		if(c[i].d<=p[M]){
			if(c[i].v>V)	cn++;
		}
	}
	if(cn==0)	cout<<cn<<' '<<M<<'\n';
	else cout<<cn<<' '<<M-1<<'\n';
}
return 0;
}
//1 5 5 15 3 0 3 0 12 4 0 1 1 4 5 5 -2 6 4 -4 2 5 8 9 15
int read(){
	char c;int s;
	c=getchar();
	while(c<'0'||c>'9') c= getchar();
	s=c-'0';
	c=getchar();
	while(c>='0'&&c<='9'){
		s=c-'0'+s*10;
		c=getchar();
	}
	return s;
}
void prepare(){
	cin>>N>>M>>L>>V;
		for(int j=1;j<=N;j++){
			c[j].d=read();
			c[j].v=read();
			cin>>c[j].a;
		}
		for(int j=1;j<=M;j++)	p[j]=read();
}
int find(int d){
	for(int i=1;i<=M;i++)
		if(p[i]>=d)	
			return i;
	return -1;
}
