
void qsort(int *array, int len){
    _qsort(array, 0, len - 1);
}

void _qsort(int *array, int lo, int hi){

    int pivot;

    if( hi > lo ){
        pivot = partition(array, lo, hi);
        _qsort(array, lo, pivot -1);
        _qsort(array, pivot + 1, hi);
    }
}

int partition(int *array, int low, int high){
    int pivot = array[high];
    int i = low - 1;
    int j = low;

    for(int j = low; j <= high - 1; j++){
        if(array[j] < pivot){
            i++;
            swap(array, i, j);
        }
    }

    swap(array, i + 1, high);

    return i +1;
}

void swap(int *array, int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void printArray(int *array){
     for(int i =0; i< 9; i++){
        printf("%d,", array[i]);
    }
       printf("\n");
}
