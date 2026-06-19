#include<bits/stdc++.h>
using namespace std;
int a[1000010][2]={0},score=0;
int main(){
	int num_2_T=1;
	int T=0;
	int n=0;
	int Max=0;
	int num1=0,num0=0;
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int Tu=0;Tu<T;Tu++){
		Max=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0];
		}
		for(int i=0;i<n;i++){
			num_2_T*=2;
		}
		for(int i=0;i<num_2_T;i++){
			score=0;
			a[0][1]+=i;
			for(int j=0;j<n;j++){
				if(a[j][1]>=2){
					a[j+1][1]+=a[j][1]/2;
					a[j][1]=a[j][1]%2;
				}
			}
			for(int j=0;j<n;j++){
				if(a[j][1]==0){
					if(num0==a[j][0]) score+=num0;
					num0=a[j][0];
				}
				if(a[j][1]==1){
					if(num1==a[j][0]) score+=num1;
					num1=a[j][0];
				}
			}
			if(score>Max) Max=score;
		}
		cout<<Max<<endl;
	} 
	return 0;
} 
