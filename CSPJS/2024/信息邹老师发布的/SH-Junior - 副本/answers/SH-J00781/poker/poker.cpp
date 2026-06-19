#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[27][14];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x,y;
		int p,q;
		cin>>x>>y;
		if(y=='A'){
			q=1;
		}
		else if(y=='T'){
			q=10;
		}
		else if(y=='J'){
			q=11;
		}
		else if(y=='Q'){
			q=12;
		}
		else if(y=='K'){
			q=13;
		}
		else{
			q=(y-'0');
		}
		p=x-'A';
		if(a[p][q]==0){
			a[p][q]++;
			cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
}
