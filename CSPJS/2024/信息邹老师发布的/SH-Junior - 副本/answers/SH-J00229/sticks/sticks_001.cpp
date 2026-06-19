#include<bits/stdc++.h>
using namespace std;
int t=0;
int cnt7=0;
int cnt71=0;
long long inp[10009];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=0;i<10010;i++){
		inp[i]=0;
	}
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>inp[i];
		if(inp[i]%7==0){
			cnt7++;
		}
		if(inp[i]%7==1){
			cnt71++;
		}
	}
	//Õý½â 
	for(int i=0;i<t;i++){
		if(inp[i]==1){
			cout<<"-1"<<endl;
		}
		if(inp[i]==2){
			cout<<"1"<<endl;
		}
		if(inp[i]==3){
			cout<<"7"<<endl;
		}
		if(inp[i]==4){
			cout<<"4"<<endl;
		}
		if(inp[i]==5){
			cout<<"2"<<endl;
		}
		if(inp[i]==6){
			cout<<"6"<<endl;
		}
		if(inp[i]==7){
			cout<<"8"<<endl;
		}
		if(inp[i]>7){
			if(inp[i]%7==0){
				for(int j=0;j<inp[i]/7;j++){
				    cout<<"8";
			    }
			    cout<<endl;
			}
			if(inp[i]%7==1){
				cout<<10;
				for(int j=0;j<inp[i]/7-1;j++){
				    cout<<"8";
			    }
			    cout<<endl;
			}
			if(inp[i]%7==2){
				cout<<18;
				for(int j=0;j<inp[i]/7-1;j++){
				    cout<<"8";
			    }
			    cout<<endl;
			}	
			if(inp[i]%7==3){
				cout<<22;
				for(int j=0;j<inp[i]/7-1;j++){
				    cout<<"8";
			    }
			    cout<<endl;
			}
			if(inp[i]%7==4){
				cout<<20;
				for(int j=0;j<inp[i]/7-1;j++){
				    cout<<"8";
			    }
			    cout<<endl;
			}
			if(inp[i]%7==5){
				cout<<28;
				for(int j=0;j<inp[i]/7-1;j++){
				    cout<<"8";
			    }
			    cout<<endl;
			}
			if(inp[i]%7==6){
				cout<<68;
				for(int j=0;j<inp[i]/7-1;j++){
				    cout<<"8";
			    }
			    cout<<endl;
			}
		}
	}
	return 0;
}
