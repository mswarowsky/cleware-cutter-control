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
#include <boost/program_options.hpp>
#include <CutterCommand.h>
#include <OnCutterCommand.h>
#include <OffCutterCommand.h>
#include <ToggleCutterCommand.h>
#include <ResetCutterCommand.h>

// needed for the USBaccess.h libary :(
#include <unistd.h>
#include <USBaccess.h>


//makes everything a bit shorter
namespace po = boost::program_options;
using namespace std;




unique_ptr<CutterCommand> create_command(int argc, char* argv[]){
    try
    {
        // Declare the supported options.
        po::options_description desc("Small tool to control a cleware USB-Cutter device \n"
                                     "Allowed options:");
        desc.add_options()
            ("help", "Print this text:")
            ("reset", po::value<int>(), "Rest by turning switch off of \"arg\" seconds and then on again")
            ("off", "Turn cutter off")
            ("on", "Turn cutter On")
            ("toggle","Toggles the current device status")
        ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);    

        if (vm.count("help")) {
            std::cout << desc << "\n";
            exit(0);
        }

        if (vm.count("on")) {
            return make_unique<OnCutterCommand>();
        }

        if (vm.count("off")){
            return make_unique<OffCutterCommand>();
        }

        if (vm.count("reset")){
            return make_unique<ResetCutterCommand>(vm["reset"].as<int>());
        }

        if (vm.count("toggle")){
            return make_unique<ToggleCutterCommand>();
        }

        // if we reach here not suitable command was found so just print help and exit
        std::cout << desc << "\n";
        exit(0);
    }
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        exit(1);
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
        exit(1);
    }
}

int main(int argc, char* argv[]) {
	CUSBaccess CWusb ;
    
    auto cmd = create_command(argc, argv);

    auto ret = cmd->execute();

    if (ret != 0){
        std::cerr << "Could not execute command on all devices." << std::endl;
        return 2;
    }
	return 0;
}
	