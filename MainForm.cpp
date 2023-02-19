
#include "pch.h"
#include "MainForm.h"
#include <wtsapi32.h>
#pragma comment(lib, "Wtsapi32.lib")

System::Void CppCLRWinformsProjekt::MainForm::drawChnlsView(int rows, int columns, System::Object^ Sender, System::EventArgs^ e)
{
	ChnlViewForm^ pChnlViewItem;
	

	if (this->panel1->Controls->Count > 0) {
		this->panel1->Controls->Clear();
		pChnlsViewList.clear();
		pChnlsNames4formulas->Clear();
		DataFile.monitoredChnls.clear();
		m_cmdMsg->ViewActive = false;
		pFreqCmds->clear();
	}
	Windows::Forms::TableLayoutPanel^ chnlFrame;
	int posX = 1, posY = 50,  panelSizeW = 196, panelSizeH = 91, adicX=1, adicY=1;
	for (int i = 0; i < rows; i++) {
		adicX = 1;
		for (int j = 0; j < columns; j++) {
			// Draw channel frames
			chnlFrame = gcnew Windows::Forms::TableLayoutPanel;
			chnlFrame->ColumnCount = 1;
			chnlFrame->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			chnlFrame->Location = System::Drawing::Point(posX + (adicX + panelSizeW) * j, posY+ i * (panelSizeH + adicY));
			chnlFrame->Name = L"tableLayoutPanel" + i;
			chnlFrame->RowCount = 1;
			chnlFrame->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			chnlFrame->Size = System::Drawing::Size(panelSizeW+7, panelSizeH+6);
			chnlFrame->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			Label^ str = gcnew Label;
			str->Text="      ------------------------";
			str->Anchor = System::Windows::Forms::AnchorStyles::None;
			chnlFrame->Controls->Add(str);
			this->panel1->Controls->Add(chnlFrame);
			chnlFrame->Show();
			// Draw channel Views
			pChnlViewItem = gcnew ChnlViewForm(% m_mainDataStruct, %pChnlsViewList, pGroupNames, pChnlsNames4formulas, pFreqCmds);
			pChnlViewItem->MdiParent = this;
			pChnlViewItem->ChnlName = CHANNEL_VIEW_DEFAULT_NAME;
			pChnlViewItem->OriginalPosX = (posX + 2) + (adicX + panelSizeW) * j;
			pChnlViewItem->OriginalPosY = (posY + 2) + i * (panelSizeH + adicY);
			pChnlViewItem->Location = System::Drawing::Point(pChnlViewItem->OriginalPosX, pChnlViewItem->OriginalPosY);
			pChnlViewItem->Size = System::Drawing::Size(panelSizeW, panelSizeH);
			pChnlViewItem->BackColor = System::Drawing::Color::AliceBlue;
			pChnlViewItem->ChnlCnf->Color = System::Convert::ToString(-984833);
			if ((M_ViewCnfList->Count > 0) && 
				((i * columns + j) < this->M_ViewCnfList->Count) &&
				(M_ViewCnfList[i * columns + j]->Visible)){
				pChnlViewItem->ChnlCnf->cpyData(M_ViewCnfList[i * columns + j]);
				pChnlViewItem->lbl2_NameChnlView->Text = M_ViewCnfList[i * columns + j]->ViewName;
				pChnlViewItem->txtBx1_VoltSPChnlView->Text = pChnlViewItem->ChnlCnf->VoltageSet;
				pChnlViewItem->txtBx2_CurrtSPChnlView->Text = pChnlViewItem->ChnlCnf->CurrentSet;
				pChnlViewItem->lbl_GroupName->Text = M_ViewCnfList[i * columns + j]->Group;
				System::Array^ colorSplit = this->M_ViewCnfList[i * columns + j]->Color->Split(',');
				pChnlViewItem->panel1->BackColor = System::Drawing::Color::FromArgb(System::Convert::ToInt32(this->M_ViewCnfList[i * columns + j]->Color));
				pChnlViewItem->ChnlCnf->ChannelName = M_ViewCnfList[i * columns + j]->ChannelName;
				pChnlViewItem->ChnlName = pChnlViewItem->ChnlCnf->ChannelName;
				if (pChnlViewItem->ChnlCnf->ChnlType == 0) { // 0: Virtual, 1: Normal/Physical
					// If channel is Virtual set background color to transparent ToDo
					//pChnlViewItem->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
						//static_cast<System::Int32>(static_cast<System::Byte>(64)));
					pChnlViewItem->txtBx1_VoltSPChnlView->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
						static_cast<System::Int32>(static_cast<System::Byte>(64)));
					pChnlViewItem->txtBx1_VoltSPChnlView ->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
						static_cast<System::Int32>(static_cast<System::Byte>(255)));
					pChnlViewItem->txtBx2_CurrtSPChnlView->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
						static_cast<System::Int32>(static_cast<System::Byte>(64)));
					pChnlViewItem->txtBx2_CurrtSPChnlView->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
						static_cast<System::Int32>(static_cast<System::Byte>(255)));
					pChnlViewItem->btn1_ChnlView->Enabled = false;
					m_cmdMsg->ViewActive = true;
				}
				pChnlViewItem->ChnlCnf->ViewName = M_ViewCnfList[i * columns + j]->ViewName;
				pChnlViewItem->ChnlCnf->Row = i;
				pChnlViewItem->ChnlCnf->Col = j;
				pChnlViewItem->ModDir = pChnlViewItem->ChnlCnf->ModDir;
				
				// If the channel slot in View contains a channel to Monitor
				// Add channel to channel available for data recording list
				if (pChnlViewItem->ChnlCnf->Visible) {
					ControlExtension::Draggable(pChnlViewItem, true);
					// Insert channel in available channels list for data recording
					DataFile.monitoredChnls.insert(CheckedList::make_value(pChnlViewItem->lbl2_NameChnlView->Text, false));
					// Insert channel in frequent channels list to get its reading regurlaly
					// If there is/isn't hardware populate the most freq cmds List for regular scan readings
					if (((m_mainDataStruct.ptrMainCrateList->Count > 0)
							&& m_mainDataStruct.GetChnlConnectedStatus(pChnlViewItem->ChnlCnf->ChannelName)
							&& m_mainDataStruct.GetChnlEnableStatus(pChnlViewItem->ChnlCnf->ChannelName)
							|| (m_mainDataStruct.ptrMainCrateList->Count == 0))
						    || (pChnlViewItem->ChnlCnf->ChnlType==0))
					{
						String^ cmd = pChnlViewItem->ChnlCnf->ChannelName; 
						RegCmdStruct_T^ item = gcnew RegCmdStruct_T;
						item->row = pChnlViewItem->ChnlCnf->Row;
						item->col = pChnlViewItem->ChnlCnf->Col;
						item->chnlViewName = pChnlViewItem->lbl2_NameChnlView->Text;
						if ((m_mainDataStruct.ptrMainCrateList->Count > 0) &&
							(pChnlViewItem->ChnlCnf->ChnlType != 0) &&
							(m_mainDataStruct.GetChnlEnableStatus(pChnlViewItem->ChnlCnf->ChannelName))){
							item->scanned = true;
							m_cmdMsg->ViewActive = true;
							pChnlViewItem->ChnlCnf->LimitVoltage = m_mainDataStruct.GetChnlNomVolt(pChnlViewItem->ChnlCnf->ChannelName);
							pChnlViewItem->ChnlCnf->LimitCurrent = m_mainDataStruct.GetChnlNomCrrnt(pChnlViewItem->ChnlCnf->ChannelName);
						}
						pChnlViewItem->txtBx1_VoltSPChnlView->Text = pChnlViewItem->ChnlCnf->VoltageSet;
						pChnlViewItem->txtBx2_CurrtSPChnlView->Text = pChnlViewItem->ChnlCnf->CurrentSet;
						// Insert all channels  Virtuals & !Virtuals in freq list
						// since VChnls are not scanned due scanned flag is set to false
						pFreqCmds->insert(pFreqCmds->begin(), FreqCmdsMapTable_T::make_value(cmd, item));
					}
				}
			}
			else {
					pChnlViewItem->ChnlCnf->ViewName = "-----";
				}
			// Must be here to make it work with formulas channels combo box
			String^ chnlVisibleName = gcnew String(pChnlViewItem->ChnlCnf->ViewName + "_");
			pChnlsNames4formulas->Add(chnlVisibleName);
			String^ chnlVisibleNameU = gcnew String(pChnlViewItem->ChnlCnf->ViewName + "_U");
			pChnlsNames4formulas->Add(chnlVisibleNameU);
			
			this->panel1->Controls->Add(pChnlViewItem);
			if (pChnlViewItem->ChnlCnf->Visible){
				if (pChnlViewItem->ChnlCnf->UseVoltageFormula) {
					pChnlViewItem->txtBx1_VoltSPChnlView->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(233)),
						static_cast<System::Int32>(static_cast<System::Byte>(84))); 
					pChnlViewItem->txtBx1_VoltSPChnlView->Enabled = false;
				}
				pChnlViewItem->BringToFront();
				pChnlViewItem->Show();
			}
			int n = pChnlsViewList.size();
			int m = pChnlsViewList.capacity();
			pChnlsViewList.push_back(pChnlViewItem);
			adicX = 6;
		}
		adicY = 5;
	}
	// Iterate through ViewList for setting formaulaRamp calculation
	for each (ChnlViewForm^ item in pChnlsViewList) {
		if (item->ChnlCnf->UseVoltageFormula) {
			item->GetformEvalAtRamp(item->ChnlCnf->VoltageFormula);
		}
	}
	this->ActiveControl = this->panel1;
	return System::Void();
}

System::Boolean CppCLRWinformsProjekt::MainForm::CreateServerPipes()
{
	HANDLE hPipe;
	
	hPipe = CreateNamedPipe(PIPE_TESTING_GUI_LIFE,
		PIPE_ACCESS_DUPLEX, // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
		PIPE_TYPE_MESSAGE | PIPE_ACCESS_INBOUND | PIPE_NOWAIT,
		PIPE_UNLIMITED_INSTANCES,
		1024 * 16,
		1024 * 16,
		0,
		NULL);
	Pipe_GuiAlive = hPipe;
	
	HANDLE hPipe2 = CreateNamedPipe(PIPE_DATA_FILE,
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE | PIPE_ACCESS_OUTBOUND | PIPE_NOWAIT,
		PIPE_UNLIMITED_INSTANCES,
		1024 * 16,
		1024 * 16,
		0,
		NULL);
	Pipe4Data2File = hPipe2;

	return (hPipe != INVALID_HANDLE_VALUE);
}

System::Boolean CppCLRWinformsProjekt::MainForm::checkPipe(HANDLE pipe)
{
	int result, error;
	char buffer[1024];
	DWORD dwRead;

	if (!PipeConnectionIO && !(result = ConnectNamedPipe(pipe, NULL))) {
		error = GetLastError();
		if (error == ERROR_PIPE_CONNECTED)
			result = 0;
		else if (error == ERROR_IO_PENDING)
			result = 1;
		PipeConnectionIO = true; // May be connection cause client can connect before this
	}
	else {
		try {
			result = ReadFile(pipe, buffer, sizeof(buffer) - 1, &dwRead, NULL);
			String^ str = gcnew String(buffer);
			Console::ForegroundColor = ConsoleColor::White;
			if (str->Contains("TEST")) {
				m_cmdMsg->statusBarMsg2 = "Comm GUI -> IO... Ok ";
				Console::WriteLine(m_cmdMsg->statusBarMsg2);
			}
			else {
				m_cmdMsg->statusBarMsg2 = "Server received from Pipe: " + str;
				Console::WriteLine(m_cmdMsg->statusBarMsg2);
			}
		}
		catch (Exception^ e) {

		}
	}
	
		
	return System::Boolean();
}

System::Void CppCLRWinformsProjekt::MainForm::SendData2Pipe(HANDLE Pipe, String^ Data)
{
	char buffer[1024*16];
	DWORD dwWritten=0;
	m_cmdMsg->statusBarMsg2 = "Sending data to record";
	Console::WriteLine(m_cmdMsg->statusBarMsg2);
	IntPtr ip = Marshal::StringToHGlobalAnsi(Data);
	const char* stream = static_cast<const char*>(ip.ToPointer());
	if ((Pipe != INVALID_HANDLE_VALUE)) {
		try {
			WriteFile(Pipe,
				stream,
				Data->Length + 1,   // = length of string + terminating '\0' !!!
				&dwWritten,
				NULL);
		}
		catch (Exception^ e) {
		}
		if (dwWritten == 0)
			dwWritten = 0;
		//CloseHandle(Pipe);  // Closed by MainForm
	}
	Marshal::FreeHGlobal(ip);
	return System::Void();
}

System::Boolean CppCLRWinformsProjekt::MainForm::ValidateVoltgReading(String ^voltMeas, String^ voltSP)
{
	Double val;
	if (Double::TryParse(voltMeas, val)) {
		Double val2;
		if (Double::TryParse(voltSP, val2)) {
			val2 = abs(val2);
			val = abs(abs(val) - val2);
			if (val >= (val2 * this->PercentageDeviationAllow) + this->VoltgDeviationAllow)
				return true;
		}
	}
	return false;
}

System::Boolean CppCLRWinformsProjekt::MainForm::EvaluateChannelFormula(String^ target, int chnlViewIndex)
{
	try {
		Double new_setPoint = (target->Contains("Voltage")) ? this->pChnlsViewList[chnlViewIndex]->GetFormulaEvaluation(this->pChnlsViewList[chnlViewIndex]->ChnlCnf->VoltageFormula, target)
			: this->pChnlsViewList[chnlViewIndex]->GetFormulaEvaluation(this->pChnlsViewList[chnlViewIndex]->ChnlCnf->CurrentFormula, target);
		Double actual_setPoint = (target->Contains("Voltage")) ? pChnlsViewList[chnlViewIndex]->vSetPoint
			: pChnlsViewList[chnlViewIndex]->cSetPoint;
		if ((new_setPoint < 0.925 * actual_setPoint) || (new_setPoint > 1.075 * actual_setPoint)) {
			//if ((Math::Truncate(actual_setPoint) != Math::Truncate(new_setPoint)) || (target->Contains("Current"))) {
			String^ cmd = gcnew String(this->pChnlsViewList[chnlViewIndex]->ChnlCnf->ChannelName + ":" + target + "Set");
			if (System::Threading::Monitor::TryEnter(m_cmdMsg)) {
				if (this->pChnlsViewList[chnlViewIndex]->ChnlCnf->ChnlType != 0) { // Not a Virtual Channel
					if (!m_cmdMsg->execRequest) {
						m_cmdMsg->CleanCmdsLists();
						String^ nomValue = gcnew String(m_mainDataStruct.GetNominalValueSet(this->pChnlsViewList[chnlViewIndex]->ChnlCnf->ChannelName, target));
						Double val;
						String^ strSetPoint = gcnew String(new_setPoint.ToString());
						if (GlobalFuncValidateSP(strSetPoint, nomValue, 0.0, 1.0)) {
							val = Math::Round(new_setPoint, 4);
							if ((((System::Convert::ToDouble(nomValue) < 0) && (val < 0)) || ((System::Convert::ToDouble(nomValue) > 0)) && (val > 0)))
								m_cmdMsg->GlobalAddSendCmds(cmd, val.ToString(), CHANNEL_CMD, 3, true);
							m_cmdMsg->StatusBarMsgIndex = 4;
						}
						else {
							System::Threading::Monitor::Exit(m_cmdMsg);
							return false;
						}
					}
				}
				else {
					// It is a Virtual Channel so just check the formula result is a valid new SP for the channel
					String^ nomValue = (target->Contains("Voltage")) ? gcnew String(this->pChnlsViewList[chnlViewIndex]->ChnlCnf->LimitVoltage)
						: gcnew String(this->pChnlsViewList[chnlViewIndex]->ChnlCnf->LimitCurrent);
					String^ strSetPoint = gcnew String(new_setPoint.ToString());
					if (GlobalFuncValidateSP(strSetPoint, nomValue, 0.0, 1.0)) {
						// Set the voltage SP on ChnlView and ChnlCnf objects
						Double val;
						val = Math::Round(new_setPoint, 4);
						if ((((val < 0) && (-System::Convert::ToDouble(nomValue) < 0)) || ((val > 0) && (System::Convert::ToDouble(nomValue) > 0)))) {
							if (target->Contains("Voltage")) {
								this->pChnlsViewList[chnlViewIndex]->ChnlCnf->VoltageSet = new_setPoint.ToString();
								this->pChnlsViewList[chnlViewIndex]->txtBx1_VoltSPChnlView->Text = new_setPoint.ToString();
							}
							else if (target->Contains("Current")) {
								this->pChnlsViewList[chnlViewIndex]->ChnlCnf->CurrentSet = new_setPoint.ToString();
								this->pChnlsViewList[chnlViewIndex]->txtBx2_CurrtSPChnlView->Text = new_setPoint.ToString();
							}
						}
					}
				}
				System::Threading::Monitor::Exit(m_cmdMsg);
			}
			if (m_cmdMsg->cmdResult && this->pChnlsViewList[chnlViewIndex]->ChnlCnf->ChnlType != 0) {
				new_setPoint = System::Convert::ToDouble(m_mainDataStruct.GetChnlVoltSet(this->pChnlsViewList[chnlViewIndex]->ChnlCnf->ChannelName));
				this->pChnlsViewList[chnlViewIndex]->txtBx1_VoltSPChnlView->Text = new_setPoint.ToString();
				pChnlsViewList[chnlViewIndex]->vSetPoint = new_setPoint;
				new_setPoint = System::Convert::ToDouble(m_mainDataStruct.GetChnlCrrntSet(this->pChnlsViewList[chnlViewIndex]->ChnlCnf->ChannelName));
				this->pChnlsViewList[chnlViewIndex]->txtBx2_CurrtSPChnlView->Text = new_setPoint.ToString();
				pChnlsViewList[chnlViewIndex]->cSetPoint = new_setPoint;
			}
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}

System::Void CppCLRWinformsProjekt::MainForm::CommProcessHandler() {
	STARTUPINFO si;
static PROCESS_INFORMATION pi;

ZeroMemory(&si, sizeof(si));
si.cb = sizeof(si);

if (pi.hProcess != NULL) {
	TerminateProcess(pi.hProcess, 0);
	const DWORD result = WaitForSingleObject(pi.hProcess, 500);
	if (result == WAIT_OBJECT_0) {
		// Success
		Console::WriteLine();
	}
	else {
		// Timed out or an error occurred
		Console::WriteLine();
	}
	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return;
}

ZeroMemory(&pi, sizeof(pi));

WCHAR wszExe[MAX_PATH] = L"VC_COMM_test.exe";
/*WCHAR wszDrive[MAX_PATH], wszDir[MAX_PATH], wszModule[MAX_PATH], wszPath[MAX_PATH];
GetModuleFileName(NULL, wszModule, MAX_PATH);
_wsplitpath(wszModule, wszDrive, wszDir, NULL, NULL);
swprintf(wszPath, L"%s%s%s", wszDrive, wszDir, wszExe);*/
//WCHAR module[MAX_PATH] = L"C:\\Users\\frang\\source\\repos\\VC_COMM\\x64\\Release\\VC_COMM1.exe ";
WCHAR module[MAX_PATH] = L"C:\\Users\\framirez\\AppData\\Local\\0_gsi_executables\\VC_COMM.exe ";
wcscat(module, (COMM_PROC_VERBOSE == 1) ? L"1" : L"0");
// Start the child process. 
if (!CreateProcess(
	NULL,//LPWSTR (module),            // No module name (use command line)
	LPWSTR(module),        // Command line
	NULL,            // Process handle not inheritable
	NULL,            // Thread handle not inheritable
	FALSE,           // Set handle inheritance to FALSE
	(COMM_PROC_VERBOSE == 1) ? 0 : DETACHED_PROCESS,//0,               // No creation flags
	NULL,            // Use parent's environment block
	NULL,            // Use parent's starting directory 
	&si,             // Pointer to STARTUPINFO structure
	&pi)             // Pointer to PROCESS_INFORMATION structure
	)
{
	int x = GetLastError();
	Console::WriteLine("CreateProcess failed (%d).\n", GetLastError());
	//system(module);
	return;
}
Console::WriteLine("CreateProcess Success! (%d).\n", GetLastError());

// Wait until child process exits.
//WaitForSingleObject(pi.hProcess, INFINITE);

// Close process and thread handles. 
//CloseHandle(pi.hProcess);
//CloseHandle(pi.hThread);
}

System::Void CppCLRWinformsProjekt::MainForm::SearchAndKillProc(String^ commProcName) {
	WTS_PROCESS_INFO* pWPIs = NULL;
	DWORD dwProcCount = 0;
	if (WTSEnumerateProcesses(WTS_CURRENT_SERVER_HANDLE, NULL, 1, &pWPIs, &dwProcCount))
	{
		if (dwProcCount > 0) {
			IntPtr ip = Marshal::StringToHGlobalUni(commProcName);
			const char* stream = static_cast<const char*>(ip.ToPointer());

			//Search among all process
			for (DWORD i = 0; i < dwProcCount; i++)
			{
				if (!strncmp(stream, (const char*)pWPIs[i].pProcessName, commProcName->Length)) {
					Console::WriteLine("OLD Comm process alive");
					HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pWPIs[i].ProcessId);
					TerminateProcess(hProcess, 0);
					CloseHandle(hProcess);

					break;
				}
				//pWPIs[i].pProcessName = process file name only, no path!
				//pWPIs[i].ProcessId = process ID
				//pWPIs[i].SessionId = session ID, if you need to limit it to the logged in user processes
				//pWPIs[i].pUserSid = user SID that started the process
			}
			Marshal::FreeHGlobal(ip);
		}

	}

	//Free memory
	if (pWPIs)
	{
		WTSFreeMemory(pWPIs);
		pWPIs = NULL;
	}
}
