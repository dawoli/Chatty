#include<bits/stdc++.h>
using namespace std;
int n,q,sep[1005][4],ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2; cin>>s1>>s2;
		int len=s1.size()-1; int loc[2]={};
		for(int i=0,j=len;i<=j;i++,j--){
			if(s1[i]=='b') loc[0]=i;
			if(s1[j]=='b') loc[0]=j;
		}
		for(int i=0,j=len;i<=j;i++,j--){
			if(s2[i]=='b') loc[1]=i;
			if(s2[j]=='b') loc[1]=j;
		}
		sep[i][0]=loc[0];
		sep[i][1]=len-loc[0];
		sep[i][2]=loc[1];
		sep[i][3]=len-loc[1];
	}
	
	string s1,s2; cin>>s1>>s2; int len=s1.size(); int loc[2]; int sum[4]={};
	for(int i=1,j=len;i<=j;i++,j--){
		if(s1[i]=='b') loc[0]=i;
		if(s1[j]=='b') loc[0]=j;
	}
	for(int i=1,j=len;i<=j;i++,j--){
		if(s2[i]=='b') loc[1]=i;
		if(s2[j]=='b') loc[1]=j;
	}
    sum[0]=loc[0];
	sum[1]=len-loc[0];
    sum[2]=loc[1];
	sum[3]=len-loc[1];	
	
	for(int i=1;i<=n;i++){
		if(sum[0]>=sep[i][0] && sum[1]>=sep[i][1] && sum[2]>=sep[i][2] && sum[3]>=sep[i][3]){
			ans++; 
		}
	}
	cout<<ans<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}


