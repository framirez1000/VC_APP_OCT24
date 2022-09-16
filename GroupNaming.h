#pragma once

namespace ListTest_CLI_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GroupNaming
	/// </summary>
	public ref class GroupNaming : public System::Windows::Forms::Form
	{
	public:
		GroupNaming(void)
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
		~GroupNaming()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::ListView^ listView1;
	protected:
	public: System::Windows::Forms::ListView^ listView2;

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Enabled = false;
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->GridLines = true;
			this->listView1->HoverSelection = true;
			this->listView1->Location = System::Drawing::Point(50, 96);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(243, 439);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Tile;
			// 
			// listView2
			// 
			this->listView2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView2->FullRowSelect = true;
			this->listView2->GridLines = true;
			this->listView2->HoverSelection = true;
			this->listView2->LabelEdit = true;
			this->listView2->Location = System::Drawing::Point(379, 96);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(248, 439);
			this->listView2->TabIndex = 0;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Tile;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(108, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Actual group names";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(447, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"New group names";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(111, 588);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 24);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Apply changes";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GroupNaming::Button1_Click);
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Location = System::Drawing::Point(433, 588);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(151, 24);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// GroupNaming
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->CancelButton = this->button2;
			this->ClientSize = System::Drawing::Size(655, 634);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listView2);
			this->Controls->Add(this->listView1);
			this->Name = L"GroupNaming";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GroupNaming";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
	}
};
}
