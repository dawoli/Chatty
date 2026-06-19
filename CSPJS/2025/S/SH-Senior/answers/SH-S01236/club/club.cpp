#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int t,sa[N][5];

struct node{
	int x,y,z;
}a[N];

bool cmp(node a,node b){
	return a.x>b.x;
}

bool cmpp(node a,node b){
	return a.x>b.x&&a.x-a.y>b.x-b.y;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		int n,ans=0,res=0,cnt=0,cntt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			sa[i][1]=a[i].x;
			sa[i][2]=a[i].y;
			sa[i][3]=a[i].z;
			if(!a[i].y) cnt++;
			if(!a[i].z) cntt++;
		}
		if(cnt==n&&cntt==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<endl;
		}else if(cntt==n){
			sort(a+1,a+n+1,cmpp);
			for(int i=1;i<=n;i++){
				if(i<=n/2) ans+=a[i].x;
				else ans+=a[i].y;
			}
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i+=2){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						if(j==k) continue;
						ans=max(ans,sa[i][j]+sa[i+1][k]);
					}
				}
				res+=ans;
			} 
			cout<<res<<endl;
		}
	}
	return 0;
}
