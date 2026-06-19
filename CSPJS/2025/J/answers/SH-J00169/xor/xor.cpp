#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],bj[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=0;
	int n,r;
	cin>>n>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(bj[i]) break;
			int sum=a[i];
			bool flag=1;
			for(int p=i+1;p<=j;p++){
				sum=(sum^a[p]);
				if(bj[p]) flag=0;
			}
			if(sum==r && flag==1){
				for(int p=i;p<=j;p++) bj[p]=1;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
