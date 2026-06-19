#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int t;

int m[maxn];

int cnt;


//int am[4];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0;
		memset(m,0,sizeof m);
		int n;
		cin>>n;
		int tmp1,tmp2;

		for(int i=1;i<=n;i++){
			cin>>m[i]>>tmp1>>tmp2;
		}
		
		sort(m+1,m+n+1);

		for(int i=n;i>n/2;i--)
		{
			cnt+=m[i];
		}
		cout<<cnt<<"\n";
	}	
	return 0;
}
