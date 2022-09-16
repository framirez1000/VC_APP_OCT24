#include "pch.h"
#include "CnfChnl.h"

//System::Boolean ListTest_CLI_Project::CnfChnl::ValidateSP(String^ spValue, String^ nomVltg, double lowLimitFactor, double highLimitFactor)
//{
//	Double val;
//	if (!Double::TryParse(spValue, val)) {
//		return false;// return false to make undo on textBox
//	}
//	else {
//		Double val2 = System::Convert::ToDouble(nomVltg);
//		if (val2 < 0) {
//			val2 *= -1;
//			val *= -1;
//		}
//		if (IN_LIMITS((double)val, lowLimitFactor * (double)val2, highLimitFactor * (double)val2)
//			&& (val2 != 0)) { // value Ok
//			return true;
//		}
//	}
//	return true;
//}
