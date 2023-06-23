//f[//i][j]表示前i个物体放入容量为j的背包获得的最大价值  
// f[i][j] = max{f[i-1][j], f[i-1][j-w[i]]+v[i]}  
//第i件物品要么放，要么不放  
//如果第i件物品不放的话,就相当于求前i-1件物体放入容量为j的背包获得的最大价值  
//如果第i件物品放进去的话,就要考虑放还是不放。放的话，相当于求前i-1件物体放入容量为j-w[i]的背包获得的最大价值  
#include <iostream>
#include <cstring>
using namespace std;

int f[101][1001];//保存前i种物品分配j重量时的价值 
int w[101];//保存第i种物品的重量 
int v[101];//保存第i中物品的价值
int c,m;//c代表背包总重量，M代表物品的数目
int main(){
	freopen("MEDIC0.IN","r",stdin);//文件名区分大小写 
	cin>> c>> m;
	for(int i=1;i<=m;i++){
		cin >>w[i]>>v[i];  
	}
	for(int i=0;i<101;i++)
		for(int j=0;j<1001;j++)	{
			f[i][j]=0;
		}
	for(int i=1;i<=m;i++){   
		for(int j=1;j<=c;j++){ 
		/*  if (j<w[i]) {// 第i件物品大于背包的重量，放不进去  
		    f[i][j] = f[i-1][j];  
		}
		else {  
		    //第i件物品的重量小于背包的重量，所以可以选择第i件物品放、还是不放  
			if (f[i-1][j] > f[i-1][j-w[i]]+v[i]) {  //不放 
				f[i][j] = f[i-1][j];  
			}
			else {
				f[i][j] = f[i-1][j-w[i]]+v[i];  
			}
		} */
		if(j<w[i]){// 第i件物品大于背包的重量，放不进去
			f[i][j]=f[i-1][j]; 				
		}
	    else{//第i件物品的重量小于背包的重量，所以可以选择第i件物品放、还是不放
			f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);}
		}
	}
	cout<<f[m][c];
	return 0;
}