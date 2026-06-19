#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,tcnt=0,cnt1[62];
	string poker[62];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>poker[i];
		cnt1[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&poker[i]==poker[j]&&cnt1[i]==1){
				cnt1[j]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt1[i]){
			tcnt++;
		}
	}
	cout<<52-tcnt;
	return 0; 
}
