#include<bits/stdc++.h>
using namespace std; 
char po[70][2],hs[5]={' ','D','C','H','S'},n[14]={' ','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
long num,every[70][2],ans;
int main(){
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>po[i];
	} 
	for(int i=0;i<num;i++){
		for(int j=1;j<=4;j++){
			for(int k=1;k<=13;k++){
				if(po[i][0]==hs[j]&&po[i][1]==n[k]) every[(j-1)*13+k][0]=1; every[(j-1)*13+k][1]==1;
			}
		}
	}
	for(int i=1;i<=52;i++){
		if(every[i][0]==0) ans+=1;
	}
	cout<<ans;
} 
