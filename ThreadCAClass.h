#pragma once
#using <System.dll>
#include "servprov.h"
#include "MainHeader.h"
#include <tchar.h>
#include <stdio.h>
#include <io.h>
#include "Crate.h"
#pragma once
#include <cliext/vector>
#include <cliext/map>
#include "CaInterfaceClass.h"
//#include "GlobalsHeader.h"
//#include "C:\Epics\base-3.16.2\include\cadef.h"

#define SAMPLE_TIME_mSEC 150
#define MAX_SAMPLE_TIME_mSEC_AT_FAILURE 5000
#define MAX_GUI_TIME_DOWN_SEC 9
#define CHECK_COMM_IO_TIME_MIN 6
#define COMM_FAILURE_TIME_SEC 5

//ref struct RegCmdStruct_T {
//	int row;
//	int col;
//	double vValue;
//	double iValue;
//	//String^ onStateValue;
//};
//typedef cliext::map<String^, RegCmdStruct_T^> FreqCmdsMapTable_T;


using namespace System;
using namespace std;
using namespace System::ComponentModel;
using namespace System::Runtime::InteropServices;


namespace Thread_CA {

	public ref class ThreadCAClass
	{
	private:
		Double^ valdDouble = 0.0;
		Double v;
		int status;
		Crate^ crateObject;
		List<Crate^>^ m_pCrateList;
		CaInterface^ m_ptrCA_Interface;
		SingletonCmmdClass^ m_Commands;
		HANDLE m_PipeClient = nullptr;
		FreqCmdsMapTable_T^ pMainFreqCmds;
		CratesT^ pMainDataStruct;

	public:
		ThreadCAClass(FreqCmdsMapTable_T^ pFreqCmds) {}
		ThreadCAClass(List<Crate^>^ ptrCrateMainList, CratesT^ mainDataStruct, CheckedList^ pHrwList , Crate^ MainCrate, FreqCmdsMapTable_T ^ pFreqCmds, CheckedList^ hrdwFailingList) 
		{
			crateObject = MainCrate;
			m_pCrateList = mainDataStruct->ptrMainCrateList;
			m_ptrCA_Interface = gcnew CaInterface(ptrCrateMainList, mainDataStruct);
			Commands = SingletonCmmdClass::Instance;
			pMainHrwList = pHrwList;
			pMainFreqCmds = gcnew FreqCmdsMapTable_T;
			pMainFreqCmds = pFreqCmds;
			m_HrdwFailingList = hrdwFailingList;
			pMainDataStruct = mainDataStruct;
		}
		/* Properties */
		property List<Crate^>^ CrateList {
			List<Crate^>^ get() { return m_pCrateList; }
			void set(List<Crate^>^ obj) { m_pCrateList = obj; }
		}
		property SingletonCmmdClass^ Commands {
			SingletonCmmdClass^ get() { return m_Commands; }
			void set(SingletonCmmdClass^ commandsSing) { m_Commands = commandsSing; }
		}
		property CaInterface^ CA_Interf {
			CaInterface^ get() { return m_ptrCA_Interface; }
			void set(CaInterface^ ptr_CA) { m_ptrCA_Interface = ptr_CA; }
		}
		property HANDLE Pipe {
			HANDLE get() { return m_PipeClient; }
			void set(HANDLE pipe) { m_PipeClient = pipe; }
		}
		property CheckedList^ pMainHrwList;
		property CheckedList^ m_HrdwFailingList;
		
		void ThreadCaEntryPoint();

	private: 
		System::Boolean CreateNamedPipeClient();
		System::Boolean TestPipeConn();
		System::Void UpdateLists();
		System::Boolean chnlHrwConnected(FreqCmdsMapTable_T::value_type cmd, CheckedList^ cmmFailCrates);
	    System::Void LogEventMsg(String^ msg);
		
	};
	
}
