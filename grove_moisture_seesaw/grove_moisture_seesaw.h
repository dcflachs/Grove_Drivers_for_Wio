/*
 * grove_moisture_seesaw.h
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


#ifndef __GROVE_MOISTURE_SEESAW_H__
#define __GROVE_MOISTURE_SEESAW_H__

#include "suli2.h"
#include "Adafruit_seesaw.h"


//GROVE_NAME        "Adafruit Seesaw Soil Moisture"
//SKU               b7182ab6-834b-4050-9565-3862c5bcac11
//IF_TYPE           I2C
//IMAGE_URL         https://cdn-learn.adafruit.com/assets/assets/000/065/920/small240/adafruit_products_4026_iso_ORIG_2018_18.jpg?1542235885
//DESCRIPTION       "The ENV II is an environment sensor which can sense temperature, humidity and atmospheric pressure. It is built with SHT30 and BMP280 sensors and is programmed over I2C."
//WIKI_URL          https://learn.adafruit.com/adafruit-stemma-soil-sensor-i2c-capacitive-moisture-sensor
//ADDED_AT          "2020-07-11"
//AUTHOR            "dcflachs"


class GroveMoistureSeesaw
{
public:
    GroveMoistureSeesaw(int pinsda, int pinscl);

    /**
     * Read temperature
     *
     * @param temperature - unit: Celsius degree
     *
     * @return bool
     */
    bool read_temperature(float *temperature);

    /**
     *
     *
     * @param moisture - range: 200 (dry) - 2000 (wet)
     *
     * @return bool
     */
    bool read_moisture(uint16_t *moisture);

private:
    I2C_T *i2c;
    Adafruit_seesaw * p_dev;
    bool device_init;
};

#endif
