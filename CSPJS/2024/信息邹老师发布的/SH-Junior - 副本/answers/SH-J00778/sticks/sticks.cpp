#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll now,n,st_sum,num[5],st[5];
int T;
void number(){
	num[0]=now%10;
	num[1]=(now/10)%10;
	num[2]=(now/100)%10;
	num[3]=(now/1000)%10;
	num[4]=(now/10000)%10;
}
void stick(){
	for(int p=0;p<5;p++){
		if(num[p]==1) st[p]=2;
		else if(num[p]==7) st[p]=3;
		else if(num[p]==4) st[p]=4;
		else if(num[p]==2 || num[p]==3 || num[p]==4) st[p]=5;
		else if(num[p]==0 || num[p]==6 || num[p]==9) st[p]=6;
		else if(num[p]==8) st[p]=7;
		st_sum+=st[p];
	}
	if(num[4]==0){
		st_sum-=st[4];
		if(num[3]==0){
			st_sum-=st[3];
			if(num[2]==0){
				st_sum-=st[2];
				if(num[1]==0) st_sum-=st[1];
			}
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		now=1;
		while(true){
			st_sum=0;
			number();
			stick();
			if(st_sum==n){
				cout<<now<<endl;
				break;
			}
			now++;
		}
	}
	return 0;
} 
