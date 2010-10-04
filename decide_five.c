#include<stdio.h>

typedef struct {
    int val;
    int state;
} no;

int ll = 150000;

int a2[32];

int cal2(int i) {
    no sc[ll];
    int j;
    for (j = 0; j <= ll; j++) {
        sc[j].val = j;
        sc[j].state = 0;
    }

    int x, y, z, zz, zzz;
    for (x = 0; x <= i; x++) {
        for (y = 0; y <= i; y++) {
            int te1 = a2[x] + a2[y];
            for (z = 0; z <= i; z++) {
                int te2 = te1 + a2[z];
                for (zzz = 0; zzz <= i; zzz++) {
                    int te3 = te2 + a2[zzz];
                    for (zz = 0; zz <= i; zz++) {
                        int temp = te3 + a2[zz];
                        if (sc[temp].state == 0)
                            sc[temp].state = 1;
                    }
                }
            }
        }
    }

    int count = 0;
    for (i = 0; i <= ll; i++) {
        if (sc[i].state == 1)count++;
        else if (sc[i].state == 0)break;
    }

    return count;

}

int calculate(int i, int door) {
    if (door == 2)return cal2(i);
}

int main() {

    FILE *fo = fopen("X:\\d\\sod5_all.out", "r");

    int a[20][20];
    int score[20];
    int p;
    for (p = 0; p < 20; p++) {
        score[p] = 0;
    }

    int t, tt;

    a2[0] = 0;
    for (t = 1; t <= 397; t++) {

        printf("%d\n", t);
        for (tt = 0; tt < 21; tt++) {
            fscanf(fo, "%d,", &a2[tt + 1]);
        }
        int decision[20];
        int i, j;
        for (i = 1; i <= 20; i++) {
            int res1 = score[i];
            int res2 = calculate(i, 2);
            if (res1 >= res2)decision[i] = 1;
            else decision[i] = 2;
        }

        for (i = 1; i < 21; i++) {
            if (decision[i] == 2) {
                for (j = 1; j <= i; j++) {
                    a[i - 1][j - 1] = a2[j];
                    score[i] = calculate(i, 2);
                }
            }
        }

    }

    fclose(fo);

    FILE *fpe = fopen("X:\\d\\sod5_result.out", "w");
    int i, j;
    for (i = 1; i <= 20; i++) {
        fprintf(fpe, "\n5: ");
        for (j = 1; j <= i; j++) {
            if (j != i)
                fprintf(fpe, "%d, ", a[i - 1][j - 1]);
            else
                fprintf(fpe, "%d", a[i - 1][j - 1]);
        }
        if (i != 20)fprintf(fpe, ";");
    }
    fclose(fpe);

    return 0;

}



