#include <bits/stdc++.h>
using namespace std;
int shu[10]={0,1,2,3,4,5,6,7,8,9};
int gun[10]={6,2,5,5,4,5,6,3,7,6};
int an[100005];
int T,n,ans=0; 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<10;j++){
			if(n==gun[j])
			    an[i]=shu[j];
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				an[i]+=8^(i-1);
			}
	}}
	for(int i=1;i<=T;i++)
		cout<<an[i]<<endl;
	return 0;
}
