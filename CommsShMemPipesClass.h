#define SEM_H
#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <io.h>
#include <iostream>
#include <cstring>
#include <sys/timeb.h>
#include <time.h>

#define READ_SH_MEM 1
#define WRITE_SH_MEM 2
#define SERVER_T 1
#define CLIENT_T 2
#define MAX_SEM_COUNT 1
#define BUF_SIZE 1024*9

//#define PIPE_COMM TEXT("\\\\.\\pipe\\CommPipe")
#define PIPE_COMM TEXT("\\\\.\\pipe\\CommPipe")
#define PIPE_THREAD TEXT("\\\\.\\pipe\\ThreadPipe")
#define SH_MEM_SEM TEXT("Global\MyShMemChannelsDataSem")
#define CMDS_SEM TEXT("Global\MyCmdsSem")
#define FREQ_CMDS_SEM TEXT("Global\FreqCmdsSem")
#define PIPE_SERVER_T 1
#define PIPE_CLIENT_T 2
#define READPIPE 1
#define WRITEPIPE 2
//TCHAR szName[] = TEXT("Global\\MyIOChannelsDataObject");
//TCHAR szMsg[] = TEXT("Message from COMM self process.");

using std::cout;
using namespace System;
using namespace System::Runtime::InteropServices; // Marshaling
ref class SemClass
{

private:
	HANDLE ghSemaphore;
public:
	SemClass() {
		ghSemaphore = NULL;
	}

	bool GetSem(LPCWSTR semName) {
		// Semaphor 
		DWORD dwWaitResult;
		ghSemaphore = CreateSemaphore(
			NULL,           // default security attributes
			MAX_SEM_COUNT,  // initial count
			MAX_SEM_COUNT,  // maximum count
			semName);

		// Critical shred mem processing
		dwWaitResult = WaitForSingleObject(
			ghSemaphore,   // handle to semaphore
			0L);           // zero-second time-out interval

		switch (dwWaitResult)
		{
			// The semaphore object was signaled.
		case WAIT_OBJECT_0:
			// TODO: Perform task
			//printf("Thread %d: wait succeeded\n", GetCurrentThreadId());
			break;
			// The semaphore was nonsignaled, so a time-out occurred.
		case WAIT_TIMEOUT:
			printf("Thread %d: wait timed out\n", GetCurrentThreadId());
			return false;
			break;
		}
		// End critical sh_mem processing
		return true;
	}

	bool  ReleaseSem() {
		// Release the semaphore when task is finished

		if (!ReleaseSemaphore(
			ghSemaphore,  // handle to semaphore
			1,            // increase count by one
			NULL))       // not interested in previous count
		{
			printf("ReleaseSemaphore error: %d\n", GetLastError());
			return false;
		}
		else;// printf("Semaphore released\n");
		return true;

	}

	void CloseSem() {
		if (ghSemaphore != NULL && ghSemaphore != INVALID_HANDLE_VALUE) {
			CloseHandle(ghSemaphore);
		}
	}
	//End semaphor section
	
	};

inline bool Create_SharedMem_Object(int type, TCHAR* shareMemName, HANDLE* hMapFileOut, LPCTSTR* pBuf) {
	HANDLE hMapFile;
	if (type == 1) { // Server mode
		hMapFile = CreateFileMapping(
			INVALID_HANDLE_VALUE,    // use paging file
			NULL,                    // default security
			PAGE_READWRITE,          // read/write access
			0,                       // maximum object size (high-order DWORD)
			BUF_SIZE,                // maximum object size (low-order DWORD)
			shareMemName);           // name of mapping object

		*hMapFileOut = hMapFile;
		if (hMapFile == NULL)
		{
			_tprintf(TEXT("Could not create file mapping object (%d).\n"), GetLastError());
			return false;
		}
		*pBuf = (LPTSTR)MapViewOfFile(hMapFile,   // handle to map object
			FILE_MAP_ALL_ACCESS,                 // read/write permission
			0,
			0,
			BUF_SIZE);

		if (*pBuf == NULL)
		{
			_tprintf(TEXT("Could not map view of file (%d).\n"), GetLastError());
			CloseHandle(hMapFile);
			*hMapFileOut = NULL;
			return false;
		}
		return true;
	}
	else {
		if (type == 2) { // Client mode
			hMapFile = OpenFileMapping(
				FILE_MAP_ALL_ACCESS,   // read/write access
				FALSE,                 // do not inherit the name
				shareMemName);               // name of mapping object

			*hMapFileOut = hMapFile;
			if (hMapFile == NULL)
			{
				_tprintf(TEXT("Could not open file mapping object (%d).\n"),
					GetLastError());
				return false;
			}

			*pBuf = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
				FILE_MAP_ALL_ACCESS,  // read/write permission
				0,
				0,
				BUF_SIZE);

			if (*pBuf == NULL)
			{
				_tprintf(TEXT("Could not map view of file (%d).\n"), GetLastError());
				CloseHandle(hMapFile);
				*hMapFileOut = NULL;
				return false;
			}
		}
		return true;
	}
	return false;
}
inline void DisconnectShMem(HANDLE* hMapFile, LPCTSTR pBuf) {
	UnmapViewOfFile(pBuf);
	CloseHandle(*hMapFile);
}

inline bool OnShMem(int action, LPCTSTR pBuf, TCHAR* pSzMsg, int sizeMsg) {
	try {
		if (action == 1) { // READ
			//MessageBox(NULL, *pBuf, TEXT("Process2"), MB_OK);
			//Console::WriteLine("MsgFromIO: "); Console::WriteLine(*pBuf);
			//String^ str(pBuf);
			String^ str = gcnew String(pBuf);
			//Console::WriteLine(str);
			CopyMemory((PVOID)pSzMsg, (TCHAR*)pBuf, str->Length * sizeof(TCHAR));
			//memcpy(pSzMsg, (TCHAR*)pBuf, sizeMsg );
			return true;
		}
		else {
			if (action == 2) { // WRITE
				int x = (_tcslen(pSzMsg) * sizeof(TCHAR));
				int y = sizeMsg * sizeof(TCHAR);
				CopyMemory((PVOID)pBuf, pSzMsg, x);
				//_getch();
				return true;
			}
		}
	}
	catch (Exception^ e) {
		return false;
	}
	return false;
}

namespace PipesFunc {
	//-- Create PIPE 26/01/23

	inline bool GetPipe(int type, LPCWSTR pipe, HANDLE* outPipe)
	{
		HANDLE hPipe = NULL;

		if ((*outPipe != NULL) && (*outPipe != INVALID_HANDLE_VALUE)) {
			DisconnectNamedPipe(*outPipe);
			CloseHandle(*outPipe);
		}
		if (type == 1) { // Server type
			hPipe = CreateNamedPipe(pipe,
				PIPE_ACCESS_DUPLEX, // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
				PIPE_TYPE_MESSAGE | PIPE_ACCESS_INBOUND | PIPE_NOWAIT,
				PIPE_UNLIMITED_INSTANCES,
				1024 * 16,
				1024 * 16,
				0,
				NULL);
		}
		else {
			if (type == 2) {// Client type
				hPipe = CreateFile(pipe,
					GENERIC_READ | GENERIC_WRITE,
					0,
					NULL,
					OPEN_EXISTING,//CREATE_NEW,//OPEN_ALWAYS
					0,
					NULL);
			}
		}
		if (hPipe == INVALID_HANDLE_VALUE)
		{
			_tprintf(TEXT("invalid pipe. GLE=%d\n"), GetLastError());
			String^ error1 = gcnew String("invalid pipe. GLE = " + GetLastError());
			*outPipe = hPipe;
			return (false);
		}

		/*if (GetLastError() != ERROR_PIPE_BUSY)
		{
			_tprintf(TEXT("Could not open pipe. GLE=%d\n"), GetLastError());
			return (false);
		}*/
		*outPipe = hPipe;
		return (true);
	}

	////
	//// -- Send/Receive PIPE 25/01/23
	////
	inline bool OnPipe(int action, HANDLE pipe, String^% msg)
	{
		//WriteFile(Pipe, message.c_str(), message.length(), &numWritten, NULL);
		//return( WaitNamedPipe(	Pipe, NMPWAIT_USE_DEFAULT_WAIT));
		//return (ReadFile(Pipe, buffer, sizeof(buffer) - 1, &dwRead, NULL));
		if (pipe != INVALID_HANDLE_VALUE) {
			bool result;
			if (action == 1) { // Read
				try {
					DWORD dwRead;
					char buffer[1024 * 6];
					result = ReadFile(pipe, buffer, sizeof(buffer) - 1, &dwRead, NULL);
					String^ str = gcnew String(buffer);
					//Console::ForegroundColor = ConsoleColor::White;
					if (result && dwRead > 0) {
						if (str->Contains("TEST")) {
							//m_cmdMsg->statusBarMsg2 = "Comm GUI -> IO... Ok ";
							//Console::WriteLine("Read OK Msg: " + str);
						}
						else {
							//m_cmdMsg->statusBarMsg2 = "Server received from Pipe: " + str;
							/*Console::WriteLine("Received length: " + dwRead);
							Console::WriteLine("");*/
						}
						msg = str;
						return (true);
					}
					else msg = "";
				}
				catch (Exception^ e) {

				}
			}
			else if (action == 2) { // Write
				try {
					DWORD numWritten;
					//String^ msg = gcnew String("TEST");
					IntPtr ip = Marshal::StringToHGlobalAnsi(msg);
					const char* stream = static_cast<const char*>(ip.ToPointer());
					if (WriteFile(pipe, stream, msg->Length + 1, &numWritten, FILE_FLAG_NO_BUFFERING & FILE_FLAG_WRITE_THROUGH)) {
						//Console::WriteLine("Sent Msg, length: " + numWritten.ToString());
					}
					else {
						return false;
						//Console::WriteLine("Sent unsuccessful: " + numWritten.ToString());
					}
					Marshal::FreeHGlobal(ip);
				}
				catch (Exception^ e) {
					//Console::ForegroundColor = ConsoleColor::Red;
					//Console::WriteLine("Error trying to Write on Comm Pipe");
					return false;
				}
				return (true);
			}
		}
		return false;
	}
}

// Next two functions are for simulating data purposes
inline String^ GetDateAndTime() {
	struct _timeb timebuffer;
	char timeline[26];
	errno_t err;
	time_t time1;
	unsigned short millitm1;
	short timezone1;
	short dstflag1;

	_ftime_s(&timebuffer);
	time1 = timebuffer.time;
	millitm1 = timebuffer.millitm;
	timezone1 = timebuffer.timezone;
	dstflag1 = timebuffer.dstflag;

	err = ctime_s(timeline, 26, &(timebuffer.time));
	char str[80];
	sprintf(str, " %.4s, %.10s, %.8s.%hu", &timeline[20], timeline, &timeline[11], timebuffer.millitm);
	String^ NewTime = gcnew String(str);
	return NewTime;
}
inline String^ GetChannelsData(int lengthData) {
	if (lengthData > 0) {
		String^ newData("");
		for (int i = 0; i < lengthData; i++) {
			newData += "Channel:" + i + ":0:0:" + i  + "&" + "Channel:" + i + "&" + GetDateAndTime() + ";";
		}
		newData += "\n";
		return newData;
	}
	return ("");
}

