
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

	if( argc == 1 ) {
		printf( "Not enough arguments were passed!\n" );
		exit( EXIT_FAILURE );
	}

	printf( "Number of arguments = %d\n", argc );
	printf( "The location and name of this file : %s\n", argv[0] );

	for( unsigned int i = 1; i < argc; i++ )
		printf( "Argv[%d] = %s\n", i, argv[i] );

	return 0;
}
