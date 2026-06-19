#include<bits/stdc++.h>
using namespace std;
long long T,n,m,l,v,car[4514][4];
int bs[1919810],dp[1145141],dp2[1145141];
long long cart[4514],cartn=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T){
		T--;
		cin>>n>>m>>l>>v;
		//carset
		cartn=0;
		for(int i=1;i<=n;i++){
			int d,vc,ac;
			cin>>d>>vc>>ac;
			if(ac>0){
				if(vc>v){
					cartn++;
					cart[cartn]=l*1e9+d;
				}
				if(vc==v&&d<l){
					cartn++;
					cart[cartn]=l*1e9+d+1;
				}
				if(vc<v){
					long long numc=d+(v*v-vc*vc)/(2*ac);
				    if(numc<l){
				    	cartn++;
				    	cart[cartn]=l*1e9+numc+1;
					}
		        }
			}
		    if(ac==0&&vc>v){
		    	cartn++;
		    	cart[cartn]=l*1e9+d;
			}
			if(ac<0&&vc>v){
				long long numc=d+(vc*vc-v*v)/(2*ac*(-1));
				if((vc*vc-v*v)%(2*ac)==0){
					numc--;
				}
				cartn++;
				cart[cartn]=min(numc,l)*1e9+d;
			}
		}
		sort(cart+1,cart+cartn+1);
		for(int i=1;i<=cartn;i++){
			long long temp=cart[i]/1e9;
			car[i][1]=cart[i]-1e9*1ll*temp;
			car[i][2]=cart[i]/1e9;
			car[i][3]=0;
			//cout<<cart[i]<<" "<<temp<<endl;
			//cout<<car[i][1]<<" "<<car[i][2]<<" "<<endl;
		}
		//detectset
		for(int i=0;i<=l;i++)bs[i]=0;
		for(int i=1;i<=m;i++){
			int pt;
			cin>>pt;
			bs[pt]++;
		}
		for(int i=0;i<=l;i++)dp[i]=0;
		dp[0]=-1;
		for(int i=0;i<=l;i++){
			if(bs[i])dp[i]=i;
			else{
				if(i>0)dp[i]=dp[i-1];
			}
			//cout<<dp[i]<<" ";
		}
		//outp 1
		long long ans1=0;
		for(int i=1;i<=cartn;i++){
			if(dp[car[i][2]]>=car[i][1]){
				ans1++;
				car[i][3]=1;
				//cout<<i<<" ";
			}
			if(dp[car[i][2]]>car[i][2]){
				cout<<"err";
				return 0;
			}
		}
		cout<<ans1<<" ";
		//outp 2
		long long ans2=0,curc=1;
		for(int i=0;i<=l;i++)dp2[i]=0;
		dp2[0]=-1;
	    for(int i=0;i<=l;i++){
	    	if(i)dp2[i]=dp2[i-1];
	    	while(car[curc][2]==i){
	    		//cout<<car[curc][3]<<endl;
	    		if(car[curc][3]){
	    			if(dp2[i]<car[curc][1]){
	    				dp2[i]=dp[i];
	    				ans2++;
					}
				}
				curc++;
			}
			//cout<<dp2[i]<<" ";
		}
	    cout<<m-ans2<<endl;
	}
	return 0;
}
