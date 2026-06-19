#include <bits/stdc++.h>
using namespace std;

int flag=0;

struct node{
	int x,y,z;
}a[100005];

bool cmp(node a,node b){
	return a.x>b.x;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z==0){
				if(a[i].y==0){
					flag=1;
				}else{
					flag=2;
				}
			}
		} 
		if(flag==1){
			int ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x; 
			}
			cout<<ans<<endl;
		}
	}
}

