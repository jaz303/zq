#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#define BUFFER_SIZE 65536
char buffer[BUFFER_SIZE];

int main(void) {
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_PULL);
    int rc = zmq_bind(subscriber, "tcp://127.0.0.1:5555");
    assert(rc == 0);

    while (1) {
        int read = zmq_recv(subscriber, buffer, BUFFER_SIZE, 0);
        
        if (read < 0) {
            fprintf(stderr, "read error: %d\n", errno);
            continue;
        }

        if (read >= BUFFER_SIZE) {
            read = BUFFER_SIZE - 1;
        }

        buffer[read] = '\0';

        printf("%s", buffer);
    }

    zmq_ctx_destroy(context);

    return 0;
}