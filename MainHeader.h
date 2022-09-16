#pragma once
#ifndef MainHeader
#define MainHeader
#include "Crate.h"
#include <cliext/vector>
#include <cliext/map>
#include "SearchListPredicate.h"

#define MAX_HRW_NAME_LENGTH 50
#define NBR_DEFAULT_CRATES 1
static char DefaultHrwNames[NBR_DEFAULT_CRATES][MAX_HRW_NAME_LENGTH] = {
	"ISEG:5230225"
};

#define NBR_GROUP_NAMES 12
#define MAX_GROUP_NAME_LENGTH 50
static char DefaultGroups[NBR_GROUP_NAMES][MAX_GROUP_NAME_LENGTH] = {
	{"Group A"},
	{"Group B" },
	{"Group C"},
	{"Group D"},
	{"Group E"},
	{"Group F"},
	{"Group G"},
	{"Group H"},
	{"Group I"},
	{"Group J"},
	{"Group K"},
	{"Group L"}
};



ref struct RegCmdStruct_T {
public:
	int row;
	int col;
	bool scanned;
	Double vValue;
	Double iValue;
	Double temperature;
	String^ onStateValue;
	String^ isVoltageRamp;
	String^ isEmergency;
	String^ isTrip;
	String^ isVoltageLimit;
	RegCmdStruct_T() {
		row = col = -1;
		scanned = false;
		onStateValue = gcnew String("");
		isVoltageRamp = gcnew String("");
		isEmergency = gcnew String("");
		isTrip = gcnew String("");
		isVoltageLimit = gcnew String("");
	}
};
typedef cliext::map<String^, RegCmdStruct_T^> FreqCmdsMapTable_T;

ref struct CratesT {
	List<Crate^>^ ptrMainCrateList;
	List<XML_Classes::Channel^>^ pMainCnfView;
	int nbrRows, nbrColumns;
	cli::array<StatusBarMsgT^>^ m_StatusBarMsgsArray;
	
	String^ GetChnlVoltMeas(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->VoltageMeasure;
		return nullptr;
	}
	String^ GetChnlCrrntMeas(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->CurrentMeasure;
		return nullptr;
	}
	String^ GetChnlNomVolt(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->VoltageNominal;
		return nullptr;
	}
	String^ GetChnlVoltSet(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->VoltageSet;
		return nullptr;
	}
	String^ GetChnlVoltRamp(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->VltgRamp;
		return nullptr;
	}
	String^ GetChnlNomCrrnt(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->CurrentNominal;
		return nullptr;
	}
	String^ GetNominalValueSet(String^ chnl, String^ target) {
		if (target->Contains("Voltage")) return GetChnlNomVolt(chnl);
		if (target->Contains("Current")) return GetChnlNomCrrnt(chnl);
	}
	String^ GetChnlCrrntSet(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->CurrentSet;
		return nullptr;
	}
	String^ GetChnlCrrntRamp(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->CrrntRamp;
		return nullptr;
	}
	bool GetChnlEnableStatus(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->Enable;
		return false;
	}
	bool GetChnlConnectedStatus(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return (true);
		return false;
	}
	Channel^ GetChnlObj(String^ chnl){
		
		if (!String::IsNullOrEmpty(chnl)) {
			System::Array^ strArray = chnl->Split(':');
			if (strArray->Length > 4) {
				Crate^ foundCrateItem = GetCrate(System::Convert::ToString(strArray->GetValue(0))
					+ ":"
					+ System::Convert::ToString(strArray->GetValue(1)));
				if (foundCrateItem != nullptr) {
					Module^ foundModItem = GetMod(System::Convert::ToString(strArray->GetValue(0))
						+ ":"
						+ System::Convert::ToString(strArray->GetValue(1))
						+ ":"
						+ System::Convert::ToString(strArray->GetValue(2))
						+ ":"
						+ System::Convert::ToString(strArray->GetValue(3)),
						foundCrateItem);
					if (foundModItem != nullptr) {
						Channel^ foundChnlItem = GetChnl(System::Convert::ToString(strArray->GetValue(0))
							+ ":"
							+ System::Convert::ToString(strArray->GetValue(1))
							+ ":"
							+ System::Convert::ToString(strArray->GetValue(2))
							+ ":"
							+ System::Convert::ToString(strArray->GetValue(3))
							+ ":"
							+ System::Convert::ToString(strArray->GetValue(4)),
							foundModItem);
						return foundChnlItem;
					}
				}
			}
		}
		return nullptr;
	}
	Crate^ GetCrate(String^ strCrate) {
		EntityPredicate^ searchItem;
		searchItem = gcnew EntityPredicate(strCrate);
		Crate^ crate = gcnew Crate;
		crate = ptrMainCrateList->Find(gcnew Predicate<Crate^>(searchItem, &EntityPredicate::CrateMatchedObj));
		return crate;
	}
	Module^ GetMod(String^ strMod, Crate^ crate) {
		EntityPredicate^ searchItem;
		searchItem = gcnew EntityPredicate(strMod);
		Module^ mod = gcnew Module;
		mod = crate->m_lstModules->Find(gcnew Predicate<Module^>(searchItem, &EntityPredicate::ModMatchedObj));
		return mod;
	}
	Channel^ GetChnl(String^ strChnl, Module^ mod) {
		EntityPredicate^ searchItem;
		searchItem = gcnew EntityPredicate(strChnl);
		Channel^ chnl = gcnew Channel;
		chnl = mod->lstChannels->Find(gcnew Predicate<Channel^>(searchItem, &EntityPredicate::ChnlMatchedObj));
		return chnl;
	}
	int GetChnlType(String^ chnl) {
		Channel^ chnlFound = GetChnlObj(chnl);
		if (chnlFound != nullptr) return chnlFound->ChnlType;
		return -1;
	}
};

#endif
