#include <stdio.h>

#define SUP						'~'
#define SUB						' '

int main (int argc, char *argv[]) {
	FILE *fp = fopen(argv[1], "rb");
	unsigned char byte;

	while (fread(&byte, sizeof(byte),1, fp)) {
		if ((byte>=SUB)&&(byte<=SUP))
			printf("%c", byte);
		if (byte == '\n')
			printf("%c", byte);	
		if (byte == '\t')
			printf("%c", byte);	
	}

	printf ("\n");
	fclose(fp);
	return 0;
}
