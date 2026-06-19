#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=1ll<<30;
int a[N][3],n;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	}
	multiset<int> s[3];
	int ans=0;
	for(int i=1;i<=n;i++){
		int mx=0;
		if(a[i][1]>a[i][mx])mx=1;
		if(a[i][2]>a[i][mx])mx=2;
		ans+=a[i][mx];
		int p=inf;
		for(int j=0;j<3;j++)if(j!=mx){
			p=min(p,a[i][mx]-a[i][j]);
		}
//		printf("kkk %d %d %d\n",i,mx,p);
		s[mx].insert(p);
	}
	for(int i=0;i<3;i++){
//		printf("%d\n",s[i].size());
		while(s[i].size()>n/2){
			
			ans-=*s[i].begin();
			s[i].erase(s[i].begin());
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--)solve();	
	return 0;
} 
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/ 
//Ren5Jie4Di4Ling5%
