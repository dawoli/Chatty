#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	short T;
	cin>>T;
	while(T--){
		int n,ei=0;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;continue;
		}
		while(n>21){
			n-=7;
			ei++;
		}
		for(int ans=1;ans<=1000;ans++){
			int p=ans;
			int a=0;
			while(p){
				a+=num[p%10];
				p=p/10;
			}if(a==n){
				cout<<ans;break;
			}
		}for(int i=1;i<=ei;i++){
			cout<<8;
		}cout<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
