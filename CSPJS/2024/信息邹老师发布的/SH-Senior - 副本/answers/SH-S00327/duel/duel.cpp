#include<iostream>
#include<algorithm>
using namespace std;

struct line{
	int num, cnt;
}c[100010];
int n,k,l=0;
int p=0,q=0;
bool flag=false;
int ans=1;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=l;j++){
			if(k==c[j].num){
				c[j].cnt+=1;
				flag=true;
			}
		}
		if(flag==false){
			c[l+1].num=k;
			c[l+1].cnt++;
			l++;
		}
		flag=false;
	}
	for(int i=1;i<=l;i++){
		if(c[i].cnt>=ans){
			ans=c[i].cnt;
	    } 
	}
	cout<<ans; 
	return 0;
}
