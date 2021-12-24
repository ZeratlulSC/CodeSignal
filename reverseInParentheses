void reverse (char * string, int len);
void found_pair_parentheses (char * string, int * arr);
bool has_parenth(char * string);
char * clear_answer (char * string);

char * solution(char * inputString) {
    int arr[2] = {0,0};
    //printf("%s\n", inputString);
    while (has_parenth(inputString)) {
        //printf("\n%s", inputString);
        found_pair_parentheses(inputString, arr);
        reverse(inputString+arr[0]+1, arr[1]-arr[0]-1);
        //printf("\n%s", inputString);
    }
    //printf("%s", inputString);
    return clear_answer(inputString);
}

void reverse (char * string, int len){
    char buff;
    //printf("\nlen = %d\n", len);
    for (int i = 0; i < len/2; i++){
        //printf("\n%c %c\n", string[i],string[len-i-1]);
        buff = string[i];
        string[i] = string[len - i - 1];
        string[len - i -1] = buff;
    }
    *(string-1) = '0';
    *(string+len) = '0';
}

void found_pair_parentheses (char * string, int * arr){
    char *buff_left;
    char *buff_right;
    buff_left = strrchr(string, '(');
    buff_right = strchr(string + (buff_left - string), ')');
    arr[0] = buff_left - string;
    arr[1] = buff_right - string;
    //printf("\npos ( = %d pos ) = %d\n", arr[0], arr[1]);
}

bool has_parenth(char * string){
    if (strchr(string, '(') != NULL) return true;
    return false;
}

char * clear_answer (char * string){
    char * ans = (char*) malloc(strlen(string)+1);
    int j = 0;
    for (int i = 0; i < strlen(string); i++){
        if (string[i] != '0') ans[j++] = string[i];
    }
    return ans;
}
