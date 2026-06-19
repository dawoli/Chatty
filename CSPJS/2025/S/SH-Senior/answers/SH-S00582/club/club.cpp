#include<bits/stdc++.h>
using namespace std;
#define N 100010
//file:///C:/Users/admin/AppData/Local/Temp/BNZ.6905a8b24c7175/day1.pdf
int sum[4]={0};
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(0);
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		sum[1]=sum[2]=sum[3]=ans=0;
		priority_queue<int,vector<int>,greater<int>> q[4];
		for(int i=1;i<=n;i++){
			int a,b,c; cin>>a>>b>>c;
			if(a>=max(b,c)){
				int x=a-max(b,c);
				if(sum[1]>=n/2){
					if(x<=q[1].top()) ans+=max(b,c);
					else{
						int y=q[1].top();	q[1].pop();
						q[1].push(x);
						ans+=a-y;
					}
				}else{
					q[1].push(x);
					sum[1]++;
					ans+=a;
				}
			}else if(b>=max(a,c)){
				int x=b-max(a,c);
				if(sum[2]>=n/2){
					if(x<=q[2].top()) ans+=max(a,c);
					else{
						int y=q[2].top();	q[2].pop();
						q[2].push(x);
						ans+=b-y;
					}
				}else{
					q[2].push(x);
					sum[2]++;
					ans+=b;
				}
			}else{
				int x=c-max(b,a);
				if(sum[3]>=n/2){
					if(x<=q[3].top()) ans+=max(b,a);
					else{
						int y=q[3].top();	q[3].pop();
						q[3].push(x);
						ans+=c-y;
					}
				}else{
					q[3].push(x);
					sum[3]++;
					ans+=c;
				}
			}
		}		cout<<ans<<endl;
	}
}

