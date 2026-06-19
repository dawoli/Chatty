#include<bits/stdc++.h>
using namespace std;
long long a[100009],n;
//string ;
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=2;
	for(int i=1;i<=n;i++){
		if(a[r]>a[l]) l++;
		r++;
	}
	cout<<n-l+1;
	return 0;
} //pdf pwd Z*L#LH%9
//rp++ 
