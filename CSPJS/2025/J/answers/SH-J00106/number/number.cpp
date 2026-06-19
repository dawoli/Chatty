#include <bits/stdc++.h>
using namespace std;
int a[1000110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int d=0;
	cin>>n;
	for(int i=0;i<=n.size()-1;i++){
		if(n[i]>='0'&&n[i]<='9'){
			d++;
			a[d]=n[i]-'0';
		}
	}
	sort(a+1,a+d+1);
	for(int i=d;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
