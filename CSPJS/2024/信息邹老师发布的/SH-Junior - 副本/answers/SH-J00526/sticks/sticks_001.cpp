#include <bits/stdc++.h>
using namespace std;
string s2;
int ans=0;
int sz[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	int n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(n%7==1&&n!=1){
			printf("10");
			n-=8;
			for(int i=1;i<=n/7;i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		ans=0;
		s2="";
		while(n>21){
			n-=7;
			s2+="8";
		}
		int g,s,b;
		bool flag=false;
		for(int i=1;i<=999;i++){
			g=i%10;
			b=i/100;
			s=(i%100)/10;
			if(i<100){
				if(i<10){
					if(sz[i]==n){
						cout<<i<<s2<<'\n';
						flag=true;
						break;
					}
				}
				else if(sz[g]+sz[s]==n){
					cout<<i<<s2<<'\n';
					flag=true;
					break;
				}
			}
			else if(sz[g]+sz[s]+sz[b]==n){
				cout<<i<<s2<<'\n';
				flag=true;
				break;
			}
		}
		if(!flag){
			printf("-1\n");
		}
		
	}
	return 0;
}
