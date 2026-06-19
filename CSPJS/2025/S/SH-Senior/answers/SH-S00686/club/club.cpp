#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct Node{
	int id;
	long long a,b,c;
	int belong;
}p[100001];
int cntp[5];
long long ans;
bool cmpa(Node x,Node y){
	if(x.belong==y.belong){
		return max(x.b,x.c)-x.a>max(y.b,y.c)-y.a;
	}
	return x.belong<y.belong;
}
bool cmpb(Node x,Node y){
	if(x.belong==y.belong){
		return max(x.a,x.c)-x.b>max(y.a,y.c)-y.b;
	}
	return x.belong<y.belong;
}
bool cmpc(Node x,Node y){
	if(x.belong==y.belong){
		return max(x.b,x.a)-x.c>max(y.b,y.a)-y.c;
	}
	return x.belong<y.belong;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int maxn=n/2;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a>p[i].b &&p[i].a>p[i].c){
				cntp[1]++;
				ans+=p[i].a;
				p[i].belong=1;
			}else if(p[i].b>p[i].a &&p[i].b>p[i].c){
				cntp[2]++;
				ans+=p[i].b;
				p[i].belong=2;
			}else{
				cntp[3]++;
				ans+=p[i].c;
				p[i].belong=3;
			}
		}
		if(cntp[1]>maxn){
			int need=cntp[1]-maxn;
			sort(p+1,p+n+1,cmpa);
			for(int k=1;k<=need;k++){
				ans=ans-p[k].a+max(p[k].b,p[k].c);
			}
		}else if(cntp[2]>maxn){
			int need=cntp[2]-maxn;
			sort(p+1,p+n+1,cmpb);
			for(int k=1;k<=need;k++){
				ans=ans-p[k+cntp[1]].b+max(p[k+cntp[1]].a,p[k+cntp[1]].c);
			}
		}else if(cntp[3]>maxn){
			int need=cntp[3]-maxn;
			sort(p+1,p+n+1,cmpc);
			for(int k=1;k<=need;k++){
				ans=ans-p[k+cntp[1]+cntp[2]].c+max(p[k+cntp[1]+cntp[2]].b,p[k+cntp[1]+cntp[2]].a);
			}
		}
		cout<<ans<<"\n";
		ans=0;
		for(int i=1;i<=n;i++){
			p[i].a=p[i].b=p[i].c=p[i].belong=0;
		}
		cntp[1]=cntp[2]=cntp[3]=0;
	}
	return 0;
} 
