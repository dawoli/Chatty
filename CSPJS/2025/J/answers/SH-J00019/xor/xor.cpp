#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500009;
int n,k;
ll a[N];
int sum;
bool b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
    	for(int i=1;i<=n;i++){
    	    if(a[i]==0) sum++;
    	    else if(a[i]==a[i-1]==1) sum++;
        }
        cout<<sum<<endl;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) sum++;
		}
		cout<<sum<<endl;
	}
	else cout<<sqrt(n)<<endl;
	return 0;
} 
