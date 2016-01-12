


int isValid(char c)
{
    return c == '.' || c == '!' || c == '?';
}


char ook2bfchar(char a, char b)
{
    if (a == '.' && b == '?')
	return '>';
    if (a == '?' && b == '.')
	return '<';
    if (a == '.' && b == '.')
	return '+';
    if (a == '!' && b == '!')
	return '-';
    if (a == '!' && b == '.')
	return '.';
    if (a == '.' && b == '!')
	return ',';
    if (a == '!' && b == '?')
	return '[';
    if (a == '?' && b == '!')
	return ']';
    return '.';
}

int bfsize(int filesize)
{
    int i;
    int sz = 0;
    for (i = 3; i < filesize; i+=10)
	sz++;

    return sz;
}

int getSize(FILE *fp)
{
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return sz;
}


char* ook2bf(char* in_filename)
{
    
    FILE* in_file;
    int filesize;
    int i;
    
    in_file = fopen(in_filename, "r");

    filesize = getSize(in_file);
    
    char ook[filesize];    
    fread(ook, 1, filesize, in_file);
    
    

    fclose(in_file);
    char* bf = malloc(bfsize(filesize));
    char c;
    for (i = 3; (i+5) < filesize; i+=10)
    {
	if (!isValid(ook[i]) || !isValid(ook[i+5]))
	    continue;
	c = ook2bfchar(ook[i], ook[i+5]);
	bf[(i-3)/10] = c;
    }

    return bf;
    
}
