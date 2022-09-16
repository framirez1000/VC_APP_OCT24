#pragma once
#include "ProgressDialog.h"

ref class ProgressDialogTask
{
public:
	ListTest_CLI_Project::ProgressDialog^ progressDialog;
	ProgressDialogTask(){}
	void EntryPoint() {
		
		progressDialog = gcnew ListTest_CLI_Project::ProgressDialog;
		if (progressDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{ 
			;
		}
	}
};

