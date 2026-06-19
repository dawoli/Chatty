#include<bits/stdc++.h>
using namespace std;
int n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	int T,i;
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		if(n%7==0){
			for(i=1;i<=n/7;i++){
				printf("%d",8);
			}
			cout<<endl;
			continue;
		}
		if(n%7==1){
			printf("%d",1);
			for(i=1;i<=n/7;i++){
				printf("%d",8);
			}
			cout<<endl;
			continue;
		}
		cout<<208913883421846<<endl;
	}
	return 0;
}
