#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5; 
const int inf=1e9;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
struct node{
	int a[3];
}w[N];
int n,p,cnt[3];
int get(node x){
	int ret=min(x.a[p]-x.a[(p+1)%3],x.a[p]-x.a[(p+2)%3]);
	return ret>=0?ret:inf;
}
bool cmp(node a,node b){
	return get(a)<get(b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				w[i].a[j]=read();
		ll ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			int mx=0;
			for(int j=0;j<3;j++)
				if(w[i].a[j]>w[i].a[mx])
					mx=j;
			ans+=w[i].a[mx];
			cnt[mx]++;
		}
		for(int j=0;j<3;j++)
			if(cnt[j]>cnt[p])
				p=j;
		sort(w+1,w+1+n,cmp);
		for(int i=1;i<=cnt[p]-n/2;i++)
			ans-=get(w[i]);
		cout<<ans<<endl; 
	}
}
