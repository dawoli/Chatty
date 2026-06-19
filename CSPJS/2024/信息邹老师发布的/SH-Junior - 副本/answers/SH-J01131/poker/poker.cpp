#include<bits/stdc++.h>
using namespace std;
//#define int long long
int A[500];

signed main(){
	ios::sync_with_stdio(false);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0,ans=0;string a;
	cin>>n;
	while(n--){
		cin>>a;
		if(a[0]=='D'){
			cnt+=100;
		}
		if (a[0]=='C'){
			cnt+=200;
		}
		if (a[0]=='H'){
			cnt+=300;
		}
		if (a[0]=='S'){
			cnt+=400;
		}
		if (a[1]=='A'){
			cnt+=1;
		}
		if (a[1]=='T'){
			cnt+=10;
		}
		if (a[1]=='J'){
			cnt+=11;
		}
		if (a[1]=='Q'){
			cnt+=12;
		}
		if (a[1]=='K'){
			cnt+=13;
		}
		if (a[1]=='2' or a[1]=='3' or a[1]=='4' or a[1]=='5' or a[1]=='6' or a[1]=='7' or a[1]=='8' or a[1]=='9'){
			cnt+=int(a[1]);
		}
		A[cnt]+=1;
		cnt=0;
		
		
		
	}
	for (int i=1;i<=500;i++){
		if (A[i]!=0){
			ans+=1;
		}
		
	}
	cout<<52-ans;
	
	
	return 0;
}
