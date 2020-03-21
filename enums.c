#include <stdio.h>
#include <stdlib.h>

enum Company {
	GOOGLE,
	FACEBOOK,
	YOUTUBE,
	GITHUB,
	APPLE,
	AMAZON
};

int main(void) {

	// using enums
	enum Company google = GOOGLE;
	enum Company youtube = YOUTUBE;
	enum Company amazon = AMAZON;

	printf("The value of google is: %d\n", google);
	printf("The value of youtube is: %d\n", youtube);
	printf("The value of amazon is: %d\n", amazon);
	return 0;
}