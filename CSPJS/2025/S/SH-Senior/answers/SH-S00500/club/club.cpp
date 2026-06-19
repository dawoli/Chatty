#include<bits/stdc++.h>
using namespace std;
const int N=100100,M=5;
int t,n,a[N][M],c[M];
vector<int> s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int mx=0,ans=0,diff=0;
		s.clear();
		c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;i++){
			mx=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				mx=max(mx,a[i][j]);
			}
			ans+=mx;
			for(int j=1;j<=3;j++)
				if(a[i][j]==mx){
					c[j]++;
					break;
				}
		}
		mx=max(c[1],max(c[2],c[3]));
		if(mx<=n/2){
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(c[1]==mx) diff=a[i][1]-max(a[i][2],a[i][3]);
			else if(c[2]==mx){
				if(a[i][1]==a[i][2]) continue;
				diff=a[i][2]-max(a[i][1],a[i][3]);
			}
			else{
				diff=a[i][3]-max(a[i][1],a[i][2]);
				if(diff==0) continue;
			}
			if(diff>=0) s.push_back(diff);
		}
		sort(s.begin(),s.end());
		for(int i=0;i<mx-n/2;i++) ans-=s[i];
		cout<<ans<<endl;
	}
	return 0;
}
