
// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

#include <stdio.h>

#define length(array) (sizeof(array) / sizeof(array[0]))


char* comment =
"\n"
"// ===================================\n"
"// Copyright (c) %d by Valtteri Kois\n"
"// All rights reserved.\n"
"// ===================================\n"
"\n";


char* abs = 
"\n"
"SIG %s Abs(%s value)\n"
"{\n"
"    %s result = (value >= 0)? value: value * -1;\n"
"    return result;\n"
"}\n\n";


char* cmp = 
"\n"
"SIG %s %s(%s a, %s b)\n"
"{\n"
"    %s result = (a %c b)? a: b;\n"
"    return result;\n"
"}\n\n";


char* sqr =
"\n"
"SIG %s Square(%s v)\n"
"{\n"
"    %s result = v * v;\n"
"    return result;\n"
"}\n\n";


char* cubed =
"\n"
"SIG %s Cube(%s v)\n"
"{\n"
"    %s result = v * v * v;\n"
"    return result;\n"
"}\n\n";


void gen_comment(int year)
{
	printf(comment, year);
}


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


void gen_square(char* type)
{
	printf(sqr, type, type, type);
}


void gen_cube(char* type)
{
	printf(cubed, type, type, type);
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

	char** all_types = signed_types;
	unsigned long long all_types_count = length(signed_types) + length(unsigned_types);

	gen_comment(2025);

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

	for(unsigned long long i = 0; i < all_types_count; ++i)
	{
		char* t = all_types[i];
		gen_square(t);
		gen_cube(t);
	}

	return 0;
}