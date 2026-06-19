#include<bits/stdc++.h>
using namespace std;
int n,a[100005][5],ans,maxm;
void dfs(int person,int count1,int count2,int count3,int cur) {
	if(person==n) {
		maxm=max(maxm,cur);
		return;
	}
	if(count1<n/2) {
		dfs(person+1,count1+1,count2,count3,cur+a[person][1]);
	}
	if(count2<n/2) {
		dfs(person+1,count1,count2+1,count3,cur+a[person][2]);
	}
	if(count3<n/2) {
		dfs(person+1,count1,count2,count3+1,cur+a[person][3]);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++) {
		cin>>n;
		for(int j=0;j<n;j++) {
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		dfs(0,0,0,0,0);
		cout<<maxm<<endl;                          
		maxm=0;
	}
	return 0;
}
