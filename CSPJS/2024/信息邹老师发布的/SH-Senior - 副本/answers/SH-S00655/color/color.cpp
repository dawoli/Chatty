#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int t,n,m,l[10005],ans,an;
bool l2[10005];
void dp(int x){
	if (x == n){
		an=0;
		for (int i=0;i<n;i++){
			for (int j=i-1;j>=0;j--){
				if (l2[j] == l2[i] && l[j] == l[i]){
					an+=l[i];break;
				}
				else if (l2[j] == l2[i] && l[j] != l[i])break;
			}
			
		}
		ans = max(an,ans);
	}
	else{
	//	for (int i=0;i<n;i++)cout<<l2[i]<<" ";cout<<x<<endl;
		dp(x+1);
		l2[x]=!l2[x];
	//	for (int i=0;i<n;i++)cout<<l2[i]<<" ";cout<<x<<endl;
		dp(x+1);
	}
		
}
signed main(){
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for (int i=0;i<n;i++){
			cin>>l[i];
		}
		dp(0);
		for (int i=0;i<n;i++)l2[i]=0;
		cout<<ans<<endl;
	}
}
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4

15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13

15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2

*/ 
