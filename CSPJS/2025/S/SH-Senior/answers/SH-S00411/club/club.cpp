#include<bits/stdc++.h>
using namespace std;
int t,n,n1,n2,n3;
long long ans;
priority_queue<int>q1,q2,q3;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		n1=n2=n3=0;
		ans=0;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		for(int i=0;i<n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(x>y){
				if(x>z){
					ans+=x,n1++;
					q1.push(max(y,z)-x);
				}
				else{
					ans+=z,n3++;
					q3.push(max(x,y)-z);
				}
			}
			else{
				if(y>z){
					ans+=y,n2++;
					q2.push(max(x,z)-y);
				}
				else{
					ans+=z,n3++;
					q3.push(max(x,y)-z);
				}
			}
		}
		while(n1>n/2){
			ans+=q1.top();
			q1.pop(),n1--;
		}
		while(n2>n/2){
			ans+=q2.top();
			q2.pop(),n2--;
		}
		while(n3>n/2){
			ans+=q3.top();
			q3.pop(),n3--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
