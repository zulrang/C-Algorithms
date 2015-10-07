#include <stdio.h>

#define N 10000

int main() {
	// uses approx. 4(2N + 4) bytes of memory on 32 and 64-bit architecture (about 78k for 10000)
	int id[N], sz[N], i, j, p, q;

	// initialize arrays
	for(i=0; i<N; i++) { id[i] = i; sz[i] = 1; }

	while(scanf("%d %d\n", &p, &q) == 2) {
		// get the root node of each input and compress each node to their parent
		for(i = p; i != id[i]; i = id[i]) id[i] = id[id[i]];
		for(j = q; j != id[j]; j = id[j]) id[j] = id[id[j]];
		if (i == j) continue; // same root node, already connected

		// different root node, set them to be the same weighted by size
		if (sz[i] < sz[j]) {
			id[i] = j; // set root of i to j
			sz[j] += sz[i]; // add size of i to j
		} else {
			id[j] = i; // set root of j to i
			sz[i] += sz[j]; // add size of j to i
		}
		printf(" %d %d\n", p, q);
	}

	return 0;
}
