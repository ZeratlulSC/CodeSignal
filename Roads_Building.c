// Arrays are already defined with this interface:
// typedef struct arr_##name {
//   int size;
//   type *arr;
// } arr_##name;
//
// arr_##name alloc_arr_##name(int len) {
//   arr_##name a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
//   return a;
// }
//
//
int nmbr_of_roads (int a);
char **  hash_create (char ** hash, int cities);
void hash_fullfill (char**hash, arr_arr_integer roads);
void ret_fullfill (char **hash, arr_arr_integer ret, int cities);

arr_arr_integer solution(int cities, arr_arr_integer roads) {
    char **hash;
    int all_roads = nmbr_of_roads(cities);
    arr_arr_integer ret = alloc_arr_arr_integer(all_roads - roads.size);
    for (int i = 0; i < ret.size; i++) ret.arr[i] = alloc_arr_integer(2);
    hash = hash_create(hash, cities);
    hash_fullfill(hash, roads);
    ret_fullfill(hash, ret, cities);
    /*for (int i = 0; i < cities; i++){
        for (int j = 0; j < cities; j++){
            printf("%d ", hash[i][j]);
        }
        printf("\n");
    }*/
    return ret;
}

int nmbr_of_roads (int a){
    return a*(a-1)/2;
}

char **  hash_create (char ** hash, int cities){
    hash = (char**) malloc(cities*cities);
    for (int i = 0; i<cities; i++){
        hash[i] = (char*) malloc(cities);
    }
    return hash;
}

void hash_fullfill (char**hash, arr_arr_integer roads){
    for (int i = 0; i < roads.size; i++){
        hash[roads.arr[i].arr[0]][roads.arr[i].arr[1]] = 1;
        hash[roads.arr[i].arr[1]][roads.arr[i].arr[0]] = 1;
    }
}

void ret_fullfill (char **hash, arr_arr_integer ret, int cities){
    int ret_point = 0;
    for (int i = 0; i < cities - 1; i++){
        for (int j = i + 1; j < cities; j++){
            if (hash[i][j] == 0) {
                ret.arr[ret_point].arr[0] = i;
                ret.arr[ret_point++].arr[1] = j; 
            }
        }
    }
}
