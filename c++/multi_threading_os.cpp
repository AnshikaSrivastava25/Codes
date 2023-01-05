#include <pthread.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// This program illustrates the use of Peterson's algorithm to synchronize
// multiple threads.Two new threads are created and alternate writing to the
// standard output.
//
// The key difference between Peterson's algorithm and strict alternation is
// the inclusion of flags indicating whether a thread is ready to enter the
// critical section.
// This function is taken from `http://git.suckless.org/dwm/file/util.c.html`.
//
// Print the error message and `perror` if the message ends in `':'`. Assumes
// `fmt` is not `NULL`.
void die(const char* fmt, ...) {
va_list ap;
va_start(ap, fmt);
vfprintf(stderr, fmt, ap);
va_end(ap);

if(fmt[0] && fmt[strlen(fmt) - 1] == ':') {
fputc(' ', stderr);
perror(NULL);
} else {
fputc('\n', stderr);
}
exit(0);
}

int turn;
int flag[2];
void* f0(void* arg) {
while(1) {
flag[0] = 1;
turn = 1;
while(flag[1] && turn == 1);
puts("hello");
flag[0] = 0;
sleep(1);
}
}
void* f1(void* arg) {
while(1) {
flag[1] = 1;
turn = 0;
while(flag[0] && turn == 0);
puts("world");
flag[1] = 0;
sleep(1);
}
}
int main(void) {
pthread_t t0, t1;
// Creates new threads. The second argument is a pointer to a
// `pthread_attr_t`, if `NULL` the thread is created with default attributes.
// The last argument is the argument that is given to the thread's entry
// point function, unused in this example.
if(pthread_create(&t0, NULL, f0, NULL)) die("unable to create thread");
if(pthread_create(&t1, NULL, f1, NULL)) die("unable to create thread");
while(1);
}
