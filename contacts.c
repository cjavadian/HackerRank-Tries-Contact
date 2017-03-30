#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH    26
#define OPERATION_BUF_SIZE  5
#define NAME_BUF_SIZE      22

/* Basic trie node -- also, keep track of number of nodes below this one. */
typedef struct node {
    int num_children;
    struct node *children[ALPHABET_LENGTH];
} trie_node;

//This is needed to run printf() function.
int main() {
	int lines;
	scanf("%i", &lines);
	while (lines) {
		char input;
    	scanf("%c", &input);
		if (strcmp("add", &input) == 0) {
			//add the add contact function here
		}
		else if (strcmp("find", &input) == 0) {
			//add the find contact function here
			//add the output function here
		}
		lines--;
	}
	
    return 0;
}
