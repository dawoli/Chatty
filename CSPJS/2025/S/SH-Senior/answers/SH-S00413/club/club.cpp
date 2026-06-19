#include<bits/stdc++.h>
using namespace std;
int t,n,ans,c[5][3],h[3][100001],m[3][100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",m[0]+i,m[1]+i,m[2]+i);
			h[0][i]=h[1][i]=h[2][i]=1e9;
			if(m[0][i]>=m[1][i]&&m[0][i]>=m[2][i]){
				if(m[1][i]>m[2][i]) h[0][i]=m[0][i]-m[1][i];
				else h[0][i]=m[0][i]-m[2][i];
				c[t][0]++;
				ans+=m[0][i];
			}
			else if(m[1][i]>=m[0][i]&&m[1][i]>=m[2][i]){
				if(m[2][i]>m[0][i]) h[1][i]=m[1][i]-m[2][i];
				else h[1][i]=m[1][i]-m[0][i];
				c[t][1]++;
				ans+=m[1][i];
			}
			else{
				if(m[0][i]>m[1][i]) h[2][i]=m[2][i]-m[0][i];
				else h[2][i]=m[2][i]-m[1][i];
				c[t][2]++;
				ans+=m[2][i];
			}
		}
		int flg=3;
		if(c[t][0]>n/2) flg=0;
		if(c[t][1]>n/2) flg=1;
		if(c[t][2]>n/2) flg=2;
		if(flg==3){
			cout<<ans<<endl;
			continue;
		}
		sort(h[flg]+1,h[flg]+n+1);
		for(int i=1;i<=c[t][flg]-n/2;i++) ans-=h[flg][i];
		cout<<ans<<endl;
	}
	return 0;
}
