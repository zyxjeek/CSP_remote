#include <iostream>
using namespace std;
int f[1001];
int w[101];
int v[101];
int c,m;
int main(){
	int i,j,k;  
	cin>> c>> m;
	for(int i=1;i<=m;i++){
		cin >>w[i]>>v[i];  
	}	
	for(i=1;i<=m;i++)    
		for(j=c;j>=w[i];j--) 
		    if(f[j-w[i]]+v[i]>f[j])
		    	f[j]=f[j-w[i]]+v[i]; 
	cout<<f[c];
	return 0;
} 
