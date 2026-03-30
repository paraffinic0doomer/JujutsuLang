/* Parser-generated C from JujutsuLang source */
#include <stdio.h>

int x,i,j;

static void write_symbol_table_runtime(void) {
    FILE *fp = fopen("symbol_table.txt", "w");
    if (!fp) return;
    fprintf(fp, "# Symbol Table\n");
    fprintf(fp, "%-20s %-10s %-8s %-14s\n", "Name", "Type", "Init", "Value");
    fprintf(fp, "----------------------------------------------------\n");
    fprintf(fp, "%-20s %-10s %-8s %-14d\n", "x", "int", "yes", x);
    fprintf(fp, "%-20s %-10s %-8s %-14d\n", "i", "int", "yes", i);
    fprintf(fp, "%-20s %-10s %-8s %-14d\n", "j", "int", "yes", j);
    fclose(fp);
}

int main(void) {
    printf("%s\n", "Enter a value of X:");
    scanf("%d", &x);
    printf("%s\n", "Value of i:");
    for(i = 0; i <= x; i = i + 1)
    {
        for(j = 0; j < x; j = j + 1){
             if(i > 2)
             {
    printf("%g\n", (double)(i));
    printf("%s\n", "Hell Yeah");
             }
        }
    }
    write_symbol_table_runtime();
    return 0;
}
