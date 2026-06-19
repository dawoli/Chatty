#include<bits\stdc++.h>
using namespace std;
int t,n[10],cnt[10],a[100010][5],num0[10],num1[10],num2[10],check;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=0;o<t;o++){
		cin>>n[t];
		for(int j=0;j<n[t];j++)
			cin>>a[j][0]>>a[j][1]>>a[j][2]; 
		for(int i=0;i<n[t];i++){
			if(a[i][0]==max(a[i][0],max(a[i][1],a[i][2]))){
				
				if(num0[t]<n[t]/2){cnt[t]+=a[i][0]; num0[t]++;}
				else if(a[i][1]==max(a[i][1],a[i][2])){cnt[t]+=a[i][1]; num1[t]++;}
				else {cnt[t]+=a[i][2]; num2[t]++;}
			}
			else if(a[i][1]==max(a[i][0],max(a[i][1],a[i][2]))){
				if(num1[t]<n[t]/2){cnt[t]+=a[i][1]; num1[t]++;}
				else if(a[i][0]==max(a[i][0],a[i][2])){cnt[t]+=a[i][0]; num0[t]++;}
				else {cnt[t]+=a[i][2]; num2[t]++;}
			}
			else if(a[i][2]==max(a[i][0],max(a[i][1],a[i][2]))){
				if(num2[t]<n[t]/2){cnt[t]+=a[i][2]; num2[t]++;}
				else if(a[i][1]==max(a[i][1],a[i][0])){cnt[t]+=a[i][1]; num1[t]++;}
				else {cnt[t]+=a[i][0]; num0[t]++;}
			}
		}
		cout<<cnt[t];
		cnt[t]=0;
	}
	return 0;
}
