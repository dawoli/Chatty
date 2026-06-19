#include<bits/stdc++.h>
using namespace std;
#define int long long
int g1,g2,g3;
signed main(){
//reopen("club.in",num);
//reopen("club.in",n);
	//int num;
	int cnt1=0,cnt2=0,cnt3=0;
	int sum=0;
	//cin>>num;
	int n;
	//for(int i=1;i<=num;i++){
	//reopen("club.in",g1);
	//reopen("club.in",g2);
	//reopen("club.in",g3);
		cin>>n;
		for(int j=1;j<=n;j++){
		cin>>g1>>g2>>g3;
		sum+=max(g1,g2,g3);
		if(max(g1,g2,g3)==g1) cnt1++;
		if(max(g1,g2,g3)==g2) cnt2++;
		if(max(g1,g2,g3)==g3) cnt3++;
		}	
		cout<<sum<<endl;
		cout<<cnt1<<" "<<cnt2<<" "<<cnt3;
	//}
} 
