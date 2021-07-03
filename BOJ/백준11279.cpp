//���� 11279 �ִ��� - https://www.acmicpc.net/problem/11279

#include <iostream>

using namespace std;

#define MAX_ELEMENT 100000 // �� �ȿ� ����� ����� ����


typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void insert_max_heap(HeapType* h, int item) {
	int i;
	i = ++(h->heap_size); // �� ũ�⸦ �ϳ� ����

	/* Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ���� */
	// i�� ��Ʈ ��Ʈ(index: 1)�� �ƴϰ�, ������ item�� ���� i�� �θ� ���(index: i/2)���� ũ��
	while ((i != 1) && (item > h->heap[i / 2])) {
		// i��° ���� �θ� ��带 ��ȯȯ��.
		h->heap[i] = h->heap[i / 2];
		// �� ���� ���� �ö�ܴ�.
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
}

int delete_max_heap(HeapType* h) {
	int parent, child;
	int item, temp;

	item = h->heap[1]; // ��Ʈ ��� ���� ��ȯ�ϱ� ���� item�� �Ҵ�
	temp = h->heap[(h->heap_size)--]; // ������ ��带 temp�� �Ҵ��ϰ� �� ũ�⸦ �ϳ� ����
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// ���� ����� �ڽ� ��� �� �� ū �ڽ� ��带 ã�´�. (��Ʈ ����� ���� �ڽ� ���(index: 2)���� �� ����)
		if ((child < h->heap_size) && ((h->heap[child]) < h->heap[child + 1])) {
			child++;
		}
		// �� ū �ڽ� ��庸�� ������ ��尡 ũ��, while�� ����
		if (temp >= h->heap[child]) {
			break;
		}

		// �� ū �ڽ� ��庸�� ������ ��尡 ������, �θ� ���� �� ū �ڽ� ��带 ��ȯ
		h->heap[parent] = h->heap[child];
		// �� �ܰ� �Ʒ��� �̵�
		parent = child;
		child *= 2;
	}

	// ������ ��带 �籸���� ��ġ�� ����
	h->heap[parent] = temp;
	// �ִ�(��Ʈ ��� ��)�� ��ȯ
	return item;
}


//class heap_sw {
//	public:
//	int heap_count;
//	int* heap;
//
//	heap_sw(int size) {
//		heap = new int[size];
//		heap_count = 0;
//	}
//
//	void swap(int* a, int* b);
//	void push(int data);
//	int pop();
//};
//
//void heap_sw::swap(int* a, int* b) {
//	int tmp = *a; 
//	*a = *b; 
//	*b = tmp;
//}
//
//void heap_sw::push(int data) {
//	heap[++heap_count] = data;
//
//	int child = heap_count;
//	int parent = child / 2;
//	while (child > 1 && heap[parent] < heap[child]) {
//		swap(&heap[parent], &heap[child]);
//		child = parent;
//		parent = child / 2;
//	}
//}
//
//int heap_sw::pop() {
//
//	int result = heap[1];
//
//	swap(&heap[1], &heap[heap_count]);
//	heap_count--;
//
//	int parent = 1;
//	int child = parent * 2;
//	if (child + 1 <= heap_count) {
//		child = (heap[child] > heap[child + 1]) ? child : child + 1;
//	}
//
//	while (child <= heap_count && heap[parent] < heap[child]) {
//		swap(&heap[parent], &heap[child]);
//
//		parent = child;
//		child = child * 2;
//		if (child + 1 <= heap_count) {
//			child = (heap[child] > heap[child + 1]) ? child : child + 1;
//		}
//	}
//
//	return result;
//}

int main() {
	int cnt;
	cin >> cnt;
	ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);

	HeapType hip;
	hip.heap_size = 0;
	int tmp;
	for (int i = 0; i < cnt; i++) {
		cin >> tmp;
		if (tmp == 0) {
			if (hip.heap_size) {
				printf("%d\n",delete_max_heap(&hip));
			}
			else {
				printf("0\n");
			}
		}
		else {
			insert_max_heap(&hip, tmp);
		}
	}


	/*int tmp;
	for (int i = 0; i < cnt; i++) {
		cin >> tmp;
		switch (tmp)
		{
		case 0:
			switch (hip.heap_size)
			{
			case 0:
				cout << 0 << endl;
				break;
			default:
				cout << delete_max_heap(&hip) << endl;
				break;
			}
			break;
		default:
			element t;
			t = tmp;
			insert_max_heap(&hip, t);
			break;
		}
	}*/

	/*int* arr = new int[cnt];
	for (int i = 0; i < cnt; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < cnt; i++) {
		switch (arr[i])
		{
		case 0:
			switch (hip.heap_size)
			{
			case 0:
				cout << 0 << endl;
				break;
			default:
				cout << delete_max_heap(&hip) << endl;
				break;
			}
			break;
		default:
			element t;
			t = arr[i];
			insert_max_heap(&hip, t);
			break;
		}
	}*/
}