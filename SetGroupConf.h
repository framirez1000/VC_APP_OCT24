#pragma once

namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SetGroupConf
	/// </summary>
	public ref class SetGroupConf : public System::Windows::Forms::Form
	{
	public:
		SetGroupConf(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SetGroupConf()
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
			this->SuspendLayout();
			// 
			// SetGroupConf
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(451, 540);
			this->Name = L"SetGroupConf";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"SetGroupConf";
			this->Load += gcnew System::EventHandler(this, &SetGroupConf::SetGroupConf_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SetGroupConf_Load(System::Object^ sender, System::EventArgs^ e) {
		int posX = 60, deltaX = 240;
		int posY = 30, deltaY = 45;
		int i = 0;
		//for each (String ^ group in m_pGroupNames) {
		//	// Create ON button
		//	Button^ btnOn = gcnew System::Windows::Forms::Button();
		//	btnOn->Location = System::Drawing::Point(posX, posY);
		//	btnOn->Name = L"ON";
		//	btnOn->Size = System::Drawing::Size(146, 30);
		//	btnOn->TabIndex = 0;
		//	btnOn->Text = group;
		//	btnOn->UseVisualStyleBackColor = true;
		//	btnOn->Visible = true;
		//	btnOn->Enabled = true;
		//	btnOn->Click += gcnew System::EventHandler(this, &SetStateByGroup::btnOnOff_Click);
		//	this->Controls->Add(btnOn);

		//	// Create OFF button
		//	Button^ btnOff = gcnew System::Windows::Forms::Button();
		//	btnOff->Location = System::Drawing::Point(posX + deltaX, posY);
		//	btnOff->Name = L"OFF";
		//	btnOff->Size = System::Drawing::Size(146, 30);
		//	btnOff->TabIndex = 0;
		//	btnOff->Text = group;
		//	btnOff->UseVisualStyleBackColor = true;
		//	btnOff->Visible = true;
		//	btnOff->Enabled = true;
		//	btnOff->Click += gcnew System::EventHandler(this, &SetStateByGroup::btnOnOff_Click);
		//	this->Controls->Add(btnOff);
		//	posY += deltaY;
		//}
	}
	};
}
