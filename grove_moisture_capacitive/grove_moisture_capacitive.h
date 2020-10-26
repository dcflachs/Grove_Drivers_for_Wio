/*
 * grove_moisture_capacitive.h
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

#ifndef __GROVE_MOISTURE_CAPACITIVE_CLASS_H__
#define __GROVE_MOISTURE_CAPACITIVE_CLASS_H__

#include "grove_moisture_class.h"

//GROVE_NAME        "Grove-Moisture-Capacitive"
//SKU               101020614
//IF_TYPE           ANALOG
//IMAGE_URL         https://files.seeedstudio.com/wiki/Grove-Capacitive_Moisture_Sensor_Corrosion_Resistant/img/main.jpg
//DESCRIPTION       "The Grove - Moisture Sensor can be used to detect the moisture of soil, to judge if there is dampness around the sensor. It can be used to decide if the plants in a garden needs watering. It can be used in gardens to automate watering plants. It can be used very easily by just inserting the sensor into the soil and reading the output using ADC."
//WIKI_URL          https://wiki.seeedstudio.com/Grove-Capacitive_Moisture_Sensor-Corrosion-Resistant/
//ADDED_AT          "2020-10-25"
//AUTHOR            "dcflachs"

class GroveMoistureCapacitive : public GroveMoisture
{
public:
    GroveMoistureCapacitive(int pin);

    /**
     *
     *
     * @param moisture - analog value, range: 0~1023
     *
     * @return bool
     */
    bool read_moisture(uint16_t *moisture);
}

#endif