#include <usbmuxd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#define SIGINT 2

int shouldQuit = 0;

int start_usbmuxd_monitor();
int stop_usbmuxd_monitor();
void interrupt_handler(int sig);

int main(int argc, char** argv) {
    signal(SIGINT, interrupt_handler);
    if(start_usbmuxd_monitor() != 0) {
        return -1;
    }
    while(shouldQuit < 1) { sleep(100); }
    stop_usbmuxd_monitor();
    return 0;
}

void _usbmuxd_monitor_cb(const usbmuxd_event_t *event, void *user_data) {
    enum usbmuxd_event_type event_type = event->event;
    switch(event_type) {
        case UE_DEVICE_ADD:
            printf("%s (%d) was added\n", event->device.udid, event->device.product_id);
            break;
        case UE_DEVICE_REMOVE:
            printf("%s (%d) was removed\n", event->device.udid, event->device.product_id);
            break;
        case UE_DEVICE_PAIRED:
            printf("%s (%d) was paired\n", event->device.udid, event->device.product_id);
            break;
        default:
            printf("No event happened\n");
            break;
    }
}

int start_usbmuxd_monitor() {
    printf("Started usbmuxd_monitor\n");
    return usbmuxd_subscribe(&_usbmuxd_monitor_cb, NULL);
}

int stop_usbmuxd_monitor() {
    printf("Stopped usbmuxd_monitor\n");
    return usbmuxd_unsubscribe();
}

void interrupt_handler(int sig) {
    if(sig == 2) {
        shouldQuit = 1;
    }
}