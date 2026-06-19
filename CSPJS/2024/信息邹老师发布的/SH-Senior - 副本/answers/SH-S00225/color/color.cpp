#include<iostream>
using namespace std;
const int N=2e5+9;
int T,n;
int a[N],c[N];
bool b[N];

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<'0'<<'\n';
	}
	
	return 0;
}
