


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

int bfsize(char* text, int filesize)
{
    int i;
    int sz = 0;
    for (i = 0; i < filesize; i++)
	if (isValid(text[i]))
	    sz++;

    sz -= sz % 2;
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
    char* bf = malloc(bfsize(ook, filesize));
    int index = 0;
    char c;
    char last_character = '0';
    for (i = 0; i < filesize; i++)
    {
	if (isValid(ook[i]))
	{
	    if (last_character == '0')
		last_character = ook[i];
	    else
	    {
		c = ook2bfchar(last_character, ook[i]);
		bf[index] = c;
		index++;
		last_character = '0';
	    }
	}
    }

    return bf;
    
}
