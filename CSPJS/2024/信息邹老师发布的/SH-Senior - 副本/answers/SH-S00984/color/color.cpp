#include<bits/stdc++.h>
using namespace std;
int a[200005];
int l[200005],h[200005];
int jl[200005];

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int j=1;j<=t;j++){
		int n;
		cin>>n;
		int l1=1,h1=1;
		bool l2=true,h2=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			jl[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(jl[a[i]]>1){
				if(a[i]==l[l1-1]){
					l[l1]=a[i];
					jl[a[i]]--;
					if(jl[a[i]]>1){
						l2=false;	
					}
					else{
						l2=true;
					}
					l1++;
				}
				else if(a[i]==h[h1-1]){
					h[h1]=a[i];
					jl[a[i]]--;
					if(jl[a[i]]>1){
						h2=false;	
					}
					else{
						h2=true;
					}
					h1++;
				}
				else if(l2){
					l[l1]=a[i];
					l2=false;
					l1++;
				}
				else if(h2){
					h[h1]=a[i];
					h2=false;
					h1++;
				}
				else{
					if(l[l1-1]>h[h1-1]){
						h[h1]=a[i];
						h1++;
					}
					else{
						l[l1]=a[i];
						l1++;
					}
				}
			}
			else{
				if(l2){
					l[l1]=a[i];
					l1++;
				}
				else if(h2){
					h[h1]=a[i];
					h1++;
				}
				else{
					if(l[l1-1]>h[h1-1]){
						h[h1]=a[i];
						h2=true;
						h1++;
					}
					else{
						l[l1]=a[i];
						l2=true;
						l1++;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(l[i]==l[i-1]){
				ans+=l[i];
			}
			if(l[i]==0){
				break;
			}
			//cout<<l[i]<<" ";
		}
		//cout<<endl;
		for(int i=1;i<=n;i++){
			if(h[i]==h[i-1]){
				ans+=h[i];
			}
			if(h[i]==0){
				break;
			}
			//cout<<h[i]<<" ";
		}
		//cout<<endl;
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			jl[a[i]]=0;
		}
	}
}
