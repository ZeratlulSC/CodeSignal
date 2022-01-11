bool solution(char * string1, char * string2) {
    //for (int i = 0; i < strlen(string1); i++) printf("%d ", string1[i] - string2[i]);
    int *alphabet = (int*) malloc (26*sizeof(int));
    for (int i = 0; i < 26; i++) alphabet[i] = -1;
    for (int i = 97; i < 123; i++){
        for (int j = 0; j < strlen(string1); j++){
            if (string1[j] == i){
                alphabet[i-97] = string2[j]-97;
                break;
            }
        }
    }  
    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 26; j++){
            if (alphabet[i] == alphabet[j] && alphabet[i] != -1){
                return false;
            }
        }
    }
    for (int i = 0; i < strlen(string1); i++){
        string1[i] = alphabet[string1[i]-97]+97;
    }
    int sum = 0;
    for (int i = 0; i < strlen(string1); i++) sum = sum + string1[i] - string2[i];
    if (sum !=0) return false;
    return true;
}
