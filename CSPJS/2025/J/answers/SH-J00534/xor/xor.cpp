#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n3l[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int no=a[0];
	int ans1=0;
	for(int i=0;i<n;i++){
		no^=a[i];
		if(no==k){
			ans1++;
			no=a[i+1];
			i++;
		}
	}
	int no2=0;
	int ans2=0;
	for(int i=0;i<n;i++){
		no2^=a[i];
		if(no2==k||a[i]==k){
			ans2++;
			no2=a[i+1];
			i++;
		}
	}
	int no3=0;
	int ans3=0;
	int js=1,tjs=0;
	int i;
	for(i=0;i<n;i++){
		js++;
		for(int j=tjs;j<tjs+js;j++){
			n3l[j]^=a[i];
			if(n3l[j]==k){
				ans3++;
				tjs=i+1;
				i++;
				js=1;
			}
		}
	}
	cout<<max(max(ans1,ans2),ans3);
} 
