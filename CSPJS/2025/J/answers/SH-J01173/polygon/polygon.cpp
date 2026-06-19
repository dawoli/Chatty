#include <bits/stdc++.h>
using namespace std;
int sticklth[5001],n,i,a,j,k;
deque<int> stick;
unsigned long long ans=0,lthadd=0,isthree=0,stklast;
bool isused[5001];
void plusn(int t){
	if(isused[t]){isused[t]=0;plusn(t+1);}
	else isused[t]=1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		sticklth[a]++;
	}
	for(i=1;i<=5000;i++)
		for(j=1;j<=sticklth[i];j++) stick.push_back(i);
	while(!isused[n]){
		isthree=0;
		lthadd=0;
		for(i=0;i<n;i++)
			if(isused[i]){lthadd+=stick[i];isthree++;stklast=stick[i];}
		if(isthree>=3)
			if(lthadd>stklast*2) ans++;
		plusn(0);
	}
	cout<<ans%998244353;
	return 0;
}
