//백준 11279 최대힙 - https://www.acmicpc.net/problem/11279

#include <iostream>

using namespace std;

#define MAX_ELEMENT 100000 // 힙 안에 저장된 요소의 개수


typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void insert_max_heap(HeapType* h, int item) {
	int i;
	i = ++(h->heap_size); // 힙 크기를 하나 증가

	/* 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정 */
	// i가 루트 노트(index: 1)이 아니고, 삽입할 item의 값이 i의 부모 노드(index: i/2)보다 크면
	while ((i != 1) && (item > h->heap[i / 2])) {
		// i번째 노드와 부모 노드를 교환환다.
		h->heap[i] = h->heap[i / 2];
		// 한 레벨 위로 올라단다.
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입
}

int delete_max_heap(HeapType* h) {
	int parent, child;
	int item, temp;

	item = h->heap[1]; // 루트 노드 값을 반환하기 위해 item에 할당
	temp = h->heap[(h->heap_size)--]; // 마지막 노드를 temp에 할당하고 힙 크기를 하나 감소
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다. (루트 노드의 왼쪽 자식 노드(index: 2)부터 비교 시작)
		if ((child < h->heap_size) && ((h->heap[child]) < h->heap[child + 1])) {
			child++;
		}
		// 더 큰 자식 노드보다 마지막 노드가 크면, while문 중지
		if (temp >= h->heap[child]) {
			break;
		}

		// 더 큰 자식 노드보다 마지막 노드가 작으면, 부모 노드와 더 큰 자식 노드를 교환
		h->heap[parent] = h->heap[child];
		// 한 단계 아래로 이동
		parent = child;
		child *= 2;
	}

	// 마지막 노드를 재구성한 위치에 삽입
	h->heap[parent] = temp;
	// 최댓값(루트 노드 값)을 반환
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