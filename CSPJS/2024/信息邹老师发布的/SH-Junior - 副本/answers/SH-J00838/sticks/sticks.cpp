#include<bits/stdc++.h>
using namespace std;
int n;
int a[15]={6,2,5,5,4,5,6,3,7,6};
int as[15]={1,5,2,2,3,2,1,4,0,1};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		int wei=n/7;
		if(n%7!=0)wei++;
		int x=wei*7-n;
		for(int i=1;i<=wei;i++){
			if(x==0){
				cout<<8;
				continue;
			}
			for(int j=0;j<=9;j++){
				if(i==1&&j==0)continue;
				if((x>=as[j]&&i!=wei)||(x==as[j]&&i==wei)){
					x-=as[j];
					cout<<j;
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
