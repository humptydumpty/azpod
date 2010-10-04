#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    int val;
    int state;
} no;

int choice[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 2};

FILE *fp;
no min_left[150000];
int result[15];
no scratch_list[150000 + 1];

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
    int ll = 150000;
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


    int j, k, tt, ttt, tttt;
    int t;
    while (res_length < nor + 2) {
        scratch_list[0].state = 1;

        for (i = 0; i < res_length; i++) {
           // printf("\ni= %d", i);
            for (j = 0; j < res_length; j++) {

                int tem1 = result[i] + result[j];
                for (ttt = 0; ttt < res_length; ttt++) {
                    for (tttt = 0; tttt < res_length; tttt++) {
                        int tem4 = tem1 + result[tttt];
                        int tem3 = tem4 + result[ttt];
                        for (tt = 0; tt < res_length; tt++) {

                            int tem2 = tem3 + result[tt];
                            k = res_length - 1;

                            int temp = tem2 + result[k];

                            if (scratch_list[temp].state == 0) {
                                scratch_list[temp].state = 1;
                                if ((temp) > scratch_length)
                                    scratch_length = (temp);
                            }

                        }
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
        int ones = -1;

        for (t = max + 1; t <= min_left[0].val; t++) {

            int k, l, ll, lll;

            for (k = 0; k < min_left_length; k++)min_left[k].state = 0;

            int score1 = 0;
            int score2 = 0;
            int score3 = 0;

            search(6 * t);
            for (j = 0; j < res_length; j++) {
                search((5 * t) + result[j]);
                for (k = 0; k < res_length; k++) {
                    int te1 = result[j] + result[k];
                    search((4 * t) + te1);
                    for (l = 0; l < res_length; l++) {
                        int te2 = te1 + result[l];
                        search((3 * t) + te2);
                        for (ll = 0; ll < res_length; ll++) {
                            int te3 = te2 + result[ll];
                            search((2 * t) + te3);
                            for (lll = 0; lll < res_length; lll++) {
                                search(t + te3 + result[lll]);
                            }
                        }
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

        if (i < (res_length - 1))
            fprintf(fp, "%d,", result[i]);
        else
            fprintf(fp, "%d", result[i]);
    }

}

int fflag;
int main() {
    fp = fopen("X:\\d\\sod6.out", "w");
    printf("doing...\n");

    int i;
    for (i = 0;; i++) {

        printf("\n%d: ", i);
        dothework(10);
        fprintf(fp, "\n");
        fflush(fp);
        int j;

        if (choice[0] == 2 && choice[1] == 1)break;

        for (j = 9; j > 0; j--) {

            if (fflag == 1) {
                choice[9] = 1;
                fflag = 0;
                break;
            } else if (choice[9] == 2) {
                choice[8] = 2;
                choice[9] = 0;
                fflag = 1;
            } else if ((choice[j - 1] == 2) && (choice[j] == 1)) {
                choice[j - 2] = 1;
                choice[j] = 0;
            } else if (choice[0] == 1 && choice [j - 1] == 2) {
                choice[0] = 0;
                choice[j - 2] = 2;
                choice[j - 1] = 0;
                fflag = 1;
                break;
            } else if (choice[j] == 1) {
                choice[j] = 0;
                choice[j - 1] = 1;
                break;
            }
        }

    }
    fclose(fp);
    return 0;
}



