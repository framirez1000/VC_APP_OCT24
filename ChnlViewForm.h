#include "CnfChnl.h"
#pragma once

namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace org::mariuszgromada::math::mxparser;  // Math lib for expression evaluation -> Formulas
	using namespace DraggableControls;


	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class ChnlViewForm : public System::Windows::Forms::Form
	{
	public: 
		property XML_Classes::Channel^ ChnlCnf;
		property int CrateDir;
		property String^ ChnlName;
		property String^ ChnlViewName;
		property int CrateLineDir;
		property int ModDir;
		property int ChnlDir;
		property List<String^>^ m_pGroupNames;
		property List<String^>^ m_pChnlViewNames;
		property List<Crate^>^ ptrMainCrateList;
		property CratesT^ m_mainDataStruct;
		property Expression^ e;
		property int formulaChnlIndex;
		property double vValue;
		property double vSetPoint;
		property Double cValue;
		property Double cSetPoint;
		property bool evaluateFormulaAtRamping;
		property int OriginalPosX;
		property int OriginalPosY;
		readouts readoutsValues;
		
	private: property cliext::vector <ChnlViewForm^>^ ChnlsViewList;
	private:
		Color m_bckColor;
		SingletonCmmdClass^ m_cmdMsg;
		List<Crate^>^ m_ptrMainCrateList;
		
	public: System::Windows::Forms::Label^ lbl_GroupName;
	public:
		ChnlViewForm(void)
		{
			m_cmdMsg = SingletonCmmdClass::Instance;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ChnlViewForm(CratesT^ pMainDataStruct, cliext::vector <ChnlViewForm^>^ pMainViewList, List<String^>^ pGroupNames, List<String^>^ pChnlNames)
		{
			ChnlCnf = gcnew XML_Classes::Channel();
			m_cmdMsg = SingletonCmmdClass::Instance;
			m_mainDataStruct = pMainDataStruct;
			m_ptrMainCrateList = m_mainDataStruct->ptrMainCrateList;
			m_pGroupNames = pGroupNames;
			m_pChnlViewNames = pChnlNames;
			ChnlsViewList = pMainViewList;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChnlViewForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Panel^ panel1;
	public: System::Windows::Forms::Button^ btn1_ChnlView;
	protected:



	public: System::Windows::Forms::Label^ lbl1_StatusChnlView;
	public: System::Windows::Forms::TextBox^ txtBx1_VoltSPChnlView;
	public: System::Windows::Forms::Label^ lbl4_NomVoltChnlView;

	private: System::Windows::Forms::Label^ lbl3_VltChnlView;
	public: System::Windows::Forms::Label^ lbl2_NameChnlView;

	private: System::Windows::Forms::Button^ btn2_CfgChnlView;
	public: System::Windows::Forms::TextBox^ txtBx2_CurrtSPChnlView;

	public: System::Windows::Forms::Label^ lbl6_NomCurrtChnlView;

	private: System::Windows::Forms::Label^ lbl5_Current;
	public: System::Windows::Forms::TextBox^ txtBx1_StateChnlView;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChnlViewForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtBx1_StateChnlView = (gcnew System::Windows::Forms::TextBox());
			this->txtBx2_CurrtSPChnlView = (gcnew System::Windows::Forms::TextBox());
			this->txtBx1_VoltSPChnlView = (gcnew System::Windows::Forms::TextBox());
			this->lbl_GroupName = (gcnew System::Windows::Forms::Label());
			this->lbl6_NomCurrtChnlView = (gcnew System::Windows::Forms::Label());
			this->lbl4_NomVoltChnlView = (gcnew System::Windows::Forms::Label());
			this->lbl5_Current = (gcnew System::Windows::Forms::Label());
			this->lbl3_VltChnlView = (gcnew System::Windows::Forms::Label());
			this->lbl2_NameChnlView = (gcnew System::Windows::Forms::Label());
			this->lbl1_StatusChnlView = (gcnew System::Windows::Forms::Label());
			this->btn2_CfgChnlView = (gcnew System::Windows::Forms::Button());
			this->btn1_ChnlView = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel1->Controls->Add(this->txtBx1_StateChnlView);
			this->panel1->Controls->Add(this->txtBx2_CurrtSPChnlView);
			this->panel1->Controls->Add(this->txtBx1_VoltSPChnlView);
			this->panel1->Controls->Add(this->lbl_GroupName);
			this->panel1->Controls->Add(this->lbl6_NomCurrtChnlView);
			this->panel1->Controls->Add(this->lbl4_NomVoltChnlView);
			this->panel1->Controls->Add(this->lbl5_Current);
			this->panel1->Controls->Add(this->lbl3_VltChnlView);
			this->panel1->Controls->Add(this->lbl2_NameChnlView);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// txtBx1_StateChnlView
			// 
			this->txtBx1_StateChnlView->BackColor = System::Drawing::Color::Lime;
			resources->ApplyResources(this->txtBx1_StateChnlView, L"txtBx1_StateChnlView");
			this->txtBx1_StateChnlView->Name = L"txtBx1_StateChnlView";
			this->txtBx1_StateChnlView->TextChanged += gcnew System::EventHandler(this, &ChnlViewForm::TxtBx1_StateChnlView_TextChanged);
			// 
			// txtBx2_CurrtSPChnlView
			// 
			this->txtBx2_CurrtSPChnlView->AcceptsReturn = true;
			resources->ApplyResources(this->txtBx2_CurrtSPChnlView, L"txtBx2_CurrtSPChnlView");
			this->txtBx2_CurrtSPChnlView->Name = L"txtBx2_CurrtSPChnlView";
			this->txtBx2_CurrtSPChnlView->TextChanged += gcnew System::EventHandler(this, &ChnlViewForm::TxtBx2_CurrtSPChnlView_TextChanged);
			this->txtBx2_CurrtSPChnlView->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &ChnlViewForm::txtBx1_VoltSPChnlView_Preview);
			// 
			// txtBx1_VoltSPChnlView
			// 
			this->txtBx1_VoltSPChnlView->AcceptsReturn = true;
			resources->ApplyResources(this->txtBx1_VoltSPChnlView, L"txtBx1_VoltSPChnlView");
			this->txtBx1_VoltSPChnlView->Name = L"txtBx1_VoltSPChnlView";
			this->txtBx1_VoltSPChnlView->TextChanged += gcnew System::EventHandler(this, &ChnlViewForm::TxtBx1_VoltSPChnlView_TextChanged);
			this->txtBx1_VoltSPChnlView->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &ChnlViewForm::txtBx1_VoltSPChnlView_Preview);
			// 
			// lbl_GroupName
			// 
			this->lbl_GroupName->AutoEllipsis = true;
			resources->ApplyResources(this->lbl_GroupName, L"lbl_GroupName");
			this->lbl_GroupName->Name = L"lbl_GroupName";
			// 
			// lbl6_NomCurrtChnlView
			// 
			this->lbl6_NomCurrtChnlView->AutoEllipsis = true;
			resources->ApplyResources(this->lbl6_NomCurrtChnlView, L"lbl6_NomCurrtChnlView");
			this->lbl6_NomCurrtChnlView->Name = L"lbl6_NomCurrtChnlView";
			// 
			// lbl4_NomVoltChnlView
			// 
			this->lbl4_NomVoltChnlView->AutoEllipsis = true;
			resources->ApplyResources(this->lbl4_NomVoltChnlView, L"lbl4_NomVoltChnlView");
			this->lbl4_NomVoltChnlView->Name = L"lbl4_NomVoltChnlView";
			// 
			// lbl5_Current
			// 
			resources->ApplyResources(this->lbl5_Current, L"lbl5_Current");
			this->lbl5_Current->Name = L"lbl5_Current";
			// 
			// lbl3_VltChnlView
			// 
			resources->ApplyResources(this->lbl3_VltChnlView, L"lbl3_VltChnlView");
			this->lbl3_VltChnlView->Name = L"lbl3_VltChnlView";
			// 
			// lbl2_NameChnlView
			// 
			this->lbl2_NameChnlView->AutoEllipsis = true;
			resources->ApplyResources(this->lbl2_NameChnlView, L"lbl2_NameChnlView");
			this->lbl2_NameChnlView->Name = L"lbl2_NameChnlView";
			// 
			// lbl1_StatusChnlView
			// 
			this->lbl1_StatusChnlView->BackColor = System::Drawing::SystemColors::HighlightText;
			resources->ApplyResources(this->lbl1_StatusChnlView, L"lbl1_StatusChnlView");
			this->lbl1_StatusChnlView->Name = L"lbl1_StatusChnlView";
			// 
			// btn2_CfgChnlView
			// 
			resources->ApplyResources(this->btn2_CfgChnlView, L"btn2_CfgChnlView");
			this->btn2_CfgChnlView->Name = L"btn2_CfgChnlView";
			this->btn2_CfgChnlView->UseVisualStyleBackColor = true;
			this->btn2_CfgChnlView->Click += gcnew System::EventHandler(this, &ChnlViewForm::Btn2_CfgChnlView_Click);
			// 
			// btn1_ChnlView
			// 
			resources->ApplyResources(this->btn1_ChnlView, L"btn1_ChnlView");
			this->btn1_ChnlView->Name = L"btn1_ChnlView";
			this->btn1_ChnlView->UseVisualStyleBackColor = true;
			this->btn1_ChnlView->Click += gcnew System::EventHandler(this, &ChnlViewForm::Btn1_ChnlView_Click);
			// 
			// ChnlViewForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->Controls->Add(this->lbl1_StatusChnlView);
			this->Controls->Add(this->btn1_ChnlView);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btn2_CfgChnlView);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ChnlViewForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->Load += gcnew System::EventHandler(this, &ChnlViewForm::ChnlViewForm_Load);
			this->DoubleClick += gcnew System::EventHandler(this, &ChnlViewForm::ChnlViewForm_DoubleClick);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
public: Double GetFormulaEvaluation(String^ formula, String^ target);
//public: System::Boolean ValidateSP(String^ spValue, String^ nomVltg, double lowLimitFactor, double highLimitFactor);
public: System::Void GetformEvalAtRamp(String^ formula);
//
// Open Chnl Conf settings Form (Ramp & set points Limits)
private: System::Void Btn2_CfgChnlView_Click(System::Object^ sender, System::EventArgs^ e) {
	CnfChnl^ cnfChannel = gcnew CnfChnl(m_mainDataStruct, m_pGroupNames, m_pChnlViewNames);
	
	cnfChannel->CrateDir = this->ChnlCnf->CrateDir;
	cnfChannel->ChnlName = this->ChnlCnf->ChannelName;
	cnfChannel->ModDir = this->ChnlCnf->ModDir;
	cnfChannel->ChnlDir = this->ChnlCnf->ChnlDir;
	cnfChannel->VoltSP_Limit = this->ChnlCnf->LimitVoltage;
	cnfChannel->CrrntSP_Limit = this->ChnlCnf->LimitCurrent;
	cnfChannel->lbl1_CnfChnl->Text = this->ChnlCnf->ViewName;
	cnfChannel->Group = this->ChnlCnf->Group;
	cnfChannel->UseVoltageFormula = this->ChnlCnf->UseVoltageFormula;
	cnfChannel->UseCurrentFormula = this->ChnlCnf->UseCurrentFormula;
	
	if (this->ChnlCnf->UseVoltageFormula) {
		cnfChannel->formula = this->ChnlCnf->VoltageFormula;
	}
	if (this->ChnlCnf->UseCurrentFormula) {
		cnfChannel->iformula = this->ChnlCnf->CurrentFormula;
	}

	cnfChannel->NameIndex = this->formulaChnlIndex;
	if (this->ChnlCnf->Group != nullptr) {
		cnfChannel->cmbBx1_SwtGrp->SelectedIndex = cnfChannel->cmbBx1_SwtGrp->FindStringExact(this->ChnlCnf->Group);
		cnfChannel->cmbBx1_SwtGrp ->Text = this->ChnlCnf->Group;
	}

	if (cnfChannel->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Open the form that gets user inputs for voltage/current Ramp Set Points/formulas
		if ((m_ptrMainCrateList->Count > 0) && (m_mainDataStruct->GetChnlConnectedStatus(this->ChnlCnf->ChannelName))){
			this->txtBx1_VoltSPChnlView->Text = m_mainDataStruct->GetChnlVoltSet(this->ChnlCnf->ChannelName);
			Double val;
			Double::TryParse(this->txtBx1_VoltSPChnlView->Text, val);
			this->vSetPoint = val;
			
			// Evaluate Voltage Formula
			if (cnfChannel->chkBx1_UseFormuVltg->Checked) {
				if ((cnfChannel->formula != nullptr) && (cnfChannel->formula != "")) {
					// Evaluate expression/formula from the user input
					this->ChnlCnf->UseVoltageFormula = true;
					this->ChnlCnf->VoltageFormula = cnfChannel->formula;
					GetformEvalAtRamp(cnfChannel->formula);
					if (cnfChannel->NameIndex >= 0) { /////??????
						vSetPoint = GetFormulaEvaluation(cnfChannel->formula, "Voltage");
						if (GlobalFuncValidateSP(vSetPoint.ToString(),
							m_mainDataStruct->GetChnlNomVolt(this->ChnlCnf->ChannelName), 0.0, 1.0)) {
							m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":VoltageSet",
								vSetPoint.ToString(), CHANNEL_CMD, 3, true);
						}
						else m_cmdMsg->StatusBarMsgIndex = 15;
					}
				}
			}
			this->txtBx1_VoltSPChnlView->Enabled = !this->ChnlCnf->UseVoltageFormula;
			
			// For current formula
			this->txtBx2_CurrtSPChnlView->Text = m_mainDataStruct->GetChnlCrrntSet(this->ChnlCnf->ChannelName);
			Double::TryParse(this->txtBx2_CurrtSPChnlView->Text, val);
			this->cSetPoint = val;
			if (cnfChannel->chkBx2_UseCrrtFrm->Checked) {
				if ((cnfChannel->iformula != nullptr) && (cnfChannel->iformula != "")) {
					// Evaluate expression/formula from the user input
					this->ChnlCnf->UseCurrentFormula = true;
					this->ChnlCnf->CurrentFormula = cnfChannel->iformula;
					//GetformEvalAtRamp(cnfChannel->iformula);
					if (cnfChannel->NameIndex >= 0) { /////??????
						cSetPoint = GetFormulaEvaluation(cnfChannel->iformula, "Current");
						if (GlobalFuncValidateSP(cSetPoint.ToString(),
							m_mainDataStruct->GetChnlNomCrrnt(this->ChnlCnf->ChannelName), 0.0, 1.0)) {
							m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":CurrentSet",
								cSetPoint.ToString(), CHANNEL_CMD, 3, true);
						}
						else m_cmdMsg->StatusBarMsgIndex = 15;
					}
				}
			}
			this->txtBx2_CurrtSPChnlView->Enabled = !this->ChnlCnf->UseCurrentFormula;

		}
		// If Channel name changed update view and NamesList (ToDo)
		if (!String::IsNullOrEmpty(cnfChannel->txtBx1_NewChnlName->Text)){
			// Search ChnlName in NamesList and change both (SetPoint name and currentValueName _U)
			int index = m_pChnlViewNames->IndexOf(this->ChnlCnf->ViewName);
			if (index != -1) {
				m_pChnlViewNames[index] = cnfChannel->txtBx1_NewChnlName->Text + "_";
				m_pChnlViewNames[index+1] = cnfChannel->txtBx1_NewChnlName->Text + "_U";
			}
			this->ChnlCnf->ViewName = cnfChannel->txtBx1_NewChnlName->Text;
			this->lbl2_NameChnlView->Text = cnfChannel->txtBx1_NewChnlName->Text;
		}
		Object^ selectedItem = cnfChannel->cmbBx1_SwtGrp->SelectedItem;
		if (cnfChannel->cmbBx1_SwtGrp->SelectedItem != nullptr) {
			this->ChnlCnf->Group = selectedItem->ToString();
			this->lbl_GroupName->Text = selectedItem->ToString();
		}
		// If SP limits changed
		if (cnfChannel->VoltSP_Limit != this->ChnlCnf->LimitVoltage)
			this->ChnlCnf->LimitVoltage = cnfChannel->VoltSP_Limit;
		if (cnfChannel->CrrntSP_Limit != this->ChnlCnf->LimitCurrent)
			this->ChnlCnf->LimitCurrent = cnfChannel->CrrntSP_Limit;
	}
	if (m_cmdMsg->cmdExecuted && m_cmdMsg->HrwConntd && (this->ChnlCnf->ChnlType != 0)) {
		this->txtBx1_VoltSPChnlView->Text = m_mainDataStruct->GetChnlVoltSet(this->ChnlCnf->ChannelName);
		this->vSetPoint = System::Convert::ToDouble(this->txtBx1_VoltSPChnlView->Text);
		this->txtBx2_CurrtSPChnlView->Text = m_mainDataStruct->GetChnlCrrntSet(this->ChnlCnf->ChannelName);
		this->vSetPoint = System::Convert::ToDouble(this->txtBx2_CurrtSPChnlView->Text);
		this->ChnlCnf->VoltageRise = m_mainDataStruct->GetChnlVoltRamp(this->ChnlCnf->ChannelName);
		this->ChnlCnf->VoltageFall = m_mainDataStruct->GetChnlVoltRamp(this->ChnlCnf->ChannelName);
		this->ChnlCnf->CurrentRise = m_mainDataStruct->GetChnlCrrntRamp(this->ChnlCnf->ChannelName);
		this->ChnlCnf->CurrentFall = m_mainDataStruct->GetChnlCrrntRamp(this->ChnlCnf->ChannelName);
	}
	this->ChnlCnf->UseVoltageFormula = cnfChannel->UseVoltageFormula;
	this->txtBx1_VoltSPChnlView->Enabled = true;
	if (this->ChnlCnf->UseVoltageFormula) {
		this->ChnlCnf->VoltageFormula = cnfChannel->formula;
		this->txtBx1_VoltSPChnlView->Enabled = false;
	}
	this->ChnlCnf->UseCurrentFormula = cnfChannel->UseCurrentFormula;
	this->txtBx2_CurrtSPChnlView->Enabled = true;
	if (this->ChnlCnf->UseCurrentFormula) {
		this->ChnlCnf->CurrentFormula = cnfChannel->iformula;
		this->txtBx2_CurrtSPChnlView->Enabled = false;
	}
}
// Load individual Chnl View
private: System::Void ChnlViewForm_Load(System::Object^ sender, System::EventArgs^ e) {
	// Fill form with default values from CrateList->ModList->Channel[i]
	//if ((m_ptrMainCrateList->Count > 0) && (this->CrateDir>=0)){
	if (m_mainDataStruct->GetChnlConnectedStatus(this->ChnlCnf->ChannelName)){
		this->txtBx1_VoltSPChnlView->Text = m_mainDataStruct->GetChnlVoltSet(this->ChnlCnf->ChannelName);
		this->txtBx2_CurrtSPChnlView->Text = m_mainDataStruct->GetChnlCrrntSet(this->ChnlCnf->ChannelName);;
	}
	
}
// 
// Change value on textbox1/textbox2 (V/I SPs) validate user input
private: System::Void txtBx1_VoltSPChnlView_Preview(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Return)
	{
		ValidateSetPointInputs();
		this->ActiveControl = this->panel1;
	}
}
//
// Validate user direct inputs for Voltage and current Set Points
private: System::Void ValidateSetPointInputs() {
	if ((!m_cmdMsg->execRequest && (m_mainDataStruct->GetChnlEnableStatus(this->ChnlCnf->ChannelName))) 
		|| (this->ChnlCnf->ChnlType == 0 )) { // ChnlType 0: Virtual channels
		m_cmdMsg->CleanCmdsLists();
		String^ spValue = gcnew String(txtBx1_VoltSPChnlView->Text);
		// Validate user entry for VoltageSet or CurrentSet and change setting in Crate if ok
		if (txtBx1_VoltSPChnlView->Modified && !(String::IsNullOrEmpty(spValue))) {
			// Convert to numerical value and validate ranges
			if (GlobalFuncValidateSP(spValue, this->ChnlCnf->LimitVoltage, 0.0, 1.0)) {
				///*m_mainDataStruct->GetChnlNomVolt(this->ChnlCnf->ChannelName)*/, 0.0, 1.0)) {
				if (this->ChnlCnf->ChnlType != 0) {
					m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":VoltageSet",
						spValue, CHANNEL_CMD, 3, false);
				}
				else {
					// Set VChnl Voltage SP to Channel user input
					this->ChnlCnf->VoltageSet  = spValue;
					this->vSetPoint = System::Convert::ToDouble(spValue);
				}
			}
			else {
				m_cmdMsg->StatusBarMsgIndex = 16;
				txtBx1_VoltSPChnlView->Undo(); 
			}
		}
		
		spValue = txtBx2_CurrtSPChnlView->Text;
		if (txtBx2_CurrtSPChnlView->Modified && !(String::IsNullOrEmpty(spValue))) {
			// Convert to numerical value and validate ranges
			if (GlobalFuncValidateSP(spValue, this->ChnlCnf->LimitCurrent, 0.0, 1.0)) {
				//m_mainDataStruct->GetChnlNomCrrnt(this->ChnlCnf->ChannelName), 0.0, 1.0)) {
				if (this->ChnlCnf->ChnlType != 0) {
					m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":CurrentSet",
						spValue, CHANNEL_CMD, 3, false);
				}
				else {
					// Set VChnl Voltage SP to Channel user input
					this->ChnlCnf->CurrentSet = spValue;
					this->cSetPoint = System::Convert::ToDouble(spValue);
				}
			}
			else {
				m_cmdMsg->StatusBarMsgIndex = 16;
				txtBx2_CurrtSPChnlView->Undo();
			}
		}
		if (m_cmdMsg->strCmdsToExcList->Count > 0) 
			m_cmdMsg->GlobalAddSendCmds("", "", -1, 3, true);
		if ((m_ptrMainCrateList->Count > 0) && (this->ChnlCnf->ChnlType != 0)) {
			// ToDo here: Check with Crate S/N to update properly
			String^ readoutValue( m_mainDataStruct->GetChnlVoltSet(this->ChnlCnf->ChannelName));
			this->txtBx1_VoltSPChnlView->Text = readoutValue;
			this->ChnlCnf->VoltageSet = readoutValue;
			this->vSetPoint = System::Convert::ToDouble(readoutValue);
			readoutValue = m_mainDataStruct->GetChnlCrrntSet(this->ChnlCnf->ChannelName);
			this->txtBx2_CurrtSPChnlView->Text = readoutValue;
			this->ChnlCnf->CurrentSet = readoutValue;
			this->cSetPoint = System::Convert::ToDouble(readoutValue);
		}
	}
	else {
		MessageBox::Show("Channel not connected or System busy with other cmd");
		if (txtBx1_VoltSPChnlView->Modified) txtBx1_VoltSPChnlView->Undo();
		if (txtBx2_CurrtSPChnlView->Modified) txtBx2_CurrtSPChnlView->Undo();
	}
	txtBx1_VoltSPChnlView->Modified = false;
	txtBx2_CurrtSPChnlView->Modified = false;
}
//
// Set ON/OFF channels individually
	private: System::Void Btn1_ChnlView_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!m_cmdMsg->execRequest && m_cmdMsg->HrwConntd && (this->ChnlCnf->ChnlType != 0)) {
			m_cmdMsg->CleanCmdsLists();
			String^ strParam = gcnew String("false");
			if (m_cmdMsg->HrwConntd) {
				if (this->lbl1_StatusChnlView->Text != "ON") {
					strParam = "true";
				}
				m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName  + ":Control:setOn",
												strParam, CHANNEL_CMD, 4, false);
				Console::WriteLine("Channel {0} included to be: \n", this->ChnlCnf->ViewName);
				m_cmdMsg->StatusBarMsgIndex = 17;
				m_cmdMsg->GlobalAddSendCmds("", "", -1, 4, true);
			}
		}
	}
private: System::Void ChnlViewForm_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	this->Location = System::Drawing::Point(this->OriginalPosX, this->OriginalPosY);
}
private: System::Void TxtBx1_StateChnlView_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TxtBx1_VoltSPChnlView_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TxtBx2_CurrtSPChnlView_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

};
}
