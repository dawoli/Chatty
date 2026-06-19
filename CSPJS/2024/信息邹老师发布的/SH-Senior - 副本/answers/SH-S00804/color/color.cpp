#include <bits/stdc++.h>
using namespace std;
const int N=2e5+9;
long long T,a[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n<<endl;
	}
}
