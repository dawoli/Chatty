#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string s[53];
	int n,q[53],k=0,sum=0;
	bool flag1=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int m=0;m<=k;m++){
			if(q[m]==i){
				flag1=1;
				break;
			}
		}
		if(flag1==1){
			flag1=0;
			continue;
		}
		for(int j=1;j<=n;j++){
			if(s[i]==s[j]&&j!=i){
				sum++;
				q[k]=j;
				k++;
			}
		}
	}
	cout<<52-n+sum<<endl;
	return 0;
} 
