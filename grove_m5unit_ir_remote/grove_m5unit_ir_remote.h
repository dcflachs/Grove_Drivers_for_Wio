/*
 * grove_m5unit_ir_remote.h
 *
 * Author     : dcflachs
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#ifndef __GROVE_M5UNIT_IR_REMOTE_H__
#define __GROVE_M5UNIT_IR_REMOTE_H__

#include "suli2.h"
#include "grove_ir_emitter.h"
#include "grove_ir_receiver.h"

//GROVE_NAME        "M5Unit IR Remote"
//SKU               bdd37ad5-7311-4138-af7d-d76865dcd6e4
//IF_TYPE           GPIO
//IMAGE_URL         https://cdn.shopify.com/s/files/1/0056/7689/2250/products/IR_1200x1200.jpg
//DESCRIPTION       "M5Unit IR Remote is an pair of 1 infrared emitter and 1 infrared receiver."
//WIKI_URL          https://docs.m5stack.com/#/en/unit/ir
//ADDED_AT          "2020-07-12"
//AUTHOR            "dcflachs"

class GroveM5UnitIR
{
public:
	GroveM5UnitIR(int pinrx, int pintx);

    /**
     * Send a sequence of data with the emitter, using frequency 38KHz.
     *
     * @param data_hex - a string in hex format, e.g. FFBBCC0011
     *
     * @return bool
     */
    bool write_data_hex(char *data_hex);

    /**
     * Send a sequence of data with the emitter, using a specified frequency.
     *
     * @param freq_khz - the frequency of the IR carrier wave, unit KHz.
     * @param data_hex - a string in hex format, e.g. FFBBCC0011
     *
     * @return bool
     */
    bool write_data_hex_in_freq(uint16_t freq_khz, char *data_hex);

    /**
     * Set the protocol parameters. Please don't modify this only if you know what it is.
     *
     * @param start_h - the length of start high signal
     * @param start_l - the length of start low signal
     * @param n_short - the length of short signal
     * @param n_long - the length of long signal
     *
     * @return bool
     */
    bool write_protocol_parameters(uint8_t start_h, uint8_t start_l, uint8_t n_short, uint8_t n_long);

    char *get_last_error();

    /**
     * Read the last IR data received. The data will be cleared after this read.
     *
     * @param len - the number of bytes
     * @param data - a string in hex format, e.g. FFBBCC0011
     *
     * @return bool
     */
    bool read_last_data_recved(uint16_t *len, char **data);

    /**
     * Read the parameters of the IR protocol(NEC).
     *
     * @param start_h - the length of start high signal
     * @param start_l - the length of start low signal
     * @param n_short - the length of short signal
     * @param n_long - the length of long signal
     *
     * @return bool
     */
    bool read_tx_protocol_parameters(uint8_t *start_h, uint8_t *start_l, uint8_t *n_short, uint8_t *n_long);
	bool read_rx_protocol_parameters(uint8_t *start_h, uint8_t *start_l, uint8_t *n_short, uint8_t *n_long);
	
	/**
     * An event which indicates the length of data IR Receiver has received.
     */
    DEFINE_EVENT(ir_recv_data_len, SULI_EDT_UINT8);

    /**
     * An event which reports the data sequence IR Receiver has received, in HEX string.
     */
    DEFINE_EVENT(ir_recv_data_hex, SULI_EDT_STRING);

private:
	GroveIRRecv 	* p_dev_rx;
	GroveIREmit 	* p_dev_tx;
};

#endif