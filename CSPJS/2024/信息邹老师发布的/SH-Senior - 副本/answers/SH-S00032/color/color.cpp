#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
int a[N];
int t,n;
unsigned long long ans=0;
int ap[M];
bool t[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		memset(ap,0,sizeof(ap));
		memset(t,0,sizeof(t));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ap[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(ap[a[i]]==1)t[i]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
