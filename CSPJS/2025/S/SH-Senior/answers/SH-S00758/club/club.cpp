#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;

const int N=1e5+5;

int n, a[N][4], ans, b[50], s[4], aa[N];
struct node{
	int x, y, z;
}p[N];
bool cmp2(node xx, node yy){
	if(xx.x!=yy.x)return xx.x>yy.x;
	return xx.y>yy.y;
}
bool cmp(int x, int y){
	return x>y;
}
void check_1(){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i][b[i]];
	}
	ans=max(ans, sum);
}
void dfs_1(int now){
	if(s[1]>(n>>1)||s[2]>(n>>1)||s[3]>(n>>1))return;
	if(now==n+1){
		check_1();
		return;
	}
	for(int i=1;i<=3;i++){
		b[now]=i;
		s[i]++;
		dfs_1(now+1);
		s[i]--;
	}
	return;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		if(n<=10){
			for(int i=1;i<=n;i++){cin>>a[i][1]>>a[i][2]>>a[i][3];}
			dfs_1(1);
			cout<<ans<<endl;
			continue;
		}
		else {
			bool flag3=0, flag2=0;
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				p[i].x=a[i][1];p[i].y=a[i][2];p[i].z=a[i][3];
				if(a[i][3]!=0)flag3=1;
				if(a[i][2]!=0)flag2=1;
			}
			if(flag2==0&&flag3==0){//A
				for(int i=1;i<=n;i++){
					aa[i]=a[i][0];
				}
				sort(aa+1, aa+n+1, cmp);
				for(int i=1;i<=n/2;i++)ans+=aa[i];
				cout<<ans<<endl;
				continue;
			}
			else if(flag3==0){//B?
			}
		}
	}
	return 0;
}
//CSP-S 2025 rp++
