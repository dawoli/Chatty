#include<bits/stdc++.h>
using namespace std;
int f[1000005]={0};
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,r0=-1,r1=-1;
		cin>>n;
		int a[100005];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		queue <int>  q;
		int c0=-1, c1=-1;
		memset(f,0,sizeof(f));
	//	int co[1000005]={0};
		//int cnt=0;
		int ocp=1;
		long long ans=0;
		for(int i=0;i<n;i++){
			//cout<<a[i]<<" "<<f[a[i]]<<endl;
			q.push(a[i]);
			if(a[i]==c0)	{
				ocp=0;
			}else if(a[i]==c1){
				ocp=1;
			}
			if(f[a[i]]){
				f[a[i]]++;
				//cout<<"&"<<ocp<<" "<<f[a[i]];
				while(!q.empty()){
					//cout<<q.front()<<endl;
					if(f[q.front()]==1){
						if(ocp){
							c0=q.front();
						}else{
							c1=q.front();
						}
						q.pop();
						//co[a[i]]=0;
					}else{
						if(f[q.front()]!=1){
							//cout<<c0<<" "<<c1<<" "<<q.front()<<endl;
							if(c0==q.front()){
								c0=q.front();
								ocp=0;
								ans+=q.front();
							}else if(c1==q.front()){
								c1=q.front();
								ocp=1;
								ans+=q.front();
							
							}else{
								if(ocp){
									c0=q.front();
									ocp=0;
								}else{
									c1=q.front();
									ocp=1;
								}	
							}
							q.pop();
						}
					}
				}
			
			}else{
				f[a[i]]++;
			}
		}
		cout<<ans<<endl;
	}
}
/*
1
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
*/
