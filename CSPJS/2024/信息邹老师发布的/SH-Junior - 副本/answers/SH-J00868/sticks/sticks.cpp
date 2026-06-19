#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;

int k[11]={6,2,5,5,4,5,6,3,7,6};

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n<2){
			cout<<-1<<'\n';
			continue;
		}
		int m=n/7+1;
		for(int i=1;i<=m;i++){
			bool f=0;
			for(int j=0;j<=9;j++){
				if((i==1&&j==0)||f)continue;
				if(n<=7){
					for(int l=0;l<=9;l++){
						if(i==1&&l==0)continue;
						if(k[l]==n){
							cout<<l;
							break;
						}
					}
					break;
				}
				if(n-k[j]<=(m-i)*7){
					cout<<j,n-=k[j];
					f=1;
				}
			}
		}
		cout<<'\n';
	}
	return 0;
} 
