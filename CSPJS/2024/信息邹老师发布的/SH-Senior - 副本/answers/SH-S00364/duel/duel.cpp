#include<bits/stdc++.h>
using namespace std;
int n,x[100009],cnt=0;
multiset<int> m;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		m.insert(a);
	}
	int k=n;
	while(!m.empty()){
		int x1=*m.begin();
		int x2=m.count(x1);
		k-=x2;
		if(k<x2){
			cout<<x2;
			return 0;
		}
		else m.erase(x1);
	}
	return 0;
}

