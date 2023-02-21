#pragma once

#include <tchar.h>
#include <stdio.h>
#include <io.h>
#include "wtypes.h"
#include "servprov.h"

#include "MyForm.h"
#include "Crate.h"
#include "ChnlViewForm.h"
#include "SetSltnViewForm.h"

#include "GlobalsHeader.h"
#include "ProgressDialog.h"
#include "MainHeader.h"
#include "SaveDataToFile.h"
#include "LogSltnForm.h"
#include "XML_ViewSettingsConf_Class.h"
#include "GroupCnfSltn.h"
#include "SearchListPredicate.h"
#include "ProgressDialog.h"
#include "ThreadCAClass.h"
#include "GlobalSettingsForm.h"
#include "SetStateByGroup.h"
#include "GroupNaming.h"
#ifndef SEM_H
#include "CommsShMemPipesClass.h"
#endif

#define TIME_2_CLEAN_STATUS_MSG2_SEC 2 // Aprox 2 sec
#define COMM_PROC_VERBOSE 1
#define MAX_DIFF_vSP_READING 0.90  // Percentage

namespace CppCLRWinformsProjekt {

    using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	   
	using namespace ListTest_CLI_Project;
	using namespace System::Threading;
	using namespace Thread_CA;
	using namespace System::Runtime::InteropServices;

	using namespace System::Xml::Serialization;
	using namespace System::IO;
	using namespace System::Runtime::Serialization;

	using namespace org::mariuszgromada::math::mxparser;  // Math lib for expression evaluation -> Formulas
	using namespace DraggableControls;

	namespace Win32 {
		[DllImport("kernel32.dll", CallingConvention = CallingConvention::StdCall)]
		int AllocConsole();
		[DllImport("kernel32.dll", CallingConvention = CallingConvention::StdCall)]
		int FreeConsole();
	}

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: property SetStateByGroup^ pSetStatesByGroup;
			 property HANDLE Pipe_GuiAlive {
				 HANDLE get() { return m_PipeServer; }
				 void set(HANDLE pipe) { m_PipeServer = pipe; }
			 }
			 property HANDLE Pipe4Data2File {
				 HANDLE get() { return m_ServerSaveData; }
				 void set(HANDLE pipe) { m_ServerSaveData = pipe; }
			 }
			 property SaveDataToFile^ pSaveData {
				 SaveDataToFile^ get() { return m_pDataSave; }
				 void set(SaveDataToFile^ pDataSaveThread) { m_pDataSave = pDataSaveThread; }
			 }
			 property bool PipeConnectionIO {
				 bool get() { return m_connectedPipeIO; };
				 void set(bool connected) { m_connectedPipeIO = connected; }
			 }
			 property int Rows;
			 property int Cols;
			 property CheckedList^ pHrwList;
			 property bool Connected;
			 property Double PercentageDeviationAllow;
			 property Double VoltgDeviationAllow;
			 property String^ FilesPath;
			 property int TimeDataRecording;
			 property List<String^>^ pGroupNames;
			 property List<String^>^ pChnlsNames4formulas;  // Channels names for formula purposes in each ChnlViewForm
			 property int Time2ClearStatusMsg;
			 property int Time2ClearStatusMsg2;
			 property bool ConnectingOrLoading;
			 property bool SwitchAllChnlsOffAtStart;
			 property bool SwitchAllChnlsOffAtEnd;
			 property bool newViewCnf;
	private:
		Crate^ crateInMainForm;
		SingletonCmmdClass^ m_cmdMsg;
		
		cliext::vector<Double> m_voltageMeasurements;
		cliext::vector<Double> m_currentMeasurements;
		cliext::vector<String^> m_isOnStatus;
		HANDLE m_PipeServer = nullptr;
		HANDLE m_ServerSaveData = nullptr;
		bool m_connectedPipeIO = false;
	private: property List<XML_Classes::Channel^>^ M_ViewCnfList; //List to channel View conf values
	public: property CheckedList^	m_HrdwFailList;
	public:
		cliext::vector <ChnlViewForm^> pChnlsViewList;
		
		CratesT m_mainDataStruct;
		CratesT ^ m_ptrMainDtSt;
		List<Crate^>^ m_ptrMainCrateList;
		ThreadCAClass^ m_ptrMainThreadCA;
		SaveDataToFile^ m_pDataSave;
		Crate^ crateMainObject;
		FileData DataFile;
		FreqCmdsMapTable_T^ pFreqCmds;
		FreqCmdsMapTable_T mFreqCmds;
		SemClass cmdsSem, freqCmdsSem;

	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setupSelectionViewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^ mainSwitchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ switchALLChannelsOffToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator4;

	private: System::Windows::Forms::ToolStripMenuItem^ groupsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator5;
	private: System::Windows::Forms::ToolStripMenuItem^ systemStateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ loggingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ automationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editCustomScriptsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator6;
	private: System::Windows::Forms::ToolStripMenuItem^ action1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ action2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ action3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ action4ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ action5ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ action6ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ action7ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ action8ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ action9ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ action10ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ configureToolbarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ globalSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator7;
	private: System::Windows::Forms::ToolStripMenuItem^ crateTableSetupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ channelNamesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator8;
	private: System::Windows::Forms::ToolStripMenuItem^ loadCrateSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveCrateSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showDebugWindowToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator9;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutProgramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ onlineHelpToolStripMenuItem;



	public: System::Windows::Forms::Panel^ panel1;

	public:

	private: System::Windows::Forms::ToolStripMenuItem^ setupByGorupsToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;

	private: System::Windows::Forms::ToolStripSplitButton^ toolStripSplitButton1;



	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel3;

	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel5;

	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator10;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel2;
private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator11;
private: System::Windows::Forms::ToolStripButton^ TG1;

private: System::Windows::Forms::ToolStripButton^ TG2;
private: System::Windows::Forms::ToolStripButton^ TG3;
private: System::Windows::Forms::ToolStripButton^ TG4;
private: System::Windows::Forms::ToolStripButton^ TG5;
private: System::Windows::Forms::ToolStripButton^ TG6;
private: System::Windows::Forms::ToolStripButton^ TG7;
private: System::Windows::Forms::ToolStripButton^ TG8;
private: System::Windows::Forms::ToolStripButton^ TG9;
private: System::Windows::Forms::ToolStripButton^ TG10;
private: System::Windows::Forms::ToolStripButton^ TG11;
private: System::Windows::Forms::ToolStripButton^ TG12;
private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel4;







	
	public:
		MainForm(Crate^ crateValueObject)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
			m_cmdMsg = SingletonCmmdClass::Instance;
			crateMainObject = gcnew Crate("ISEG", "140.181.78.178");
			m_ptrMainCrateList = gcnew List<Crate^>;
			pChnlsViewList = gcnew cliext::vector<ChnlViewForm^>;
			M_ViewCnfList = gcnew List<XML_Classes::Channel^>;
			m_HrdwFailList = gcnew CheckedList;
			pHrwList = gcnew CheckedList;
			pFreqCmds = gcnew FreqCmdsMapTable_T;
			mFreqCmds = gcnew FreqCmdsMapTable_T;
			m_mainDataStruct.ptrMainCrateList = m_ptrMainCrateList;
			m_mainDataStruct.pMainCnfView = M_ViewCnfList;
			
			m_ptrMainThreadCA = gcnew ThreadCAClass(m_ptrMainCrateList, % m_mainDataStruct, pHrwList,  crateMainObject, pFreqCmds, m_HrdwFailList);
			m_voltageMeasurements = gcnew cliext::vector<Double>(16);
			m_voltageMeasurements.assign(16, 0.0);
			m_currentMeasurements = gcnew cliext::vector<Double>(16);
			m_currentMeasurements.assign(16, 0.0);
			m_isOnStatus = gcnew cliext::vector<String^>(16);
			m_isOnStatus.assign(16, "");
			crateInMainForm = crateMainObject;
			Rows = 0; Cols = 0;
			DataFile.savingInterval = 5; // sec, default 5 sec
			TimeDataRecording = 5;       // Global setting
			CreateServerPipes();
			PercentageDeviationAllow = .001;
			VoltgDeviationAllow = .01;
			pGroupNames = gcnew List<String^>;
			pChnlsNames4formulas = gcnew List<String^>;
			ConnectingOrLoading = false;
			m_mainDataStruct.m_StatusBarMsgsArray = GetArrayMsg();
			SwitchAllChnlsOffAtStart = false;
			SwitchAllChnlsOffAtEnd = false;
			FilesPath = "C:\\ProgramData\\VoltageControllerNew\\LOG";
			newViewCnf = true;
			
		}
		void mainFormEntryPoint() {
			//InitializeComponent();
		}
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ configToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;

	private: System::ComponentModel::IContainer^ components;

	public: System::Windows::Forms::Timer^ timer1;
			//System::Boolean CheckValidityNewSP(String^ voltMeas, String^ voltSP);



	private:



	private:
		/// <summary>
		/// Erforderliche Designervariable.
		String^ strThreadTest;
		/// </summary>
	
	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->configToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setupSelectionViewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mainSwitchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->switchALLChannelsOffToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->setupByGorupsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->systemStateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loggingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->automationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editCustomScriptsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->action1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->action2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->action3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->action4ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->action5ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->action6ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->action7ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->action8ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->action9ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->action10ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->configureToolbarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->globalSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->crateTableSetupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->channelNamesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->loadCrateSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveCrateSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showDebugWindowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator9 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->aboutProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->onlineHelpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator10 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator11 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->TG1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG8 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG9 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG10 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG11 = (gcnew System::Windows::Forms::ToolStripButton());
			this->TG12 = (gcnew System::Windows::Forms::ToolStripButton());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripSplitButton1 = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel5 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel4 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->toolsToolStripMenuItem, this->automationToolStripMenuItem, this->settingsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1284, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->configToolStripMenuItem,
					this->toolStripMenuItem2, this->toolStripMenuItem1, this->toolStripSeparator2, this->toolStripMenuItem3, this->toolStripSeparator1,
					this->exitToolStripMenuItem1
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// configToolStripMenuItem
			// 
			this->configToolStripMenuItem->Enabled = false;
			this->configToolStripMenuItem->Name = L"configToolStripMenuItem";
			this->configToolStripMenuItem->Size = System::Drawing::Size(207, 22);
			this->configToolStripMenuItem->Text = L"New Settings";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(207, 22);
			this->toolStripMenuItem2->Text = L"Save selection Settings ...";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::ToolStripMenuItem2_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(207, 22);
			this->toolStripMenuItem1->Text = L"Open selection Settings...";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::LoadCOnfViewFromFile_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(204, 6);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(207, 22);
			this->toolStripMenuItem3->Text = L"Connect/Disconnect";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MainForm::ToolStripMenuItem3_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(204, 6);
			// 
			// exitToolStripMenuItem1
			// 
			this->exitToolStripMenuItem1->AutoToolTip = true;
			this->exitToolStripMenuItem1->Name = L"exitToolStripMenuItem1";
			this->exitToolStripMenuItem1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->exitToolStripMenuItem1->ShortcutKeyDisplayString = L" ";
			this->exitToolStripMenuItem1->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X));
			this->exitToolStripMenuItem1->Size = System::Drawing::Size(207, 22);
			this->exitToolStripMenuItem1->Text = L"E&xit";
			this->exitToolStripMenuItem1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->exitToolStripMenuItem1->ToolTipText = L"Exit";
			this->exitToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::ExitToolStripMenuItem1_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->setupSelectionViewToolStripMenuItem,
					this->toolStripSeparator3, this->mainSwitchToolStripMenuItem, this->switchALLChannelsOffToolStripMenuItem, this->toolStripSeparator4,
					this->setupByGorupsToolStripMenuItem, this->groupsToolStripMenuItem, this->toolStripSeparator5, this->systemStateToolStripMenuItem,
					this->loggingToolStripMenuItem
			});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// setupSelectionViewToolStripMenuItem
			// 
			this->setupSelectionViewToolStripMenuItem->Name = L"setupSelectionViewToolStripMenuItem";
			this->setupSelectionViewToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->setupSelectionViewToolStripMenuItem->Text = L"Setup selection view";
			this->setupSelectionViewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SetupSelectionViewToolStripMenuItem_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(197, 6);
			// 
			// mainSwitchToolStripMenuItem
			// 
			this->mainSwitchToolStripMenuItem->Enabled = false;
			this->mainSwitchToolStripMenuItem->Name = L"mainSwitchToolStripMenuItem";
			this->mainSwitchToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->mainSwitchToolStripMenuItem->Text = L"Main switch";
			// 
			// switchALLChannelsOffToolStripMenuItem
			// 
			this->switchALLChannelsOffToolStripMenuItem->Name = L"switchALLChannelsOffToolStripMenuItem";
			this->switchALLChannelsOffToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->switchALLChannelsOffToolStripMenuItem->Text = L"Switch ALL channels off";
			this->switchALLChannelsOffToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SwitchALLChannelsOffToolStripMenuItem_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(197, 6);
			// 
			// setupByGorupsToolStripMenuItem
			// 
			this->setupByGorupsToolStripMenuItem->Name = L"setupByGorupsToolStripMenuItem";
			this->setupByGorupsToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->setupByGorupsToolStripMenuItem->Text = L"Setup by gorups...";
			// 
			// groupsToolStripMenuItem
			// 
			this->groupsToolStripMenuItem->Name = L"groupsToolStripMenuItem";
			this->groupsToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->groupsToolStripMenuItem->Text = L"Groups...";
			this->groupsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GroupsToolStripMenuItem_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(197, 6);
			// 
			// systemStateToolStripMenuItem
			// 
			this->systemStateToolStripMenuItem->Enabled = false;
			this->systemStateToolStripMenuItem->Name = L"systemStateToolStripMenuItem";
			this->systemStateToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->systemStateToolStripMenuItem->Text = L"System state...";
			// 
			// loggingToolStripMenuItem
			// 
			this->loggingToolStripMenuItem->Name = L"loggingToolStripMenuItem";
			this->loggingToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->loggingToolStripMenuItem->Text = L"Logging...";
			this->loggingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::LoggingToolStripMenuItem_Click);
			// 
			// automationToolStripMenuItem
			// 
			this->automationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->editCustomScriptsToolStripMenuItem,
					this->toolStripSeparator6, this->action1ToolStripMenuItem, this->action2ToolStripMenuItem, this->action3ToolStripMenuItem, this->action4ToolStripMenuItem,
					this->action5ToolStripMenuItem, this->action6ToolStripMenuItem, this->action7ToolStripMenuItem, this->action8ToolStripMenuItem,
					this->action9ToolStripMenuItem, this->action10ToolStripMenuItem
			});
			this->automationToolStripMenuItem->Enabled = false;
			this->automationToolStripMenuItem->Name = L"automationToolStripMenuItem";
			this->automationToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->automationToolStripMenuItem->Text = L"Automation";
			// 
			// editCustomScriptsToolStripMenuItem
			// 
			this->editCustomScriptsToolStripMenuItem->Name = L"editCustomScriptsToolStripMenuItem";
			this->editCustomScriptsToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->editCustomScriptsToolStripMenuItem->Text = L"Edit custom scripts";
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(171, 6);
			// 
			// action1ToolStripMenuItem
			// 
			this->action1ToolStripMenuItem->Name = L"action1ToolStripMenuItem";
			this->action1ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action1ToolStripMenuItem->Text = L"Action 1";
			// 
			// action2ToolStripMenuItem
			// 
			this->action2ToolStripMenuItem->Name = L"action2ToolStripMenuItem";
			this->action2ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action2ToolStripMenuItem->Text = L"Action 2";
			// 
			// action3ToolStripMenuItem
			// 
			this->action3ToolStripMenuItem->Name = L"action3ToolStripMenuItem";
			this->action3ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action3ToolStripMenuItem->Text = L"Action 3";
			// 
			// action4ToolStripMenuItem
			// 
			this->action4ToolStripMenuItem->Name = L"action4ToolStripMenuItem";
			this->action4ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action4ToolStripMenuItem->Text = L"Action 4";
			// 
			// action5ToolStripMenuItem
			// 
			this->action5ToolStripMenuItem->Name = L"action5ToolStripMenuItem";
			this->action5ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action5ToolStripMenuItem->Text = L"Action 5";
			// 
			// action6ToolStripMenuItem
			// 
			this->action6ToolStripMenuItem->Name = L"action6ToolStripMenuItem";
			this->action6ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action6ToolStripMenuItem->Text = L"Action 6";
			// 
			// action7ToolStripMenuItem
			// 
			this->action7ToolStripMenuItem->Name = L"action7ToolStripMenuItem";
			this->action7ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action7ToolStripMenuItem->Text = L"Action 7";
			// 
			// action8ToolStripMenuItem
			// 
			this->action8ToolStripMenuItem->Name = L"action8ToolStripMenuItem";
			this->action8ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action8ToolStripMenuItem->Text = L"Action 8";
			// 
			// action9ToolStripMenuItem
			// 
			this->action9ToolStripMenuItem->Name = L"action9ToolStripMenuItem";
			this->action9ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action9ToolStripMenuItem->Text = L"Action 9";
			// 
			// action10ToolStripMenuItem
			// 
			this->action10ToolStripMenuItem->Name = L"action10ToolStripMenuItem";
			this->action10ToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->action10ToolStripMenuItem->Text = L"Action 10";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->configureToolbarToolStripMenuItem,
					this->globalSettingsToolStripMenuItem, this->toolStripSeparator7, this->crateTableSetupToolStripMenuItem, this->channelNamesToolStripMenuItem,
					this->toolStripSeparator8, this->loadCrateSettingsToolStripMenuItem, this->saveCrateSettingsToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// configureToolbarToolStripMenuItem
			// 
			this->configureToolbarToolStripMenuItem->Enabled = false;
			this->configureToolbarToolStripMenuItem->Name = L"configureToolbarToolStripMenuItem";
			this->configureToolbarToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->configureToolbarToolStripMenuItem->Text = L"Configure toolbar...";
			// 
			// globalSettingsToolStripMenuItem
			// 
			this->globalSettingsToolStripMenuItem->Name = L"globalSettingsToolStripMenuItem";
			this->globalSettingsToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->globalSettingsToolStripMenuItem->Text = L"Global settings...";
			this->globalSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GlobalSettingsToolStripMenuItem_Click);
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(174, 6);
			// 
			// crateTableSetupToolStripMenuItem
			// 
			this->crateTableSetupToolStripMenuItem->Name = L"crateTableSetupToolStripMenuItem";
			this->crateTableSetupToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->crateTableSetupToolStripMenuItem->Text = L"Crate table setup...";
			this->crateTableSetupToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::CrateTableSetupToolStripMenuItem_Click);
			// 
			// channelNamesToolStripMenuItem
			// 
			this->channelNamesToolStripMenuItem->Name = L"channelNamesToolStripMenuItem";
			this->channelNamesToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->channelNamesToolStripMenuItem->Text = L"Group names";
			this->channelNamesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ChannelNamesToolStripMenuItem_Click);
			// 
			// toolStripSeparator8
			// 
			this->toolStripSeparator8->Name = L"toolStripSeparator8";
			this->toolStripSeparator8->Size = System::Drawing::Size(174, 6);
			// 
			// loadCrateSettingsToolStripMenuItem
			// 
			this->loadCrateSettingsToolStripMenuItem->Name = L"loadCrateSettingsToolStripMenuItem";
			this->loadCrateSettingsToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->loadCrateSettingsToolStripMenuItem->Text = L"Load crate settings";
			this->loadCrateSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::LoadCrateSettingsToolStripMenuItem_Click);
			// 
			// saveCrateSettingsToolStripMenuItem
			// 
			this->saveCrateSettingsToolStripMenuItem->Name = L"saveCrateSettingsToolStripMenuItem";
			this->saveCrateSettingsToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->saveCrateSettingsToolStripMenuItem->Text = L"Save crate settings";
			this->saveCrateSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SaveCrateSettingsToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->showDebugWindowToolStripMenuItem,
					this->toolStripSeparator9, this->aboutProgramToolStripMenuItem, this->onlineHelpToolStripMenuItem
			});
			this->helpToolStripMenuItem->Enabled = false;
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// showDebugWindowToolStripMenuItem
			// 
			this->showDebugWindowToolStripMenuItem->Name = L"showDebugWindowToolStripMenuItem";
			this->showDebugWindowToolStripMenuItem->Size = System::Drawing::Size(185, 22);
			this->showDebugWindowToolStripMenuItem->Text = L"Show debug window";
			// 
			// toolStripSeparator9
			// 
			this->toolStripSeparator9->Name = L"toolStripSeparator9";
			this->toolStripSeparator9->Size = System::Drawing::Size(182, 6);
			// 
			// aboutProgramToolStripMenuItem
			// 
			this->aboutProgramToolStripMenuItem->Name = L"aboutProgramToolStripMenuItem";
			this->aboutProgramToolStripMenuItem->Size = System::Drawing::Size(185, 22);
			this->aboutProgramToolStripMenuItem->Text = L"About program";
			// 
			// onlineHelpToolStripMenuItem
			// 
			this->onlineHelpToolStripMenuItem->Name = L"onlineHelpToolStripMenuItem";
			this->onlineHelpToolStripMenuItem->Size = System::Drawing::Size(185, 22);
			this->onlineHelpToolStripMenuItem->Text = L"Online help";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(86, 26);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X));
			this->exitToolStripMenuItem->ShowShortcutKeys = false;
			this->exitToolStripMenuItem->Size = System::Drawing::Size(85, 22);
			this->exitToolStripMenuItem->Text = L"E&xit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ExitToolStripMenuItem_Click_1);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 750;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::Timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->AllowDrop = true;
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1284, 694);
			this->panel1->TabIndex = 9;
			// 
			// toolStrip1
			// 
			this->toolStrip1->AllowDrop = true;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(16) {
				this->toolStripButton2,
					this->toolStripSeparator10, this->toolStripButton1, this->toolStripSeparator11, this->TG1, this->TG2, this->TG3, this->TG4, this->TG5,
					this->TG6, this->TG7, this->TG8, this->TG9, this->TG10, this->TG11, this->TG12
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1284, 25);
			this->toolStrip1->TabIndex = 6;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"toolStripButton2";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MainForm::ToolStripMenuItem3_Click);
			// 
			// toolStripSeparator10
			// 
			this->toolStripSeparator10->Name = L"toolStripSeparator10";
			this->toolStripSeparator10->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MainForm::SwitchALLChannelsOffToolStripMenuItem_Click);
			// 
			// toolStripSeparator11
			// 
			this->toolStripSeparator11->Name = L"toolStripSeparator11";
			this->toolStripSeparator11->Size = System::Drawing::Size(6, 25);
			// 
			// TG1
			// 
			this->TG1->BackColor = System::Drawing::Color::RosyBrown;
			this->TG1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG1.Image")));
			this->TG1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG1->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG1->Name = L"TG1";
			this->TG1->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG1->Size = System::Drawing::Size(36, 22);
			this->TG1->Text = L"TG1";
			this->TG1->ToolTipText = L"Toggle Group 1";
			this->TG1->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG2
			// 
			this->TG2->BackColor = System::Drawing::Color::RosyBrown;
			this->TG2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG2.Image")));
			this->TG2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG2->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG2->Name = L"TG2";
			this->TG2->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG2->Size = System::Drawing::Size(36, 22);
			this->TG2->Text = L"TG2";
			this->TG2->ToolTipText = L"Toggle Group 2";
			this->TG2->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG3
			// 
			this->TG3->BackColor = System::Drawing::Color::RosyBrown;
			this->TG3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG3.Image")));
			this->TG3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG3->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG3->Name = L"TG3";
			this->TG3->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG3->Size = System::Drawing::Size(36, 22);
			this->TG3->Text = L"TG3";
			this->TG3->ToolTipText = L"Toggle Group 3";
			this->TG3->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG4
			// 
			this->TG4->BackColor = System::Drawing::Color::RosyBrown;
			this->TG4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG4.Image")));
			this->TG4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG4->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG4->Name = L"TG4";
			this->TG4->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG4->Size = System::Drawing::Size(36, 22);
			this->TG4->Text = L"TG4";
			this->TG4->ToolTipText = L"Toggle Group 4";
			this->TG4->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG5
			// 
			this->TG5->BackColor = System::Drawing::Color::RosyBrown;
			this->TG5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG5.Image")));
			this->TG5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG5->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG5->Name = L"TG5";
			this->TG5->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG5->Size = System::Drawing::Size(36, 22);
			this->TG5->Text = L"TG5";
			this->TG5->ToolTipText = L"Toggle Group 5";
			this->TG5->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG6
			// 
			this->TG6->BackColor = System::Drawing::Color::RosyBrown;
			this->TG6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG6.Image")));
			this->TG6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG6->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG6->Name = L"TG6";
			this->TG6->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG6->Size = System::Drawing::Size(36, 22);
			this->TG6->Text = L"TG6";
			this->TG6->ToolTipText = L"Toggle Group 6";
			this->TG6->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG7
			// 
			this->TG7->BackColor = System::Drawing::Color::RosyBrown;
			this->TG7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG7.Image")));
			this->TG7->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG7->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG7->Name = L"TG7";
			this->TG7->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG7->Size = System::Drawing::Size(36, 22);
			this->TG7->Text = L"TG7";
			this->TG7->ToolTipText = L"Toggle Group 7";
			this->TG7->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG8
			// 
			this->TG8->BackColor = System::Drawing::Color::RosyBrown;
			this->TG8->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG8.Image")));
			this->TG8->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG8->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG8->Name = L"TG8";
			this->TG8->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG8->Size = System::Drawing::Size(36, 22);
			this->TG8->Text = L"TG8";
			this->TG8->ToolTipText = L"Toggle Group 8";
			this->TG8->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG9
			// 
			this->TG9->BackColor = System::Drawing::Color::RosyBrown;
			this->TG9->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG9.Image")));
			this->TG9->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG9->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG9->Name = L"TG9";
			this->TG9->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG9->Size = System::Drawing::Size(36, 22);
			this->TG9->Text = L"TG9";
			this->TG9->ToolTipText = L"Toggle Group 9";
			this->TG9->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG10
			// 
			this->TG10->BackColor = System::Drawing::Color::RosyBrown;
			this->TG10->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG10.Image")));
			this->TG10->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG10->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG10->Name = L"TG10";
			this->TG10->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG10->Size = System::Drawing::Size(42, 22);
			this->TG10->Text = L"TG10";
			this->TG10->ToolTipText = L"Toggle Group 10";
			this->TG10->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG11
			// 
			this->TG11->BackColor = System::Drawing::Color::RosyBrown;
			this->TG11->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG11.Image")));
			this->TG11->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG11->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG11->Name = L"TG11";
			this->TG11->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG11->Size = System::Drawing::Size(42, 22);
			this->TG11->Text = L"TG11";
			this->TG11->ToolTipText = L"Toggle Group 11";
			this->TG11->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// TG12
			// 
			this->TG12->BackColor = System::Drawing::Color::RosyBrown;
			this->TG12->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			//this->TG12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TG12.Image")));
			this->TG12->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TG12->Margin = System::Windows::Forms::Padding(0, 1, 5, 2);
			this->TG12->Name = L"TG12";
			this->TG12->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->TG12->Size = System::Drawing::Size(42, 22);
			this->TG12->Text = L"TG12";
			this->TG12->ToolTipText = L"Toggle Group 12";
			this->TG12->Click += gcnew System::EventHandler(this, &MainForm::ToggleGroup_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->toolStripStatusLabel1,
					this->toolStripSplitButton1, this->toolStripStatusLabel3, this->toolStripStatusLabel5, this->toolStripStatusLabel4, this->toolStripStatusLabel2
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 694);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1284, 24);
			this->statusStrip1->TabIndex = 6;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->toolStripStatusLabel1->BorderSides = static_cast<System::Windows::Forms::ToolStripStatusLabelBorderSides>((((System::Windows::Forms::ToolStripStatusLabelBorderSides::Left | System::Windows::Forms::ToolStripStatusLabelBorderSides::Top)
				| System::Windows::Forms::ToolStripStatusLabelBorderSides::Right)
				| System::Windows::Forms::ToolStripStatusLabelBorderSides::Bottom));
			this->toolStripStatusLabel1->BorderStyle = System::Windows::Forms::Border3DStyle::Sunken;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(86, 19);
			this->toolStripStatusLabel1->Text = L"System status:";
			// 
			// toolStripSplitButton1
			// 
			this->toolStripSplitButton1->ForeColor = System::Drawing::Color::DimGray;
			this->toolStripSplitButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSplitButton1->Name = L"toolStripSplitButton1";
			this->toolStripSplitButton1->Size = System::Drawing::Size(155, 22);
			this->toolStripSplitButton1->Text = L"Connected crates List <>";
			this->toolStripSplitButton1->ButtonClick += gcnew System::EventHandler(this, &MainForm::ToolStripSplitButton1_ButtonClick);
			this->toolStripSplitButton1->DropDownOpening += gcnew System::EventHandler(this, &MainForm::ToolStripSplitButton1_ButtonClick);
			// 
			// toolStripStatusLabel3
			// 
			this->toolStripStatusLabel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->toolStripStatusLabel3->BorderSides = static_cast<System::Windows::Forms::ToolStripStatusLabelBorderSides>((((System::Windows::Forms::ToolStripStatusLabelBorderSides::Left | System::Windows::Forms::ToolStripStatusLabelBorderSides::Top)
				| System::Windows::Forms::ToolStripStatusLabelBorderSides::Right)
				| System::Windows::Forms::ToolStripStatusLabelBorderSides::Bottom));
			this->toolStripStatusLabel3->BorderStyle = System::Windows::Forms::Border3DStyle::Sunken;
			this->toolStripStatusLabel3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
			this->toolStripStatusLabel3->Size = System::Drawing::Size(81, 19);
			this->toolStripStatusLabel3->Text = L"Main switch: ";
			// 
			// toolStripStatusLabel5
			// 
			this->toolStripStatusLabel5->AutoSize = false;
			this->toolStripStatusLabel5->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Right;
			this->toolStripStatusLabel5->ForeColor = System::Drawing::SystemColors::Window;
			this->toolStripStatusLabel5->Name = L"toolStripStatusLabel5";
			this->toolStripStatusLabel5->Size = System::Drawing::Size(400, 19);
			this->toolStripStatusLabel5->Text = L"Msg:                        ";
			this->toolStripStatusLabel5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// toolStripStatusLabel4
			// 
			this->toolStripStatusLabel4->AutoSize = false;
			this->toolStripStatusLabel4->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Right;
			this->toolStripStatusLabel4->Name = L"toolStripStatusLabel4";
			this->toolStripStatusLabel4->Size = System::Drawing::Size(170, 19);
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->AutoSize = false;
			this->toolStripStatusLabel2->AutoToolTip = true;
			this->toolStripStatusLabel2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripStatusLabel2->ForeColor = System::Drawing::SystemColors::Window;
			this->toolStripStatusLabel2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(310, 19);
			this->toolStripStatusLabel2->Text = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->ClientSize = System::Drawing::Size(1284, 718);
			this->ContextMenuStrip = this->contextMenuStrip1;
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->statusStrip1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"EpicsCA   VC";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::OnFormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//
	// Timer CLick event callback
	// Updates User interface values: Voltage/currents readouts, channels states
	private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	System:String^ data2save = "";
		static int savingTime = 0;
		static int checkPipeTime = 0;
		static Double val;
		static int msgLifeTime;

		if (freqCmdsSem.GetSem(FREQ_CMDS_SEM)) {
			mFreqCmds = pFreqCmds;
			freqCmdsSem.ReleaseSem();
		}
		bool found = false;
		if ( m_cmdMsg->ViewActive) { //m_cmdMsg->HrwConntd &&
			for each (FreqCmdsMapTable_T::value_type elem in mFreqCmds) {
				found = false;
				for (int index = 0; (index < Rows * Cols) && !found; ++index) {
					if (pChnlsViewList[index]->Visible) {
						if ((pChnlsViewList[index]->ChnlCnf->Row == elem->second->row) &&
							(pChnlsViewList[index]->ChnlCnf->Col == elem->second->col)) {
							this->pChnlsViewList[index]->lbl4_NomVoltChnlView->Text = elem->second->vValue.ToString("f3");
							this->pChnlsViewList[index]->vValue = elem->second->vValue;
							this->pChnlsViewList[index]->readoutsValues.voltg = elem->second->vValue;
							this->pChnlsViewList[index]->lbl6_NomCurrtChnlView->Text = elem->second->iValue.ToString("G3");
							
							Double viewValue, spValue;
							// Voltage SetPoint
							if (Double::TryParse(this->pChnlsViewList[index]->txtBx1_VoltSPChnlView->Text, viewValue)) {
								if (Double::TryParse(elem->second->vSet, spValue))
								if (viewValue != spValue && !this->pChnlsViewList[index]->txtBx1_VoltSPChnlView->Modified) {
										// If vSP from Crate Not equal to SP in View then Update View and CnfChnl 16.01.23
										this->pChnlsViewList[index]->txtBx1_VoltSPChnlView->Text = elem->second->vSet;
										//this->pChnlsViewList[index]->ChnlCnf->VoltageSet = this->pChnlsViewList[index]->txtBx1_VoltSPChnlView->Text;
								}
							}
							// Current SetPoint
							//if (viewValue != spValue) {
								// If vSP from Crate Not equal to SP in View then Update View and CnfChnl 16.01.23
								//this->pChnlsViewList[index]->txtBx2_CurrtSPChnlView->Text = elem->second->vSet.ToString("G3");
								//this->pChnlsViewList[index]->ChnlCnf->CurrentSet = this->pChnlsViewList[index]->txtBx2_CurrtSPChnlView->Text;
							//}
							if (elem->second->onStateValue != nullptr) {
								this->pChnlsViewList[index]->lbl1_StatusChnlView->Text = elem->second->onStateValue->ToUpper();
								// Set backgorund color for Channel Status 
								if (elem->second->onStateValue->Equals("on")) {
									//spValue *= 1.20; // Simulating a fail state
									if (elem->second->vValue < spValue * MAX_DIFF_vSP_READING) {
										// Blink
										if (this->pChnlsViewList[index]->lbl1_StatusChnlView->BackColor == System::Drawing::Color::Red)
											this->pChnlsViewList[index]->lbl1_StatusChnlView->BackColor = System::Drawing::Color::White;
										else
											this->pChnlsViewList[index]->lbl1_StatusChnlView->BackColor = System::Drawing::Color::Red;
									}
									else if (((elem->second->isVoltageRamp == "ramping") || (elem->second->isEmergency == "active")
										|| (elem->second->isTrip == "tripped") || (elem->second->isVoltageLimit == "exceeded"))
										|| ((elem->second->isVoltageRamp != "ramping")
											&& ValidateVoltgReading(elem->second->vValue.ToString(), this->pChnlsViewList[index]->txtBx1_VoltSPChnlView->Text)))
									{
										// Blink
										if (this->pChnlsViewList[index]->lbl1_StatusChnlView->BackColor == System::Drawing::Color::GreenYellow)
											this->pChnlsViewList[index]->lbl1_StatusChnlView->BackColor = System::Drawing::Color::White;
										else
											this->pChnlsViewList[index]->lbl1_StatusChnlView->BackColor = System::Drawing::Color::GreenYellow;
									}
									else if ((elem->second->onStateValue == "on") || (elem->second->onStateValue == "ON") || (elem->second->onStateValue == "On"))
										this->pChnlsViewList[index]->lbl1_StatusChnlView->BackColor = System::Drawing::Color::GreenYellow;
									else if (elem->second->onStateValue == "off")
										this->pChnlsViewList[index]->lbl1_StatusChnlView->BackColor = System::Drawing::Color::Gray;
									found = true;
								}
							}
							else this->pChnlsViewList[index]->lbl1_StatusChnlView->Text = "N/A";
							// Logging channels
							if (this->pChnlsViewList[index]->ChnlCnf->LoggingChnl) {
								if (data2save != "") data2save += ", ";
								data2save += this->pChnlsViewList[index]->lbl4_NomVoltChnlView->Text;
								data2save += ", ";
								data2save += this->pChnlsViewList[index]->txtBx1_VoltSPChnlView->Text;
								data2save += ", ";
								data2save += this->pChnlsViewList[index]->lbl6_NomCurrtChnlView->Text;
								data2save += ", ";
								data2save += this->pChnlsViewList[index]->txtBx2_CurrtSPChnlView->Text;
								data2save += ", ";
								data2save += elem->second->temperature.ToString("f6");
							}
							// Calculate/evaluate formulas for SP
							if ((this->pChnlsViewList[index]->ChnlCnf->UseVoltageFormula) && !ConnectingOrLoading) {
								EvaluateChannelFormula("Voltage", index);
							}
							if ((this->pChnlsViewList[index]->ChnlCnf->UseCurrentFormula) && !ConnectingOrLoading) {
								EvaluateChannelFormula("Current", index);
							}
						}

						if (Double::TryParse(this->pChnlsViewList[index]->txtBx1_VoltSPChnlView->Text, val)) {
							try {
								this->pChnlsViewList[index]->vSetPoint = System::Convert::ToDouble(m_mainDataStruct.GetChnlVoltSet(this->pChnlsViewList[index]->ChnlCnf->ChannelName));
							}
							catch (Exception^ e) {

							}
						}
						if (Double::TryParse(this->pChnlsViewList[index]->lbl4_NomVoltChnlView->Text, val)) {
							try {
								this->pChnlsViewList[index]->vValue = System::Convert::ToDouble(m_mainDataStruct.GetChnlVoltMeas(this->pChnlsViewList[index]->ChnlCnf->ChannelName));
							}
							catch (Exception^ e) {

							}
						}

					}
				}
			}
		}
		
		// Scan Time related Tasks
		if (savingTime++ >= (1000/ timer1->Interval)*DataFile.savingInterval) {
			if (data2save != "") SendData2Pipe(Pipe4Data2File, MSG_DATA_HEADER + data2save);
			savingTime = 0;
		}
		if (checkPipeTime++ >= (1000 / timer1->Interval) * (TIME_2_TEST_GUI_LIFE_SEC + 2)) {
			checkPipe(Pipe_GuiAlive);
			checkPipeTime = 0;
		}
		if (m_cmdMsg->StatusBarMsgIndex != -1) {
			msgLifeTime = m_mainDataStruct.m_StatusBarMsgsArray[m_cmdMsg->StatusBarMsgIndex]->MsgLifeTime;
			ShowMsgOnStatusBar(m_cmdMsg->StatusBarMsgIndex);
		}
		if (this->Time2ClearStatusMsg++ >= (1000 / timer1->Interval) * msgLifeTime) {
			ShowMsgOnStatusBar(-1);
			this->Time2ClearStatusMsg = 0;
		}
		if (m_cmdMsg->statusBarMsg2 != "") {
			ShowMsg2OnStatusBar(0);
		}
		if (this->Time2ClearStatusMsg2++ >= (1000 / timer1->Interval) * TIME_2_CLEAN_STATUS_MSG2_SEC) {
			ShowMsg2OnStatusBar(-1);
			this->Time2ClearStatusMsg2 = 0;
		}
		if (newViewCnf) {
			if (cmdsSem.GetSem(CMDS_SEM)) {
				m_cmdMsg->nameChanged = true; //Force to create New Data Structure in COMM
				cmdsSem.ReleaseSem();
				newViewCnf = false;
			}
		}
	}

	// Draw channels view declaration
public: System::Void drawChnlsView(int rows, int columns, System::Object^ Sender, System::EventArgs^ e);
	//
	// Load Form event callback
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

		//int rc = Win32::AllocConsole();
		//Console::SetWindowPosition(1, 1);
		//HWND console = GetConsoleWindow();
		//RECT r;
		//GetWindowRect(console, &r); //stores the console's current dimensions
		//MoveWindow(console, 1305, 1, 500, 1000, TRUE); // 500 width, 1000 height
		//Console::WriteLine("Main GUI Thread created");
		
		// COMM process creation
	SearchAndKillProc("VC_COMM.exe");

	CommProcessHandler();
		System::Threading::Thread::Sleep(2 * SAMPLE_TIME_mSEC);
		
		/* Creates thread managing comm IO */
		ThreadStart^ threadDelegate = gcnew ThreadStart(m_ptrMainThreadCA, &ThreadCAClass::ThreadCaEntryPoint);
		Thread^ newThread = gcnew Thread(threadDelegate);
		newThread->Start();
		drawChnlsView(Rows, Cols, this, e);
		
		/* Creates thread managing data saving (voltage) */
		pSaveData = gcnew SaveDataToFile();
		ThreadStart^ threadDelegate2 = gcnew ThreadStart(pSaveData, &SaveDataToFile::EntryPoint);
		Thread^ newThread2 = gcnew Thread(threadDelegate2);
		newThread2->Start();
		
		// Load Group names to GroupNames List
		for (int i = 0; i < NBR_GROUP_NAMES; i++) {
			String^ groupItem = gcnew String(DefaultGroups[i]);
			pGroupNames->Add(groupItem);
		}
		// Call function that populates the Setup By Groups dynamic menu
		SetupByGroupDynamicMenu_Builder();
		m_cmdMsg->HrwConntd = false;
		this->toolStripStatusLabel1->Text = "System status: Not connected";
		this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile("C:\\GECA_VC_icons\\unplugged2.png")));
		this->toolStripButton2->Text = "Disconnected";
		this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile("C:\\GECA_VC_icons\\switchOff.png")));
		this->toolStripButton1->Text = "Switch all Channels OFF";
	}

//
// Delegate for menu Items dynamically created for Ramp group settings
private: System::Void ConfigRampGroupSettings_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::ToolStripMenuItem^ MenuItem;
	MenuItem = (System::Windows::Forms::ToolStripMenuItem^) sender;
	GetCmdsFromGroupCnfForm(MenuItem->Text);
}

//
// SetUp By groups menu creation
private: System::Void SetupByGroupDynamicMenu_Builder() {
	// Create all submenu Items under Setup groups MainMenu submenu item dynamically
	// according to GroupItems List. This submenu must be updated every time a View
	// is load as well as when the group names change
	this->setupByGorupsToolStripMenuItem->DropDownItems->Clear();
	int i = 1; 
	for each (String ^ group in pGroupNames) {
		System::Windows::Forms::ToolStripMenuItem^ SubItemToAdd;
		SubItemToAdd = gcnew System::Windows::Forms::ToolStripMenuItem(group);
		this->setupByGorupsToolStripMenuItem->DropDownItems->Add(SubItemToAdd);
		// Set the appropiate delegate for the newly menu item created
		SubItemToAdd->Click += gcnew System::EventHandler(this, &MainForm::ConfigRampGroupSettings_Click);
		System::Windows::Forms::ToolStripSeparator^ toolStripSeparator;
		toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->setupByGorupsToolStripMenuItem->DropDownItems->Add(toolStripSeparator);
		try {
			//Console::WriteLine(this->toolStrip1->Items->Find("ToggleGroup1", true)[0]->Text);
			this->toolStrip1->Items->Find("TG" + i, false)[0]->ToolTipText = SubItemToAdd->Text;
		}
		catch (Exception^ e) {
			Console::WriteLine(e->ToString());
		}
		i++;
	}
}

//
// Add/Delete Crates Form menu option
private: System::Void CrateTableSetupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ AddCrateForm = gcnew MyForm(pHrwList);
		String^ str = L"148.181.78.178";
		ListViewItem^ LVItem;

		int x = m_ptrMainCrateList->Count; //AddCrateForm->listView1->Items->Count;
		for (int i = 0; i < x; i++) {
			LVItem = gcnew ListViewItem();
			LVItem->Text = m_ptrMainCrateList[i]->Name;
			LVItem->SubItems->Add(System::Convert::ToString(m_ptrMainCrateList[i]->Modules));
			LVItem->SubItems->Add(System::Convert::ToString(m_ptrMainCrateList[i]->Channels));
			LVItem->SubItems->Add("Connected");
			AddCrateForm->listView1->Items->Add(LVItem);
		}
		for each (CheckedList::value_type elem in pHrwList) {
			if (!elem->second) {
				LVItem = gcnew ListViewItem();
				LVItem->Text = elem->first;
				LVItem->SubItems->Add("-");
				LVItem->SubItems->Add("-");
				LVItem->SubItems->Add("Not connected");
				AddCrateForm->listView1->Items->Add(LVItem);
			}
		}
		
		if (AddCrateForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			;
		}
		else
		{
			;
		}
		
	}
//
// Set selection channels View menu option
private: System::Void SetupSelectionViewToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		 SetSltnViewForm^ vForm = gcnew SetSltnViewForm(% m_mainDataStruct);

		if (vForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			m_mainDataStruct.nbrRows = vForm->m_nrRows;
			Rows = vForm->m_nrRows;
			m_mainDataStruct.nbrColumns = vForm->m_columns;
			Cols = vForm->m_columns;
			
			vForm->Close();
			drawChnlsView(Rows, Cols, this, e);
		}
}

private: System::Boolean CreateServerPipes();
private: System::Boolean checkPipe(HANDLE pipe);
private: System::Void SendData2Pipe(HANDLE Pipe, String^ Data);
private: System::Void ExitToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	CloseAllAtExit(sender, e);
	/*if (SwitchAllChnlsOffAtEnd)
			SwitchALLChannelsOffToolStripMenuItem_Click(sender, e);
		try {
			if (Pipe_GuiAlive != nullptr)
				CloseHandle(Pipe_GuiAlive);
			if (Pipe4Data2File)
				CloseHandle(Pipe4Data2File);
			CommProcessHandler();
		}
		catch (Exception^ e) {
			;
		}
		Environment::Exit(0);
		Application::Exit();*/
	}
private: System::Void ExitToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
	CloseAllAtExit(sender, e);
	/*if (SwitchAllChnlsOffAtEnd)
			SwitchALLChannelsOffToolStripMenuItem_Click(sender, e);
		try {
			if (Pipe_GuiAlive != nullptr)
				CloseHandle(Pipe_GuiAlive);
			if (Pipe4Data2File)
				CloseHandle(Pipe4Data2File);
			CommProcessHandler();
		}
		catch (Exception^ e) {
			;
		}
		Environment::Exit(0);
		Application::Exit();*/
	}
private: System::Void OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	CloseAllAtExit(sender, e);
	/*if (SwitchAllChnlsOffAtEnd)
			SwitchALLChannelsOffToolStripMenuItem_Click(sender, e);
		try {
			if (Pipe_GuiAlive != nullptr)
				CloseHandle(Pipe_GuiAlive);
			if (Pipe4Data2File)
				CloseHandle(Pipe4Data2File);
			CommProcessHandler();
		}
		catch (Exception^ e) { 
			; 
		}
		Environment::Exit(0);
		Application::Exit();*/
	}

//
// logging channels->VoltageReadings into a text file
private: System::Void LoggingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	LogSltnForm^ logFileForm = gcnew LogSltnForm();
	String^ chnlNames =  "";

	logFileForm->m_DataFile.fileName = DataFile.fileName;
	logFileForm->m_FileRecordingName = DataFile.path + DataFile.fileName;
	logFileForm->m_RecordingTime = TimeDataRecording;
	for each (CheckedList::value_type elmnt in DataFile.monitoredChnls) {
		logFileForm->checkedListBox1->Items->Add(elmnt->first, elmnt->second);
	}
	if (logFileForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		Console::WriteLine("Returned to Main Gui from LogFileForm");
		
		DataFile.monitoredChnls.clear();
		for (int i = 0; i < logFileForm->checkedListBox1->Items->Count; i++) {
			String^	item = logFileForm->checkedListBox1->GetItemText(logFileForm->checkedListBox1->Items[i]);
			bool itemCheckedState = logFileForm->checkedListBox1->GetItemChecked(i);
			DataFile.monitoredChnls.insert(CheckedList::make_value(item, itemCheckedState));
			for (int j = 0; j < pChnlsViewList.size(); j++) {
				if (this->pChnlsViewList[j]->lbl2_NameChnlView->Text == item) {
					this->pChnlsViewList[j]->ChnlCnf->LoggingChnl = itemCheckedState;
				}
			}
			if (itemCheckedState) {
				if (chnlNames != "") chnlNames += ", ";
				chnlNames += item;
				chnlNames += ", ";
				chnlNames += "Volt_SP";
				chnlNames += ", ";
				chnlNames += "Current";
				chnlNames += ", ";
				chnlNames += "Current_SP";
				chnlNames += ", ";
				chnlNames += "Temperature";
			}
		}
		if (!String::IsNullOrEmpty(logFileForm->m_DataFile.fileName)) {// != nullptr)
			DataFile.fileName = logFileForm->m_DataFile.fileName;
			DataFile.path = logFileForm->m_DataFile.path;
		}
		DataFile.savingInterval = logFileForm->m_DataFile.savingInterval;
		logFileForm->Close();
		// Send new fileName and interval to SaveData thread and channels header names
		SendData2Pipe(Pipe4Data2File, MSG_FILE_NAME_HEADER + DataFile.path + DataFile.fileName);
		SendData2Pipe(Pipe4Data2File, MSG_CHNLS_NAMES_HEADER + chnlNames);
	}
}
//
// Save selection view settings in a XML file
private: System::Void ToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ myStream;
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

	Console::WriteLine("Save View Settings file selection dialog created");
	saveFileDialog1->InitialDirectory = DEFAULT_DATA_FILE_PATH;
	saveFileDialog1->Filter = "sel files (*.sel)|*.sel";
	saveFileDialog1->FilterIndex = 2;
	saveFileDialog1->RestoreDirectory = false;
	saveFileDialog1->AutoUpgradeEnabled = true;
	
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
		{
			// Insert code to read the stream here.
			// Iterate ChnlViewList and save in file chosen in an XML file
			XML_Classes::VC_XML^ confViewData = gcnew XML_Classes::VC_XML;
			confViewData->data->SelectedRows = this->Rows;
			confViewData->data->SelectedCols = this->Cols;
			confViewData->data->PercentageDeviationAllow = this->PercentageDeviationAllow;
			confViewData->data->VoltgDeviationAllow = this->VoltgDeviationAllow;
			confViewData->data->FilePathAndName = DataFile.path + DataFile.fileName;
			confViewData->data->TimeToRecordData = DataFile.savingInterval;
			confViewData->data->SwitchAllChnlsOffAtStart = SwitchAllChnlsOffAtStart;
			confViewData->data->SwitchAllChnlsOffAtEnd = SwitchAllChnlsOffAtEnd;
			XML_Classes::Channel^ channelViewConf = gcnew XML_Classes::Channel;
			System::IO::TextWriter^ writer =
				gcnew System::IO::StreamWriter(myStream);
			System::Xml::Serialization::XmlSerializer^ ser;
			cliext::vector<ChnlViewForm^>::iterator it = pChnlsViewList.begin();
			if (pChnlsViewList.size() > 0) {
				// Pass group List to correspondent objects
				for each (String ^ groupItem in pGroupNames) {
					XML_Classes::Group^ group = gcnew XML_Classes::Group();
					group->GroupName = groupItem;
					confViewData->data->ViewGroups->GroupsList->Add(group);
				}
				// Create the serializable object
				//Create object to be serialized and populate lists to dump into an XML file
				ser = gcnew System::Xml::Serialization::XmlSerializer(confViewData->GetType());
				EntityPredicate^ searchItem;
				XML_Classes::Crate^ foundItem;
				for (int i = 0; (it != pChnlsViewList.end()); i++, it++) {
					if (pChnlsViewList[i]->ChnlCnf->Visible) {
						XML_Classes::Channel^ chnl = gcnew XML_Classes::Channel();
						chnl->cpyData(pChnlsViewList[i]->ChnlCnf);
						//chnl->NomVoltage = pChnlsViewList[i]->lbl4_NomVoltChnlView->Text;
						chnl->NomCurrent = pChnlsViewList[i]->lbl6_NomCurrtChnlView->Text;
						chnl->State = pChnlsViewList[i]->lbl1_StatusChnlView->Text;
						if ((m_ptrMainCrateList->Count > 0)
							&& m_mainDataStruct.GetChnlConnectedStatus(pChnlsViewList[i]->ChnlCnf->ChannelName)){
							chnl->VoltageRise = m_mainDataStruct.GetChnlVoltRamp(pChnlsViewList[i]->ChnlCnf->ChannelName);
							chnl->VoltageFall = m_mainDataStruct.GetChnlVoltRamp(pChnlsViewList[i]->ChnlCnf->ChannelName);
							chnl->CurrentRise = m_mainDataStruct.GetChnlCrrntRamp(pChnlsViewList[i]->ChnlCnf->ChannelName);
							chnl->CurrentFall = m_mainDataStruct.GetChnlCrrntRamp(pChnlsViewList[i]->ChnlCnf->ChannelName);
							//chnl->LimitVoltage = m_mainDataStruct.GetChnlNomVolt(pChnlsViewList[i]->ChnlCnf->ChannelName);
							//chnl->LimitCurrent = m_mainDataStruct.GetChnlNomCrrnt(pChnlsViewList[i]->ChnlCnf->ChannelName);
							chnl->VoltageSet = m_mainDataStruct.GetChnlVoltSet(pChnlsViewList[i]->ChnlCnf->ChannelName);
							chnl->CurrentSet = m_mainDataStruct.GetChnlCrrntSet(pChnlsViewList[i]->ChnlCnf->ChannelName);
						}
						chnl->Active = pChnlsViewList[i]->ChnlCnf->LoggingChnl.ToString();
						chnl->row = chnl->Row;
						chnl->col = chnl->Col;
						confViewData->data->channels->ChannelsList->Add(chnl);
						channelViewConf = pChnlsViewList[i]->ChnlCnf;
						// If cmd not in List -> Add it
						XML_Classes::Crate^ crate = gcnew XML_Classes::Crate;
						crate->CrateName = gcnew String(pChnlsViewList[i]->ChnlCnf->GetCrateName());
						searchItem = gcnew EntityPredicate(crate->CrateName);
						foundItem = confViewData->data->CrateList->Find(gcnew Predicate<XML_Classes::Crate^>(searchItem, &EntityPredicate::CrateMatched));
						if (foundItem == nullptr) {
							confViewData->data->CrateList->Add(crate);
							Console::WriteLine("XML Crate added: {0}", crate->CrateName);
						}
					}
				}
				ser->Serialize(writer, confViewData);
				writer->Close();
			}
			myStream->Close();
		}
		else {
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::WriteLine("No new file especified... in file explorer window");
		}
		Console::WriteLine("Return from File selection dialog created");
	}
}
//
// Open/Load View selection view settings from a XML file
//
private: System::Void LoadCOnfViewFromFile_Click(System::Object^ sender, System::EventArgs^ e) {
	ConnectingOrLoading = true;
	String^ msgToUsr = "If continue, actual View Setting will be overwritten by an XML config file of your choice";
	String^ msgCaption = "Click Ok to overwrite or Cancel to cancel";
	MessageBoxButtons buttons = MessageBoxButtons::OKCancel;
	
	
	if (MessageBox::Show(msgToUsr, msgCaption, buttons) == System::Windows::Forms::DialogResult::OK) {
		Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		Console::WriteLine("Open View Settings file selection dialog created");
		openFileDialog1->InitialDirectory = DEFAULT_DATA_FILE_PATH;
		openFileDialog1->Filter = "sel files (*.sel)|*.sel";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = false;
		openFileDialog1->AutoUpgradeEnabled = true;
		XML_Classes::VC_XML^ confViewData = gcnew XML_Classes::VC_XML;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				if (m_cmdMsg->HrwConntd) {
					ToolStripMenuItem3_Click(sender, e);  // Disconnect
				}
				// Insert code to read the stream here.
				// Iterate ChnlViewList and open in file chosen in an XML file
				System::Xml::Serialization::XmlSerializer^ ser = gcnew System::Xml::Serialization::XmlSerializer(confViewData->GetType());
				String^ fileName = openFileDialog1->FileName;
				myStream->Close();
				try {
					System::IO::FileStream^ fs =
						gcnew System::IO::FileStream(fileName,
							System::IO::FileMode::Open);
					confViewData = (XML_Classes::VC_XML^) ser->Deserialize(fs);
					Console::WriteLine("View Settings XML file loaded");
					m_cmdMsg->StatusBarMsgIndex = 18;
					//m_cmdMsg->statusBarMsg = "View loaded from config file";
					fs->Close();
				}
				catch (Exception^ e) {
					Console::WriteLine("Error opening XML config file");
					m_cmdMsg->StatusBarMsgIndex = 19;
					//m_cmdMsg->statusBarMsg = "Error in loading View from config file";
				}
				//			
				myStream->Close();
			}
			else {
				myStream->Close();
				Console::ForegroundColor = ConsoleColor::Yellow;
				Console::WriteLine("No file especified... in file explorer window");
				m_cmdMsg->StatusBarMsgIndex = 20;
				//m_cmdMsg->statusBarMsg = "No config file especified";
			}
			Console::WriteLine("Return from Open selection dialog created");
			
		}

		if ((confViewData != nullptr) && (confViewData->data->CrateList->Count > 0)){
			// Insert crates no yet in crate main list:
			// Check crates from the XML conf file as well as crates from HrdwMainList
			// No double entries. First get crate from XML and include them in HrdList
			// Then process HrdwList to add crates contained in this list (the same as connect procedure)

			// Populate Crate Main List with crates from XML conf file
			/* Creates thread managing data saving (voltage) */
			ThreadStart^ progressBarThreadDelegate = gcnew ThreadStart(this, &MainForm::TaskBarProgress);
			Thread^ newThread2 = gcnew Thread(progressBarThreadDelegate);
			newThread2->Start();
			if (confViewData->data->CrateList->Count == m_ptrMainCrateList->Count) {

			}
			//
			// Re-populate groupNames list with object names loaded
			pGroupNames->Clear();
			for each (XML_Classes::Group ^ group in confViewData->data->ViewGroups->GroupsList) {
				String^ groupName = gcnew String(group->GroupName);
				pGroupNames->Add(groupName);
			}
			if (pGroupNames->Count == 0) {
				// Load default group names list
				for (int i = 0; i < NBR_GROUP_NAMES; i++) {
					String^ groupItem = gcnew String(DefaultGroups[i]);
					pGroupNames->Add(groupItem);
				}
			}
			SetupByGroupDynamicMenu_Builder();

			if (!m_cmdMsg->execRequest) {
				m_cmdMsg->strCmdsToExcList->Clear();
				for each (XML_Classes::Crate ^ crate in confViewData->data->CrateList) {
					if ((pHrwList->find(crate->CrateName)) == pHrwList->end()) {
						m_cmdMsg->GlobalAddSendCmds(crate->CrateName, "", CRATE_CMD, 0, false);
					}
				}
				m_cmdMsg->GlobalAddSendCmds("", "", -1, 0, true);
				if (!m_cmdMsg->cmdExecuted) {
					Console::WriteLine("Not answer in time from inserting new Crate");
				}
				else Console::WriteLine("New Crate created");
				
			}
			// Fill conf channel ViewList with data from XML channel List
			m_mainDataStruct.nbrRows = confViewData->data->SelectedRows;
			Rows = confViewData->data->SelectedRows;
			m_mainDataStruct.nbrColumns = confViewData->data->SelectedCols;
			Cols = confViewData->data->SelectedCols;
			PercentageDeviationAllow = confViewData->data->PercentageDeviationAllow;
			VoltgDeviationAllow = confViewData->data->VoltgDeviationAllow;
			if (!String::IsNullOrEmpty(confViewData->data->FilePathAndName)) {
				DataFile.path = Path::GetDirectoryName(confViewData->data->FilePathAndName) + "\\";
				DataFile.fileName = Path::GetFileName(confViewData->data->FilePathAndName);
			}
			if (confViewData->data->TimeToRecordData > 0)
				TimeDataRecording = confViewData->data->TimeToRecordData;
			SwitchAllChnlsOffAtStart = confViewData->data->SwitchAllChnlsOffAtStart;
			SwitchAllChnlsOffAtEnd = confViewData->data->SwitchAllChnlsOffAtEnd;
			M_ViewCnfList->Clear();
			int modNumber = -1;
			if (!m_cmdMsg->execRequest) {
				m_cmdMsg->CleanCmdsLists();
			}
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					XML_Classes::Channel^ chnlCnf = gcnew XML_Classes::Channel();
					for each (XML_Classes::Channel ^ chnl in confViewData->data->channels->ChannelsList) {
						if ((chnl->Row == i) && (chnl->Col == j)) {
							chnlCnf->cpyData(chnl);
							//break;
						}
						if (m_mainDataStruct.GetChnlConnectedStatus(chnlCnf->ChannelName)) {
							// Cmds for volt & current SP => validate SP and insert in cmd list
							m_cmdMsg->GlobalAddSendCmds(chnlCnf->ChannelName + ":VoltageSet", chnlCnf->VoltageSet, CHANNEL_CMD, 3, false);
							m_cmdMsg->GlobalAddSendCmds(chnlCnf->ChannelName + ":CurrentSet", chnlCnf->CurrentSet, CHANNEL_CMD, 3, false);
							// Cmds for Ramps
							if ((chnl->ModDir != modNumber)) {
								auto it = pHrwList->find(chnl->GetCrateName());
									if (it != pHrwList->end()) {
										auto ref = *it;
											if (ref->second) {
												String^ strExecCmd = chnlCnf->GetModName() + ":VoltageRampSpeed";
													Double val;
													!Double::TryParse(chnl->LimitVoltage, val);
													Double val2;
													!Double::TryParse(chnl->VoltageRise, val2);
													Math::Truncate(val);
												val = (val2 / val) * 100;
												val = Math::Round(val, 2);
												String^ strParam = System::Convert::ToString(val.ToString("0.##"));
												m_cmdMsg->GlobalAddSendCmds(strExecCmd, strParam, MODULE_CMD, 3, false);  // (cmd, param, target, cmdType, sendFlag)
											}
									}
								modNumber = chnl->ModDir;
							}
						}
					}
					M_ViewCnfList->Add(chnlCnf);
				}
			}
			//AddSendCmds("", "", -1, 3, true); // (cmd, param, target, cmdType, sendFlag)
			if (m_cmdMsg->strCmdsToExcList->Count > 0) 
				m_cmdMsg->GlobalAddSendCmds("", "", -1, 3, true);
			// Call drawChnlsView with number of Rows and columns from XML conf file
			drawChnlsView(Rows, Cols, this, e);
			if (pFreqCmds->size() > 0) {
				m_cmdMsg->ViewActive = true;
			}
			SetStateGroupToggleBtns(false);
			// After loaded View a check for hardware already connected is done to 
			// match channels in View with channels from hrw (if posssible)
			// this possible hrw connected come from Manu option Connect/Disconnect
			// and is done in the same drawChnlsView function
			
		}
	}
	ConnectingOrLoading = false;
}// End Load View
//
// Clear ALL channels, modules and crates from the Main system data structure
//
void CleanMainLists() {
	// Clear ALL crate main list
	for each (Crate ^ crate in m_ptrMainCrateList) {
		for each (Module ^ module in crate->m_lstModules) {
			// Clear existing channel List for each Module
			module->lstChannels->Clear();
		}
		// Clear existing Module List for each Crate
		crate->m_lstModules->Clear();
	}
	m_ptrMainCrateList->Clear();
}
//
// Thread function for showing a progress bar
void TaskBarProgress() {
	int horizontal = 0;
	int vertical = 0;
	ProgressDialog^ progressDialog = gcnew ProgressDialog();
	
	progressDialog->StartPosition = FormStartPosition::Manual;
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	horizontal = Screen::PrimaryScreen->Bounds.Width;
	vertical = Screen::PrimaryScreen->Bounds.Height;
	if ((this->Left < horizontal) ) {
		progressDialog->Location = System::Drawing::Point((this->Left + this->Width) / 2, (this->Top + this->Height) / 2);
	}
	else {
		progressDialog->Location = System::Drawing::Point(((this->Left + this->Width + horizontal) / 2) , (this->Top + this->Height) / 2);
	}
	progressDialog->ShowDialog(this->ParentForm);// == System::Windows::Forms::DialogResult::Cancel){
}
//
// Fill order to set ALL/Group channels state to OFF
//
private: System::Void SwitchALLChannelsOffToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		List<String^> cmdList;
		List<String^> paramList;
		cmdList.Add(":Control:setOn");
		paramList.Add("false");
		if (!SetChannelsCnfParam("AllChannels", % cmdList, % paramList))
			Console::Write("OFF cmds sent but not answer from Crate(s)");
		else {
			SetStateGroupToggleBtns(false);
		}
	}
//
// Set ALL Group(s) channels state (ON/OFF) by filling the cmd list to execute
private: System::Boolean SetChannelsCnfParam(String^ groupSet, List<String^>^ pCmdList, List<String^>^ pParamList) {
		if (!m_cmdMsg->execRequest) {
			m_cmdMsg->CleanCmdsLists();
			for each (ChnlViewForm ^ viewChnlItem in pChnlsViewList) {
				if (viewChnlItem->ChnlCnf->Visible && (viewChnlItem->ChnlCnf->ChnlType != 0)) {
					if ((groupSet == "AllChannels") || (viewChnlItem->ChnlCnf->Group == groupSet)) {
						// Include Channel cmd for changing state according to paramList
						// Iterate cmdList and paramList
						int i = 0;
						for each (String^ cmd in pCmdList){
							//String^ strExecCmd = viewChnlItem->ChnlCnf->ChannelName + /*":" + viewChnlItem->ChnlCnf->CrateLine + ":" + viewChnlItem->ChnlCnf->ModDir
							//	+ ":" + viewChnlItem->ChnlCnf->ChnlDir +*/ cmd;
							m_cmdMsg->GlobalAddSendCmds(viewChnlItem->ChnlCnf->ChannelName + /*":" + viewChnlItem->ChnlCnf->CrateLine + ":" + viewChnlItem->ChnlCnf->ModDir
															+ ":" + viewChnlItem->ChnlCnf->ChnlDir +*/ cmd,
														pParamList[i], CHANNEL_CMD, 4, false);
							Console::WriteLine("Channel {0} included to be {1} ", viewChnlItem->ChnlCnf->ViewName, cmd);
						}
					}
				}
			}
			
			if (m_cmdMsg->strCmdsToExcList->Count > 0) {
				m_cmdMsg->StatusBarMsgIndex = 5;
				//m_cmdMsg->statusBarMsg = "Sending commands";
			}
			else {
				Console::Write("No channels to turn OFF");
				m_cmdMsg->StatusBarMsgIndex = 21;
				//m_cmdMsg->statusBarMsg = "No commands to send";
			}
			m_cmdMsg->GlobalAddSendCmds("", "", -1, 4, true);
			if (m_cmdMsg->cmdExecuted) {
				// Load channel config info: vRamp, iRamp, vSetPoint, iSetPoint, NominalVolt, NominalCurrent.
				m_cmdMsg->CleanCmdsLists;
				Console::Write("OFF cmds executed ");
				m_cmdMsg->StatusBarMsgIndex = 6;
				//m_cmdMsg->statusBarMsg = "Set channels state cmds executed";
				return true;
			}
		}
		return false;
	}
//
// Setup groups... Menu option: Group cmds for RAMP settings
private: System::Void GetCmdsFromGroupCnfForm(String^ group) {
	if (m_cmdMsg->HrwConntd && (pChnlsViewList.size() > 0)) {
		if (!m_cmdMsg->execRequest) {
			GroupCnfSltn^ pCnfGroup = gcnew GroupCnfSltn(% m_mainDataStruct, pChnlsViewList);

			m_cmdMsg->CleanCmdsLists();
			pCnfGroup->Group = group;
			// Take references to populate Lists in the GroupCnfSltn form
			pCnfGroup->pCmdsList = m_cmdMsg->strCmdsToExcList;
			pCnfGroup->pParamList = m_cmdMsg->strParamsList;
			pCnfGroup->m_CmdMsg = m_cmdMsg;
			if (pCnfGroup->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				Console::WriteLine("Group settings: {0}", pCnfGroup->Group);
				if (m_cmdMsg->cmdExecuted) {
					m_cmdMsg->CleanCmdsLists();
					m_cmdMsg->StatusBarMsgIndex = 7; //ShowMsgOnStatusBar("RAMP conf settings executed");
					return;
				}

			}
			else {
				Console::WriteLine("Cancel group settings");
				m_cmdMsg->CleanCmdsLists();
			}
		}
	}
	else
		MessageBox::Show("None Hardware / View for group settings");
}
//
// Connect/ Disconnect
private: System::Void ToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
	static bool connectionState = false;
	ConnectingOrLoading = true;

	if (!connectionState && !m_cmdMsg->execRequest) {
		// Connection procedure
		//m_cmdMsg->GlobalAddSendCmds("DISCONNECT", "", -1, 5, true); // Order disconnect to reset COMM alarm
		m_cmdMsg->CleanCmdsLists();
		for each (CheckedList::value_type elem in pHrwList) { // Look for crates added
			if (!elem->second) {							  // If not connected => not in MainCrateList
				m_cmdMsg->GlobalAddSendCmds(elem->first, "", CRATE_CMD, 2, false);
			}
		}
		if (m_cmdMsg->strCmdsToExcList->Count > 0) {
			ThreadStart^ progressBarThreadDelegate = gcnew ThreadStart(this, &MainForm::TaskBarProgress);
			Thread^ newThread2 = gcnew Thread(progressBarThreadDelegate);
			newThread2->Start();
			
			m_cmdMsg->doCaSearch = true;
			m_cmdMsg->GlobalAddSendCmds("", "", -1, 2, true);
			int i = 0;
			while (!m_cmdMsg->cmdExecuted && i++ < 200 * (m_cmdMsg->strCmdsToExcList->Count))
				System::Threading::Thread::Sleep(100);
			if (!m_cmdMsg->cmdExecuted) {
				Console::WriteLine("Not answer in time from inserting new Crate(s)");
				newThread2->Abort();
			}
			else {
				Console::WriteLine("New Crate(s) created");
			}
		}
		else {
			Console::ForegroundColor = ConsoleColor::White;
			Console::WriteLine("Not hardware to add");
			//this->toolStripStatusLabel5->Text = "Not hardware to add";
			m_cmdMsg->StatusBarMsgIndex = 8;
			//m_cmdMsg->statusBarMsg = "No hardware to connect";
		}
		// Wait for the hardware to connect, MAX 10 sec
		
		// If hardware connected -> iterate view to scan Enable/Disable channels
		//Console::WriteLine(" i = {0}", i);
		int chnlsToScan = 0;
		bool found;
		String^ cmd;
		int modNmbr = -1;
		if (m_mainDataStruct.ptrMainCrateList->Count > 0) {
			if (!m_cmdMsg->execRequest) {
				m_cmdMsg->CleanCmdsLists();
				for each (FreqCmdsMapTable_T::value_type elem in pFreqCmds) {
					found = false;
					for (int i = 0; i < pChnlsViewList.size() && !found; i++) {
						if ((pChnlsViewList[i]->ChnlCnf->Visible) && (m_mainDataStruct.ptrMainCrateList->Count > 0)
							&& m_mainDataStruct.GetChnlEnableStatus(pChnlsViewList[i]->ChnlCnf->ChannelName)) {
							cmd = pChnlsViewList[i]->ChnlCnf->ChannelName;
							if (cmd == elem->first) {
								if (m_mainDataStruct.GetChnlEnableStatus(pChnlsViewList[i]->ChnlCnf->ChannelName)) {
									elem->second->scanned = true;
									chnlsToScan++;
								}
								else elem->second->scanned = false;
								found = true;
								// SP & Ramps
								if (m_mainDataStruct.GetChnlConnectedStatus(pChnlsViewList[i]->ChnlCnf->ChannelName)) {
									m_cmdMsg->GlobalAddSendCmds(pChnlsViewList[i]->ChnlCnf->ChannelName + ":VoltageSet", pChnlsViewList[i]->ChnlCnf->VoltageSet, CHANNEL_CMD, 3, false);
									m_cmdMsg->GlobalAddSendCmds(pChnlsViewList[i]->ChnlCnf->ChannelName + ":CurrentSet", pChnlsViewList[i]->ChnlCnf->CurrentSet, CHANNEL_CMD, 3, false);
									if ((modNmbr != pChnlsViewList[i]->ChnlCnf->ModDir) && (m_mainDataStruct.ptrMainCrateList->Count > 0)) {
										auto it = pHrwList->find(pChnlsViewList[i]->ChnlCnf->GetCrateName());
										if (it != pHrwList->end()) {
											auto ref = *it;
											if (ref->second) {
												String^ strExecCmd = pChnlsViewList[i]->ChnlCnf->GetModName() + ":VoltageRampSpeed";
												Double val;
												!Double::TryParse(pChnlsViewList[i]->ChnlCnf->LimitVoltage, val);
												Double val2;
												!Double::TryParse(pChnlsViewList[i]->ChnlCnf->VoltageRise, val2);
												Math::Truncate(val);
												val = (val2 / val) * 100;
												String^ strParam = System::Convert::ToString(val.ToString("0.##"));
												m_cmdMsg->GlobalAddSendCmds(strExecCmd, strParam, MODULE_CMD, 3, false);
											}
										}
										modNmbr = pChnlsViewList[i]->ChnlCnf->ModDir;
									}
								}
								pChnlsViewList[i]->txtBx1_VoltSPChnlView->Text = m_mainDataStruct.GetChnlVoltSet(pChnlsViewList[i]->ChnlCnf->ChannelName);
								pChnlsViewList[i]->vSetPoint = System::Convert::ToDouble(pChnlsViewList[i]->txtBx1_VoltSPChnlView->Text);
								pChnlsViewList[i]->vValue = System::Convert::ToDouble(m_mainDataStruct.GetChnlVoltMeas(pChnlsViewList[i]->ChnlCnf->ChannelName));
								pChnlsViewList[i]->txtBx2_CurrtSPChnlView->Text = m_mainDataStruct.GetChnlCrrntSet(pChnlsViewList[i]->ChnlCnf->ChannelName);
								pChnlsViewList[i]->cSetPoint = System::Convert::ToDouble(pChnlsViewList[i]->txtBx2_CurrtSPChnlView->Text);
								pChnlsViewList[i]->cValue = System::Convert::ToDouble(m_mainDataStruct.GetChnlCrrntMeas(pChnlsViewList[i]->ChnlCnf->ChannelName));
							}
						}
						else elem->second->scanned = false;
					}
				}
				m_cmdMsg->GlobalAddSendCmds("", "", -1, 3, true);   // (cmd, param, target, cmdType, sendFlag)
			}
		}
		if (chnlsToScan > 0) m_cmdMsg->ViewActive = true;
	}
	else if (connectionState && !m_cmdMsg->execRequest) {
		// Eliminate/Delete all Lists objects -> Channels->Mod's->Crates
		m_cmdMsg->ViewActive = false;
		m_cmdMsg->HrwConntd = false;
		CleanMainLists();
		// All hardware must be set not connected
		for each (CheckedList::value_type elem in pHrwList) {
			CheckedList::const_reference cref = elem;
			cref->second = false;
		}
		m_cmdMsg->GlobalAddSendCmds("DISCONNECT", "", -1, 5, true); // Order disconnect to reset COMM alarm
	}
	if (m_mainDataStruct.ptrMainCrateList->Count > 0) {
		m_cmdMsg->StatusBarMsgIndex = 9;
		for each (Crate ^ crate in m_mainDataStruct.ptrMainCrateList) {
			Console::WriteLine("Conected->: {0}, Modules= {1}, Channels: {2}, connected= {3} ", crate->Name, crate->Modules, crate->Channels, crate->VoltChnlsEnable);
		}
		connectionState = true;
		this->toolStripStatusLabel1->Text = "System status: Connected";
		this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile("C:\\GECA_VC_icons\\plugged.png")));
		m_cmdMsg->doCaSearch = false;
		if (SwitchAllChnlsOffAtStart) {
			m_cmdMsg->statusBarMsg2 = "Switching all channels OFF at start";
			System::Threading::Thread::Sleep(100);
			SwitchALLChannelsOffToolStripMenuItem_Click(sender, e);
		}
		for (int i = 0; i < pChnlsViewList.size(); i++) {
			if (pChnlsViewList[i]->Visible) {
				if (pChnlsViewList[i]->ChnlCnf->ChnlType != 0) {
					pChnlsViewList[i]->txtBx1_VoltSPChnlView->Text = m_mainDataStruct.GetChnlVoltSet(pChnlsViewList[i]->ChnlCnf->ChannelName);
					pChnlsViewList[i]->txtBx2_CurrtSPChnlView->Text = m_mainDataStruct.GetChnlCrrntSet(pChnlsViewList[i]->ChnlCnf->ChannelName);
				}
				Double chnlValue;
				if (!Double::TryParse(pChnlsViewList[i]->txtBx1_VoltSPChnlView->Text, chnlValue)) {
					pChnlsViewList[i]->vSetPoint = 0.0;
					pChnlsViewList[i]->vValue = 0.0;
				}
				else {
					pChnlsViewList[i]->vSetPoint = System::Convert::ToDouble(pChnlsViewList[i]->txtBx1_VoltSPChnlView->Text);
					pChnlsViewList[i]->vValue = System::Convert::ToDouble(m_mainDataStruct.GetChnlVoltMeas(pChnlsViewList[i]->ChnlCnf->ChannelName));
				}
				if (!Double::TryParse(pChnlsViewList[i]->txtBx2_CurrtSPChnlView->Text, chnlValue)) {
					pChnlsViewList[i]->cSetPoint = 0.0;
					pChnlsViewList[i]->cValue = 0.0;
				}
				else {
					pChnlsViewList[i]->cSetPoint = System::Convert::ToDouble(pChnlsViewList[i]->txtBx2_CurrtSPChnlView->Text);
					pChnlsViewList[i]->cValue = System::Convert::ToDouble(m_mainDataStruct.GetChnlCrrntMeas(pChnlsViewList[i]->ChnlCnf->ChannelName));
				}
			}
		}
		
		
	}
	else {
		if (connectionState) m_cmdMsg->StatusBarMsgIndex = 10; 
		connectionState = false;
		this->toolStripStatusLabel1->Text = "System status: Not connected";
		this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(Image::FromFile("C:\\GECA_VC_icons\\unplugged2.png")));

	}
	ConnectingOrLoading = false;
	newViewCnf = true; //Force to create New Data Structure in COMM
}
//
// Save crate hardware List
private: System::Void SaveCrateSettingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ myStream;
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

	Console::WriteLine("Save Hardware Settings file selection dialog created");
	saveFileDialog1->InitialDirectory = DEFAULT_DATA_FILE_PATH;
	saveFileDialog1->Filter = "sel files (*.sel)|*.sel";
	saveFileDialog1->FilterIndex = 2;
	saveFileDialog1->RestoreDirectory = false;
	saveFileDialog1->AutoUpgradeEnabled = true;

	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
		{
			// Iterate Hardware List and save its content in a chosen XML file  
			XML_Classes::CratesList^ crateList = gcnew XML_Classes::CratesList;
			System::Xml::Serialization::XmlSerializer^ ser = gcnew System::Xml::Serialization::XmlSerializer(crateList->GetType());
			System::IO::TextWriter^ writer =
				gcnew System::IO::StreamWriter(myStream);
			for each (CheckedList::value_type elem in pHrwList) {
				XML_Classes::Crate^ crateItem = gcnew XML_Classes::Crate;
				crateItem->CrateName = elem->first;
				crateList->CrateList->Add(crateItem);
			}
			if (crateList->CrateList->Count > 0) {
				ser->Serialize(writer, crateList);
				writer->Close();
			}
			myStream->Close();
		}
		else {
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::WriteLine("No new file especified... in file explorer window");
		}
		Console::WriteLine("Return from Crate File selection dialog created");
	}
}
//
// Load crate hardware List
private: System::Void LoadCrateSettingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int nbrCratesAdded;
	Stream^ myStream;
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	Console::WriteLine("Opened Crate Load Settings file selection dialog");
	openFileDialog1->InitialDirectory = DEFAULT_DATA_FILE_PATH;
	openFileDialog1->Filter = "sel files (*.sel)|*.sel";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = false;
	openFileDialog1->AutoUpgradeEnabled = true;
	XML_Classes::CratesList^ crateList = gcnew XML_Classes::CratesList;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			// Iterate CratesList loaded from the XML file and add crates to cmdsToExecute
			// and assembly the cmd 
			System::Xml::Serialization::XmlSerializer^ ser = gcnew System::Xml::Serialization::XmlSerializer(crateList->GetType());
			String^ fileName = openFileDialog1->FileName;
			myStream->Close();
			try {
				System::IO::FileStream^ fs =
					gcnew System::IO::FileStream(fileName,
						System::IO::FileMode::Open);
				crateList = (XML_Classes::CratesList^) ser->Deserialize(fs);
				Console::WriteLine("Crate Settings XML file loaded");
				fs->Close();
				//m_cmdMsg->statusBarMsg = ("Crate(s) file loaded: " + crateList->CrateList->Count + " crates to add");
				m_cmdMsg->statusBarMsg += crateList->CrateList->Count + " crates to add ";
				m_cmdMsg->StatusBarMsgIndex = 11;
			}
			catch (Exception^ e) {
				Console::WriteLine("Error opening XML config file");
			}
			//			
			myStream->Close();
		}
		else {
			myStream->Close();
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::WriteLine("No file especified... in file explorer window");
		}
		if (!m_cmdMsg->execRequest) {
			// Add crates to cmd list to added to hardwareList (Not to connect)
			nbrCratesAdded = pHrwList->size();
			m_cmdMsg->CleanCmdsLists();
			for each (XML_Classes::Crate ^ crate in crateList->CrateList) {
				m_cmdMsg->GlobalAddSendCmds(crate->CrateName, "", CRATE_CMD, 0, false);
				//m_cmdMsg->strCmdsToExcList->Add(crate->CrateName);
			}
			m_cmdMsg->GlobalAddSendCmds("", "", -1, 0, true);
		}
		int i = 0;
		while (!m_cmdMsg->cmdExecuted && i++ < 10 * (m_cmdMsg->strCmdsToExcList->Count))
			System::Threading::Thread::Sleep(100);
		for each (CheckedList::value_type crate in pHrwList) {
			Console::WriteLine("Crate added: {0} ", crate->first);
		}
		m_cmdMsg->statusBarMsg += (pHrwList->size() - nbrCratesAdded);
		m_cmdMsg->StatusBarMsgIndex = 12;
		//ShowMsgOnStatusBar("Crates added: " + (pHrwList->size() - nbrCratesAdded));
		
	}
}
//
// Set global settings menu option (Erros, deviation)
private: System::Void GlobalSettingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	GlobalSettingsForm^ globSetForm = gcnew GlobalSettingsForm();

	globSetForm->NewPercentage = this->PercentageDeviationAllow*100.0;
	globSetForm->NewAdditionalVoltError = this->VoltgDeviationAllow;
	globSetForm->m_RecordingTime = TimeDataRecording;
	globSetForm->PathName = this->DataFile.path;
	globSetForm->m_SwitchAllCnlsOffAtStart = this->SwitchAllChnlsOffAtStart;
	globSetForm->m_SwitchAllCnlsOffAtEnd = this->SwitchAllChnlsOffAtEnd;

	if (globSetForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		m_cmdMsg->statusBarMsg = "New global settings set";
		Console::ForegroundColor = ConsoleColor::White;
		Console::WriteLine(m_cmdMsg->statusBarMsg);
		if (globSetForm->NewPercentage != this->PercentageDeviationAllow*100.0)
			this->PercentageDeviationAllow = globSetForm->NewPercentage;
		if (globSetForm->NewAdditionalVoltError != this->VoltgDeviationAllow)
			this->VoltgDeviationAllow = globSetForm->NewAdditionalVoltError;
		TimeDataRecording = globSetForm->m_RecordingTime;
		this->DataFile.path = globSetForm->PathName;
		this->SwitchAllChnlsOffAtStart = globSetForm->m_SwitchAllCnlsOffAtStart;
		this->SwitchAllChnlsOffAtEnd = globSetForm->m_SwitchAllCnlsOffAtEnd;
	}
}
//
// Create Naming Group Names Form
private: System::Void ChannelNamesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	GroupNaming^ pNamingGroup = gcnew GroupNaming();

	for each(String ^ groupName in pGroupNames) {
		ListViewItem^ listItem = gcnew ListViewItem();
		listItem->Text = groupName;
		pNamingGroup->listView1->Items->Add(groupName);
		pNamingGroup->listView2->Items->Add((ListViewItem^) listItem->Clone());
	}
	pNamingGroup->listView1->Enabled = false;
	pNamingGroup->listView2->Enabled = true;
	if (pNamingGroup->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Copy the new channels group names to the group names list
		pGroupNames->Clear();
		for each (ListViewItem ^ itemGroup in pNamingGroup->listView2->Items) {
			String^ group = gcnew String(itemGroup->Text);
			pGroupNames->Add(group);
		}
		SetupByGroupDynamicMenu_Builder();
		m_cmdMsg->StatusBarMsgIndex = 13;
		//ShowMsgOnStatusBar("Group names List changed, check View");
	}
}
//
// Set Channels State On/Off by groups
private: System::Void GroupsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (pSetStatesByGroup == nullptr || pSetStatesByGroup->IsDisposed) {
		pSetStatesByGroup = gcnew SetStateByGroup(pGroupNames, m_cmdMsg, % pChnlsViewList);
		int horizontal = 0;
		int vertical = 0;
		pSetStatesByGroup->StartPosition = FormStartPosition::Manual;
		RECT desktop;
		// Get a handle to the desktop window
		const HWND hDesktop = GetDesktopWindow();
		horizontal = Screen::PrimaryScreen->Bounds.Width;
		vertical = Screen::PrimaryScreen->Bounds.Height;
		if ((this->Left < horizontal)) {
			pSetStatesByGroup->Location = System::Drawing::Point((this->Left + this->Width) / 2, (this->Top + this->Height) / 2);
		}
		else {
			pSetStatesByGroup->Location = System::Drawing::Point(((this->Left + this->Width + horizontal) / 2), (this->Top + this->Height) / 2);
		}
		if (pChnlsViewList.size() > 0) {
			//pSetStatesByGroup->Show(this->ParentForm);
			pSetStatesByGroup->Show();
			/*if (pSetStatesByGroup->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			}*/
		}
		else
			MessageBox::Show("Not Channels View for group setting states");
	}
	else pSetStatesByGroup->Activate();
}
//
//
private: System::Void ToolStripSplitButton1_ButtonClick(System::Object^ sender, System::EventArgs^ e) {
	//cliext::vector< System::Windows::Forms::ToolStripItem^>^ itemsArray = gcnew cliext::vector< System::Windows::Forms::ToolStripItem^  >(m_ptrMainCrateList->Count);
	Console::WriteLine("toolStripSplit");
	System::Windows::Forms::ToolStripMenuItem^ statusToolStripMenuItem;
	this->toolStripSplitButton1->DropDownItems->Clear();
	for each (Crate ^ crate in m_ptrMainCrateList) {
		statusToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		//itemsArray->push_back(statusToolStripMenuItem);
		statusToolStripMenuItem->Text = crate->Name;
		if (m_HrdwFailList->find(crate->Name) != m_HrdwFailList->end())
			statusToolStripMenuItem->ForeColor = System::Drawing::Color::Red;
		this->toolStripSplitButton1->DropDownItems->Add(statusToolStripMenuItem);
	}
}
//
// Show Msg on Status Bar
private: System::Void ShowMsgOnStatusBar(int msgIndex) {
	
	this->toolStripStatusLabel5->Text = "Msg:                                                ";
	if (msgIndex >= 0) {
		this->toolStripStatusLabel5->BackColor =  m_mainDataStruct.m_StatusBarMsgsArray[m_cmdMsg->StatusBarMsgIndex]->MsgBackColor;
		this->toolStripStatusLabel5->ForeColor = m_mainDataStruct.m_StatusBarMsgsArray[m_cmdMsg->StatusBarMsgIndex]->MsgForeColor;
		this->toolStripStatusLabel5->Text = "Msg: " + m_mainDataStruct.m_StatusBarMsgsArray[m_cmdMsg->StatusBarMsgIndex]->Msg + m_cmdMsg->statusBarMsg;
		this->Time2ClearStatusMsg = 0;
		m_cmdMsg->statusBarMsg = "";
		m_cmdMsg->StatusBarMsgIndex = -1;
	}
	else { 
		this->toolStripStatusLabel5->BackColor = System::Drawing::SystemColors::GrayText;
	}
}
private: System::Void ShowMsg2OnStatusBar(int msgIndex) {
			 this->toolStripStatusLabel2->Text = "Doing... ";
			 if (msgIndex >= 0) {
				 this->toolStripStatusLabel2->Text += m_cmdMsg->statusBarMsg2;
				 this->Time2ClearStatusMsg2 = 0;
				 m_cmdMsg->statusBarMsg2 = "";
			 }
			 //else toolStripStatusLabel2->Text = "";
 }
private: System::Boolean ValidateVoltgReading(String^ voltMeas, String^ voltSP);

private: System::Boolean EvaluateChannelFormula( String^ target, int chnlViewIndex);

//
// Event to catch user click for togglin channels On-Off by group
// Gets the button clicked and then calls setByGroup according to last state
//
private: System::Void ToggleGroup_Click(System::Object^ sender, System::EventArgs^ e) {
	List<String^> cmdList;
	List<String^> paramList;

	cmdList.Add(":Control:setOn");
	String^ btnName = safe_cast<ToolStripItem^>(sender)->Name;
	String^ btnGroupName = safe_cast<ToolStripItem^>(sender)->ToolTipText;
	//MessageBox::Show("\r\nButtonName: " + btnGroupName + "\r\nButtonState: " + "Selected");
	try {
		ToolStripItem^ btn = this->toolStrip1->Items->Find(btnName->ToString(), false)[0];
		auto color = btn->BackColor;
		if (String::Equals(btn->BackColor.ToString(), "Color [RosyBrown]")) {
			//MessageBox::Show("\r\nButtonName: " + btnGroupName + "\r\nButtonState: " + "Selected");
			paramList.Add("true");
			btn->BackColor = System::Drawing::Color::GreenYellow;
		}
		else {
			paramList.Add("false");
			btn->BackColor = System::Drawing::Color::RosyBrown;
		}

		if (SetChannelsCnfParam(btn->ToolTipText, % cmdList, % paramList)) {
			m_cmdMsg->CleanCmdsLists;
			m_cmdMsg->StatusBarMsgIndex = 6;
			Console::Write("Group Channels cmds sent ");
		}
		else {
			//btn->BackColor = color;
		}
	}
	catch (...) {}
} // ToggleGroup_Click END

//
// Sets Group direct buttoms action state: On/OFF
//
    private: 
	  System::Void SetStateGroupToggleBtns(bool state) {

	for each (ToolStripItem^ item in (this->toolStrip1->Items))
	{
		if (item->Name->Contains("TG") && !state) {
			item->BackColor = System::Drawing::Color::RosyBrown;
		}
	} 

}
	  System::Void CommProcessHandler();
	  System::Void CloseAllAtExit(System::Object^ sender, System::EventArgs^ e) {
				 if (SwitchAllChnlsOffAtEnd)
					 SwitchALLChannelsOffToolStripMenuItem_Click(sender, e);
				 try {
					 if (Pipe_GuiAlive != nullptr)
						 CloseHandle(Pipe_GuiAlive);
					 if (Pipe4Data2File)
						 CloseHandle(Pipe4Data2File);
					 CommProcessHandler();
				 }
				 catch (Exception^ e) {
					 ;
				 }
				 Environment::Exit(0);
				 Application::Exit();
			 }
	  System::Void SearchAndKillProc(String^ commProcName);

};
}


