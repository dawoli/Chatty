#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=52;
	cin>>n;
	string c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==1){
		cout<<51;
		return 0;
	}
	cnt=cnt-n;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(c[i]==c[j]){
				cnt=cnt+1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
