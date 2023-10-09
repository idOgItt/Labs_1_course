// Полоса ограничена прямыми i + j + 10 = 0 и i + j + 20 = 0         
#include <stdio.h>
#include <math.h>

int check(int a, int b) {
	int c = a + b + 10;
	int d = a + b + 20;
	if ((c <= 0) && (d >= 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int max(int x, int y) {
	if (x >= y) { 
		return x;
	}
	else {
		return y;
	}
}

int min(int x, int y) {
	if (x <= y) { 
		return x;
	}
	else {
		return y;
	}
}

int mod(int x, int y) {
	return x-floor(x/y)*y;
}

int abs(int x) {
	if (x < 0) {
		return (-1)*x;
	}
	else {
		return x;
	}
}

int sign(int x) {
	if (x > 0) {
		return 1;
	}
	else if (x < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	const int i0 = -25;
	const int j0 = -9;
	const int l0 = -8;
	int ik = i0;
	int jk = j0;
	int lk = l0;
	int i1 = ik;
	int j1 = jk;
	int l1 = lk;
	int k = 0;
	while (check(i1, j1) != 1 && k<51) {
		ik = i1;
		jk = j1;
		lk = l1;
		printf("%i\n",k);
		printf("(%i, %i) l=%i\n",i1,j1,l1);
		i1 = mod((lk*abs(ik-jk) - ik*abs(jk-lk) + jk*abs(ik-lk)),20) - k;
		j1 = mod((min(ik,jk)*max(lk,lk)*min(ik,lk)),25) + 5*sign(ik) + k;
		l1 = abs(lk)*sign(ik-jk) - abs(ik)*sign(jk-lk) + abs(jk)*sign(ik-lk);
		k += 1;
	}
	if (k > 50) {
		printf("Missed, k=%i i=%i j=%i l=%i\n",k-1,ik,jk,lk);
	}
	else {
		printf("Hit on step %i i=%i j=%i l=%i\n",k,i1,j1,l1);
	}
}