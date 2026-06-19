#include<bits/stdc++.h>
using namespace std;
int n;
short as[92233720368547759];
int hs[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen(sticks.in,"r",stdin);
	freopen(sticks.out,"w",stdout);
	int t,n;
	cin>>t;
	for(unsigned long long i=0;i<=pow(2,63);i++){
		unsigned long long temp=i;
		while(temp){
			as[i]+=hs[temp%10];
			temp/=10;
		}
	}
	for(int q=0;q<t;q++){
		cin>>n;
		if(n<2){
			cout<<-1;
			continue;
		}
		for(unsigned long long i=1;i<=pow(2,63);i++){
			if(as[i]==n){
				cout<<i;
				continue;
			}
		}
		cout<<-1;
	}
	return 0;
} 
