

#include <ucdm/descriptor.h>


const descriptor_vendor_t descriptor_vendor = {
    .name = APP_DESCRIPTOR_VENDOR_NAME,
    .url = APP_DESCRIPTOR_VENDOR_URL
};

const descriptor_hardware_t descriptor_hardware = {
    .name = APP_DESCRIPTOR_HARDWARE_NAME,
    .revision = APP_DESCRIPTOR_HARDWARE_REVISION,
    .variant = APP_DESCRIPTOR_HARDWARE_VARIANT
};

const descriptor_firmware_t descriptor_firmware = {
    .name = APP_DESCRIPTOR_FIRMWARE_NAME,
    .revision = APP_DESCRIPTOR_FIRMWARE_REVISION
};
