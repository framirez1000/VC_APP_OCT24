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
	/// Summary for ProgressDialog
	/// </summary>
	public ref class ProgressDialog : public System::Windows::Forms::Form
	{
	public:
		SingletonCmmdClass^ m_cmdMsg;
		ProgressDialog(void)
		{
			m_cmdMsg = SingletonCmmdClass::Instance;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ProgressDialog(System::Windows::Forms::Form^ sender)
		{
			m_cmdMsg = SingletonCmmdClass::Instance;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->Parent = (System::Windows::Forms::Form^) sender->ParentForm;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProgressDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn1_PrgssDlg;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label2;
	public:
	private: System::ComponentModel::IContainer^ components;
	private:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btn1_PrgssDlg = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn1_PrgssDlg
			// 
			this->btn1_PrgssDlg->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn1_PrgssDlg->Enabled = false;
			this->btn1_PrgssDlg->Location = System::Drawing::Point(95, 216);
			this->btn1_PrgssDlg->Name = L"btn1_PrgssDlg";
			this->btn1_PrgssDlg->Size = System::Drawing::Size(75, 23);
			this->btn1_PrgssDlg->TabIndex = 0;
			this->btn1_PrgssDlg->Text = L"Ok";
			this->btn1_PrgssDlg->UseVisualStyleBackColor = true;
			this->btn1_PrgssDlg->Click += gcnew System::EventHandler(this, &ProgressDialog::Button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(98, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Processing ......";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(48, 132);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(180, 15);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 2;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &ProgressDialog::Timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(174, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 1;
			// 
			// ProgressDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->CancelButton = this->btn1_PrgssDlg;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn1_PrgssDlg);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ProgressDialog";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ProgressDialog";
			this->Load += gcnew System::EventHandler(this, &ProgressDialog::ProgressDialog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void ProgressDialog_Load(System::Object^ sender, System::EventArgs^ e) {
		bool timeUp = false;
		int timeElapsed = 0;

		this->btn1_PrgssDlg->Visible = false;
		progressBar1->Value = 0;
		progressBar1->Value = m_cmdMsg->barProgressValue;
	}
	private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		static int timeElapsed = 0;
		static int timeToAutoClose = 0;
		static int lastProgressValue;
		
		//if (m_cmdMsg->barProgressValue >= 95) m_cmdMsg->barProgressValue = 0;
		
		if ((m_cmdMsg->cmdExecuted) || (timeElapsed >= 100) || (progressBar1->Value >= 100)) {
			this->btn1_PrgssDlg->Visible = true;
			this->btn1_PrgssDlg->Enabled = true;
		} 
		progressBar1->Value = m_cmdMsg->barProgressValue;
		if (progressBar1->Value > lastProgressValue) lastProgressValue = progressBar1->Value;
		else timeElapsed++;
		label2->Text = progressBar1->Value + "  %";
		//Check time elapsed to autoclose the progress bar in case the user skip it
		if ((timeElapsed - 100) >= (1000 / (this->timer1->Interval))*60*5)
			this->Button1_Click(sender, e);
}
};
}
