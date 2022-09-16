#include "pch.h"
#pragma once
#include <iostream>

#include "servprov.h"
#include "GlobalsHeader.h"
//#include "ThreadCAClass.h"
#include "Crate.h"
#include "MainForm.h"


using namespace System;
using namespace System::Threading;
using namespace Thread_CA;
using namespace System::Windows::Forms;


ref class ThreadTester;
public ref class ThreadTester {
public:
	ThreadTester() {}

	void ThreadFunction() {
		//str.Copy("Modify in thread");
		Globals::globalVar=L"From Thread: started .... and sleeping for 20 sec ..";
		std::cout << "Hello " ;
		//std::cout << Globals::globalVar->Substring(0);
		Console::WriteLine(Globals::globalVar->Substring(0));
		//System::Threading::Thread::Sleep(20000);
		for (int i = 0; i < 20; i++) {
			Globals::globalVar = "From Thread: time to die in sec .. " + (20 - i);
			System::Threading::Thread::Sleep(1000);
		}
		
	}
};
//int main(array<System::String ^> ^args)
//{
//    return 0;
//}

[STAThread]
int main() {
	Crate^ crateMainObject = gcnew Crate("ISEG","140.181.78.178");
	Globals::globalVar = gcnew String("Hello");
	
	//
	// Thread test     
	//
	/*
	ThreadTester^ threadTest = gcnew ThreadTester();
	ThreadStart^ threadDelegate = gcnew ThreadStart(threadTest, &ThreadTester::ThreadFunction);
	Thread^ newThread = gcnew Thread(threadDelegate);
	newThread->Start();
	*/

	//
	// Thread in charge of CA 
	//
	//ThreadCAClass^ threadCA = gcnew ThreadCAClass(crateMainObject);
	//ThreadStart^ threadDelegate = gcnew ThreadStart(threadCA, &ThreadCAClass::ThreadCaEntryPoint);
	//Thread^ newThread = gcnew Thread(threadDelegate);
	//newThread->Start();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Application::Run(gcnew CppCLRWinformsProjekt::Form1()); 
	Application::Run(gcnew CppCLRWinformsProjekt::MainForm(crateMainObject));
		
	return 0;
}

