#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int t,n,e[maxn];
long long sum;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		sum=0;
		memset(e,0,sizeof(e));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;
				cin>>x;
				e[i]=max(e[i],x);
			}
		}
		sort(e+1,e+1+n,cmp);
		for(int i=1;i<=n/2;i++) sum+=e[i];
		cout<<sum<<endl;
	}
	
	return 0;
}
