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
#include <CutterCommandFactory.h>

//makes everything a bit shorter
namespace po = boost::program_options;




std::unique_ptr<CutterCommand> parse_arguments(int argc, char* argv[]){
    try
    {
        // Declare the supported options.
        po::options_description desc("Small tool to control a cleware USB-Cutter device \n"
                                     "It is only allowed to pass one option \nAllowed options:");
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

        auto cmd = CutterCommandFactory::create_cutter_command(vm);

        //If we get a valid command return it else print help and fail
        if (cmd != nullptr){
            return cmd;
        }

        std::cout << desc << "\n";
        exit(0);
    }
    catch(std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        exit(1);
    }
    catch(...) {
        std::cerr << "Exception of unknown type!\n";
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    
    auto cmd = parse_arguments(argc, argv);

    auto ret = cmd->execute();

    if (ret != 0){
        std::cerr << "Could not execute command on all devices." << std::endl;
        return 2;
    }
	return 0;
}
	