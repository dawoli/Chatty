#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
};
bool cmp1(node a,node b){
	return a.x<b.x;
}
node a[200005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int s=1;s<=t;s++){
		int n,p=0,q=0,ans=0;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y==0&&a[i].z==0)
				p++;
			else if(a[i].z==0)q++;
		}
		if(p==n){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
		}else if(q==n){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			for(int i=n/2+1;i<=n;i++)
				ans+=a[i].y;
		}else{
			for(int i=1;i<=n;i++)
				ans+=max(max(a[i].x,a[i].y),a[i].z);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
