#include<bits/stdc++.h>
using namespace std;
long long ansers[10000];
int usestick[8]={-1,-1,1,7,4,2,0,8};
long long putstick(int sticknum,long long number,long long minans){
	if(sticknum<=1) return 0;
	if(ansers[sticknum]) return ansers[sticknum];
	if(sticknum<=7){
		for(int i=2;i<=7;i++){
			if((sticknum==i&&number+usestick[i])&&number+usestick[i]<minans){
				minans=number+usestick[i];
			}
		}
		return minans;
	}bool first;
	if(number==0) first=1;
	for(int i=2;i<=7;i++){
		long long nowans;
		if(first&&i==6){
			first=0;
			nowans=putstick(sticknum-i,(number+6)*10,minans);
		}
		else nowans=putstick(sticknum-i,(number+usestick[i])*10,minans);
		if(nowans&&nowans<minans) minans=nowans;
	}ansers[sticknum]=minans;
	return minans;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	int sticknum[T];
	for(int i=0;i<T;i++) cin>>sticknum[i];
	for(int i=0;i<T;i++){
		if(sticknum[i]%8==0){
			for(int j=0;j<sticknum[i]/8;j++) printf("8");
			cout<<"\n";
			continue;
		}
		if(sticknum[i]%8==1){
			cout<<"-1"<<"\n";
			continue;
		}
		if(sticknum[i]==6){
			cout<<"6"<<"\n";
			continue;
		}
		long long ans=putstick(sticknum[i],0,9e18);
		if(ans) cout<<ans;
		else cout<<"-1";
		cout<<"\n";
	}
	return 0;
}
