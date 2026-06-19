#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=201,HN=151;
/*
typedef pair<int,int> pii;
struct stu{
	pii s[4];	
}a[N];
int cnt[4];
bool cmp1(pii x,pii y){
	return x.first>y.first;
}
bool cmp2(stu x,stu y){
	if(x.s[1]!=y.s[1]) return x.s[1]>y.s[1];
	if(x.s[2]!=y.s[2]) return x.s[2]>y.s[2];
	return x.s[3]>y.s[3];
}
int main(){
	freopen("club2.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	int maxn;
	int ans;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s[1].first>>a[i].s[2].first>>a[i].s[3].first;
			a[i].s[1].second=1;
			a[i].s[2].second=2;
			a[i].s[3].second=3;
			sort(a[i].s+1,a[i].s+4,cmp1);
		}
		maxn=n/2;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(cnt[a[i].s[j].second]!=maxn){
					cnt[a[i].s[j].second]++;
					ans+=a[i].s[j];
					break;
				} 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
*/

struct stu{
	int s[4];	
}a[N];
int f[2][HN][HN][HN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	int maxn;
	while(t--){
		cin>>n;
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++)
			cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
		maxn=n/2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=maxn;j++){
				for(int k=0;k<=maxn;k++){
					for(int l=0;l<=maxn;l++){
						if(j>0)
							f[i&1][j][k][l]=max(f[1-(i&1)][j-1][k][l]+a[i].s[1],f[i&1][j][k][l]);
						if(k>0)	
							f[i&1][j][k][l]=max(f[1-(i&1)][j][k-1][l]+a[i].s[2],f[i&1][j][k][l]);
						if(l>0)
							f[i&1][j][k][l]=max(f[1-(i&1)][j][k][l-1]+a[i].s[3],f[i&1][j][k][l]);		  
					}
				}
			}
		}
		cout<<f[n&1][maxn][maxn][maxn]<<"\n";
	}
	return 0;
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

18 
4 
13
*/
