#include<bits/stdc++.h>
#define N 1009
using namespace std;
typedef long long ll;
ll T,n,m,k,x,y,d;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(ll p=1;p<=T;p++){
		cin>>n>>m>>k>>x>>y>>d;
		char mp[N][N];
		for(ll i=1;i<=n;i++) //ÊäÈëÍ¼ 
			for(ll j=1;j<=m;j++)
				cin>>mp[i][j];
		set<ll> st; ll cnt=0;
		st.insert(x*1000+y);
		for(ll i=1;i<=k;i++){ //Ö´ÐÐ 
			if(d==0) y++;
			else if(d==1) x++;
			else if(d==2) y--;
			else x--;
			if(x>=1 and x<=n and y>=1 and y<=m and mp[x][y]=='.') st.insert(x*1000+y);
			else{
				if(d==0) y--;
				else if(d==1) x--;
				else if(d==2) y++;
				else x++;
				d=(d+1)%4;
			}
		}
		cout<<st.size()<<endl;
	}
	return 0;
}
