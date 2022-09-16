#pragma once

/* Classes definitions */
#include "MyForm.h"
#include "Crate.h"

#include "GlobalsHeader.h"
//#include "CaInterfaceClass.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	using namespace ListTest_CLI_Project;
	
	

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		Crate^ crateInMainForm;
		cliext::vector<Double> m_voltageMeasurements;
		cliext::vector<Double> m_currentMeasurements;
		cliext::vector<String^> m_isOnStatus;
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
	private: System::Windows::Forms::ToolStripMenuItem^ setupGroupsToolStripMenuItem;
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

	private:

	private: System::Windows::Forms::ColumnHeader^ voltColumn;
	private: System::Windows::Forms::ColumnHeader^ columnOnStatus;
	private: System::Windows::Forms::ColumnHeader^ currentColumn;
	public:



	public:
		Form1(Crate^ crateValueObject)
		{
			crateInMainForm = gcnew Crate();
			m_voltageMeasurements = gcnew cliext::vector<Double>;
			m_currentMeasurements = gcnew cliext::vector<Double>;
			m_isOnStatus = gcnew cliext::vector<String^>;
			crateInMainForm = crateValueObject;
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}
		void mainFormEntryPoint() {
			//InitializeComponent();
		}
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^ button1;

	public:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ configToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;





	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::ListView^ listView1;
	private:

	private: System::Windows::Forms::Label^ label3;
	public:
	private:


	protected:

	protected:

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
			System::Windows::Forms::ListViewItem^ listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"Column 2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem6 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem7 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem8 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem9 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem10 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem11 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem12 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem13 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem14 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem15 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			System::Windows::Forms::ListViewItem^ listViewItem16 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"column1 text",
					L"column2 text", L"Column 3 text"
			}, -1));
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->setupGroupsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->voltColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->currentColumn = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnOnStatus = (gcnew System::Windows::Forms::ColumnHeader());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->button1->Location = System::Drawing::Point(150, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(222, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Got to 2nd form";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::Button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->toolsToolStripMenuItem, this->automationToolStripMenuItem, this->settingsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1198, 24);
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
			this->configToolStripMenuItem->Name = L"configToolStripMenuItem";
			this->configToolStripMenuItem->Size = System::Drawing::Size(207, 22);
			this->configToolStripMenuItem->Text = L"New Settings";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(207, 22);
			this->toolStripMenuItem2->Text = L"Save selection Settings ...";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(207, 22);
			this->toolStripMenuItem1->Text = L"Open selection Settings...";
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
			this->exitToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::ExitToolStripMenuItem1_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->setupSelectionViewToolStripMenuItem,
					this->toolStripSeparator3, this->mainSwitchToolStripMenuItem, this->switchALLChannelsOffToolStripMenuItem, this->toolStripSeparator4,
					this->setupGroupsToolStripMenuItem, this->groupsToolStripMenuItem, this->toolStripSeparator5, this->systemStateToolStripMenuItem,
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
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(197, 6);
			// 
			// mainSwitchToolStripMenuItem
			// 
			this->mainSwitchToolStripMenuItem->Name = L"mainSwitchToolStripMenuItem";
			this->mainSwitchToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->mainSwitchToolStripMenuItem->Text = L"Main switch";
			// 
			// switchALLChannelsOffToolStripMenuItem
			// 
			this->switchALLChannelsOffToolStripMenuItem->Name = L"switchALLChannelsOffToolStripMenuItem";
			this->switchALLChannelsOffToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->switchALLChannelsOffToolStripMenuItem->Text = L"Switch ALL channels off";
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(197, 6);
			// 
			// setupGroupsToolStripMenuItem
			// 
			this->setupGroupsToolStripMenuItem->Name = L"setupGroupsToolStripMenuItem";
			this->setupGroupsToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->setupGroupsToolStripMenuItem->Text = L"Setup groups...";
			// 
			// groupsToolStripMenuItem
			// 
			this->groupsToolStripMenuItem->Name = L"groupsToolStripMenuItem";
			this->groupsToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->groupsToolStripMenuItem->Text = L"Groups...";
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(197, 6);
			// 
			// systemStateToolStripMenuItem
			// 
			this->systemStateToolStripMenuItem->Name = L"systemStateToolStripMenuItem";
			this->systemStateToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->systemStateToolStripMenuItem->Text = L"System state...";
			// 
			// loggingToolStripMenuItem
			// 
			this->loggingToolStripMenuItem->Name = L"loggingToolStripMenuItem";
			this->loggingToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->loggingToolStripMenuItem->Text = L"Logging...";
			// 
			// automationToolStripMenuItem
			// 
			this->automationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->editCustomScriptsToolStripMenuItem,
					this->toolStripSeparator6, this->action1ToolStripMenuItem, this->action2ToolStripMenuItem, this->action3ToolStripMenuItem, this->action4ToolStripMenuItem,
					this->action5ToolStripMenuItem, this->action6ToolStripMenuItem, this->action7ToolStripMenuItem, this->action8ToolStripMenuItem,
					this->action9ToolStripMenuItem, this->action10ToolStripMenuItem
			});
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
			this->configureToolbarToolStripMenuItem->Name = L"configureToolbarToolStripMenuItem";
			this->configureToolbarToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->configureToolbarToolStripMenuItem->Text = L"Configure toolbar...";
			// 
			// globalSettingsToolStripMenuItem
			// 
			this->globalSettingsToolStripMenuItem->Name = L"globalSettingsToolStripMenuItem";
			this->globalSettingsToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->globalSettingsToolStripMenuItem->Text = L"Global settings...";
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
			// 
			// channelNamesToolStripMenuItem
			// 
			this->channelNamesToolStripMenuItem->Name = L"channelNamesToolStripMenuItem";
			this->channelNamesToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->channelNamesToolStripMenuItem->Text = L"Channel names";
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
			// 
			// saveCrateSettingsToolStripMenuItem
			// 
			this->saveCrateSettingsToolStripMenuItem->Name = L"saveCrateSettingsToolStripMenuItem";
			this->saveCrateSettingsToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->saveCrateSettingsToolStripMenuItem->Text = L"Save crate settings";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->showDebugWindowToolStripMenuItem,
					this->toolStripSeparator9, this->aboutProgramToolStripMenuItem, this->onlineHelpToolStripMenuItem
			});
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
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ExitToolStripMenuItem_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(167, 254);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"From 2nd thread";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::Timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(167, 217);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"From main thread ";
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->voltColumn, this->currentColumn,
					this->columnOnStatus
			});
			this->listView1->GridLines = true;
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(16) {
				listViewItem1, listViewItem2,
					listViewItem3, listViewItem4, listViewItem5, listViewItem6, listViewItem7, listViewItem8, listViewItem9, listViewItem10, listViewItem11,
					listViewItem12, listViewItem13, listViewItem14, listViewItem15, listViewItem16
			});
			this->listView1->LabelEdit = true;
			this->listView1->Location = System::Drawing::Point(752, 109);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(254, 303);
			this->listView1->TabIndex = 4;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// voltColumn
			// 
			this->voltColumn->Text = L"Voltage";
			this->voltColumn->Width = 95;
			// 
			// currentColumn
			// 
			this->currentColumn->Text = L"Currents";
			this->currentColumn->Width = 91;
			// 
			// columnOnStatus
			// 
			this->columnOnStatus->Text = L"OnStatus";
			this->columnOnStatus->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(749, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(191, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Module VOLT channels readings";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->ClientSize = System::Drawing::Size(1198, 709);
			this->ContextMenuStrip = this->contextMenuStrip1;
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"List Test & CLI for VC";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm ^ Form2Example = gcnew MyForm;
		String^ str = L"148.181.78.178";
		ListViewItem^ LVItem, ^ LVItem1;
		LVItem = gcnew ListViewItem();
		LVItem->Text = L"Crate List";

		Form2Example->testLabel->Text = L" Good ";
		Form2Example->listView1->Items->Add(LVItem);
		int x = Form2Example->listView1->Items->Count;
		Form2Example->listView1->BeginUpdate();
		
		/*if (Form2Example->addItem->Click()) {
			Form2Example->listView1->Items->Add(L"148.181.78.178");
		}*/
		
		if (Form2Example->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			LVItem->Text = L"148.181.78.178";
			Form2Example->listView1->Items->Add(L"148.181.78.178");
			Form2Example->listView1->Clear();
			;//Form2Example->testLabel->Text = L" Good ";
			Form2Example->listBox1->Items->Add(L"Crate List");
			Form2Example->listView1->Items->Add(str);
			int y = Form2Example->listView1->Items->Count;
			if (x != y) {
				; 
				MessageBox::Show(str + L" Item added to list");
				//Form2Example->ShowDialog();
			}
			Form2Example->panel1->Refresh();
			Form2Example->listView1->Update();
			Form2Example->Update();
			Form2Example->listBox1->Refresh();
		}
		else
		{
			
		}
		Form2Example->listView1->EndUpdate();
	}
private: System::Void ExitToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void ExitToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (!crateInMainForm->voltageMeasurements.empty())
		this->label1->Text = Globals::globalVar->ToString() + " " + crateInMainForm->voltageMeasurements.front();// Substring(0);
	
	//
	// Pending:
	// Copy crate volt, current & others lists form crate obj to local object and ubdate LISTVIEW from this local copy using Monitor
	// to avoid any possible effect on the user interface and the thread using CA 
	//
	m_voltageMeasurements.clear();
	m_currentMeasurements.clear();
	m_isOnStatus.clear();
	/* Monitor::Enter(this) */
	m_voltageMeasurements = crateInMainForm->voltageMeasurements;
	m_currentMeasurements = crateInMainForm->currentMeasurements;
	m_isOnStatus = crateInMainForm->isOnStatus;
	if (!crateInMainForm->voltageMeasurements.empty());
		//this->listView1->Items->Add(System::Convert::ToString(crateInMainForm->voltageMeasurements.at(crateInMainForm->voltageMeasurements.size() - 1)),
		//	                        System::Convert::ToString(crateInMainForm->voltageMeasurements.at(crateInMainForm->voltageMeasurements.size() - 1)));
	/* Monitor::Exit(this) */
	//this->listView1->Clear();
	//this->listView2->Clear();
	cliext::vector<double>::iterator it = m_voltageMeasurements.begin();
	for (int i=0; it != m_voltageMeasurements.end(); ++it, i++) {
		this->listView1->Items[i]->Text= (System::Convert::ToString(*it));
		this->listView1->Items[i]->SubItems[1]->Text = m_currentMeasurements[i].ToString();
		this->listView1->Items[i]->SubItems[2]->Text = m_isOnStatus[i];
		
		//this->listView1->Items[i]->Text = (System::Convert::ToString(*it)); //Add(System::Convert::ToString(*it));
		//this->listView2->Items->Add(System::Convert::ToString(*it));*/
		//this->listView1->Items->Add(item);
	}
	//if (crateInMainForm->voltageMeasurements.size() > 1) crateInMainForm->voltageMeasurements.pop_back();
	if (crateInMainForm != nullptr) this->label2->Text = crateInMainForm->Name + ":" + crateInMainForm->Address + "   Status:  " + System::Convert::ToInt16 (crateInMainForm->Status);
}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	ListViewItem^ row;
	
	for (int i = 0; i < MAX_CHANNELS; i++) {
		;
		/*row = gcnew ListViewItem("Text column " + System::Convert::ToString(i));
		row->SubItems->Add("Text column " + System::Convert::ToString(i));
		this->listView1->Items->Add(row);*/
	}
}
};
}

