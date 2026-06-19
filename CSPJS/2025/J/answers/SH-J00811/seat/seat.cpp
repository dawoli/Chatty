#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin >>n>>m;
	vector<int> a;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int g;
			cin>>g;
			a.push_back(g);
		}
	}
	x=a[0];
	int pos;
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<a.size();i++){
		if(a[i]==x){
			pos=i;
			break;
		}
	} 
	cout<<pos/n+1<<' ';
	if(pos/n%2==0){
		cout<<pos%n+1;
	}else{
		cout<<n-(pos%n);
	}
	return 0;
}
