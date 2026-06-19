#include<bits/stdc++.h>
using namespace std;
int t,n;
map<int,string>mp;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	//mp[1]="-1";
	mp[2]="1";
	mp[3]="7";
	mp[4]="4";
	mp[5]="2";
	mp[6]="6";
	mp[8]="10";
	mp[10]="22";
	mp[11]="20";
	mp[17]="200";
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1)printf("-1\n");
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)printf("8");
			printf("\n");
		}
		else if((n-1)%7==0){
			printf("10");
			for(int i=1;i<=(n-8)/7;i++)printf("8");
			printf("\n");
		}
		else{
			string s;
			while(n!=2&&n!=3&&n!=4&&n!=5&&n!=6&&n!=8&&n!=10&&n!=11&&n!=17){
				s=s+"8";
				n-=7;
			};
			s=mp[n]+s;
			cout<<s<<endl;
		}
	}
	return 0;
}

