#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define repn(i,n) for(int i=0;i<(n);i++)
using namespace std;
const int N=2e5+10,M=1e6+10;

int n,a[N],b[N],pre[N],mp[M],mp2[M];

int c[N],s[N];
void bitprint(int x){
	string ret="";
	while(x){ret+=(x&1)+'0'; x>>=1;}
	reverse(ret.begin(), ret.end());
	cout<<ret<<'\n';
}
void solve1(){
	int sall=(1<<(n-1))-1, ret=0;
	rep(i,0,sall){
		rep(j,0,n-1){
			c[j+1]=(i>>j)&1;
			s[j+1]=s[j]+c[j+1];
		}
		int sum=0;
		printf("i = %d\n",i);
		rep(j,1,n){
			if(pre[j] && c[j]==c[pre[j]] && s[j-1]-s[pre[j]]==(1-c[j])*(j-1-pre[j])) printf(" += a[%d] (%d)\n",j,a[j])sum+=a[j];
//			else{
//				printf("    j %d  pre %d  c[%d %d] s %d\n",j,pre[j],c[pre[j]],c[j],s[j-1]-s[pre[j]]);
//			}
		}
			
		ret=max(ret,sum);
	}
	rep(i,0,sall){
		rep(j,0,n-1){
			c[j+1]=(i>>j)&1;
			s[j+1]=s[j]+c[j+1];
		}
		int sum=0;
		rep(j,1,n) if(pre[j] && c[j]==c[pre[j]] && s[j-1]-s[pre[j]]==(1-c[j])*(j-1-pre[j])) sum+=a[j];
		if(sum==ret){
			bitprint(i);
		}
	}
	cout<<ret<<endl;
}


signed main(){
//	freopen("color2.in","r",stdin);
//	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T; cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
			b[i]=a[i];
			mp2[a[i]]++;
		}
//		更改了 a 后要重新计算 
//		int _n=n; n=0;
//		rep(i,1,_n){
//			if(mp2[b[i]]>1) a[++n]=b[i];
//		}
		rep(i,1,n){
			pre[i]=mp[a[i]];
			mp[a[i]]=i;
		}
		
		if(n<=15){
			rep(i,1,n) cout<<a[i]<<' '; cout<<endl;
			solve1();
		}
		
		rep(i,1,n) mp[b[i]]=mp2[b[i]]=0;
	}
	
	
	return 0;
}
/*
1
8
5 3 13 5 5 3 5 13
0 0  1 0 0 0 0  1

5 2 5 1 2 1
0 1 0   1

1 2 3 1 1 2 1 3




*/
