#include<bits/stdc++.h>
using namespace std;
int T,N,Ans,c[500005],nd[500005],lt,nl,is[500005];
struct im{int id,v;}nw[500005];
struct node{im v[3];}s[500005];
bool cp(im a,im b){if(a.v!=b.v)return a.v>b.v;return a.id<b.id;}
bool Cp(im a,im b){if(a.v!=b.v)return a.v<b.v;return a.id<b.id;}
bool cmp(node a,node b){
	if(a.v[0].v!=a.v[0].v)return a.v[0].v>b.v[0].v;
	if(a.v[1].v!=b.v[1].v)return a.v[1].v>b.v[1].v;
	if(a.v[2].v!=a.v[2].v)return a.v[2].v>a.v[2].v;
	return a.v[1].id<b.v[1].id;
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>T;
	while(T--){Ans=0;memset(c,0,sizeof(c));lt=0;memset(is,0,sizeof(is));
		cin>>N;
		for(int i=1;i<=N;i++){
			cin>>s[i].v[0].v>>s[i].v[1].v>>s[i].v[2].v;
			s[i].v[0].id=0,s[i].v[1].id=1,s[i].v[2].id=2;
			sort(s[i].v,s[i].v+3,cp);
		}sort(s+1,s+1+N,cmp);
		for(int i=1;i<=N;i++){
			c[s[i].v[0].id]++;Ans+=s[i].v[0].v;
		}
		for(int i=0;i<3;i++){
			while(c[i]>(N/2)){nd[++lt]=i,c[i]--;}
		}
		if(lt==0){cout<<Ans<<endl;continue;}
		for(int i=1;i<=lt;i++){nl=0;
			for(int j=1;j<=N;j++){
				if(nd[i]==s[j].v[0].id&&!is[j])nw[++nl]={j,s[j].v[0].v-s[j].v[1].v};
			}
			sort(nw+1,nw+1+nl,Cp);
			if(nl!=0){
				is[nw[1].id]=1;Ans-=nw[1].v;
			}
		}cout<<Ans<<endl;
	}
	return 0;
}

