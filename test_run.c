/* Parser-generated C from JujutsuLang source */
#include <stdio.h>

int x = 2;
int y = 3;
int total = 0;
int ans;

int square()
{
    int t = y * y;
    return t;
}

static void write_symbol_table_runtime(void) {
    FILE *fp = fopen("symbol_table.txt", "w");
    if (!fp) return;
    fprintf(fp, "# Symbol Table\n");
    fprintf(fp, "%-20s %-10s %-8s %-14s\n", "Name", "Type", "Init", "Value");
    fprintf(fp, "----------------------------------------------------\n");
    fprintf(fp, "%-20s %-10s %-8s %-14d\n", "x", "int", "yes", x);
    fprintf(fp, "%-20s %-10s %-8s %-14d\n", "y", "int", "yes", y);
    fprintf(fp, "%-20s %-10s %-8s %-14d\n", "total", "int", "yes", total);
    fprintf(fp, "%-20s %-10s %-8s %-14d\n", "ans", "int", "yes", ans);
    fclose(fp);
}

int main(void) {
    ans = square();
    for (x = 0; x < 4; x = x + 1)
    {
        total = total + x;
    }
    while (total < 10)
    {
        total = total + 1;
    }
    if (ans > 8)
    {
        total = total + ans;
    }
    else
    {
        total = total - 1;
    }
    printf("%s\n", "Final total:");
    printf("%g\n", (double)(total));
    write_symbol_table_runtime();
    return 0;
}
