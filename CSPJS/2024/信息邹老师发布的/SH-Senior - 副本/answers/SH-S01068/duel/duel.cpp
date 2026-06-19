#include<bits/stdc++.h>
#include<fstream>
std::ifstream fin("duel.in");
std::ofstream fout("duel.out");
using namespace std;
struct monster{
	long long num;
	bool flag=false;
}mon[100005];
bool cmp(monster x,monster y){
	return x.num<y.num; 
}
bool cmp1(long long x,long long y){
	return x<y;
}
long long a[100005];
long long b[100005];
long long n;
long long sum;
void pot(){
	sort(mon+1,mon+n+1,cmp);
	long long maxn=mon[n].num;
	for(int i=1;i<=n;i++){
		long long j=1;
		if(mon[i].num==j){
			b[j]++;
		}
		else{
			j=mon[i].num;
			b[j]++;
		}
	}
	for(int i=1;i<=maxn;i++) {
		if(b[i]!=0){
			sum++;
		}
		
	}
}
void search(){
	pot();
	long long cnt=n;long long dec;
	long long maxn=mon[n].num;
	long long minn=mon[1].num;//最小防御 
	for(long long i=2;i<=sum;i++){
		long long smaller=b[minn];//较小值数量 
		long long bigger;//较大值数量 
	 	dec=minn+1;
	 	sort(b+1,b+n+1,cmp1);
	 		while(1){
				if(b[dec]!=0){
					bigger=b[dec];
					minn=dec;
						if(smaller>bigger){
							//cout<<bigger<<" ";
							cnt-=bigger;
							smaller=abs(bigger-smaller);
							break;
						}
						else if(smaller==bigger){
							cnt-=bigger;
							//cout<<bigger<<" ";
							break;
						}
						else {
							//cout<<smaller<<" ";
							cnt-=bigger;
							smaller=abs(bigger-smaller);
							break;
						}
						
						//fout<<smaller<<" ";
						
				} 
				else{
					dec++;
				} 
			}	
		}
	fout<<cnt;
	//cout<<cnt;
}
int main(){
	fin>>n;
	long long cnt;
	long long f=true;
	cnt=n;
	for(int i=1;i<=n;i++){
		fin>>mon[i].num;
	}
	for(int i=1;i<=n;i++){
		if(mon[i].num>2)
		f=false;
	}
	if(f==false){
		search();
		return 0;
	}
	else{
	long long counter=0;
		for(int i=1;i<=n;i++){
			if(mon[i].num==2){
			counter++;
			}
			
		}
		fout<<counter;
		//cout<<counter;
	}
	
	return 0;
} 
