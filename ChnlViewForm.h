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
		ToolTip toolTipChnlName;
		readouts readoutsValues;
		NamePos_T chnlNamePosInViewTable; // Contains ChnlName & its pos in the ChnlsView to rapid access
		
	private: property cliext::vector <ChnlViewForm^>^ ChnlsViewList;
	private:
		Color m_bckColor;
		SingletonCmmdClass^ m_cmdMsg;
		List<Crate^>^ m_ptrMainCrateList;
		FreqCmdsMapTable_T^ myPtrFreqCmds = nullptr;

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
		ChnlViewForm(CratesT^ pMainDataStruct, cliext::vector <ChnlViewForm^>^ pMainViewList, List<String^>^ pGroupNames, List<String^>^ pChnlNames, FreqCmdsMapTable_T^ pFreqCmds)
		{
			ChnlCnf = gcnew XML_Classes::Channel();
			m_cmdMsg = SingletonCmmdClass::Instance;
			m_mainDataStruct = pMainDataStruct;
			m_ptrMainCrateList = m_mainDataStruct->ptrMainCrateList;
			m_pGroupNames = pGroupNames;
			m_pChnlViewNames = pChnlNames;
			ChnlsViewList = pMainViewList;
			myPtrFreqCmds = gcnew FreqCmdsMapTable_T;
			myPtrFreqCmds = pFreqCmds;
			InitializeComponent();
			chnlNamePosInViewTable = gcnew NamePos_T();
			
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
	// Validate user direct inputs for Voltage and current Set Points
	private: System::Void ValidateSetPointInputs();
	//
	// Open Chnl Conf settings Form (Ramp & set points Limits)
	private: System::Void Btn2_CfgChnlView_Click(System::Object^ sender, System::EventArgs^ e);

// Load individual Chnl View
private: System::Void ChnlViewForm_Load(System::Object^ sender, System::EventArgs^ e) {
	// Fill form with default values from CrateList->ModList->Channel[i]
	//if ((m_ptrMainCrateList->Count > 0) && (this->CrateDir>=0)){
	if (m_mainDataStruct->GetChnlConnectedStatus(this->ChnlCnf->ChannelName)){
		this->txtBx1_VoltSPChnlView->Text = m_mainDataStruct->GetChnlVoltSet(this->ChnlCnf->ChannelName);
		this->txtBx2_CurrtSPChnlView->Text = m_mainDataStruct->GetChnlCrrntSet(this->ChnlCnf->ChannelName);;
	}
	toolTipChnlName.SetToolTip(this->lbl2_NameChnlView, this->ChnlName);
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
// Set ON/OFF channels individually
	private: System::Void Btn1_ChnlView_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void ChnlViewForm_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	this->Location = System::Drawing::Point(this->OriginalPosX, this->OriginalPosY);
}
private: System::Void TxtBx1_StateChnlView_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TxtBx1_VoltSPChnlView_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TxtBx2_CurrtSPChnlView_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
// Clear the ChannelsInFormulaList if the formula checkBox was cleared
		 public: static void ClearFormList() {
			 //chnlNamePosInViewTable.
			 /*if (ChnlCnf->UseVoltageFormula) {

			 }*/
		 }
};
}
