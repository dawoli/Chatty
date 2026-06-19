#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,x,y,d,ans=1;
char s[1009][1009];
bool yn(ll x,ll y,ll d){
	if(d==0&&y+1<=m&&s[x][y+1]!='x') 
	return 1; 
	else if(d==1&&x+1<=n&&s[x+1][y]!='x') 
	return 1; 
	else if(d==2&&y-1>=1&&s[x][y-1]!='x') 
	return 1;
	else if(d==1&&x-1>=1&&s[x-1][y]!='x') 
	return 1;
	else return 0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(ll ff=0;ff<t;ff++){
		ans=1;
		for(ll i=0;i<1001;i++)
			for(ll j=0;j<1001;j++)
				s[i][j]=0; 
		cin>>n>>m>>k>>x>>y>>d;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++)
				cin>>s[i][j]; 
		if(k==1){
			if(yn(x,y,d))
				cout<<"2";
			else
			 	cout<<"1";
		}
		if(n==1&&k!=1){
			for(ll a=0;a<k;a++){
				if(yn(x,y,d)){
					ans++;
				if(d==0)y++;
				else y--;
				}
				else d=(d+1)%4;
			}
			cout<<ans;
		}
	}
	return 0;
}
