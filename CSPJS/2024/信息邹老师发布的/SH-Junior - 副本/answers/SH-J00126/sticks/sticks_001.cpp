#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[7]={make_pair(0,6),make_pair(6,6),make_pair(1,2),make_pair(2,5),make_pair(4,4),make_pair(7,3),make_pair(8,7)};
int solve(int k){
	int temp=100;
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			if(a[i].second+a[j].second==k && a[i].first!=0){
				temp=min(a[i].first*10+a[j].first,temp);
			}
		}
	}
	return temp;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	int n;
	scanf("%d",&t);
	for(int ti=0;ti<t;ti++){
		scanf("%d",&n);
		int temp;
		if(n<=7){
			if(n==1){
				printf("%d\n",-1);
				continue;
			}
			for(int i=0;i<7;i++){
				if(a[i].second==n) temp=a[i].first;
			}
			if(temp==0) temp=6;
			printf("%d\n",temp);
			continue;
		}
		else if(n>7 && n<14){
			printf("%d\n",solve(n));
			continue;
		}
		if(n%7==0){
			int ans=0,p=n/7;
			for(int i=0;i<p;i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		int n8=n/7-1,nr=n%7+7;
		nr=solve(nr);
		printf("%d",nr);
		for(int i=0;i<n8;i++){
			printf("8");
		}
		printf("\n");
	}
	return 0;
}
