#include<bits/stdc++.h>
using namespace std;
int s[100005]={0};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int N;cin>>N;
	for(int i=0;i<N;i++){
		int x;cin>>x;
		s[x]++;
	}
	int ans=0,tmp=0,num=0;
	for(int i=1;i<100000;i++){
		if(s[i]!=0){
			if(num-ans>=s[i])ans+=s[i];
			else {
				ans+=num-ans;
			}

			num+=s[i];
		}
		if(num==N)break;
	}
	cout<<N-ans;	

} 
