#pragma once
#include "SltnChnlForm.h"
namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class ChnlSltnVForm : public System::Windows::Forms::Form
	{
	public: property int CrateLine;
			
	private: 
		CratesT^ m_pMainDataLists;
		List<XML_Classes::Channel^>^ M_pChnlsCnf;
		String^ m_chnlViewName;
		String^ m_chnlName;
		int m_modDir, m_chnlDir, m_index;
		System::Drawing::Color m_bckColor;
		property List<String^>^ m_ChnlsTaken;
		
	public:
		ChnlSltnVForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ChnlSltnVForm(CratesT^ ptrMainDataStruct, List<XML_Classes::Channel^>^ pChnlsViewCnfList, List<String^>^ chnlsTaken)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_pMainDataLists = ptrMainDataStruct;
			M_pChnlsCnf = pChnlsViewCnfList;
			m_ChnlsTaken = chnlsTaken;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChnlSltnVForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^ sltChnlbtn1;
	protected:

	protected:

	private: System::Windows::Forms::Button^ clearClrSeltnBtn2;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Button^ btn_ColorPicker;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		/* Properties */
	public:
		property String^ ChnlName {
			String^ get() { return m_chnlName; }
			void set(String^ name) { m_chnlName = name; }
		}
		property String^ ChnlViewName {
			String^ get() { return m_chnlViewName; }
			void set(String^ name) { m_chnlViewName = name; }
		}
		property int CrateDir;
		property int ModDir {
			int get() { return m_modDir; }
			void set(int modDir) { m_modDir = modDir; }
		}
		property int ChnlDir {
			int get() { return this->m_chnlDir; }
			void set(int chnlDir) { this->m_chnlDir = chnlDir; }
		}
		property int Index {
			int get() { return m_index; }
			void set(int index) { m_index = index; }
		}
		property System::Drawing::Color ChnlColor {
			System::Drawing::Color get() { return m_bckColor; }
			void set(System::Drawing::Color chnlColor) { m_bckColor = chnlColor; }
		}
		property int ChnlType;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChnlSltnVForm::typeid));
			this->sltChnlbtn1 = (gcnew System::Windows::Forms::Button());
			this->clearClrSeltnBtn2 = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->btn_ColorPicker = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// sltChnlbtn1
			// 
			resources->ApplyResources(this->sltChnlbtn1, L"sltChnlbtn1");
			this->sltChnlbtn1->Name = L"sltChnlbtn1";
			this->sltChnlbtn1->UseVisualStyleBackColor = true;
			this->sltChnlbtn1->Click += gcnew System::EventHandler(this, &ChnlSltnVForm::SltChnlbtn1_Click);
			// 
			// clearClrSeltnBtn2
			// 
			resources->ApplyResources(this->clearClrSeltnBtn2, L"clearClrSeltnBtn2");
			this->clearClrSeltnBtn2->Name = L"clearClrSeltnBtn2";
			this->clearClrSeltnBtn2->UseVisualStyleBackColor = true;
			this->clearClrSeltnBtn2->Click += gcnew System::EventHandler(this, &ChnlSltnVForm::ClearClrSeltnBtn2_Click);
			// 
			// btn_ColorPicker
			// 
			this->btn_ColorPicker->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			resources->ApplyResources(this->btn_ColorPicker, L"btn_ColorPicker");
			this->btn_ColorPicker->Name = L"btn_ColorPicker";
			this->btn_ColorPicker->UseVisualStyleBackColor = false;
			this->btn_ColorPicker->Click += gcnew System::EventHandler(this, &ChnlSltnVForm::Button1_Click);
			// 
			// ChnlSltnVForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Controls->Add(this->btn_ColorPicker);
			this->Controls->Add(this->clearClrSeltnBtn2);
			this->Controls->Add(this->sltChnlbtn1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ChnlSltnVForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->ResumeLayout(false);

		}
#pragma endregion

//
// Gets the channel selected from a radio button click
private: System::Void SltChnlbtn1_Click(System::Object^ sender, System::EventArgs^ e) {
		SltnChnlForm^ slctChannel = gcnew SltnChnlForm(m_pMainDataLists, m_ChnlsTaken);

		if (slctChannel->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// take the channel selection from slctChannelForm
			if (!String::IsNullOrEmpty(slctChannel->ChnlViewName)) {
				
				this->sltChnlbtn1->Text = slctChannel->ChnlViewName;
				this->ModDir = slctChannel->ModDir;
				this->ChnlDir = slctChannel->ChnlDir;
				this->CrateLine = slctChannel->CrateLineDir;
				this->ChnlType = slctChannel->ChnlType;
				if ((this->Index >= 0) && (this->Index < this->M_pChnlsCnf->Count)) {
					if (m_pMainDataLists->GetChnlConnectedStatus(slctChannel->ChnlName)) {
						this->M_pChnlsCnf[this->Index]->NomVoltage = m_pMainDataLists->GetChnlNomVolt(slctChannel->ChnlName);
						this->M_pChnlsCnf[this->Index]->NomCurrent = m_pMainDataLists->GetChnlNomCrrnt(slctChannel->ChnlName);
						this->M_pChnlsCnf[this->Index]->VoltageSet = m_pMainDataLists->GetChnlVoltSet(slctChannel->ChnlName);
						this->M_pChnlsCnf[this->Index]->CurrentSet = m_pMainDataLists->GetChnlCrrntSet(slctChannel->ChnlName);
						this->M_pChnlsCnf[this->Index]->VoltageRise = m_pMainDataLists->GetChnlVoltRamp(slctChannel->ChnlName);
						this->M_pChnlsCnf[this->Index]->VoltageFall = m_pMainDataLists->GetChnlVoltRamp(slctChannel->ChnlName);
						this->M_pChnlsCnf[this->Index]->CurrentRise = m_pMainDataLists->GetChnlCrrntRamp(slctChannel->ChnlName);
						this->M_pChnlsCnf[this->Index]->CurrentFall = m_pMainDataLists->GetChnlCrrntRamp(slctChannel->ChnlName);
					}
					else {
						XML_Classes::Channel^ chnl = gcnew XML_Classes::Channel;
						this->M_pChnlsCnf[this->Index]->cpyData(chnl);
					}
					this->M_pChnlsCnf[this->Index]->ViewName = slctChannel->ChnlViewName;
					this->M_pChnlsCnf[this->Index]->ChannelName = slctChannel->ChnlName;
					this->M_pChnlsCnf[this->Index]->CrateLine = slctChannel->CrateLineDir;
					this->M_pChnlsCnf[this->Index]->CrateDir = slctChannel->CrateLineDir;
					this->M_pChnlsCnf[this->Index]->ModDir = slctChannel->ModDir;
					this->M_pChnlsCnf[this->Index]->ChnlDir = slctChannel->ChnlDir;
					this->M_pChnlsCnf[this->Index]->ChnlType = slctChannel->ChnlType;
					this->M_pChnlsCnf[this->Index]->Visible = true;
				}
				String^ chnl = gcnew String(slctChannel->ChnlName);
				m_ChnlsTaken->Add(chnl);
				slctChannel->Close();
			}
		}
	}
	
//
// Gets the color selected from a color dialog box
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->ChnlColor = colorDialog1->Color;
			this->BackColor= colorDialog1->Color;
			this->M_pChnlsCnf[this->Index]->ChnlColor = colorDialog1->Color;
			this->M_pChnlsCnf[this->Index]->Color = colorDialog1->Color.ToArgb().ToString();
		}
}
private: System::Void ClearClrSeltnBtn2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (m_ChnlsTaken->Contains(M_pChnlsCnf[this->Index]->ChannelName))
		m_ChnlsTaken->Remove(M_pChnlsCnf[this->Index]->ChannelName);
	XML_Classes::Channel^ chnl = gcnew XML_Classes::Channel;
	this->M_pChnlsCnf[this->Index]->cpyData(chnl);
	this->sltChnlbtn1->Text = chnl->ViewName;
	
}
};
}
