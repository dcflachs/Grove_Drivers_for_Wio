/*
 * grove_m5unit_env2.cpp
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
#include "grove_m5unit_env2.h"

GroveM5UnitENV2::GroveM5UnitENV2(int pinsda, int pinscl)
{
    this->p_dev_bmp = (GroveBaroBMP280 *)malloc(sizeof(GroveBaroBMP280));
    this->p_dev_bmp = new GroveBaroBMP280(pinsda, pinscl, BMP280_ALT_ADDRESS);

    this->p_dev_sht = (GroveTempHumiSHT31 *)malloc(sizeof(GroveTempHumiSHT31));
    this->p_dev_sht = new GroveTempHumiSHT31(pinsda, pinscl);
}

bool GroveM5UnitENV2::read_temperature_barom(float *temperature)
{
    return this->p_dev_bmp->read_temperature(temperature);
}

bool GroveM5UnitENV2::read_pressure(int32_t *pressure)
{
    return this->p_dev_bmp->read_pressure(pressure);
}

bool GroveM5UnitENV2::read_altitude(float *altitude)
{
    return this->p_dev_bmp->read_altitude(altitude);
}

bool GroveM5UnitENV2::read_temperature_humid(float *temperature)
{
    return this->p_dev_sht->read_temperature(temperature);
}

bool GroveM5UnitENV2::read_humidity(float *humidity)
{
    return this->p_dev_sht->read_humidity(humidity);
}

bool GroveM5UnitENV2::write_heater_onoff(int onoff)
{
    return this->p_dev_sht->write_heater_onoff(onoff);
}
