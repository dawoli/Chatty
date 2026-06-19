#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans=0;
struct node{
	int a1,a2,a3,value;
};
priority_queue <int> q1,q2,q3;
node a[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ans=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].a1);
			scanf("%d",&a[i].a2);
			scanf("%d",&a[i].a3);
			//cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
				a[i].value=min((a[i].a1-a[i].a2),(a[i].a1-a[i].a3));
				q1.push(a[i].value*(-1));
				ans+=a[i].a1;
			}
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
				a[i].value=min((a[i].a2-a[i].a1),(a[i].a2-a[i].a3));
				q2.push(a[i].value*(-1));
				ans+=a[i].a2;
			}
			else{
				a[i].value=min((a[i].a3-a[i].a1),(a[i].a3-a[i].a2));
				q3.push(a[i].value*(-1));
				ans+=a[i].a3;
			}
		}
		if(q1.size()<=(n/2)&&q2.size()<=(n/2)&&q3.size()<=(n/2)){
			cout<<ans<<endl;
		}
		else if(q1.size()>(n/2)){
			while(q1.size()>(n/2)){
				ans+=q1.top();
				q1.pop();
			}
			cout<<ans<<endl;
		}
		else if(q2.size()>(n/2)){
			while(q2.size()>(n/2)){
				ans+=q2.top();
				q2.pop();
			}
			cout<<ans<<endl;
		}
		else if(q3.size()>(n/2)){
			while(q3.size()>(n/2)){
				ans+=q3.top();
				q3.pop();
			}
			cout<<ans<<endl;
		}
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
	}
	return 0;
} 
