#pragma once
#include "GlobalsHeader.h"


namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: SingletonCmmdClass^ m_cmdMsg;
	private: System::Windows::Forms::ColumnHeader^ Modules;
	public:
	private: System::Windows::Forms::ColumnHeader^ Channels;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_cmdMsg = SingletonCmmdClass::Instance;
		}
		MyForm(CheckedList^ pHrwList)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_cmdMsg = SingletonCmmdClass::Instance;
			pMainHrwList = pHrwList;
		}
	property CheckedList^ pMainHrwList;
	protected:
		/// <summary>
		/// Clean up any resources being used.    
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	
	private: System::Windows::Forms::Button^ btnOK;
	protected:

	protected:
	private: System::Windows::Forms::Button^ btnCancel;
	public: System::Windows::Forms::Label^ testLabel;
	public: System::Windows::Forms::ListView^ listView1;
	public: System::Windows::Forms::Panel^ panel1;

	public: System::Windows::Forms::Button^ addCrate;

	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	public:
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::TextBox^ txtBx1_AddCrate;

	public: System::Windows::Forms::Label^ label1;
	private:
	public: System::Windows::Forms::Button^ removeCratebutton1;
	private: System::Windows::Forms::ComboBox^ cmbBx1_CrateBrand;
	public: System::Windows::Forms::Label^ label2;
	private:
	private: System::Windows::Forms::ComboBox^ cmbBx2_Protocol;
	public:
	public: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ProgressBar^ prgrsBr1_AddCrate;
	
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->testLabel = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->Modules = (gcnew System::Windows::Forms::ColumnHeader());
			this->Channels = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->prgrsBr1_AddCrate = (gcnew System::Windows::Forms::ProgressBar());
			this->addCrate = (gcnew System::Windows::Forms::Button());
			this->txtBx1_AddCrate = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->removeCratebutton1 = (gcnew System::Windows::Forms::Button());
			this->cmbBx1_CrateBrand = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cmbBx2_Protocol = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnOK
			// 
			this->btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOK->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnOK->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnOK.Image")));
			this->btnOK->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnOK->Location = System::Drawing::Point(175, 387);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(108, 24);
			this->btnOK->TabIndex = 0;
			this->btnOK->Text = L"  Ok";
			this->btnOK->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &MyForm::BtnOK_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnCancel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCancel.Image")));
			this->btnCancel->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnCancel->Location = System::Drawing::Point(297, 387);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(108, 24);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"  Cancel";
			this->btnCancel->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &MyForm::BtnCancel_Click);
			// 
			// testLabel
			// 
			this->testLabel->AutoSize = true;
			this->testLabel->Location = System::Drawing::Point(78, 23);
			this->testLabel->Name = L"testLabel";
			this->testLabel->Size = System::Drawing::Size(154, 15);
			this->testLabel->TabIndex = 2;
			this->testLabel->Text = L"Add / remove crate from list";
			this->testLabel->Click += gcnew System::EventHandler(this, &MyForm::TestLabel_Click);
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->columnHeader1, this->Modules,
					this->Channels, this->columnHeader2
			});
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->ForeColor = System::Drawing::SystemColors::Window;
			this->listView1->Location = System::Drawing::Point(33, 12);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(306, 161);
			this->listView1->TabIndex = 3;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Crate Serial Number";
			this->columnHeader1->Width = 127;
			// 
			// Modules
			// 
			this->Modules->Text = L"Modules";
			this->Modules->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Modules->Width = 59;
			// 
			// Channels
			// 
			this->Channels->Text = L"Channels";
			this->Channels->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Channels->Width = 58;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Status";
			this->columnHeader2->Width = 63;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->prgrsBr1_AddCrate);
			this->panel1->Controls->Add(this->listView1);
			this->panel1->Location = System::Drawing::Point(28, 55);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(376, 187);
			this->panel1->TabIndex = 4;
			// 
			// prgrsBr1_AddCrate
			// 
			this->prgrsBr1_AddCrate->Location = System::Drawing::Point(133, 108);
			this->prgrsBr1_AddCrate->Name = L"prgrsBr1_AddCrate";
			this->prgrsBr1_AddCrate->Size = System::Drawing::Size(100, 17);
			this->prgrsBr1_AddCrate->TabIndex = 9;
			this->prgrsBr1_AddCrate->Visible = false;
			// 
			// addCrate
			// 
			this->addCrate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addCrate->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->addCrate->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addCrate.Image")));
			this->addCrate->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->addCrate->Location = System::Drawing::Point(71, 337);
			this->addCrate->Name = L"addCrate";
			this->addCrate->Size = System::Drawing::Size(284, 24);
			this->addCrate->TabIndex = 6;
			this->addCrate->Text = L"  Add crate";
			this->addCrate->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->addCrate->UseVisualStyleBackColor = true;
			this->addCrate->Click += gcnew System::EventHandler(this, &MyForm::AddItem_Click);
			// 
			// txtBx1_AddCrate
			// 
			this->txtBx1_AddCrate->Location = System::Drawing::Point(71, 314);
			this->txtBx1_AddCrate->Name = L"txtBx1_AddCrate";
			this->txtBx1_AddCrate->Size = System::Drawing::Size(131, 21);
			this->txtBx1_AddCrate->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(72, 297);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Crate SERIAL number";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::TestLabel_Click);
			// 
			// removeCratebutton1
			// 
			this->removeCratebutton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->removeCratebutton1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->removeCratebutton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"removeCratebutton1.Image")));
			this->removeCratebutton1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->removeCratebutton1->Location = System::Drawing::Point(75, 255);
			this->removeCratebutton1->Name = L"removeCratebutton1";
			this->removeCratebutton1->Size = System::Drawing::Size(280, 24);
			this->removeCratebutton1->TabIndex = 6;
			this->removeCratebutton1->Text = L"  Remove crate";
			this->removeCratebutton1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->removeCratebutton1->UseVisualStyleBackColor = true;
			this->removeCratebutton1->Click += gcnew System::EventHandler(this, &MyForm::RemoveCratebutton1_Click);
			// 
			// cmbBx1_CrateBrand
			// 
			this->cmbBx1_CrateBrand->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cmbBx1_CrateBrand->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->cmbBx1_CrateBrand->FormattingEnabled = true;
			this->cmbBx1_CrateBrand->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"ISEG" });
			this->cmbBx1_CrateBrand->Location = System::Drawing::Point(205, 314);
			this->cmbBx1_CrateBrand->Name = L"cmbBx1_CrateBrand";
			this->cmbBx1_CrateBrand->Size = System::Drawing::Size(84, 21);
			this->cmbBx1_CrateBrand->TabIndex = 8;
			this->cmbBx1_CrateBrand->Text = L"ISEG";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(205, 297);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Crate brand";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::TestLabel_Click);
			// 
			// cmbBx2_Protocol
			// 
			this->cmbBx2_Protocol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbBx2_Protocol->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->cmbBx2_Protocol->FormattingEnabled = true;
			this->cmbBx2_Protocol->Location = System::Drawing::Point(292, 314);
			this->cmbBx2_Protocol->Name = L"cmbBx2_Protocol";
			this->cmbBx2_Protocol->Size = System::Drawing::Size(62, 21);
			this->cmbBx2_Protocol->TabIndex = 8;
			this->cmbBx2_Protocol->Text = L"EPICS_CA";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(294, 297);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Protocol";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::TestLabel_Click);
			// 
			// MyForm
			// 
			this->AcceptButton = this->btnOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(437, 422);
			this->Controls->Add(this->cmbBx2_Protocol);
			this->Controls->Add(this->cmbBx1_CrateBrand);
			this->Controls->Add(this->txtBx1_AddCrate);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->testLabel);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->removeCratebutton1);
			this->Controls->Add(this->addCrate);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Crate list";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void BtnOK_Click(System::Object^ sender, System::EventArgs^ e) {
		//this->Close();
}
//
// Add crate: check for hardware existance, if found it's added to Hardware List
// not connection is made if found
private: System::Void AddItem_Click(System::Object^ sender, System::EventArgs^ e) {
	bool timeUp;
	
	if (this->txtBx1_AddCrate->Text != "") {
		// Get the crate brand from the combo box (for EPICS IOC cmds)
		Object^ selectedItem;
		selectedItem = this->cmbBx1_CrateBrand->SelectedItem;
		// Check if the crate is already in list
		//ListViewItem^ m_listViewCrateItem = gcnew ListViewItem(selectedItem->ToString() + ":" + this->txtBx1_AddCrate->Text);
		String^ crateToAdd = selectedItem->ToString() + ":" + this->txtBx1_AddCrate->Text;
		int pos=-1;
		for each (ListViewItem ^ elem in listView1->Items) {
			if (elem->Text == crateToAdd) {
				pos = listView1->Items->IndexOf(elem);
			}
		}
		if (pos >= 0) { 
			// if crate already exist => msg & return
			MessageBox::Show("Crate already in list position: " + pos);
			return;
		}
		prgrsBr1_AddCrate->Visible = true;
		prgrsBr1_AddCrate->Value = 10;
		// Fill SingComm structure
		if (!m_cmdMsg->execRequest) {
			m_cmdMsg->GlobalAddSendCmds(crateToAdd, "", CRATE_CMD, 0, true);
			/*m_cmdMsg->strCmdsToExcList->Add(crateToAdd);
			m_cmdMsg->cmdType = 0;
			m_cmdMsg->cmdExecuted = false;
			m_cmdMsg->execRequest = true;
			prgrsBr1_AddCrate->Value = 0;*/
			timeUp = false;
			int i = 0;
			while (!m_cmdMsg->cmdExecuted && i++ < 50) {
				System::Threading::Thread::Sleep(100);
				prgrsBr1_AddCrate->Value = m_cmdMsg->barProgressValue;
			}
			prgrsBr1_AddCrate->Visible = false;
			if ((m_cmdMsg->cmdExecuted) && (m_cmdMsg->cmdResult)) {
				ListViewItem^ m_listViewCrateItem = gcnew ListViewItem;
				m_listViewCrateItem->Text=(selectedItem->ToString() + ":" + this->txtBx1_AddCrate->Text);
				m_listViewCrateItem->SubItems->Add("-");
				m_listViewCrateItem->SubItems->Add("-");
				m_listViewCrateItem->SubItems->Add("Not connected");
				this->listView1->Items->Add(m_listViewCrateItem);
				MessageBox::Show("Crate " + this->txtBx1_AddCrate->Text + " added ...");
				//this->m_childCrateAddedList->Add(m_listViewCrateItem->Text);
				m_cmdMsg->execRequest = false;
				m_cmdMsg->StatusBarMsgIndex = 15;
				//m_cmdMsg->statusBarMsg = "Crate  added";
			}
			else
			{
				m_cmdMsg->execRequest = false;
				MessageBox::Show("Crate not found or comm timeOut, try again now or later ...");
			}
		}
		else { 
			prgrsBr1_AddCrate->Step = 100;
			MessageBox::Show("Busy processing cmd, try later ...");
		}
		this->txtBx1_AddCrate->Text="";
	}
	
	
}
//
// Delete crate from Hardware List (this is done if crate hardware has not connected status
private: System::Void RemoveCratebutton1_Click(System::Object^ sender, System::EventArgs^ e) {
	// 
	if (listView1->SelectedItems->Count > 0)
	{
		MessageBox::Show(listView1->SelectedItems[0]->SubItems[0]->Text + "  " + listView1->SelectedItems[0]->SubItems[1]->Text);
		if (listView1->SelectedItems[0]->SubItems[3]->Text == "Not connected") {
			// Search for crate in HardwareList an delete it
			// Deleted this crate from local View List if deleted from Hardware List
			String^ crateToDelete = gcnew String (listView1->SelectedItems[0]->Text);
			CheckedList::const_iterator it = pMainHrwList->find(crateToDelete);
			CheckedList::const_reference cref = *it;
			if (cref != nullptr) {
				pMainHrwList->erase(crateToDelete);
				//foundItem = listView1->Items->Find(gcnew Predicate<ListView^>(searchItem, &EntityPredicate::ListViewMatched));
				listView1->SelectedItems[0]->Remove();
			}
			//this->m_childCrateDeletedList->Add(listView1->SelectedItems[0]->Text);
		}
		else {
			MessageBox::Show("Cannot delete connected hardware ...");
		}
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TestLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
		 
/* Properties */
 

private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
};
}
