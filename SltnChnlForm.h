#pragma once
#include "SlctChnlClass.h"
#include "Crate.h"
#include "MainHeader.h"

namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	

	/// <summary>
	/// Summary for SltnChnlForm
	/// </summary>
	public ref class SltnChnlForm : public System::Windows::Forms::Form
	{
	public:
		property String^ ChnlName;
		property String^ ChnlViewName;
		property int CrateLineDir;
		property int ModDir;
		property int ChnlDir;
		property List<String^>^ m_ChnlsTaken;
		property int ChnlType;
	private:
		CratesT^ m_pCratesList;
		Crate^ m_ptrCrate;
	public:
		SltnChnlForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		SltnChnlForm(CratesT^ ptrMainDataStruct, List<String^>^ chnlsTaken)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_pCratesList = ptrMainDataStruct;
			m_ChnlsTaken = chnlsTaken;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SltnChnlForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ btn1_SlctChnlOk;
	private: System::Windows::Forms::Button^ btn2_SlctChnlCancel;

	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabMathPage1;
	private: System::Windows::Forms::Panel^ panel1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	/* Properties */
	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn1_SlctChnlOk = (gcnew System::Windows::Forms::Button());
			this->btn2_SlctChnlCancel = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabMathPage1 = (gcnew System::Windows::Forms::TabPage());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tabControl1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn1_SlctChnlOk
			// 
			this->btn1_SlctChnlOk->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btn1_SlctChnlOk->Location = System::Drawing::Point(384, 515);
			this->btn1_SlctChnlOk->Name = L"btn1_SlctChnlOk";
			this->btn1_SlctChnlOk->Size = System::Drawing::Size(75, 23);
			this->btn1_SlctChnlOk->TabIndex = 1;
			this->btn1_SlctChnlOk->Text = L"Ok";
			this->btn1_SlctChnlOk->UseVisualStyleBackColor = true;
			this->btn1_SlctChnlOk->Click += gcnew System::EventHandler(this, &SltnChnlForm::Btn1_SlctChnlOk_Click);
			// 
			// btn2_SlctChnlCancel
			// 
			this->btn2_SlctChnlCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn2_SlctChnlCancel->Location = System::Drawing::Point(505, 515);
			this->btn2_SlctChnlCancel->Name = L"btn2_SlctChnlCancel";
			this->btn2_SlctChnlCancel->Size = System::Drawing::Size(75, 23);
			this->btn2_SlctChnlCancel->TabIndex = 2;
			this->btn2_SlctChnlCancel->Text = L"Cancel";
			this->btn2_SlctChnlCancel->UseVisualStyleBackColor = true;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabMathPage1);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(613, 503);
			this->tabControl1->TabIndex = 4;
			// 
			// tabMathPage1
			// 
			this->tabMathPage1->AutoScroll = true;
			this->tabMathPage1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->tabMathPage1->Location = System::Drawing::Point(4, 22);
			this->tabMathPage1->Name = L"tabMathPage1";
			this->tabMathPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabMathPage1->Size = System::Drawing::Size(605, 477);
			this->tabMathPage1->TabIndex = 0;
			this->tabMathPage1->Text = L"VChnl";
			this->tabMathPage1->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->btn2_SlctChnlCancel);
			this->panel1->Controls->Add(this->tabControl1);
			this->panel1->Controls->Add(this->btn1_SlctChnlOk);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(617, 552);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SltnChnlForm::Panel1_Paint);
			// 
			// SltnChnlForm
			// 
			this->AcceptButton = this->btn1_SlctChnlOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->CancelButton = this->btn2_SlctChnlCancel;
			this->ClientSize = System::Drawing::Size(617, 552);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"SltnChnlForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Select channel";
			this->Load += gcnew System::EventHandler(this, &SltnChnlForm::SltnChnlForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
//
//
private: System::Void Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		SlctChnlClass^ pSlctChnlObjet;
		pSlctChnlObjet = gcnew SlctChnlClass();

		pSlctChnlObjet->lbl_ModChnl->Text = "Test";
		pSlctChnlObjet->lbl_ModChnl->AutoSize = true;
		pSlctChnlObjet->lbl_ModChnl->Location = System::Drawing::Point(5, 220);
		pSlctChnlObjet->lbl_ModChnl->Name = L"label11";
		pSlctChnlObjet->lbl_ModChnl->Size = System::Drawing::Size(70, 30);
		pSlctChnlObjet->lbl_ModChnl->TabIndex = 0;
		pSlctChnlObjet->lbl_ModChnl->Text = L"Mod 1 Chnl 0";
		pSlctChnlObjet->lbl_ModChnl->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		pSlctChnlObjet->lbl_ModChnl->BringToFront();
		pSlctChnlObjet->lbl_ModChnl->Visible = true;
		pSlctChnlObjet->lbl_ModChnl->Enabled = true;
		this->panel1->Controls->Add(pSlctChnlObjet->lbl_ModChnl);
		this->panel1->SendToBack();

		System::Windows::Forms::Label^ lbl_ModChnl11;
		System::Windows::Forms::RadioButton^ slctRadioButton11;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel11;

		lbl_ModChnl11 = (gcnew System::Windows::Forms::Label());
		slctRadioButton11 = (gcnew System::Windows::Forms::RadioButton());
		tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());

		lbl_ModChnl11->Text = "Test";
		lbl_ModChnl11->AutoSize = true;
		lbl_ModChnl11->Location = System::Drawing::Point(5, 240);
		lbl_ModChnl11->Name = L"label11";
		lbl_ModChnl11->Size = System::Drawing::Size(70, 30);
		lbl_ModChnl11->TabIndex = 0;
		lbl_ModChnl11->Text = L"Mod 111 Chnl 000";
		lbl_ModChnl11->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		lbl_ModChnl11->BringToFront();
		lbl_ModChnl11->Visible = true;
		lbl_ModChnl11->Enabled = true;
		this->panel1->Controls->Add(lbl_ModChnl11);
		
	}

//
// Load the TABS and radio buttons for each voltage channel contained in Crate/Mod/ChnlList
// Chnl in selectable according to enable status from load Crate/Mod/ChnlList proceudre
private: System::Void SltnChnlForm_Load(System::Object^ sender, System::EventArgs^ e) {
	
	cli::array<Windows::Forms::RadioButton^,1>^ radioButtonsChnls = gcnew cli::array<Windows::Forms::RadioButton^>(32);
	cli::array<Windows::Forms::TableLayoutPanel^, 1> ^ lyoutPanelsChnls = gcnew cli::array<Windows::Forms::TableLayoutPanel^>(32);
	int posX = 19, posY = 20, panelSizeW = 125, panelSizeH = 40;
	for (int i = 0; i < 32; i++) {
		// Plot Virtual channels
		lyoutPanelsChnls[i] = gcnew Windows::Forms::TableLayoutPanel;
		lyoutPanelsChnls[i]->ColumnCount = 1;
		lyoutPanelsChnls[i]->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
		
		lyoutPanelsChnls[i]->Location = System::Drawing::Point(posX, posY);
		lyoutPanelsChnls[i]->Name = L"tableLayoutPanel" + i;
		lyoutPanelsChnls[i]->RowCount = 1;
		lyoutPanelsChnls[i]->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		lyoutPanelsChnls[i]->Size = System::Drawing::Size(panelSizeW, panelSizeH);
		lyoutPanelsChnls[i]->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
		this->tabMathPage1->Controls->Add(lyoutPanelsChnls[i]);
		lyoutPanelsChnls[i]->Show();
		
		radioButtonsChnls[i] = gcnew Windows::Forms::RadioButton;
		radioButtonsChnls[i]->Name = this->tabMathPage1->Text + ":" + this->tabMathPage1->Text 
									+ ":0:0:" + i;
		radioButtonsChnls[i]->Text = "Mod 0 Chnl " + i;
		radioButtonsChnls[i]->Size= System::Drawing::Size(95, 20);
		radioButtonsChnls[i] ->Location= System::Drawing::Point(posX+5, posY+panelSizeH/2-7);
		radioButtonsChnls[i]->CheckedChanged += gcnew System::EventHandler(this, &SltnChnlForm::OnCheckedChanged);
		this->tabMathPage1->Controls->Add(radioButtonsChnls[i]);
		this->tabMathPage1->AutoScroll= true;
		radioButtonsChnls[i]->BringToFront();
		radioButtonsChnls[i]->BackColor = System::Drawing::Color::Transparent;
		if (m_ChnlsTaken->Contains(radioButtonsChnls[i]->Name)) {
			radioButtonsChnls[i]->Enabled = false;
		}
		radioButtonsChnls[i]->Show();
		posY += panelSizeH;
	}
	// Iterate main Crate list to create crateTabs and show available channels to select
	TabPage^ pgeChnls;
	int nroCrates = 0;
	for each (Crate ^ crate in m_pCratesList->ptrMainCrateList) {
		m_ptrCrate = crate;
		posX = 19;  panelSizeW = 105; panelSizeH = 40;
		pgeChnls = gcnew TabPage;
		
		pgeChnls->ForeColor = System::Drawing::SystemColors::ActiveCaption;
		pgeChnls->Location = System::Drawing::Point(4, 22);
		pgeChnls->Name = crate->Name;
		pgeChnls->Text = crate->Name;
		pgeChnls->Padding = System::Windows::Forms::Padding(3);
		pgeChnls->Size = System::Drawing::Size(605, 477);
		pgeChnls->TabIndex = ++nroCrates;
		pgeChnls->UseVisualStyleBackColor = true;

		this->tabControl1->Controls->Add(pgeChnls);
		pgeChnls->AutoScroll = true;int i = 0;
		// Add selection view for available channels from availible modules/channels objects
		for each (Module ^ mod in crate->m_lstModules) {
			Windows::Forms::RadioButton ^ rdBtn;
			Windows::Forms::TableLayoutPanel^ chnlFrame;
			posY = 20;
			cli::array<Windows::Forms::RadioButton^, 1> ^ rdBtnsChnls = gcnew cli::array<Windows::Forms::RadioButton^>(mod->lstChannels->Count);
			int j = 0;
			for each (Channel ^ chnl in mod->lstChannels) {
				chnlFrame= gcnew Windows::Forms::TableLayoutPanel;
				chnlFrame->ColumnCount = 1;
				chnlFrame->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
				chnlFrame->Location = System::Drawing::Point(posX + panelSizeW*i, posY);
				chnlFrame->Name = L"tableLayoutPanel" + i;
				chnlFrame->RowCount = 1;
				chnlFrame->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				chnlFrame->Size = System::Drawing::Size(panelSizeW, panelSizeH);
				chnlFrame->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
				pgeChnls->Controls->Add(chnlFrame);
				chnlFrame->Show();

				rdBtnsChnls[j] = gcnew Windows::Forms::RadioButton;
				rdBtnsChnls[j]->Name = crate->Name + ":" + crate->Address + ":" + mod->Address + ":" + chnl->Address;
				rdBtnsChnls[j]->Text = " Mod " + mod->Address + " Chnl " + chnl->Address;
				rdBtnsChnls[j]->Size = System::Drawing::Size(95, 20);
				rdBtnsChnls[j]->Location= System::Drawing::Point( posX + 5 + (panelSizeW )*i, posY + panelSizeH / 2 - 7);
				pgeChnls->Controls->Add(rdBtnsChnls[j]);
				rdBtnsChnls[j]->BringToFront();
				rdBtnsChnls[j]->BackColor = System::Drawing::Color::Transparent;
				rdBtnsChnls[j]->Enabled = chnl->Enable;
				if (m_ChnlsTaken->Contains(chnl->Name)) {
					rdBtnsChnls[j]->Enabled = false;
				}
				rdBtnsChnls[j]->CheckedChanged += gcnew System::EventHandler(this, &SltnChnlForm::OnCheckedChanged);
				rdBtnsChnls[j]->Show();
				posY += panelSizeH;
				j++;
			}
			i++;
		}
	}

}

//
// Gets the channel selected from a radio button checked state
private: void OnCheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			//throw gcnew System::NotImplementedException();
			RadioButton^ rb = (RadioButton^)sender;
			
			if (rb->Checked == true) {
				String^ str= rb->Name;			// Has the format i.e. ISEG:$serialNumber$ + $crateLine$ + $ModDir$ + $ChnlDir$
				ChnlViewName = str;
				ChnlName = str;
				ChnlType = 1;                   // 0: Virtual, 1: Normal/Physical
				System::Array^ strArray = str->Split(':');
				if (str->Contains("VChnl")) {  // Channel is a Virtual Channel
					//ChnlViewName = "VChnl " + strArray->GetValue(4);
					//ChnlName = "VChnl " + strArray->GetValue(4);
					this->ChnlType = 0;
				}
				CrateLineDir = System::Convert::ToInt16(strArray->GetValue(2)); // Crate Line
				ModDir = System::Convert::ToInt16(strArray->GetValue(3));		// Mod Dir
				ChnlDir = System::Convert::ToInt16(strArray->GetValue(4));		// Chnl dir
				//int pos = str->IndexOf(" ");
				//ChnlName = str->Substring(0, pos);
				//str = str->Substring(pos + 1);  // Trim crate name
				//pos = str->IndexOf(" ");
				//str = str->Substring(pos + 1);  // Trim "Line" word
				//pos = str->IndexOf(" ");
				//CrateLineDir = System::Convert::ToInt16(str->Substring(0, pos));
				//pos = str->IndexOf(" ");
				//str = str->Substring(pos + 1);  // Trim "Line" nmbr
				//pos = str->IndexOf(" ");
				//str = str->Substring(pos + 1);  // Trim "Mod" word
				//pos = str->IndexOf(" ");
				//ModDir = System::Convert::ToInt16( str->Substring(0, pos));
				//str = str->Substring(pos + 1);  // Trim "Mod" nbr
				//pos = str->IndexOf(" ");
				//str = str->Substring(pos + 1);  // Trim "Chnl" word
				//ChnlDir = System::Convert::ToInt16(str);
				//
				MessageBox::Show(rb->Name + "\r\nCrateName:" + CrateLineDir + ChnlName + "\r\nChnl Type: " + System::Convert::ToInt16(this->ChnlType) + "\r\n Mod Dir: " + ModDir + "\r\nChnl Dir: " + ChnlDir);
			}
			
		}

//
// Back to caller
private: System::Void Btn1_SlctChnlOk_Click(System::Object^ sender, System::EventArgs^ e) {
	return;
}
};
}
