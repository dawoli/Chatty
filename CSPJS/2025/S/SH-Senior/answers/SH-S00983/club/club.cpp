#include<bits/stdc++.h>
using namespace std;
int t,n,ans,cnt;
const int N=1e5+5;
int a[N][3];
int b[N];

bool cmp(int t,int s){
	return t>s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]==0&&a[i][2]==0)cnt++;
		}
		if(n==2){
			int x=max(a[0][0],a[0][1]);
			int y=max(a[0][2],x);
			int x_2=max(a[1][0],a[1][1]);
			int y_2=max(a[1][2],x_2);
			if(y==a[0][2]&&y_2==a[1][2]){
				int z=max(a[0][0],a[0][1]);
				int z_2=max(a[1][0],a[1][1]);
				ans=max(z+y_2,z_2+y);
			}
			if(y==a[0][1]&&y_2==a[1][1]){
				int z=max(a[0][0],a[0][2]);
				int z_2=max(a[1][0],a[1][2]);
				ans=max(z+y_2,z_2+y);
			}
			if(y==a[0][0]&&y_2==a[1][0]){
				int z=max(a[0][2],a[0][1]);
				int z_2=max(a[1][2],a[1][1]);
				ans=max(z+y_2,z_2+y);
			}
			
			cout<<ans<<endl;
		}
		else if(cnt==n){
			for(int i=0;i<n;i++){
				b[i]=a[i][0];
			}
			sort(b,b+n,cmp);
			for(int j=0;j<n/2;j++){
				ans+=b[j];
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=0;i<n;i++){
				int x=max(a[i][0],a[i][1]);
				int y=max(a[i][2],x);
				ans+=y;
			}
			cout<<ans<<endl;
		} 
		
	} 
	return 0;
}
