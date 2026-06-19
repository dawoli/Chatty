#include<bits/stdc++.h>
using namespace std;
int n,att[100004],ali[100004],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		att[p]++;
		ali[p]++;
	}
	for(int i=1;i<=100000;i++){
		int id=i;
		while(ali[i]&&id<100000){
			id++;
			if(att[id]==0)continue;
			if(att[id]>=ali[i]){
		   	ans-=ali[i];
			att[id]-=ali[i];
		   	ali[i]=0;
		   	
		    }
			else{
			    ali[i]-=att[id];
			    ans-=att[id];
		        att[id]=0;
		        
			}  
		}
	}
			
	cout<<ans;
	
	return 0;
}
