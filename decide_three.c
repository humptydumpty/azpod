#include<stdio.h>

typedef struct {
    int val;
    int state;
} no;


int ll = 30000;


//int a1[42] = {0, 1, 3, 8, 12, 18, 22, 49, 57, 68, 92, 115, 144, 177, 203, 205, 260, 273, 395, 412, 414, 493, 552, 630, 720, 736, 838, 926, 1076, 1166, 1237, 1240, 1268, 1338, 1428, 1499, 1926, 2016, 2247, 2369, 2596, 2610};

int a2[42];

/*
int cal1(int i) {
    no sc[ll];
    int j;
    for (j = 0; j <= ll; j++) {
        sc[j].val = j;
        sc[j].state = 0;
    }

    int x, y, z;
    for (x = 0; x <= i; x++) {
        for (y = 0; y <= i; y++) {
            for (z = 0; z <= i; z++) {
                int temp = a1[x] + a1[y] + a1[z];
                if (sc[temp].state == 0)
                    sc[temp].state = 1;
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
 */
int cal2(int i) {
    no sc[ll];
    int j;
    for (j = 0; j <= ll; j++) {
        sc[j].val = j;
        sc[j].state = 0;
    }

    int x, y, z;
    for (x = 0; x <= i; x++) {
        for (y = 0; y <= i; y++) {
            for (z = 0; z <= i; z++) {
                int temp = a2[x] + a2[y] + a2[z];
                if (sc[temp].state == 0)
                    sc[temp].state = 1;
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
    //if (door == 1)return cal1(i);
    //else
    if (door == 2)return cal2(i);
}

int main() {

    FILE *fo = fopen("C:\\Users\\Seedrick\\Desktop\\az\\sod3_2.out", "r");
    //FILE *fp = fopen("X:\\sod_16k.out", "w");

    int a[40][40];
    int score[40];
    int p;
    for (p = 0; p < 40; p++) {
        score[p] = 0;
    }

    long t, tt;

    a2[0] = 0;
    for (t = 1; t <= 70122; t++) {

        printf("%d\n", t);
        for (tt = 0; tt < 41; tt++) {
            if (tt != 40) {
                fscanf(fo, "%d,", &a2[tt + 1]);
            } else if (tt == 40) {
                fscanf(fo, "%d", &a2[tt + 1]);
            }
        }
        int decision[40];
        int i, j;
        for (i = 1; i <= 40; i++) {
            int res1 = score[i];
            int res2 = calculate(i, 2);
            //printf("%d, %d\n", res1, res2);
            if (res1 >= res2)decision[i] = 1;
            else decision[i] = 2;
        }


        /////////////////
        for (i = 1; i < 41; i++) {
            if (decision[i] == 2) {
                for (j = 1; j <= i; j++) {
                    a[i - 1][j - 1] = a2[j];
                    score[i] = calculate(i, 2);
                }
            }
        }
        /////////////////



    }//t


    /*
        for (i = 1; i < 41; i++) {
            fprintf(fp, "3: ");

            if (decision[i] == 1) {
                for (j = 1; j <= i; j++) {
                    if (j != (i))

                        fprintf(fp, "%d, ", a1[j]);
                    else
                        fprintf(fp, "%d", a1[j]);
                }
                if (i != (40))fprintf(fp, ";\n");
                else fprintf(fp, "\n");
            } else if (decision[i] == 2) {
                for (j = 1; j <= i; j++) {
                    if (j != (i))

                        fprintf(fp, "%d, ", a2[j]);
                    else
                        fprintf(fp, "%d", a2[j]);
                }
                if (i != (40))fprintf(fp, ";\n");
                else fprintf(fp, "\n");
            }

        }
     */

    /*
        for (i = 0; i < 40; i++) {
            printf("%d", decision[i]);
        }
     */
    //fclose(fp);
    fclose(fo);

    FILE *fpe = fopen("C:\\Users\\Seedrick\\Desktop\\azsod3_result.out", "w");
    int i, j;
    for (i = 1; i <= 40; i++) {
        fprintf(fpe, "\n3: ");
        for (j = 1; j <= i; j++) {
            if (j != i)
                fprintf(fpe, "%d, ", a[i - 1][j - 1]);
            else
                fprintf(fpe, "%d", a[i - 1][j - 1]);
        }
        if (i != 40)fprintf(fpe, ";");
    }
    fclose(fpe);

    return 0;

}
