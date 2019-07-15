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

#ifndef DataHeatBalFanSys_hh_INCLUDED
#define DataHeatBalFanSys_hh_INCLUDED

// ObjexxFCL Headers
#include <ObjexxFCL/Array1D.hh>

// EnergyPlus Headers
#include <EnergyPlus.hh>

namespace EnergyPlus {

namespace DataHeatBalFanSys {

    // Data
    // -only module should be available to other modules and routines.
    // Thus, all variables in this module must be PUBLIC.

    // MODULE PARAMETER DEFINITIONS:
    EP_GLOBAL extern int const UseSimpleAirFlow;
    EP_GLOBAL extern Real64 const MaxRadHeatFlux; // [W/m2] max limit for radiant heat flux at a surface due to HVAC equipment

    // Controls for PredictorCorrector
    EP_GLOBAL extern int const iGetZoneSetPoints;
    EP_GLOBAL extern int const iPredictStep;
    EP_GLOBAL extern int const iCorrectStep;
    EP_GLOBAL extern int const iRevertZoneTimestepHistories;
    EP_GLOBAL extern int const iPushZoneTimestepHistories;
    EP_GLOBAL extern int const iPushSystemTimestepHistories;

    // DERIVED TYPE DEFINITIONS:

    // MODULE VARIABLE DECLARATIONS:
    EP_GLOBAL extern Array1D<Real64> SumConvHTRadSys;         // Sum of convection to zone air from hi temp radiant heaters
    EP_GLOBAL extern Array1D<Real64> SumLatentHTRadSys;       // Sum of latent gains from hi temp radiant heaters
    EP_GLOBAL extern Array1D<Real64> SumConvPool;             // Sum of convection to zone air from pools
    EP_GLOBAL extern Array1D<Real64> SumLatentPool;           // Sum of latent gains from pools
    EP_GLOBAL extern Array1D<Real64> QHTRadSysToPerson;       // Sum of radiant gains to people from hi temp radiant heaters
    EP_GLOBAL extern Array1D<Real64> QHWBaseboardToPerson;    // Sum of radiant gains to people from hot water baseboard heaters
    EP_GLOBAL extern Array1D<Real64> QSteamBaseboardToPerson; // Sum of radiant gains to people from steam baseboard heaters
    EP_GLOBAL extern Array1D<Real64> QElecBaseboardToPerson;  // Sum of radiant gains to people from electric baseboard heaters
    EP_GLOBAL extern Array1D<Real64> QCoolingPanelToPerson;   // Sum of radiant losses to people from cooling panels
    // Zone air drybulb conditions variables
    EP_GLOBAL extern Array1D<Real64> ZTAV;         // Zone Air Temperature Averaged over the Zone Time step
    EP_GLOBAL extern Array1D<Real64> MAT;          // MEAN AIR TEMPARATURE (C)
    EP_GLOBAL extern Array1D<Real64> TempTstatAir; // temperature of air near the thermo stat
    EP_GLOBAL extern Array1D<Real64> ZT;           // Zone Air Temperature Averaged over the System Time Increment
    EP_GLOBAL extern Array1D<Real64> XMAT;         // TEMPORARY ZONE TEMPERATURE TO TEST CONVERGENCE
    EP_GLOBAL extern Array1D<Real64> XM2T;
    EP_GLOBAL extern Array1D<Real64> XM3T;
    EP_GLOBAL extern Array1D<Real64> XM4T;
    EP_GLOBAL extern Array1D<Real64> DSXMAT; // Down Stepped MAT history storage
    EP_GLOBAL extern Array1D<Real64> DSXM2T; // Down Stepped MAT history storage
    EP_GLOBAL extern Array1D<Real64> DSXM3T; // Down Stepped MAT history storage
    EP_GLOBAL extern Array1D<Real64> DSXM4T; // Down Stepped MAT history storage
    EP_GLOBAL extern Array1D<Real64> XMPT;   // Zone air temperature at previous time step

    EP_GLOBAL extern Array1D<Real64> ZTAVComf; // Zone Air Temperature Averaged over the Zone Time step used
    // in thermal comfort models (currently Fang model only)
    EP_GLOBAL extern Array1D<Real64> ZoneAirHumRatAvgComf; // AIR Humidity Ratio averaged over the zone time
    // step used in thermal comfort models (currently Fang model only)

    // Zone Air moisture conditions variables
    EP_GLOBAL extern Array1D<Real64> ZoneAirHumRatAvg;  // AIR Humidity Ratio averaged over the zone time step
    EP_GLOBAL extern Array1D<Real64> ZoneAirHumRat;     // AIR Humidity Ratio
    EP_GLOBAL extern Array1D<Real64> WZoneTimeMinus1;   // Humidity ratio history terms for 3rd order derivative
    EP_GLOBAL extern Array1D<Real64> WZoneTimeMinus2;   // Time Minus 2 Zone Time Steps Term
    EP_GLOBAL extern Array1D<Real64> WZoneTimeMinus3;   // Time Minus 3 Zone Time Steps Term
    EP_GLOBAL extern Array1D<Real64> WZoneTimeMinus4;   // Time Minus 4 Zone Time Steps Term
    EP_GLOBAL extern Array1D<Real64> DSWZoneTimeMinus1; // DownStepped Humidity ratio history terms for 3rd order derivative
    EP_GLOBAL extern Array1D<Real64> DSWZoneTimeMinus2; // DownStepped Time Minus 2 Zone Time Steps Term
    EP_GLOBAL extern Array1D<Real64> DSWZoneTimeMinus3; // DownStepped Time Minus 3 Zone Time Steps Term
    EP_GLOBAL extern Array1D<Real64> DSWZoneTimeMinus4; // DownStepped Time Minus 4 Zone Time Steps Term
    EP_GLOBAL extern Array1D<Real64> WZoneTimeMinusP;   // Humidity ratio history terms at previous time step

    EP_GLOBAL extern Array1D<Real64> ZoneAirHumRatTemp;   // Temp zone air humidity ratio at time plus 1
    EP_GLOBAL extern Array1D<Real64> WZoneTimeMinus1Temp; // Zone air humidity ratio at previous timestep
    EP_GLOBAL extern Array1D<Real64> WZoneTimeMinus2Temp; // Zone air humidity ratio at timestep T-2
    EP_GLOBAL extern Array1D<Real64> WZoneTimeMinus3Temp; // Zone air humidity ratio at timestep T-3
    EP_GLOBAL extern Array1D<Real64> ZoneAirHumRatOld;    // Last Time Steps Zone AIR Humidity Ratio

    EP_GLOBAL extern Array1D<Real64> MCPI;                       // INFILTRATION MASS FLOW * AIR SPECIFIC HEAT
    EP_GLOBAL extern Array1D<Real64> MCPTI;                      // INFILTRATION MASS FLOW * AIR CP * AIR TEMPERATURE
    EP_GLOBAL extern Array1D<Real64> MCPV;                       // VENTILATION MASS FLOW * AIR SPECIFIC HEAT
    EP_GLOBAL extern Array1D<Real64> MCPTV;                      // VENTILATION MASS FLOW * AIR CP * AIR TEMPERATURE
    EP_GLOBAL extern Array1D<Real64> MCPM;                       // Mixing MASS FLOW * AIR SPECIFIC HEAT
    EP_GLOBAL extern Array1D<Real64> MCPTM;                      // Mixing MASS FLOW * AIR CP * AIR TEMPERATURE
    EP_GLOBAL extern Array1D<Real64> MCPE;                       // EARTHTUBE MASS FLOW * AIR SPECIFIC HEAT
    EP_GLOBAL extern Array1D<Real64> EAMFL;                      // OUTDOOR AIR MASS FLOW for EarthTube
    EP_GLOBAL extern Array1D<Real64> EAMFLxHumRat;               // OUTDOOR AIR MASS FLOW * Humidity Ratio for EarthTube (water vapor mass flow)
    EP_GLOBAL extern Array1D<Real64> MCPTE;                      // EARTHTUBE MASS FLOW * AIR CP * AIR TEMPERATURE
    EP_GLOBAL extern Array1D<Real64> MCPC;                       // COOLTOWER MASS FLOW * AIR SPECIFIC HEAT
    EP_GLOBAL extern Array1D<Real64> CTMFL;                      // OUTDOOR AIR MASS FLOW for cooltower
    EP_GLOBAL extern Array1D<Real64> MCPTC;                      // COOLTOWER MASS FLOW * AIR CP * AIR TEMPERATURE
    EP_GLOBAL extern Array1D<Real64> ThermChimAMFL;              // OUTDOOR AIR MASS FLOW for THERMALCHIMNEY
    EP_GLOBAL extern Array1D<Real64> MCPTThermChim;              // THERMALCHIMNEY MASS FLOW * AIR SPECIFIC HEAT
    EP_GLOBAL extern Array1D<Real64> MCPThermChim;               // THERMALCHIMNEY MASS FLOW * AIR CP * AIR TEMPERATURE
    EP_GLOBAL extern Array1D<Real64> ZoneLatentGain;             // Latent Energy from each Zone (People, equipment)
    EP_GLOBAL extern Array1D<Real64> ZoneLatentGainExceptPeople; // Added for hybrid model -- Latent Energy from each Zone (equipment)
    EP_GLOBAL extern Array1D<Real64> OAMFL;                      // OUTDOOR AIR MASS FLOW (kg/s) for infiltration
    EP_GLOBAL extern Array1D<Real64> VAMFL;                      // OUTDOOR AIR MASS FLOW (kg/s) for ventilation
    EP_GLOBAL extern Array1D<Real64> NonAirSystemResponse;       // Convective heat addition rate from non forced air
    // equipment such as baseboards plus heat from lights to
    EP_GLOBAL extern Array1D<Real64> SysDepZoneLoads; // Convective heat addition or subtraction rate from sources that
    // depend on what is happening with the HVAC system. Such as:
    // heat gain from lights to return air when return flow = 0; heat gain
    // from air flow windows to return air when return air flow = 0;
    // and heat removed by return air from refrigeration cases when
    // return air flow = 0.
    EP_GLOBAL extern Array1D<Real64> SysDepZoneLoadsLagged; // SysDepZoneLoads saved to be added to zone heat balance next
    // HVAC time step
    EP_GLOBAL extern Array1D<Real64>
        MDotCPOA; // Airbalance MASS FLOW * AIR SPECIFIC HEAT used at Air Balance Method = Quadrature in the ZoneAirBalance:OutdoorAir
    EP_GLOBAL extern Array1D<Real64> MDotOA; // Airbalance MASS FLOW rate used at Air Balance Method = Quadrature in the ZoneAirBalance:OutdoorAir

    EP_GLOBAL extern Array1D<Real64> MixingMassFlowZone;    // Mixing MASS FLOW (kg/s)
    EP_GLOBAL extern Array1D<Real64> MixingMassFlowXHumRat; // Mixing MASS FLOW * Humidity Ratio

    EP_GLOBAL extern Array1D_bool ZoneMassBalanceFlag;  // zone mass flow balance flag
    EP_GLOBAL extern Array1D_bool ZoneInfiltrationFlag; // Zone Infiltration flag
    EP_GLOBAL extern Array1D_int ZoneReOrder;           // zone number reordered for zone mass balance

    // REAL Variables for the Heat Balance Simulation

    EP_GLOBAL extern Array1D<Real64> QRadSysSource;     // Current source/sink for a particular surface (radiant sys)
    EP_GLOBAL extern Array1D<Real64> TCondFDSourceNode; // Temperature of source/sink location in surface from CondFD algo
    EP_GLOBAL extern Array1D<Real64> QPVSysSource;      // Current source/sink for a surface (integrated PV sys)

    EP_GLOBAL extern Array1D<Real64> CTFTsrcConstPart; // Constant Outside Portion of the CTF calculation of
    // temperature at source
    EP_GLOBAL extern Array1D<Real64> CTFTuserConstPart; // Constant Outside Portion of the CTF calculation of
    // temperature at the user specified location
    EP_GLOBAL extern Array1D<Real64> QHTRadSysSurf; // Current radiant heat flux at a surface due to the presence
    // of high temperature radiant heaters
    EP_GLOBAL extern Array1D<Real64> QHWBaseboardSurf; // Current radiant heat flux at a surface due to the presence
    // of hot water baseboard heaters
    EP_GLOBAL extern Array1D<Real64> QSteamBaseboardSurf; // Current radiant heat flux at a surface due to the presence
    // of steam baseboard heaters
    EP_GLOBAL extern Array1D<Real64> QElecBaseboardSurf; // Current radiant heat flux at a surface due to the presence
    // of electric baseboard heaters
    EP_GLOBAL extern Array1D<Real64> QCoolingPanelSurf; // Current radiant heat flux at a surface due to the presence
    // of simple cooling panels
    EP_GLOBAL extern Array1D<Real64> QRadSurfAFNDuct;     // Current radiant heat flux at a surface due to radiation from AFN ducts
    EP_GLOBAL extern Array1D<Real64> QPoolSurfNumerator;  // Current pool heat flux impact at the surface (numerator of surface heat balance)
    EP_GLOBAL extern Array1D<Real64> PoolHeatTransCoefs;  // Current pool heat transfer coefficients (denominator of surface heat balance)
    EP_GLOBAL extern Array1D<Real64> RadSysTiHBConstCoef; // Inside heat balance coefficient that is constant
    EP_GLOBAL extern Array1D<Real64> RadSysTiHBToutCoef;  // Inside heat balance coefficient that modifies Toutside
    EP_GLOBAL extern Array1D<Real64> RadSysTiHBQsrcCoef;  // Inside heat balance coefficient that modifies source/sink
    EP_GLOBAL extern Array1D<Real64> RadSysToHBConstCoef; // Outside heat balance coefficient that is constant
    EP_GLOBAL extern Array1D<Real64> RadSysToHBTinCoef;   // Outside heat balance coefficient that modifies Toutside
    EP_GLOBAL extern Array1D<Real64> RadSysToHBQsrcCoef;  // Outside heat balance coefficient that modifies source/sink

    // Moisture variables to carry info from HB to the Zone Temp Predictor-Corrector for Fan System
    EP_GLOBAL extern Array1D<Real64> SumHmAW;   // SUM OF ZONE AREA*Moist CONVECTION COEFF*INSIDE Humidity Ratio
    EP_GLOBAL extern Array1D<Real64> SumHmARa;  // SUM OF ZONE AREA*Moist CONVECTION COEFF*Rho Air
    EP_GLOBAL extern Array1D<Real64> SumHmARaW; // SUM OF ZONE AREA*Moist CONVECTION COEFF*Rho Air* Inside Humidity Ration
    EP_GLOBAL extern Array1D<Real64> SumHmARaZ;

    EP_GLOBAL extern Array1D<Real64> TempZoneThermostatSetPoint;
    EP_GLOBAL extern Array1D<Real64> AdapComfortCoolingSetPoint;
    EP_GLOBAL extern Array1D<Real64> ZoneThermostatSetPointHi;
    EP_GLOBAL extern Array1D<Real64> ZoneThermostatSetPointLo;
    EP_GLOBAL extern Array1D<Real64> ZoneThermostatSetPointHiAver;
    EP_GLOBAL extern Array1D<Real64> ZoneThermostatSetPointLoAver;

    EP_GLOBAL extern Array1D<Real64> LoadCorrectionFactor; // PH 3/3/04

    EP_GLOBAL extern Array1D<Real64> AIRRAT; // "air power capacity"  PH 3/5/04
    EP_GLOBAL extern Array1D<Real64> ZTM1;   // zone air temperature at previous timestep
    EP_GLOBAL extern Array1D<Real64> ZTM2;   // zone air temperature at timestep T-2
    EP_GLOBAL extern Array1D<Real64> ZTM3;   // zone air temperature at previous T-3
    // Hybrid Modeling
    EP_GLOBAL extern Array1D<Real64> PreviousMeasuredZT1;     // Measured zone air temperature at previous timestep1
    EP_GLOBAL extern Array1D<Real64> PreviousMeasuredZT2;     // Measured zone air temperature at previous timestep2
    EP_GLOBAL extern Array1D<Real64> PreviousMeasuredZT3;     // Measured zone air temperature at previous timestep3
    EP_GLOBAL extern Array1D<Real64> PreviousMeasuredHumRat1; // Hybrid model zone humidity ratio at previous timestep
    EP_GLOBAL extern Array1D<Real64> PreviousMeasuredHumRat2; // Hybrid model zone humidity ratio at previous timestep
    EP_GLOBAL extern Array1D<Real64> PreviousMeasuredHumRat3; // Hybrid model zone humidity ratio at previous timestep
    // Exact and Euler solutions
    EP_GLOBAL extern Array1D<Real64> ZoneTMX; // TEMPORARY ZONE TEMPERATURE TO TEST CONVERGENCE in Exact and Euler method
    EP_GLOBAL extern Array1D<Real64> ZoneTM2; // TEMPORARY ZONE TEMPERATURE at timestep t-2 in Exact and Euler method
    EP_GLOBAL extern Array1D<Real64> ZoneT1;  // Zone temperature at the previous time step used in Exact and Euler method
    EP_GLOBAL extern Array1D<Real64> ZoneWMX; // TEMPORARY ZONE TEMPERATURE TO TEST CONVERGENCE in Exact and Euler method
    EP_GLOBAL extern Array1D<Real64> ZoneWM2; // TEMPORARY ZONE TEMPERATURE at timestep t-2 in Exact and Euler method
    EP_GLOBAL extern Array1D<Real64> ZoneW1;  // Zone temperature at the previous time step used in Exact and Euler method
    EP_GLOBAL extern Array1D_int TempControlType;
    EP_GLOBAL extern Array1D_int ComfortControlType;

    // Types

    struct ZoneComfortControlsFangerData
    {
        // Members
        int FangerType;      // Index for Fanger type
        Real64 LowPMV;       // Low PMV value
        Real64 HighPMV;      // High PMV Value
        int DualPMVErrCount; // Dual PMV setpoint error count
        int DualPMVErrIndex; // Dual PMV setpoint error index

        // Default Constructor
        ZoneComfortControlsFangerData() : FangerType(0), LowPMV(0.0), HighPMV(0.0), DualPMVErrCount(0), DualPMVErrIndex(0)
        {
        }
    };

    // Object Data
    EP_GLOBAL extern Array1D<ZoneComfortControlsFangerData> ZoneComfortControlsFanger;

    void clear_state();

} // namespace DataHeatBalFanSys

} // namespace EnergyPlus

#endif
