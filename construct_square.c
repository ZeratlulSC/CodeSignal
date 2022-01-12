char* diff_letters (char *s);
char* diff_nmbrs (int nmbr);
int squares (int *len);
bool str_cmpr (char *let, char* nmbr);

int cmp(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int solution(char * s) {
    char * ret_l = (char*) malloc(27);
    int *square = (int*) malloc(31622*sizeof(int)); 
    ret_l = diff_letters(s);
    qsort(ret_l, strlen(ret_l), 1, cmp);
    char * ret_n = (char*) malloc(11);
    squares(square);
    ret_n = diff_nmbrs(square[31621]);
    qsort(ret_n, strlen(ret_n), sizeof(char), cmp);
    int nmbrs = 31621;
    while (!str_cmpr(ret_l, ret_n)) {
        nmbrs--;
        ret_n = diff_nmbrs(square[nmbrs]);
        qsort(ret_n, strlen(ret_n), sizeof(char), cmp);
        if (nmbrs == -1) return -1;
    }
    return square[nmbrs];
}

char* diff_letters(char *s){
    int * ret = (int*) malloc(26*sizeof(int));
    for (int i = 0; i < strlen(s); i++){
        ret[s[i]-97]++;
    }
    int size = 0;
    for (int i = 0; i < 26; i++) {
        if (ret[i] !=0) size++;
    }
    char * ret_ch = (char*) malloc(size+1);
    for (int i = 0; i < size; i++){
        while((ret[i]) == 0) ret++;
        sprintf(ret_ch+i, "%d", ret[i]);
    }
    //printf("%s\n", ret_ch);
    //free(ret);
    return ret_ch;
}

int squares (int *len){
    for (int i = 0; i < 31622; i++) len[i] = (i+1)*(i+1);
}

char * diff_nmbrs (int nmbr){
    int * nmbrs = (int*)malloc(10*sizeof(int));
    for (int i = nmbr; i > 0; i=i/10){
        nmbrs[i%10]++;
    }
    int size = 0;
    for (int i = 0; i < 10; i++) {
        if (nmbrs[i] !=0) size++;
        //printf("%d ", nmbrs[i]);
    }
    char * ret_ch = (char*) malloc(size+1);
    for (int i = 0; i < size; i++){
        while((nmbrs[i]) == 0) nmbrs++;
        sprintf(ret_ch+i, "%d", nmbrs[i]);
    }
    //printf("\n%s\n", ret_ch);
    return ret_ch;
}

bool str_cmpr (char *let, char* nmbr){
    if (strcmp(let, nmbr) == 0) return true;
    return false;
}
