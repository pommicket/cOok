#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ook2bf.c"
#include "bfcompiler.c"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
	fprintf(stderr, "Error: Usage: %s <file>\n", argv[0]);
	return 0;
    }

    char* bf;
    
    
    bf = ook2bf(argv[1]);
    compilebf(bf);

    
    
    return 0;
}
