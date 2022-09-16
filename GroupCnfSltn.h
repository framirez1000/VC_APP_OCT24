#pragma once
#include "Crate.h"
#include "ChnlViewForm.h"
#include "MainHeader.h"
#include "SearchListPredicate.h"
namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GroupCnfSltn
	/// </summary>
	public ref class GroupCnfSltn : public System::Windows::Forms::Form
	{
	public: property SingletonCmmdClass^ m_CmdMsg;
			property CratesT^ pMainDataStruct;
	public:
		GroupCnfSltn(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		GroupCnfSltn(CratesT^ ptrMainDataStruct, cliext::vector<ChnlViewForm^> pChnlsViewList)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			pMainDataStruct = ptrMainDataStruct;
			pCrateList = ptrMainDataStruct->ptrMainCrateList;
			pChnlsView = pChnlsViewList;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GroupCnfSltn()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl1_V_RR;
	protected:
	private: System::Windows::Forms::Label^ lbl2_V_FR;
	private: System::Windows::Forms::Label^ lbl3_C_RR;
	private: System::Windows::Forms::Label^ lbl4_C_FR;
	private: System::Windows::Forms::TextBox^ txtBx1_V_RR;
	private: System::Windows::Forms::TextBox^ txtBx2_V_FR;
	private: System::Windows::Forms::TextBox^ txtBx3_C_RR;
	private: System::Windows::Forms::TextBox^ txtBx4_C_FR;
	private: System::Windows::Forms::CheckBox^ chckBx1_V_RR;
	private: System::Windows::Forms::CheckBox^ chckBx2_V_FR;
	private: System::Windows::Forms::CheckBox^ chckBx3_C_RR;
	private: System::Windows::Forms::CheckBox^ chckBx4_C_FR;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ lbl5_Cnf_Grp;
	private: System::Windows::Forms::Button^ bttn1_OK;
	private: System::Windows::Forms::Button^ bttn2_Cancel;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
	public:
		cliext::vector<ChnlViewForm^> pChnlsView;
		property String^ Group;
		property String^ NominalVoltage;
		property String^ NominalCurrent;
		property List < Crate^>^ pCrateList;
		property List<String^>^ pCmdsList;
		property List < String^>^ pParamList;
		property String^ VltgRampText;
		property String^ CrrntRampText;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl1_V_RR = (gcnew System::Windows::Forms::Label());
			this->lbl2_V_FR = (gcnew System::Windows::Forms::Label());
			this->lbl3_C_RR = (gcnew System::Windows::Forms::Label());
			this->lbl4_C_FR = (gcnew System::Windows::Forms::Label());
			this->txtBx1_V_RR = (gcnew System::Windows::Forms::TextBox());
			this->txtBx2_V_FR = (gcnew System::Windows::Forms::TextBox());
			this->txtBx3_C_RR = (gcnew System::Windows::Forms::TextBox());
			this->txtBx4_C_FR = (gcnew System::Windows::Forms::TextBox());
			this->chckBx1_V_RR = (gcnew System::Windows::Forms::CheckBox());
			this->chckBx2_V_FR = (gcnew System::Windows::Forms::CheckBox());
			this->chckBx3_C_RR = (gcnew System::Windows::Forms::CheckBox());
			this->chckBx4_C_FR = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lbl5_Cnf_Grp = (gcnew System::Windows::Forms::Label());
			this->bttn1_OK = (gcnew System::Windows::Forms::Button());
			this->bttn2_Cancel = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbl1_V_RR
			// 
			this->lbl1_V_RR->AutoSize = true;
			this->lbl1_V_RR->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lbl1_V_RR->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl1_V_RR->Location = System::Drawing::Point(44, 42);
			this->lbl1_V_RR->Name = L"lbl1_V_RR";
			this->lbl1_V_RR->Size = System::Drawing::Size(93, 13);
			this->lbl1_V_RR->TabIndex = 0;
			this->lbl1_V_RR->Text = L"Voltage Rise Rate";
			// 
			// lbl2_V_FR
			// 
			this->lbl2_V_FR->AutoSize = true;
			this->lbl2_V_FR->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl2_V_FR->Location = System::Drawing::Point(44, 69);
			this->lbl2_V_FR->Name = L"lbl2_V_FR";
			this->lbl2_V_FR->Size = System::Drawing::Size(88, 13);
			this->lbl2_V_FR->TabIndex = 0;
			this->lbl2_V_FR->Text = L"Voltage Fall Rate";
			// 
			// lbl3_C_RR
			// 
			this->lbl3_C_RR->AutoSize = true;
			this->lbl3_C_RR->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl3_C_RR->Location = System::Drawing::Point(44, 135);
			this->lbl3_C_RR->Name = L"lbl3_C_RR";
			this->lbl3_C_RR->Size = System::Drawing::Size(91, 13);
			this->lbl3_C_RR->TabIndex = 0;
			this->lbl3_C_RR->Text = L"Current Rise Rate";
			// 
			// lbl4_C_FR
			// 
			this->lbl4_C_FR->AutoSize = true;
			this->lbl4_C_FR->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl4_C_FR->Location = System::Drawing::Point(41, 163);
			this->lbl4_C_FR->Name = L"lbl4_C_FR";
			this->lbl4_C_FR->Size = System::Drawing::Size(86, 13);
			this->lbl4_C_FR->TabIndex = 0;
			this->lbl4_C_FR->Text = L"Current Fall Rate";
			// 
			// txtBx1_V_RR
			// 
			this->txtBx1_V_RR->Location = System::Drawing::Point(178, 40);
			this->txtBx1_V_RR->Name = L"txtBx1_V_RR";
			this->txtBx1_V_RR->Size = System::Drawing::Size(131, 20);
			this->txtBx1_V_RR->TabIndex = 1;
			this->txtBx1_V_RR->Text = L"100.0 V/s";
			this->txtBx1_V_RR->Leave += gcnew System::EventHandler(this, &GroupCnfSltn::TxtBx1_V_RR_Leave);
			// 
			// txtBx2_V_FR
			// 
			this->txtBx2_V_FR->Enabled = false;
			this->txtBx2_V_FR->Location = System::Drawing::Point(178, 66);
			this->txtBx2_V_FR->Name = L"txtBx2_V_FR";
			this->txtBx2_V_FR->Size = System::Drawing::Size(131, 20);
			this->txtBx2_V_FR->TabIndex = 2;
			this->txtBx2_V_FR->Text = L"1.000 V/s";
			// 
			// txtBx3_C_RR
			// 
			this->txtBx3_C_RR->Location = System::Drawing::Point(178, 132);
			this->txtBx3_C_RR->Name = L"txtBx3_C_RR";
			this->txtBx3_C_RR->Size = System::Drawing::Size(131, 20);
			this->txtBx3_C_RR->TabIndex = 3;
			this->txtBx3_C_RR->Text = L"100.0 A/s";
			this->txtBx3_C_RR->Leave += gcnew System::EventHandler(this, &GroupCnfSltn::TxtBx3_C_RR_Leave);
			// 
			// txtBx4_C_FR
			// 
			this->txtBx4_C_FR->Enabled = false;
			this->txtBx4_C_FR->Location = System::Drawing::Point(178, 158);
			this->txtBx4_C_FR->Name = L"txtBx4_C_FR";
			this->txtBx4_C_FR->Size = System::Drawing::Size(131, 20);
			this->txtBx4_C_FR->TabIndex = 4;
			this->txtBx4_C_FR->Text = L"1.000 A/s";
			// 
			// chckBx1_V_RR
			// 
			this->chckBx1_V_RR->AutoSize = true;
			this->chckBx1_V_RR->Checked = true;
			this->chckBx1_V_RR->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chckBx1_V_RR->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->chckBx1_V_RR->Location = System::Drawing::Point(355, 41);
			this->chckBx1_V_RR->Name = L"chckBx1_V_RR";
			this->chckBx1_V_RR->Size = System::Drawing::Size(105, 17);
			this->chckBx1_V_RR->TabIndex = 5;
			this->chckBx1_V_RR->Text = L"Use for selection";
			this->chckBx1_V_RR->UseVisualStyleBackColor = true;
			// 
			// chckBx2_V_FR
			// 
			this->chckBx2_V_FR->AutoSize = true;
			this->chckBx2_V_FR->Checked = true;
			this->chckBx2_V_FR->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chckBx2_V_FR->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->chckBx2_V_FR->Location = System::Drawing::Point(355, 64);
			this->chckBx2_V_FR->Name = L"chckBx2_V_FR";
			this->chckBx2_V_FR->Size = System::Drawing::Size(105, 17);
			this->chckBx2_V_FR->TabIndex = 6;
			this->chckBx2_V_FR->Text = L"Use for selection";
			this->chckBx2_V_FR->UseVisualStyleBackColor = true;
			// 
			// chckBx3_C_RR
			// 
			this->chckBx3_C_RR->AutoSize = true;
			this->chckBx3_C_RR->Checked = true;
			this->chckBx3_C_RR->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chckBx3_C_RR->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->chckBx3_C_RR->Location = System::Drawing::Point(355, 131);
			this->chckBx3_C_RR->Name = L"chckBx3_C_RR";
			this->chckBx3_C_RR->Size = System::Drawing::Size(105, 17);
			this->chckBx3_C_RR->TabIndex = 7;
			this->chckBx3_C_RR->Text = L"Use for selection";
			this->chckBx3_C_RR->UseVisualStyleBackColor = true;
			// 
			// chckBx4_C_FR
			// 
			this->chckBx4_C_FR->AutoSize = true;
			this->chckBx4_C_FR->Checked = true;
			this->chckBx4_C_FR->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chckBx4_C_FR->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->chckBx4_C_FR->Location = System::Drawing::Point(355, 159);
			this->chckBx4_C_FR->Name = L"chckBx4_C_FR";
			this->chckBx4_C_FR->Size = System::Drawing::Size(105, 17);
			this->chckBx4_C_FR->TabIndex = 8;
			this->chckBx4_C_FR->Text = L"Use for selection";
			this->chckBx4_C_FR->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::Control;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->lbl5_Cnf_Grp, 0, 0);
			this->tableLayoutPanel1->Enabled = false;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(481, 28);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// lbl5_Cnf_Grp
			// 
			this->lbl5_Cnf_Grp->AutoSize = true;
			this->lbl5_Cnf_Grp->Location = System::Drawing::Point(3, 0);
			this->lbl5_Cnf_Grp->Name = L"lbl5_Cnf_Grp";
			this->lbl5_Cnf_Grp->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->lbl5_Cnf_Grp->Size = System::Drawing::Size(102, 18);
			this->lbl5_Cnf_Grp->TabIndex = 0;
			this->lbl5_Cnf_Grp->Text = L"Configure Selection ";
			// 
			// bttn1_OK
			// 
			this->bttn1_OK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->bttn1_OK->Location = System::Drawing::Point(44, 217);
			this->bttn1_OK->Name = L"bttn1_OK";
			this->bttn1_OK->Size = System::Drawing::Size(159, 23);
			this->bttn1_OK->TabIndex = 10;
			this->bttn1_OK->Text = L"OK";
			this->bttn1_OK->UseVisualStyleBackColor = true;
			this->bttn1_OK->Click += gcnew System::EventHandler(this, &GroupCnfSltn::Bttn1_OK_Click);
			// 
			// bttn2_Cancel
			// 
			this->bttn2_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->bttn2_Cancel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->bttn2_Cancel->Location = System::Drawing::Point(273, 217);
			this->bttn2_Cancel->Name = L"bttn2_Cancel";
			this->bttn2_Cancel->Size = System::Drawing::Size(159, 23);
			this->bttn2_Cancel->TabIndex = 11;
			this->bttn2_Cancel->Text = L"Cancel";
			this->bttn2_Cancel->UseVisualStyleBackColor = true;
			this->bttn2_Cancel->Click += gcnew System::EventHandler(this, &GroupCnfSltn::Bttn2_Cancel_Click);
			// 
			// GroupCnfSltn
			// 
			this->AcceptButton = this->bttn1_OK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->CancelButton = this->bttn2_Cancel;
			this->ClientSize = System::Drawing::Size(481, 262);
			this->ControlBox = false;
			this->Controls->Add(this->bttn2_Cancel);
			this->Controls->Add(this->bttn1_OK);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->chckBx4_C_FR);
			this->Controls->Add(this->chckBx3_C_RR);
			this->Controls->Add(this->chckBx2_V_FR);
			this->Controls->Add(this->chckBx1_V_RR);
			this->Controls->Add(this->txtBx4_C_FR);
			this->Controls->Add(this->txtBx3_C_RR);
			this->Controls->Add(this->txtBx2_V_FR);
			this->Controls->Add(this->txtBx1_V_RR);
			this->Controls->Add(this->lbl4_C_FR);
			this->Controls->Add(this->lbl3_C_RR);
			this->Controls->Add(this->lbl2_V_FR);
			this->Controls->Add(this->lbl1_V_RR);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GroupCnfSltn";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GroupCnfSltn";
			this->Load += gcnew System::EventHandler(this, &GroupCnfSltn::GroupCnfSltn_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void TxtBx1_V_RR_Leave(System::Object^ sender, System::EventArgs^ e) {
	txtBx1_V_RR->Modified = true;
}
private: System::Void TxtBx3_C_RR_Leave(System::Object^ sender, System::EventArgs^ e) {
	txtBx3_C_RR->Modified = true;
}
//
// Accept changes
private: System::Void Bttn1_OK_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ msgToUser = nullptr;
	
	this->DialogResult = System::Windows::Forms::DialogResult::None;
	
	if ((!String::IsNullOrEmpty(txtBx1_V_RR->Text) && txtBx1_V_RR->Modified) ||
		(!String::IsNullOrEmpty(txtBx3_C_RR->Text) && txtBx3_C_RR->Modified)) {
		Double voltRamp, crrntRamp;
		bool vltInputValid = Double::TryParse(txtBx1_V_RR->Text, voltRamp);
		bool crrntInputValid = Double::TryParse(txtBx3_C_RR->Text, crrntRamp);
		if ((!vltInputValid) && (!crrntInputValid)) {
			Console::WriteLine("Input error");
			if (txtBx1_V_RR->Modified) txtBx1_V_RR->Text = VltgRampText;
			if (txtBx3_C_RR->Modified) txtBx3_C_RR->Text = CrrntRampText;
		}
		else{
			EntityPredicate^ searchItem;
			String^ foundItem;
			for each (ChnlViewForm ^ chnl in pChnlsView) {
				if (chnl->ChnlCnf->Group == Group) {
					if (pMainDataStruct->GetChnlConnectedStatus(chnl->ChnlCnf->ChannelName)) {
						NominalVoltage = pCrateList[chnl->ChnlCnf->CrateDir]->m_lstModules[chnl->ChnlCnf->ModDir]->lstChannels[chnl->ChnlCnf->ChnlDir]->VoltageNominal;
						Double nomVltg = System::Convert::ToDouble(NominalVoltage);
						if (txtBx1_V_RR->Modified && GlobalFuncValidateSP(txtBx1_V_RR->Text, NominalVoltage, 0.0, 0.20)) {
							// New Voltage Ramp valued validated, trasform to % of Nominal Voltage 
							// and insert Cmd
							Double voltRampPercentage = (voltRamp / nomVltg) * 100;
							String^ strExecCmd = chnl->ChnlCnf->GetModName() + ":VoltageRampSpeed";
							// If cmd not in List -> Add it
							searchItem = gcnew EntityPredicate(strExecCmd);
							foundItem = pCmdsList->Find(gcnew Predicate<String^>(searchItem, &EntityPredicate::Matched));
							if (foundItem == nullptr) {
								m_CmdMsg->GlobalAddSendCmds(strExecCmd,	voltRampPercentage.ToString(), MODULE_CMD, 3, false);
								this->DialogResult = System::Windows::Forms::DialogResult::OK;
							}
						}
						else 
							if (txtBx1_V_RR->Modified) {
								//txtBx1_V_RR->Text = VltgRampText;
								m_CmdMsg->statusBarMsg = "Input value error - ";
							}

						NominalCurrent = pCrateList[chnl->ChnlCnf->CrateDir]->m_lstModules[chnl->ChnlCnf->ModDir]->lstChannels[chnl->ChnlCnf->ChnlDir]->CurrentNominal;
						Double nomCurrent = System::Convert::ToDouble(NominalCurrent);
						if (txtBx3_C_RR->Modified && GlobalFuncValidateSP(txtBx1_V_RR->Text, NominalCurrent, 0.1E-10, 1.0)) {
							// New Current Ramp valued validated, trasform to % of Nominal Current
							// and insert Cmd
							Double crrntRampPercentage = (crrntRamp / nomCurrent) * 100;
							String^ strExecCmd = chnl->ChnlCnf->GetModName() + ":CurrentRampSpeed";
							if (!m_CmdMsg->strCmdsToExcList->Contains(strExecCmd)) {
								m_CmdMsg->GlobalAddSendCmds(strExecCmd, crrntRampPercentage.ToString(), MODULE_CMD, 3, false);
								this->DialogResult = System::Windows::Forms::DialogResult::OK;
							}
						}
						else 
							if (txtBx3_C_RR->Modified) {
								//txtBx3_C_RR->Text = CrrntRampText;
								m_CmdMsg->statusBarMsg = "Input value error - ";
							}
					}
				}
			}
			m_CmdMsg->GlobalAddSendCmds("", "", -1, 3, true);
			for each (ChnlViewForm ^ chnl in pChnlsView) {
				chnl->ChnlCnf->VoltageRise = pMainDataStruct->GetChnlVoltRamp(chnl->ChnlCnf->ChannelName);
				chnl->ChnlCnf->VoltageFall = chnl->ChnlCnf->VoltageRise;
				chnl->ChnlCnf->CurrentRise = pMainDataStruct->GetChnlCrrntRamp(chnl->ChnlCnf->ChannelName);
				chnl->ChnlCnf->CurrentFall = chnl->ChnlCnf->CurrentRise;
			}
		}
	}
	txtBx1_V_RR->Modified = false;
	txtBx3_C_RR->Modified = false;
}
private: System::Void Bttn2_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void GroupCnfSltn_Load(System::Object^ sender, System::EventArgs^ e) {
	this->lbl5_Cnf_Grp->Text += " < " + Group + " >";
	VltgRampText = txtBx1_V_RR->Text;
	CrrntRampText = txtBx3_C_RR->Text;
	this->ActiveControl = bttn2_Cancel;
}
};
}
