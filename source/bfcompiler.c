#define START_SIZE 10
typedef struct List
{
    unsigned int size;
    char* array;

} List;


void create_list(List* s)
{
    s->size = START_SIZE;
    s->array = malloc(START_SIZE);
    int i;
    for (i = 0; i < s->size; i++)
	s->array[i] = 0;
    
}

void right_change_size(List* s, int new_size)
{
    char* new_array = malloc(new_size);
    unsigned int i;
    for (i = 0; i < s->size; i++)
	new_array[i] = s->array[i];
    for (i = s->size; i < new_size; i++)
	new_array[i] = 0;

    free(s->array);
    s->array = new_array;

    s->size = new_size;
    
    
    
}

int left_change_size(List* s, int new_size)
{
    char* new_array = malloc(new_size);
    unsigned int i;
    for (i = 0; i < s->size; i++)
	new_array[i+new_size-s->size-1] = s->array[i];
    
    for (i = 0; i < new_size-s->size-1; i++)
	new_array[i] = 0;
    
    free(s->array);
    s->array = new_array;

    int ret = new_size - s->size;
    
    s->size = new_size;
    
    return ret;
}

int right_matching(char* text, int pos)
{
    int level = 0;
    int i;
    for (i = pos+1;;i++)
    {
	if (i >= strlen(text))
	    return strlen(text)-1;
	if (text[i] == '[')
	    level++;
	if (text[i] == ']' && level-- == 0)
	    break;

    }

    return i;
}

int left_matching(char* text, int pos)
{
    int level = 0;
    int i;
    for (i = pos-1;;i--)
    {
	if (i < 0)
	    return 0;
	if (text[i] == ']')
	  level++;
	if (text[i] == '[' && level-- == 0)
	    break;
	
    }

    return i;
}


void compilebf(char* bf)
{
    int size;
    int i;
    int ptr;
    List* l;
    
    size = strlen(bf);
    
    ptr = START_SIZE / 2;
    create_list(l);

    for (i = 0; i < size; i++)
    {
	switch(bf[i])
	{
	case '>':
	    ptr++;
	    if (ptr >= l->size)
		right_change_size(l, l->size*2);
	    break;
	case '<':
	    ptr--;
	    if (ptr < 0)
		ptr += left_change_size(l, l->size*2);
	    break;
	case '+':
	    l->array[ptr]++;
	    break;
	case '-':
	    l->array[ptr]--;
	    break;
	case '.':
	    putchar(l->array[ptr]);
	    break;
	case '[':
	    if (!l->array[ptr])
		i = right_matching(bf, i);
	    break;
	case ']':
	    i = left_matching(bf, i)-1;
	    break;
	    
	}

	}
    
}
