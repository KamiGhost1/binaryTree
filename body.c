#include "head.h"

Tr *create_tree(){
    Tr *tree;
    int tmp;
    printf("enter pick you tree:");
    scanf("%d",&tmp);
    tree = create_dot(tmp);
    return tree;
}

Tr *create_dot(int dot){
    Tr *tree;
    tree = (Tr*)malloc(sizeof(Tr));
    (*tree).valve=dot;
    (*tree).L=(*tree).R=NULL;
    return tree;
}

void add_dot(Tr *tree){
    int tmp;
    Tr *ptr;
    printf("enter new dot: ");
    scanf("%d",&tmp);
    /*while ((tmp != tree->valve) || ((tree->L==NULL)&&(tree->R==NULL))){
        if (tree->valve == tmp)
            break;
        if (tree->valve < tmp)
            if (tree->R !=NULL)
                tree=tree->R;
            else break;
        if (tree->valve > tmp)
            if (tree->L !=NULL)
                tree=tree->L;
            else break;
    } */
    tree = search_dot(tree,tmp);
    if (!tree){
    printf("error!\n");   
    }
    else if (tree->valve == tmp)
        printf("valve exist!\n");
    else {
        ptr = tree;
        if (tree->valve > tmp){
            tree->L = create_dot(tmp);
            tree=tree->L;
            tree->Pre = ptr;//change
        }
        if (tree->valve < tmp){
            tree->R = create_dot(tmp);
            tree=tree->R;
            tree->Pre = ptr; //change
        }
            
    }
}

void print_tree(Tr *tree) {
	if (tree->L)
		print_tree(tree->L);
	printf("%d \n", tree->valve);
	if (tree->R)
		print_tree(tree->R);
}


Tr *search_dot(Tr *tree, int tmp){
    if (tmp == NULL){
        printf("enter searchItem: ");
        scanf("%d",&tmp);
    }
    if (!tree || tree->valve == tmp){
        if (tree){
            printf("item exists!\n");
            return tree;
        }
        else {
            printf("item doesn't exist!\n");
            return NULL;
        }
    }
    if(tree->valve < tmp){
        if(tree->R)
            return search_dot(tree->R, tmp);
        else return tree;
    }
       
    else {
        if(tree->L)
            return search_dot(tree->L, tmp);
        else return tree;
    }
}


void helpMenu(){
    printf("\tSTART WORK:\n -start\n\tEND WORK:\n exit\n");
    printf("\tOPTIONS:\nadd - add new item\nsearch - search item in list\n");
    printf("show - print list\n");
    printf("del - deleted Item in list\n");
    printf("help - help menu\n");
}

void rm_list(Tr *tree, int dot){
    Tr *ptr;
    if (dot ==NULL){
        printf("enter valve to deleting:");
        scanf("%d",&dot);
    }
    tree = search_dot(tree, dot);
    if (tree->valve == dot){
        if ((!tree->L) && (!tree->R)){
            ptr = tree->Pre;
            if(ptr->valve > tree->valve){
                ptr->L = NULL;
            }
            else {
                ptr->R = NULL;
            }
            tree->valve=NULL;
            free(tree);
            printf("dot deleted\n");
        }

        else if (tree->R && tree->L){
            ptr = balance(tree);
            if (ptr){
                tree = search_dot(ptr->Pre,ptr->valve);
                if (tree->valve > ptr->valve){
                tree->L = ptr;
                ptr->Pre = tree;
                }
                else {
                tree->R = ptr;
                ptr->Pre = tree;
                }
            }
        }

        else if (tree->L){
            ptr=tree->L;
            tree->valve = NULL;
            tree=tree->Pre;
            if(tree->valve > ptr->valve){
                tree->L = ptr;
                ptr = ptr->Pre;
                free(ptr);
            }
            else {
                tree->R = ptr;
                ptr = ptr->Pre;
                free(ptr);
            }
        }
        else if (tree->R){
            ptr=tree->R;
            tree->valve = NULL;
            tree=tree->Pre;
            if(tree->valve > ptr->valve){
                tree->L = ptr;
                ptr = ptr->Pre;
                free(ptr);
            }
            else {
                tree->R = ptr;
                ptr = ptr->Pre;
                free(ptr);
            }
        }
    }
}

Tr *balance(Tr *tree){
    Tr *ptr1, *ptr2;
    ptr1 = tree->L;
    ptr2 = tree->L;
    tree->valve = ptr1->valve;
    if(ptr1->L)
        tree->L = ptr1->L;
    else 
        tree->L = NULL;
    
    if(ptr1->R){
        ptr1 = ptr1->R;
        ptr1->Pre = tree;
        free(ptr2);
        return ptr1;
    }
    else {
        free(ptr2);
        return NULL;
    }
}