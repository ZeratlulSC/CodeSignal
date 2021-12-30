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
int middle_box3 (int *arr1, int *arr2, int *arr3);
int width_arr(arr_arr_integer arr);
int height_arr(arr_arr_integer arr);
void fill_this_shit_with_that(arr_arr_integer arr, arr_arr_integer arr_to_fill);

arr_arr_integer solution(arr_arr_integer image) {
    //printf("%d", middle_box3(image.arr[0].arr+1, image.arr[1].arr+1, image.arr[2].arr+1));
    //printf("\nwidth = %d\nheight = %d\n\n", width_arr(image), height_arr(image));
    arr_arr_integer ret = alloc_arr_arr_integer(height_arr(image));
    for (int i = 0; i < ret.size; i++){
        ret.arr[i] = alloc_arr_integer(width_arr(image));
    }
    fill_this_shit_with_that(image, ret);
    //printf("%d", ret.arr[0].arr[0]);
    return ret;
}

int middle_box3 (int *arr1, int *arr2, int *arr3){
    return (arr1[0] + arr1[1] + arr1[2] + arr2[0] + arr2[1] + arr2[2] + arr3[0] + arr3[1] + arr3[2])/9;
}
int width_arr(arr_arr_integer arr){
    return arr.arr[0].size - 2;
}
int height_arr(arr_arr_integer arr){
    return arr.size - 2;
}
void fill_this_shit_with_that(arr_arr_integer arr, arr_arr_integer arr_to_fill){
    for (int i = 0; i < height_arr(arr); i++){
        for (int j = 0; j < width_arr(arr); j++){
            arr_to_fill.arr[i].arr[j] = middle_box3(arr.arr[i].arr+j, arr.arr[i+1].arr+j, arr.arr[i+2].arr+j);
        }
    }
}
