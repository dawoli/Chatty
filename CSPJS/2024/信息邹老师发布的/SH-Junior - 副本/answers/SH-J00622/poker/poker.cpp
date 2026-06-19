#include<bits/stdc++.h>
using namespace std;
struct node{
	char col, num;
}a[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0,flag;
	cin>>n;
	for(int i=1;i<=n;i++){
		flag=0;
		getchar();
		a[i].col=getchar();
		a[i].num=getchar();
		for(int j=1;j<i;j++){
			if(a[i].col==a[j].col&&a[i].num==a[j].num){
				flag=1;
				break;
			}
		}
		if(flag==0)ans+=1;
	}
	cout<<52-ans<<endl;
	return 0;
}
