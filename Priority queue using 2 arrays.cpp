#include <stdio.h>
#define MAX 10

int d[MAX], p[MAX], n = 0;

void enqueue(int x, int pr) {
    if (n == MAX) printf("Overflow\n");
    else { d[n] = x; p[n] = pr; n++; printf("Inserted\n"); }
}

void dequeue() {
    if (n == 0) { printf("Underflow\n"); return; }
    int hp = 0;
    for (int i = 1; i < n; i++)
        if (p[i] < p[hp]) hp = i;
    printf("Deleted: %d\n", d[hp]);
    for (int i = hp; i < n - 1; i++) {
        d[i] = d[i + 1];
        p[i] = p[i + 1];
    }
    n--;
}

void display() {
    if (n == 0) { printf("Underflow\n"); return; }
    for (int i = 0; i < n; i++)
        printf("%d(p:%d) ", d[i], p[i]);
    printf("\n");
}

int main() {
    int ch, val, pr;
    do {
        printf("\n1.Ins 2.Del 3.Disp 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Val, Pri: ");
            scanf("%d%d", &val, &pr);
            enqueue(val, pr);
        } else if (ch == 2) {
            dequeue();
        } else if (ch == 3) {
            display();
        }
    } while (ch != 4);
    return 0;
}
