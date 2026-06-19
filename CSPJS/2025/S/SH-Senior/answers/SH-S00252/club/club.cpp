#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int ml,nml,cha;
}p[100002];
int a[100002][10];
int s[5];
bool cmp(Node x,Node y){
	return x.cha>y.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t; cin>>t;
	while(t--){
		memset(s,0,sizeof(s));
		int n,ans=0; cin>>n;
		for (int i=0;i<n;i++){
			for (int j=0;j<3;j++){
				cin>>a[i][j];
			}
			int ml,nml;
			if (a[i][0]>=a[i][1] && a[i][0]>=a[i][2]){
				ml=0;
				if (a[i][1]>a[i][2]) nml=1;
				else nml=2;
			}else if (a[i][1]>=a[i][0] && a[i][1]>=a[i][2]){
				ml=1;
				if (a[i][0]>a[i][2]) nml=0;
				else nml=2;
			}
			else{
				ml=2;
				if (a[i][0]>a[i][1]) nml=0;
				else nml=1;
			}
			ans+=a[i][ml];
			p[i].ml=ml; p[i].nml=nml; p[i].cha=a[i][ml]-a[i][nml];
		}
		sort(p,p+n,cmp);
		for (int i=0;i<n;i++){
			int ml=p[i].ml,nml=p[i].nml,cha=p[i].cha;
			if (s[ml]<n/2) s[ml]++;
			else{
				s[nml]++;
				ans-=cha;
			}
		}
		cout<<ans<<endl;
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
*/
