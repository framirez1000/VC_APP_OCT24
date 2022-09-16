#pragma once
#include <tchar.h>
#include <stdio.h>
#include <io.h>
#include "servprov.h"
#include "GlobalsHeader.h"
#define SAMPLE_TIME_mSEC 100
ref class SaveDataToFile
{
	HANDLE m_ClientPipe = nullptr;
	property HANDLE Pipe {
		HANDLE get() { return m_ClientPipe; }
		void set(HANDLE pipe) { m_ClientPipe = pipe; }
	}
public:	
	SaveDataToFile() {
		CrateClientPipe();
	}
	System::Void EntryPoint();
	System::Void CrateClientPipe();
};

