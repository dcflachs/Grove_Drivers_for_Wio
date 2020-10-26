/*
 * grove_m5unit_ir_remote.cpp
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

#include "suli2.h"
#include "grove_m5unit_ir_remote.h"

GroveM5UnitIR::GroveM5UnitIR(int pinrx, int pintx)
{
    this->p_dev_rx = (GroveIRRecv *)malloc(sizeof(GroveIRRecv));
    this->p_dev_rx = new GroveIRRecv(pinrx);

    this->p_dev_tx = (GroveIREmit *)malloc(sizeof(GroveIREmit));
    this->p_dev_tx = new GroveIREmit(pintx);
}


bool GroveM5UnitIR::write_data_hex(char *data_hex)
{
	return this->p_dev_tx->write_data_hex(data_hex);
}

bool GroveM5UnitIR::write_data_hex_in_freq(uint16_t freq_khz, char *data_hex)
{
	return this->p_dev_tx->write_data_hex_in_freq(freq_khz, data_hex);
}

bool GroveM5UnitIR::write_protocol_parameters(uint8_t start_h, uint8_t start_l, uint8_t n_short, uint8_t n_long)
{
	return this->p_dev_tx->write_protocol_parameters(start_h, start_l, n_short, n_long);
}

bool GroveM5UnitIR::read_tx_protocol_parameters(uint8_t *start_h, uint8_t *start_l, uint8_t *n_short, uint8_t *n_long)
{
	return this->p_dev_tx->read_protocal_parameters(start_h, start_l, n_short, n_long);
}

bool GroveM5UnitIR::read_rx_protocol_parameters(uint8_t *start_h, uint8_t *start_l, uint8_t *n_short, uint8_t *n_long)
{
	return this->p_dev_rx->read_protocol_parameters(start_h, start_l, n_short, n_long);
}

char * GroveM5UnitIR::get_last_error()
{
	return this->p_dev_tx->get_last_error();
}

bool GroveM5UnitIR::read_last_data_recved(uint16_t *len, char **data)
{
	return this->p_dev_rx->read_last_data_recved(len, data);
}