#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int a[100010][5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int best=0;
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int tmp=max(a[i][1],max(a[i][2],a[i][3]));
			best+=tmp;
			a[i][1]=tmp-a[i][1];
			a[i][2]=tmp-a[i][2];
			a[i][3]=tmp-a[i][3];
			if(a[i][1]==0){
				c1++;
				a[i][1]=1e9;
			}
			else if(a[i][2]==0){
				c2++;
				a[i][2]=1e9;
			}
			else{
				c3++;
				a[i][3]=1e9;
			}
		}
		if(c1<=n/2&&c2<=n/2&&c3<=n/2){
			cout<<best<<"\n";
			continue;
		}
		int cpos=0;
		if(c1>n/2)cpos=1;
		else if(c2>n/2)cpos=2;
		else cpos=3;
		vector<int>cost;
		for(int i=1;i<=n;i++){
			if(a[i][cpos]==1e9){
				int tmp=0;
				if(cpos==1)tmp=min(a[i][2],a[i][3]);
				if(cpos==2)tmp=min(a[i][1],a[i][3]);
				if(cpos==3)tmp=min(a[i][2],a[i][1]);
				cost.push_back(tmp);
			}
		}
		sort(cost.begin(),cost.end());
		int del=0;
		if(cpos==1)del=c1-n/2;
		else if(cpos==2)del=c2-n/2;
		else del=c3-n/2;
		for(int i=0;i<del;i++){
			best-=cost[i];
		} 
		cout<<best<<"\n";
	} 
	return 0;
}
