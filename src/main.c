
#include <stdio.h>
#include <unistd.h>

static char[4096] input_buff;

static FILE* input_stream;
static FILE* output_stream;

static size_t input_size;

int put_to_stream(const char* str)
{
    fprintf(stdout_stream, "%s\n", str);
}

int get_from_stream(const char* str)
{
    fprintf(stdout_stream, "%s\n", str);
}

void close_streams(void)
{

}

size_t fgetsize(FILE *file)
{
    fseek(f, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(f, 0, SEEK_SET);
    return size;
}

int main(int argc, char *argv[]) {
    //opterr = 0;
	int rez = 0;
	while ( (rez = getopt(argc, argv, "o:f:")) != -1){
        switch (rez) {
		case 'o':
            stdout_stream = fopen(optarg, "r");
            if(stdout_stream == NULL)
            {
                stdout_stream = stdout;
            }
            break;
		case 'f':
            stdin_stream = fopen(optarg, "r");
            if(stdin_stream == NULL)
            {
                stdin_stream = stdin;
            }
            fsize = fgetsize(stdin_stream);
            if(fread(input_buff, fsize, stdin_stream) == 0)
            {
                
            }
            break;
		case '?':
            return -1;
        case ':':
            return -2;
		}
	}
}
