#include<iostream>
#include<fstream>
std::ifstream fin("poker.in");
std::ofstream fout("poker.out");
int main(){
	int n;
	fin>>n;
	char d[n*2],a[n*2],c[n*2],h[n*2],s[n*2];
	for(int i=2;i<=n*2;i+=2){
		d[i]=0;
		c[i]=0;
		h[i]=0;
		s[i]=0;
	} 
	int sum=52-n;
	for(int i=1;i<=n*2;i++){
		fin>>a[i];		
	}
	for(int i=1;i<=n*2;i+=2)	{
		if(a[i]=='D'){
			d[i]=a[i+1];
		}
		else{
			d[i]=0;
		}
		if(a[i]=='C'){
			c[i]=a[i+1];
		}
		else{
			c[i]=0;
		}
		if(a[i]=='H'){
			h[i]=a[i+1];
		}
		else{
			h[i]=0;
		}
		if(a[i]=='S'){
			s[i]=a[i+1];
		}
		else{
			s[i]=0;
		}
	}
	for(int i=1;i<=n*2;i+=2){
		if(s[i]==s[i+2] && s[i]!=0){
			sum++; 
		}
	}
	for(int i=1;i<=2*n;i+=2){
		if(d[i]==d[i+2] && d[i]!=0){
			sum++;
		}
	}
	for(int i=1;i<=2*n;i+=2){
		if(h[i]==h[i+2] && h[i]!=0){
			
		}
	}
	for(int i=1;i<=2*n;i+=2){
		if(c[i]==c[i+2] && c[i]!=0){
			sum++;
		}
	}
	fout<<sum;
}
