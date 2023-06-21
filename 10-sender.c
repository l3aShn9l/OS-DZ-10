#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void send_bit(int receiver_pid, int bit) {
    if (bit == 0) {
        kill(receiver_pid, SIGUSR1);
    } else {
        kill(receiver_pid, SIGUSR2);
    }
    usleep(100000);
}

int main() {
    int receiver_pid, number;

    printf("Sender PID: %d\n", getpid());
    printf("Enter the receiver PID: ");
    scanf("%d", &receiver_pid);

    printf("Enter the number to send: ");
    scanf("%d", &number);

    for (int i = 0; i < 32; ++i) {
        send_bit(receiver_pid, (number >> i) & 1);
    }

    return 0;
}
