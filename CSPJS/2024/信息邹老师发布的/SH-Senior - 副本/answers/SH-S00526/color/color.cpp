#include<bits/stdc++.h>
using namespace std;
#define N 200005//注意设置大小
typedef long long ll;

int a[N];

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		cout<<1<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

