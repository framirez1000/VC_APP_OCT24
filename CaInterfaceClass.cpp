/* This ca_pend_io() is UDP broadcasts (very expensive
	bandwidth) because are sent to all IOCs in the subnet.

	For every broadcast, IOC checks if it owns one of the
	requested channels. If no bradcast is repeated up to 100 times.
	Do not search for obsolete channels to reduce broadcast traffic.

	One broadcast package can contain many channel requests. This
	is much more efficient than sending only one request at a time.
	Thus, always try to connect all channels at once, using only
	one ca_pend_io() after all ca_search() calls. This also speeds up
	your program: waiting 10 seconds for 1000 channels in parallel
	is much shorter than even waiting only 1 second for 1000 sequential
	channel searches. ca_pend_io() returns early when all channels are
	found.
	*/
	/* 
	If not all channels can be found now, the IOC is probably down.
	Searching continues in the background and channels connect
	automatically when the IOC comes up.

	Try to uncomment the #define WITH_NOT_EXISTING_CHANNEL above to
	see what happens if a channel cannot be found.

	Normally, ca_search() should not be called any more after startup.
	There may be exceptions, when channels are added dynamically to a
	running program. But this is not the normal case.

	Connected channels may disconnect and reconnect later automatically
	when an IOC reboots. Always keep this in mind when doing any
	network traffic. Any long-lived program, such as GUIs or servers,
	MUST be written in a way to survive disconnected channels and
	they MUST react in a reasonable manner.
	It depends on the application and is generally is your problem what
	"reasonable" means.
	
	As before, it increases network performance to do as many ca_get()
	calls as possible with one ca_pend_io(). In opposite to searching,
	data transfer is done via TCP. Thus, it affects only the client
	and the IOC and all network components in between. It does not
	affect all IOCs on the same network as searching does! But still,
	many requests can be sent in the same message if they go to the
	same IOC -- which is often the case. Luckily, you don't have to
	care about this. Just always try to read as many channels as
	possible in parallel.
	
	Always when the result of ca_pend_io() after ca_get()
	is not ECA_NORMAL, you MUST check ca_state() of all
	involved channels before trusting any value.
	*/

#include "pch.h"

#include "GlobalsHeader.h"
#include <sstream>
#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>  
#include "CaInterfaceClass.h"

//#include < vcclr.h >
/* include EPICS headers */
//#include "C:\Epics\base-3.16.2\include\cadef.h"

/* Strings describing the connection status of a channel */
const char* channel_state_str[4] = {
	"not found",
	"connection lost",
	"connected",
	"closed"
};

#define CRATE_BASE_READ_CHANNEL "ISEG:5230225:0:1:"
#define CMD_NAME "VoltageMeasure"

char* channelNamesPV[16] = {
	"ISEG:5230225:0:1:0:VoltageMeasure",
	"ISEG:5230225:0:1:1:VoltageMeasure",
	"ISEG:5230225:0:1:2:VoltageMeasure",
	"ISEG:5230225:0:1:3:VoltageMeasure",
	"ISEG:5230225:0:1:4:VoltageMeasure",
	"ISEG:5230225:0:1:5:VoltageMeasure",
	"ISEG:5230225:0:1:6:VoltageMeasure",
	"ISEG:5230225:0:1:7:VoltageMeasure",
	"ISEG:5230225:0:1:8:VoltageMeasure",
	"ISEG:5230225:0:1:9:VoltageMeasure",
	"ISEG:5230225:0:1:10:VoltageMeasure",
	"ISEG:5230225:0:1:11:VoltageMeasure",
	"ISEG:5230225:0:1:12:VoltageMeasure",
	"ISEG:5230225:0:1:13:VoltageMeasure",
	"ISEG:5230225:0:1:14:VoltageMeasure",
	"ISEG:5230225:0:1:15:VoltageMeasure"
};

char* channelNamesBase[16] = {
	"ISEG:5230225:0:1:0:",
	"ISEG:5230225:0:1:1:",
	"ISEG:5230225:0:1:2:",
	"ISEG:5230225:0:1:3:",
	"ISEG:5230225:0:1:4:",
	"ISEG:5230225:0:1:5:",
	"ISEG:5230225:0:1:6:",
	"ISEG:5230225:0:1:7:",
	"ISEG:5230225:0:1:8:",
	"ISEG:5230225:0:1:9:",
	"ISEG:5230225:0:1:10:",
	"ISEG:5230225:0:1:11:",
	"ISEG:5230225:0:1:12:",
	"ISEG:5230225:0:1:13:",
	"ISEG:5230225:0:1:14:",
	"ISEG:5230225:0:1:15:"
};

extern ChannelsMembersT chnlValue;

using namespace System::Runtime::InteropServices;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Threading;
using namespace System::Collections;
using namespace System::Collections::Generic;

//using namespace CA_Interface;

	CaInterface::CaInterface(List<Crate^>^ ptrCrateMainList, CratesT^ mainDataStruct)
	{
		m_ptrCrateMainList = mainDataStruct->ptrMainCrateList;// ptrCrateMainList;
		pMainDataStruct = mainDataStruct;
		Commands = SingletonCmmdClass::Instance;
	}

	bool CaInterface::DetectHrw(String^ device)
	{
		short line, crateNbr;
		
		ca_task_initialize();
		if (getCrateLine(device, &line, &crateNbr) == ECA_NORMAL)	
			return true;
		return false;
	}

	bool CaInterface::setCAValue(System::String^ cmd, System::String^ dValue, bool sendNow)
	{
		chid connectionID;
		int status, crateDir, crateLine, mod, chnl, type, chnlType = -1;
		
		if (cmd == nullptr) return false;
		CaInterface::DecodeCmdMsg(cmd, &crateDir, &crateLine, &mod, &chnl, &type);
		ChId^ it;
		if (crateDir >= 0) {
			int modIndex = getModIndex(m_ptrCrateMainList, crateDir, mod);
			if (modIndex != -1) {
				if (type == 3) { // Channel cmd
					it = m_ptrCrateMainList[crateDir]->m_lstModules[modIndex]->lstChannels[chnl]->ChnlCmdsTableId[cmd];
					chnlType = GetChnlType(cmd, ChnlConfCmds, MAX_CONF_CMDS_NMBR);
				}
				else if (type == 2) { // Module cmd
					it = m_ptrCrateMainList[crateDir]->m_lstModules[modIndex]->pModCmdsTableId[cmd];
					chnlType = GetChnlType(cmd, ModConfCmds, MOD_CMDS_NMBR);
				}
				else if (type == 1) {
					it = m_ptrCrateMainList[crateDir]->pCrateCmdsTableId[cmd];
					chnlType = GetChnlType(cmd, CrateConfCmds, CRATE_CMDS_NMBR);
				}
			}
		}
		
		/* Set conf value for crate/module/channel */
		if (it != nullptr) {
			switch(chnlType) {
			case DBR_STRING: {
				IntPtr ip = Marshal::StringToHGlobalAnsi(dValue);
				const char* strValue = static_cast<const char*>(ip.ToPointer());
				ca_put(DBR_STRING, it->chnlID, strValue);
				status = ca_pend_io(MAX_WAIT_CA_TIME);
				Marshal::FreeHGlobal(ip);
				char strChar[40];
				ca_get(DBR_STRING, it->chnlID, strChar);
				status = ca_pend_io(MAX_WAIT_CA_TIME);
				String^ str = gcnew String(strChar);
				Console::Write("Value written (type String): ");
				Console::WriteLine(str);
				break;
			}
			case DBR_DOUBLE: {
				double val = System::Convert::ToDouble(dValue);
				ca_put(DBR_DOUBLE, it->chnlID, &val);
				status = ca_pend_io(MAX_WAIT_CA_TIME);
				val = 0;
				ca_get(DBR_DOUBLE, it->chnlID, &val);
				status = ca_pend_io(MAX_WAIT_CA_TIME);
				Console::WriteLine("Value written (type Double): " + val);
				break;
			}
			case DBR_ENUM:
			{ // Use to put new channel state order ON/OFF 
				bool val = System::Convert::ToBoolean(dValue);
				ca_put(DBR_SHORT, it->chnlID, &val);
				break;
			}
			default:
				break;
			}
			if (sendNow) status = ca_pend_io(MAX_WAIT_CA_TIME);
			else status == ECA_NORMAL;
			if (status != ECA_NORMAL) {
				return status;
			}
		}
		return 0;
	}

	bool CaInterface::getCAValue(System::String^ cmd, double* dfValue, int *iValue, int valueType)
	{
		/*Pending: Search for cmd type*/
		static chid connectionID = NULL;
		int status, vType, crateDir, crateLine, mod, chnl, type;

		CaInterface::DecodeCmdMsg(cmd, &crateDir, &crateLine, &mod, &chnl, &type);
		ca_task_initialize();
		ca_pend_io(MAX_WAIT_CA_TIME);
		if (cmd == nullptr) return false;
		IntPtr ip = Marshal::StringToHGlobalAnsi(cmd);
		const char* strCmd = static_cast<const char*>(ip.ToPointer());
		if (connectionID == NULL) {
			ChId^ it = gcnew ChId;
			if (type == 3) { // Cmd for channels
				String^ chnl = GetChnlName(cmd);
				if (chnl != nullptr)
					it = pMainDataStruct->GetChnlObj(chnl)->ChnlCmdsTableId[cmd];
					//it = m_ptrCrateMainList[crateDir]->m_lstModules[mod]->lstChannels[chnl]->ChnlCmdsTableId[cmd];
				else return false;
			}
			else if (type == 2) {// Cmd for module
				String^ crate = GetCrateName(cmd);
				String^ mod = GetModName(cmd);
				if ((crate != nullptr) && (mod != nullptr)) {
					it = pMainDataStruct->GetMod(mod, pMainDataStruct->GetCrate(crate))->pModCmdsTableId[cmd];
					//it = m_ptrCrateMainList[crateDir]->m_lstModules[mod]->pModCmdsTableId[cmd];
				}
				else return false;
			}
			else if (type == 1) // Cmd for crate
				return false; // Later: it = m_ptrCrateMainList[crateDir]->CrateCmdsTableId[cmd];
			connectionID =  it->chnlID;
			
		}
		Marshal::FreeHGlobal(ip);
		status = ca_pend_io(MAX_WAIT_CA_TIME);
		if (status != ECA_NORMAL) return status;
		/* Get channel reading for that module */
		switch (valueType)
		{
		case 0:
			ca_put(DBR_DOUBLE, connectionID, dfValue);
			ca_get(DBR_DOUBLE, connectionID, dfValue);
			break;
		case 1:
			ca_put(DBR_SHORT, connectionID, iValue);
			ca_get(DBR_SHORT, connectionID, iValue);
			break;
		default:
			break;
		}
		
		status = ca_pend_io(MAX_WAIT_CA_TIME);
		if (status != ECA_NORMAL)
			return status;

		return true;
	}

	int CaInterface::getCrateLine(String^ strCrateSN, short* pline, short* pCrateNumber)
	{
		chid crateListID, powerOnID;
		char cModNumber[40] = { "Off" }, cPowerOn[40] = { "On" }, cCrateList[40];
		int status = !ECA_NORMAL, statusComm = !ECA_NORMAL;
		string auxCrateList;
		short crateNumber, line;

		ca_task_initialize();
		IntPtr ip = Marshal::StringToHGlobalAnsi(strCrateSN + ":CrateList");  //cmd: ISEG:5230225:CrateList return char string: line.crateNumber, example "0.1000" 
		const char* mod = static_cast<const char*>(ip.ToPointer());
		ca_search(mod, &crateListID);
		statusComm = ca_pend_io(MAX_WAIT_CA_TIME);
		ca_put(DBR_STRING, crateListID, cCrateList);
		ca_get(DBR_STRING, crateListID, cCrateList);
		statusComm = ca_pend_io(MAX_WAIT_CA_TIME);
		auxCrateList = cCrateList;
		if (statusComm == ECA_NORMAL) {
			line = std::stoi(auxCrateList.substr(0, auxCrateList.find(".")));
			crateNumber = std::stoi(auxCrateList.substr(1 + auxCrateList.find(".")));
			ip = Marshal::StringToHGlobalAnsi(strCrateSN + ":" + line + ":" + crateNumber + ":PowerOn");  //cmd: ISEG:5230225:CrateNumber
			mod = static_cast<const char*>(ip.ToPointer());
			ca_search(mod, &powerOnID);
			statusComm = ca_pend_io(MAX_WAIT_CA_TIME);
			ca_put(DBR_STRING, powerOnID, cPowerOn);
			ca_get(DBR_STRING, powerOnID, cPowerOn);
			statusComm = ca_pend_io(MAX_WAIT_CA_TIME);
		}
		Marshal::FreeHGlobal(ip);
		*pline = line;
		*pCrateNumber = crateNumber;
		return statusComm;
	}

	bool CaInterface::test_Crate_Comm(String^ device)
	{
		String^ deviceCommCheck;
		chid channelsID, modID, modID2, crateListID, crateID, crateID2, modListID;
		dbr_sts_string	strCrateStatus, strModStatus;
		short crateNumber, modNumber, channelsNumber, chnlCount, modGood, line;
		int status = !ECA_NORMAL, statusComm = !ECA_NORMAL;
		char cModList[40] = { "Off" };
		SingletonCmmdClass^ Commands = SingletonCmmdClass::Instance;
		
		Console::ForegroundColor = ConsoleColor::DarkGreen;
		Console::WriteLine("Checking Comm -> IO .... " + device);
		if ((device != nullptr) && (device != "")) {
			//ca_task_initialize();
			channelsNumber = 0;
			string auxCrateList;
			IntPtr ip = Marshal::StringToHGlobalAnsi(device + ":CrateList");	//cmd: ISEG:5230225:CrateList
			const char* mod = static_cast<const char*>(ip.ToPointer());
			for (int i = 0; (i < 3) && (statusComm != ECA_NORMAL); i++) {					// MAX 3 tries for checking connection
				//Commands->barProgressValue = 5;
				statusComm = getCrateLine(device, &line, &crateNumber);						//throw gcnew System::NotImplementedException();
				ip = Marshal::StringToHGlobalAnsi(device + ":" + line + ":ModuleList");  //cmd: ISEG:5230225:$line$:ModuleList 
				
				modNumber = 0;
				for (int j = 0; j < MAX_No_MODULES_x_CRATE; j++) {
					chnlCount = 0;
					if ((Commands->barProgressValue + (100/ MAX_No_MODULES_x_CRATE)) >= 100) Commands->barProgressValue = 100;
					else Commands->barProgressValue += (100 / MAX_No_MODULES_x_CRATE);
					ip = Marshal::StringToHGlobalAnsi(device + ":" + line + ":" + j + ":isModuleGood");  //cmd: ISEG:5230225:$line:j:isModuleGood 
					mod = static_cast<const char*>(ip.ToPointer());
					ca_search(mod, &modID);
					ip = Marshal::StringToHGlobalAnsi(device + ":" + line + ":" + j + ":ChannelNumber");  //cmd: ISEG:5230225:$line:j:ChannelNumber
					mod = static_cast<const char*>(ip.ToPointer());
					ca_search(mod, &modID2);
					status = ca_pend_io(MAX_WAIT_CA_TIME);
					ca_put(DBR_STS_STRING, modID, &strModStatus);
					ca_get(DBR_STS_STRING, modID, &strModStatus);
					ca_put(DBR_SHORT, modID2, &chnlCount);
					ca_get(DBR_SHORT, modID2, &chnlCount);
					status = ca_pend_io(MAX_WAIT_CA_TIME);
					if (status == ECA_NORMAL) {
						channelsNumber += chnlCount;
						modNumber++;
					}
				}
				Commands->returnValue1 = modNumber;
				Commands->returnValue2 = channelsNumber;				
			}
			Marshal::FreeHGlobal(ip);
		}
		return (statusComm== ECA_NORMAL);
	}

	bool CaInterface::Add_Crate(String^ crateToAdd)
	{
		//throw gcnew System::NotImplementedException();
		chid modChnlNmbrID, modID;
		dbr_sts_string	strCrateStatus, strModStatus;
		unsigned long ulModStatus;
		short crateNumber, modNumber, channelsNumber=0, chnlCount, line, CrateNumber, totalChnls;
		int status;
		char cCrtaeStatus[40];
		bool connected = false, returnValue = false;

		ca_task_initialize();
		
		IntPtr ip = Marshal::StringToHGlobalAnsi(crateToAdd + ":Status");  //cmd: ISEG:5230225:Status
		const char* mod = static_cast<const char*>(ip.ToPointer());
		Console::ForegroundColor = ConsoleColor::White;
		Console::WriteLine("Searching for crate: ... " + crateToAdd);
		status = getCrateLine(crateToAdd, &line, &crateNumber);
		char errorStatus[40];
		chtype chnlDataType;
		/* Check for errors */
		switch (status)
		{
		case ECA_NORMAL:
			Crate^ ptrCrate;
			
			ptrCrate = gcnew Crate();
			Commands->deviceCmd = crateToAdd;
			ptrCrate->Name = crateToAdd;
			ptrCrate->Address = line.ToString();
			CaInterface::getCrateCnf(ptrCrate, crateNumber, line);
			
			modNumber = totalChnls = 0;
			//Commands->barProgressValue = 5;
			Console::ForegroundColor = ConsoleColor::White;
			Console::WriteLine("Detecting modules conf... ");
			for (int j = 0; j < MAX_No_MODULES_x_CRATE; j++) {
				Commands->barProgressValue += (100 / MAX_No_MODULES_x_CRATE / Commands->progressRate);
				chnlCount = channelsNumber = 0; 
				ip = Marshal::StringToHGlobalAnsi(crateToAdd + ":" + line + ":" + j + ":Status");  //cmd: ISEG:5230225:0:$mod$:Status => module status
				mod = static_cast<const char*>(ip.ToPointer());
				ca_search(mod, &modID);
				
				ip = Marshal::StringToHGlobalAnsi(crateToAdd + ":" + line + ":" + j + ":ChannelNumber");  //cmd: ISEG:5230225:0:j:ChannelNumber => mod channel number
				mod = static_cast<const char*>(ip.ToPointer());
				ca_search(mod, &modChnlNmbrID);
				status = ca_pend_io(MAX_WAIT_CA_TIME);
				chnlDataType = ca_field_type(modID);
				chnlDataType = ca_field_type(modChnlNmbrID);
				status = ca_put(DBR_LONG, modID, &ulModStatus);
				status = ca_get(DBR_LONG, modID, &ulModStatus);
				status = ca_pend_io(MAX_WAIT_CA_TIME);
				if (status == ECA_NORMAL) {
					// Module found => create modObject and search for its channels
					Console::ForegroundColor = ConsoleColor::White;
					Console::WriteLine("Module {0} ... found", j);
					Module^ ptrMod;
					ptrMod = gcnew Module();
					CaInterface::getModCnf(ptrMod, line, j);
					modNumber++; 
					int chnlsEnable = 0;
					for (int z = 0; ((z < MAX_No_CHANNELS_x_MOD) && (status == ECA_NORMAL)); z++) {
						// Iterate searching channels and add each found to chnlsList in crateObject->modObject
						// Checking if channel exists
						int k = 0; status = !ECA_NORMAL;
						ip = Marshal::StringToHGlobalAnsi(crateToAdd + ":" + line + ":" + j + ":" + z + ":Status");  //cmd: ISEG:5230225:0:$j-mod$:$channel$:Status => channel status
						mod = static_cast<const char*>(ip.ToPointer());
						while ((status != ECA_NORMAL) && (k < MAX_CONN_ITER_NMBR)) {
							ca_search(mod, &modID);
							status = ca_pend_io(MAX_WAIT_CA_TIME);
							k++;
						}
						if (status == ECA_NORMAL) {
							Channel^ ptrChnl;
							ptrChnl = gcnew Channel();
							ptrChnl->Name = ptrCrate->Name + ":" + line + ":" + j + ":" + z;
							channelsNumber++;
							CaInterface::getChnlCnf(ptrChnl, line, j, z);
							ptrChnl->Name = ptrCrate->Name + ":" + line + ":" + j + ":" + z;
							ptrMod->lstChannels->Add(ptrChnl);
							if (ptrChnl->Enable) chnlsEnable++;
						}
					}
					
					// Add mod to modList in crateObject
					ptrMod->Channels = channelsNumber;
					ptrCrate->VoltChnlsEnable += chnlsEnable;
					if (chnlsEnable > 0) 
						ptrMod->Enable = true;
					Console::ForegroundColor = ConsoleColor::White;
					Console::WriteLine("\nChannels detected this Mod: {0} ", channelsNumber);
					totalChnls += channelsNumber;
					ptrMod->Name = ptrCrate->Name + ":" + line + ":" + j;
					ptrCrate->m_lstModules->Add(ptrMod);
				}
			}
			ptrCrate->Channels = totalChnls;
			ptrCrate->Modules = modNumber;
			ptrCrate->Enable = true;
			m_ptrCrateMainList->Add(ptrCrate);
			returnValue = true;
			Console::ForegroundColor = ConsoleColor::White;
			Console::WriteLine("Channels detected this Crate: {0} ", totalChnls);
			//Commands->execRequest = false;
			//Commands->cmdType = 0;
			//Commands->deviceCmd = "";
			////Commands->barProgressValue = 0;
			//Commands->cmdExecuted = true;
			//Commands->cmdResult = COMM_OK;
			Console::ForegroundColor = ConsoleColor::White;
			Console::WriteLine("Crate " + crateToAdd + "... Ok");
			break;
		case ECA_TIMEOUT:
			Commands->cmdResult = COMM_FAIL;
			Console::ForegroundColor = ConsoleColor::DarkYellow;
			Console::WriteLine("Crate " + crateToAdd + " not detected");
			break;
		default:;
			//	ca_message(status));
		}
		Marshal::FreeHGlobal(ip);
		return (returnValue);
	}

	void CaInterface::getModCnf(Module^ ptrMod, int line, int modDir)
	{
		int status;
		Module ModObj ;
		char membersValues[MOD_CMDS_NMBR][40];
		char strCmd[40] = { "" };
		chtype chnlDataType;

		//throw gcnew System::NotImplementedException();
		Console::ForegroundColor = ConsoleColor::White;
		Console::WriteLine("Trying adding a Module... ");
		if (ptrMod == nullptr) return;
		//ca_task_initialize();
		String^ baseCmd(Commands->deviceCmd + ":" + line + ":" + modDir);   //cmd: ISEG:5230225:$line$:$modDir$
		IntPtr ip = Marshal::StringToHGlobalAnsi(baseCmd);
		const char* mod = static_cast<const char*>(ip.ToPointer());
		strcpy(strCmd, mod);
		strcat(strCmd, ModConfCmds[0].strCmd);
		ca_search(strCmd, &ModConfCmds[0].channelID);
		status = ca_pend_io(MAX_WAIT_CA_TIME);
		chnlDataType = ca_field_type(ModConfCmds[0].channelID);
		ca_put(ModConfCmds[0].channelDataType, ModConfCmds[0].channelID, &membersValues[0]);
		ca_get(ModConfCmds[0].channelDataType, ModConfCmds[0].channelID, &membersValues[0]);
		status = ca_pend_io(MAX_WAIT_CA_TIME);
		ip = Marshal::StringToHGlobalAnsi(baseCmd);  
		mod = static_cast<const char*>(ip.ToPointer());
		if (Commands->doCaSearch) {
			for (int k = 0; k < MOD_CMDS_NMBR; k++) {
				strcpy(strCmd, mod);
				strcat(strCmd, ModConfCmds[k].strCmd);
				ca_search(strCmd, &ModConfCmds[k].channelID);
			}
			status = ca_pend_io(MAX_WAIT_CA_TIME);
			for (int k = 0; k < MOD_CMDS_NMBR; k++) {
				strcpy(strCmd, mod);
				strcat(strCmd, ModConfCmds[k].strCmd);
				String^ str = gcnew String(strCmd);
				ChId^ chnlID = gcnew ChId;
				chnlID->chnlID = ModConfCmds[k].channelID;
				auto it = ptrMod->pModCmdsTableId->insert(CmdsId::make_value(str, chnlID));
				ModConfCmds[k].channelDataType = ca_field_type(ModConfCmds[k].channelID);
			}
			status = ca_pend_io(MAX_WAIT_CA_TIME);
		}
		for (int k = 0; k < MOD_CMDS_NMBR; k++) {
			status = ca_put(ModConfCmds[k].channelDataType, ModConfCmds[k].channelID, &membersValues[k]);
			status = ca_get(ModConfCmds[k].channelDataType, ModConfCmds[k].channelID, &membersValues[k]);
		}
		status = ca_pend_io(MAX_WAIT_CA_TIME);
		strcpy(membersValues[11], "0.1");
		Double vRamp;
		status = ca_put(DBR_STRING, ModConfCmds[11].channelID, &membersValues[11]);
		status = ca_get(DBR_DOUBLE, ModConfCmds[11].channelID, &vRamp);
		status = ca_pend_io(MAX_WAIT_CA_TIME);
		ip = Marshal::StringToHGlobalAnsi(vRamp.ToString());
		mod = static_cast<const char*>(ip.ToPointer());
		strcpy(membersValues[11], mod);
		if (modDir == 1)
			Console::WriteLine(" Voltage Ramp: {0}: ", System::Convert::ToString(membersValues[11]));
		switch (status)
		{
		case ECA_NORMAL:
			Commands->cmdResult = COMM_OK;
			break;
		default:
			Commands->cmdResult = COMM_FAIL;
		}
		setAllModMmbrs(ptrMod, membersValues, modDir);
		Marshal::FreeHGlobal(ip);
	}

	void CaInterface::setAllModMmbrs(Module^ ptrMod, char mmbersValues[][40], int modDir)
	{
		//throw gcnew System::NotImplementedException();
		ptrMod->Address = System::Convert::ToString(modDir);                    // modDir = $mod$
		//ptrMod->Channels = System::Convert::ToUInt16(mmbersValues[1][0]);
		String^ Channels = gcnew System::String((char*)mmbersValues[1]);
		String^ FirmwareRelease = gcnew System::String((char*)mmbersValues[2]);
		ptrMod->FirmwareRelease = FirmwareRelease;
		String^ FirmwareName = gcnew System::String((char*)mmbersValues[3]);
		ptrMod->FirmwareName = FirmwareName;
		String^ Article = gcnew System::String((char*)mmbersValues[4]);
		ptrMod->Article = Article;
		String^ VoltageLimit = gcnew System::String((char*)mmbersValues[5]);
		ptrMod->VoltageLimit = VoltageLimit;
		String^ VoltageLimitNegative = gcnew System::String((char*)mmbersValues[6]);
		ptrMod->VoltageLimitNegative = VoltageLimitNegative;
		String^ CurrentLimit = gcnew System::String((char*)mmbersValues[7]);
		ptrMod->CurrentLimit = CurrentLimit;
		String^ Temperature = gcnew System::String((char*)mmbersValues[8]);
		ptrMod->Temperature = Temperature;
		String^ SerialNumber = gcnew System::String((char*)mmbersValues[9]);
		ptrMod->SerialNumber = SerialNumber;
		String^ DigitalFilter = gcnew System::String((char*)mmbersValues[9]);
		ptrMod->DigitalFilter = DigitalFilter;
	}

	void CaInterface::getCrateCnf(Crate^ ptrCrate, int crateNmbr, int crtDir)
	{
		//throw gcnew System::NotImplementedException();
		chid cID;
		int status;
		Module ModObj;
		char membersValues[CRATE_CMDS_NMBR][40];
		char strCmd[40] = {""}, cAux[40], cCrateList[40];
		//throw gcnew System::NotImplementedException();
		if (ptrCrate == nullptr) return;
		//ca_task_initialize();
		String^ baseCmd(Commands->deviceCmd);
		IntPtr ip = Marshal::StringToHGlobalAnsi(baseCmd);
		const char* crate = static_cast<const char*>(ip.ToPointer());
		if (Commands->doCaSearch) {
			for (int k = 0; k < CRATE_CMDS_NMBR; k++) {
				strcpy(strCmd, crate);
				if (CrateConfCmds[k].cmdParamNmbr==2) {
					strcat(strCmd, ":");
					strcat(strCmd, itoa(crtDir,cAux,10));
					strcat(strCmd, ":");
					strcat(strCmd, itoa(crateNmbr, cAux, 10));
				}
				strcat(strCmd, CrateConfCmds[k].strCmd);
				ca_search(strCmd, &CrateConfCmds[k].channelID);
				//status = ca_pend_io(MAX_WAIT_CA_TIME);
			}
			status = ca_pend_io(MAX_WAIT_CA_TIME);
			for (int k = 0; k < CRATE_CMDS_NMBR; k++) {
				strcpy(strCmd, crate);
				if (CrateConfCmds[k].cmdParamNmbr == 2) {
					strcat(strCmd, ":");
					strcat(strCmd, itoa(crtDir, cAux, 10));
					strcat(strCmd, ":");
					strcat(strCmd, itoa(crateNmbr, cAux, 10));
				}
				strcat(strCmd, ChnlConfCmds[k].strCmd);
				String^ str = gcnew String(strCmd);
				ChId^ chnlID = gcnew ChId;
				chnlID->chnlID = ChnlConfCmds[k].channelID;
				auto it = ptrCrate->pCrateCmdsTableId->insert(CmdsId::make_value(str, chnlID));
			}
		}
		for (int k = 0; k < CRATE_CMDS_NMBR; k++) {
			ca_put(CrateConfCmds[k].channelDataType, CrateConfCmds[k].channelID, &(membersValues[k]));
			ca_get(CrateConfCmds[k].channelDataType, CrateConfCmds[k].channelID, &(membersValues[k]));
			//status = ca_pend_io(MAX_WAIT_CA_TIME);
		}
		status = ca_pend_io(MAX_WAIT_CA_TIME);
		switch (status)
		{
		case ECA_NORMAL:
			Commands->cmdResult = COMM_OK;
			break;
		default:
			Commands->cmdResult = COMM_FAIL;
		}
		setAllCrateMmbrs(ptrCrate, membersValues, crtDir);
		Marshal::FreeHGlobal(ip);
	}

	void CaInterface::setAllCrateMmbrs(Crate^ ptrCrate, char mmbersValues[][40], int crateDir)
	{
		//throw gcnew System::NotImplementedException();
		const char cAux[40] = { ""};

		ptrCrate->Address = System::Convert::ToString(crateDir);                // crateDir = $line$
		String^ CrateNumber = gcnew System::String((char*)mmbersValues[1]);
		ptrCrate->CrateNumber = (int)System::Convert::ToDecimal(CrateNumber);
		String^ ModuleNumber = gcnew System::String((char*)mmbersValues[2]);
		ptrCrate->ModuleNumber = (int)System::Convert::ToDecimal(ModuleNumber);
		String^ FirmwareRelease = gcnew System::String(( char *)mmbersValues[3]);
		ptrCrate->FirmwareRelease = FirmwareRelease;
		String^ FirmwareName = gcnew System::String(( char*)mmbersValues[4]);
		ptrCrate->FirmwareName = FirmwareName;
		String^ Article = gcnew System::String(( char*)mmbersValues[5]);
		ptrCrate->Article = Article;
		String^ FanSpeed = gcnew System::String(( char*)mmbersValues[6]);
		ptrCrate->FanSpeed = FanSpeed;
		String^ SerialNumber = gcnew System::String(( char*)mmbersValues[7]);
		ptrCrate->SerialNumber = SerialNumber;
		String^ PowerOn = gcnew System::String(( char*)mmbersValues[8]);
		ptrCrate->PowerOn = PowerOn;
		
	}

	int CaInterface::getChnlCnf(Channel^ ptrChnl, int line, int mod, int chnl)
	{
		//throw gcnew System::NotImplementedException();
		int status;
		char membersValues[CHNLS_CMDS_NMBR][40];
		double doubMembersValues[CHNLS_CMDS_NMBR+2]; // + 2 couse of VltgRamp & CrrntRamp which actually depend on a module cmd
		int intMembersValues[CHNLS_CMDS_NMBR];
		char strCmd[40] = { "" };
		dbr_time_double chnlStatus;
		chtype channelsDT[MAX_CONF_CMDS_NMBR];
		double voltageMeasurement;
				
		//throw gcnew System::NotImplementedException();
		Console::ForegroundColor = ConsoleColor::White;
		Console::WriteLine("\nGetting channel {0} conf... Status: ", chnl);
		if (ptrChnl == nullptr) return 0;
		ca_task_initialize();
		String^ baseCmd(Commands->deviceCmd + ":" + line + ":" + mod + ":" + chnl);   //cmd: ISEG:5230225:$crateLine$:$mod$:$chnl$:Cmd
		IntPtr ip = Marshal::StringToHGlobalAnsi(baseCmd);
		const char* channel = static_cast<const char*>(ip.ToPointer());
		// For RAMP SPEED depending on module
		chid voltRampSpeedID, crrntRampSpeedID;
		double vltgRampValue, crrntRampValue;
		bool setRampOn;
		// End RAMP speed
		if (Commands->doCaSearch) {
			// Get channels Id
			for (int k = 0; k < (CHNLS_CMDS_NMBR-2); k++) {
				// Search for all channels IOC id
				strcpy(strCmd, channel);
				strcat(strCmd, ChnlConfCmds[k].strCmd);
				ca_search(strCmd, &ChnlConfCmds[k].channelID);
			}
			// Special treament for RAMP because they are module commands
			baseCmd = (Commands->deviceCmd + ":" + line + ":" + mod);
			ip = Marshal::StringToHGlobalAnsi(baseCmd);
			channel = static_cast<const char*>(ip.ToPointer());
			strcpy(strCmd, channel);
			strcat(strCmd, ModConfCmds[11].strCmd);
			status = ca_search(strCmd, &ChnlConfCmds[CHNLS_CMDS_NMBR-2].channelID);
			strcpy(strCmd, channel);
			strcat(strCmd, ModConfCmds[12].strCmd);
			status &= ca_search(strCmd, &ChnlConfCmds[CHNLS_CMDS_NMBR-1].channelID);
			status &= ca_pend_io(MAX_WAIT_CA_TIME);
			if (mod == 1 && chnl == 0) {
				chnlValues2 = chnlValues;
				voltageMeasurement = chnlValues.voltMeasure;
			}
			Console::Write("Searched: {0} ", status);
			// End Special
			baseCmd = (Commands->deviceCmd + ":" + line + ":" + mod + ":" + chnl);   //cmd: ISEG:5230225:$crateLine$:$mod$:$chnl$:Cmd
			ip = Marshal::StringToHGlobalAnsi(baseCmd);
			const char* channel = static_cast<const char*>(ip.ToPointer()); 
			// Insert chnnels Ids and its cmds in a table
			for (int i = 0; i < (CHNLS_CMDS_NMBR-2); i++) {
				strcpy(strCmd, channel);
				strcat(strCmd, ChnlConfCmds[i].strCmd);
				String^ str = gcnew String(strCmd);
				ChId^ chnlID = gcnew ChId;
				chnlID->chnlID = ChnlConfCmds[i].channelID;
				auto it = ptrChnl->ChnlCmdsTableId->insert(CmdsId::make_value(str, chnlID));
			}
			baseCmd = (Commands->deviceCmd + ":" + line + ":" + mod);
			ip = Marshal::StringToHGlobalAnsi(baseCmd);
			channel = static_cast<const char*>(ip.ToPointer());
			strcpy(strCmd, channel);
			strcat(strCmd, ModConfCmds[11].strCmd);
			String^ str = gcnew String(strCmd);
			ChId^ chnlID = gcnew ChId;
			chnlID->chnlID = ChnlConfCmds[CHNLS_CMDS_NMBR-2].channelID;
			auto it = ptrChnl->ChnlCmdsTableId->insert(CmdsId::make_value(str, chnlID));
			strcpy(strCmd, channel);
			strcat(strCmd, ModConfCmds[12].strCmd);
			str = gcnew String(strCmd);
			chnlID = gcnew ChId;
			chnlID->chnlID = ChnlConfCmds[CHNLS_CMDS_NMBR-1].channelID;
			it = ptrChnl->ChnlCmdsTableId->insert(CmdsId::make_value(str, chnlID));
			for (int k = 0; k < CHNLS_CMDS_NMBR; k++) {
				// Get all IOC data types for all channels
				ChnlConfCmds[k].channelDataType = ca_field_type(ChnlConfCmds[k].channelID);
			}
			status = ca_pend_io(MAX_WAIT_CA_TIME);
			Console::Write(" Type: {0} ", status);
		}
		baseCmd = (Commands->deviceCmd + ":" + line + ":" + mod + ":" + chnl);   //cmd: ISEG:5230225:$crateLine$:$mod$:$chnl$:Cmd
		ip = Marshal::StringToHGlobalAnsi(baseCmd);
		channel = static_cast<const char*>(ip.ToPointer());
		for (int k = 0; k < (CHNLS_CMDS_NMBR-2); k++) {
			// Depending on channel type, send cmd to read directly or two cmds to prepare values and then read
			strcpy(strCmd, channel);
			strcat(strCmd, ChnlConfCmds[k].strCmd);
			String^ str = gcnew String(strCmd);
			auto it = ptrChnl->ChnlCmdsTableId->find(str);
			if (it != ptrChnl->ChnlCmdsTableId->end()) {
				auto ref = *it;
				if (ChnlConfCmds[k].cmdType == READ)
					status = ca_put(ChnlConfCmds[k].channelDataType, ref->second->chnlID, ChnlConfCmds[k].ptrData);
				status = ca_get(ChnlConfCmds[k].channelDataType, ref->second->chnlID, &doubMembersValues[k]);
			}
		}
		
		status = ca_pend_io(MAX_WAIT_CA_TIME);
		if (mod == 1 && chnl == 0) {
			chnlValues2 = chnlValues;
			voltageMeasurement = chnlValues.voltMeasure;
		}
		baseCmd = (Commands->deviceCmd + ":" + line + ":" + mod);
		ip = Marshal::StringToHGlobalAnsi(baseCmd);
		channel = static_cast<const char*>(ip.ToPointer());
		strcpy(strCmd, channel);
		strcat(strCmd, ChnlConfCmds[CHNLS_CMDS_NMBR - 2].strCmd);
		String^ str = gcnew String(strCmd);
		auto it = ptrChnl->ChnlCmdsTableId->find(str);
		if (it != ptrChnl->ChnlCmdsTableId->end()) {
			auto ref = *it;
			char strVRamp[40] = { "0.10" };
			if (Commands->doCaSearch) status = ca_put(DBR_STRING, ref->second->chnlID, strVRamp);
			status = ca_get(DBR_DOUBLE, ref->second->chnlID, &doubMembersValues[CHNLS_CMDS_NMBR - 2]);
		}
		strcpy(strCmd, channel);
		strcat(strCmd, ChnlConfCmds[CHNLS_CMDS_NMBR-1].strCmd);
		str = gcnew String(strCmd);
		it = ptrChnl->ChnlCmdsTableId->find(str);
		if (it != ptrChnl->ChnlCmdsTableId->end()) {
			auto ref = *it;
			char strIRamp[40] = { "0.10" };
			if (Commands->doCaSearch) status = ca_put(DBR_STRING, ref->second->chnlID, strIRamp);
			status = ca_get(DBR_DOUBLE, ref->second->chnlID, &doubMembersValues[CHNLS_CMDS_NMBR - 1]);
		}
		status = ca_pend_io(MAX_WAIT_CA_TIME);
		Console::Write(" Conf: {0} ", status);
		
		if (mod == 1 && chnl == 0)
			chnlValues2 = chnlValues;
		// End for testing purposes
		setAllChnlMmbrs(ptrChnl, doubMembersValues, mod, chnl);
		Marshal::FreeHGlobal(ip);
		Console::Write(" Enable: {0} ", System::Convert::ToByte(ptrChnl->Enable));
		if (ptrChnl->Enable) return 1;
		return 0;
	}

	void CaInterface::setAllChnlMmbrs(Channel^ ptrchnl, double * chnlValues, int modDir, int chnlDir)
	{
		//throw gcnew System::NotImplementedException();
		ptrchnl->Address = System::Convert::ToString(chnlDir); // chnlDir = $channel$
		chnlValues[1] = Math::Round(chnlValues[1], 2);
		String^ VoltageMeasure = chnlValues[1].ToString();
		ptrchnl->VoltageMeasure = VoltageMeasure;
		chnlValues[2] = Math::Round(chnlValues[2], 2);
		ptrchnl->CurrentMeasure = chnlValues[2].ToString(); //CurrentMeasure;
		ptrchnl->VoltageNominal = chnlValues[3].ToString();
		ptrchnl->CurrentNominal = chnlValues[4].ToString();
		if ((chnlValues[3] != 0) && ((chnlValues[4] != 0))) ptrchnl->Enable = true;
		//ptrchnl->Enable = true; // This line is to Just test if Wiener mod works but NOT luck
		ptrchnl->IsOn = chnlValues[15].ToString();
		chnlValues[7] = Math::Round(chnlValues[7], 2);
		ptrchnl->VoltageSet = chnlValues[7].ToString("f");
		chnlValues[8] = Math::Round(chnlValues[8], 8);
		ptrchnl->CurrentSet = chnlValues[8].ToString("G3");
		if (modDir == 1 && chnlDir == 0)
			Console::Write(" Ramp values {0}  -  {1}", chnlValues[CHNLS_CMDS_NMBR-2], chnlValues[CHNLS_CMDS_NMBR-1]);
		double d = (chnlValues[3] * chnlValues[CHNLS_CMDS_NMBR-2] / 100);
		ptrchnl->VltgRamp = d.ToString();
		d = (chnlValues[4] * chnlValues[CHNLS_CMDS_NMBR-1] / 100);
		ptrchnl->CrrntRamp = d.ToString();
		
	}

	void CaInterface::DecodeCmdMsg(String^ cmd, int* crateDir, int* crateLine, int* mod, int* chnl, int* type)
	{
		//throw gcnew System::NotImplementedException();
		System::Array^ strCrate = cmd->Split(':');
		
		*type = 1;
		String^ strCrateName = gcnew String((System::String^) strCrate->GetValue(0) + ":" +
			(System::String^) strCrate->GetValue(1));
		int index = -1, i = 0;
		for each (Crate ^ elem in m_ptrCrateMainList) {
			if (elem->Name == strCrateName) {
				index = i;
				break;
			}
			else i++;
		}
		*crateDir = index;
		int elmNmbr = strCrate->Length;
		if (!int::TryParse((System::String^) strCrate->GetValue(2), *crateLine))
			return;
		if (!int::TryParse((System::String^) strCrate->GetValue(3), *mod))
			return;
		*type = 2;
		if (!int::TryParse((System::String^) strCrate->GetValue(4), *chnl))
			return;
		*type = 3;
		return;
	}

	int CaInterface::GetChnlType(String^ cmd, CmdsT* cmdTable, int tableSize)
	{
		int chnlType = -1;
		for (int i = 0; i < tableSize; i++) {
			{
				String^ str = gcnew String(cmdTable[i].strCmd);
				if (cmd->Contains(str)) {
					chnlType = cmdTable[i].channelDataType;
					break;
				}
			}
		}
		return chnlType;
	}

	System::Int16 CaInterface::FreqCmdsMgr(double* doubArray, double* doubArray2, char isOnArray[][40], System::String^ cmd, int index, bool sendCmds)
	{
		int crateDir, crateLine, mod, chnl, type;

		if (!sendCmds) {
			DecodeCmdMsg(cmd, &crateDir, &crateLine, &mod, &chnl, &type);
			String^ chnl = GetChnlName(cmd);
			if (chnl != nullptr) {
				auto it = pMainDataStruct->GetChnlObj(chnl)->ChnlCmdsTableId[cmd];
				if (doubArray != nullptr) {
					ca_put(DBR_DOUBLE, it->chnlID, &doubArray[index]);
					ca_get(DBR_DOUBLE, it->chnlID, &doubArray[index]);
				}
				else if (doubArray2 != nullptr) {
					ca_put(DBR_DOUBLE, it->chnlID, &doubArray2[index]);
					ca_get(DBR_DOUBLE, it->chnlID, &doubArray2[index]);
				}
				else if (isOnArray != nullptr) {
					ca_get(DBR_STRING, it->chnlID, &(isOnArray[index]));
				}
			}
			else return false;
		}
		else return( ca_pend_io(MAX_WAIT_CA_TIME));

		return 0;
	}

	System::Int16 CaInterface::FreqCmdsMgrSP(double* doubArray, double* doubArray2, char isOnArray[][40], System::String^ cmd, int index, bool sendCmds)
	{
		int crateDir, crateLine, mod, chnl, type;

		if (!sendCmds) {
			DecodeCmdMsg(cmd, &crateDir, &crateLine, &mod, &chnl, &type);
			String^ chnl = GetChnlName(cmd);
			if (chnl != nullptr) {
				auto it = pMainDataStruct->GetChnlObj(chnl)->ChnlCmdsTableId[cmd];
				if (doubArray != nullptr) {
					ca_get(DBR_DOUBLE, it->chnlID, &doubArray[index]);
				}
				else if (doubArray2 != nullptr) {
					ca_get(DBR_DOUBLE, it->chnlID, &doubArray2[index]);
				}
				else if (isOnArray != nullptr) {
					ca_get(DBR_STRING, it->chnlID, &(isOnArray[index]));
				}
			}
			else return false;
		}
		else return(ca_pend_io(MAX_WAIT_CA_TIME));

		return 0;
	}
	
	String^ CaInterface::GetCrateName(String^ chnl)
	{
		// TODO: insert return statement here
		System::Array^ strCrate = chnl->Split(':');
		if (strCrate->Length > 1) {
			String^ strCrateName = gcnew String((System::String^) strCrate->GetValue(0) + ":" +
				(System::String^) strCrate->GetValue(1));
			return strCrateName;
		}
		else return nullptr;
	}

	String^ CaInterface::GetModName(String^ chnl)
	{
		// TODO: insert return statement here
		System::Array^ strCrate = chnl->Split(':');
		if (strCrate->Length > 3) {
			String^ strCrateName = gcnew String((System::String^) strCrate->GetValue(0) + ":" +
				(System::String^) strCrate->GetValue(1) + ":" +
				(System::String^) strCrate->GetValue(2) + ":" +
				(System::String^) strCrate->GetValue(3));
			return strCrateName;
		}
		else return nullptr;
	}

	String^ CaInterface::GetChnlName(String^ chnl)
	{
		// TODO: insert return statement here
		System::Array^ strCrate = chnl->Split(':');
		if (strCrate->Length > 4) {
			String^ strCrateName = gcnew String((System::String^) strCrate->GetValue(0) + ":" +
				(System::String^) strCrate->GetValue(1) + ":" +
				(System::String^) strCrate->GetValue(2) + ":" +
				(System::String^) strCrate->GetValue(3) + ":" +
				(System::String^) strCrate->GetValue(4));
			return strCrateName;
		}
		else return nullptr;
	}

	int CaInterface::getModIndex(List<Crate^>^ m_ptrCrateMainList, int crateDir, int mod)
	{
		int modIndex = -1;
		if ((m_ptrCrateMainList != nullptr) && (crateDir >= 0) && (mod >= 0)) {
			int nbrMod = m_ptrCrateMainList[crateDir]->m_lstModules->Count;
			for (int i = 0; i < nbrMod; i++) {
				if (System::Convert::ToInt32(m_ptrCrateMainList[crateDir]->m_lstModules[i]->Address) == mod) {
					modIndex = i;
					break;
				}
			}
		}
		return modIndex;
	}
