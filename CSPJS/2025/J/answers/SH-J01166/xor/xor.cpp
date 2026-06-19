#include<iostream>
using namespace std;

const int N=5e5+10;
int n,k;
int a[N],b[N],loc[N],cur_loc=1, ans;
bool vst[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i] = a[i];
		if(b[i] == k) cur_loc = i+1, ans++;
		for(int j=cur_loc;j<i;j++){
			b[j] ^= a[i];
			if(b[j] == k){
				cur_loc = i+1;
				ans++;
				break;
			} 
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
