#include<bits/stdc++.h>
using namespace std;
int a[100002]={};
int b[100002]={};
int c[100002]={};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
		a[b[i]]++;
	}
	sort(b,b+n);
	int nn=0;
	for(int i=0;i<n;i++){
		if(c[nn]!=b[i]){
			nn++;
			c[nn]=b[i];
		}
	}
	int sum=0,sumw=0;
	for(int i=1;i<=nn;i++){
		//cout<<a[c[i]]<<" ";
		if(i!=nn){
			if(a[c[i+1]]<=a[c[i]]){
				sum+=a[c[i]]-a[c[i+1]]; 
			}
			else{
				sum-=a[c[i+1]]-a[c[i]];
				if(sum<=0){
					sum=0;
				}
			}
			//cout<<a[c[i]]-a[c[i+1]]<<" "<<sum<<endl; 
		}
		else{
			sum+=a[c[i]];
		}
	}
	cout<<sum<<endl;
	return 0;
} 
