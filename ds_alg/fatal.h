// This file include some function mention in this book

#include <stdio.h>
#include <stdlib.h>

#define Error( Str )		FatalError( Str )
#define FatalError( Str )	fprintf( stderr, "%s\n", Str ), exit(1)
