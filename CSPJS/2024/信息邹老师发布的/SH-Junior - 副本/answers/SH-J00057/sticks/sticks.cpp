#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int sti[10]={6,2,5,5,4,5,6,3,7,6};
int ans[1010];
int main(){
	freopen("sticks.in","w",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n;
		cin>>n;
		if(n==1) {
			cout<<-1<<endl;
			continue;
		}
		if(n<=7){
			for(int i=1;i<=9;i++){
				if(sti[i]==n){
					cout<<i<<endl;
					break;
				}
			}
			continue;
		}
		if(n%7!=0){
			int en=n-(n/7-1)*7;//cout<<en<<endl;//
			for(int i=3;i<=n/7+1;i++) ans[i]=8;
			for(int i=0;i<=9;i++){
				int h=en-sti[i];//cout<<sti[i]<<"h:"<<h<<endl;//
				if(h==1) {
					continue;
				}
				if(h<=7){
					for(int j=0;j<=9;j++){
						if(sti[j]==h){
							ans[1]=i;//cout<<i<<endl;//
							ans[2]=j;
							break;
						}
					}
					break;
				}
			}
			sort(ans+1,ans+n/7+2);
			if(ans[1]==0){
				if(ans[2]==0){
					ans[1]=ans[3];
					ans[3]=0;
				}
				else{
					ans[1]=ans[2];
					ans[2]=0;
				}
			}
		}
		else{
			for(int i=1;i<=n%7;i++){
				ans[i]=8;
			}
		}
		int s=0;
		for(int i=1;i<=n/7+1;i++){
			s=s*10+ans[i];
		}
		cout<<s<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
