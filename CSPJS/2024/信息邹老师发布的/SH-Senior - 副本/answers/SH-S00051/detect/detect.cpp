#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	long long a[10000];
	int d[10000];
	int v[10000];
	int mntr[10000];
	int t;
	long long n,m,V;
	double L;
	double s;
	int maxn=-100000;
	int cnt=0;
	int tmp=0;
	int o;
	int fs;
	cin>>t;
	for(int i=1;i<=t;i++){
		tmp=0;
		cnt=0;
		cin>>n>>m>>L>>V;
		for(int j=0;j<n;j++){
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int k=0;k<m;k++){
			cin>>o;
			mntr[o]=1;
		}
		for(int z=0;z<n+1;z++){
			if(a[z]==0){
				if(v[z]>V){
			fs=cnt+1;
			for(int q=d[z];q<L;q++){
				if(mntr[q]!=0){
					mntr[q]=mntr[q]+1;
					cnt=fs;
				}
			}
			continue;
		}
	}
	else{
		s=double(V*V-v[z]*v[z])/double(2*a[z]);
		if(s<0) continue;
		if(v[z]>V){
			fs=cnt+1;
			for(int q=d[z];q<L;q++){
				if(mntr[q]!=0){
					mntr[q]=mntr[q]+1;
					cnt=fs;
				}
			}
			continue;
		}
		if(s>0){
			if(s+double(d[z])>=L){
				continue;
			}
			else{
				fs=cnt+1;
				for(int g=d[z];g<L;g++){
					if(mntr[g]!=0){
						mntr[g]=mntr[g]+1;
						cnt=fs;
					}
				}
			}	
		}
}
		}
	for(int w=0;w<L;w++){
		maxn=max(maxn,mntr[w]);
	}
	for(int b=0;b<L;b++){
		if(mntr[b]==maxn){
			tmp++;
		}
	}
	cout<<cnt<<" "<<m-tmp<<endl;
	}
	return 0;
}
