#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("club.in");
ofstream fout("club.out");
 
long long a [100005];
long long b [100005];
long long c [100005];
int main(){
	int t;
	fin>>t;
	
	for(int q=1; q<=t; q++){
		long long ans=0;
		int n;
		fin>>n;
		int aa=0;
		int bb=0;
		int cc=0;
		long long sum=0;
		for(int i=0; i<=n-1; i++){
			fin>>a[i]>>b[i]>>c[i];
			
		}
		for(int i=0; i<=n-1; i++){
			sum+=a[i];
		}
		for(int i=0; i<=n-1; i++){
			sum+=c[i];
		}
		
		for(int i=0; i<=n-1; i++){
			if(a[i]>=b[i] && a[i]>=c[i]){
				sum+=a[i];
				aa++;
				
				
				
			}
			else if(b[i]>=a[i] && b[i]>=c[i]){
				sum+=b[i];
				bb++;
			}
			else if(c[i]>=a[i] && c[i]>=b[i]){
				sum+=c[i];
				cc++;
				
			}
			
		}
		
		if(aa<=n/2 &&bb<=n/2 &&cc<=n/2){
			fout<<sum<<endl;
		}
		
		else{
			fout<<sum-2<<endl;
		}
	}
	return 0;
} 
