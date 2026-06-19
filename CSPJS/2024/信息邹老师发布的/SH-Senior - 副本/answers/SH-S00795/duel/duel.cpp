#include <bits/stdc++.h>
using namespace std;
int a[100005];
map<int,int> r;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=1;
	for(int i=1;i<=n;i++) r[a[i]]++;
	int ans=n;
	int bf=0;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) bf+=r[a[i-1]];
		if(bf!=0) bf--;
	}
	bf+=r[a[n]];
	cout<<bf;
	return 0;
} 
