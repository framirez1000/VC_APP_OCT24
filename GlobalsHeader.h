#ifndef _GlobalsHeader
#define _GlobalsHeader
#endif
#pragma once
#include <tchar.h>
#include <stdio.h>
#include <Windows.h>

#include <cliext/vector>
#include <cliext/list>
#include <cliext/map>
#include <list>
#include "XML_ViewSettingsConf_Class.h"
#include "C:\Epics\base-3.16.2\include\cadef.h"
#include <fileapi.h>

//#include "Crate.h"
//#include "MainHeader.h"
// Macro to validate values into limits
#define IN_LIMITS(value, lower, upper) ((value >= lower) && (value <= upper))
#define INSIDE_LIMITS(value, lower, upper) ((value > lower) && (value < upper))
#define IN_LEFT_LIMITS(value, lower, upper) ((value >= lower) && (value < upper))
#define IN_RIGHT_LIMITS(value, lower, upper) ((value > lower) && (value <= upper))
#define TIME_2_TEST_GUI_LIFE_SEC 30
#define DEFAULT_DATA_FILE_PATH "C:\\ProgramData\\GECA_VC_Data\\LOG\\"
#define DEFAULT_DATA_FILE_NAME "dataFile.csv"
#define MSG_DATA_HEADER "DATA "
#define MSG_FILE_NAME_HEADER "NAME "
#define MSG_CHNLS_NAMES_HEADER "CHNM "
#define MAX_NMBR_STATUSBAR_MSGS 30
#define COMM_FAILURE_MSG "COMM FAILURE"
#define COMM_TRY_MSG "TRYING TO COMMUNICATE"
#define COMM_BACK_MSG "COMMUNICATION RE-STABLISHED"
#define PIPE_TESTING_GUI_LIFE TEXT("\\\\.\\pipe\\PipeLifeGUI")
#define PIPE_DATA_FILE TEXT("\\\\.\\pipe\\PipeDataFile")
//#define PIPE_COMM TEXT("\\\\.\\pipe\\CommPipe")
//#define PIPE_THREAD TEXT("\\\\.\\pipe\\ThreadPipe")
//#define SH_MEM_SEM TEXT("Global\MyShMemChannelsDataSem")
//#define CMDS_SEM TEXT("Global\MyShMemChannelsDataSem")

#define MAX_CRATES 8
#define MAX_CHANNELS 16
#define MAX_VIEW_CHANNELS 100
#define MAX_MODULES 8
#define MAX_CHANNELS_X_CRATE 128

#define DETECT_HRW 0
#define CHECK_CRATE 1
#define ADD_CRATE 2
#define SET_CONF_VALUE 3
#define CHANNELS_TO_ON_OFF 4
#define DISCONNECT 5
#define STOP 6
#define E_OK 0
#define COMM_OK 0
#define COMM_FAIL 1
#define CHANNEL_VIEW_DEFAULT_NAME "Select channel"

#define MAX_CMDS_EXEC_LIST 5
#define CRATE_CMD 0
#define MODULE_CMD 1
#define CHANNEL_CMD 2
#define CHNLS_CMDS_NMBR 39
 
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;
using namespace System::Xml::Serialization;

static bool lockCrateObject;
ref struct Globals {
 public: 
	 static String^ globalVar;
 };

ref class SingletonCmmdClass
{
private:
	SingletonCmmdClass() {
		strParamsList = gcnew List<String^>(MAX_CMDS_EXEC_LIST);
		strCmdsToExcList = gcnew List<String^>(MAX_CMDS_EXEC_LIST);
		CmdTargetList = gcnew List<int>(MAX_CMDS_EXEC_LIST);
		//statusBarMsg = gcnew String("System Start-Up");
		StatusBarMsgIndex = 24;
	}
	SingletonCmmdClass(const SingletonCmmdClass%) { throw gcnew System::InvalidOperationException("singleton cannot be copy-constructed"); }
	static SingletonCmmdClass m_instance;
public:
	String^ deviceCmd;
	int cmdType, cmdTarget;
	bool execRequest, cmdExecuted, cmdResult, doCaSearch=true;
	int returnValue1, returnValue2;
	List<String^>^ p;
	short barProgressValue;
	short progressRate=1;
	List<String^>^ strCmdsToExcList;
	List<String^>^ strParamsList;
	List<int>^ CmdTargetList;
	bool ViewActive = false;
	property bool HrwConntd;
	property String^ statusBarMsg;
	property String^ statusBarMsg2;
	property int StatusBarMsgIndex;
	property bool nameChanged;
public:
	static property SingletonCmmdClass^ Instance { SingletonCmmdClass^ get() { return % m_instance; } }
	static System::Void GlobalAddSendCmds(String^ cmd, String^ param, int destiny, int cmdType, bool send)
	{
		if (!String::IsNullOrEmpty(cmd) && !(Instance->strCmdsToExcList->Contains(cmd))) {
			Instance->strCmdsToExcList->Add(cmd);
			Instance->strParamsList->Add(param);
			Instance->CmdTargetList->Add(destiny);
		}
		if (send && (Instance->strCmdsToExcList->Count > 0)) {
			Instance->barProgressValue = 0;
			Instance->cmdType = cmdType; // 
			Instance->cmdResult = false;
			Instance->cmdExecuted = false;
			Instance->execRequest = true;
			int i = 0;
			while (!Instance->cmdExecuted && (i++ < 10 * (Instance->strCmdsToExcList->Count)))
				System::Threading::Thread::Sleep(100);
			if (Instance->cmdExecuted) {
				Console::WriteLine("Setting(s) sent");
			}
		}
		else if (send) { 
			Instance->StatusBarMsgIndex = 25;
			//Instance->statusBarMsg += " Nothing to send"; 
		}
		return System::Void();
	}
	static System::Void CleanCmdsLists() {
		Instance->strCmdsToExcList->Clear();
		Instance->strParamsList->Clear();
		Instance->CmdTargetList->Clear();
		Instance->cmdResult = false;
		Instance->cmdExecuted = false;
	}
};

static bool GlobalFuncValidateSP(String^ spValue, String^ nomVltg, double lowLimitFactor, double highLimitFactor) {
	int i;
	
	Double val;
	if (!Double::TryParse(spValue, val)) {
		return false;// return false to make undo on textBox
	}
	else {
		Double val2 = System::Convert::ToDouble(nomVltg);
		if (val2 < 0) {
			val2 *= -1;
			val *= -1;
		}
		if (IN_LIMITS((double)val, lowLimitFactor * (double)val2, highLimitFactor * (double)val2)
			&& (val2 != 0)) { // value Ok
			return true;
		}
		else return false;
	}
	return true;
}
static String^ GlobalGetModName(String^ chnlName)
{
	// TODO: insert return statement here
	System::Array^ strArray = chnlName->Split(':');
	return (System::Convert::ToString(strArray->GetValue(0))
		+ ":" + System::Convert::ToString(strArray->GetValue(1))
		+ ":" + System::Convert::ToString(strArray->GetValue(2))
		+ ":" + System::Convert::ToString(strArray->GetValue(3)));
}
typedef cliext::map<String^, bool> CheckedList; // For a check list in HrdList/LogDataFile Form

ref struct ChId {
	chid chnlID;
};

typedef cliext::map<String^, ChId^> CmdsId;     // For a CMD-CHID pair in comm with IO (channel/Mod/Crate classes and CA_thread)

ref struct readouts {
	double voltg, current;
};
ref struct FileData {

	FileData() {
		fileName = gcnew String(DEFAULT_DATA_FILE_NAME);
		path = gcnew String(DEFAULT_DATA_FILE_PATH);
		savingInterval = 5;
	}
	System::String^ fileName;
	System::String^ path;
	int savingInterval;
	CheckedList monitoredChnls;
} ;

ref class StatusBarMsgT {
	public: property String^ Msg;
			property System::Drawing::Color MsgBackColor;
			property System::Drawing::Color MsgForeColor;
			property int MsgLifeTime;

	StatusBarMsgT(String^ msg, System::Drawing::Color msgBackColor, System::Drawing::Color msgForeColor, int msgLifeTime) {
		Msg = msg; 
		MsgBackColor = msgBackColor;
		MsgForeColor = msgForeColor;
		MsgLifeTime = msgLifeTime;
}
};
static cli::array<StatusBarMsgT^>^ GetArrayMsg() {
	cli::array<StatusBarMsgT^>^ local = gcnew cli::array <StatusBarMsgT^>(MAX_NMBR_STATUSBAR_MSGS);
		local[0] = gcnew StatusBarMsgT("COMM FAILURE", System::Drawing::Color::Red, System::Drawing::Color::White, 5);
		local[1] = gcnew StatusBarMsgT("TRYING TO COMMUNICATE", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[2] = gcnew StatusBarMsgT("COMMUNICATION RE-STABLISHED", System::Drawing::Color::Green, System::Drawing::Color::White, 4);
		local[3] = gcnew StatusBarMsgT(" Total crates(s): ", System::Drawing::Color::Red, System::Drawing::Color::White, 4);
		local[4] = gcnew StatusBarMsgT("New Volt Set Point formula value send", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[5] = gcnew StatusBarMsgT("Sending commands", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[6] = gcnew StatusBarMsgT("Set channels state cmds executed", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[7] = gcnew StatusBarMsgT("RAMP conf settings cmds executed", System::Drawing::Color::Red, System::Drawing::Color::White, 4);
		local[8] = gcnew StatusBarMsgT("No hardware to connect", System::Drawing::Color::DarkGoldenrod, System::Drawing::Color::White, 4);
		local[9] = gcnew StatusBarMsgT("Connected", System::Drawing::Color::Green, System::Drawing::Color::White, 4);
		local[10] = gcnew StatusBarMsgT("Disconnected", System::Drawing::Color::DarkGoldenrod, System::Drawing::Color::White, 4);
		local[11] = gcnew StatusBarMsgT("Crate(s) file loaded: ", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[12] = gcnew StatusBarMsgT("Crates added: ", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[13] = gcnew StatusBarMsgT("Group names List changed, check View", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[14] = gcnew StatusBarMsgT("Crate  added", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[15] = gcnew StatusBarMsgT("Formula value error", System::Drawing::Color::DarkGoldenrod, System::Drawing::Color::White, 4);
		local[16] = gcnew StatusBarMsgT("Input value error", System::Drawing::Color::DarkGoldenrod, System::Drawing::Color::White, 4);
		local[17] = gcnew StatusBarMsgT("Sending ON/OFF command", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[18] = gcnew StatusBarMsgT("View loaded from config file", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[19] = gcnew StatusBarMsgT("Error in loading View from config file", System::Drawing::Color::DarkGoldenrod, System::Drawing::Color::White, 5);
		local[20] = gcnew StatusBarMsgT("No config file especified", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[21] = gcnew StatusBarMsgT("No commands to send", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[22] = gcnew StatusBarMsgT("Crate  added", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[23] = gcnew StatusBarMsgT("Crate  added", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[24] = gcnew StatusBarMsgT("System Start-Up", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[25] = gcnew StatusBarMsgT("Nothing to send", System::Drawing::Color::LightSlateGray, System::Drawing::Color::DarkGoldenrod, 4);
		local[26] = gcnew StatusBarMsgT("Ramp value error", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[27] = gcnew StatusBarMsgT("Not executed, not connection", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[28] = gcnew StatusBarMsgT("Setting(s) sent", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		local[29] = gcnew StatusBarMsgT("Not executed, not connection", System::Drawing::Color::Gray, System::Drawing::Color::White, 4);
		//local[26] = gcnew StatusBarMsgT("Not executed, not connection", System::Drawing::Color::Gray, System::Drawing::Color::White, 5);
	return local;
}

#define kilo 0		 // kilo
#define normal 1     // Volts OR Amp
#define mili 2       // milli
#define uicro 3      // micro
#define CONVERSION_TABLE_NBR_ELEM 4

const double conversionCoef[CONVERSION_TABLE_NBR_ELEM] { 1000, 1, 0.001, 0.000001 };
inline String^ ConvertUnits(Double% val, int unitsIn, int unitsOut) {
	if ((unitsIn >= 0) && (unitsIn <= (CONVERSION_TABLE_NBR_ELEM-1)) 
		&& (unitsOut >= 0) && (unitsOut <= (CONVERSION_TABLE_NBR_ELEM-1))) 
	{
		if (conversionCoef[unitsOut] != 0)
			val = val * ((DOUBLE)conversionCoef[unitsIn] / (Double)conversionCoef[unitsOut]);
			return System::Convert::ToString(val);
	}
	else return "0";
}
bool inline ProcessSPvalStrUserInput(String^% strSP, int* pUnitsOut, bool voltage)
{
	System::Array^ splitInput = strSP->Split(' ');
	if (splitInput->Length == 2) {
		Double newVal=0;
		if (Double::TryParse(System::Convert::ToString(splitInput->GetValue(0)), newVal))
		{
			bool unitsOk = false;
			String^ str = System::Convert::ToString(splitInput->GetValue(1));
			if ((voltage && System::Convert::ToString("kV V m mV u uV")->Contains(str))
				|| (!voltage && System::Convert::ToString("kA A Amp m mA uA")->Contains(str)))
			{
				if (str->Equals("k") || str->Equals("kA") || str->Equals("kV"))
					* pUnitsOut = kilo;
				else if (str->Equals("A") || str->Equals("Amp") || str->Equals("V"))
					* pUnitsOut = normal;
				else if (str->Equals("m") || str->Equals("mA") || str->Equals("mV"))
					* pUnitsOut = mili;
				else if (str->Equals("u") || str->Equals("uA") || str->Equals("uV"))
					* pUnitsOut = uicro;
			
				strSP = System::Convert::ToString(splitInput->GetValue(0));
				return true;
			}
		}
	}
	return false;
	
}