#include<bits/stdc++.h>
using namespace std;
int t,n,num[10010][4],ans;

int panduan(int num[10010][4],int club_1,int club_2,int club_3,int n){
	for(int j=0;j<n;j++){
		int nmax=0;
		for(int k=0;k<=3;k++){
			if (num[j][k]>=nmax){
			nmax=num[j][k];
			} 
		}
		if (num[j][0]==nmax) club_1+=1;
		else{
			if (num[j][1]==nmax) club_2+=1;
			else club_3+=1;
		}
		ans+=nmax;
		if (club_1>(n/2) or club_2>(n/2) or club_3>(n/2)){
			for(int j=0;j<n;j++){
				for(int k=0;k<3;k++){
					if (num[j][k]==0){
						;
					}
					else{
						if (num[j][k]==nmax){
							if(club_1>(n/2)) num[j][0]=0;
							if(club_2>(n/2)) num[j][1]=0;
							if(club_3>(n/2)) num[j][2]=0;
						}
					}
				}
			}
			ans=0;
			nmax=0;
			panduan(num,0,0,0,n);
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int club_1,club_2,club_3;
		cin>>n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++) cin>>num[j][k];
		}
		panduan(num,0,0,0,n);
		cout<<ans<<endl;
		
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++) num[j][k]=0;
		}
		n=ans=club_1=club_2=club_3=0;
	}
}
