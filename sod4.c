#include<stdio.h>

typedef struct {
    int val;
    int state;
} no;

FILE *fp;
no min_left[9000];
int result[45];
no scratch_list[9000 + 1];

int scratch_length;
int res_length;
int min_left_length;

void search(int t) {
    int i;
    for (i = 0; i < min_left_length; i++) {
        if (min_left[i].val == t)
            min_left[i].state = 1;
    }
}

int find() {
    int i = 0;
    while (min_left[i++].state == 1 && i < min_left_length);
    return (i - 1);
}

int count_one() {
    int i = 0;
    int count = 0;
    while (i < min_left_length) {
        if (min_left[i].state == 1) {
            count++;
        }
        i++;
    }
    return (count);
}

dothework(int nor) {
    int ll = 9000;
    //int nor;



    //int nod = 3;
    int i;

    scratch_length = 0;
    res_length = 0;
    min_left_length = 0;

    for (i = 0; i <= ll; i++) {
        scratch_list[i].val = i;
        scratch_list[i].state = 0;
    }

    result[0] = 0;
    res_length++;

    result[1] = 1;
    res_length++;

    int j, k, l;
    int t;
    while (res_length < nor + 2) {

        for (i = 0; i < res_length; i++) {
            for (j = 0; j < res_length; j++) {
                for (k = 0; k < res_length; k++) {
                    for (l = 0; l < res_length; l++) {
                        if (scratch_list[result[i] + result[j] + result[k] + result[l]].state == 0) {
                            scratch_list[result[i] + result[j] + result[k] + result[l]].state = 1;
                            if ((result[i] + result[j] + result[k] + result[l]) > scratch_length)
                                scratch_length = (result[i] + result[j] + result[k] + result[l]);
                        }
                    }

                }
            }
        }

        for (t = 0; t < ll; t++) {
            min_left[t].state = 0;
        }

        min_left_length = 0;

        for (t = 1; t <= ll; t++) {
            if (scratch_list[t].state == 0) {
                min_left[min_left_length].val = scratch_list[t].val;
                min_left[min_left_length++].state = 0;
            }
        }


        int max = result[res_length - 1];
        int score = 0;
        int index = -1;
        int ones = -1;

        for (t = max + 1; t <= min_left[0].val; t++) {

            int k;
            for (k = 0; k < ll; k++) {
                min_left[k].state = 0;
            }
            int myscore = 0;

            for (j = 0; j < res_length; j++) {
                for (k = 0; k < res_length; k++) {
                    for (l = 0; l < res_length; l++) {
                        search(t + result[j] + result[k] + result[l]);
                    }
                }
            }
            for (k = 0; k < res_length; k++) {
                for (l = 0; l < res_length; l++) {
                    search(t + t + result[k] + result[l]);
                }
            }

            for (k = 0; k < res_length; k++) {

                search(t + t + t + result[l]);

            }

            search(4 * t);

            myscore = find();

            int myones = count_one();

            if (score < myscore) {
                score = myscore;
                index = t;
                ones = myones;
            } else if (myscore == score) {
                if (myones > ones) {
                    score = myscore;
                    index = t;
                    ones = myones;
                }
            }
        }


        result[res_length++] = index;


    }


    int it;
    for (it = 1; it < res_length; it++) {
        printf("%d\n",it);
        if (it < (res_length - 1)) {
            fprintf(fp, "%d,", result[it]);
        } else {
            fprintf(fp, "%d", result[it]);
        }
    }

}

int main() {
    fp = fopen("C:\\sod4.out", "w");
    printf("Enter the number of regions : ");
    //scanf("%d", &nor);

    int i;

    for (i = 1; i <= 20; i++) {
        fprintf(fp, "4: ");
        dothework(i);
        if (i <= 21) {
            fprintf(fp, ";\n");
        } else {
            fprintf(fp, "\n");
        }
    }



   
        

    fclose(fp);
    return 0;
}

