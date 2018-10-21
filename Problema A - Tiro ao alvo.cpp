#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int calcuMDC(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
int calcuMMC(int a, int b) {
	return (a*b) / calcuMDC(a,b);
}
int rMMC(int*const vet, int N) {
	if(N >= 2) {
		vet[N-2] = calcuMMC(vet[N-1],vet[N-2]);
		N--;
		return rMMC(vet,N);
	}
	return calcuMMC(vet[N],vet[N-1]);
}
int ver_s () {
	int correto = 0;
	int s = -1;
		while(correto != 1) {
			scanf("%d",&s);
			if(s<0 || s>50) {
				printf("Você errou!!!");
			} else {
				return s;
			}
		}
}
int main() {
	setlocale(LC_ALL,"Portuguese");
	printf("       Problema A - Tiro ao Alvo\n\n");
	printf("Digite os números correspondentes a questão: ");
	int N = ver_s ();
	int lancament[N];
	for(int i=0;i<N;i++) scanf("%d",&lancament[i]); printf("%d",rMMC(lancament,N));
		return 0;
}
