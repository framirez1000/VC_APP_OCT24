#include "pch.h"
#include "ChnlViewForm.h"
#pragma once
#ifndef SEM_H
#include "CommsShMemPipesClass.h"
#endif

//
// Validate user direct inputs for Voltage and current Set Points
System::Void ListTest_CLI_Project::ChnlViewForm::ValidateSetPointInputs() {
	if ((!m_cmdMsg->execRequest && (m_mainDataStruct->GetChnlEnableStatus(this->ChnlCnf->ChannelName)))
		|| (this->ChnlCnf->ChnlType == 0)) { // ChnlType 0: Virtual channels
		m_cmdMsg->CleanCmdsLists();
		String^ spValue = gcnew String(txtBx1_VoltSPChnlView->Text);
		// Validate user entry for VoltageSet or CurrentSet and change setting in Crate if ok
		if (txtBx1_VoltSPChnlView->Modified && !(String::IsNullOrEmpty(spValue))) {
			//Process user input: "value units", example: 3.2 mV Or 3.2 uV
			int unitsIn;
			if (ProcessSPvalStrUserInput(spValue, &unitsIn, true)) { // Check if input string is valid, param3 true for volt
				Double val = System::Convert::ToDouble(spValue);
				spValue = ConvertUnits(val, unitsIn, 1); // Converting to Amp from any (mAmp, uAmp)
			// Convert to numerical value and validate ranges
				if (GlobalFuncValidateSP(spValue, this->ChnlCnf->LimitVoltage, 0.0, 1.0)) {
					///*m_mainDataStruct->GetChnlNomVolt(this->ChnlCnf->ChannelName)*/, 0.0, 1.0)) {
					SemClass cmdsSem;
					if ((this->ChnlCnf->ChnlType != 0) && cmdsSem.GetSem(CMDS_SEM)) {
						m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":VoltageSet",
							spValue, CHANNEL_CMD, 3, false);
						cmdsSem.ReleaseSem();
					}
					else {
						// Set VChnl Voltage SP to Channel user input
						this->ChnlCnf->VoltageSet = spValue;
						this->vSetPoint = System::Convert::ToDouble(spValue);
						this->UpdateCnfChnlList(this->ChnlCnf->ChannelName, "", "", "", this->ChnlCnf->UseVoltageFormula, spValue);
					}
				}
				else {
					m_cmdMsg->StatusBarMsgIndex = 16;
					txtBx1_VoltSPChnlView->Undo();
				}
			}
		}

		spValue = txtBx2_CurrtSPChnlView->Text;
		if (txtBx2_CurrtSPChnlView->Modified && !(String::IsNullOrEmpty(spValue))) {
			//Process user input: "value units", example: 3.2 mA Or 3.2 uA
			int unitsIn;
			if (ProcessSPvalStrUserInput(spValue, &unitsIn, false)) { // param3 false for current
				Double val = System::Convert::ToDouble(spValue);
				spValue = ConvertUnits(val, unitsIn, 1); // Converting to Amp from any (mAmp, uAmp)

				// Convert to numerical value and validate ranges
				if (GlobalFuncValidateSP(spValue, this->ChnlCnf->LimitCurrent, 0.0, 1.0)) {
					//m_mainDataStruct->GetChnlNomCrrnt(this->ChnlCnf->ChannelName), 0.0, 1.0)) {
					SemClass cmdsSem;
					if ((this->ChnlCnf->ChnlType != 0) && cmdsSem.GetSem(CMDS_SEM)) {
						m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":CurrentSet",
							spValue, CHANNEL_CMD, 3, false);
						cmdsSem.ReleaseSem();
					}
					else {
						// Set VChnl Current SP to Channel user input
						this->ChnlCnf->CurrentSet = spValue;
						this->cSetPoint = System::Convert::ToDouble(spValue);
					}
				}
				else {
					m_cmdMsg->StatusBarMsgIndex = 16;
					txtBx2_CurrtSPChnlView->Undo();
				}
			}
		}
		SemClass cmdsSem;
		if (cmdsSem.GetSem(CMDS_SEM)) {
			if (m_cmdMsg->strCmdsToExcList->Count > 0)
				m_cmdMsg->GlobalAddSendCmds("", "", -1, 3, true);
			cmdsSem.ReleaseSem();
		}
		if ((m_ptrMainCrateList->Count > 0) && (this->ChnlCnf->ChnlType != 0)) {
			// ToDo here: Check with Crate S/N to update properly
			String^ readoutValue(m_mainDataStruct->GetChnlVoltSet(this->ChnlCnf->ChannelName));
			this->txtBx1_VoltSPChnlView->Text = readoutValue;
			this->ChnlCnf->VoltageSet = readoutValue;
			this->vSetPoint = System::Convert::ToDouble(readoutValue);
			readoutValue = m_mainDataStruct->GetChnlCrrntSet(this->ChnlCnf->ChannelName);
			this->txtBx2_CurrtSPChnlView->Text = readoutValue;
			this->ChnlCnf->CurrentSet = readoutValue;
			this->cSetPoint = System::Convert::ToDouble(readoutValue);
		}
	}
	else {
		MessageBox::Show("Channel not connected or System busy with other cmd");
		if (txtBx1_VoltSPChnlView->Modified) txtBx1_VoltSPChnlView->Undo();
		if (txtBx2_CurrtSPChnlView->Modified) txtBx2_CurrtSPChnlView->Undo();
	}
	txtBx1_VoltSPChnlView->Modified = false;
	txtBx2_CurrtSPChnlView->Modified = false;
}
//
// Open Chnl Conf settings Form (Chnl name, formulas, Ramp & set points Limits) and check OK return
System::Void ListTest_CLI_Project::ChnlViewForm::Btn2_CfgChnlView_Click(System::Object^ sender, System::EventArgs^ e) {
	CnfChnl^ cnfChannel = gcnew CnfChnl(m_mainDataStruct, m_pGroupNames, m_pChnlViewNames);

	cnfChannel->CrateDir = this->ChnlCnf->CrateDir;
	cnfChannel->ChnlName = this->ChnlCnf->ChannelName;
	cnfChannel->ModDir = this->ChnlCnf->ModDir;
	cnfChannel->ChnlDir = this->ChnlCnf->ChnlDir;
	cnfChannel->VoltSP_Limit = this->ChnlCnf->LimitVoltage;
	cnfChannel->CrrntSP_Limit = this->ChnlCnf->LimitCurrent;
	cnfChannel->lbl1_CnfChnl->Text = this->ChnlCnf->ViewName;
	cnfChannel->txtBx1_NewChnlName->Text = this->ChnlCnf->ViewName; // 02/09/24
	cnfChannel->Group = this->ChnlCnf->Group;
	cnfChannel->UseVoltageFormula = this->ChnlCnf->UseVoltageFormula;
	cnfChannel->UseCurrentFormula = this->ChnlCnf->UseCurrentFormula;
	// Changes on 05/12/22
	cnfChannel->vSetPoint = this->ChnlCnf->VoltageSet;
	cnfChannel->cSetPoint = this->ChnlCnf->CurrentSet;
	//m_mainDataStruct.pMainCnfView
	// Save the last formula and compare to new one, if different then clear chnlNamesFormList
	String^ actualFormula = gcnew String(this->ChnlCnf->VoltageFormula);
	if (this->ChnlCnf->ChnlType != 0) {
		cnfChannel->nominalVolt = m_mainDataStruct->GetChnlNomVolt(this->ChnlCnf->ChannelName);
		cnfChannel->nominalCurrent = m_mainDataStruct->GetChnlNomCrrnt(this->ChnlCnf->ChannelName);
	}
	else {
		cnfChannel->nominalVolt = this->ChnlCnf->LimitVoltage;
		cnfChannel->nominalCurrent = this->ChnlCnf->LimitCurrent;
	}

	//if (this->ChnlCnf->UseVoltageFormula) { // Commented out 02/09/24
		cnfChannel->formula = this->ChnlCnf->VoltageFormula;
	//} // Commented out 02/09/24
	if (this->ChnlCnf->UseCurrentFormula) {
		cnfChannel->iformula = this->ChnlCnf->CurrentFormula;
	}

	cnfChannel->NameIndex = this->formulaChnlIndex;
	if (this->ChnlCnf->Group != nullptr) {
		cnfChannel->cmbBx1_SwtGrp->SelectedIndex = cnfChannel->cmbBx1_SwtGrp->FindStringExact(this->ChnlCnf->Group);
		cnfChannel->cmbBx1_SwtGrp->Text = this->ChnlCnf->Group;
	}

	if (cnfChannel->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// Open the form that gets user inputs for voltage/current Ramp Set Points/formulas
		if (((m_ptrMainCrateList->Count > 0) && (m_mainDataStruct->GetChnlConnectedStatus(this->ChnlCnf->ChannelName)) || this->ChnlCnf->ChnlType == 0)) {
			if (this->ChnlCnf->ChnlType != 0) this->txtBx1_VoltSPChnlView->Text = m_mainDataStruct->GetChnlVoltSet(this->ChnlCnf->ChannelName);
			Double val;
			Double::TryParse(this->txtBx1_VoltSPChnlView->Text, val);
			this->vSetPoint = val;

			// Evaluate Voltage Formula
			if (actualFormula != cnfChannel->formula) chnlNamePosInViewTable.clear(); // 2024
			if (cnfChannel->chkBx1_UseFormuVltg->Checked) {
				if ((cnfChannel->formula != nullptr) && (cnfChannel->formula != "")) {
					// Evaluate expression/formula from the user input
					this->ChnlCnf->UseVoltageFormula = true;
					this->ChnlCnf->VoltageFormula = cnfChannel->formula;
					GetformEvalAtRamp(cnfChannel->formula);
					if (cnfChannel->NameIndex >= 0 && ChnlCnf->ChnlType != 0) { /////??????
						vSetPoint = GetFormulaEvaluation(cnfChannel->formula, "Voltage");
						if (GlobalFuncValidateSP(vSetPoint.ToString(),
							m_mainDataStruct->GetChnlNomVolt(this->ChnlCnf->ChannelName), 0.0, 1.0)) 
						{
							SemClass cmdsSem;
							if ((this->ChnlCnf->ChnlType != 0) && cmdsSem.GetSem(CMDS_SEM)) {
								m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":VoltageSet",
									vSetPoint.ToString(), CHANNEL_CMD, 3, true);
								cmdsSem.ReleaseSem();
							}
							/*m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":VoltageSet",
								vSetPoint.ToString(), CHANNEL_CMD, 3, true);*/
						}
						else m_cmdMsg->StatusBarMsgIndex = 15;
					}
				}
			}
			this->txtBx1_VoltSPChnlView->Enabled = !this->ChnlCnf->UseVoltageFormula;

			// For current formula
			if (this->ChnlCnf->ChnlType != 0) this->txtBx2_CurrtSPChnlView->Text = m_mainDataStruct->GetChnlCrrntSet(this->ChnlCnf->ChannelName);
			Double::TryParse(this->txtBx2_CurrtSPChnlView->Text, val);
			this->cSetPoint = val;
			if (cnfChannel->chkBx2_UseCrrtFrm->Checked) {
				if ((cnfChannel->iformula != nullptr) && (cnfChannel->iformula != "")) {
					// Evaluate expression/formula from the user input
					this->ChnlCnf->UseCurrentFormula = true;
					this->ChnlCnf->CurrentFormula = cnfChannel->iformula;
					//GetformEvalAtRamp(cnfChannel->iformula);
					if (cnfChannel->NameIndex >= 0) { /////??????
						cSetPoint = GetFormulaEvaluation(cnfChannel->iformula, "Current");
						if (GlobalFuncValidateSP(cSetPoint.ToString(),
							m_mainDataStruct->GetChnlNomCrrnt(this->ChnlCnf->ChannelName), 0.0, 1.0)) 
						{
							SemClass cmdsSem;
							if ((this->ChnlCnf->ChnlType != 0) && cmdsSem.GetSem(CMDS_SEM)) {
								m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":CurrentSet",
									cSetPoint.ToString(), CHANNEL_CMD, 3, true);
								cmdsSem.ReleaseSem();
							}
							/*m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":CurrentSet",
								cSetPoint.ToString(), CHANNEL_CMD, 3, true);*/
						}
						else m_cmdMsg->StatusBarMsgIndex = 15;
					}
				}
			}
			this->txtBx2_CurrtSPChnlView->Enabled = !this->ChnlCnf->UseCurrentFormula;

		}

		// If Voltage Ramp Limit changed
		if (cnfChannel->VoltRampLimit != this->ChnlCnf->VoltRampLimit) {
			this->ChnlCnf->VoltRampLimit = cnfChannel->VoltRampLimit;
			XML_Classes::Channel^ chnl = m_mainDataStruct->GetChnlInView(System::Convert::ToString(this->ChnlCnf->ChannelName), m_mainDataStruct->pMainCnfView);
			if (chnl != nullptr) chnl->VoltRampLimit = cnfChannel->VoltRampLimit;
		}
		// If Channel name changed update view and NamesList
		String^ formerName = cnfChannel->ChnlName;
		if (!String::IsNullOrEmpty(cnfChannel->txtBx1_NewChnlName->Text)) {
			String^ newName = gcnew String(cnfChannel->txtBx1_NewChnlName->Text);
			if (!newName->Equals(ChnlCnf->ViewName)) {
				this->myNameChanged = true;

				// Search ChnlName in NamesList and change both (SetPoint name and currentValueName _U)
				int index = m_pChnlViewNames->IndexOf(this->ChnlCnf->ViewName + "_");
				if (index != -1) {
					formerName = cnfChannel->ChnlName;
					// Update Config Channel List for the modified channel so changes are avaliable for UserViewChanges // 30/09/2024
					//this->UpdateCnfChnlList(formerName->TrimEnd('_'), cnfChannel->formula, cnfChannel->txtBx1_NewChnlName->Text, this->ChnlCnf->LimitVoltage, this->ChnlCnf->UseVoltageFormula, this->txtBx1_VoltSPChnlView->Text);
					m_pChnlViewNames[index] = cnfChannel->txtBx1_NewChnlName->Text + "_";
					m_pChnlViewNames[index + 1] = cnfChannel->txtBx1_NewChnlName->Text + "_U";
				}
				auto it = myPtrFreqCmds->find(this->ChnlCnf->ChannelName);
				if (it != myPtrFreqCmds->end()) {
					FreqCmdsMapTable_T::generic_value gcval = *it;
					gcval->second->chnlViewName = cnfChannel->txtBx1_NewChnlName->Text;
				}
				this->ChnlCnf->ViewName = cnfChannel->txtBx1_NewChnlName->Text;
				this->lbl2_NameChnlView->Text = cnfChannel->txtBx1_NewChnlName->Text;
				
				// Iterate through ChnlsViewList and clear all data struct for Form Eval
				for each (ChnlViewForm^ chnl in ChnlsViewList) {
					if (chnl->ChnlCnf->UseVoltageFormula) chnl->chnlNamePosInViewTable.clear();
				}
				// Set reload Comm Data for external comm
				SemClass cmdsSem;
				if ((this->ChnlCnf->ChnlType != 0) && cmdsSem.GetSem(CMDS_SEM)) {
					m_cmdMsg->nameChanged = true;					
					cmdsSem.ReleaseSem();
				}
			}
		}
		
		Object^ selectedItem = cnfChannel->cmbBx1_SwtGrp->SelectedItem;
		if (cnfChannel->cmbBx1_SwtGrp->SelectedItem != nullptr) {
			this->ChnlCnf->Group = selectedItem->ToString();
			this->lbl_GroupName->Text = selectedItem->ToString();
		}
		// If SP limits changed
		if (cnfChannel->VoltSP_Limit != this->ChnlCnf->LimitVoltage) {
			this->ChnlCnf->LimitVoltage = cnfChannel->VoltSP_Limit;
			XML_Classes::Channel^ chnl = m_mainDataStruct->GetChnlInView(System::Convert::ToString(this->ChnlCnf->ChannelName), m_mainDataStruct->pMainCnfView);
			if (chnl != nullptr) chnl->LimitVoltage = cnfChannel->VoltSP_Limit;
		}
		if (cnfChannel->CrrntSP_Limit != this->ChnlCnf->LimitCurrent) {
			this->ChnlCnf->LimitCurrent = cnfChannel->CrrntSP_Limit;
			XML_Classes::Channel^ chnl = m_mainDataStruct->GetChnlInView(System::Convert::ToString(this->ChnlCnf->ChannelName), m_mainDataStruct->pMainCnfView);
			if (chnl != nullptr) chnl->LimitCurrent = cnfChannel->CrrntSP_Limit;
		}

		// Update Config Channel List for the modified channel so changes are avaliable for UserViewChanges
		// 30/09/2024
		// this->UpdateCnfChnlList(formerName, cnfChannel->formula, this->ChnlCnf->ViewName, this->ChnlCnf->LimitVoltage);
		this->UpdateCnfChnlList(formerName->TrimEnd('_'), cnfChannel->formula, cnfChannel->txtBx1_NewChnlName->Text, this->ChnlCnf->LimitVoltage, this->ChnlCnf->UseVoltageFormula, this->txtBx1_VoltSPChnlView->Text);
	} // Ok: end
	if (m_cmdMsg->cmdExecuted && m_cmdMsg->HrwConntd && (this->ChnlCnf->ChnlType != 0)) {
		this->txtBx1_VoltSPChnlView->Text = m_mainDataStruct->GetChnlVoltSet(this->ChnlCnf->ChannelName);
		this->vSetPoint = System::Convert::ToDouble(this->txtBx1_VoltSPChnlView->Text);
		this->txtBx2_CurrtSPChnlView->Text = m_mainDataStruct->GetChnlCrrntSet(this->ChnlCnf->ChannelName);
		this->vSetPoint = System::Convert::ToDouble(this->txtBx2_CurrtSPChnlView->Text);
		this->ChnlCnf->VoltageRise = m_mainDataStruct->GetChnlVoltRamp(this->ChnlCnf->ChannelName);
		this->ChnlCnf->VoltageFall = m_mainDataStruct->GetChnlVoltRamp(this->ChnlCnf->ChannelName);
		this->ChnlCnf->CurrentRise = m_mainDataStruct->GetChnlCrrntRamp(this->ChnlCnf->ChannelName);
		this->ChnlCnf->CurrentFall = m_mainDataStruct->GetChnlCrrntRamp(this->ChnlCnf->ChannelName);
	}
	else if (this->ChnlCnf->ChnlType == 0) {
		// Changes on 05/12/22
		Double val;
		if (Double::TryParse(this->txtBx1_VoltSPChnlView->Text, val)) {
			this->vSetPoint = System::Convert::ToDouble(this->txtBx1_VoltSPChnlView->Text);
		}
		if (Double::TryParse(this->txtBx2_CurrtSPChnlView->Text, val)) {
			this->cSetPoint = System::Convert::ToDouble(this->txtBx2_CurrtSPChnlView->Text);
		}
	}

	this->ChnlCnf->UseVoltageFormula = cnfChannel->UseVoltageFormula;
	this->txtBx1_VoltSPChnlView->Enabled = true;
	if (this->ChnlCnf->UseVoltageFormula) {
		this->ChnlCnf->VoltageFormula = cnfChannel->formula;
		this->txtBx1_VoltSPChnlView->Enabled = false;
	}
	this->ChnlCnf->UseCurrentFormula = cnfChannel->UseCurrentFormula;
	this->txtBx2_CurrtSPChnlView->Enabled = true;
	if (this->ChnlCnf->UseCurrentFormula) {
		this->ChnlCnf->CurrentFormula = cnfChannel->iformula;
		this->txtBx2_CurrtSPChnlView->Enabled = false;
	}
	this->txtBx1_VoltSPChnlView->ForeColor = System::Drawing::Color::White;

	
} // End of Btn2_CfgChnlView_Click

//
// Set ON/OFF channels individually
	System::Void ListTest_CLI_Project::ChnlViewForm::Btn1_ChnlView_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!m_cmdMsg->execRequest && m_cmdMsg->HrwConntd && (this->ChnlCnf->ChnlType != 0)) {
			m_cmdMsg->CleanCmdsLists();
			String^ strParam = gcnew String("false");
			if (m_cmdMsg->HrwConntd) {
				if (this->ChnlCnf->State->Contains("off"))
				//if (this->lbl1_StatusChnlView->Text != "ON") 
					strParam = "true";
				
				SemClass cmdsSem;
				if (cmdsSem.GetSem(CMDS_SEM)) {
					m_cmdMsg->GlobalAddSendCmds(this->ChnlCnf->ChannelName + ":Control:setOn",
						strParam, CHANNEL_CMD, 4, false);
					//Console::WriteLine("Channel {0} included to be: \n", this->ChnlCnf->ViewName);
					m_cmdMsg->StatusBarMsgIndex = 17;
					m_cmdMsg->GlobalAddSendCmds("", "", -1, 4, true);
					cmdsSem.ReleaseSem();
				}
			}
		}
	}

//
// Formula evaluation
//
	Double ListTest_CLI_Project::ChnlViewForm::GetFormulaEvaluation(String^ formula, String^  target)
{
	String^ strReadOut = gcnew String("");
	String^ strSP = gcnew String("");
	int index = 0;
	
	if (chnlNamePosInViewTable.size() != 0) {
		for each (NamePos_T::value_type pair in chnlNamePosInViewTable) {
			if (formula->IndexOf(pair->first) >= 0) {
				if (target->Contains("Voltage")) {
					strReadOut = System::Convert::ToString(this->ChnlsViewList[pair->second]->readoutsValues.voltg);
					strSP = System::Convert::ToString(this->ChnlsViewList[pair->second]->ChnlCnf->VoltageSet);
				}
				else if (target->Contains("Current")) {
					strReadOut = System::Convert::ToString(this->ChnlsViewList[pair->second]->readoutsValues.current);
					strSP = System::Convert::ToString(this->ChnlsViewList[pair->second]->ChnlCnf->CurrentSet);
				}
				formula = formula->Replace(pair->first + "U", strReadOut);
				formula = formula->Replace(pair->first, strSP);
			}
		}
	}
	else {
		for each (String ^ chnlName in m_pChnlViewNames) {
			if (formula->IndexOf(chnlName) >= 0) {
				if (target->Contains("Voltage")) {
					strReadOut = System::Convert::ToString(this->ChnlsViewList[index / 2]->readoutsValues.voltg);
					strSP = System::Convert::ToString(this->ChnlsViewList[index / 2]->ChnlCnf->VoltageSet);
				}
				else if (target->Contains("Current")) {
					strReadOut = System::Convert::ToString(this->ChnlsViewList[index / 2]->readoutsValues.current);
					strSP = System::Convert::ToString(this->ChnlsViewList[index / 2]->ChnlCnf->CurrentSet);
				}
				formula = formula->Replace(chnlName + "U", strReadOut);
				formula = formula->Replace(chnlName, strSP);
				chnlNamePosInViewTable.insert(NamePos_T::make_value(chnlName, index / 2));
			}
			
			index++;
		}
	}
	Expression^ e = gcnew Expression(formula);
	Double val = e->calculate();
	val = Math::Round(val, 5);
	//Console::WriteLine("Expression eval: {0}", val);

	return Double(val);
	
}

System::Void ListTest_CLI_Project::ChnlViewForm::GetformEvalAtRamp(String^ formula)
{
	// Iterate NamesList to check if a scanned channel was included in formula
		// to make "formula" evaluation when channel ramping
	for (int i = 1; i < this->m_pChnlViewNames->Count; i+=2) {
		if (formula->Contains(this->m_pChnlViewNames[i])) {
			evaluateFormulaAtRamping = true;
			break;
		}
	}
	return System::Void();
}

//System::Void ListTest_CLI_Project::ChnlViewForm::Btn2_CfgChnlView_Click(System::Object^ sender, System::EventArgs^ e)
//{
//	return System::Void();
//}

// Update Config Channel List for the modified channel so changes are avaliable for UserViewChanges
// 30/09/24 
	System::Void ListTest_CLI_Project::ChnlViewForm::UpdateCnfChnlList(String^ chnlName, String^ formula,  String^ newChnlName, String^ voltLimit, bool useVoltForm, String^ voltSP) {
		// Search channel pos in confList
		int pos = m_mainDataStruct->GetChnlCnfListPos(chnlName, m_mainDataStruct->pMainCnfView);
		
		// If found change the attribute
		if (pos >= 0) {
			if (!System::String::IsNullOrEmpty(newChnlName)) m_mainDataStruct->pMainCnfView[pos]->ViewName = newChnlName;
			if (!System::String::IsNullOrEmpty(formula)) m_mainDataStruct->pMainCnfView[pos]->VoltageFormula = formula;
			if (!System::String::IsNullOrEmpty(voltLimit)) m_mainDataStruct->pMainCnfView[pos]->LimitVoltage = voltLimit;
			m_mainDataStruct->pMainCnfView[pos]->UseVoltageFormula = useVoltForm;
			if (!System::String::IsNullOrEmpty(voltSP)) m_mainDataStruct->pMainCnfView[pos]->VoltageSet = voltSP;
		}
	}
