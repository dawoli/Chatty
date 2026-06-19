#include<bits/stdc++.h>
using namespace std;
int n=0,T=0;
int s[1000009];
int ans=0;
int DP[109][109][109];
int dns(int i,int r,int b,int choice,int ans){
	int ans1=0,ans2=0;
//	cout<<i<<" "<<r<<" "<<b<<" "<<s[i]<<" "<<ans<<endl;
	if(choice==0){
		if(s[i]==r){
			ans+=r;
		}
		else{
			r=s[i];
		}
	}
	else{
		if(s[i]==b){
			ans+=b;
		}
		else{
			b=s[i];
		}
	}
	if(i==n-1){
		return ans;
	}
	ans1=dns(i+1,r,b,0,ans);
	ans2=dns(i+1,r,b,1,ans);
	if(ans1>ans2){
		return ans1;
	}
	return ans2;
}
int DPP(){
	ans=0;

	for(int i=1;i<=100;i++){
		DP[0][s[0]][i]=10;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=100;j++){
			for(int k=1;k<=100;k++){
				DP[i][j][k]=DP[i-1][j][k];
			}
		}

		for(int j=1;j<=100;j++){
			if(DP[i][s[i]][j]==0){
				DP[i][s[i]][j]=10;
			}
			else if(DP[i][s[i]][j]==15){
				if(ans<=25)
				DP[i][s[i]][j]=25;
				else{
				DP[i][s[i]][j]=ans;	
				}
			}
			else if(DP[i][s[i]][j]>=25){
				DP[i][s[i]][j]+=s[i];
				if(ans<DP[i][s[i]][j]){
					ans=DP[i][s[i]][j];
				}			
			}
			if(DP[i][j][s[i]]==0){
				DP[i][j][s[i]]=15;
			}
			else if(DP[i][j][s[i]]==10){
				if(ans<=25)
					DP[i][j][s[i]]=25;
				else{
					DP[i][j][s[i]]=ans;

				}
			}
			else if(DP[i][j][s[i]]>=25&&j!=s[i]){
				DP[i][j][s[i]]+=s[i];
				if(ans<DP[i][j][s[i]]){
					ans=DP[i][j][s[i]];
				}
			}
		}
	}
	if(ans>=25)
		cout<<ans-25<<endl;
	else
		cout<<0<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int ZZZZZ=0;ZZZZZ<T;ZZZZZ++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		if(n<=25){
			int ans1=dns(0,-1,-1,0,0);
			cout<<ans1<<endl;	
		}
		else{
			DPP();
		}
	}
	return 0;
} 
