/*
 * usb_audio --- USB audio output
 *
 * Copyright (C) 2019 Kiffie
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#ifndef __USB_AUDIO_H__
#define __USB_AUDIO_H__

#include <usb.h>

#define ID_INPUT_TERMINAL  0x01
#define ID_OUTPUT_TERMINAL 0x03
#define ID_MIXER_UNIT      0x05
#define ID_SELECTOR_UNIT   0x04
#define ID_FEATURE_UNIT    0x02
#define ID_PROCESSING_UNIT 0x06
#define ID_EXTENSION_UNIT  0x07

#define PCM_FSAMPLE_MAX 96000
#define PCM_CHANNELS 2
#define PCM_SUBFRAMESIZE 3
#define USB_AUDIO_ISO_EP_SIZE (PCM_SUBFRAMESIZE*PCM_FSAMPLE_MAX*PCM_CHANNELS/1000)


typedef void (*usb_audio_data_cb_t)(uint8_t ep_addr, void *data, unsigned len);


void usb_audio_init();
int usb_audio_class_handler(usb9_setup_data_t *sudata, void **inout_data);

/* returns true on success */
bool usb_audio_set_callback(uint8_t ep_addr, usb_audio_data_cb_t callback);

static inline void usb_audio_shutdown(void){
    usb_shutdown();
}

#endif
