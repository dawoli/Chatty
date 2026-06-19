#include<iostream>
using namespace std;
int t,n,m,l,V=0;
int d=0;
int v=0;
int a=0;
int p=0;
int chaosu=0;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){	
		cin>>n>>m>>l>>V;
		for(int k=0;k<n;k++){
			cin>>d>>v>>a;
			if(V<v)chaosu++;

			
		}
		for(int k=1;k<=m;k++){
			cin>>p;
		}
		if(chaosu!=0){cout<<chaosu<<" "<<m-1<<endl;
		chaosu=0;
		}
		else if(chaosu==0){cout<<chaosu<<" "<<m<<endl;
		chaosu=0;
		}
	}
	return 0;
}

