#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem {
    long long value;
    long long priority;
};

struct PriorityQueue {
    struct Elem *arr;
    long long sizeMax;
    long long size;
    long long ElementNumber;
};

struct Elem Init(long long value);
void swap(struct Elem *a, struct Elem *b);
long long siftDown(struct Elem *arr, long long size, long long i);
void sift_up(struct Elem *arr, long long size, long long i);
struct PriorityQueue PriorityQueueInit(long long sizeMax);
void PriorityQueuePush(struct PriorityQueue *queue, struct Elem value);
void PriorityQueuePop(struct PriorityQueue *queue);
long long PriorityQueueSize(struct PriorityQueue *queue);

int main() {
    long long n;
    scanf("%lld", &n);
    struct PriorityQueue units = PriorityQueueInit(n);
    for (long long i = 0; i < n; i++)
        PriorityQueuePush(&units, Init(0));
    long long k;
    scanf("%lld", &k);
    long long timeMax = 0;
    for (long long i = 0; i < k; i++) {
        long long start, working;
        scanf("%lld %lld", &start, &working);
        long long time = units.arr[0].value;
        PriorityQueuePop(&units);
        if (time < start)
            time = start;
        time += working;
        if (timeMax < time)
            timeMax = time;
        PriorityQueuePush(&units, Init(time));
    }
    printf("%lld", timeMax);
    free(units.arr);
}

struct Elem Init(long long value) {
    struct Elem elem;
    elem.value = value;
    elem.priority = -value;
    return elem;
}

void swap(struct Elem *a, struct Elem *b) {
    struct Elem c = *a;
    *a = *b;
    *b = c;
}

long long siftDown(struct Elem *arr, long long size, long long i) {
    long long sizeMax = 0;
    while (i < size / 2) {
        long long left = i * 2 + 1;
        long long right = left + 1;
        long long j = left;
        if (right < size && arr[right].priority > arr[left].priority)
            j = right;
        if (arr[i].priority >= arr[j].priority)
            return sizeMax;
        swap(&arr[i], &arr[j]);
        i = j;
        sizeMax = i;
    }
    return sizeMax;
}

void sift_up(struct Elem *arr, long long size, long long i) {
    while (i > 0 && arr[i].priority > arr[(i - 1) / 2].priority) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct PriorityQueue PriorityQueueInit(long long sizeMax) {
    struct PriorityQueue queue;
    queue.sizeMax = sizeMax;
    queue.size = 0;
    queue.ElementNumber = 0;
    queue.arr = malloc(sizeof(struct Elem) * sizeMax);
    for (long long i = 0; i < sizeMax; i++) {
        queue.arr[i] = Init(0);
        queue.arr[i].priority = -1000000000;
    }
    return queue;
}

void PriorityQueuePush(struct PriorityQueue *queue, struct Elem value) {
    (*queue).arr[(*queue).size++] = value;
    sift_up((*queue).arr, (*queue).sizeMax, (*queue).size - 1);
    (*queue).ElementNumber++;
}

void PriorityQueuePop(struct PriorityQueue *queue) {
    (*queue).arr[0].priority = -1000000000;
    (*queue).size = siftDown((*queue).arr, (*queue).sizeMax, 0);
    (*queue).ElementNumber--;
}

long long PriorityQueueSize(struct PriorityQueue *queue) {
    return (*queue).ElementNumber;
}