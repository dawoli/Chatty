#include<bits/stdc++.h>
using namespace std;
long long T,q,lst[200005],ans=0;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	for(;T>0;T--){
		ans=0;
		cin>>q;
		for(int i=2;i<q+2;i++){
			cin>>lst[i];
			if(lst[i]==lst[i-1]||lst[i]==lst[i-2]) ans+=lst[i];	
		}
		cout<<ans<<endl;
	}
	return 0;
} 
