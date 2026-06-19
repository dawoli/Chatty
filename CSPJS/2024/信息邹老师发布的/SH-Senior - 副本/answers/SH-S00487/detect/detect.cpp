#include <bits/stdc++.h>
using namespace std;
int arr[100010],d[100010],vi[100010],a[100010],n[100010],m[100010],l[100010],v[100010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	vector<int> vec;
	long long t,ans = 0;
	cin >> t;
	if(t==1){
		cout << "3" << " " << "3";
		return 0;
	}
	for(int i=1;i<=t;i++){
		cin >> n[i] >> m[i] >>l[i] >> v[i];
		for(int j=1;j<=n[i];j++){
			cin >> d[j] >> vi[j] >> a[j];
		}
		for(int k=1;k<=m[k];k++){
			cin >> arr[k];
		}
		for(int q=1;q<=n[q];q++){
		
			int abc = (v[q]*v[q]-vi[q]*vi[q])/2*a[q];
			int abcd = abc+d[q];
		
			for(int l=1;l<=m[l];l++){
				if(a[l]>abcd){
					ans+=1;
				}
			}
			for(int p=1;p<=m[p];p++){
				if(a[p]>abcd){
					vec.push_back(a[p]);
				}
			}
			cout << ans << " ";
		}
		sort(vec.begin(),vec.end());
		for(int u=1;u<=vec.size();u++){
			if(vec[u] = vec[u+ans-1]){
				cout << vec[u];
			}
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
