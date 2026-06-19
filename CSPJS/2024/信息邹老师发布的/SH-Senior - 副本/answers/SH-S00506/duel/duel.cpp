#include<bits/stdc++.h>
#define N 100009
using namespace std;
int n,r[N],cnt,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		r[k]++;
	}
	cout<<*max_element(r+1,r+100000)<<endl;
	return 0;
}
