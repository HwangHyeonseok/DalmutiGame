// 정렬 알고리즘 정의 
// 버블 정렬 : bubble_sort 함수

#pragma region 버블 정렬 : bubble_sort 함수
void bubble_sort(int arr[], int size) { //카드 정렬 함수 - 버블 소트 알고리즘 이용
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
#pragma endregion