#include <error.h>
#include <matrix.h>
#include <types.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	int t = 0;
	int o = 0;
	char *tvalue = NULL;
	char *ovalue = NULL;
	int c;
	int opterr = 0;
	while((c = getopt(argc, argv, "t:o:")) != -1)
	{
		switch(c)
		{
			case 't':
				tvalue = optarg;
				break;
			case 'o':
				ovalue = optarg;
				break;
			case '?':
				if (optopt == 't' || optopt == 'o')
					fprintf(stderr, "Опция -%c требует тип в качестве аргумента. \n", optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Неизвестная опция '-%c'. \n", optopt);
				else
					fprintf(stderr, "Неизвестный символ опции '\\x%x'. \n", optopt);
				return 1;
			default:
				abort();
		}
	}
	if (tvalue == NULL)
	{
		fprintf(stderr, "Опции требуют аргумента!\n");
		return 1;
	}
    return 0;
}
