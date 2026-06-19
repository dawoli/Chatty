#include<bits/stdc++.h>
using namespace std; 
int val[500010],k;
int calc(int i,int n){
	int cnt=0,sum=0;
	for(int i=i;i<n;i++){
		for(int j=i;j<n;j++){
			if(i==j) sum=val[i];
			else sum=sum^val[j];
			if(sum==k){
				//cout<<i<<" "<<j<<endl; 
				//cnt+=max(1,calc(i+1,j));
				cnt++;
				i=j;
			} 
		}
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	cout<<calc(0,n);
	return 0; 
}
