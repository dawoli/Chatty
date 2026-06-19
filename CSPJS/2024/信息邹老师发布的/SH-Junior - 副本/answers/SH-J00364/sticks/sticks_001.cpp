#include<bits/stdc++.h>
using namespace std;
int n,k;
struct node{
	int tag,value;
}a[10];
int b[20000];
bool is;
void print(int pos){
	for(int i=1;i<=pos;i++){
		printf("%d",b[i]);
	}
	printf("\n");
}
void dfs(int x,int sum,int pos){
	if(x==pos+1){
		if(sum==k){
			is=true;
			print(pos);
		}
		return ;
	}
	for(int i=1;i<=7;i++){
		if(is==true)break;
		if(x==1&&i==1)continue;
		if(sum+a[i].value+7*(pos-x)>=k){
			b[x]=a[i].tag;
			dfs(x+1,sum+a[i].value,pos);
		}
		
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	a[1].tag=0,a[1].value=6;
	a[2].tag=1,a[2].value=2;
	a[3].tag=2,a[3].value=5;
	a[4].tag=4,a[4].value=4;
	a[5].tag=6,a[5].value=6;
	a[6].tag=7,a[6].value=3;
	a[7].tag=8,a[7].value=7;
	cin>>n;
	while(n--){
		is=false;
		scanf("%d",&k);
		if(k==1)cout<<"-1\n";
		else {
			int pos=k/7+1;
			if(k%7==0){
				pos--;
				for(int i=1;i<=pos;i++){
					cout<<8;
				}
				cout<<"\n";
			}
			else dfs(1,0,pos);
		}
	}
	return 0;
}
