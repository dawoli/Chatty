#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> x >> y;
	long long all=x*y;
	int ans=0,adress=0;
	vector<int> a(all);
	for(int i=0;i<all;i++){
		cin >> a[i];
	}
	ans=a[0];
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<all;i++){
		if(a[i]==ans){
			adress=i+1;
			break;
		}
	}
	int ansx,ansy;
	if(adress%x==0) ansx=adress/x;
	else ansx=adress/x+1;
	//cout << adress << endl;
	if(x!=2){
		if(ansx%2==0){
			if(adress%x==0){
				ansy=1;
			}else{
				ansy=x-adress%x+1;
			}
		}else{
			if(adress%x==0){
				ansy=x;
			}else{
				ansy=adress%x;
			}
		}
	}else{//////////
		if(ansx%2==0){
			if(adress%x==0){
				ansy=1;
			}else{
				ansy=2;
			}
		}else{
			if(adress%x==0){
				ansy=2;
			}else{
				ansy=1;
			}
		}
	}
	
	cout << ansx << " " << ansy;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
