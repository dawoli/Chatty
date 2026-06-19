#include<iostream>
#include<cmath>
using namespace std;
int num[10][2]={{0,6},{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6}};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int minn=10000000000001;
		cin>>n;
		if(n<=1){
			cout<<-1<<endl;
			continue;
		}
		if(n<=7&&n>=2){
			for(int i=1;i<=9;i++){
				if(num[i][1]==n){
					cout<<num[i][0]<<endl;
					break;
				}
			}
			continue;
		}
		if(n>7){
			if(n%7==0){
				for(int i=0;i<n/7;i++){
					cout<<8;
				}
				cout<<endl;
				continue;
			}else{
				if(n/7+1==2){
					for(int i=2;i<=7;i++){
						for(int j=2;j<=7;j++){
							int na;
							if(i+j==n){
								bool ifi=true,ifj=true;
								for(int k=0;k<=9;k++){
									if(num[k][1]==i&&num[k][0]!=0&&ifi){
										na+=num[k][0]*10;
										ifi=false;
									}
									if(num[k][1]==j&&ifj){
										na+=num[k][0];
										ifj=false;
									}
								}
								if(na<minn){
									minn=na;
								}
							}
						}
					}
				}else if(n/7+1==3){
					for(int i=2;i<=7;i++){
						for(int j=2;j<=7;j++){
							for(int l=2;l<=7;l++){
								int na;
								if(i+j+l==n){
									bool ifi=true,ifj=true,ifl=true;
									for(int k=0;k<=9;k++){
										if(num[k][1]==i&&num[k][0]!=0&&ifi){
											na+=num[k][0]*100;
											ifi=false;
										}
										if(num[k][1]==j&&ifj){
											na+=num[k][0]*10;
											ifj=false;
										}
										if(num[k][1]==l&&ifl){
											na+=num[k][0];
											ifj=false;
										}
									}
									if(na<minn){
										minn=na;
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<minn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

