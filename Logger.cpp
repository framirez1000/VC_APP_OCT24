#include "pch.h"
#include "Logger.h"

System::Void Logger::EntryPoint()
{
	String^ msg = gcnew String("");
	String^ fileName = "\\LOG\\Logs.csv";

	while (true) {
		System::Threading::Thread::Sleep(LOOP_TIME_mSEC);
		if (!connected) connected = this->ConnectMyPipe();    // Wait until client connects
		if (connected) {
			if (this->ReadFromPipe(msg)) {
				this->Write2File(msg);
				this->connected = false;
			}
		}
	}
	return System::Void();
}

System::Boolean Logger::ConnectMyPipe()
{
	if (!this->created) {
		mPipe = NULL;
		HANDLE hPipe = CreateNamedPipe(
			PIPE_LOGGER,             // pipe name 
			PIPE_ACCESS_DUPLEX,       // read/write access 
			PIPE_TYPE_MESSAGE |       // message type pipe 
			PIPE_READMODE_MESSAGE |   // message-read mode 
			PIPE_WAIT,                // blocking mode 
			PIPE_UNLIMITED_INSTANCES, // max. instances  
			BUFF_SIZE * mPipeSize,                  // output buffer size 
			BUFF_SIZE * mPipeSize,                  // input buffer size 
			0,                        // client time-out 
			NULL);                    // default security attribute
		mPipe = hPipe;
		if (hPipe != INVALID_HANDLE_VALUE) this->created = true;
	}
	if (mPipe != INVALID_HANDLE_VALUE) {
		BOOL   fConnected = false;
		if (GetLastError() == ERROR_NO_DATA) 
			DisconnectNamedPipe(mPipe);
		fConnected = ConnectNamedPipe(mPipe, NULL) ?
			TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
		int i = GetLastError();
		return fConnected;
	}
	return false;
}

System::Boolean Logger::ReadFromPipe(String^% msg)
{
	try {
		DWORD dwRead;
		char buffer[BUFF_SIZE*2];
		bool result = ReadFile(mPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL);
		String^ str = gcnew String(buffer);
		
		if (result && dwRead > 0) {
			if (str->Contains(MSG_LOGGER_HEADER)) {
				msg = str;
				return (true);
			}
			else {
				msg = "";
				return (false);
			}
		}
		else msg = "";
		return false;
	}
	catch (Exception^ e) {
		return false;
	}
	return System::Boolean();
}

System::Void Logger::Write2File(String^ msg)
{
	String^ fileName = "\\LOG\\Logs.csv";
	String^ substr = msg->Substring(6);
	//substr = String::Concat(substr, "\n");
	DateTime cpCurrentDateTime = DateTime::Now;
	String^ strTemp = cpCurrentDateTime.ToShortDateString();
	strTemp = String::Concat(strTemp, " ");
	strTemp = String::Concat(strTemp, cpCurrentDateTime.ToLongTimeString());
	try {
		//char buffer[BUFF_SIZE * 6];
		StreamWriter^ sw = gcnew StreamWriter(Directory::GetCurrentDirectory() + fileName, TRUE);
		//wchar_t strArray[1024 * 2]{}, * str = strArray;
		//str = (wchar_t*)Marshal::StringToHGlobalUni(strTemp+substr).ToPointer();
		//strcat(buffer, "\n");
		sw->WriteLine(strTemp + substr);
		sw->Close();
	}
	catch (Exception^ e) {
		;
		//Console::ForegroundColor = ConsoleColor::Yellow;
		//Console::WriteLine(strTemp + "Saving data... FAILED: file not found/Busy");
	}
		
	return System::Void();
}
