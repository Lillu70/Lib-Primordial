
#include <stdio.h>

#define length(array) (sizeof(array) / sizeof(array[0]))


char* abs = 
"\n"
"SIG %s Abs(%s value)\n"
"{\n"
"    %s result = (value >= 0)? value: value * -1;\n"
"    return result;"
"}\n\n";


char* cmp = 
"\n"
"SIG %s %s(%s a, %s b)\n"
"{\n"
"    %s result = (a %c b)? a: b;\n"
"    return result;\n"
"}\n\n";


void gen_max(char* type)
{
	printf(cmp, type, "Max", type, type, type, '>');
}


void gen_min(char* type)
{
	printf(cmp, type, "Min", type, type, type, '<');
}


void gen_abs(char* type)
{
	printf(abs, type, type, type);
}


int main()
{
	char* signed_types[] = 
	{
		"f64",
		"f32",
		"s64",
		"s32",
		"s16",
		"s8"
	};

	char* unsigned_types[] = 
	{
		"u64",
		"u32",
		"u16",
		"u8",
	};


	for(unsigned long long i = 0; i < length(signed_types); ++i)
	{
		char* t = signed_types[i];

		gen_max(t);
		gen_min(t);
		gen_abs(t);
	}


	for(unsigned long long i = 0; i < length(unsigned_types); ++i)
	{
		char* t = unsigned_types[i];

		gen_max(t);
		gen_min(t);
	}

	return 0;
}