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
void logic(arr_arr_integer integer, arr_arr_boolean boolean);

arr_arr_integer solution(arr_arr_boolean matrix) {
    arr_arr_integer ret = alloc_arr_arr_integer(matrix.size);
    for (int i = 0; i < matrix.size; i++) ret.arr[i] = alloc_arr_integer(matrix.arr[0].size);
    logic(ret, matrix);
    return ret;
}

void logic(arr_arr_integer integer, arr_arr_boolean boolean){
    //обходим квадрат внутри квадрата без границы
    for (int i = 1; i < boolean.size-1; i++){
        for (int j = 1; j < boolean.arr[0].size-1; j++){
            if (boolean.arr[i].arr[j] == true) {
                integer.arr[i-1].arr[j-1]++;
                integer.arr[i-1].arr[j]++;
                integer.arr[i-1].arr[j+1]++;
                integer.arr[i].arr[j-1]++;
                integer.arr[i].arr[j+1]++;
                integer.arr[i+1].arr[j-1]++;
                integer.arr[i+1].arr[j]++;
                integer.arr[i+1].arr[j+1]++; 
            }
        }
    }
    //обходим верхнюю границу без граничных точек
    for (int i = 1; i < boolean.arr[0].size-1; i++){
        if (boolean.arr[0].arr[i] == true){
            integer.arr[0].arr[i+1]++;
            integer.arr[0].arr[i-1]++;
            integer.arr[1].arr[i-1]++;
            integer.arr[1].arr[i]++;
            integer.arr[1].arr[i+1]++;
        }
    }
    //обходим нижнюю границу без граничных точек 
    for (int i = 1; i < boolean.arr[0].size-1; i++){
        if (boolean.arr[boolean.size-1].arr[i] == true){
            integer.arr[boolean.size-1].arr[i+1]++;
            integer.arr[boolean.size-1].arr[i-1]++;
            integer.arr[boolean.size-2].arr[i-1]++;
            integer.arr[boolean.size-2].arr[i]++;
            integer.arr[boolean.size-2].arr[i+1]++;
        }
    }
    //обходим левую границу без граничных точек
    for (int i = 1; i < boolean.size-1; i++){
        if (boolean.arr[i].arr[0] == true){
            integer.arr[i-1].arr[0]++;
            integer.arr[i+1].arr[0]++;
            integer.arr[i].arr[1]++;
            integer.arr[i-1].arr[1]++;
            integer.arr[i+1].arr[1]++;
        }
    }
    //обходим правую границу без граничных точек
    for (int i = 1; i < boolean.size-1; i++){
        if (boolean.arr[i].arr[boolean.arr[0].size-1] == true){
            integer.arr[i].arr[boolean.arr[0].size-2]++;
            integer.arr[i-1].arr[boolean.arr[0].size-1]++;
            integer.arr[i+1].arr[boolean.arr[0].size-1]++;
            integer.arr[i-1].arr[boolean.arr[0].size-2]++;
            integer.arr[i+1].arr[boolean.arr[0].size-2]++;
        }
    }
    //угол левый верх
    if (boolean.arr[0].arr[0] == true){
        integer.arr[0].arr[1]++;
        integer.arr[1].arr[1]++;
        integer.arr[1].arr[0]++;
    }
    //угол левый низ
    if (boolean.arr[boolean.size-1].arr[0] == true){
        integer.arr[boolean.size-1].arr[1]++;
        integer.arr[boolean.size-2].arr[0]++;
        integer.arr[boolean.size-2].arr[1]++;
    }
    //угол правый верх
    if (boolean.arr[0].arr[boolean.arr[0].size-1] == true){
        integer.arr[0].arr[boolean.arr[0].size-2]++;
        integer.arr[1].arr[boolean.arr[0].size-1]++;
        integer.arr[1].arr[boolean.arr[0].size-2]++;
    }
    //угол правый низ
    if (boolean.arr[boolean.size-1].arr[boolean.arr[0].size-1] == true){
        integer.arr[boolean.size-2].arr[boolean.arr[0].size-1]++;
        integer.arr[boolean.size-1].arr[boolean.arr[0].size-2]++;
        integer.arr[boolean.size-2].arr[boolean.arr[0].size-2]++;
    }
}
