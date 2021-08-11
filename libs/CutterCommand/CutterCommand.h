// MIT License

// Copyright (c) 2021 Markus Swarowsky

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __CUTTERCOMMAND_H__
#define __CUTTERCOMMAND_H__

// needed for the USBaccess.h libary :(
#include <unistd.h>
#include <USBaccess.h>

#define CUTTER_ON 0
#define CUTTER_OFF 1

class CutterCommand
{
    public:
    /**
     * @brief This executes the command on a given device 
     * 
     * @return int zero on success
     */
    virtual int execute() = 0;

    protected:
    /**
     * @brief Set the cutter to the given state 
     * 
     * @param usb Instance of the USBaccess libary used to access the devices
     * @param device_id The device id of the connected cutters starting from 0
     * @param state The state the cutter will be set to
     * @return int zero on success
     */
    int set_cutter_state(CUSBaccess &usb, int device_id, int state);
};

#endif //__CUTTERCOMMAND_H__
