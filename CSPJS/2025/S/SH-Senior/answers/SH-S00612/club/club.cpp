#include<bits/stdc++.h>
using namespace std;
struct student{
	int sata,satb,satc;
};
bool is(int cnt[],int tar){
	for(int i=0;i<3;i++){
		if(cnt[i]>tar) return false;
	}
	return true;
}
/*
int add(student a[],int n){
	int tot[n]={0};
	
}
*/
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	int cnt[3]={0};
	int ans=0;
	while(t--){
		int n;
		cin>>n;
		int nhalf=n/2;
		student a[n];
		int b[n]={0};
		for(int i=0;i<n;i++){
			cin>>a[i].sata>>a[i].satb>>a[i].satc;
			b[i]=max(a[i].sata,max(a[i].satb,a[i].satc));
			if(b[i]==a[i].sata){
				cnt[0]++;
			}
			else if(b[i]==a[i].satb){
				cnt[1]++;
			}
			else{
				cnt[2]++;
			}
		}
		for(int i=0;i<n;i++){
			ans+=b[i];
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
