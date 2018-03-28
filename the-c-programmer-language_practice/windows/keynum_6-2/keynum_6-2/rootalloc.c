#include <stdio.h>
#include <stdlib.h>

struct troot
{
	char *roots;
	struct tword* root_word;
	struct troot* left;
	struct troot* right;
};
struct troot* rootalloc()
{
	return (struct troot*)malloc(sizeof(struct troot));
}