#include<bits/stdc++.h>
using namespace std;
int T,n,a[5][100010],pa,pb,pc;
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n;
		ans=pa=pb=pc=0;
		for (int i = 1; i <= n; i++){
			int x,y,z;
			cin>>x>>y>>z;
			if (max({x,y,z})==x){
				a[1][++pa]=x-max(y,z);
				ans+=x;
			}
			else if (max({x,y,z})==y){
				a[2][++pb]=y-max(x,z);
				ans+=y;
			}
			else{
				a[3][++pc]=z-max(x,y);
				ans+=z;
			}
		}
		sort(a[1]+1,a[1]+1+pa);
		sort(a[2]+1,a[2]+1+pb);
		sort(a[3]+1,a[3]+1+pc);
		int x=1;
		while (pa>n/2){
			ans-=a[1][x++];
			pa--;
		}
		while (pb>n/2){
			ans-=a[2][x++];
			pb--;
		}
		while (pc>n/2){
			ans-=a[3][x++];
			pc--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
