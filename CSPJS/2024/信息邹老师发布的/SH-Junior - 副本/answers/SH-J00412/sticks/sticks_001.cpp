#include<bits/stdc++.h>

using namespace std;
int t;
int st[17]={6,2,5,5,4,5,6,3,7,6};
int w;
int a[100007];
int now=0;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		if(n==1){
			cout<<"-1"<<endl;
			continue;
		}
		memset(a,0,sizeof(a));
		now=0;
		w=0;
		if(n%7==0){
			w=n/7;
		}
		else{
			w=n/7+1;
		}
		for(int j=1;j<=w;j++){
			for(int k=0;k<=9;k++){
				if(k==0&&j==1){
					continue;
				} 
				else{
					if(j==w){
						if(st[k]==n-now){
							a[j]=k;
							break; 
						}
					}
					else{
						if(now+st[k]+(w-j)*7>=n){
							a[j]=k;
							now=now+st[k];
							break; 
						}
					}
				}
			}
		}
		for(int p=1;p<=w;p++){
			cout<<a[p];
		}
		cout<<endl;
	}
	return 0;
} 
