#include "head.h"

void workspace(){
    Tr *tree;
    int valve = NULL;
    _Bool found = 0;
    char cmd[10];
    tree = create_tree();
    Route_table route[]={
        {"add",add_dot},
        {"search",search_dot},
        {"del",rm_list},
        {"show",print_tree},
        {"help",helpMenu}
    };
    printf("\tStart of work!\n");
    while(1){
        int i;
        found = 0;
        valve = NULL;
        printf(">");
        scanf("%s", cmd);
        for(i=0;i<sizeof(route)/sizeof(Route_table);i++){
            if(!strcmp(route[i].cmd, cmd)){
                found = 1;
                route[i].func(tree,valve);
                break;
            }
        }
        if (!strcmp(cmd, "exit"))
            break;
        if(!found){
            printf("unknown parameters!\nuse help!\n");
        }
    }
    printf("\tEnd of work!\n");
    free(tree);
}