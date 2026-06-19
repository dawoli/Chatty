#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int nums=n/7;
	//	cout<<nums;
		string s="";
		for(int i=0;i<nums-2;i++){
			s+="8";
		}
		int ans=n%7;
		if(nums<2){
			if(nums==1){
				string ansl[7]={"8","10","18","22","26","66","68"};
				cout<<ansl[ans]<<endl;
				continue;
			}
			else{
				string ansl[7]={"-1","-1","1","7","4","2","6"};
				cout<<ansl[ans]<<endl;
				continue;
			}
		}
		if(ans==0){
			cout<<"88"+s<<endl;
			continue;
		}
	//	cout<<s<<endl;
		if(ans==1){
			s="108"+s;
			cout<<s<<endl;
			continue;
		}
		if(ans==2){
			s="188"+s;
			cout<<s<<endl;
			continue;
		}
		if(ans==3){
			s="200"+s;
			cout<<s<<endl;
			continue;
		}
		if(ans==4){
			s="208"+s;
			cout<<s<<endl;
			continue;
		}
		if(ans==5){
			s="288"+s;
			cout<<s<<endl;
			continue;
		}
		if(ans==6){
			s="688"+s;
			cout<<s<<endl;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
