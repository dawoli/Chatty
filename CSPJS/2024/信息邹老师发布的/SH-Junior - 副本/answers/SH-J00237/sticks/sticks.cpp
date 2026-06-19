#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int b[10]={8,0,6,9,2,3,5,4,7,1};
bool dfs(int last,int up,bool isF){
	if(last==0){
		cout<<up;
		return 1;
}
    if(last<2){
    	return 0;
	}
	for (int i=0;i<10;i++){
		if(b[i]==0){
			i++;
		}
		int d=dfs(last-a[b[i]],b[i],0);
		if(d){
			if(!isF){cout<<up;
		}
			
			return 1;
		}
	}
	return 0;
}
int main(){
	cin.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,tmp;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>tmp;
		if(!dfs(tmp,1,1)){
			cout<<-1;
		}
		cout<<endl;
	}
	

	return 0;
}
