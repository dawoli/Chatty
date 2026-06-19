#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long n,r[N],cnt;
bool vst[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	long long large=2;
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		while(r[large]==r[i] and large<=n){ 
			large++;
		}
		while(vst[large] and large<=n){  
			large++;
		}
		if(large<=n){
			cnt++;
			vst[large]=1;
		}
		else{
			break;
		}
	}
	cout<<n-cnt;
	return 0;
} 
