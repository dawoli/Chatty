#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;


int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int Damn,cnt1=0,cnt0=0,lin=INT_MAX;
	bool A=1,B=1;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>Damn;
		if(Damn!=lin&&lin!=INT_MAX){
			B=0;
		}
		lin=Damn;
		if(Damn!=0&&Damn!=1){
			A=0;
		}else{
			if(Damn==1){
				cnt1++;
			}else cnt0++;
		}
	}
	
	if(A){
		cout<<cnt1/3;
		return 0;
	}
	if(B){
		cout<<n/3;
		return 0;
	}
	
	
	return 0;
}
