#include <stdio.h>

#define swap(i, j) char t = i; i = j; j = t;

int main() {
	int i;
	int iter;
	int j = 0;
	int temp;
	char s[256];
	char key[] = "Test";
	char data[] = "Hello";
	for (i = 0; i < 256; ++i)
		s[i] = i;
	for (i = 0; i < 256; ++i) {
		j = (j + s[i] + key[i%4]) % 256;
		swap(s[i], s[j]);
	}
	printf("Hex Dump of Cipher Text: ");
	for (iter = 0; data[iter] != '\0'; ++iter) {
		i = (i+1) % 256;
		j = (j + s[i]) % 256;
		swap(s[i], s[j]);
		printf("%x ", (unsigned char)(s[(s[i] + s[j]) %256] ^ data[iter]));
	}
	printf("\nOriginal Hex Dump of Text: ");
	printf("%x %x %x %x %x", data[0], data[1], data[2], data[3], data[4]);
	getchar();
}


