int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (target < nums[m]) r = m-1;
        else if (target > nums[m]) l = m+1;
        else return m;
    }
    return -1;
}

// Особые случаи:
// -- пустой список
// -- крайние элементы списка
// -- отсутствующий элемент
// -- повторяющиеся элементы
// -- переполнение целого при вычислении среднего индекса
