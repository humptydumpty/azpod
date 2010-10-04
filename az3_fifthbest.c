#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    int val;
    int state;
} no;


int choice[40] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 1};

/*
int choice[40] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 0, 4, 4, 4};
 */


int inc(int i) {

    if (i == 0 && choice[i] == 4) return 0;
    if (choice[i] < 4) {
        choice[i]++;
        return 1;
    } else {
        choice[i] = 0;
        return (inc(i - 1));
    }
    //return 1;
}


FILE *fp;
no min_left[10000];
int result[45];
no scratch_list[10000 + 1];

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
    int ll = 10000;
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
    int j, k;
    int t;
    while (res_length < nor + 2) {
        scratch_list[0].state = 1;
        for (i = 0; i < res_length; i++) {
            for (j = 0; j < res_length; j++) {
                int te1 = result[i] + result[j];
                for (k = res_length - 1; k < res_length; k++) {
                    int tem = result[k] + te1;
                    if (scratch_list[tem].state == 0) {
                        scratch_list[tem].state = 1;
                        if ((tem) > scratch_length)
                            //scratch_length = (result[i] + result[j] + result[k]);
                            scratch_length = (tem);
                    }
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
        int index4 = -1;
        int index5 = -1; // CHANGE
        int ones = -1;
        for (t = max + 1; t <= min_left[0].val; t++) {
            int k;
            for (k = 0; k < ll; k++)min_left[k].state = 0;
            int score1 = 0;
            int score2 = 0;
            int score3 = 0;
            int score4 = 0;
            int score5 = 0; // CHANGE
            search(3 * t);
            for (j = 0; j < res_length; j++) {
                search(t + t + result[j]);
                for (k = 0; k < res_length; k++) {
                    search(t + result[j] + result[k]);
                }
            }
            score1 = find();
            int myones;
            myones = count_one();
            if (score < score1) {
                score5 = score4;
                index5 = index4;
                score4 = score3;
                index4 = index3;
                score3 = score2;
                index3 = index2;
                score2 = score;
                index2 = index1;
                score = score1;
                index1 = t;
                ones = myones;
            } else if (score1 == score) {
                if (myones > ones) {
                    score5 = score4;
                    index5 = index4;
                    score4 = score3;
                    index4 = index3;
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
        if (choice[res_length] == 0)
            result[res_length++] = index1;
        else if (choice[res_length] == 1) {
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
        } else if (choice[res_length] == 3) {
            if (index4 != -1) {
                result[res_length++] = index4;
            } else if (index3 != -1) {
                result[res_length++] = index3;
            } else if (index2 != -1) {
                result[res_length++] = index2;
            } else {
                result[res_length++] = index1;
            }
        } else if (choice[res_length] == 4) {
            if (index5 != -1) {
                result[res_length++] = index5;
            } else if (index4 != -1) {
                result[res_length++] = index4;
            } else if (index3 != -1) {
                result[res_length++] = index3;
            } else if (index2 != -1) {
                result[res_length++] = index2;
            } else {
                result[res_length++] = index1;
            }
        }
    }
    for (i = 1; i < res_length; i++) {

        if (i < (res_length - 1)) {
            fprintf(fp, "%d,", result[i]);
            fflush(fp);
        } else {
            fprintf(fp, "%d", result[i]);
            fflush(fp);
        }
    }
}

int fflag, fflag3;

int main() {
    fflag = 0;
    fflag3 = 0;
    printf("doing...\n");
    fp = fopen("sod3.out", "w");
    FILE *fps = fopen("count.out", "w");
    int i;
    for (i = 0;; i++) {
        fprintf(fps, "\n%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", choice[0], choice[1], choice[2], choice[3], choice[4], choice[5], choice[6], choice[7], choice[8], choice[9], choice[10], choice[11], choice[12], choice[13], choice[14], choice[15], choice[16], choice[17], choice[18], choice[19], choice[20], choice[21], choice[22], choice[23], choice[24], choice[25], choice[26], choice[27], choice[28], choice[29], choice[30], choice[31], choice[32], choice[33], choice[34], choice[35], choice[36], choice[37], choice[38], choice[39]);
        fflush(fps);
        printf("\n%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d : %6d", choice[0], choice[1], choice[2], choice[3], choice[4], choice[5], choice[6], choice[7], choice[8], choice[9], choice[10], choice[11], choice[12], choice[13], choice[14], choice[15], choice[16], choice[17], choice[18], choice[19], choice[20], choice[21], choice[22], choice[23], choice[24], choice[25], choice[26], choice[27], choice[28], choice[29], choice[30], choice[31], choice[32], choice[33], choice[34], choice[35], choice[36], choice[37], choice[38], choice[39], i);

        //printf("\n%d: ", i);
        dothework(40);
        fprintf(fp, "\n");
        fflush(fp);
        int j;

        if (inc(39) == 0) break;

    }

    fclose(fp);
    fclose(fps);
    return 0;
}
