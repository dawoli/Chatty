#include<bits/stdc++.h>
using namespace std;

int main (){
	freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	int r;
	cin>>r;
	for(int r1=0;r1<r;r1++){
		int s;
		cin>>s;
		int p = s/2;

		int q[s][3];
		int a[p+2][3],a1=0,a2=0,a3=0;
			for(int i=0;i<p+2;i++){
			a[i][0]  = 0;
			a[i][1] = 0;
			a[i][2] = 0;
		}
		for(int i=0;i<s;i++){
			cin>>q[i][0]>>q[i][1]>>q[i][2];
			if(q[i][0]>=q[i][1]&&q[i][0]>=q[i][2]){
				a[a1][0] = i;
			//	cout<<a[a1][0]<<q[i][0]<<q[i][1]<<q[i][2]<<endl;
				a1++; 
			
			}else if(q[i][1]>=q[i][0]&&q[i][1]>=q[i][2]){
				a[a2][1] = i;
				a2++; 
				
			}else if(q[i][2]>=q[i][1]&&q[i][2]>=q[i][0]){
				a[a3][2] = i;
				a3++; 
					
			}
		}
	
		while(true){
			if(a1<=p&&a2<=p&&a3<=p){
				break;
			}//cout<<"time"<<endl;
			int t = 20000,t1,t11;
			if(a1>p){
				for(int i=0;i<a1;i++){
					if(q[a[i][0]][0] == max(q[a[i][0]][1],max(q[a[i][0]][0],q[a[i][0]][2]))){
						if(t>(q[a[i][0]][0]-max(q[a[i][0]][1],q[a[i][0]][2]))){
							t = q[a[i][0]][0]-max(q[a[i][0]][1],q[a[i][0]][2]);
							t1  = a[i][0];
							t11=i;
						}
					}
					
					
				}
			
				a1--;
				if(q[t1][1]>q[t1][2]){
					a[a2][1] = t1;
					//cout<<q[t1][1]<<" "<<a2;
				a2++;
				
				}else{
					a[a3][2] = t1;
					a3++;
				}
				for(int i=t11;i<a1;i++){
					a[i][0] = a[i+1][0];
				}		
			}
			
			else if(a2>0){
					for(int i=0;i<a2;i++){
					if(q[a[i][1]][1] == max(q[a[i][1]][1],max(q[a[i][1]][0],q[a[i][1]][2]))){
						if(t>(q[a[i][1]][1]-max(q[a[i][1]][0],q[a[i][1]][2]))){
							t = q[a[i][1]][1]-max(q[a[i][1]][0],q[a[i][1]][2]);
							t1  = a[i][1];
							t11=i;
						}
					}
					
					
				}
				a2--;
				if(q[t1][0]>q[t1][2]){
					a[a1][0] = t1;
				a1++;
				
				}else{
					a[a3][2] = t1;
					a3++;
				}
				for(int i=t11;i<a2;i++){
					a[i][1] = a[i+1][1];
				}		
			}else if(a3>0){
					for(int i=0;i<a3;i++){
					if(q[a[i][2]][1] == max(q[a[i][2]][1],max(q[a[i][2]][0],q[a[i][2]][2]))){
						if(t>(q[a[i][2]][2]-max(q[a[i][2]][0],q[a[i][2]][1]))){
							t = q[a[i][2]][2]-max(q[a[i][2]][0],q[a[i][2]][1]);
							t1  = a[i][2];
							t11=i;
						}
					}
					
					
				}
				a3--;
				if(q[t1][1]<q[t1][0]){
					a[a1][0] = t1;
				a1++;
				
				}else{
					a[a2][1] = t1;
					a2++;
				}
				for(int i=t11;i<a3;i++){
					a[i][2] = a[i+1][2];
				}
		}
	}
	long long f = 0;
	for(int i=0;i<a1;i++){
		f+=q[a[i][0]][0];
		//cout<<q[a[i][0]][0]<<" ";
		
	}//cout<<endl;
	for(int i=0;i<a2;i++){
		f+=q[a[i][1]][1];
		//cout<<q[a[i][1]][1]<<" ";
	}//cout<<a2<<endl;
	for(int i=0;i<a3;i++){
		f+=q[a[i][2]][2];
	//	cout<<q[a[i][2]][2]<<" ";
	}//cout<<endl;
	cout<<f<<endl;
//	cout<<"_____________________________________"<<endl;
	}
	return 0;
} 

/*
3 4
4 2 1 
3 2 4 
5 3 4 
3 5 1 
4 
0 1 0 
0 1 0 
0 2 0 
0 2 0 
2 
10 9 8
4 0 0
*/



