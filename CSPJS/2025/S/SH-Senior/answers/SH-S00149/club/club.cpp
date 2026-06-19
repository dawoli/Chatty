#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[4][N],m1,m2,m3;
long long ans;
priority_queue<int> que[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		ans=m1=m2=m3=0;
		for(int i=1;i<=3;i++){
			while(!que[i].empty()){
				que[i].pop();
			}
		}
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		for(int i=0;i<n;i++){
			if(a[1][i]>=a[2][i] && a[1][i]>=a[3][i]){
				if(m1<n/2){
					ans+=a[1][i];
					m1++;
					que[1].push(max(a[2][i],a[3][i])-a[1][i]);
		    	}
		    	else if(m1==n/2){
		    		if(a[1][i]-max(a[2][i],a[3][i])>=-que[1].top()){
		    			ans+=a[1][i]+que[1].top();
		    			que[1].pop();
		    			que[1].push(max(a[2][i],a[3][i])-a[1][i]);
					}
					else{
						ans+=max(a[2][i],a[3][i]);
					}
				}
			}
			else if(a[2][i]>=a[1][i] && a[2][i]>=a[3][i]){
				if(m2<n/2){
					ans+=a[2][i];
					m2++;
					que[2].push(max(a[1][i],a[3][i])-a[2][i]);
		    	}
		    	else if(m2==n/2){
		    		if(a[2][i]-max(a[1][i],a[3][i])>=-que[2].top()){
		    			ans+=a[2][i]+que[2].top();
		    			que[2].pop();
		    			que[2].push(max(a[1][i],a[3][i])-a[2][i]);
					}
					else{
						ans+=max(a[1][i],a[3][i]);
					}
				}
			}
			else if(a[3][i]>=a[1][i] && a[3][i]>=a[2][i]){
				if(m3<n/2){
					ans+=a[3][i];
					m3++;
					que[3].push(max(a[1][i],a[2][i])-a[3][i]);
		    	}
		    	else if(m3==n/2){
		    		if(a[3][i]-max(a[1][i],a[2][i])>=-que[3].top()){
		    			ans+=a[3][i]+que[3].top();
		    			que[3].pop();
		    			que[3].push(max(a[1][i],a[2][i])-a[3][i]);
					}
					else{
						ans+=max(a[1][i],a[2][i]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
