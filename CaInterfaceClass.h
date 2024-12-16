
#pragma once
#include <map>
#include <string>
#include "Crate.h"
#include "MainHeader.h"
//#include "GlobalsHeader.h"
//#include "C:\Epics\base-3.16.2\include\cadef.h"
#include < vcclr.h >


#ifndef _EPICS_INTERFACE_H
#define  _EPICS_INTERFACE_H

#define MAX_CMD_LENGTH 50
#define MAX_No_CHANNELS_x_MOD 16
#define MAX_No_MODULES_x_CRATE 10

#define MAX_WAIT_CA_TIME 0.099//0.075 // 0.05
#define MAX_CONN_ITER_NMBR 3
#define READ 0
#define WRITE 1

// Enum defintions for using string values in case statement
//static enum EnumStringValue {
//	evNotDefined,
//	evVoltageRamp,
//	evCurrentRamp,
//	evVoltageSet,
//	evCurrentSet
//};
using namespace System;
//using namespace std;

// Map to associate the strings with the enum values
//static std::map<std::string, EnumStringValue> m_SwitchCmdMap;


typedef struct CmdsT {
	char* strCmd;
	chid channelID;
	short channelDataType; /* SHORT, int, STRING,*/
	void* ptrData;
	unsigned short cmdParamNmbr,
		cmdType; // 0: read, 1: write
	
};
typedef struct ChannelsMembersT {
	unsigned long Status;
	double 	voltMeasure, crrntMeasure, voltNominal,
			crrntNominal, tempExternal, voltSet,
			crrntSet, vltgBounds, crrntBounds,
			vltgCoef, dlyTripTime;
	 short	ctrlSetOn, aux13, aux14, aux15, aux16,
	 		aux17, aux18, aux19, aux20, aux21,
	 		aux22, aux23, aux24, aux25, aux26,
	 		aux27, aux28, aux29, aux30, aux31,
	 		aux32, aux33, aux34, aux35, aux36,
		    aux37, aux38;
};
#define MAX_CONF_CMDS_NMBR 39
#define CRATE_CMDS_NMBR 9
static CmdsT CrateConfCmds[CRATE_CMDS_NMBR] = {
	{":CrateList", NULL, DBR_SHORT, NULL, 0},
	{":CrateNumber", NULL, DBR_STRING, NULL, 0},
	{":ModuleNumber", NULL, DBR_STRING, NULL, 0},
	{":FirmwareRelease", NULL, DBR_STRING, NULL, 2},
	{":FirmwareName", NULL, DBR_STRING, NULL, 2},
	{":Article", NULL, DBR_STRING, NULL, 2},
	{":FanSpeed", NULL, DBR_STRING, NULL, 2},
	{":SerialNumber", NULL, DBR_STRING, NULL, 2},
	{":PowerOn", NULL, DBR_STRING, NULL, 2}
};
#define MOD_CMDS_NMBR 13
static CmdsT ModConfCmds[MOD_CMDS_NMBR] = {
	{":Status", NULL, DBF_LONG, NULL},
	{":ChannelNumber", NULL, DBF_LONG, NULL },
	{":FirmwareRelease", NULL, DBR_STRING, NULL},
	{":FirmwareName", NULL, DBR_STRING, NULL},
	{":Article", NULL, DBR_STRING, NULL},
	{":VoltageLimit", NULL, DBF_DOUBLE, NULL},
	{":VoltageLimitNegative", NULL, DBF_DOUBLE, NULL},
	{":CurrentLimit", NULL, DBF_DOUBLE, NULL},
	{":Temperature", NULL, DBF_DOUBLE, NULL},
	{":SerialNumber", NULL, DBR_STRING, NULL},
	{":DigitalFilter", NULL, DBR_STRING, NULL},
	{":VoltageRampSpeed", NULL, DBF_DOUBLE, NULL},
	{":CurrentRampSpeed", NULL, DBF_DOUBLE, NULL}};
//#define CHNLS_CMDS_NMBR 37

static ChannelsMembersT chnlValues={0, 0.5, 0.6,0,0,0,0,10,10,
									0, 0.5, 0.6,0,0,0,0,0,0, 
									0, 0.5, 0.6,0,0,0,0,0,0,
									0, 0.5, 0.6,0,0,0,0,0,0,0,0,0 }, chnlValues2;
static CmdsT ChnlConfCmds[MAX_CONF_CMDS_NMBR] = {
/*0: Channel status*/										{":Status",				NULL, DBR_LONG,	  &(chnlValues.Status),		 0, READ},
/*1: Channel VoltageMeasure: Get the chnl actual vltg*/		{":VoltageMeasure",		NULL, DBR_DOUBLE, &(chnlValues.voltMeasure), 0, READ},
/*2: Channel CurrentMeasure: Get the chnl actual crrnt*/	{":CurrentMeasure",		NULL, DBR_DOUBLE, &(chnlValues.crrntMeasure),0, READ},
/*3: Channel VoltageNominal: Get the chnl nominal vltg*/	{":VoltageNominal",		NULL, DBR_DOUBLE, &(chnlValues.voltNominal), 0, READ},
/*4: Channel CurrentNominal: Get the chnl nominal vltg*/	{":CurrentNominal",		NULL, DBR_DOUBLE, &(chnlValues.crrntNominal),0, READ},
/*5: Channel TemperatureExternal: Get the chnl ext temp*/	{":TemperatureExternal",NULL, DBR_DOUBLE, &(chnlValues.tempExternal),0, READ},
/*6: Channel Control: Set chnl STATE to On/Off*/			{":Control:setOn",		NULL, DBR_ENUM,	  &(chnlValues.ctrlSetOn),	 0, WRITE},
/*7: Channel VoltageSet: Set/Get chnl vltg Set Point*/		{":VoltageSet",			NULL, DBR_STRING, &(chnlValues.voltSet),	 0, WRITE},
/*8: Channel CurrentSet: Set/Get chnl crrnt Set Point*/		{":CurrentSet",			NULL, DBR_STRING, &(chnlValues.crrntSet),	 0, WRITE},
/*9: Channel VoltageBounds*/								{":VoltageBounds",		NULL, DBR_DOUBLE, &(chnlValues.vltgBounds),  0, READ},
/*10: Channel CurrentBounds*/								{":CurrentBounds",		NULL, DBR_DOUBLE, &(chnlValues.crrntBounds), 0, READ},
/*11: Channel VctCoefficient*/								{":VctCoefficient",		NULL, DBR_DOUBLE, &(chnlValues.vltgCoef),	 0, WRITE},
/*12: Channel DelayedTripTime*/								{":DelayedTripTime",	NULL, DBR_DOUBLE, &(chnlValues.dlyTripTime), 0, WRITE},
/*13: Channel InputError*/									{":InputError",			NULL, DBR_ENUM,	  &(chnlValues.aux13),		 0, 0},
/*14: Channel isOn: Read the chnl STATE*/					{":isOn",				NULL, DBR_ENUM,	  &(chnlValues.aux14),		 0, 0},
/*15: Channel isVoltageRamp*/								{":isVoltageRamp",		NULL, DBR_ENUM,	  &(chnlValues.aux15),		 0, 0},
/*16: Channel isEmergency*/									{":isEmergency",		NULL, DBR_ENUM,	  &(chnlValues.aux16),		 0, 0},
/*17: Channel isCC*/										{":isCC",				NULL, DBR_ENUM,	  &(chnlValues.aux17),		 0, 0},
/*18*/	{":isCV", NULL, DBR_ENUM, &(chnlValues.aux18), 0, 0},
/*19*/	{":isCurrentBound", NULL, DBR_ENUM, &(chnlValues.aux19), 0, 0},
/*20*/	{":isVoltageBound", NULL, DBR_ENUM, &(chnlValues.aux20), 0, 0},
/*21*/	{":isExternalInhibit", NULL, DBR_ENUM, &(chnlValues.aux21), 0, 0},
/*22*/	{":isTrip", NULL, DBR_ENUM, &(chnlValues.aux22), 0, 0},
/*23*/	{":isCurrentLimit", NULL, DBR_ENUM, &(chnlValues.aux23), 0, 0},
/*24*/	{":isVoltageLimit", NULL, DBR_ENUM, &(chnlValues.aux24), 0, 0},
/*25*/	{":EventInputError", NULL, DBR_ENUM, &(chnlValues.aux25), 0, 0},
/*26*/	{":EOn2Off", NULL, DBR_ENUM, &(chnlValues.aux26), 0, 0},
/*27*/	{":EventEndOfRamp", NULL, DBR_ENUM, &(chnlValues.aux27), 0, 0},
/*28*/	{":EventEmergency", NULL, DBR_ENUM, &(chnlValues.aux28), 0, 0},
/*29*/	{":ECC", NULL, DBR_ENUM, &(chnlValues.aux29), 0, 0},
/*30*/	{":ECV", NULL, DBR_ENUM, &(chnlValues.aux30), 0, 0},
/*31*/	{":ECurrentBounds", NULL, DBR_ENUM, &(chnlValues.aux31), 0, 0},
/*34*/	{":EVVoltageBounds", NULL, DBR_ENUM, &(chnlValues.aux32), 0, 0},
/*33*/	{":EventExternalInhibit", NULL, DBR_ENUM, &(chnlValues.aux33), 0, 0},
/*34*/	{":EventTrip", NULL, DBR_ENUM, &(chnlValues.aux34), 0, 0},
/*35*/	{":EventCurrentLimit", NULL, DBR_ENUM, &(chnlValues.aux35), 0, 0},
/*36*/	{":EventVoltageLimit", NULL, DBR_ENUM, &(chnlValues.aux36), 0, 0},
/*37: Watch Out-> Module cmd*/	{":VoltageRampSpeed", NULL, DBR_DOUBLE, &(chnlValues.aux37), 0, 0},
/*38: Watch Out-> Module cmd*/	{":CurrentRampSpeed", NULL, DBR_DOUBLE, &(chnlValues.aux38), 0, 0}
};


using namespace std;

	public ref class CaInterface
	{
	private: property CratesT^ pMainDataStruct;
	private:
		//System::String m_strFullCMD;
		float fValue;
		int iValue;
		List<Crate^>^ m_ptrCrateMainList;
		SingletonCmmdClass^ Commands;
		//static std::map<const char*, EnumStringValue> m_mapStringValues;
	//public:	MapStringValues m_SwitchCmdMap;

	public:
		CaInterface(List<Crate^>^ ptrCrateMainList, CratesT^ mainDataStruct);
		bool DetectHrw(String^ deveice);
		bool setCAValue(System::String^ cmd, System::String^ fValue, bool sendNow);
		bool getCAValue(System::String^ cmd, double* fValue, int* iValue, int valueType);
		bool test_Crate_Comm(String^ device);
		int getCrateLine(String^ strCrateSN, short *line, short *crateNumber);
		bool Add_Crate(String^ crateToAdd);
		void getModCnf(Module^ ptrMod, int line, int modDir);
		void setAllModMmbrs(Module^ ptrMod, char mmbersValues[][40], int modDir);
		void getCrateCnf(Crate^ ptrCrate, int crateNmbr, int crtDir);
		void setAllCrateMmbrs(Crate^ ptrMod, char mmbersValues[][40], int modDir);
		int getChnlCnf(Channel^ ptrChnl, int line, int mod, int chnl);
		void setAllChnlMmbrs(Channel^ ptrchnl, double* ChnlConfCmds, int modDir, int chnlDir);
		void DecodeCmdMsg(String^ cmd, int* crateDir, int* crateLine, int* mod, int* chnl, int* type);
		int GetChnlType(String^ cmd, CmdsT* cmdTable, int tableSize);
	public: System::Int16 FreqCmdsMgr(double* doubArray, double* doubArray2, char isOnArray[][60], System::String^ cmd, int index, bool sendCmds);
			System::Int16 CaInterface::FreqCmdsMgrSP(double* doubArray, double* doubArray2, char isOnArray[][40], System::String^ cmd, int index, bool sendCmds);
			String^ GetCrateName(String^ chnl);
			String^ GetModName(String^ chnl);
			String^ GetChnlName(String^ chnl);
			int getModIndex(List<Crate^>^ m_ptrCrateMainList, int crateDir, int mod);
			void ClearModErrors(String^ crate, short mod);
	};
	

#endif // !_EPICS_INTERFACE_H
	static void ini_Map() {
		/*m_SwitchCmdMap[(std::string)":VoltageRampSpeed"] = evVoltageRamp;
		m_SwitchCmdMap[":CurrentRampSpeed"] = evCurrentRamp;
		m_SwitchCmdMap[":VoltageSet"] = evVoltageSet;
		m_SwitchCmdMap[":CurrentSet"] = evCurrentSet;*/
	}
