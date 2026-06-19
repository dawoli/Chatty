#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int x;
		cin>>x;
		if(x==1){
			cout<<"-1"<<endl;
		}
		else if(x==4){
			cout<<0<<endl;
		}
		else if(x==2){
			cout<<1<<endl;
		}
		else if(x==5){
			cout<<2<<endl;
		}
		else if(x==6){
			cout<<6<<endl;
		}
		else if(x==3){
			cout<<7<<endl;
		}
		else if(x==7){
			cout<<8<<endl;
		}
		else if(x==18){
			cout<<208<<endl;
		}
		else{
			int ca[]={0,0,0,0,0,0,0,0,0};
			while(x>=2){
				if(x-7>=0){
					ca[8]++;
					x-=7;
				}
				else if(x-6>=0){
					ca[6]++;
					x-=7;
				}
				else if(x-5>=0){
					ca[2]++;
					x-=5;
				}
				else if(x-4>=0){
					ca[0]++;
					x-=4;
				}
				else if(x-3>=0){
					ca[7]++;
					x-=3;
				}
				else if(x-2>=0){
					ca[1]++;
					x-=2;
				}
			}
			if(x==1){
				cout<<-1;
			}
			else{
				if(ca[0]>=1){
					for(int i=1;i<10;i++){
						if(ca[i]>0){
							cout<<i;
							ca[i]--;
						}
					}
				}
				for(int i=0;i<10;i++){
					if(ca[i]!=0){
						for(int j=0;j<ca[i];j++){
							cout<<i;
						}
					}
				}
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
