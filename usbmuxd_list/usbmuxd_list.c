#include <stdio.h>
#include <usbmuxd.h>
#include <string.h>

int main() {
    usbmuxd_device_info_t* device_info;
    int device_count = usbmuxd_get_device_list(&device_info);
    printf("Found %d devices:\n", device_count);
    int i = 0;
    for(i = 0; device_info[i].handle > 0; i++) {
        printf("%s\n", device_info[i].udid);
    }
    usbmuxd_device_list_free(&device_info);
    return 0;
}