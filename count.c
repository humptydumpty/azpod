

#include<stdio.h>
#include<math.h>
#include <string.h>

typedef struct {
    int val;
    int state;
} no;

int choice[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 2};

FILE *fp;
no min_left[40000];
int result[45];
no scratch_list[40000 + 1];

int scratch_length;
int res_length;
int min_left_length;

int bins(int t, int left, int right) {
    int mid = (left + right) / 2;

    if (t == min_left[mid].val)return mid;
    else if (left > right)return -1;
    else if (t < min_left[mid].val)return bins(t, left, mid - 1);
    else return bins(t, mid + 1, right);

}

void search(int t) {
    int index = bins(t, 0, min_left_length - 1);
    if (index != -1)min_left[index].state = 1;
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
    int ll = 40000;
    int i;

    scratch_length = 0;
    res_length = 0;
    min_left_length = 0;

    for (i = 0; i < ll; i++) {
        scratch_list[i].val = i;
        scratch_list[i].state = 0;
        min_left[i].state = 0;
    }
    scratch_list[ll].val = i;
    scratch_list[ll].state = 0;

    result[0] = 0;
    res_length++;

    result[1] = 1;
    res_length++;


    int j, k, tt;
    int t;
    while (res_length < nor + 2) {
        scratch_list[0].state = 1;
        //printf("%d-", res_length);
        for (i = 0; i < res_length; i++) {
            for (j = 0; j < res_length; j++) {
                //for (j = res_length-1; j < res_length; j++) {
                int tem1 = result[i] + result[j];
                for (tt = 0; tt < res_length; tt++) {
                    int tem2 = tem1 + result[tt];
                    //for (k = res_length - 1; k < res_length; k++) {
                    k = res_length - 1;
                    int temp = tem2 + result[k];
                    if (scratch_list[temp].state == 0) {
                        scratch_list[temp].state = 1;
                        if ((temp) > scratch_length)
                            scratch_length = (temp);
                    }
                    //}
                }
            }
        }
        min_left_length = 0;

        for (t = result[res_length - 1]; t <= ll; t++) {
            if (scratch_list[t].state == 0) {
                min_left[min_left_length].val = scratch_list[t].val;
                min_left[min_left_length++].state = 0;
            }
        }


        int max = result[res_length - 1];
        int score = 0;
        int index1 = -1;
        int index2 = -1;
        int index3 = -1;
        int ones = -1;

        for (t = max + 1; t <= min_left[0].val; t++) {

            int k, l;

            for (k = 0; k < ll; k++) {
                min_left[k].state = 0;
            }

            int score1 = 0;
            int score2 = 0;
            int score3 = 0;

            search(4 * t);
            for (j = 0; j < res_length; j++) {
                search((3 * t) + result[j]);
                for (k = 0; k < res_length; k++) {
                    int te1 = result[j] + result[k];
                    search((2 * t) + te1);
                    for (l = 0; l < res_length; l++) {
                        search(t + te1 + result[l]);
                    }
                }
            }


            score1 = find();

            int myones;

            myones = count_one();

            if (score < score1) {
                score3 = score2;
                index3 = index2;
                score2 = score;
                index2 = index1;
                score = score1;
                index1 = t;
                ones = myones;
            } else if (score1 == score) {
                if (myones > ones) {
                    score3 = score2;
                    index3 = index2;
                    score2 = score;
                    index2 = index1;
                    score = score1;
                    index1 = t;
                    ones = myones;
                }
            }
        }

        if (choice[res_length] == 0) {
            result[res_length++] = index1;
        } else if (choice[res_length] == 1) {
            if (index2 != -1) {
                result[res_length++] = index2;
            } else {
                result[res_length++] = index1;
            }
        } else if (choice[res_length] == 2) {
            if (index3 != -1) {
                result[res_length++] = index3;
            } else if (index2 != -1) {
                result[res_length++] = index2;
            } else {
                result[res_length++] = index1;
            }
        }
    }
    for (i = 1; i < res_length; i++) {
        //printf("%d\n", i);
        if (i < (res_length - 1))
            fprintf(fp, "%d,", result[i]);
        else
            fprintf(fp, "%d", result[i]);
    }

}
int fflag;

void print_choice() {
    //printf("hello");
    printf("\n");
    int i;
    for (i = 0; i < 30; i++) {
        printf("hello");
        printf("%d---", choice[i]);
    }
}

int main() {
    //fp = fopen("X:\\d\\sod4.out", "w");
    FILE *fps = fopen("X:\\d\\sodst.out", "w");
    printf("doing\n");

    fflag = 0;
    int i;

    for (i = 0;; i++) {
        fprintf(fps, "\n%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", choice[0], choice[1], choice[2], choice[3], choice[4], choice[5], choice[6], choice[7], choice[8], choice[9], choice[10], choice[11], choice[12], choice[13], choice[14], choice[15], choice[16], choice[17], choice[18], choice[19], choice[20], choice[21], choice[22], choice[23], choice[24], choice[25], choice[26], choice[27], choice[28], choice[29]);
        //fprintf(fps,"\n%d",choice[0]);



        printf("\n%d: ", i);
        //dothework(30);
        //fprintf(fp, "\n");
        //fflush(fp);
        int j;

        if (choice[0] == 2 && choice[1] == 1)break;

        for (j = 29; j > 0; j--) {

            if (fflag == 1) {
                choice[29] = 1;
                //printf("\nChoice %d = 1", 29);
                fflag = 0;
                break;
            } else if (choice[29] == 2) {
                choice[28] = 2;
                //printf("\n\nChoice %d = 2", 28);
                choice[29] = 0;
                fflag = 1;
            } else if ((choice[j - 1] == 2) && (choice[j] == 1)) {
                choice[j - 2] = 1;
                //printf("\nChoice %d = 1", (j - 2));
                choice[j] = 0;
            } else if (choice[0] == 1 && choice [j - 1] == 2) {
                choice[0] = 0;
                choice[j - 2] = 2;
                // printf("\n\nChoice %d = 2", (j - 2));
                choice[j - 1] = 0;
                fflag = 1;
                break;
            } else if (choice[j] == 1) {
                choice[j] = 0;
                choice[j - 1] = 1;
                //printf("\nChoice %d = 1", (j - 1));
                break;
            }
        }

    }
    //fclose(fp);
    fclose(fps);
    return 0;
}
