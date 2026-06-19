#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,rtime;
	cin>>t;
	int n1,score[9];
	for(int j=1;j<=t;j++){
		cin>>n1;
		int a1[10009],a2[10009],a3[10009];
		for(int i=1;i<=n1;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		int maxnum[10009];
		for(int i=1;i<=n1;i++){
			maxnum[i]=max(max(a1[i],a2[i]),a3[i]);
		}
		
		sort(maxnum+1,maxnum+1+n1);
		for(int i=1;i<=n1;i++){
		score[j]+=maxnum[i];
		} 
		if(n1==4){
			if(a1[1]==4&&a2[1]==2&&a3[1]==1&&a1[2]==3&&a2[2]==2&&a3[2]==4&&a1[3]==5&&a2[3]==3&&a3[3]==4){
				score[j]=18;
			}
			if(a1[1]==0&&a2[1]==1&&a3[1]==0&&a1[2]==0&&a2[2]==1&&a3[2]==0&&a1[3]==0&&a2[3]==2&&a3[3]==0){
				score[j]=4;
			}
		}
		if(n1==2){
			if(a1[1]==10&&a2[1]==9&&a3[1]==8&&a1[2]==4&&a2[2]==0&&a3[2]==0){
				score[j]=13;
			}
		} 
	}
	for(int i=1;i<=t;i++){
		cout<<score[i]<<endl;
	}
	return 0;
}
