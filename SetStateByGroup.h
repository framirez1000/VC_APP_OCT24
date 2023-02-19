#pragma once
#include "GlobalsHeader.h"
#include "ChnlViewForm.h"
namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace DraggableControls;
	
	/// <summary>
	/// Summary for SetStateByGroup
	/// </summary>
	public ref class SetStateByGroup : public System::Windows::Forms::Form
	{
		
		property List<String^ > ^ m_pGroupNames;
		property SingletonCmmdClass^ m_cmdMsg;
		property cliext::vector <ChnlViewForm^>^ m_pChnlsViewList;
	
	public:
		SetStateByGroup(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		SetStateByGroup(List<String^>^ pGroupNames, SingletonCmmdClass^ pCmdMsg, cliext::vector <ChnlViewForm^>^ pChnlsViewList)
		{
			InitializeComponent();
			m_pGroupNames = pGroupNames;
			//m_cmdMsg = pCmdMsg;
			m_cmdMsg = SingletonCmmdClass::Instance;
			m_pChnlsViewList = pChnlsViewList;
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SetStateByGroup()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	private: System::Windows::Forms::Button^ btn2_Exit;
	private: System::Windows::Forms::Label^ lbl1_On;
	private: System::Windows::Forms::Label^ lbl2_Off;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn2_Exit = (gcnew System::Windows::Forms::Button());
			this->lbl1_On = (gcnew System::Windows::Forms::Label());
			this->lbl2_Off = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn2_Exit
			// 
			this->btn2_Exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn2_Exit->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn2_Exit->Location = System::Drawing::Point(182, 563);
			this->btn2_Exit->Name = L"btn2_Exit";
			this->btn2_Exit->Size = System::Drawing::Size(146, 34);
			this->btn2_Exit->TabIndex = 0;
			this->btn2_Exit->Text = L"Exit";
			this->btn2_Exit->UseVisualStyleBackColor = true;
			this->btn2_Exit->Click += gcnew System::EventHandler(this, &SetStateByGroup::Btn2_Exit_Click);
			// 
			// lbl1_On
			// 
			this->lbl1_On->AutoSize = true;
			this->lbl1_On->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lbl1_On->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl1_On->ForeColor = System::Drawing::Color::White;
			this->lbl1_On->Location = System::Drawing::Point(80, 12);
			this->lbl1_On->Name = L"lbl1_On";
			this->lbl1_On->Size = System::Drawing::Size(86, 13);
			this->lbl1_On->TabIndex = 1;
			this->lbl1_On->Text = L"Set Group ON";
			// 
			// lbl2_Off
			// 
			this->lbl2_Off->AutoSize = true;
			this->lbl2_Off->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->lbl2_Off->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl2_Off->ForeColor = System::Drawing::Color::White;
			this->lbl2_Off->Location = System::Drawing::Point(320, 12);
			this->lbl2_Off->Name = L"lbl2_Off";
			this->lbl2_Off->Size = System::Drawing::Size(91, 13);
			this->lbl2_Off->TabIndex = 1;
			this->lbl2_Off->Text = L"Set Group OFF";
			// 
			// SetStateByGroup
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::Black;
			this->CancelButton = this->btn2_Exit;
			this->ClientSize = System::Drawing::Size(521, 609);
			this->Controls->Add(this->lbl2_Off);
			this->Controls->Add(this->lbl1_On);
			this->Controls->Add(this->btn2_Exit);
			this->Name = L"SetStateByGroup";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"SetStateByGroup";
			this->Load += gcnew System::EventHandler(this, &SetStateByGroup::NamingGroupForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//	
// Form Load
private: System::Void NamingGroupForm_Load(System::Object^ sender, System::EventArgs^ e) {
	int posX = 60, deltaX = 240;
	int posY = 30, deltaY = 45;
	int i = 0;

	for each (String ^ group in m_pGroupNames) {
		// Create ON button
		Button^ btnOn = gcnew System::Windows::Forms::Button();
		btnOn->Location = System::Drawing::Point(posX, posY);
		btnOn->Name = L"ON";
		btnOn->Size = System::Drawing::Size(146, 30);
		btnOn->TabIndex = 0;
		btnOn->Text = group;
		btnOn->UseVisualStyleBackColor = true;
		btnOn->Visible = true;
		btnOn->Enabled = true;
		btnOn->AllowDrop = true;
		ControlExtension::Draggable(btnOn, true);
		btnOn->Click += gcnew System::EventHandler(this, &SetStateByGroup::btnOnOff_Click);
		this->Controls->Add(btnOn);
		
		// Create OFF button
		Button^ btnOff = gcnew System::Windows::Forms::Button();
		btnOff->Location = System::Drawing::Point(posX + deltaX, posY);
		btnOff->Name = L"OFF";
		btnOff->Size = System::Drawing::Size(146, 30);
		btnOff->TabIndex = 0;
		btnOff->Text = group;
		btnOff->UseVisualStyleBackColor = true;
		btnOff->Visible = true;
		btnOff->Enabled = true;
		btnOff->AllowDrop = true;
		ControlExtension::Draggable(btnOff, true);
		
		btnOff->Click += gcnew System::EventHandler(this, &SetStateByGroup::btnOnOff_Click);
		this->Controls->Add(btnOff);
		posY += deltaY;
		}
	}
private: System::Void Btn2_Exit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btnOnOff_Click(System::Object^ sender, System::EventArgs^ e) {
	if (m_cmdMsg->HrwConntd) {
		String^ param = gcnew String("false");
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^) sender;
		if (btn->Name == "ON") {
			param = "true";
		}
		if (!SetChannelsCnfParam(btn->Text, ":Control:setOn", param))
			Console::WriteLine("Group OFF cmds sent but not answer from Crate(s)");
		else Console::WriteLine("Group OFF cmds sent successfully");

		Console::WriteLine(btn->Text + " Set to -> " + btn->Name);
	}
	else {
		Console::WriteLine("Nothing to set, no hardware connected");
	}
	this->ActiveControl = this->btn2_Exit;
}
//
// Fill cmd function to be execeuted by ThreadIO
private: System::Boolean SetChannelsCnfParam(String^ groupSet, String^ cmd, String^ param) {
	if (!m_cmdMsg->execRequest) {
		m_cmdMsg->CleanCmdsLists();
		if (m_cmdMsg->HrwConntd) {
			for each (ChnlViewForm ^ viewChnlItem in m_pChnlsViewList) {
				if (viewChnlItem->ChnlCnf->Visible){// && !viewChnlItem->ChnlCnf->UseVoltageFormula) {
					if ((groupSet == "AllChannels") || (viewChnlItem->ChnlCnf->Group == groupSet)) {
						// Include Channel cmd for changing state according to paramList
						m_cmdMsg->GlobalAddSendCmds(viewChnlItem->ChnlCnf->ChannelName + /*":" + viewChnlItem->ChnlCnf->CrateLine + ":" + viewChnlItem->ChnlCnf->ModDir
															+ ":" + viewChnlItem->ChnlCnf->ChnlDir +*/ cmd,
														param, CHANNEL_CMD, 4, false);
							Console::WriteLine("Channel {0} included to be {1} ", viewChnlItem->ChnlCnf->ViewName, cmd);
					}
				}
			}

			m_cmdMsg->GlobalAddSendCmds("", "", -1, 4, true);
			if (m_cmdMsg->cmdExecuted) {
				// Load channel config info: vRamp, iRamp, vSetPoint, iSetPoint, NominalVolt, NominalCurrent.
				m_cmdMsg->CleanCmdsLists();
				Console::Write("On/Off cmds executed");
				return true;
			}
		}
		else {
			m_cmdMsg->statusBarMsg = "Nothing to set";
			Console::WriteLine("Nothing to set, no hardware connected");
		}
	}
	return false;
}
};
}
