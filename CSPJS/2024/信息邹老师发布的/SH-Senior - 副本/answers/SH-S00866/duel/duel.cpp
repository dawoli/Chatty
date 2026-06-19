#include<bits/stdc++.h>
using namespace std;
int n=0,middle=0,temp=0,a_max=-1,ans=0,max_num=-1,temp_num=0;
int a[100010]={};
int main(){
	int start_num = 0;
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	cin>>n;
	ans = n;
	for(int i=0;i<n;i++){
		cin>>temp;
		a[temp]++;
		if(temp>max_num){
			max_num=temp;
		}
	}
	while(start_num!=a_max&&start_num!=-1){
		start_num=-1;
		a_max=0;
		for(int i=1;i<=max_num;i++){
			if(a[i]>0){
					temp_num=i;
					if(start_num==-1){
						start_num=i;	
					}
				if(a_max==0){
					a_max=i;
				}
			}
			if(i>a_max&&a[i]>0){
				a[a_max]--;
				a_max=i;
				ans--;
			}
		}
		a[a_max]--;
		max_num=temp_num;
	}
	cout<<ans;
	return 0;
} 
