#include<bits/stdc++.h>
using namespace std;
int number[200010];
int color[200010];
int ans,flag,score;
int beans(int u,int n){
	if(u==n+1){
		score=0;
		for(int i=n;i>0;i--){
			for(int j=i-1;j>0;j--){
				if(color[i]==color[j]){
					if(number[i]==number[j]){
						score+=number[i];
					}
					break;
				}
			}
		}
		ans=max(ans,score);
	}
	else{
		color[u]=1;
		beans(u+1,n);
		color[n]=0;
		beans(u+1,n);
	}
}
int main(){
	freopen("color.in","w",stdin);
	freopen("color.out","r",stdout);
	int t;
	cin>>t; 
	int n;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>number[j];
		}
		beans(1,n);
		cout<<ans<<'\n';
	}
	return 0;
}
