#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LENGTH    26
#define OPERATION_BUF_SIZE  5
#define NAME_BUF_SIZE      22


/* Basic trie node -- also, keep track of number of nodes below this one. */
typedef struct node {
    int num_children; 
    struct node *children[ALPHABET_LENGTH]; //  the characters stored at every level
} trie_node;

trie_node * newNode() {
	trie_node * new = (trie_node*)calloc(1, sizeof(trie_node));
	return new;
}

trie_node * find(const char* name, trie_node * root) {
	int index = *name - 'a';
    if (!*name) {
        return root;
    }
    trie_node * ch = root->children[index];
    if (!*(name+1) && (ch == NULL)) {
        return ch;
    }
    if (ch != NULL) {
        return find(name+1, ch);
    }
    return NULL;
}

void add(const char* name, trie_node * root) {
    root->num_children++;
    if (!*name) {
        return;
    }
    int index = *name - 'a';
    trie_node * ch = root->children[index];
    if (ch != NULL) {
        name++;
        add(name, ch);
        return;
    }
    ch = newNode();
    root->children[index] = ch;
    name++;
    add(name, ch);
}

//This is needed to run printf() function.
int main() {
	int lines;
	scanf("%i", &lines);
    trie_node * root = newNode();
    trie_node * last = newNode();
	while (lines) {
		char inst[OPERATION_BUF_SIZE];
		char name[NAME_BUF_SIZE];
    	scanf("%s", inst);
		scanf("%s", name);
		if (inst[0] == 'a') {
			add(name, root);
		} else if (inst[0] == 'f') {
			last = find(name, root);
            if (last != NULL) {
				printf("%i\n", last->num_children);
			} else {
				printf("0\n");
            }
		}
		lines--;
	}
	
    return 0;
}
