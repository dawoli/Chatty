#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n,num=0,num0=0,num1=0,num2=0;
		cin>>n;
		int a[100050][4];
		for(long long i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				a[i][3]=0;
				num+=a[i][0];
				num0++;
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				a[i][3]=1;
				num+=a[i][1];
				num1++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
				a[i][3]=2;
				num+=a[i][2];
				num2++;
			}
		}
		if(num0>n/2){
			int x[100000]={0};
			int q=0;
			for(int i=0;i<n;i++){
				if(a[i][3]==0){
					x[q]=a[i][0]-max(a[i][1],a[i][2]);
					q++;
				}
			}
			sort(x,x+q);
			for(int i=0;i<num0-n/2;i++){
				num-=x[i];
			}
		}
		else if(num1>n/2){
			int x[100000]={0};
			int q=0;
			for(int i=0;i<n;i++){
				if(a[i][3]==1){
					x[q]=a[i][1]-max(a[i][0],a[i][2]);
					q++;
				}
			}
			sort(x,x+q);
			for(int i=0;i<num1-n/2;i++){
				num-=x[i];
			}
		}
		else if(num2>n/2){
			int x[100000]={0};
			int q=0;
			for(int i=0;i<n;i++){
				if(a[i][3]==2){
					x[q]=a[i][2]-max(a[i][1],a[i][0]);
					q++;
				}
			}
			sort(x,x+q);
			for(int i=0;i<num2-n/2;i++){
				num-=x[i];
			}
		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
