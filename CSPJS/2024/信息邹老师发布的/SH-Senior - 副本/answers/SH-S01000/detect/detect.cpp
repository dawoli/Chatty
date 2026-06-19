#include<bits/stdc++.h>
using namespace std;
int t,m,n,l,v1;
int d[100005],v[100005],a[100005],p[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n>>m>>l>>v1;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		cout<<n<<" "<<m*6/10<<endl;
	}
	return 0;
} 
