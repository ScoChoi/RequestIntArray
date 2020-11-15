
/* Author: Scott Choi, ascottychoi@gmail.com
 * Functionality: Request integers to place in array that you will print to standard output
 */

#include <stdio.h>
#include <stdlib.h>

// x = rdi, y = rsi, z = rdx, rax = return value
long addq(long y, long z) {
	z = z + y;
	return z;
}

long imulq(long z, long x) {
	x = x * z;
	return x;
}

long salq(long z) {
	z = z << 63;
	return z;
}

long sarq(long z) {
	z = z >> 63;
	return z;
}

long movq(long x, long rax) {
	rax = x;
	return rax;
}

long xorq(long z, long rax) {
	rax = rax ^ z;
	return rax;
}

long f(long x, long y, long z) { // combine all the functions 
	long rax;
	z = addq(y, z);
	x = imulq(z, x);
	z = salq(z);
	z = sarq(z);
	rax = movq(x, rax);
	rax = xorq(z, rax);
	return rax;
}

long main() {
	printf("f(1, 2, 4): %d\n", f(1, 2, 4));
	printf("f(3, 5, 7): %d\n", f(3, 5, 7));
	printf("f(10, 20, 30): %d\n", f(10, 20, 30));
	return 0;
};
