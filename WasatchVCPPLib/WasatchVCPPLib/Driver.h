/**
    @file   Driver.h
    @author Mark Zieg <mzieg@wasatchphotonics.com>
    @brief  interface of WasatchVCPP::Driver
    @note   customers normally wouldn't access this file; use WasatchVCPP.h instead
*/

#pragma once

#include "libusb.h"
#include "Logger.h"

#include <string>
#include <vector>

//! Namespace encapsulating the internal implementation of WasatchVCPP; customers
//! would not normally access these classes or objects directly.
namespace WasatchVCPP
{
    class Spectrometer;

    /**
        @brief  This is an internal class encapsulating state and control of all
                connected spectrometers.

        End-users / customers would not normally access this class directly; they 
        should interact with the library through WasatchVCPPWrapper.h or 
        WasatchVCPP::Proxy.
    */
    class Driver
    {
        public:
            const std::string libraryVersion = "0.0.6";

            static Driver* getInstance();

            int getNumberOfSpectrometers();
            int openAllSpectrometers();
            Spectrometer* getSpectrometer(int index);

            std::string getLibraryVersion();

            Logger logger;

        private:
            static Driver* instance;
            Driver(); 

            std::vector<Spectrometer*> spectrometers;
    };
}
