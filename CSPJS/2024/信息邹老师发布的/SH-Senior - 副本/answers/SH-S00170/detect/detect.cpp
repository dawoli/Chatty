#include<bits/stdc++.h>
//#define fin std::cin
//#define fout std::cout
//DELETE!!DELETE!!FILE!!FILE!!
using std::ifstream;
using std::ofstream;
using std::system;
using std::memset;
using std::vector;
using std::sort;
using std::cerr;
ifstream fin("detect.in");
ofstream fout("detect.out");

//Clarifications:
//n cars
//m detectors
//L length
//V speed limit
//d entrypoint
//v initial speed
//a acceleration 
//p locations of detectors
int T;
void print(int arr[],int l){
	cerr<<"{";
	for(int i=0;i<l;i++) cerr<<arr[i]<<",";
	cerr<<"}";
}
int solve(int n,int m,int L,int V,int d[],int v[],int a[],int p[]){
	//cerr<<"\033[1;33m";
	vector<int> detectors[m];
	int detects[n];
	//bool detected[n];
	int ans1=0;
	int ans2=0;
	//for(int i=0;i<m;i++) detectors[i]=0;
	for(int i=0;i<n;i++) detects[i]=0;//detected[i]=false,
	sort(p,p+m);
	for(int i=0;i<n;i++){
		//cerr<<"In i=["<<i<<"]:\n";
		//cerr<<"  a[i]="<<a[i]<<"\n";
		if(a[i]==0){
			if(v[i]>V){
				for(int j=0;j<n;j++){
					if(p[j]>=d[i]){
						//cerr<<"  detectors["<<j<<"]= "<<detectors[j];
						detectors[j].push_back(i);
						detects[i]++;
						//cerr<<" -> "<<detectors[j]<<"\n";
					}
				}
				//detected[i]=true;
			}
		}
		else if(a[i]<0){
			if(v[i]>V){
				int legal=(V*V-v[i]*v[i])/(2*a[i])+d[i];
				int leftover=(V*V-v[i]*v[i])%(2*a[i]);
				if(leftover>0){
					bool flag=true;
					for(int j=0;j<m and flag;j++){
						if(p[j]<=legal and p[j]>=d[i]){
							//cerr<<"  detectors["<<j<<"]= "<<detectors[j];
							detectors[j].push_back(i);
							//cerr<<" -> "<<detectors[j]<<"\n";
							//detected[i]=true;
							detects[i]++;
						}
					}
				}
				else {
					bool flag=true;
					for(int j=0;j<m and flag;j++){
						if(p[j]<legal and p[j]>=d[i]){
							//cerr<<"  detectors["<<j<<"]= "<<detectors[j];
							detectors[j].push_back(i);
							//detected[i]=true;
							detects[i]++;
							//cerr<<" -> "<<detectors[j]<<"\n";
						}
					}
				}
			}
		}
		else {
			int illegal=(V*V-v[i]*v[i])/(2*a[i])+d[i];
			for(int j=0;j<m;j++){
				if(p[j]>=illegal){
					//cerr<<"  detectors["<<j<<"]= "<<detectors[j];
					detectors[j].push_back(i);
					//detected[i]=true;
					detects[i]++;
					//cerr<<" -> "<<detectors[j]<<"\n";
				}
			}
		}
	}
	//cerr<<"here\n";
	for(int i=0;i<n;i++) if(detects[i]>0) ans1++;
	for(int i=0;i<m;i++){
		if(!detectors[i].empty()){
			bool flag=true;
			for(auto j:detectors[i]){
				if(detects[j]<=1) {
					flag=false;
					break;
				}
			}
			if(flag){
				//cerr<<"detector "<<i<<" can be removed\n  it detects";
				for(auto j:detectors[i]){
					//cerr<<j<<",";
					detects[j]--;
				}
				//cerr<<"\n";
				ans2++;
				//print(detects,n);
				//cerr<<"\n";
			}
		}
	}
	//print(detectors,m);
	//cerr<<"\n";
	//cerr<<"\033[0m";
	fout<<ans1<<" "<<ans2<<"\n";
}
int main(){
	system("cls");
	fin>>T;
	for(int i=0;i<T;i++){
		int n,m,L,V;
		fin>>n>>m>>L>>V;
		int d[n],v[n],a[n];
		for(int j=0;j<n;j++) fin>>d[j]>>v[j]>>a[j];
		int p[m];
		for(int j=0;j<m;j++) fin>>p[j];
		solve(n,m,L,V,d,v,a,p);
	}
	return 0;
}
