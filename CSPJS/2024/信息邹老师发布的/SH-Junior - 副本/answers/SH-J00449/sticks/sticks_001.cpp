#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){
			printf("-1\n");
			continue;
		}
		int k=n/7,yu=n%7;
		string s;
		for(int i=1;i<=k;i++){
			s+='8';
		}
		if(yu==0)cout<<s;
		else if(yu==1){
			cout<<"10";
			for(int i=1;i<k;i++){
				cout<<"8";
			}
		}else if(yu==2){
			cout<<"1";
			cout<<s;
		}else if(yu==3){
			if(k>=2){
				cout<<"200";
				for(int i=1;i<=k-2;k++){
					cout<<"8";
				}
			}else if(k==1)cout<<"20";
			else cout<<"7";
		}else if(yu==4){
			if(k>=1){
				cout<<"20";
				for(int i=1;i<=k-1;i++)cout<<"8";
			}else cout<<"4";
		}else if(yu==5){
			cout<<"2";
			cout<<s;
		}else if(yu==6){
			cout<<"6";
			cout<<s;
		}
		printf("\n");
	}
	return 0;
}
