#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+100;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n ,atk[MAXN]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>atk[i];
	}
	sort(atk,atk+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<atk[i];
//	}
	int ans=n,num=1,almin=1;
//	bool alive[MAXN]={1};
	while(num<=n){
		num++;
		if(atk[num]>atk[almin]){
//			cout<<atk[num]<<"k"<<atk[almin]<<endl;
//			alive[almin]=false;
			almin++;
			ans--;
		}
	}
	cout<<ans;
	return 0;
} 
