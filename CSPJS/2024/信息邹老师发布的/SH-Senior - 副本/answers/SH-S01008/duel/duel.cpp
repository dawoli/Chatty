#include<bits/stdc++.h>
using namespace std;
int n,r[100010],cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	int p=1;
	cnt=n;
	for(int i=2;i<=n;i++){
		if(r[i]>r[p]){
			p++;
			cnt--;
		}
	}
	cout<<cnt;
	return 0;
} 
