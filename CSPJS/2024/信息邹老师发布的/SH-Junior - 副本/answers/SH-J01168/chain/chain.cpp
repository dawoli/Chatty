#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		int l[100010][200010];
		for(int i=0;i<n;i++){
			int li;
			cin>>li;
			for(int j=0;j<li;j++){
				cin>>l[i][j];
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			int a=0,b=0;
			for(int i=0;i<n;i++){
				if(l[i][1]==r){
					a++;
				}
				if(l[i][-1]==c){
					b++;
				}
			}
			if(a==0 || b==0){
				cout<<0<<endl;
			}else{
				cout<<1<<endl;
			}
		}
	};
	return 0;
}
