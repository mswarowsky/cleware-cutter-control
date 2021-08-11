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


#include <boost/program_options.hpp>
#include "CutterCommand.h"


/**
 * @brief Small factory class to creates commands pases on the program 
 * arguments map created by boots
 * 
 */
class CutterCommandFactory
{    
public:
    /**
     * @brief This creates a derived CutterCommand object according the the 
     * given variable map. 
     * 
     * This checks for the arguments: on, off, toggle, reset <arg>
     * If variables contains one of the arguments return a ptr to the 
     * corressponding CutterCommand else nullptr.
     * 
     * @return Pointer to CutterCommand object or nullptr
     * 
     */
    static std::unique_ptr<CutterCommand> create_cutter_command(
        boost::program_options::variables_map &variables);
};
