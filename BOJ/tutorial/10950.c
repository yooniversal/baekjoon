//10950

#include <stdio.h>
int main() {

	int T, a, b;

	scanf("%d", &T);

	while (T != 0) {

		scanf("%d %d", &a, &b);

		printf("%d\n", a + b);

		T--;
	}

	return 0;
}