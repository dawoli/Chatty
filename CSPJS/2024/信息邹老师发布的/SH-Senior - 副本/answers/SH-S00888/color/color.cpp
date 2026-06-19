#include<bits/stdc++.h>
using namespace std;
int rx[100005];
#define count __counter______
int count[1000005];
void doProcess(){
	memset(count,0,sizeof(count));
	memset(rx,0,sizeof(rx));
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		rx[i]=x;
		count[x]++;
	}
	vector<pair<int,int>> valueInfo;
	for(int i=0;i<n;i++){
		if(count[rx[i]]<2){
			continue;
		}
		valueInfo.push_back(pair<int,int>{i,rx[i]});
	}
	int lastValues[3];
	int ans=0;
	for(pair<int,int>& v:valueInfo){
		if(lastValues[2]==v.second||lastValues[1]==v.second){
			ans+=v.second;
		}else{
			lastValues[0]=v.second;
			sort(lastValues,lastValues+3);
			if(lastValues[2]==v.second||lastValues[1]==v.second){
				ans+=v.second/3;
			}
		}
	} 
	printf("%d\n",ans);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		doProcess();
	}
	exit(0);
}
