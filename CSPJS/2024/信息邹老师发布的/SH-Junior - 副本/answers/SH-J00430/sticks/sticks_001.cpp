#include<bits/stdc++.h>
using namespace std;
int a[]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		bool f=0;
		for(int i=1;i<=50000000/50;++i){
			int cnp=i,cnt=0;
			while(cnp){
				cnt+=a[cnp%10];
				cnp/=10;
			}
			if(cnt==n){
				printf("%d\n",i);
				f=1;
				break;
			}
		}
		if(f==0)
		printf("-1\n");
	}
	return 0;
}
