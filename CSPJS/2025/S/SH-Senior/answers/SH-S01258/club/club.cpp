#include<bits/stdc++.h>
using namespace std;
int t;
int n,ans;
int a1[100005],a2[100005],a3[100005];
int dp[100005][2];
struct edge{
	int a1,a2,a3,pos;
};

bool cmp1(edge a,edge b){ 
	return a.a1>b.a1;
}
bool cmp2(edge a,edge b){ 
	return a.a2>b.a2;
}
bool cmp3(edge a,edge b){ 
	return a.a3>b.a3;
}
void dfs(int like,int now,int cn1,int cn2,int cn3){
	if(now==n) ans=max(ans,like);
	if(cn1<n/2) dfs(like+a1[now+1],now+1,cn1+1,cn2,cn3);
	if(cn2<n/2) dfs(like+a2[now+1],now+1,cn1,cn2+1,cn3);
	if(cn3<n/2) dfs(like+a3[now+1],now+1,cn1,cn2,cn3+1);	
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool flaga=true,flagb=true;
		memset(a1,sizeof(a1),0);
		memset(a2,sizeof(a2),0);
		memset(a3,sizeof(a3),0);
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		 	if(a3[i]!=0) flagb=false;
			if(a2[i]!=0) flaga=false;
		}	
		if(n<=30){
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		if(flaga){
			sort(a1+1,a1+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=a1[i];
			cout<<ans<<endl;
			ans=0; 
			continue;
		}
		edge p1[n],p2[n],p3[n];
		bool p[100005]={0};
		for(int i=1;i<=n;i++){
			cin>>p1[i].a1>>p1[i].a2>>p1[i].a3;
			p2[i].a1=p3[i].a1=p1[i].a1;
			p2[i].a2=p3[i].a2=p1[i].a2;
			p2[i].a3=p3[i].a3=p1[i].a3;
			p1[i].pos=i;
			p2[i].pos=i;
			p3[i].pos=i;
		} 
		sort(p1+1,p1+n+1,cmp1);
		sort(p2+1,p2+n+1,cmp2);
		sort(p3+1,p3+n+1,cmp3);
		int c1=1,c2=1,c3=1;
		int cn1=0,cn2=0,cn3=0;
		for(int i=0;i<n;i++){
			if(p1[c1].pos==p2[c2].pos && p2[c2].pos==p3[c3].pos){
				if(max(p1[c1].a1,max(p2[c2].a2,p3[c3].a3))==p1[c1].a1 && cn1<n/2 && !p[p1[c1].pos]){
					ans+=p1[c1].a1;
					p[p1[c1].pos]=!false;
					cn1++;
				}
				if(max(p1[c1].a1,max(p2[c2].a2,p3[c3].a3))==p2[c2].a2 && cn2<n/2 && !p[p2[c2].pos]){
					ans+=p2[c2].a2;
					p[p2[c2].pos]=!false;
					cn2++;
				}
				if(max(p1[c1].a1,max(p2[c2].a2,p3[c3].a3))==p3[c3].a3 && cn3<n/2 && !p[p3[c3].pos]){
					ans+=p3[c3].a3;
					p[p3[c3].pos]=!false;
					cn3++;
				}
				c1++,c2++,c3++;
				continue;
			}
			if(p1[c1].pos==p2[c2].pos){
				if(p1[c1].a1>p2[c2].a2 && cn1<n/2 && cn3<n/2 && !p[p1[c1].pos] && !p[p3[c3].pos]){
					ans+=p1[c1].a1;
					ans+=p3[c3].a3;
					p[p1[c1].pos]=!false;
					p[p3[c3].pos]=!false;
					cn1++,cn3++;
					c1++,c2++,c3++;
					continue;
				}
				if(p1[c1].a1<p2[c2].a2 && cn2<n/2 && cn3<n/2 && !p[p2[c2].pos] && !p[p3[c3].pos]){
					ans+=p2[c2].a2;
					ans+=p3[c3].a3;
					p[p2[c2].pos]=!false;
					p[p3[c3].pos]=!false;
					cn2++,cn3++;
					c1++,c2++,c3++;
					continue;
				}
			}
			if(p1[c1].pos==p3[c3].pos){
				if(p1[c1].a1>p3[c3].a3 && cn1<n/2 && cn2<n/2 && !p[p1[c1].pos] && !p[p2[c2].pos]){
					ans+=p1[c1].a1;
					ans+=p2[c2].a2;
					p[p1[c1].pos]=!false;
					p[p2[c2].pos]=!false;
					cn1++,cn2++;
					c1++,c2++,c3++;
					continue;
				}
				if(p1[c1].a1<p3[c3].a3 && cn2<n/2 && cn3<n/2 && !p[p2[c2].pos] && !p[p3[c3].pos]){
					ans+=p2[c2].a2;
					ans+=p3[c3].a3;
					p[p2[c2].pos]=!false;
					p[p3[c3].pos]=!false;
					cn2++,cn3++;
					c1++,c2++,c3++;
					continue;
				}
			}
			if(p2[c2].pos==p3[c3].pos){
				if(p2[c2].a2>p3[c3].a3 && cn1<n/2 && cn2<n/2 && !p[p1[c1].pos] && !p[p2[c2].pos]){
					ans+=p1[c1].a1;
					ans+=p2[c2].a2;
					p[p1[c1].pos]=!false;
					p[p2[c2].pos]=!false;
					cn1++,cn2++;
					c1++,c2++,c3++;
					continue;
				}
				if(p2[c2].a2<p3[c3].a3 && cn1<n/2 && cn3<n/2 && !p[p1[c1].pos] && !p[p3[c3].pos]){
					ans+=p1[c1].a1;
					ans+=p3[c3].a3;
					p[p1[c1].pos]=!false;
					p[p3[c3].pos]=!false;
					cn1++,cn3++;
					c1++,c2++,c3++;
					continue;
				}
			}
			if(cn1<n/2 && !p[p1[c1].pos]){
				ans+=p1[c1].a1;
				p[p1[c1].pos]=!false;
				cn1++,c1++;
			}
			if(cn2<n/2 && !p[p2[c2].pos]){
				ans+=p2[c2].a2;
				p[p2[c2].pos]=!false;
				cn2++,c2++;
			}
			if(cn3<n/2 && !p[p3[c3].pos]){
				ans+=p3[c3].a3;
				p[p3[c3].pos]=!false;
				cn3++,c3++;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/ 
