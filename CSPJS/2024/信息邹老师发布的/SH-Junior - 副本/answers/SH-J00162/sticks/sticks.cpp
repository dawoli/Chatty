#include<bits/stdc++.h>
using namespace std;
int n_s[10]={6,2,5,5,4,5,6,3,7,6};
int hs_n[8]={10,10,1,7,4,2,0,8};
int nhs_n[8]={10,10,1,7,4,2,6,8};
int main(){
	//*
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	/**/
	int n,tt,tmax,vmax;
	cin>>tt;
	int shang,yu,len;
	char head,tmp;
	char num[5005];
	for(int turn=0;turn<tt;turn++){
		cin>>n;
		shang=n/n_s[8];
		yu=n-shang*n_s[8];
		head=nhs_n[yu]+'0';
		if(yu==0){
			for(int i=0;i<shang;i++)num[i]='8';
		}else if(yu==1){
			for(int i=0;i<shang-1;i++)num[i]='8';
			num[shang]='0';
			num[shang+1]='1';
		}else{
			for(int i=0;i<shang;i++)num[i]='8';
			num[shang]=head;
		}
		len=strlen(num);
		if(yu!=1)
		for(int i=len-1;i>0;i++){
			vmax=10;
			tmax=0;
			//...---...²»»á×ö 
			for(int j=0;j<n_s[num[i-1]-'0'];j++){
				if(n_s[num[i]]-'0'+j>7)break;
				if(i==len-1?nhs_n[n_s[num[i]]-'0'+j]:hs_n[n_s[num[i]]-'0'+j]<vmax){
				vmax=i==len-1?nhs_n[n_s[num[i]]-'0'+j]:hs_n[n_s[num[i]]-'0'+j];
				tmax=j;
				}
			}
			num[i]=vmax==10?num[i]:vmax+'0';
			num[i-1]-=tmax;
		}
		for(int i=len-1;i>(len-1)/2;i++){
			tmp=num[len-1];
			num[len-1]=num[len-1-i];
			num[len-1-i]=tmp;
		}
		cout<<num;
	}
}
