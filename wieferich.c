#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

int main(void) {
	mpz_t B,D,E,M,R;
	unsigned long int result;

	mpz_init_set_ui(B, 2);
	mpz_init_set_ui(D, 2);
	mpz_init(E);
	mpz_init(M);
	mpz_init(R);

	for(;;) {
		mpz_sub_ui(E, D, 1);
		mpz_mul(M, D, D);
		mpz_powm(R, B, E, M);
		result = mpz_get_ui(R);
		if (result == 1) {
			gmp_printf("%Zd\n", D);
		}
		mpz_nextprime(D, D);
	}
	mpz_clear(B);
	mpz_clear(D);
	mpz_clear(E);
	mpz_clear(M);
	mpz_clear(R);
	return 0;
}
