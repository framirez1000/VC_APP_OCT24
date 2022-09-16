#include "pch.h"
#include "SetSltnViewForm.h"
#include "ChnlSltnVForm.h"


using namespace System;
using namespace ListTest_CLI_Project;


System::Void ListTest_CLI_Project::SetSltnViewForm::drawSltnChnlView(int rows, int columns, System::Object^ Sender, System::EventArgs^ e)
{
	ChnlSltnVForm^ pChnlViewItem;
	XML_Classes::Channel^ chnlCnf;
	if (this->panel1->Controls->Count > 0) this->panel1->Controls->Clear();
	if (rows * columns != 0) {
		this->nmrcUpDown_Rows->ValueChanged -= gcnew System::EventHandler(this, &SetSltnViewForm::NmrcUpDown_Rows_ValueChanged_1);
		this->nmrcUpDown_Columns->ValueChanged -= gcnew System::EventHandler(this, &SetSltnViewForm::NmrcUpDown_Rows_ValueChanged_1);
		this->nmrcUpDown_Rows->Value = rows;
		this->nmrcUpDown_Columns->Value = columns;
		this->nmrcUpDown_Rows->ValueChanged += gcnew System::EventHandler(this, &SetSltnViewForm::NmrcUpDown_Rows_ValueChanged_1);
		this->nmrcUpDown_Columns->ValueChanged += gcnew System::EventHandler(this, &SetSltnViewForm::NmrcUpDown_Rows_ValueChanged_1);
	}
	else {
		rows=(int)this->nmrcUpDown_Rows->Value;
		columns=(int )this->nmrcUpDown_Columns->Value;
	}
	// Resize the configList with XML channel objects
	{
		int size = rows * columns;
		if (size > M_ChnlsCnfView->Count) {
			if (rows > m_nrRows) {
				size -= M_ChnlsCnfView->Count;
				for (int i = 0; i < size; i++) {
					chnlCnf = gcnew XML_Classes::Channel;
					chnlCnf->ViewName = CHANNEL_VIEW_DEFAULT_NAME;
					chnlCnf->ChnlColor = System::Drawing::Color::AliceBlue;
					chnlCnf->Color = chnlCnf->ChnlColor.ToArgb().ToString();
					M_ChnlsCnfView->Add(chnlCnf);
				}
			}
			else {
				if (columns > m_columns) {
					for (int i = 0; i < rows; i++) {
						chnlCnf = gcnew XML_Classes::Channel;
						chnlCnf->ViewName = CHANNEL_VIEW_DEFAULT_NAME;
						chnlCnf->ChnlColor = System::Drawing::Color::AliceBlue;
						chnlCnf->Color = chnlCnf->ChnlColor.ToArgb().ToString();
						M_ChnlsCnfView->Insert((i * columns) + m_columns, chnlCnf);
					}
				}
			}
		}
		else if (size < M_ChnlsCnfView->Count) {
			if (rows < m_nrRows) {
				size = M_ChnlsCnfView->Count - size;
				for (int i = 0; i < size; i++)
					M_ChnlsCnfView->RemoveAt(M_ChnlsCnfView->Count - 1);
			}
			else if (columns < m_columns) {
				List<XML_Classes::Channel^>^ pChnlsAuxList = gcnew List<XML_Classes::Channel^>;
				XML_Classes::Channel^ chnlItem;
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < m_columns; j++) {
						if (j != (m_columns - 1)) {
							chnlItem = gcnew XML_Classes::Channel;
							chnlItem = this->M_ChnlsCnfView[i * m_columns + j];
							pChnlsAuxList->Add(chnlItem);
						}
					}
				}
				this->M_ChnlsCnfView->Clear();
				this->M_ChnlsCnfView->AddRange(pChnlsAuxList->GetRange(0, pChnlsAuxList->Count));
			}
		}
	} // End new resizing
	// Draw
	for (int i = 0, tempChnlNbr = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++, tempChnlNbr++) {
			// Create all channels View Form according to nbr rows and columns
			pChnlViewItem = gcnew ChnlSltnVForm(m_mainDataStruct, this->M_ChnlsCnfView, ChnlsTaken);
			pChnlViewItem->MdiParent = this;
			pChnlViewItem->Location = System::Drawing::Point(j * 196 + 1, 126 + i * 95);
			pChnlViewItem->sltChnlbtn1->Text = this->M_ChnlsCnfView[i * columns + j]->ViewName;
			pChnlViewItem->ChnlViewName = this->M_ChnlsCnfView[i * columns + j]->ViewName;
			//pChnlViewItem->BackColor = (System::Drawing::Color) this->M_ChnlsCnfView[i * columns + j]->ChnlColor;
			pChnlViewItem->BackColor = System::Drawing::Color::FromArgb(System::Convert::ToInt32(this->M_ChnlsCnfView[i * columns + j]->Color));
			pChnlViewItem->CrateLine = this->M_ChnlsCnfView[i * columns + j]->CrateLine;
			pChnlViewItem->CrateDir = this->M_ChnlsCnfView[i * columns + j]->CrateDir;
			pChnlViewItem->ModDir = this->M_ChnlsCnfView[i * columns + j]->ModDir;
			pChnlViewItem->ChnlDir = this->M_ChnlsCnfView[i * columns + j]->ChnlDir;
			pChnlViewItem->ChnlType = this->M_ChnlsCnfView[i * columns + j]->ChnlType;
			pChnlViewItem->BringToFront();
			pChnlViewItem->Index = i * columns + j;
			this->panel1->Controls->Add(pChnlViewItem);
			pChnlViewItem->Show();
		}
	}
	m_nrRows = rows;
	m_columns = columns;
	return System::Void();
}
