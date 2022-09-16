#pragma once
#include "GlobalsHeader.h"

namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for LogSltnForm
	/// </summary>
	public ref class LogSltnForm : public System::Windows::Forms::Form
	{
	public:
		FileData m_DataFile;
		property String^ m_FileRecordingName;
		property int m_RecordingTime;
	public:
		LogSltnForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_FileRecordingName = gcnew String("");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogSltnForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;


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
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(25, 40);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(232, 214);
			this->checkedListBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Select channels to log";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(36, 273);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Check all";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LogSltnForm::Button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(151, 273);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Uncheck all";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LogSltnForm::Button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(287, 34);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(278, 71);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Log parameter";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Logging interval (sec)";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(7, 34);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3600, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(137, 20);
			this->numericUpDown1->TabIndex = 0;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(287, 130);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(278, 124);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Log file selection";
			// 
			// button3
			// 
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(7, 90);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(264, 24);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Select LOG file";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &LogSltnForm::Button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(7, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(264, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Log file name";
			// 
			// button4
			// 
			this->button4->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button4->Location = System::Drawing::Point(294, 273);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(115, 23);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Ok";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &LogSltnForm::Button4_Click);
			// 
			// button5
			// 
			this->button5->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button5->Location = System::Drawing::Point(443, 273);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(115, 23);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Cancel";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// LogSltnForm
			// 
			this->AcceptButton = this->button4;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->CancelButton = this->button5;
			this->ClientSize = System::Drawing::Size(577, 308);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkedListBox1);
			this->Name = L"LogSltnForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"LogSltnForm";
			this->Load += gcnew System::EventHandler(this, &LogSltnForm::LogSltnForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (textBox1->Text != "")
			m_DataFile.fileName = textBox1->Text; // DEFAULT_DATA_FILE_PATH + textBox1->Text;
		//m_DataFile.fileName = "C:\\ProgramData\\VoltageControllerNew\\LOG" + textBox1->Text;
		else if (String::IsNullOrEmpty(m_DataFile.fileName)) {
			m_DataFile.fileName = DEFAULT_DATA_FILE_NAME;
		}
		Console::WriteLine("Data file set... Ok");
		m_DataFile.savingInterval = safe_cast<int> (numericUpDown1->Value);
		return;
	}
private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ myStream;
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

	Console::WriteLine("File selection dialog created");
	saveFileDialog1->InitialDirectory = DEFAULT_DATA_FILE_PATH; 
	saveFileDialog1->Filter = "txt files (*.txt)|*.txt|csv files (*.csv)|*.csv";
	saveFileDialog1->FilterIndex = 2;
	saveFileDialog1->RestoreDirectory = false;
	saveFileDialog1->AutoUpgradeEnabled = true;
	saveFileDialog1->FileName = textBox1->Text;
	
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
		{
			// Insert code to read the stream here.
			saveFileDialog1->CheckPathExists = true;
			m_DataFile.path = Path::GetDirectoryName(saveFileDialog1->FileName) + "\\";
			m_DataFile.fileName = Path::GetFileName(saveFileDialog1->FileName);
			textBox1->Text = m_DataFile.fileName;
			myStream->Close();
		}
		else {
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::WriteLine("No new file especified... in file explorer window");
		}
		Console::WriteLine("Return from File selection dialog created");
	}
}
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Select all channels to record their data
	for (int i = 0; i < this->checkedListBox1->Items->Count; i++)
		this->checkedListBox1->SetItemChecked(i, true);
}
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// UnSelect all channels to not record their data
	//this->checkedListBox1->ClearSelected();
	for (int i = 0; i < this->checkedListBox1->Items->Count; i++)
		this->checkedListBox1->SetItemChecked(i, false);
}
private: System::Void LogSltnForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->numericUpDown1->Value = m_RecordingTime;
	this->m_DataFile.path = DEFAULT_DATA_FILE_PATH;
	textBox1->Text = m_DataFile.fileName;
}
};
}
