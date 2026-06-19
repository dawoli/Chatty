#include<bits/stdc++.h>
using namespace std;
int sl[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>sl[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(sl[j]>=sl[j+1]){
				int k=sl[j];
				sl[j]=sl[j+1];
				sl[j+1]=k;
			}
		}
	} 
	int ssl=0;
	int ans=0;
	for(int x=2;x<n;x++){
		for(int i=0;i<=x;i++){
			ssl+=i; 
		}
		int ls=n;
		while(ls>x){
			if(ssl>sl[ls]){
				int ws=ls-2;
				int lsans=0;
				int lj=1;
				while(ws>1){
					lsans+=lj;
					lj++;
					ws--;
				}
				ans+=lsans;
				break;
			}
			ls--;
		}
		ssl=0;
	}
	cout<<ans;
}
