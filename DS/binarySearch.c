typedef int ElementType;
typedef struct Node* List;
struct Node {
	int size;
	int length;
	ElementType data[10];
};




int binarySearch(int a[], int k) {
	int left, right, not_found = -1;
	left = 1;
	right = 10;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] > k)
			right = mid - 1;
		else if (a[mid] < k)
			left = mid + 1;
		else
			return mid;
	}
	return not_found;
}