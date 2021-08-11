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

#include <iostream>

#include "ToggleCutterCommand.h"
#include <USBaccess.h>



int ToggleCutterCommand::execute(){
    CUSBaccess CWusb;

    int USBcount = CWusb.OpenCleware();
    int ret = 0;
	for (int devID=0 ; devID < USBcount ; devID++) {
		int state;

		// get state
		state = CWusb.GetSwitch(devID, CUSBaccess::SWITCH_0);

		if(state < 0){
			std::cerr << "Read state failed";
            // increase error count
			ret++;
            //got to the next device
            continue; 
		}
		std::cout << "Toggle device " << devID << " from state: " << state << " to state " 
                  << (state^1) << std::endl;

		//toggle state
		state ^= 1;

		//set new state
        ret += set_cutter_state(CWusb, devID, state);
    }

    CWusb.CloseCleware();
    return ret;
}