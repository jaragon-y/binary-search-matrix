#include <stdio.h>
#include <limits.h>
#define M 500
//bb matricial
void buscar(int pos[],int matriz[][M],int inix,int iniy,int finx,int finy,int valor,int *);

int main(){
	FILE *arch;
	int n,valor,m,flag=1;
	arch=fopen("matriz.txt","r");
	fscanf(arch,"%d%d%d",&n,&m,&valor);
	int matriz[n][M],pos[2];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)fscanf(arch,"%d",&matriz[i][j]);
	}	
	buscar(pos,matriz,0,0,n-1,m-1,valor,&flag);
	if(flag==1){
		printf("no se hallo");
	}else
		printf("%d %d",pos[0],pos[1]);
	return 0;
}

void buscar(int pos[],int matriz[][M],int inix,int iniy,int finx,int finy,int valor,int *flag){
	int midx=(inix+finx)/2,midy=(iniy+finy)/2;
	if(matriz[midx][midy]==valor){
		pos[0]=midx;
		pos[1]=midy;
		(*flag)=0;
		return ;
	}
	if (valor<matriz[inix][iniy] || valor>matriz[finx][finy])return ;
	if(midx==finx && midy==finy &&midx==inix && midy==iniy)return ;	
	if(matriz[midx][midy]<valor){//se elimina el cuadrante izquierdo superior
		if((*flag))buscar(pos,matriz,midx+1,iniy,finx,midy,valor,flag);//parte inferior izquierda
		if((*flag))buscar(pos,matriz,inix,midy+1,midx,finy,valor,flag);//parte superior derecha  
		if((*flag))buscar(pos,matriz,midx+1,midy+1,finx,finy,valor,flag);//parte inferior derecha  
	}else{//se elimina el cuadrante derecho inferior
		if((*flag))buscar(pos,matriz,inix,iniy,midx-1,midy-1,valor,flag);//parte superior izquierda
		if((*flag))buscar(pos,matriz,midx,iniy,finx,midy-1,valor,flag);//parte inferior izquierda
		if((*flag))buscar(pos,matriz,inix,midy,midx-1,finy,valor,flag);//parte superior derecha  
	}	
}
