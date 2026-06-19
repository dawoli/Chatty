#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("club.in");
	ofstream fout("club.out");
	int T;
	fin>>T;
	long long answer[10]={0};
	for(int t=0;t<T;t++){
		int acnt=0,bcnt=0,ccnt=0;
		int ans=0;
		int a[100005]={0},b[100005]={0},c[100005]={0};
		int club[100005]={0};
		int n;
		fin>>n;
		for(int i=0;i<n;i++){
			fin>>a[i]>>b[i]>>c[i];
			
			if(a[i]>=b[i]&&a[i]>=c[i]){
				acnt++;
				ans=ans+a[i];
				club[i]=1;
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				bcnt++;
				ans=ans+b[i];
				club[i]=2;
			}
			else if(c[i]>=b[i]&&c[i]>=a[i]){
				ccnt++;
				ans=ans+c[i];
				club[i]=3;
			}
		}
		
		while(acnt>n/2){
			if(acnt<=n/2)	break;
			acnt--;
			int mina=9999999;
			for(int i=0;i<n;i++){
				int d=min(a[i]-b[i],a[i]-c[i]);
				if(d<mina&&club[i]==1){
					mina=d;
					a[i]=99999999;
				}
			}
			ans=ans-mina;	
		}
		
		while(bcnt>n/2){
			if(bcnt<=n/2)	break;
			bcnt--;
			int minb=9999999;
			for(int i=0;i<n;i++){
				int d=min(b[i]-a[i],b[i]-c[i]);
				if(d<minb&&club[i]==2){
					minb=d;
					b[i]=99999999;
				}
			}	
			ans=ans-minb;
		}
		
		while(ccnt>n/2){
			if(ccnt<=n/2)	break;
			ccnt--;
			int minc=9999999;
			for(int i=0;i<n;i++){
				int d=min(c[i]-a[i],c[i]-b[i]);
				if(d<minc&&club[i]==3){
					minc=d;
					c[i]=99999999;
				}
			}	
			ans=ans-minc;
		}
		answer[t]=ans;
	}
	for(int t=0;t<T;t++){
		fout<<answer[t]<<endl;
	}
	return 0;
} 

