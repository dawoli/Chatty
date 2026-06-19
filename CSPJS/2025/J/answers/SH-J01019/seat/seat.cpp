#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int a[N];
int n,m;
//ÐÐ¡¢ÁÐ 

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	
	int R=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int hang,lie=1;
	
	for(int i=1;i<=n*m;){
		for(hang=1;hang<=n;hang++,i++){
			if(a[i]==R){
				cout<<lie<<" "<<hang;
				return 0;
			}			
		}
		lie++;
		for(hang=n;hang>=1;hang--,i++){
			if(a[i]==R){
				cout<<lie<<" "<<hang;
				return 0;
			}
		}
		lie++;

		//cout<<"a["<<i<<"]: h:"<<hang<<" l:"<<lie<<'\n';
	}
	return 0;
}
