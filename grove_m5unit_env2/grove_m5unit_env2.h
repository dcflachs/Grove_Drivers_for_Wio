/*
 * grove_m5unit_env2.h
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


#ifndef __GROVE_M5UNIT_ENV2_H__
#define __GROVE_M5UNIT_ENV2_H__

#include "suli2.h"
#include "grove_baro_bmp280.h"
#include "grove_temp_humi_sht31.h"

//GROVE_NAME        "M5UnitENVII (BMP280 + SHT30)"
//SKU               8e56e2c6-f92b-40a2-ba95-7d472581fc31
//IF_TYPE           I2C
//IMAGE_URL         https://cdn.shopify.com/s/files/1/0056/7689/2250/products/1_3dad71c4-dc87-4e30-9f02-b5bf8e69f8bc_1200x1200.jpg
//DESCRIPTION       "The ENV II is an environment sensor which can sense temperature, humidity and atmospheric pressure. It is built with SHT30 and BMP280 sensors and is programmed over I2C."
//WIKI_URL          https://docs.m5stack.com/#/en/unit/envII
//ADDED_AT          "2020-06-28"
//AUTHOR            "dcflachs"


class GroveM5UnitENV2
{
public:
    GroveM5UnitENV2(int pinsda, int pinscl);

    /**
     * Read a rough temperature value of the envirenment
     *
     * @param temperature - unit: Celsius degree
     *
     * @return bool
     */
    bool read_temperature_barom(float *temperature);

    /**
     *
     *
     * @param pressure - unit: Pa
     *
     * @return bool
     */
    bool read_pressure(int32_t *pressure);

    /**
     *
     *
     * @param altitude - the absolute altitude, unit: m
     *
     * @return bool
     */
    bool read_altitude(float *altitude);

    /**
     * Read the temperature value of the envirenment
     *
     * @param temperature - unit: Celsius degree
     *
     * @return bool
     */
    bool read_temperature_humid(float *temperature);

    /**
     *
     *
     * @param humidity - unit: %
     *
     * @return bool
     */
    bool read_humidity(float *humidity);

    /**
     *
     *
     * @param onoff - 1: on, 0: off
     *
     * @return bool
     */
    bool write_heater_onoff(int onoff);

private:
    GroveBaroBMP280    * p_dev_bmp;
    GroveTempHumiSHT31 * p_dev_sht;
};

#endif
