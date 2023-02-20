#pragma once

#include "Crate.h"
#include <cliext/map>
#include "MainHeader.h"
#include <regex>
//#include <iostream>
#include <sstream>
//#include<string>

using namespace System::Text::RegularExpressions;

using namespace System;
typedef cli::array<System::String^>^ Groups;

namespace ListTest_CLI_Project {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for CnfChnl
	/// </summary>
	public ref class CnfChnl : public System::Windows::Forms::Form
	{
	public:
		property String^ ChnlName;
		property int CrateDir;
		property int ModDir;
		property int ChnlDir;
		property Crate^ MyCrate;
		property Groups pGroups;
		property String^ Group;
		property bool UseCurrentFormula;
		property bool UseVoltageFormula;
		property List<String^>^ m_pGroupNames;
		property List<String^>^ m_ChnlNames;
		property CratesT^ m_MainDataStruct;
		ToolTip toolTip1;
		ToolTip toolTipChosenChnl;
		ToolTip toolTipFormulaTxtBx;
		property String^ text;
		property TextRenderer^ textRenderer;
		property int NameIndex;
		property String^ formula;
		property String^ iformula;
		property String^ VoltSP_Limit;
		property String^ CrrntSP_Limit;
		property double vRamp;
		property double cRamp;
		// Changes on 05/12/22
		property String^ vSetPoint;         // From Double to String
		property String^ cSetPoint;         // Same
		property String^ nominalVolt;       // New - For lbl9_MaxVltg
		property String^ nominalCurrent;    // New - For lbl11_MaxCrrt

	private: const int CB_SETCUEBANNER = 0x1703;

	
	private:
		List<Crate^>^ m_ptrMainCrateList;
		SingletonCmmdClass^ m_cmdMsg;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbl_NewVhnlName;
	public: System::Windows::Forms::TextBox^ txtBx1_NewChnlName;
	private:

	private:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cmbBx1_ChnlNames;
	public: System::Windows::Forms::Label^ lbl14_ChooseChnl;
	public: System::Windows::Forms::Label^ label4_CurrentFormuChnl;

	private: System::Windows::Forms::ComboBox^ cmbBx2_currentFormChnls;
	public:

	public:

	public:
	private:


	private: System::Windows::Forms::Label^ label2;
		
			 
	public:
		CnfChnl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		CnfChnl(CratesT^ pMainDataStruct, List<String^>^ pGroupNames, List<String^>^ pChnlNames)
		{
			m_cmdMsg = SingletonCmmdClass::Instance;
			m_MainDataStruct = pMainDataStruct;
			m_ptrMainCrateList = pMainDataStruct->ptrMainCrateList;
			m_pGroupNames = pGroupNames;
			m_ChnlNames = pChnlNames;
			String^ ChnlName = gcnew String("");
			String^ Group = gcnew String("");
			String^ text = gcnew String("");
			String^ formula = gcnew String("");
			String^ iformula = gcnew String("");
			String^ VoltSPLimit = gcnew String("");
			String^ CrrntSPLimit = gcnew String("");
			//TextRenderer^ textRenderer = gcnew TextRenderer;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			NameIndex = -1;
			pGroups = gcnew cli::array<String^>{ "A", "B", "C", "D", "E", "F", "G", "H" };
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CnfChnl()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ lbl1_CnfChnl;
	protected:

	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ lbl2_VltgRiseRate;
	private: System::Windows::Forms::Label^ lbl3_VltgFallRate;
	private: System::Windows::Forms::Label^ lbl4_CrrtRiseRate;
	private: System::Windows::Forms::Label^ lbl5_CrrtFallRate;
	private: System::Windows::Forms::TextBox^ txtBx1_VltgRiseRate;
	private: System::Windows::Forms::TextBox^ txtBx2_VltgFallRate;
	private: System::Windows::Forms::TextBox^ txtBx3_CrrtRiseRate;
	private: System::Windows::Forms::TextBox^ txtBx4_CrrtFallRate;
	public: System::Windows::Forms::CheckBox^ chkBx1_UseFormuVltg;
	private:

	private: System::Windows::Forms::Label^ lbl6_VltgFrm;
	private: System::Windows::Forms::TextBox^ txtBx5_VltgFrm;
	private: System::Windows::Forms::Label^ lbl7_CrrtFrm;
	private: System::Windows::Forms::TextBox^ txtBx6_CrrtFrm;
public: System::Windows::Forms::CheckBox^ chkBx2_UseCrrtFrm;
private:

	private: System::Windows::Forms::Label^ lbl8_SwtcGrpCnf;
	public: System::Windows::Forms::ComboBox^ cmbBx1_SwtGrp;
	private:

	private: System::Windows::Forms::Label^ lbl9_MaxVltg;
    public: System::Windows::Forms::TextBox^ txtBx7_MaxVltg;


	private: System::Windows::Forms::Label^ lbl11_MaxCrrt;
    public: System::Windows::Forms::TextBox^ txtBx8_MaxCrrt;
    

	private: System::Windows::Forms::Button^ btn1_ClearAllLimits;
	private: System::Windows::Forms::Label^ lbl10_ActVltg;
	private: System::Windows::Forms::Label^ lbl12_ActCrrt;
	private: System::Windows::Forms::CheckBox^ chkBx3_CtrlPwr;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ txtBx9_CtrlPwr;
	private: System::Windows::Forms::Button^ btn2_Ok;
	private: System::Windows::Forms::Button^ btn3_Cancel;
	private: System::Windows::Forms::Label^ lbl13_CrateRamps;
	private: System::Windows::Forms::Label^ lbl14_vUpRamp;
	private: System::Windows::Forms::Label^ lbl15_vDownRamp;
	private: System::Windows::Forms::Label^ lbl16_iUpRamp;
	private: System::Windows::Forms::Label^ lbl17_iDownRamp;
	private: System::Windows::Forms::Label^ lbl18_CrateSPs;
	private: System::Windows::Forms::Label^ lbl19_CrateV_SP;
	private: System::Windows::Forms::Label^ lbl20_CrateI_SP;

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
			this->lbl1_CnfChnl = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lbl2_VltgRiseRate = (gcnew System::Windows::Forms::Label());
			this->lbl3_VltgFallRate = (gcnew System::Windows::Forms::Label());
			this->lbl4_CrrtRiseRate = (gcnew System::Windows::Forms::Label());
			this->lbl5_CrrtFallRate = (gcnew System::Windows::Forms::Label());
			this->txtBx1_VltgRiseRate = (gcnew System::Windows::Forms::TextBox());
			this->txtBx2_VltgFallRate = (gcnew System::Windows::Forms::TextBox());
			this->txtBx3_CrrtRiseRate = (gcnew System::Windows::Forms::TextBox());
			this->txtBx4_CrrtFallRate = (gcnew System::Windows::Forms::TextBox());
			this->chkBx1_UseFormuVltg = (gcnew System::Windows::Forms::CheckBox());
			this->lbl6_VltgFrm = (gcnew System::Windows::Forms::Label());
			this->txtBx5_VltgFrm = (gcnew System::Windows::Forms::TextBox());
			this->lbl7_CrrtFrm = (gcnew System::Windows::Forms::Label());
			this->txtBx6_CrrtFrm = (gcnew System::Windows::Forms::TextBox());
			this->chkBx2_UseCrrtFrm = (gcnew System::Windows::Forms::CheckBox());
			this->lbl8_SwtcGrpCnf = (gcnew System::Windows::Forms::Label());
			this->cmbBx1_SwtGrp = (gcnew System::Windows::Forms::ComboBox());
			this->lbl9_MaxVltg = (gcnew System::Windows::Forms::Label());
			this->txtBx7_MaxVltg = (gcnew System::Windows::Forms::TextBox());
			this->lbl11_MaxCrrt = (gcnew System::Windows::Forms::Label());
			this->txtBx8_MaxCrrt = (gcnew System::Windows::Forms::TextBox());
			this->btn1_ClearAllLimits = (gcnew System::Windows::Forms::Button());
			this->lbl10_ActVltg = (gcnew System::Windows::Forms::Label());
			this->lbl12_ActCrrt = (gcnew System::Windows::Forms::Label());
			this->chkBx3_CtrlPwr = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtBx9_CtrlPwr = (gcnew System::Windows::Forms::TextBox());
			this->btn2_Ok = (gcnew System::Windows::Forms::Button());
			this->btn3_Cancel = (gcnew System::Windows::Forms::Button());
			this->lbl13_CrateRamps = (gcnew System::Windows::Forms::Label());
			this->lbl14_vUpRamp = (gcnew System::Windows::Forms::Label());
			this->lbl15_vDownRamp = (gcnew System::Windows::Forms::Label());
			this->lbl16_iUpRamp = (gcnew System::Windows::Forms::Label());
			this->lbl17_iDownRamp = (gcnew System::Windows::Forms::Label());
			this->lbl18_CrateSPs = (gcnew System::Windows::Forms::Label());
			this->lbl19_CrateV_SP = (gcnew System::Windows::Forms::Label());
			this->lbl20_CrateI_SP = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_NewVhnlName = (gcnew System::Windows::Forms::Label());
			this->txtBx1_NewChnlName = (gcnew System::Windows::Forms::TextBox());
			this->cmbBx1_ChnlNames = (gcnew System::Windows::Forms::ComboBox());
			this->lbl14_ChooseChnl = (gcnew System::Windows::Forms::Label());
			this->label4_CurrentFormuChnl = (gcnew System::Windows::Forms::Label());
			this->cmbBx2_currentFormChnls = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbl1_CnfChnl
			// 
			this->lbl1_CnfChnl->AutoSize = true;
			this->lbl1_CnfChnl->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->lbl1_CnfChnl->Location = System::Drawing::Point(97, 14);
			this->lbl1_CnfChnl->Name = L"lbl1_CnfChnl";
			this->lbl1_CnfChnl->Size = System::Drawing::Size(109, 13);
			this->lbl1_CnfChnl->TabIndex = 0;
			this->lbl1_CnfChnl->Text = L"Channel Name <U-1>";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox1->Controls->Add(this->lbl1_CnfChnl);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(325, 34);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Configure channel ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L" Name: ";
			// 
			// lbl2_VltgRiseRate
			// 
			this->lbl2_VltgRiseRate->AutoSize = true;
			this->lbl2_VltgRiseRate->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl2_VltgRiseRate->Location = System::Drawing::Point(16, 86);
			this->lbl2_VltgRiseRate->Name = L"lbl2_VltgRiseRate";
			this->lbl2_VltgRiseRate->Size = System::Drawing::Size(109, 13);
			this->lbl2_VltgRiseRate->TabIndex = 2;
			this->lbl2_VltgRiseRate->Text = L"Voltage rise rate [V/s]";
			// 
			// lbl3_VltgFallRate
			// 
			this->lbl3_VltgFallRate->AutoSize = true;
			this->lbl3_VltgFallRate->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl3_VltgFallRate->Location = System::Drawing::Point(16, 110);
			this->lbl3_VltgFallRate->Name = L"lbl3_VltgFallRate";
			this->lbl3_VltgFallRate->Size = System::Drawing::Size(106, 13);
			this->lbl3_VltgFallRate->TabIndex = 2;
			this->lbl3_VltgFallRate->Text = L"Voltage fall rate [V/s]";
			// 
			// lbl4_CrrtRiseRate
			// 
			this->lbl4_CrrtRiseRate->AutoSize = true;
			this->lbl4_CrrtRiseRate->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl4_CrrtRiseRate->Location = System::Drawing::Point(16, 141);
			this->lbl4_CrrtRiseRate->Name = L"lbl4_CrrtRiseRate";
			this->lbl4_CrrtRiseRate->Size = System::Drawing::Size(107, 13);
			this->lbl4_CrrtRiseRate->TabIndex = 2;
			this->lbl4_CrrtRiseRate->Text = L"Current rise rate [A/s]";
			// 
			// lbl5_CrrtFallRate
			// 
			this->lbl5_CrrtFallRate->AutoSize = true;
			this->lbl5_CrrtFallRate->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl5_CrrtFallRate->Location = System::Drawing::Point(15, 164);
			this->lbl5_CrrtFallRate->Name = L"lbl5_CrrtFallRate";
			this->lbl5_CrrtFallRate->Size = System::Drawing::Size(104, 13);
			this->lbl5_CrrtFallRate->TabIndex = 2;
			this->lbl5_CrrtFallRate->Text = L"Current fall rate [A/s]";
			// 
			// txtBx1_VltgRiseRate
			// 
			this->txtBx1_VltgRiseRate->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx1_VltgRiseRate->Location = System::Drawing::Point(145, 85);
			this->txtBx1_VltgRiseRate->Name = L"txtBx1_VltgRiseRate";
			this->txtBx1_VltgRiseRate->Size = System::Drawing::Size(77, 20);
			this->txtBx1_VltgRiseRate->TabIndex = 2;
			this->txtBx1_VltgRiseRate->Text = L"100.0";
			this->txtBx1_VltgRiseRate->Leave += gcnew System::EventHandler(this, &CnfChnl::TxtBx1_VltgRiseRate_Leave);
			// 
			// txtBx2_VltgFallRate
			// 
			this->txtBx2_VltgFallRate->Enabled = false;
			this->txtBx2_VltgFallRate->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx2_VltgFallRate->Location = System::Drawing::Point(145, 107);
			this->txtBx2_VltgFallRate->Name = L"txtBx2_VltgFallRate";
			this->txtBx2_VltgFallRate->Size = System::Drawing::Size(77, 20);
			this->txtBx2_VltgFallRate->TabIndex = 3;
			this->txtBx2_VltgFallRate->Text = L"1.000";
			// 
			// txtBx3_CrrtRiseRate
			// 
			this->txtBx3_CrrtRiseRate->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx3_CrrtRiseRate->Location = System::Drawing::Point(145, 138);
			this->txtBx3_CrrtRiseRate->Name = L"txtBx3_CrrtRiseRate";
			this->txtBx3_CrrtRiseRate->Size = System::Drawing::Size(77, 20);
			this->txtBx3_CrrtRiseRate->TabIndex = 3;
			this->txtBx3_CrrtRiseRate->Text = L"100.0";
			this->txtBx3_CrrtRiseRate->Leave += gcnew System::EventHandler(this, &CnfChnl::TxtBx3_CrrtRiseRate_Leave);
			// 
			// txtBx4_CrrtFallRate
			// 
			this->txtBx4_CrrtFallRate->Enabled = false;
			this->txtBx4_CrrtFallRate->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx4_CrrtFallRate->Location = System::Drawing::Point(145, 161);
			this->txtBx4_CrrtFallRate->Name = L"txtBx4_CrrtFallRate";
			this->txtBx4_CrrtFallRate->Size = System::Drawing::Size(77, 20);
			this->txtBx4_CrrtFallRate->TabIndex = 3;
			this->txtBx4_CrrtFallRate->Text = L"1.000";
			// 
			// chkBx1_UseFormuVltg
			// 
			this->chkBx1_UseFormuVltg->AutoSize = true;
			this->chkBx1_UseFormuVltg->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->chkBx1_UseFormuVltg->ForeColor = System::Drawing::SystemColors::Window;
			this->chkBx1_UseFormuVltg->Location = System::Drawing::Point(19, 192);
			this->chkBx1_UseFormuVltg->Name = L"chkBx1_UseFormuVltg";
			this->chkBx1_UseFormuVltg->Size = System::Drawing::Size(125, 17);
			this->chkBx1_UseFormuVltg->TabIndex = 4;
			this->chkBx1_UseFormuVltg->Text = L"Use formula (Voltage)";
			this->chkBx1_UseFormuVltg->UseVisualStyleBackColor = false;
			this->chkBx1_UseFormuVltg->Click += gcnew System::EventHandler(this, &CnfChnl::ChkBx1_UseFormuVltg_Click);
			// 
			// lbl6_VltgFrm
			// 
			this->lbl6_VltgFrm->AutoSize = true;
			this->lbl6_VltgFrm->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl6_VltgFrm->Location = System::Drawing::Point(16, 212);
			this->lbl6_VltgFrm->Name = L"lbl6_VltgFrm";
			this->lbl6_VltgFrm->Size = System::Drawing::Size(237, 13);
			this->lbl6_VltgFrm->TabIndex = 2;
			this->lbl6_VltgFrm->Text = L"Voltage formula (append \"_U\" to channel name!)";
			// 
			// txtBx5_VltgFrm
			// 
			this->txtBx5_VltgFrm->Enabled = false;
			this->txtBx5_VltgFrm->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx5_VltgFrm->Location = System::Drawing::Point(19, 228);
			this->txtBx5_VltgFrm->Name = L"txtBx5_VltgFrm";
			this->txtBx5_VltgFrm->Size = System::Drawing::Size(284, 20);
			this->txtBx5_VltgFrm->TabIndex = 5;
			this->txtBx5_VltgFrm->TextChanged += gcnew System::EventHandler(this, &CnfChnl::TxtBx5_VltgFrm_TextChanged);
			// 
			// lbl7_CrrtFrm
			// 
			this->lbl7_CrrtFrm->AutoSize = true;
			this->lbl7_CrrtFrm->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl7_CrrtFrm->Location = System::Drawing::Point(16, 295);
			this->lbl7_CrrtFrm->Name = L"lbl7_CrrtFrm";
			this->lbl7_CrrtFrm->Size = System::Drawing::Size(230, 13);
			this->lbl7_CrrtFrm->TabIndex = 2;
			this->lbl7_CrrtFrm->Text = L"Current formula (append \"_I\" to channel name!)";
			// 
			// txtBx6_CrrtFrm
			// 
			this->txtBx6_CrrtFrm->Enabled = false;
			this->txtBx6_CrrtFrm->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx6_CrrtFrm->Location = System::Drawing::Point(19, 313);
			this->txtBx6_CrrtFrm->Name = L"txtBx6_CrrtFrm";
			this->txtBx6_CrrtFrm->Size = System::Drawing::Size(284, 20);
			this->txtBx6_CrrtFrm->TabIndex = 8;
			this->txtBx6_CrrtFrm->TextChanged += gcnew System::EventHandler(this, &CnfChnl::TxtBx6_CrrtFrm_TextChanged);
			// 
			// chkBx2_UseCrrtFrm
			// 
			this->chkBx2_UseCrrtFrm->AutoSize = true;
			this->chkBx2_UseCrrtFrm->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->chkBx2_UseCrrtFrm->ForeColor = System::Drawing::SystemColors::Window;
			this->chkBx2_UseCrrtFrm->Location = System::Drawing::Point(19, 275);
			this->chkBx2_UseCrrtFrm->Name = L"chkBx2_UseCrrtFrm";
			this->chkBx2_UseCrrtFrm->Size = System::Drawing::Size(123, 17);
			this->chkBx2_UseCrrtFrm->TabIndex = 7;
			this->chkBx2_UseCrrtFrm->Text = L"Use formula (Current)";
			this->chkBx2_UseCrrtFrm->UseVisualStyleBackColor = false;
			this->chkBx2_UseCrrtFrm->CheckedChanged += gcnew System::EventHandler(this, &CnfChnl::ChkBx2_UseCrrtFrm_CheckedChanged);
			// 
			// lbl8_SwtcGrpCnf
			// 
			this->lbl8_SwtcGrpCnf->AutoSize = true;
			this->lbl8_SwtcGrpCnf->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl8_SwtcGrpCnf->Location = System::Drawing::Point(16, 372);
			this->lbl8_SwtcGrpCnf->Name = L"lbl8_SwtcGrpCnf";
			this->lbl8_SwtcGrpCnf->Size = System::Drawing::Size(152, 13);
			this->lbl8_SwtcGrpCnf->TabIndex = 2;
			this->lbl8_SwtcGrpCnf->Text = L"Channel group (Switch/Config)";
			// 
			// cmbBx1_SwtGrp
			// 
			this->cmbBx1_SwtGrp->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->cmbBx1_SwtGrp->FormattingEnabled = true;
			this->cmbBx1_SwtGrp->Location = System::Drawing::Point(211, 369);
			this->cmbBx1_SwtGrp->Name = L"cmbBx1_SwtGrp";
			this->cmbBx1_SwtGrp->Size = System::Drawing::Size(92, 21);
			this->cmbBx1_SwtGrp->TabIndex = 9;
			this->cmbBx1_SwtGrp->Text = L"-";
			// 
			// lbl9_MaxVltg
			// 
			this->lbl9_MaxVltg->AutoSize = true;
			this->lbl9_MaxVltg->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->lbl9_MaxVltg->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl9_MaxVltg->Location = System::Drawing::Point(115, 405);
			this->lbl9_MaxVltg->Name = L"lbl9_MaxVltg";
			this->lbl9_MaxVltg->Size = System::Drawing::Size(34, 13);
			this->lbl9_MaxVltg->TabIndex = 2;
			this->lbl9_MaxVltg->Text = L"100.0";
			this->lbl9_MaxVltg->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtBx7_MaxVltg
			// 
			this->txtBx7_MaxVltg->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx7_MaxVltg->Location = System::Drawing::Point(115, 421);
			this->txtBx7_MaxVltg->Name = L"txtBx7_MaxVltg";
			this->txtBx7_MaxVltg->Size = System::Drawing::Size(107, 20);
			this->txtBx7_MaxVltg->TabIndex = 10;
			this->txtBx7_MaxVltg->Text = L"100.0";
			this->txtBx7_MaxVltg->Leave += gcnew System::EventHandler(this, &CnfChnl::TxtBx7_MaxVltg_Leave);
			// 
			// lbl11_MaxCrrt
			// 
			this->lbl11_MaxCrrt->AutoSize = true;
			this->lbl11_MaxCrrt->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->lbl11_MaxCrrt->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl11_MaxCrrt->Location = System::Drawing::Point(115, 446);
			this->lbl11_MaxCrrt->Name = L"lbl11_MaxCrrt";
			this->lbl11_MaxCrrt->Size = System::Drawing::Size(34, 13);
			this->lbl11_MaxCrrt->TabIndex = 2;
			this->lbl11_MaxCrrt->Text = L"100.0";
			this->lbl11_MaxCrrt->Click += gcnew System::EventHandler(this, &CnfChnl::Lbl11_MaxCrrt_Click);
			// 
			// txtBx8_MaxCrrt
			// 
			this->txtBx8_MaxCrrt->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx8_MaxCrrt->Location = System::Drawing::Point(115, 462);
			this->txtBx8_MaxCrrt->Name = L"txtBx8_MaxCrrt";
			this->txtBx8_MaxCrrt->Size = System::Drawing::Size(107, 20);
			this->txtBx8_MaxCrrt->TabIndex = 11;
			this->txtBx8_MaxCrrt->Text = L"100.0";
			this->txtBx8_MaxCrrt->TextChanged += gcnew System::EventHandler(this, &CnfChnl::TxtBx8_MaxCrrt_TextChanged);
			this->txtBx8_MaxCrrt->Leave += gcnew System::EventHandler(this, &CnfChnl::txtBx8_MaxCrrt_Leave);
			// 
			// btn1_ClearAllLimits
			// 
			this->btn1_ClearAllLimits->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btn1_ClearAllLimits->Location = System::Drawing::Point(115, 486);
			this->btn1_ClearAllLimits->Name = L"btn1_ClearAllLimits";
			this->btn1_ClearAllLimits->Size = System::Drawing::Size(107, 18);
			this->btn1_ClearAllLimits->TabIndex = 12;
			this->btn1_ClearAllLimits->Text = L"Clear limits";
			this->btn1_ClearAllLimits->UseVisualStyleBackColor = true;
			this->btn1_ClearAllLimits->Click += gcnew System::EventHandler(this, &CnfChnl::Btn1_ClearAllLimits_Click);
			// 
			// lbl10_ActVltg
			// 
			this->lbl10_ActVltg->AutoSize = true;
			this->lbl10_ActVltg->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl10_ActVltg->Location = System::Drawing::Point(16, 424);
			this->lbl10_ActVltg->Name = L"lbl10_ActVltg";
			this->lbl10_ActVltg->Size = System::Drawing::Size(84, 13);
			this->lbl10_ActVltg->TabIndex = 2;
			this->lbl10_ActVltg->Text = L"act. Voltage limit";
			// 
			// lbl12_ActCrrt
			// 
			this->lbl12_ActCrrt->AutoSize = true;
			this->lbl12_ActCrrt->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl12_ActCrrt->Location = System::Drawing::Point(16, 465);
			this->lbl12_ActCrrt->Name = L"lbl12_ActCrrt";
			this->lbl12_ActCrrt->Size = System::Drawing::Size(82, 13);
			this->lbl12_ActCrrt->TabIndex = 2;
			this->lbl12_ActCrrt->Text = L"act. Current limit";
			// 
			// chkBx3_CtrlPwr
			// 
			this->chkBx3_CtrlPwr->AutoSize = true;
			this->chkBx3_CtrlPwr->Enabled = false;
			this->chkBx3_CtrlPwr->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->chkBx3_CtrlPwr->ForeColor = System::Drawing::SystemColors::Window;
			this->chkBx3_CtrlPwr->Location = System::Drawing::Point(3, 2);
			this->chkBx3_CtrlPwr->Name = L"chkBx3_CtrlPwr";
			this->chkBx3_CtrlPwr->Size = System::Drawing::Size(89, 17);
			this->chkBx3_CtrlPwr->TabIndex = 13;
			this->chkBx3_CtrlPwr->Text = L"Control power";
			this->chkBx3_CtrlPwr->UseVisualStyleBackColor = false;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->chkBx3_CtrlPwr);
			this->panel1->Controls->Add(this->txtBx9_CtrlPwr);
			this->panel1->Enabled = false;
			this->panel1->Location = System::Drawing::Point(19, 508);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(283, 27);
			this->panel1->TabIndex = 7;
			// 
			// txtBx9_CtrlPwr
			// 
			this->txtBx9_CtrlPwr->Enabled = false;
			this->txtBx9_CtrlPwr->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx9_CtrlPwr->Location = System::Drawing::Point(94, 2);
			this->txtBx9_CtrlPwr->Name = L"txtBx9_CtrlPwr";
			this->txtBx9_CtrlPwr->Size = System::Drawing::Size(182, 20);
			this->txtBx9_CtrlPwr->TabIndex = 14;
			this->txtBx9_CtrlPwr->Text = L"0.0 W";
			// 
			// btn2_Ok
			// 
			this->btn2_Ok->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btn2_Ok->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btn2_Ok->Location = System::Drawing::Point(20, 561);
			this->btn2_Ok->Name = L"btn2_Ok";
			this->btn2_Ok->Size = System::Drawing::Size(128, 21);
			this->btn2_Ok->TabIndex = 15;
			this->btn2_Ok->Text = L"Ok";
			this->btn2_Ok->UseVisualStyleBackColor = false;
			this->btn2_Ok->Click += gcnew System::EventHandler(this, &CnfChnl::Btn2_Ok_Click);
			// 
			// btn3_Cancel
			// 
			this->btn3_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn3_Cancel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btn3_Cancel->Location = System::Drawing::Point(181, 561);
			this->btn3_Cancel->Name = L"btn3_Cancel";
			this->btn3_Cancel->Size = System::Drawing::Size(132, 21);
			this->btn3_Cancel->TabIndex = 16;
			this->btn3_Cancel->Text = L"Cancel";
			this->btn3_Cancel->UseVisualStyleBackColor = true;
			// 
			// lbl13_CrateRamps
			// 
			this->lbl13_CrateRamps->AutoSize = true;
			this->lbl13_CrateRamps->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl13_CrateRamps->Location = System::Drawing::Point(228, 70);
			this->lbl13_CrateRamps->Name = L"lbl13_CrateRamps";
			this->lbl13_CrateRamps->Size = System::Drawing::Size(89, 13);
			this->lbl13_CrateRamps->TabIndex = 2;
			this->lbl13_CrateRamps->Text = L"Crate act. Ramps";
			this->lbl13_CrateRamps->Click += gcnew System::EventHandler(this, &CnfChnl::Label1_Click);
			// 
			// lbl14_vUpRamp
			// 
			this->lbl14_vUpRamp->AutoSize = true;
			this->lbl14_vUpRamp->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl14_vUpRamp->Location = System::Drawing::Point(248, 88);
			this->lbl14_vUpRamp->Name = L"lbl14_vUpRamp";
			this->lbl14_vUpRamp->Size = System::Drawing::Size(39, 13);
			this->lbl14_vUpRamp->TabIndex = 2;
			this->lbl14_vUpRamp->Text = L"20 V/s";
			this->lbl14_vUpRamp->Click += gcnew System::EventHandler(this, &CnfChnl::Label1_Click);
			// 
			// lbl15_vDownRamp
			// 
			this->lbl15_vDownRamp->AutoSize = true;
			this->lbl15_vDownRamp->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl15_vDownRamp->Location = System::Drawing::Point(249, 110);
			this->lbl15_vDownRamp->Name = L"lbl15_vDownRamp";
			this->lbl15_vDownRamp->Size = System::Drawing::Size(39, 13);
			this->lbl15_vDownRamp->TabIndex = 2;
			this->lbl15_vDownRamp->Text = L"20 V/s";
			this->lbl15_vDownRamp->Click += gcnew System::EventHandler(this, &CnfChnl::Label1_Click);
			// 
			// lbl16_iUpRamp
			// 
			this->lbl16_iUpRamp->AutoSize = true;
			this->lbl16_iUpRamp->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl16_iUpRamp->Location = System::Drawing::Point(249, 141);
			this->lbl16_iUpRamp->Name = L"lbl16_iUpRamp";
			this->lbl16_iUpRamp->Size = System::Drawing::Size(48, 13);
			this->lbl16_iUpRamp->TabIndex = 2;
			this->lbl16_iUpRamp->Text = L"0.10 A/s";
			this->lbl16_iUpRamp->Click += gcnew System::EventHandler(this, &CnfChnl::Label1_Click);
			// 
			// lbl17_iDownRamp
			// 
			this->lbl17_iDownRamp->AutoSize = true;
			this->lbl17_iDownRamp->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl17_iDownRamp->Location = System::Drawing::Point(249, 164);
			this->lbl17_iDownRamp->Name = L"lbl17_iDownRamp";
			this->lbl17_iDownRamp->Size = System::Drawing::Size(48, 13);
			this->lbl17_iDownRamp->TabIndex = 2;
			this->lbl17_iDownRamp->Text = L"0.10 A/s";
			this->lbl17_iDownRamp->Click += gcnew System::EventHandler(this, &CnfChnl::Label1_Click);
			// 
			// lbl18_CrateSPs
			// 
			this->lbl18_CrateSPs->AutoSize = true;
			this->lbl18_CrateSPs->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl18_CrateSPs->Location = System::Drawing::Point(226, 405);
			this->lbl18_CrateSPs->Name = L"lbl18_CrateSPs";
			this->lbl18_CrateSPs->Size = System::Drawing::Size(101, 13);
			this->lbl18_CrateSPs->TabIndex = 2;
			this->lbl18_CrateSPs->Text = L"Crate act. SetPoints";
			this->lbl18_CrateSPs->Click += gcnew System::EventHandler(this, &CnfChnl::Label1_Click);
			// 
			// lbl19_CrateV_SP
			// 
			this->lbl19_CrateV_SP->AutoSize = true;
			this->lbl19_CrateV_SP->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl19_CrateV_SP->Location = System::Drawing::Point(249, 424);
			this->lbl19_CrateV_SP->Name = L"lbl19_CrateV_SP";
			this->lbl19_CrateV_SP->Size = System::Drawing::Size(29, 13);
			this->lbl19_CrateV_SP->TabIndex = 2;
			this->lbl19_CrateV_SP->Text = L"20 V";
			this->lbl19_CrateV_SP->Click += gcnew System::EventHandler(this, &CnfChnl::Label1_Click);
			// 
			// lbl20_CrateI_SP
			// 
			this->lbl20_CrateI_SP->AutoSize = true;
			this->lbl20_CrateI_SP->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl20_CrateI_SP->Location = System::Drawing::Point(249, 465);
			this->lbl20_CrateI_SP->Name = L"lbl20_CrateI_SP";
			this->lbl20_CrateI_SP->Size = System::Drawing::Size(38, 13);
			this->lbl20_CrateI_SP->TabIndex = 2;
			this->lbl20_CrateI_SP->Text = L"0.40 A";
			this->lbl20_CrateI_SP->Click += gcnew System::EventHandler(this, &CnfChnl::Label1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::Window;
			this->label1->Location = System::Drawing::Point(16, 405);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Max. Voltage =                       V";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::Window;
			this->label2->Location = System::Drawing::Point(17, 446);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(166, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Max. Current =                       Amp";
			// 
			// lbl_NewVhnlName
			// 
			this->lbl_NewVhnlName->AutoSize = true;
			this->lbl_NewVhnlName->ForeColor = System::Drawing::SystemColors::Window;
			this->lbl_NewVhnlName->Location = System::Drawing::Point(15, 37);
			this->lbl_NewVhnlName->Name = L"lbl_NewVhnlName";
			this->lbl_NewVhnlName->Size = System::Drawing::Size(66, 13);
			this->lbl_NewVhnlName->TabIndex = 2;
			this->lbl_NewVhnlName->Text = L"New Name: ";
			// 
			// txtBx1_NewChnlName
			// 
			this->txtBx1_NewChnlName->BackColor = System::Drawing::SystemColors::Window;
			this->txtBx1_NewChnlName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBx1_NewChnlName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBx1_NewChnlName->Location = System::Drawing::Point(145, 39);
			this->txtBx1_NewChnlName->Name = L"txtBx1_NewChnlName";
			this->txtBx1_NewChnlName->Size = System::Drawing::Size(159, 20);
			this->txtBx1_NewChnlName->TabIndex = 1;
			this->txtBx1_NewChnlName->Leave += gcnew System::EventHandler(this, &CnfChnl::TextBox1_Leave);
			// 
			// cmbBx1_ChnlNames
			// 
			this->cmbBx1_ChnlNames->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->cmbBx1_ChnlNames->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->cmbBx1_ChnlNames->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBx1_ChnlNames->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->cmbBx1_ChnlNames->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->cmbBx1_ChnlNames->Location = System::Drawing::Point(212, 253);
			this->cmbBx1_ChnlNames->Margin = System::Windows::Forms::Padding(4);
			this->cmbBx1_ChnlNames->Name = L"cmbBx1_ChnlNames";
			this->cmbBx1_ChnlNames->Size = System::Drawing::Size(92, 19);
			this->cmbBx1_ChnlNames->TabIndex = 6;
			this->cmbBx1_ChnlNames->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &CnfChnl::cmbBx1_DrawItem);
			this->cmbBx1_ChnlNames->SelectedIndexChanged += gcnew System::EventHandler(this, &CnfChnl::CmbBx1_ChnlNames_IndexChanged);
			this->cmbBx1_ChnlNames->DropDownClosed += gcnew System::EventHandler(this, &CnfChnl::cmBx1_DropClosed);
			this->cmbBx1_ChnlNames->MouseLeave += gcnew System::EventHandler(this, &CnfChnl::cmBx1_MouseLeave);
			// 
			// lbl14_ChooseChnl
			// 
			this->lbl14_ChooseChnl->AutoEllipsis = true;
			this->lbl14_ChooseChnl->BackColor = System::Drawing::Color::Transparent;
			this->lbl14_ChooseChnl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl14_ChooseChnl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lbl14_ChooseChnl->Location = System::Drawing::Point(214, 255);
			this->lbl14_ChooseChnl->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->lbl14_ChooseChnl->Name = L"lbl14_ChooseChnl";
			this->lbl14_ChooseChnl->Size = System::Drawing::Size(69, 15);
			this->lbl14_ChooseChnl->TabIndex = 0;
			this->lbl14_ChooseChnl->Text = L"Choose chnl...";
			// 
			// label4_CurrentFormuChnl
			// 
			this->label4_CurrentFormuChnl->AutoEllipsis = true;
			this->label4_CurrentFormuChnl->BackColor = System::Drawing::Color::Transparent;
			this->label4_CurrentFormuChnl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4_CurrentFormuChnl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4_CurrentFormuChnl->Location = System::Drawing::Point(214, 340);
			this->label4_CurrentFormuChnl->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label4_CurrentFormuChnl->Name = L"label4_CurrentFormuChnl";
			this->label4_CurrentFormuChnl->Size = System::Drawing::Size(69, 15);
			this->label4_CurrentFormuChnl->TabIndex = 17;
			this->label4_CurrentFormuChnl->Text = L"Choose chnl...";
			// 
			// cmbBx2_currentFormChnls
			// 
			this->cmbBx2_currentFormChnls->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->cmbBx2_currentFormChnls->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->cmbBx2_currentFormChnls->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBx2_currentFormChnls->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->cmbBx2_currentFormChnls->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->cmbBx2_currentFormChnls->Location = System::Drawing::Point(211, 338);
			this->cmbBx2_currentFormChnls->Margin = System::Windows::Forms::Padding(4);
			this->cmbBx2_currentFormChnls->Name = L"cmbBx2_currentFormChnls";
			this->cmbBx2_currentFormChnls->Size = System::Drawing::Size(92, 19);
			this->cmbBx2_currentFormChnls->TabIndex = 18;
			this->cmbBx2_currentFormChnls->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &CnfChnl::cmbBx2_DrawItem);
			this->cmbBx2_currentFormChnls->SelectedIndexChanged += gcnew System::EventHandler(this, &CnfChnl::cmbBx2_currentFormChnls_IndexChanged);
			//this->cmbBx2_currentFormChnls->DropDownClosed += gcnew System::EventHandler(this, &CnfChnl::cmBx2_DropClosed);
			//this->cmbBx2_currentFormChnls->MouseLeave += gcnew System::EventHandler(this, &CnfChnl::cmBx2_MouseLeave);
			// 
			// CnfChnl
			// 
			this->AcceptButton = this->btn2_Ok;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->CancelButton = this->btn3_Cancel;
			this->ClientSize = System::Drawing::Size(325, 597);
			this->Controls->Add(this->label4_CurrentFormuChnl);
			this->Controls->Add(this->cmbBx2_currentFormChnls);
			this->Controls->Add(this->lbl14_ChooseChnl);
			this->Controls->Add(this->cmbBx1_ChnlNames);
			this->Controls->Add(this->lbl9_MaxVltg);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btn3_Cancel);
			this->Controls->Add(this->btn2_Ok);
			this->Controls->Add(this->btn1_ClearAllLimits);
			this->Controls->Add(this->cmbBx1_SwtGrp);
			this->Controls->Add(this->chkBx2_UseCrrtFrm);
			this->Controls->Add(this->chkBx1_UseFormuVltg);
			this->Controls->Add(this->txtBx8_MaxCrrt);
			this->Controls->Add(this->txtBx7_MaxVltg);
			this->Controls->Add(this->txtBx1_NewChnlName);
			this->Controls->Add(this->txtBx6_CrrtFrm);
			this->Controls->Add(this->txtBx5_VltgFrm);
			this->Controls->Add(this->txtBx4_CrrtFallRate);
			this->Controls->Add(this->txtBx3_CrrtRiseRate);
			this->Controls->Add(this->txtBx2_VltgFallRate);
			this->Controls->Add(this->lbl11_MaxCrrt);
			this->Controls->Add(this->txtBx1_VltgRiseRate);
			this->Controls->Add(this->lbl17_iDownRamp);
			this->Controls->Add(this->lbl16_iUpRamp);
			this->Controls->Add(this->lbl15_vDownRamp);
			this->Controls->Add(this->lbl14_vUpRamp);
			this->Controls->Add(this->lbl20_CrateI_SP);
			this->Controls->Add(this->lbl19_CrateV_SP);
			this->Controls->Add(this->lbl18_CrateSPs);
			this->Controls->Add(this->lbl13_CrateRamps);
			this->Controls->Add(this->lbl_NewVhnlName);
			this->Controls->Add(this->lbl12_ActCrrt);
			this->Controls->Add(this->lbl10_ActVltg);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbl8_SwtcGrpCnf);
			this->Controls->Add(this->lbl7_CrrtFrm);
			this->Controls->Add(this->lbl3_VltgFallRate);
			this->Controls->Add(this->lbl6_VltgFrm);
			this->Controls->Add(this->lbl5_CrrtFallRate);
			this->Controls->Add(this->lbl4_CrrtRiseRate);
			this->Controls->Add(this->lbl2_VltgRiseRate);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"CnfChnl";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Configure channel limits";
			this->Load += gcnew System::EventHandler(this, &CnfChnl::CnfChnl_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//this->cmbBx1_ChnlNames->DrawItem += gcnew DrawItemEventHandler(this, &CnfChnl::cmbBx1_DrawItem);
private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void CnfChnl_Load(System::Object^ sender, System::EventArgs^ e) {
	
	List<String^>^ m_iChnlNames;
	m_iChnlNames =  (m_ChnlNames);
	cmbBx1_SwtGrp->Items->AddRange(m_pGroupNames->ToArray());
	cmbBx2_currentFormChnls->Items->AddRange(m_ChnlNames->ToArray());
	cmbBx1_ChnlNames->Items->AddRange(m_ChnlNames->ToArray());

	this->txtBx7_MaxVltg->Text = this->VoltSP_Limit;
	this->txtBx8_MaxCrrt->Text = this->CrrntSP_Limit;
	
	this->cmbBx1_ChnlNames->Text = L"Chnls names";
	this->lbl14_ChooseChnl->Visible = true;
	this->lbl14_ChooseChnl->BringToFront();
	this->chkBx1_UseFormuVltg->Checked = this->UseVoltageFormula;
	this->txtBx5_VltgFrm->Text = this->formula;
	this->txtBx5_VltgFrm->Enabled = this->UseVoltageFormula;
	this->cmbBx1_ChnlNames->Enabled = chkBx1_UseFormuVltg->Checked;


	this->chkBx2_UseCrrtFrm->Checked = this->UseCurrentFormula;
	this->txtBx6_CrrtFrm->Text = this->iformula;
	this->txtBx6_CrrtFrm->Enabled = this->UseCurrentFormula;
	this->cmbBx2_currentFormChnls->Enabled = chkBx2_UseCrrtFrm->Checked;

	// 05/12/22 Add MAX Limits for V,I using nominal and limits by user
	this->lbl9_MaxVltg->Text = this->nominalVolt;
	this->lbl19_CrateV_SP->Text = this->vSetPoint;
	this->lbl11_MaxCrrt->Text = this->nominalCurrent;
	this->lbl20_CrateI_SP->Text = this->cSetPoint;

	// Tool tip for formula checkbox
		// Set up the delays for the ToolTip.
	toolTipFormulaTxtBx.AutoPopDelay = 5000;
	toolTipFormulaTxtBx.InitialDelay = 1000;
	toolTipFormulaTxtBx.ReshowDelay = 500;
	// Force the ToolTip text to be displayed whether or not the form is active.
	toolTipFormulaTxtBx.ShowAlways = true;
	// Set up the ToolTip text for the Button and Checkbox.
	toolTip1.SetToolTip(this->txtBx5_VltgFrm, this->txtBx5_VltgFrm->Text);
	UpdateForm();
}
// 
// Apply changes OK  button click
private: System::Void Btn2_Ok_Click(System::Object^ sender, System::EventArgs^ e) {
	// Validate input inside ranges [0.1 - 20]% of Nominal voltage
	String^ msgToUser = nullptr;
	
	if (!m_cmdMsg->execRequest) {
		m_cmdMsg->CleanCmdsLists();
		/***** Checking Voltage Ramp change *******/
		if ((txtBx1_VltgRiseRate->Modified) && !(String::IsNullOrEmpty(txtBx1_VltgRiseRate->Text))) {
			// Convert to numerical value and validate ranges
			Double val;
			if ((MyCrate != nullptr) && Double::TryParse(this->txtBx7_MaxVltg->Text, val) && GlobalFuncValidateSP(txtBx1_VltgRiseRate->Text, this->txtBx7_MaxVltg->Text, 0.0, 1.0))
			{
				Double val2;
				Double::TryParse(this->txtBx1_VltgRiseRate->Text, val);
				Double::TryParse(this->lbl9_MaxVltg->Text, val2);
				val = (val / val2) * 100;
				m_cmdMsg->GlobalAddSendCmds(GlobalGetModName(this->ChnlName) + ":VoltageRampSpeed",
											val.ToString(), MODULE_CMD, 3, false);
			}
			else m_cmdMsg->StatusBarMsgIndex = 16;

			txtBx1_VltgRiseRate->Modified = false;
		}
		/***** Checking Current Ramp change *******/
		if ((txtBx3_CrrtRiseRate->Modified) && (!String::IsNullOrEmpty(txtBx3_CrrtRiseRate->Text))) {
			// Convert to numerical value and validate ranges
			Double val;
			if ((MyCrate != nullptr) && (Double::TryParse(txtBx8_MaxCrrt->Text, val)) && GlobalFuncValidateSP(txtBx3_CrrtRiseRate->Text, this->lbl11_MaxCrrt->Text, 0.0, 1.0))
			{
				Double val2;
				Double::TryParse(this->txtBx3_CrrtRiseRate->Text, val);
				Double::TryParse(this->lbl11_MaxCrrt->Text, val2);
				val = (val / val2) * 100;
				m_cmdMsg->GlobalAddSendCmds(GlobalGetModName(this->ChnlName) + ":CurrentRampSpeed",
											val.ToString(), MODULE_CMD, 3, false);
			}
			else m_cmdMsg->StatusBarMsgIndex = 16;
			
			txtBx3_CrrtRiseRate->Modified = false;
		}
		this->UseCurrentFormula = this->chkBx2_UseCrrtFrm->Checked;
		this->UseVoltageFormula = this->chkBx1_UseFormuVltg->Checked;
	}
	/***** Checking Voltage and Current MAX values changes (For Set Points) *******/
	if ((txtBx7_MaxVltg->Modified) && (!String::IsNullOrEmpty(txtBx7_MaxVltg->Text))) {
		// Convert to numerical value and validate ranges
		Double val;
		if (GlobalFuncValidateSP(txtBx7_MaxVltg->Text, this->lbl9_MaxVltg->Text, 0.0, 1.0)
			&& (!GlobalFuncValidateSP(txtBx7_MaxVltg->Text, vSetPoint, 0.0, 1.0)))
		{
			/*m_cmdMsg->GlobalAddSendCmds(this->ChnlName + ":VoltageSet",
										txtBx7_MaxVltg->Text, CHANNEL_CMD, 3, false);*/
			this->VoltSP_Limit = txtBx7_MaxVltg->Text;
			
		}
		else m_cmdMsg->StatusBarMsgIndex = 16;

		
		txtBx7_MaxVltg->Modified = false;
	}
	if ((txtBx8_MaxCrrt->Modified) && (!String::IsNullOrEmpty(txtBx8_MaxCrrt->Text))
		&& (!GlobalFuncValidateSP(txtBx7_MaxVltg->Text, cSetPoint, 0.0, 1.0))) {
		// Convert to numerical value and validate ranges
		Double val;
		if (GlobalFuncValidateSP(txtBx8_MaxCrrt->Text, this->lbl11_MaxCrrt->Text, 0.0,1.0))
		{
			/*m_cmdMsg->GlobalAddSendCmds(this->ChnlName + ":CurrentSet",
										txtBx8_MaxCrrt->Text, CHANNEL_CMD, 3, false);*/
			this->CrrntSP_Limit = txtBx8_MaxCrrt->Text;
			
		}
		else m_cmdMsg->StatusBarMsgIndex = 16;

		
		txtBx8_MaxCrrt->Modified = false;
	}
	if (m_cmdMsg->strCmdsToExcList->Count > 0) {
		m_cmdMsg->GlobalAddSendCmds("", "", -1, 3, true);
		
	}
	else {
		;
	}

	
	
	if (m_cmdMsg->cmdExecuted) {
		// Load channel config info: vRamp, iRamp, vSetPoint, iSetPoint, NominalVolt, NominalCurrent.
		UpdateForm();
		m_cmdMsg->CleanCmdsLists();
		m_cmdMsg->StatusBarMsgIndex = 28;
	}
	if (!String::IsNullOrEmpty(msgToUser)) {
		msgToUser += "\r\n \r\n You can reenter (a) valid value(s) or cancel and continue ...";
		MessageBox::Show(msgToUser);
		msgToUser = "";
	}
	
	if (this->txtBx1_NewChnlName->Modified) {
		if (!String::IsNullOrEmpty(this->txtBx1_NewChnlName->Text)) 
		{
			String^ strName(this->txtBx1_NewChnlName->Text);
			std::string os;
			//const std::regex vowels("[+/^%* =!~`'\"\\,; ]");
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(strName)).ToPointer();
			os = chars; std::regex rx2("[+/^%* =\\!\\~`'\"\\\\,; \\]\\[\\{\\}&@#$\\%()]");
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			std::stringstream result;
			std::regex_replace(std::ostream_iterator<char>(result),
				os.begin(),	os.end(), rx2, "");
			
			//this->lbl1_CnfChnl->Text = strName;
			const std::string& resultstr = result.str();
			const char* cstr2 = resultstr.c_str();
			String^ strNewName = gcnew String(cstr2);
			strNewName = strNewName->TrimStart('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', ':');
			this->txtBx1_NewChnlName->Text = strNewName;
			this->lbl1_CnfChnl->Text = this->txtBx1_NewChnlName->Text;
		}
		this->txtBx1_NewChnlName->Modified = false;
	}
	if ((this->chkBx1_UseFormuVltg->Checked) && (this->formula != this->txtBx5_VltgFrm->Text)) {
		this->formula = this->txtBx5_VltgFrm->Text;
		this->NameIndex = 0;		
	}
	if ((this->chkBx2_UseCrrtFrm->Checked) && (this->iformula != this->txtBx6_CrrtFrm->Text)) {
		this->iformula = this->txtBx6_CrrtFrm->Text;
		this->NameIndex = 0;
	}
}

private: void UpdateForm() {
	this->ActiveControl = btn3_Cancel;
	// Load channel config info: vRamp, iRamp, vSetPoint, iSetPoint, NominalVolt, NominalCurrent.
			 if (m_ptrMainCrateList->Count > 0) {
				 Crate^ crate;
				 System::Array^ strArray = this->ChnlName->Split(':');
				 crate = m_MainDataStruct->GetCrate(System::Convert::ToString(strArray->GetValue(0))
					 + ":"
					 + System::Convert::ToString(strArray->GetValue(1)));
				 if (crate != nullptr) {
					 MyCrate = crate;
					 Double val;
					 this->lbl14_vUpRamp->Text = m_MainDataStruct->GetChnlVoltRamp(this->ChnlName);
					 this->lbl15_vDownRamp->Text = this->lbl14_vUpRamp->Text;
					 if (Double::TryParse(this->lbl14_vUpRamp->Text, val)) {
						 vRamp = val;
						 this->lbl14_vUpRamp->Text = Math::Round(vRamp, 2).ToString();
						 this->lbl15_vDownRamp->Text = this->lbl14_vUpRamp->Text;
					 }
					 this->lbl16_iUpRamp->Text = m_MainDataStruct->GetChnlCrrntRamp(this->ChnlName);
					 this->lbl17_iDownRamp->Text = this->lbl16_iUpRamp->Text;
					 if (Double::TryParse(this->lbl16_iUpRamp->Text, val)) {
						 cRamp = val;
						 this->lbl16_iUpRamp->Text = Math::Round(cRamp, 6).ToString();
						 this->lbl17_iDownRamp->Text = this->lbl16_iUpRamp->Text;
					 }

					 this->lbl9_MaxVltg->Text = m_MainDataStruct->GetChnlNomVolt(this->ChnlName);
					 this->txtBx7_MaxVltg->Text = this->VoltSP_Limit;
					 this->lbl11_MaxCrrt->Text = m_MainDataStruct->GetChnlNomCrrnt(this->ChnlName);
					 this->txtBx8_MaxCrrt->Text = this->CrrntSP_Limit;
					 
					 if (this->lbl11_MaxCrrt->Text->Length > 6)
						 this->lbl11_MaxCrrt->Text = this->lbl11_MaxCrrt->Text->Substring(0, 6);
					 
					 this->lbl19_CrateV_SP->Text = m_MainDataStruct->GetChnlVoltSet(this->ChnlName);
					 if (Double::TryParse(this->lbl19_CrateV_SP->Text, val)) {
						 vSetPoint = this->lbl19_CrateV_SP->Text; // 05/12/22
						 this->lbl19_CrateV_SP->Text = Math::Round(System::Convert::ToDouble(vSetPoint), 2).ToString();
					 }
					 this->lbl20_CrateI_SP->Text = m_MainDataStruct->GetChnlCrrntSet(this->ChnlName);
					 if (Double::TryParse(this->lbl20_CrateI_SP->Text, val)) {
						 cSetPoint = this->lbl20_CrateI_SP->Text; // 05/12/22
						 this->lbl20_CrateI_SP->Text = Math::Round(System::Convert::ToDouble(cSetPoint), 6).ToString();
					 }
				 }
			 }
			 // Disable Channel Ramp settings for Virtual channels
			 if (this->ChnlName->Contains("VChnl")) {
				 this->txtBx1_VltgRiseRate->Enabled = false;
				 this->txtBx3_CrrtRiseRate->Enabled = false;
				 this->txtBx7_MaxVltg->Enabled = false;
				 this->txtBx8_MaxCrrt->Enabled = false;
				 this->btn1_ClearAllLimits->Enabled = false;
			 }
}
			 
//
// New name textbox
private: System::Void TextBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
	this->txtBx1_NewChnlName->Modified = true;
}
private: System::Void TxtBx7_MaxVltg_Leave(System::Object^ sender, System::EventArgs^ e) {
	// Validate input inside ranges [0.1 - 100]% of Nominal voltage
	if (txtBx7_MaxVltg != nullptr) {
		// Convert to numerical value and validate ranges
		Double val, val2;
		if (!Double::TryParse(txtBx7_MaxVltg->Text, val)) {
			MessageBox::Show("Entry wasn't numeric");
			txtBx7_MaxVltg->Modified = false;
			return;
		}
		if (!Double::TryParse(this->lbl9_MaxVltg->Text, val2)) {
			MessageBox::Show("Entry wasn't numeric");
			txtBx7_MaxVltg->Modified = false;
			return;
		}
		if (val2 < 0) {
			val2 *= -1; val *= -1;
		}
		if ((val < 0.0 * val2) || (val > 1.0 * val2)) {
			txtBx7_MaxVltg->Undo();
			txtBx7_MaxVltg->Modified = false;
			return;
		}
		txtBx7_MaxVltg->Modified = true;
	}

}
private: System::Void txtBx8_MaxCrrt_Leave(System::Object^ sender, System::EventArgs^ e) {
	txtBx8_MaxCrrt->Modified = true;
}
private: System::Void Btn1_ClearAllLimits_Click(System::Object^ sender, System::EventArgs^ e) {
	this->txtBx7_MaxVltg->Text="";
	this->txtBx7_MaxVltg->Modified = false;
	this->txtBx8_MaxCrrt->Text = "";
	this->txtBx8_MaxCrrt->Modified = false;
}
private: System::Void TxtBx1_VltgRiseRate_Leave(System::Object^ sender, System::EventArgs^ e) {
	txtBx1_VltgRiseRate->Modified = true;
}
private: System::Void TxtBx3_CrrtRiseRate_Leave(System::Object^ sender, System::EventArgs^ e) {
	txtBx3_CrrtRiseRate->Modified = true;
}
//
private: void cmbBx1_DrawItem(System::Object^ sender, DrawItemEventArgs^ e)
		 {
			//this->lbl14_ChooseChnl->Visible = false;
			if (e->Index < 0) { return; }
			 text = this->cmbBx1_ChnlNames->GetItemText(cmbBx1_ChnlNames->Items[e->Index]);
			 e->DrawBackground();
			 if (SolidBrush^ br = gcnew SolidBrush(e->ForeColor))
			 {
				 e->Graphics->DrawString(text, e->Font, br, e->Bounds);
			 }

			 if ((e->State & DrawItemState::Selected) == DrawItemState::Selected && cmbBx1_ChnlNames->DroppedDown)
			 {
				 if (textRenderer->MeasureText(text, cmbBx1_ChnlNames->Font).Width > cmbBx1_ChnlNames->Width)
				 {
					 toolTip1.Show(text, cmbBx1_ChnlNames, e->Bounds.Right, e->Bounds.Bottom);
				 }
				 else
				 {
					 toolTip1.Hide(cmbBx1_ChnlNames);
				 }
			 }
			 e->DrawFocusRectangle();
		 }

// Tool Tio for combobox Current channels
private: void cmbBx2_DrawItem(System::Object^ sender, DrawItemEventArgs^ e)
{
	//this->lbl14_ChooseChnl->Visible = false;
	if (e->Index < 0) { return; }
	text = this->cmbBx2_currentFormChnls->GetItemText(cmbBx2_currentFormChnls->Items[e->Index]);
	e->DrawBackground();
	if (SolidBrush ^ br = gcnew SolidBrush(e->ForeColor))
	{
		e->Graphics->DrawString(text, e->Font, br, e->Bounds);
	}

	if ((e->State & DrawItemState::Selected) == DrawItemState::Selected && cmbBx2_currentFormChnls->DroppedDown)
	{
		if (textRenderer->MeasureText(text, cmbBx2_currentFormChnls->Font).Width > cmbBx2_currentFormChnls->Width)
		{
			toolTip1.Show(text, cmbBx2_currentFormChnls, e->Bounds.Right, e->Bounds.Bottom);
		}
		else
		{
			toolTip1.Hide(cmbBx2_currentFormChnls);
		}
	}
	e->DrawFocusRectangle();
}

private: void cmBx1_DropClosed(System::Object^ sender, EventArgs^ e)
		 {
			 toolTip1.Hide(cmbBx1_ChnlNames);
			 this->lbl14_ChooseChnl->Visible = true;
			 this->lbl14_ChooseChnl->BringToFront();
		 }

private: void cmBx1_MouseLeave(System::Object^ sender, EventArgs^ e)
		 {
			 toolTip1.Hide(cmbBx1_ChnlNames);
			 this->lbl14_ChooseChnl->Visible = true;
			 this->lbl14_ChooseChnl->BringToFront();
		 }

private: void combo_box1_MouseHover(System::Object^ sender, EventArgs^ e)
{
	this->lbl14_ChooseChnl->Visible = false;
	if (!cmbBx1_ChnlNames->DroppedDown && textRenderer->MeasureText(cmbBx1_ChnlNames->SelectedItem->ToString(), cmbBx1_ChnlNames->Font).Width > cmbBx1_ChnlNames->Width)
			 {
				 toolTip1.Show(cmbBx1_ChnlNames->SelectedItem->ToString(), cmbBx1_ChnlNames, cmbBx1_ChnlNames->Location.X, cmbBx1_ChnlNames->Location.Y);
			 }
}

//
// Check the combo box for channels chosen of the Use voltage formula check box
//
private: System::Void CmbBx1_ChnlNames_IndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->cmbBx1_ChnlNames->GetItemText(this->cmbBx1_ChnlNames->SelectedItem)->Contains(CHANNEL_VIEW_DEFAULT_NAME)) {
		this->cmbBx1_ChnlNames->SelectedIndex = -1;
	}
	else {
		this->txtBx5_VltgFrm->Text += "(" + this->cmbBx1_ChnlNames->GetItemText(this->cmbBx1_ChnlNames->SelectedItem) + ")";
		this->lbl14_ChooseChnl->Text = this->cmbBx1_ChnlNames->GetItemText(this->cmbBx1_ChnlNames->SelectedItem);
		this->cmbBx1_ChnlNames->SendToBack();
		this->lbl14_ChooseChnl->Visible = true;
		this->lbl14_ChooseChnl->BringToFront();
		this->NameIndex = this->cmbBx1_ChnlNames->SelectedIndex;
		this->toolTipChosenChnl.SetToolTip(this->lbl14_ChooseChnl, this->lbl14_ChooseChnl->Text);
		this->toolTip1.SetToolTip(this->txtBx5_VltgFrm, this->txtBx5_VltgFrm->Text);
		Console::WriteLine("Channel chosen: {0} at index: {1}", this->lbl14_ChooseChnl->Text, this->NameIndex);
	}
}

//
// Check the combo box for channels chosen of the Use current formula check box
//
private: System::Void cmbBx2_currentFormChnls_IndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->cmbBx2_currentFormChnls->GetItemText(this->cmbBx2_currentFormChnls->SelectedItem)->Contains(CHANNEL_VIEW_DEFAULT_NAME)) {
		this->cmbBx2_currentFormChnls->SelectedIndex = -1;
	}
	else {
		this->txtBx6_CrrtFrm->Text += "(" + this->cmbBx2_currentFormChnls->GetItemText(this->cmbBx2_currentFormChnls->SelectedItem) + ")";
		this->label4_CurrentFormuChnl->Text = this->cmbBx2_currentFormChnls->GetItemText(this->cmbBx2_currentFormChnls->SelectedItem);
		this->cmbBx2_currentFormChnls->SendToBack();
		this->label4_CurrentFormuChnl->Visible = true;
		this->label4_CurrentFormuChnl->BringToFront();
		this->NameIndex = this->cmbBx2_currentFormChnls->SelectedIndex;
		this->toolTipChosenChnl.SetToolTip(this->label4_CurrentFormuChnl, this->label4_CurrentFormuChnl->Text);
		this->toolTip1.SetToolTip(this->txtBx6_CrrtFrm, this->txtBx6_CrrtFrm->Text);
		Console::WriteLine("Channel chosen: {0} at index: {1}", this->label4_CurrentFormuChnl->Text, this->NameIndex);
	}
}
//private: System::Boolean ValidateSP(String^ spValue, String^ nomVltg, double lowLimitFactor, double highLimitFactor);

		 /*[System:Runtime:InteropServices:DllImport("user32.dll", CharSet = System:Runtime:InteropServices:CharSet:Auto)]
		 extern int SendMessage(IntPtr hWnd, int msg, int wParam, [System:Runtime:InteropServices:MarshalAs(System : Runtime : InteropServices : UnmanagedType : LPWStr)]string lParam);*/
private: System::Void TxtBx8_MaxCrrt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Lbl11_MaxCrrt_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TxtBx6_CrrtFrm_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TxtBx5_VltgFrm_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

//
// Check the status of the Use current formula check box
//
private: System::Void ChkBx2_UseCrrtFrm_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	
		this->txtBx6_CrrtFrm->Enabled = this->chkBx2_UseCrrtFrm->Checked;
		this->cmbBx2_currentFormChnls->Enabled = this->chkBx2_UseCrrtFrm->Checked;
	
}

//
//  Check the status of the Use voltage formula check box
//
private: System::Void ChkBx1_UseFormuVltg_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->chkBx1_UseFormuVltg->Checked) {
		this->txtBx5_VltgFrm->Enabled = true;
		this->cmbBx1_ChnlNames->Enabled = true;
	}
	else {
		this->txtBx5_VltgFrm->Enabled = false;
		this->cmbBx1_ChnlNames->Enabled = false;
	}
}

};
}
