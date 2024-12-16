#include "pch.h"
#include "SaveDataToFile.h"



using namespace System;
using namespace System::IO;
using namespace System::Runtime::Serialization;
using namespace System::Data;

System::Void SaveDataToFile::EntryPoint()
{
	char buffer[1024 * 16];
	DWORD dwRead;
	String^ fileName = "C:\\ProgramData\\VoltageControllerNew\\LOG\\textfile.csv";
	BOOL result;
	int erroNbr;
	
	if (Globals::consoleVerbose != 0) Console::WriteLine("Thread DataSaving created");
	while (true) {
		System::Threading::Thread::Sleep(SAMPLE_TIME_mSEC);
		
		/* Block in Pipe waiting for a msg */
		try {
			result = ReadFile(Pipe, buffer, sizeof(buffer) - 1, &dwRead, NULL);
			erroNbr = GetLastError();
		}
		catch (Exception^ e) {

		}
		if (dwRead > 0) {
			// Save data to a file
			String^ str = gcnew String(buffer);
			String^ substr = str->Substring(5);
			int msg_type = 0;
			if (str->Contains(MSG_DATA_HEADER) || str->Contains(MSG_CHNLS_NAMES_HEADER)) {
				// Opens a file and serializes the object into it in binary format.
				DateTime cpCurrentDateTime = DateTime::Now;
				String^ strTemp = cpCurrentDateTime.ToShortDateString();
				strTemp = String::Concat(strTemp, " ");
				strTemp = String::Concat(strTemp, cpCurrentDateTime.ToLongTimeString());
				try {
					StreamWriter^ sw = gcnew StreamWriter(fileName, TRUE);
					strcat(buffer, "\n");
					if (Globals::consoleVerbose != 0) Console::ForegroundColor = ConsoleColor::Blue;
					if (Globals::consoleVerbose != 0) Console::Write(strTemp + " Saving data...");
					sw->WriteLine(substr);
					if (Globals::consoleVerbose != 0) Console::WriteLine("Ok");
					sw->Close();
				}
				catch (Exception^ e) {
					if (Globals::consoleVerbose != 0) Console::ForegroundColor = ConsoleColor::Yellow;
					if (Globals::consoleVerbose != 0) Console::WriteLine(strTemp + "Saving data... FAILED: file not found/Busy");
				}
			}
			else
				if (str->Contains(MSG_FILE_NAME_HEADER))
					fileName = substr;	
				else if (str->Contains(MSG_LOGGER_HEADER)) {
					DateTime cpCurrentDateTime = DateTime::Now;
					String^ strTemp = cpCurrentDateTime.ToShortDateString();
					strTemp = String::Concat(strTemp, " ");
					strTemp = String::Concat(strTemp, cpCurrentDateTime.ToLongTimeString());
					try {
						StreamWriter^ sw = gcnew StreamWriter((Directory::GetCurrentDirectory() + "\\Log\\Logs.txt"), TRUE);
						strcat(buffer, "\n");
						//Console::ForegroundColor = ConsoleColor::Blue;
						//Console::Write(strTemp + " Saving data...");
						substr = str->Substring(7);
						sw->WriteLine(substr);
						//Console::WriteLine("Ok");
						sw->Close();
					}
					catch (Exception^ e) {
						//Console::ForegroundColor = ConsoleColor::Yellow;
						//Console::WriteLine(strTemp + "Saving data... FAILED: file not found/Busy");
					}
				}
		}
		else {
			DWORD dwError = GetLastError();
			if (!result && GetLastError() != ERROR_IO_PENDING) break;
		}

	}
	//return System::Void();
}

System::Void SaveDataToFile::CrateClientPipe()
{
	System::Threading::Thread::Sleep(SAMPLE_TIME_mSEC);
	Pipe = NULL;
	HANDLE pipe = CreateFile(PIPE_DATA_FILE,
							GENERIC_READ | GENERIC_WRITE, 
							0, 
							NULL, 
							OPEN_EXISTING, 
							0, NULL);
	//ConnectNamedPipe(pipe, NULL);
	if (pipe != INVALID_HANDLE_VALUE)
	{
		Pipe = pipe;
	}
	else {
		DWORD last_error;
		int error;
		while (pipe == INVALID_HANDLE_VALUE) {
			Sleep(1 * 1000);

			if (pipe != INVALID_HANDLE_VALUE)
			{
				break;
			}
			
			error = GetLastError();
			if (GetLastError() != ERROR_PIPE_BUSY)
			{
				_tprintf(TEXT("Could not open pipe. GLE=%d\n"), GetLastError());
				//return -1;
			}
			
			pipe = CreateFile(PIPE_DATA_FILE,
				GENERIC_READ | GENERIC_WRITE,
				0,
				NULL,
				OPEN_EXISTING,
				0, ///FILE_ATTRIBUTE_NORMAL,
				NULL);
			if(!WaitNamedPipe(PIPE_DATA_FILE, 20000))
			{
				printf("Could not open pipe: 20 second wait timed out.");
				return;
			}
		}
	}
	if (pipe != INVALID_HANDLE_VALUE)
	{
		Pipe = pipe;
	}
	
	return System::Void();
}
