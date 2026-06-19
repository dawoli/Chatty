#include<bits/stdc++.h>
using namespace std;
int t;
int n;
char ans[70][15000];
int anslen[70];
int sum[14]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68};
char intandchar[10]={'0','1','2','3','4','5','6','7','8','9'};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n<14){
			if(n<2){
				anslen[i]=2;
				ans[i][1]='1';
				ans[i][2]='-';
			}
			else{
				int a=sum[n];
				while(a){
					anslen[i]++;
					ans[i][anslen[i]]=intandchar[a%10];
					a/=10;
				}
			}
		}
		else{
			int a=n;
			while(a>=14){
				anslen[i]++;
				ans[i][anslen[i]]='8';
				a-=7;
			}
			a=sum[a];
			while(a){
				anslen[i]++;
				ans[i][anslen[i]]=intandchar[a%10];
				a/=10;
			}
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=anslen[i];j>=1;j--){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
