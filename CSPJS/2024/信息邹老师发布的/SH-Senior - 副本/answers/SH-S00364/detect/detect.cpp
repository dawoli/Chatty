#include<bits/stdc++.h>
using namespace std;
int d[100009],v[100009],a;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,l,xs,max_=-1,ans1=0;
		cin>>n>>m>>l>>xs;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a;
		for(int i=1;i<=m;i++){
			cin>>l;
			max_=max(max_,l);
		}
		for(int i=1;i<=n;i++)if(d[i]<=max_&&v[i]>xs)ans1++;
		cout<<ans1<<" "<<m-1<<endl;
	}
	return 0;
}
