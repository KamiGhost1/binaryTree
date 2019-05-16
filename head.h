#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define debug

#pragma pack(push,1)
typedef struct _TREE{
	int valve;
	struct Tr *R, *L, *Pre;
} Tr;
#pragma pack(pop)

typedef struct _route{
	char cmd[20];
	void (*func)();
}Route_table;

Tr *create_tree();
Tr *create_dot(int dot);
void add_dot(Tr *tree);
Tr *search_dot(Tr *tree, int dot);
void print_tree(Tr *tree);
void workspace();
void helpMenu();
void rm_list(Tr *tree, int dot);
Tr  *balance(Tr *tree);