#include<bits/stdc++.h>
using namespace std;
int n,k,a[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	set<int> s;
	s.insert(0);
	int x=0;
	for(int i=1;i<=n;i++){
		x^=a[i];
		if(s.count(x^k)){
			cnt++;
			x=0;
			s.clear();
		}else{
			s.insert(x);
		}
		s.insert(0);
	}
	cout<<cnt;
	return 0;
}
