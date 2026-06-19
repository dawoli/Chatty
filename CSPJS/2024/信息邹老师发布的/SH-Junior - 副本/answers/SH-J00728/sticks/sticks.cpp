 #include<iostream>
 using namespace std;
 int main(){
 	freopen("sticks.in","r",stdin);
 	freopen("sticks.out","w",stdout);
 	int t;
 	cin>>t;
 	for(int f=0;f<t;f++){
 		int n;
 		cin>>n;
 		if(n%7==0){
 			int a=n/7;
 			for(int i=0;i<a;i++){
 				cout<<8;
			}
			cout<<"\0";
		}
 		else if(n%7==1){
 			int a=n/7-1;
 			cout<<1;
			for(int i=0;i<a;i++){
			 	cout<<8;
			} 
			cout<<0;
			cout<<endl;
		}
		else{
			cout<<"-1";
		}
		
 		
		
		
		
	 }
 	fclose(stdin);
 	fclose(stdout);
	 return 0;
 }
