#include<bits/stdc++.h>
using namespace std;
#define iM 998244353
int mg[5005],n;
int al=0;
void dfs(int s,int mx=-1,int zl=0,int ik=0){
	ik++;
	int imx=mx,izl; 
	for(int i=s+1;i<n;i++){
		if(mx<mg[i]){
			imx=mg[i];
		}
		izl=mg[i]+zl;
		if(izl>imx*2){
			if(ik>=3){
				al++;
				if(al==iM){
					al=0;
				}
			}
		}
		dfs(i,imx,izl,ik);
	}
}
int main(){
	//freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>mg[i];
	}
	dfs(-1);
	cout<<al;
	//fclose(stdin);
	fclose(stdout);
	return 0;
}
