#pragma once
/* Classes definitions */
#include "ChnlSltnVForm.h"
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
	/// Summary for MyForm1
	/// </summary>
	public ref class SetSltnViewForm : public System::Windows::Forms::Form
	{
	public:
		int m_nrRows;
		int m_columns;
		CratesT^ m_mainDataStruct;
	property List<String^>^ ChnlsTaken;
	private: property List<XML_Classes::Channel^>^ M_ChnlsCnfView;
		
	private: System::Windows::Forms::Button^ btn_RmvSltn;
	private: System::Windows::Forms::Button^ btn_Cancel;
	private: System::Windows::Forms::Button^ btn_Ok;
	private: System::Windows::Forms::NumericUpDown^ nmrcUpDown_Columns;
	private: System::Windows::Forms::NumericUpDown^ nmrcUpDown_Rows;
	private: System::Windows::Forms::Label^ lbl_noColumns;
	private: System::Windows::Forms::Label^ lbl_noRows;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Panel^ panel1;
			 			 
	public:
		SetSltnViewForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		SetSltnViewForm(CratesT^ ptrMainDataStruct)
		{
			InitializeComponent();
			m_mainDataStruct = ptrMainDataStruct;
			M_ChnlsCnfView = gcnew List<XML_Classes::Channel^>;
			ChnlsTaken = gcnew List<String^>;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SetSltnViewForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->btn_RmvSltn = (gcnew System::Windows::Forms::Button());
			this->btn_Cancel = (gcnew System::Windows::Forms::Button());
			this->btn_Ok = (gcnew System::Windows::Forms::Button());
			this->nmrcUpDown_Columns = (gcnew System::Windows::Forms::NumericUpDown());
			this->nmrcUpDown_Rows = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbl_noColumns = (gcnew System::Windows::Forms::Label());
			this->lbl_noRows = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nmrcUpDown_Columns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nmrcUpDown_Rows))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_RmvSltn
			// 
			this->btn_RmvSltn->Location = System::Drawing::Point(497, 73);
			this->btn_RmvSltn->Name = L"btn_RmvSltn";
			this->btn_RmvSltn->Size = System::Drawing::Size(69, 25);
			this->btn_RmvSltn->TabIndex = 7;
			this->btn_RmvSltn->Text = L"Remove all";
			this->btn_RmvSltn->UseVisualStyleBackColor = true;
			this->btn_RmvSltn->Click += gcnew System::EventHandler(this, &SetSltnViewForm::Btn_RmvSltn_Click);
			// 
			// btn_Cancel
			// 
			this->btn_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_Cancel->Location = System::Drawing::Point(497, 42);
			this->btn_Cancel->Name = L"btn_Cancel";
			this->btn_Cancel->Size = System::Drawing::Size(69, 25);
			this->btn_Cancel->TabIndex = 8;
			this->btn_Cancel->Text = L"Cancel";
			this->btn_Cancel->UseVisualStyleBackColor = true;
			this->btn_Cancel->Click += gcnew System::EventHandler(this, &SetSltnViewForm::Btn_Cancel_Click);
			// 
			// btn_Ok
			// 
			this->btn_Ok->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btn_Ok->Location = System::Drawing::Point(497, 11);
			this->btn_Ok->Name = L"btn_Ok";
			this->btn_Ok->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->btn_Ok->Size = System::Drawing::Size(69, 25);
			this->btn_Ok->TabIndex = 9;
			this->btn_Ok->Text = L"Ok";
			this->btn_Ok->UseVisualStyleBackColor = true;
			this->btn_Ok->Click += gcnew System::EventHandler(this, &SetSltnViewForm::Btn_Ok_Click_1);
			// 
			// nmrcUpDown_Columns
			// 
			this->nmrcUpDown_Columns->Location = System::Drawing::Point(236, 55);
			this->nmrcUpDown_Columns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->nmrcUpDown_Columns->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nmrcUpDown_Columns->Name = L"nmrcUpDown_Columns";
			this->nmrcUpDown_Columns->Size = System::Drawing::Size(57, 20);
			this->nmrcUpDown_Columns->TabIndex = 5;
			this->nmrcUpDown_Columns->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->nmrcUpDown_Columns->ValueChanged += gcnew System::EventHandler(this, &SetSltnViewForm::NmrcUpDown_Columns_ValueChanged);
			// 
			// nmrcUpDown_Rows
			// 
			this->nmrcUpDown_Rows->Location = System::Drawing::Point(236, 25);
			this->nmrcUpDown_Rows->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->nmrcUpDown_Rows->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nmrcUpDown_Rows->Name = L"nmrcUpDown_Rows";
			this->nmrcUpDown_Rows->Size = System::Drawing::Size(57, 20);
			this->nmrcUpDown_Rows->TabIndex = 6;
			this->nmrcUpDown_Rows->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->nmrcUpDown_Rows->ValueChanged += gcnew System::EventHandler(this, &SetSltnViewForm::NmrcUpDown_Rows_ValueChanged_1);
			// 
			// lbl_noColumns
			// 
			this->lbl_noColumns->AutoSize = true;
			this->lbl_noColumns->Location = System::Drawing::Point(119, 69);
			this->lbl_noColumns->Name = L"lbl_noColumns";
			this->lbl_noColumns->Size = System::Drawing::Size(98, 13);
			this->lbl_noColumns->TabIndex = 3;
			this->lbl_noColumns->Text = L"Number of columns";
			// 
			// lbl_noRows
			// 
			this->lbl_noRows->AutoSize = true;
			this->lbl_noRows->Location = System::Drawing::Point(136, 34);
			this->lbl_noRows->Name = L"lbl_noRows";
			this->lbl_noRows->Size = System::Drawing::Size(81, 13);
			this->lbl_noRows->TabIndex = 4;
			this->lbl_noRows->Text = L"Number of rows";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->btn_RmvSltn);
			this->groupBox2->Controls->Add(this->btn_Cancel);
			this->groupBox2->Controls->Add(this->btn_Ok);
			this->groupBox2->Controls->Add(this->nmrcUpDown_Columns);
			this->groupBox2->Controls->Add(this->nmrcUpDown_Rows);
			this->groupBox2->Controls->Add(this->lbl_noColumns);
			this->groupBox2->Controls->Add(this->lbl_noRows);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox2->Location = System::Drawing::Point(0, 10);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->groupBox2->Size = System::Drawing::Size(634, 110);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Appearence";
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 120);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(634, 491);
			this->panel1->TabIndex = 15;
			// 
			// SetSltnViewForm
			// 
			this->AcceptButton = this->btn_Ok;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btn_Cancel;
			this->ClientSize = System::Drawing::Size(634, 611);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox2);
			this->IsMdiContainer = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SetSltnViewForm";
			this->Padding = System::Windows::Forms::Padding(0, 10, 0, 0);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Setup selection";
			this->Load += gcnew System::EventHandler(this, &SetSltnViewForm::SetSltnViewForm_Load_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nmrcUpDown_Columns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nmrcUpDown_Rows))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
public: System::Void drawSltnChnlView(int rows, int columns, System::Object^ Sender, System::EventArgs^ e);
//
// Load Form
private: System::Void SetSltnViewForm_Load_1(System::Object^ sender, System::EventArgs^ e) {
	ChnlSltnVForm^ pChnlViewItem;
	
	XML_Classes::Channel^ chnlCnfView;
	this->groupBox2->BringToFront();
	// Ini copy List
	for (int i = 0; i < m_mainDataStruct->pMainCnfView->Count; i++) {
		chnlCnfView = gcnew XML_Classes::Channel();
		chnlCnfView->cpyData(m_mainDataStruct->pMainCnfView[i]);
		M_ChnlsCnfView->Add(chnlCnfView);
		if (!String::IsNullOrEmpty(chnlCnfView->ChannelName)
			&& (chnlCnfView->ChannelName != CHANNEL_VIEW_DEFAULT_NAME)
			&& (chnlCnfView->ChannelName != "N/A")) {

			String^ chnl = gcnew String(chnlCnfView->ChannelName);
			ChnlsTaken->Add(chnl);
		}
	}
	this->m_nrRows = this->m_columns = 0; 
	if ((m_mainDataStruct->nbrRows > 0) || (m_mainDataStruct->nbrColumns > 0)) {
		this->m_nrRows = m_mainDataStruct->nbrRows;
		this->m_columns = m_mainDataStruct->nbrColumns;
	}
	drawSltnChnlView((int)this->m_nrRows, (int)this->m_columns, this, e);
}
//
// Ok button click event
private: System::Void Btn_Ok_Click_1(System::Object^ sender, System::EventArgs^ e) {
	m_mainDataStruct->pMainCnfView->Clear();
	XML_Classes::Channel^ chnlCnfItem;
	for (int i = 0; i < M_ChnlsCnfView->Count; i++) {
		chnlCnfItem = gcnew XML_Classes::Channel();
		chnlCnfItem->cpyData(M_ChnlsCnfView[i]);
		// Copy all memeber values ......
		m_mainDataStruct->pMainCnfView->Add(chnlCnfItem);
	}
	M_ChnlsCnfView->Clear();
	m_mainDataStruct->nbrRows = this->m_nrRows = (int)this->nmrcUpDown_Rows->Value;
	m_mainDataStruct->nbrColumns = this->m_columns = (int)this->nmrcUpDown_Columns->Value;
	return;
}
private: System::Void Btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
	M_ChnlsCnfView->Clear();
}
private: System::Void Btn_RmvSltn_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void NmrcUpDown_Columns_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	drawSltnChnlView((int)this->nmrcUpDown_Rows->Value, (int)this->nmrcUpDown_Columns->Value, this, e);
}
private: System::Void NmrcUpDown_Rows_ValueChanged_1(System::Object^ sender, System::EventArgs^ e) {
	drawSltnChnlView((int)this->nmrcUpDown_Rows->Value, (int)this->nmrcUpDown_Columns->Value, this, e);
}
};
}
