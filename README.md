# zq

Just a little command-line utility I'm writing to get the hang of ZMQ.

## Example

Pipe `foo` through a ZMQ `PUSH` -> `PULL` pipepline:

    $ cat foo | zq tcp://localhost:2212