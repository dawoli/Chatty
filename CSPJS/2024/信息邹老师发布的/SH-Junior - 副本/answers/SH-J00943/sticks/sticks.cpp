#include<bits/stdc++.h>
using namespace std;
int v[10]={6,2,5,5,4,5,6,3,7,6};
int a[100005];
int ans=0,T,r;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>a[i];
		r=a[i];
		if(a[i]<=1) cout<<"-1"<<endl;
		else if(a[i]==2) cout<<"1"<<endl;
		else if(a[i]==3) cout<<"7"<<endl;
		else if(a[i]==4) cout<<"4"<<endl;
		else if(a[i]==5) cout<<"2"<<endl;
		else if(a[i]==6) cout<<"6"<<endl;
		else if(a[i]==7) cout<<"8"<<endl;
		else if(a[i]==8) cout<<"10"<<endl;
		else if(a[i]==9) cout<<"17"<<endl;
		else if(a[i]==10) cout<<"22"<<endl;
		else if(a[i]==11) cout<<"20"<<endl;
		else if(a[i]==12) cout<<"66"<<endl;
		else if(a[i]==13) cout<<"68"<<endl;
		else if(a[i]==14) cout<<"88"<<endl;
		else if(a[i]==15) cout<<"108"<<endl;
		else if(a[i]==16) cout<<"188"<<endl;
		else if(a[i]==17) cout<<"200"<<endl;
		else if(a[i]==18) cout<<"208"<<endl;
		else if(a[i]==19) cout<<"288"<<endl;
		else if(a[i]==20) cout<<"688"<<endl;
		else{
			for(int x=x/7;x>=0;i--){
				if(r<=7){
					for(int k=1;k<9;k++){
						if(r-a[k]==0){
							ans=pow(10,x)*r;
							r=r-a[k];
						}
					}
				}
			}
			cout<<ans<<endl;
		}

	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
