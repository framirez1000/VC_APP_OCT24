#pragma once

namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GlobalSettingsForm
	/// </summary>
	public ref class GlobalSettingsForm : public System::Windows::Forms::Form
	{
	public:
		GlobalSettingsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			PercentageDefaultValue = "1.0000";
			AdditionalVoltError = "1.000";
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GlobalSettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		property String^ PercentageDefaultValue;
		property String^ AdditionalVoltError;
	public:
		property Double NewPercentage;
		property Double NewAdditionalVoltError;
		property int m_RecordingTime;
		property String^ PathName;
		property bool m_SwitchAllCnlsOffAtStart;
		property bool m_SwitchAllCnlsOffAtEnd;

	private: System::Windows::Forms::GroupBox^ grpBx1_PowerSettings;
	protected:
	private: System::Windows::Forms::CheckBox^ chckBox4_ChnlsOFFload;
	private: System::Windows::Forms::CheckBox^ chckBx3_ChnlsOFFend;
	private: System::Windows::Forms::CheckBox^ chckBx2_ChnlsOFF;
	private: System::Windows::Forms::CheckBox^ chckBx1MainSwitch;
	private: System::Windows::Forms::GroupBox^ grpBx2_Out_Settings;
	private: System::Windows::Forms::Label^ lbl4_Crr_FR;
	private: System::Windows::Forms::Label^ lbl3_Crr_RR;
	private: System::Windows::Forms::Label^ lbl2_Vlt_FR;
	private: System::Windows::Forms::Label^ lbl1_Vlt_RR;
	private: System::Windows::Forms::TextBox^ txtBx4_Crr_FR;
	private: System::Windows::Forms::TextBox^ txtBx3_Crr_RR;
	private: System::Windows::Forms::TextBox^ txtBx2_Vlt_FR;
	private: System::Windows::Forms::TextBox^ txtBx1_VltRire;
	private: System::Windows::Forms::GroupBox^ grpBx3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ btn1_SlctDir;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::Button^ btn2_Ok;
	private: System::Windows::Forms::Button^ btn3_Cancel;

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
			this->grpBx1_PowerSettings = (gcnew System::Windows::Forms::GroupBox());
			this->chckBox4_ChnlsOFFload = (gcnew System::Windows::Forms::CheckBox());
			this->chckBx3_ChnlsOFFend = (gcnew System::Windows::Forms::CheckBox());
			this->chckBx2_ChnlsOFF = (gcnew System::Windows::Forms::CheckBox());
			this->chckBx1MainSwitch = (gcnew System::Windows::Forms::CheckBox());
			this->grpBx2_Out_Settings = (gcnew System::Windows::Forms::GroupBox());
			this->lbl4_Crr_FR = (gcnew System::Windows::Forms::Label());
			this->lbl3_Crr_RR = (gcnew System::Windows::Forms::Label());
			this->lbl2_Vlt_FR = (gcnew System::Windows::Forms::Label());
			this->lbl1_Vlt_RR = (gcnew System::Windows::Forms::Label());
			this->txtBx4_Crr_FR = (gcnew System::Windows::Forms::TextBox());
			this->txtBx3_Crr_RR = (gcnew System::Windows::Forms::TextBox());
			this->txtBx2_Vlt_FR = (gcnew System::Windows::Forms::TextBox());
			this->txtBx1_VltRire = (gcnew System::Windows::Forms::TextBox());
			this->grpBx3 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->btn1_SlctDir = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->btn2_Ok = (gcnew System::Windows::Forms::Button());
			this->btn3_Cancel = (gcnew System::Windows::Forms::Button());
			this->grpBx1_PowerSettings->SuspendLayout();
			this->grpBx2_Out_Settings->SuspendLayout();
			this->grpBx3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpBx1_PowerSettings
			// 
			this->grpBx1_PowerSettings->BackColor = System::Drawing::Color::Black;
			this->grpBx1_PowerSettings->Controls->Add(this->chckBox4_ChnlsOFFload);
			this->grpBx1_PowerSettings->Controls->Add(this->chckBx3_ChnlsOFFend);
			this->grpBx1_PowerSettings->Controls->Add(this->chckBx2_ChnlsOFF);
			this->grpBx1_PowerSettings->Controls->Add(this->chckBx1MainSwitch);
			this->grpBx1_PowerSettings->ForeColor = System::Drawing::Color::White;
			this->grpBx1_PowerSettings->Location = System::Drawing::Point(12, 12);
			this->grpBx1_PowerSettings->Name = L"grpBx1_PowerSettings";
			this->grpBx1_PowerSettings->Size = System::Drawing::Size(258, 136);
			this->grpBx1_PowerSettings->TabIndex = 0;
			this->grpBx1_PowerSettings->TabStop = false;
			this->grpBx1_PowerSettings->Text = L"Power and output settings";
			// 
			// chckBox4_ChnlsOFFload
			// 
			this->chckBox4_ChnlsOFFload->AutoSize = true;
			this->chckBox4_ChnlsOFFload->Enabled = false;
			this->chckBox4_ChnlsOFFload->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chckBox4_ChnlsOFFload->ForeColor = System::Drawing::Color::White;
			this->chckBox4_ChnlsOFFload->Location = System::Drawing::Point(18, 97);
			this->chckBox4_ChnlsOFFload->Name = L"chckBox4_ChnlsOFFload";
			this->chckBox4_ChnlsOFFload->Size = System::Drawing::Size(237, 17);
			this->chckBox4_ChnlsOFFload->TabIndex = 3;
			this->chckBox4_ChnlsOFFload->Text = L"Switch all channels OFF on loading data files";
			this->chckBox4_ChnlsOFFload->UseVisualStyleBackColor = true;
			// 
			// chckBx3_ChnlsOFFend
			// 
			this->chckBx3_ChnlsOFFend->AutoSize = true;
			this->chckBx3_ChnlsOFFend->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chckBx3_ChnlsOFFend->ForeColor = System::Drawing::Color::White;
			this->chckBx3_ChnlsOFFend->Location = System::Drawing::Point(18, 74);
			this->chckBx3_ChnlsOFFend->Name = L"chckBx3_ChnlsOFFend";
			this->chckBx3_ChnlsOFFend->Size = System::Drawing::Size(176, 17);
			this->chckBx3_ChnlsOFFend->TabIndex = 2;
			this->chckBx3_ChnlsOFFend->Text = L"Switch all channels OFF on end";
			this->chckBx3_ChnlsOFFend->UseVisualStyleBackColor = true;
			// 
			// chckBx2_ChnlsOFF
			// 
			this->chckBx2_ChnlsOFF->AutoSize = true;
			this->chckBx2_ChnlsOFF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chckBx2_ChnlsOFF->ForeColor = System::Drawing::Color::White;
			this->chckBx2_ChnlsOFF->Location = System::Drawing::Point(18, 51);
			this->chckBx2_ChnlsOFF->Name = L"chckBx2_ChnlsOFF";
			this->chckBx2_ChnlsOFF->Size = System::Drawing::Size(178, 17);
			this->chckBx2_ChnlsOFF->TabIndex = 1;
			this->chckBx2_ChnlsOFF->Text = L"Switch all channels OFF on start";
			this->chckBx2_ChnlsOFF->UseVisualStyleBackColor = true;
			// 
			// chckBx1MainSwitch
			// 
			this->chckBx1MainSwitch->AutoSize = true;
			this->chckBx1MainSwitch->Enabled = false;
			this->chckBx1MainSwitch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chckBx1MainSwitch->ForeColor = System::Drawing::Color::White;
			this->chckBx1MainSwitch->Location = System::Drawing::Point(18, 28);
			this->chckBx1MainSwitch->Name = L"chckBx1MainSwitch";
			this->chckBx1MainSwitch->Size = System::Drawing::Size(164, 17);
			this->chckBx1MainSwitch->TabIndex = 0;
			this->chckBx1MainSwitch->Text = L"Main switch OFF on host end";
			this->chckBx1MainSwitch->UseVisualStyleBackColor = true;
			// 
			// grpBx2_Out_Settings
			// 
			this->grpBx2_Out_Settings->Controls->Add(this->lbl4_Crr_FR);
			this->grpBx2_Out_Settings->Controls->Add(this->lbl3_Crr_RR);
			this->grpBx2_Out_Settings->Controls->Add(this->lbl2_Vlt_FR);
			this->grpBx2_Out_Settings->Controls->Add(this->lbl1_Vlt_RR);
			this->grpBx2_Out_Settings->Controls->Add(this->txtBx4_Crr_FR);
			this->grpBx2_Out_Settings->Controls->Add(this->txtBx3_Crr_RR);
			this->grpBx2_Out_Settings->Controls->Add(this->txtBx2_Vlt_FR);
			this->grpBx2_Out_Settings->Controls->Add(this->txtBx1_VltRire);
			this->grpBx2_Out_Settings->ForeColor = System::Drawing::Color::White;
			this->grpBx2_Out_Settings->Location = System::Drawing::Point(12, 160);
			this->grpBx2_Out_Settings->Name = L"grpBx2_Out_Settings";
			this->grpBx2_Out_Settings->Size = System::Drawing::Size(254, 167);
			this->grpBx2_Out_Settings->TabIndex = 1;
			this->grpBx2_Out_Settings->TabStop = false;
			this->grpBx2_Out_Settings->Text = L"Output default settings";
			// 
			// lbl4_Crr_FR
			// 
			this->lbl4_Crr_FR->AutoSize = true;
			this->lbl4_Crr_FR->Enabled = false;
			this->lbl4_Crr_FR->ForeColor = System::Drawing::Color::White;
			this->lbl4_Crr_FR->Location = System::Drawing::Point(10, 124);
			this->lbl4_Crr_FR->Name = L"lbl4_Crr_FR";
			this->lbl4_Crr_FR->Size = System::Drawing::Size(112, 13);
			this->lbl4_Crr_FR->TabIndex = 1;
			this->lbl4_Crr_FR->Text = L"Current Fall Rate [A/s]";
			// 
			// lbl3_Crr_RR
			// 
			this->lbl3_Crr_RR->AutoSize = true;
			this->lbl3_Crr_RR->Enabled = false;
			this->lbl3_Crr_RR->ForeColor = System::Drawing::Color::White;
			this->lbl3_Crr_RR->Location = System::Drawing::Point(10, 94);
			this->lbl3_Crr_RR->Name = L"lbl3_Crr_RR";
			this->lbl3_Crr_RR->Size = System::Drawing::Size(117, 13);
			this->lbl3_Crr_RR->TabIndex = 1;
			this->lbl3_Crr_RR->Text = L"Current Rise Rate [A/s]";
			// 
			// lbl2_Vlt_FR
			// 
			this->lbl2_Vlt_FR->AutoSize = true;
			this->lbl2_Vlt_FR->Enabled = false;
			this->lbl2_Vlt_FR->ForeColor = System::Drawing::Color::White;
			this->lbl2_Vlt_FR->Location = System::Drawing::Point(10, 66);
			this->lbl2_Vlt_FR->Name = L"lbl2_Vlt_FR";
			this->lbl2_Vlt_FR->Size = System::Drawing::Size(114, 13);
			this->lbl2_Vlt_FR->TabIndex = 1;
			this->lbl2_Vlt_FR->Text = L"Voltage Fall Rate [V/s]";
			// 
			// lbl1_Vlt_RR
			// 
			this->lbl1_Vlt_RR->AutoSize = true;
			this->lbl1_Vlt_RR->Enabled = false;
			this->lbl1_Vlt_RR->ForeColor = System::Drawing::Color::White;
			this->lbl1_Vlt_RR->Location = System::Drawing::Point(10, 38);
			this->lbl1_Vlt_RR->Name = L"lbl1_Vlt_RR";
			this->lbl1_Vlt_RR->Size = System::Drawing::Size(119, 13);
			this->lbl1_Vlt_RR->TabIndex = 1;
			this->lbl1_Vlt_RR->Text = L"Voltage Rise Rate [V/s]";
			// 
			// txtBx4_Crr_FR
			// 
			this->txtBx4_Crr_FR->Enabled = false;
			this->txtBx4_Crr_FR->Location = System::Drawing::Point(133, 121);
			this->txtBx4_Crr_FR->Name = L"txtBx4_Crr_FR";
			this->txtBx4_Crr_FR->Size = System::Drawing::Size(92, 20);
			this->txtBx4_Crr_FR->TabIndex = 7;
			this->txtBx4_Crr_FR->Text = L"1.000";
			// 
			// txtBx3_Crr_RR
			// 
			this->txtBx3_Crr_RR->Enabled = false;
			this->txtBx3_Crr_RR->Location = System::Drawing::Point(133, 91);
			this->txtBx3_Crr_RR->Name = L"txtBx3_Crr_RR";
			this->txtBx3_Crr_RR->Size = System::Drawing::Size(92, 20);
			this->txtBx3_Crr_RR->TabIndex = 6;
			this->txtBx3_Crr_RR->Text = L"100.0";
			// 
			// txtBx2_Vlt_FR
			// 
			this->txtBx2_Vlt_FR->Enabled = false;
			this->txtBx2_Vlt_FR->Location = System::Drawing::Point(133, 63);
			this->txtBx2_Vlt_FR->Name = L"txtBx2_Vlt_FR";
			this->txtBx2_Vlt_FR->Size = System::Drawing::Size(92, 20);
			this->txtBx2_Vlt_FR->TabIndex = 5;
			this->txtBx2_Vlt_FR->Text = L"1.000";
			// 
			// txtBx1_VltRire
			// 
			this->txtBx1_VltRire->Enabled = false;
			this->txtBx1_VltRire->Location = System::Drawing::Point(133, 35);
			this->txtBx1_VltRire->Name = L"txtBx1_VltRire";
			this->txtBx1_VltRire->Size = System::Drawing::Size(92, 20);
			this->txtBx1_VltRire->TabIndex = 4;
			this->txtBx1_VltRire->Text = L"100.0";
			// 
			// grpBx3
			// 
			this->grpBx3->BackColor = System::Drawing::Color::Black;
			this->grpBx3->Controls->Add(this->label3);
			this->grpBx3->Controls->Add(this->label2);
			this->grpBx3->Controls->Add(this->label1);
			this->grpBx3->Controls->Add(this->label4);
			this->grpBx3->Controls->Add(this->textBox3);
			this->grpBx3->Controls->Add(this->textBox4);
			this->grpBx3->ForeColor = System::Drawing::SystemColors::Window;
			this->grpBx3->Location = System::Drawing::Point(12, 338);
			this->grpBx3->Name = L"grpBx3";
			this->grpBx3->Size = System::Drawing::Size(254, 81);
			this->grpBx3->TabIndex = 1;
			this->grpBx3->TabStop = false;
			this->grpBx3->Text = L"Output default settings";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(200, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Volt";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(107, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"+";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(86, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(15, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"%";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(8, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(131, 14);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Max. allowed deviation";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(133, 51);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(61, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"1.000";
			this->textBox3->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &GlobalSettingsForm::TextBox3_Enter);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(39, 51);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(45, 20);
			this->textBox4->TabIndex = 8;
			this->textBox4->Text = L"1.0000";
			this->textBox4->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &GlobalSettingsForm::TextBox4_Enter);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(12, 429);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(254, 57);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Output default settings";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Enabled = false;
			this->numericUpDown1->Location = System::Drawing::Point(186, 18);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(57, 20);
			this->numericUpDown1->TabIndex = 11;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8080, 0, 0, 0 });
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Enabled = false;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->ForeColor = System::Drawing::Color::White;
			this->checkBox1->Location = System::Drawing::Point(12, 19);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(89, 17);
			this->checkBox1->TabIndex = 10;
			this->checkBox1->Text = L"Server active";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Enabled = false;
			this->label6->ForeColor = System::Drawing::SystemColors::MenuText;
			this->label6->Location = System::Drawing::Point(121, 20);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Server port";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(286, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(254, 81);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Network settings";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Enabled = false;
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(8, 26);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(151, 13);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Read/Wrte access community";
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(6, 51);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(242, 20);
			this->textBox2->TabIndex = 12;
			this->textBox2->Text = L"guru";
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::Black;
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->numericUpDown3);
			this->groupBox3->Controls->Add(this->numericUpDown2);
			this->groupBox3->Controls->Add(this->checkBox2);
			this->groupBox3->ForeColor = System::Drawing::Color::White;
			this->groupBox3->Location = System::Drawing::Point(286, 109);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(254, 93);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Output default settings";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(8, 60);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(141, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Default logging interval (sec)";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(157, 58);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3600, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(86, 20);
			this->numericUpDown3->TabIndex = 15;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Enabled = false;
			this->numericUpDown2->Location = System::Drawing::Point(157, 21);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15000, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(86, 20);
			this->numericUpDown2->TabIndex = 14;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8080, 0, 0, 0 });
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Enabled = false;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox2->ForeColor = System::Drawing::Color::White;
			this->checkBox2->Location = System::Drawing::Point(12, 22);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(125, 17);
			this->checkBox2->TabIndex = 13;
			this->checkBox2->Text = L"Active main fan (rpm)";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::Color::Black;
			this->groupBox4->Controls->Add(this->btn1_SlctDir);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->textBox1);
			this->groupBox4->Controls->Add(this->checkBox3);
			this->groupBox4->ForeColor = System::Drawing::Color::White;
			this->groupBox4->Location = System::Drawing::Point(286, 220);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(254, 157);
			this->groupBox4->TabIndex = 1;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Files and folders";
			// 
			// btn1_SlctDir
			// 
			this->btn1_SlctDir->ForeColor = System::Drawing::SystemColors::MenuText;
			this->btn1_SlctDir->Location = System::Drawing::Point(6, 79);
			this->btn1_SlctDir->Name = L"btn1_SlctDir";
			this->btn1_SlctDir->Size = System::Drawing::Size(242, 26);
			this->btn1_SlctDir->TabIndex = 17;
			this->btn1_SlctDir->Text = L"Select directory";
			this->btn1_SlctDir->UseVisualStyleBackColor = true;
			this->btn1_SlctDir->Click += gcnew System::EventHandler(this, &GlobalSettingsForm::Btn1_SlctDir_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Enabled = false;
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(9, 31);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(108, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Default data directory";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(6, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(242, 20);
			this->textBox1->TabIndex = 16;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Enabled = false;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox3->ForeColor = System::Drawing::Color::White;
			this->checkBox3->Location = System::Drawing::Point(11, 123);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(192, 17);
			this->checkBox3->TabIndex = 18;
			this->checkBox3->Text = L"Reload last loaded script on startup";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// btn2_Ok
			// 
			this->btn2_Ok->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn2_Ok->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btn2_Ok->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btn2_Ok->Location = System::Drawing::Point(313, 454);
			this->btn2_Ok->Name = L"btn2_Ok";
			this->btn2_Ok->Size = System::Drawing::Size(110, 26);
			this->btn2_Ok->TabIndex = 19;
			this->btn2_Ok->Text = L"Ok";
			this->btn2_Ok->UseVisualStyleBackColor = false;
			this->btn2_Ok->Click += gcnew System::EventHandler(this, &GlobalSettingsForm::Btn2_Ok_Click);
			// 
			// btn3_Cancel
			// 
			this->btn3_Cancel->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn3_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn3_Cancel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btn3_Cancel->Location = System::Drawing::Point(430, 454);
			this->btn3_Cancel->Name = L"btn3_Cancel";
			this->btn3_Cancel->Size = System::Drawing::Size(110, 26);
			this->btn3_Cancel->TabIndex = 20;
			this->btn3_Cancel->Text = L"Cancel";
			this->btn3_Cancel->UseVisualStyleBackColor = false;
			// 
			// GlobalSettingsForm
			// 
			this->AcceptButton = this->btn2_Ok;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->CancelButton = this->btn3_Cancel;
			this->ClientSize = System::Drawing::Size(552, 492);
			this->Controls->Add(this->btn3_Cancel);
			this->Controls->Add(this->btn2_Ok);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->grpBx3);
			this->Controls->Add(this->grpBx2_Out_Settings);
			this->Controls->Add(this->grpBx1_PowerSettings);
			this->Name = L"GlobalSettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GlobalSettingsForm";
			this->Load += gcnew System::EventHandler(this, &GlobalSettingsForm::GlobalSettingsForm_Load);
			this->grpBx1_PowerSettings->ResumeLayout(false);
			this->grpBx1_PowerSettings->PerformLayout();
			this->grpBx2_Out_Settings->ResumeLayout(false);
			this->grpBx2_Out_Settings->PerformLayout();
			this->grpBx3->ResumeLayout(false);
			this->grpBx3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
//	
// Voltage percentage setting
private: System::Void TextBox4_Enter(System::Object^ sender, System::Windows::Forms::KeyEventArgs^) {
	
	if (textBox4->Text != nullptr) {
		Double val;
		if (!Double::TryParse(textBox4->Text, val)) {
			MessageBox::Show("Entry wasn't numeric");
			return;
		}
		if ((val > 5) || (val < 0)) {
			textBox4->Text = PercentageDefaultValue;
		}
		else {
			NewPercentage = val/100.0;
			this->textBox4->Modified = true;
		}
	}
}
//	
// Voltage deviation allowed setting
private: System::Void TextBox3_Enter(System::Object^ sender, System::Windows::Forms::KeyEventArgs^) {
	
	if (textBox3->Text != nullptr) {
		Double val;
		if (!Double::TryParse(textBox3->Text, val)) {
			MessageBox::Show("Entry wasn't numeric");
			return;
		}
		if ((val > 15) || (val < 0)) {
			textBox3->Text = PercentageDefaultValue;
		}
		else {
			NewAdditionalVoltError = val;
			this->textBox3->Modified = true;
		}
	}
}
private: System::Void Btn2_Ok_Click(System::Object^ sender, System::EventArgs^ e) {
	this->btn2_Ok->DialogResult = System::Windows::Forms::DialogResult::OK;
	m_RecordingTime = System::Convert::ToUInt16(this->numericUpDown3->Value);
	this->m_SwitchAllCnlsOffAtStart = this->chckBx2_ChnlsOFF->Checked;
	this->m_SwitchAllCnlsOffAtEnd = this->chckBx3_ChnlsOFFend->Checked;
}
private: System::Void GlobalSettingsForm_Load(System::Object^ sender, System::EventArgs^ e) {
	/*for each (Control ^ ctrl in this->grpBx1_PowerSettings->Controls) {
		ctrl->Enabled = true;
		ctrl->ForeColor = System::Drawing::SystemColors::Window;
		ctrl->Enabled = false;
	}*/
	this->ActiveControl = this->btn3_Cancel;
	this->numericUpDown3->Value = m_RecordingTime;
	this->textBox1->Text = this->PathName;
	this->chckBx2_ChnlsOFF->Checked = this->m_SwitchAllCnlsOffAtStart;
	this->chckBx3_ChnlsOFFend->Checked = this->m_SwitchAllCnlsOffAtEnd;
}
private: System::Void Btn1_SlctDir_Click(System::Object^ sender, System::EventArgs^ e) {
	FolderBrowserDialog^ savePathDialog = gcnew FolderBrowserDialog;

	if (savePathDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->PathName = savePathDialog->SelectedPath + "\\";
		this->textBox1->Text = this->PathName;
	}
}
};
}
