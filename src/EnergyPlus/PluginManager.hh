// EnergyPlus, Copyright (c) 1996-2019, The Board of Trustees of the University of Illinois,
// The Regents of the University of California, through Lawrence Berkeley National Laboratory
// (subject to receipt of any required approvals from the U.S. Dept. of Energy), Oak Ridge
// National Laboratory, managed by UT-Battelle, Alliance for Sustainable Energy, LLC, and other
// contributors. All rights reserved.
//
// NOTICE: This Software was developed under funding from the U.S. Department of Energy and the
// U.S. Government consequently retains certain rights. As such, the U.S. Government has been
// granted for itself and others acting on its behalf a paid-up, nonexclusive, irrevocable,
// worldwide license in the Software to reproduce, distribute copies to the public, prepare
// derivative works, and perform publicly and display publicly, and to permit others to do so.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice, this list of
//     conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// (3) Neither the name of the University of California, Lawrence Berkeley National Laboratory,
//     the University of Illinois, U.S. Dept. of Energy nor the names of its contributors may be
//     used to endorse or promote products derived from this software without specific prior
//     written permission.
//
// (4) Use of EnergyPlus(TM) Name. If Licensee (i) distributes the software in stand-alone form
//     without changes from the version obtained under this License, or (ii) Licensee makes a
//     reference solely to the software portion of its product, Licensee must refer to the
//     software as "EnergyPlus version X" software, where "X" is the version number Licensee
//     obtained under this License and may not use a different name for the software. Except as
//     specifically required in this Section (4), Licensee shall not use in a company name, a
//     product name, in advertising, publicity, or other promotional activities any name, trade
//     name, trademark, logo, or other designation of "EnergyPlus", "E+", "e+" or confusingly
//     similar designation, without the U.S. Department of Energy's prior written consent.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef EPLUS_PLUGINMANAGER_HH
#define EPLUS_PLUGINMANAGER_HH

#include <vector>
#include <EnergyPlus/EnergyPlus.hh>

#ifdef _DEBUG
// We don't want to try to import a debug build of Python here
// so if we are building a Debug build of the C++ code, we need
// to undefine _DEBUG during the #include command for Python.h.
// Otherwise it will fail
#undef _DEBUG
  #include <Python.h>
  #define _DEBUG
#else
#include <Python.h>
#endif

namespace EnergyPlus {

namespace PluginManagement {

    void registerNewCallback(int iCalledFrom, void (*f)());

    void runAnyRegisteredCallbacks(int iCalledFrom);

    void clear_state();

    // STUFF RELATED TO PYTHON PLUGINS DOWN HERE

    struct PluginInstance {
        PluginInstance(const std::string& fileName, const std::string& className, const std::string& emsName, bool runPluginDuringWarmup);
        ~PluginInstance();
        static void reportPythonError();
        std::string stringIdentifier; // for diagnostic reporting
        bool runDuringWarmup;
        std::string emsAlias;
        PyObject *pClassInstance = nullptr;  // pointer to the instantiated class instance
        PyObject *pPluginMainFunction = nullptr;  // pointer to the main plugin function
        PyObject *pPluginInitFunction = nullptr;  // pointer to the init plugin function
        void run(); // calls main() on this plugin instance
        void init(); // calls initialize() on this plugin instance
    };

    class PluginManager {
    public:
        PluginManager();
        ~PluginManager() {
            Py_FinalizeEx();
        }
        static void addToPythonPath(const std::string& path, bool userDefinedPath);
        static std::string sanitizedPath(std::string path); // intentionally not a const& string
        static int calledFromFromString(std::string const &calledFrom);
        static void initAllRegisteredPlugins();
        void setupOutputVariables();
        void addGlobalVariable(const std::string& name);
        int getGlobalVariableHandle(const std::string& name, bool suppress_warning = false);
        Real64 getGlobalVariableValue(int handle);
        void setGlobalVariableValue(int handle, Real64 value);
        static std::pair<int, int> getLocationOfUserDefinedPlugin(std::string const &programName);
        static void runSingleUserDefinedPlugin(int callingPoint, int index);
        std::vector<std::string> globalVariableNames;
        std::vector<Real64> globalVariableValues;
    };

    extern std::unique_ptr<PluginManager> pluginManager;
}
}

#endif // EPLUS_PLUGINMANAGER_HH