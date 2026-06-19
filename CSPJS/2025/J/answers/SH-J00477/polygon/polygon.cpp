#include<bits/stdc++.h>
using namespace std;
int c,c1[1009],sumsticks,ans,max1=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>c1[i];
		if(max1<c1[i]) max1=c1[i];
 	}
	for(int i=1;i<=c;i++){
		sumsticks+=c1[i];
		if(sumsticks>max1*2) ans++; 
	}
	cout<<ans<<endl;
	return 0;
}
