#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int d[10]={6,2,5,5,4,5,6,3,7,6};
const int ps=1000000;
int calc(int x){
	if(x==1)	return ps;
	int y=x/7;
	if(x%7!=0){
		y++;
	}
	return y;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue; 
		}	
		int x=n/7;
		if(n%7!=0){
			x++;
		}
		for(int i=1;i<=x;i++){
			for(int j=0;j<=9;j++){
				if(i==1 && j==0)	continue;
				if(n<d[j]){
					continue;
				}
				if(calc(n-d[j])>x-i){
					continue;
				}
				n-=d[j];
				cout<<j;
				break;
			}
		}
		cout<<endl;
	}	
	return 0;
} 
