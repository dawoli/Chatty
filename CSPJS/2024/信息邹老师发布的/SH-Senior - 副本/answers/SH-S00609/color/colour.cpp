#include<bits/stdc++.h>

using namespace std;
const int N = 1000030;
int ans;
int anss[N];
int ert;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>ert;
	for(int b=0;b<ert;b++){
		int ans=0;
		int data[N],dat0[N],dat1[N],dat2[N],dat3[N],dat4[N],dat5[N],dat6[N],dat7[N],dat8[N],dat9[N];
		int num=0;
		cin>>num;
		for(int i=1;i<=num;i++){
			cin>>data[i];
		}
		for(int i=1;i<=num;i++){
			if(data[i]==0){
				dat0[i]=1;
			}
			if(data[i]==1){
				dat1[i]=1;
			}
			if(data[i]==2){
				dat2[i]=1;
			}
			if(data[i]==3){
				dat3[i]=1;
			}
			if(data[i]==4){
				dat4[i]=1;
			}
			if(data[i]==5){
				dat5[i]=1;
			}
			if(data[i]==6){
				dat6[i]=1;
			}
			if(data[i]==7){
				dat7[i]=1;
			}
			if(data[i]==8){
				dat8[i]=1;
			}
			if(data[i]==9){
				dat9[i]=1;
			}
		}
		for(int k=1;k<=num;k++){
			if (dat0[k]!=0){
				for(int n=num;n>k;n--){
					if(dat0[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat0[n]=0;
						dat0[k]=0;
					}
				}
			}
		}
		for(int k=1;k<=num;k++){
			if (dat1[k]!=0){
				for(int n=num;n>k;n--){
					if(dat1[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat1[n]=0;
						dat1[k]=0;
					}
				}
			}
		}
		for(int k=1;k<=num;k++){
			if (dat2[k]!=0){
				for(int n=num;n>k;n--){
					if(dat2[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat2[n]=0;
						dat2[k]=0;
					}
				}
			}
		}
		for(int k=1;k<=num;k++){
			if (dat3[k]!=0){
				for(int n=num;n>k;n--){
					if(dat3[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat3[n]=0;
						dat3[k]=0;
					}
				}
			}
		}
		for(int k=1;k<=num;k++){
			if (dat4[k]!=0){
				for(int n=num;n>k;n--){
					if(dat4[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat4[n]=0;
						dat4[k]=0;
					}
				}
			}
		}
		for(int k=1;k<=num;k++){
			if (dat5[k]!=0){
				for(int n=num;n>k;n--){
					if(dat5[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat5[n]=0;
						dat5[k]=0;
					}
				}
			}
		}
		for(int k=1;k<=num;k++){
			if (dat6[k]!=0){
				for(int n=num;n>k;n--){
					if(dat0[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat6[n]=0;
						dat6[k]=0;
					}
				}
			}
		}
		for(int k=1;k<=num;k++){
			if (dat7[k]!=0){
				for(int n=num;n>k;n--){
					if(dat7[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat7[n]=0;
						dat7[k]=0;
					}
				}
			}
		}
		for(int k=1;k<=num;k++){
			if (dat8[k]!=0){
				for(int n=num;n>k;n--){
					if(dat8[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat8[n]=0;
						dat8[k]=0;
					}
				}
			}
		}
		for(int k=1;k<=num;k++){
			if (dat9[k]!=0){
				for(int n=num;n>k;n--){
					if(dat9[n]!=0&&n-k!=1&&k-n!=1){
						ans+=k;
						dat9[n]=0;
						dat9[k]=0;
					}
				}
			}
		}
		anss[b]=ans;
	}
	for(int c=0;c<ert;c++){
		cout<<anss[c]<<endl;
	}
	return 0;
}
