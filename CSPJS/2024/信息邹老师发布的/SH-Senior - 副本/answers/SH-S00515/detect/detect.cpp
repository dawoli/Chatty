#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int v;
int s2[10000]={-1};
bool g[10000][10000];
bool f(int a,int b ,int c,int d){
	if(a>d){
		return false;
	}
	float e=sqrt(2*(d-a)*c+b*b)*1.0;
	if(e>v*1.0){
		return true; 
	}
	return false;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,l,fl,ji=0;
	cin>>t;
	for(int i=0;i<t;i++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				g[m][n]=false;
			}
		}
		ji=0;
		int j2=0;
		cin>>n>>m>>l>>v;
		int c[n][3];
		int ch[n];
		for(int i=0;i<n;i++)ch[i]=-1;
		int s[m];
		for(int j=0;j<n;j++){
			cin>>c[j][0]>>c[j][1]>>c[j][2];
		}
		for(int j=0;j<m;j++){
			cin>>s[j];
			for(int k=0;k<n;k++){
				if(f(c[k][0],c[k][1],c[k][2],s[j])){
					g[k][j]=true;
					ch[k]=j;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(ch[i]>0){
				ji++;
			}
		}
		cout<<ji<<" "<<m-1<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}



