#include<bits/stdc++.h>
using namespace std;
int r[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int cnt=n;
	for(int i=1;i<=n;i++)	cin>>r[i];
	sort(r+1,r+n+1);
	int pre=0;
	for(int i=1;i<=n;i++){
		if(r[i]>r[pre+1]){
			cnt--;
			pre++;
		}
	}
	cout<<cnt;
	return 0;
}

