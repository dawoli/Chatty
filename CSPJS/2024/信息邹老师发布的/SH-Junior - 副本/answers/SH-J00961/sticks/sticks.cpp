#include<bits/stdc++.h>
using namespace std;
int st[10]={6,2,5,5,4,5,6,3,7,6};
int t,n;
/*void dfs(int a,int P){
	if(a==0){
		minn=d
	}
	if(t==0){
		
	}
}*/
int main(){
	ifstream fin("sticks.in");
	ofstream fout("sticks.out");
	fin>>t;
	for(int i=1;i<=t;i++){
		fin>>n;
		if(n<=40){
			for(int i=1;i<=1000000;i++){
				int i1=i,sum=0;
				while(i1!=0){
					sum+=st[i1%10];
					i1/=10;
				}
				if(sum==n){
					fout<<i<<endl;
					break;
				}
				if(i==1000000){
					fout<<-1<<endl;
				}
			}
		}else{
			//fout<<n%7<<" "<<n/7<<endl;
			if(n%7==0){
				for(int i=1;i<=n/7;i++){
					fout<<8;
				}
				fout<<endl;
			}
			if(n%7==1){
				fout<<10;
				for(int i=1;i<=n/7-1;i++){
					fout<<8;
				}
				fout<<endl;
			}
			if(n%7==2){
				fout<<18;
				for(int i=1;i<=n/7-1;i++){
					fout<<8;
				}
				fout<<endl;
			}
			if(n%7==3){
				fout<<200;
				for(int i=1;i<=n/7-2;i++){
					fout<<8;
				}
				fout<<endl;
			}
			if(n%7==4){
				fout<<20;
				for(int i=1;i<=n/7-1;i++){
					fout<<8;
				}
				fout<<endl;
			}
			if(n%7==5){
				fout<<2;
				for(int i=1;i<=n/7;i++){
					fout<<8;
				}
				fout<<endl;
			}
			if(n%7==6){
				fout<<6;
				for(int i=1;i<=n/7;i++){
					fout<<8;
				}
				fout<<endl;
			}
		}
	}
	fin.close();
	fout.close();
	return 0;
}
