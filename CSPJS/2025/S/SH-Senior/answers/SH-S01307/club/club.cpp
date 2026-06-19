#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	int ans=0,ac=0,bc=0,cc=0;
	int a,b,c;
	int af[100010]={0},bf[100010]={0},cf[100010]={0};
	for(int i=1;i<=t;i++){
		cin>>n; 
		af[100010]={0},bf[100010]={0},cf[100010]={0},ans=0,ac=0,bc=0,cc=0;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			ans+=max(a,max(b,c));
			if(max(a,max(b,c))==a){
				ac++;
				af[ac]=min(a-b,a-c);
				
			}
			else if(max(a,max(b,c))==b){
				bc++;
				bf[bc]=min(b-a,b-c);
			}
			else{
				cc++;
				cf[cc]=min(c-a,c-b);
			}
		}
		if(ac>n/2){
			sort(af+1,af+ac);
			for(int j=0;j<ac-n/2;j++){
				ans=ans-af[j+1];
			}
		}
		else if(bc>n/2){
			sort(bf+1,bf+bc);
			for(int j=0;j<bc-n/2;j++){
				ans=ans-bf[j+1];
			}
		}
		else if(cc>n/2){
			sort(cf+1,cf+cc);
			for(int j=0;j<cc-n/2;j++){
				ans=ans-cf[j+1];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
