#include <stdio.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int head = 0;
int count = 0;

void insert(int value) {
    buffer[head] = value;
    head = (head + 1) % BUFFER_SIZE;
    if (count < BUFFER_SIZE)
        count++;
}

void printBuffer() {
    int index;
    printf("Buffer contents (oldest to newest): ");
    for (int i = 0; i < count; i++) {
        index = (head + i) % BUFFER_SIZE;
        printf("%d ", buffer[index]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(12);
    insert(14);
    insert(15);
    insert(13);
    insert(18);
    insert(20);

    printBuffer();

    return 0;
}
