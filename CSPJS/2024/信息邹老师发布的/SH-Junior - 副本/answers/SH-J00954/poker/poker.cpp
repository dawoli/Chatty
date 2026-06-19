#include <bits/stdc++.h>
using namespace std;
map<string,long long> a;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		string x;
		cin>>x;
		a[x]++;
	}
	cout<<52-a.size()<<endl;
} 
