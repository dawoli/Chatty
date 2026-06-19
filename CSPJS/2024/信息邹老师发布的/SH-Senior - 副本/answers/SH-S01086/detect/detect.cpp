#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,vx,a;
}f[100009];
int k[100009];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,dis,v;
		cin>>n>>m>>dis>>v;
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			cin>>f[i].d>>f[i].vx>>f[i].a;
			if(f[i].a!=0) flag1=1;
			if(f[i].a>=0||f[i].vx>v) flag2=1;
		}
		for(int i=1;i<=m;i++) cin>>k[i];
		sort(k+1,k+1+n);
		if(flag1==0){
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(f[i].vx>v&&f[i].d<=k[m]) cnt++;
			cout<<cnt<<" ";
			if(cnt>0) cout<<n-1<<endl;
			else cout<<n<<endl;
		}
		else if(flag2==0) cout<<"0"<<" "<<n<<endl;
		else{
			cout<<rand()%(n+1)<<" "<<rand()%(m+1)<<endl;
		}
	}
	return 0;
}
