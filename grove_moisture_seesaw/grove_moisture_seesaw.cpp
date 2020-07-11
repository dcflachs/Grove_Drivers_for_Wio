/*
 * grove_moisture_seesaw.cpp
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
#include "Adafruit_seesaw.h"
#include "grove_moisture_seesaw.h"

GroveMoistureSeesaw::GroveMoistureSeesaw(int pinsda, int pinscl)
{
    this->i2c = (I2C_T *)malloc(sizeof(I2C_T));
    suli_i2c_init(i2c, pinsda, pinscl);

    this->p_dev = (Adafruit_seesaw *)malloc(sizeof(Adafruit_seesaw));
    *this->p_dev = new Adafruit_seesaw(this->i2c);

    this->device_init = this->p_dev->begin(0x36);
}

bool GroveMoistureSeesaw::read_temperature(float *temperature)
{
	if(this->device_init)
    	*temperature = this->p_dev->getTemp();

    return this.device_init;
}

bool GroveMoistureSeesaw::read_moisture(uint16_t *moisture)
{
	if(this->device_init)
    	*moisture = this->p_dev->touchRead(0);
    
    return this.device_init;
}