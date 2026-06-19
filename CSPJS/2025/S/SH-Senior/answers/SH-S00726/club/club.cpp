#include<iostream>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long a[100010][3]={},mini[100010]={},maxi[100010]={},cha[100010]={},cha2[100010]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long max1=0,max2=0,max0=0,maxmanyi=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int big,middle,small;
			if(a[i][0]>=a[i][1]&&a[i][1]>=a[i][2]){
				big=0;
				middle=1;
				small=2;
			}else if(a[i][0]>=a[i][2]&&a[i][2]>=a[i][1]){
				big=0;
				middle=2;
				small=1;
			}else if(a[i][1]>=a[i][0]&&a[i][0]>=a[i][2]){
				big=1;
				middle=0;
				small=2;
			}else if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][0]){
				big=1;
				middle=2;
				small=0;
			}else if(a[i][2]>=a[i][0]&&a[i][0]>=a[i][1]){
				big=2;
				middle=0;
				small=1;
			}else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][0]){
				big=2;
				middle=1;
				small=0;
			}maxi[i]=big;
			mini[i]=small;
			cha[i]=a[i][big]-a[i][middle];
			if(big==0)max0++;
			else if(big==1){
				max1++;
			}else{
				max2++;
			}maxmanyi+=a[i][big];
		}if(max0<=n/2&&max1<=n/2&&max2<=n/2){
			cout<<maxmanyi<<endl;
		}else{
			for(int i=0;i<n;i++){
				cha2[i]=100001;
			}
			if(max0>n/2){
				for(int i=0;i<n;i++){
					if(maxi[i]==0){
						cha2[i]=cha[i];
					}
				}
				sort(cha2,cha2+n);
//				for(int i=0;i<n;i++){
//					cout<<cha2[i]<<endl;
//				}
				int i=0;
				while(max0>n/2){
					maxmanyi-=cha2[i];
					max0--;
					i++;
				}cout<<maxmanyi<<endl;
			}if(max1>n/2){
				for(int i=0;i<n;i++){
					if(maxi[i]==1){
						cha2[i]=cha[i];
					}
				}
				sort(cha2,cha2+n);
//				for(int i=0;i<n;i++){
//					cout<<cha2[i]<<endl;
//				}
				int i=0;
				while(max1>n/2){
					maxmanyi-=cha2[i];
					max1--;
					i++;
				}cout<<maxmanyi<<endl;
			}if(max2>n/2){
				for(int i=0;i<n;i++){
					if(maxi[i]==2){
						cha2[i]=cha[i];
					}
				}
				sort(cha2,cha2+n);
//				for(int i=0;i<n;i++){
//					cout<<cha2[i]<<endl;
//				}
				int i=0;
				while(max2>n/2){
					maxmanyi-=cha2[i];
					max2--;
					i++;
				}cout<<maxmanyi<<endl;
			}
		}
	}
	return 0;
}
