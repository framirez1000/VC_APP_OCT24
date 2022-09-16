#pragma once
ref class SlctChnlClass : public System::Windows::Forms::ContainerControl
{
public:
	System::Windows::Forms::Label^ lbl_ModChnl;
	System::Windows::Forms::RadioButton^ slctRadioButton;
	System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel;

	SlctChnlClass(void) {
		lbl_ModChnl = (gcnew System::Windows::Forms::Label());
		slctRadioButton = (gcnew System::Windows::Forms::RadioButton());
		tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());

		lbl_ModChnl->Text = "Test";
		lbl_ModChnl->AutoSize = true;
		lbl_ModChnl->Location = System::Drawing::Point(5, 140);
		lbl_ModChnl->Name = L"label11";
		lbl_ModChnl->Size = System::Drawing::Size(70, 30);
		lbl_ModChnl->TabIndex = 0;
		lbl_ModChnl->Text = L"Mod 11 Chnl 00";
		lbl_ModChnl->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		lbl_ModChnl->BringToFront();
		lbl_ModChnl->Visible = true;
		lbl_ModChnl->Enabled = true;
	}
};


