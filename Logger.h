#pragma once
#include <tchar.h>
#include <stdio.h>
#include <io.h>
#include "GlobalsHeader.h"
#include <tchar.h>


#define LOOP_TIME_mSEC 25
#define BUFF_SIZE 1024



using namespace System::Runtime::InteropServices; // Marshaling

ref class Logger
{
	HANDLE m_ClientPipe = nullptr;
	property HANDLE mPipe {
		HANDLE get() { return m_ClientPipe; }
		void set(HANDLE pipe) { m_ClientPipe = pipe; }
	}
	property bool created;
	property bool connected;
	property short mPipeNameTableNumber;
	property short mPipeSize;
	property short mPipe_T;
public:
	Logger(short pipeNameTableNumber, short pipeSize, short pipe_T) {
		mPipeNameTableNumber = pipeNameTableNumber;
		mPipeSize = pipeSize;
		mPipe_T = pipe_T;
	}
	System::Void EntryPoint();
	System::Boolean ConnectMyPipe();          
	System::Boolean ReadFromPipe(String^% msg);
	System::Void Write2File(String^ msg, bool includeDate);
};

