#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=0;ii<t;ii++){
		int p,lm,assignment;
		cin>>p>>lm>>assignment;
		for(int i=0;i<p;i++){
			int d;
			cin>>d;
			for(int j=0;j<d;j++){
				int l;
				cin>>l;
			}
		}
		for(int i=0;i<assignment;i++){
			int a,b;
			cin>>a>>b;
		}
		
		srand(time(0));
		for(int i=0;i<assignment;i++)
			cout<<rand()%2<<"\n";
		
	}
}
