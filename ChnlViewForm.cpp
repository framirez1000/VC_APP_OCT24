#include "pch.h"
#include "ChnlViewForm.h"

Double ListTest_CLI_Project::ChnlViewForm::GetFormulaEvaluation(String^ formula, String^  target)
{
	String^ strReadOut = gcnew String("");
	String^ strSP = gcnew String("");
	int index = 0;
	for each (String ^ chnlName in m_pChnlViewNames) {
		if (formula->Contains(chnlName)) {
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
		}
		index++;
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
