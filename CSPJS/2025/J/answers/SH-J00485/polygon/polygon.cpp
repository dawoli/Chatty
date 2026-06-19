#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int n;
vector<int> a;
void calc(int sum,int k,int pre){
	if(pre==n){
		return ;
	}
	for(int i=pre+1;i<=n;i++){
		if(a[i]<sum&&k>=2) cnt++;
		calc(sum+a[i],k+1,i);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a.resize(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	calc(0,0,0);
	cout<<cnt;
	return 0;
}
