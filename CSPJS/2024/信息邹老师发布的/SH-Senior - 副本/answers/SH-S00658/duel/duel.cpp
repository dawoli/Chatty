#include<fstream>
std::ifstream fin("duel.in");
std::ofstream fout("duel.out");
long long a[100005],num[100005],at[100005];
long long son[100005];
int main(){
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>a[i];
		num[a[i]]++;
		at[a[i]]++;
	}
	long long last=0;
	long long unable=0;
	for(int i=0;i<=100001;i++){
		if(num[i]!=0) {
			son[i]=num[last];
			if(num[i]>=son[i]+unable) {
				son[i]=0;
				num[last]=0;
				at[i]-=son[i];
			}
			else{
				if(unable>at[i]){
					unable-=at[i];
					at[i]=0;
					unable+=son[i];
				}
				else{
					at[i]-=unable;
					unable=0;
					son[i]-=at[i];
					num[last]-=at[i];
					at[i]=0;
					unable+=son[i];
				}
			}
			last=i;	
		}
	}
	fout<<unable+num[last];
	return 0;
}
