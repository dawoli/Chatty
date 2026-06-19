#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans;
bool cmp(int x,int y){
	return x > y;
}
int d3(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				if(a[i] *2 < a[i]+a[j]+a[k]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int d4(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				for(int l = k+1;l <= n;l++)
				if(a[i] *2 < a[i]+a[j]+a[k]+a[l]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int d5(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				for(int l = k+1;l <= n;l++)
				for(int m = l+1;m <= n;m++)
				if(a[i] *2 < a[i]+a[j]+a[k]+a[l]+a[m]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int d6(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				for(int l = k+1;l <= n;l++)
				for(int m = l+1;m <= n;m++)
				for(int o = m+1;o <= n;o++)
				if(a[i] *2 < a[i]+a[j]+a[k]+a[l]+a[m]+a[o]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int d7(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				for(int l = k+1;l <= n;l++)
				for(int m = l+1;m <= n;m++)
				for(int o = m+1;o <= n;o++)
				for(int p = o+1;p <= n;p++)
				if(a[i] *2 < a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int d8(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				for(int l = k+1;l <= n;l++)
				for(int m = l+1;m <= n;m++)
				for(int o = m+1;o <= n;o++)
				for(int p = o+1;p <= n;p++)
				for(int q = p+1;q <= n;q++)
				if(a[i] *2 < a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int d9(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				for(int l = k+1;l <= n;l++)
				for(int m = l+1;m <= n;m++)
				for(int o = m+1;o <= n;o++)
				for(int p = o+1;p <= n;p++)
				for(int q = p+1;q <= n;q++)
				for(int r = q+1;r <= n;r++)
				if(a[i] *2 < a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int d10(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				for(int l = k+1;l <= n;l++)
				for(int m = l+1;m <= n;m++)
				for(int o = m+1;o <= n;o++)
				for(int p = o+1;p <= n;p++)
				for(int q = p+1;q <= n;q++)
				for(int r = q+1;r <= n;r++)
				for(int s = r+1;s <= n;s++)
				if(a[i] *2 < a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int d11(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				for(int l = k+1;l <= n;l++)
				for(int m = l+1;m <= n;m++)
				for(int o = m+1;o <= n;o++)
				for(int p = o+1;p <= n;p++)
				for(int q = p+1;q <= n;q++)
				for(int r = q+1;r <= n;r++)
				for(int s = r+1;s <= n;s++)
				for(int t = s+1;t <= n;t++)
				if(a[i] *2 < a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int d12(int n){
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				for(int l = k+1;l <= n;l++)
				for(int m = l+1;m <= n;m++)
				for(int o = m+1;o <= n;o++)
				for(int p = o+1;p <= n;p++)
				for(int q = p+1;q <= n;q++)
				for(int r = q+1;r <= n;r++)
				for(int s = r+1;s <= n;s++)
				for(int t = s+1;t <= n;t++)
				for(int u = t+1;u <= n;u++)
				if(a[i] *2 < a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]){
					ans++;
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		d3(n);	
	}else if(n==4){
		d3(n);
		d4(n);
	}else if(n==5){
		d3(n);
		d4(n);
		d5(n);
	}else if(n==6){
		d3(n);
		d4(n);
		d5(n);
		d6(n);
	}else if(n==7){
		d3(n);
		d4(n);
		d5(n);
		d6(n);
		d7(n);
	}else if(n==8){
		d3(n);
		d4(n);
		d5(n);
		d6(n);
		d7(n);
		d8(n);
	}else if(n==9){
		d3(n);
		d4(n);
		d5(n);
		d6(n);
		d7(n);
		d8(n);
		d9(n);
	}else if(n==10){
		d3(n);
		d4(n);
		d5(n);
		d6(n);
		d7(n);
		d8(n);
		d9(n);
		d10(n);
	}else if(n==11){
		d3(n);
		d4(n);
		d5(n);
		d6(n);
		d7(n);
		d8(n);
		d9(n);
		d10(n);
		d11(n);
	}else if(n==12){
		d3(n);
		d4(n);
		d5(n);
		d6(n);
		d7(n);
		d8(n);
		d9(n);
		d10(n);
		d11(n);
		d12(n);
	}
	cout << ans;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
