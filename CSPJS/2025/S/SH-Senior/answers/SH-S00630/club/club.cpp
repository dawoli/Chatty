#include<bits/stdc++.h>
using namespace std;
int t,n,cur1,cur2,cur3,a[100005],b[100005],c[100005],ans,maxb,maxc,tmpa[100005],tmpb[100005],tmpc[100005];
bool vis[100005];
struct Node{
	int val,id;
}d[100005];
void dfs(int step,int cnta,int cntb,int cntc,int sum){
	if(step>n){
		ans=max(ans,sum);
		return;
	}
	if(cnta<n/2){
		dfs(step+1,cnta+1,cntb,cntc,sum+a[step]);
	}
	if(cntb<n/2){
		dfs(step+1,cnta,cntb+1,cntc,sum+b[step]);
	}
	if(cntc<n/2){
		dfs(step+1,cnta,cntb,cntc+1,sum+c[step]);
	}
}
bool cmp(int x,int y){
	return abs(a[x]-b[x])>abs(a[y]-b[y]);
}
bool cmpa(int x,int y){
	return abs(a[x]-max(b[x],c[x]))>abs(a[y]-max(b[y],c[y]));
}
bool cmpb(int x,int y){
	return abs(b[x]-max(a[x],c[x]))>abs(b[y]-max(a[y],c[y]));
}
bool cmpc(int x,int y){
	return abs(c[x]-max(a[x],b[x]))>abs(c[y]-max(a[y],b[y]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		maxb=0,maxc=0,ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
			maxb=max(maxb,b[i]);
			maxc=max(maxc,c[i]);
		}
		//Test Case 1-4
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		//Test Case 12
		else if(maxb==0&&maxc==0){
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;--i)
				ans+=a[i];
			cout<<ans<<endl;
		}
		//Test Case 9,13,14
		else if(maxc==0){
			cur1=cur2=0;
			for(int i=1;i<=n;++i){
				if(a[i]>b[i])
					tmpa[++cur1]=i;
				else tmpb[++cur2]=i;
			}
			if(cur2>n/2){
				sort(tmpb+1,tmpb+cur2+1,cmp);
				for(int i=cur2;i>n/2;--i)
					tmpa[++cur1]=tmpb[i];
			}
			else {
				sort(tmpa+1,tmpa+cur1+1,cmp);
				for(int i=cur1;i>n/2;--i)
					tmpb[++cur2]=tmpa[i];
			}
			for(int i=1;i<=n/2;++i){
				ans+=a[tmpa[i]];
				ans+=b[tmpb[i]];
			}
			cout<<ans<<endl;
		}
		//Other Test Case
		else{
			cur1=cur2=cur3=0;
			for(int i=1;i<=n;++i){
				if(a[i]>=b[i]&&a[i]>=c[i])
					tmpa[++cur1]=i;
				else if(b[i]>=a[i]&&b[i]>=c[i])
					tmpb[++cur2]=i;
				else tmpc[++cur3]=i;
			}
			if(cur1>n/2){
				sort(tmpa+1,tmpa+cur1+1,cmpa);
				for(int i=cur1;i>n/2;--i){
					if(b[tmpa[i]]>c[tmpa[i]])
						tmpb[++cur2]=tmpa[i];
					else tmpc[++cur3]=tmpa[i];
				}
			}
			else if(cur2>n/2){
				sort(tmpb+1,tmpb+cur2+1,cmpb);
				for(int i=cur2;i>n/2;--i){
					if(a[tmpb[i]]>c[tmpb[i]])
						tmpa[++cur1]=tmpb[i];
					else tmpc[++cur3]=tmpb[i];
				}
			}
			else{
				sort(tmpc+1,tmpc+cur3+1,cmpc);
				for(int i=cur3;i>n/2;--i){
					if(a[tmpc[i]]>b[tmpc[i]])
						tmpa[++cur1]=tmpc[i];
					else tmpb[++cur2]=tmpc[i];
				}
			}
			for(int i=1;i<=min(cur1,n/2);++i)
				ans+=a[tmpa[i]];
			for(int i=1;i<=min(cur2,n/2);++i)
				ans+=b[tmpb[i]];
			for(int i=1;i<=min(cur3,n/2);++i)
				ans+=c[tmpc[i]];
			cout<<ans<<endl;
		}
	}
	return 0;
} 
