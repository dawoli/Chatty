#include<bits/stdc++.h>
using namespace std;

priority_queue<int> p;
int n,m,a;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int c;
		cin>>c;
		if(i==1)a=c;
		p.push(c);
	}
	int k=0;
	while(!p.empty()){
		int x=p.top();
		p.pop();
		k++;
		if(x==a){
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k--;
				if(k==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				k--;
				if(k==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
