#include "task1.h"
#include "getopt.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"


int main(int argc, char** argv)
{
	consoleArgs arg;

	char opt;
	int longind;
	const char* options = "i:o:g:G:";;
	const struct option long_options[] = {
											{"in",  required_argument, NULL, 'i'},
											{"out",  required_argument, NULL, 'o'},
											{"gain",    required_argument, NULL, 'g'},
											{"generator",    required_argument, NULL, 'G'}};

	arg = (consoleArgs){ NULL, NULL, NULL, NULL };

	while ((opt = getopt_long(argc, argv, options, long_options, &longind)) != -1)
	{
		switch (opt)
		{
			case 'i':
			{
				arg.in_add = optarg;
				break;
			}
			
			case 'o':
			{
				arg.out_add = optarg;
				break;
			}

			case 'g':
			{
				arg.gain = optarg;
				break;
			}

			case 'G':
			{
				arg.gen_type = optarg;
				break;
			}
		}
	}

	if ((arg.in_add != NULL) &&
		(arg.out_add != NULL) &&
		(arg.gain   == NULL) && 
		(arg.gen_type == NULL))					/*	"--in ... --out ..."	Case for copy existance file into a new one	*/
	{
		printf("\nCopy .wav file from \n\"%s\"\nto\n\"%s\"\n\n", arg.in_add, arg.out_add);
		copyWavFile(arg.in_add, arg.out_add);	/*	Invoking of function, that copies one file into a new one	*/
	}

	else if ((arg.in_add != NULL) &&
		(arg.out_add != NULL) &&
		(arg.gain	!= NULL) &&
		(arg.gen_type == NULL))					/*	"--in ... --out ... --gain ..."	Case for gaining input wav file and writing gained signal into a new file	*/ 
	{
		printf("\nCopy .wav file from \n\"%s\"\nto\n\"%s\"\nwith gain:\n\"%s\"\n\n", arg.in_add, arg.out_add, arg.gain);
		gainWavFile(arg.in_add, arg.out_add, arg.gain);
	}

	else if ((arg.in_add == NULL) &&
		(arg.out_add != NULL) &&
		(arg.gain	== NULL) &&
		(arg.gen_type != NULL))					/*	"--out ... --generator ..." Case for generating test signal and writing into a new .wav file	*/
	{
		printf("Generate %s to\n\"%s\"\n", arg.gen_type, arg.out_add);
		generateWavFile(arg.gen_type, arg.out_add);
	}
	else
	{
		printf("Wrong arguments sequence!");
	}

	return 0;
}
