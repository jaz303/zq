#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER_SIZE 65536
char buffer[BUFFER_SIZE];

void usage(int code) {
    fprintf(stderr, "Usage: zq socket\n");
    exit(code);
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        usage(1);
    }

    void *ctx = zmq_ctx_new();
    void *publisher = zmq_socket(ctx, ZMQ_PUSH);
    
    int rc = zmq_connect(publisher, argv[1]);
    assert(rc == 0);

    while (!feof(stdin)) {
        if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
            zmq_send(publisher, buffer, strlen(buffer), 0);
        }
    }

    zmq_ctx_destroy(ctx);

    return 0;

}