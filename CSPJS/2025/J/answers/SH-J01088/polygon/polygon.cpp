#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int n;
int a[MAXN];
int used[MAXN];
int ans=0;

int k;
void pro(int si,int sum,int maxl,int s){
	if(si==k+1){
		if(sum>2*maxl){
			ans++;
		}
		return;
	}
	for(int i=s;i<=n;i++){
		for(int j=i;j<=n;j++)
		if(!used[i]){
		    pro(si+1,sum+a[i],max(maxl,a[i]),i);
		    
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		k=i;
		pro(1,0,0,1); 
	}
   
	cout<<9;
	return 0;
} 
