#pragma once
#include "DeviceCommonInfo.h"
#include "Module.h"

using namespace System::Collections;
using namespace System::Collections::Generic;

ref class Crate :
	public DeviceCommonInfo
{
private:
	int m_CrateNumber;
	int m_ModuleNumber;
	int m_modulesNumber;
	int m_channelsNumber;
public: 
	String^ m_ptrFanSpeed;
	
public:
	List<Module^>^ m_lstModules;
	//cliext::vector <Module> lstModules;
	cliext::vector<Double> voltageMeasurements;
	cliext::vector<Double> currentMeasurements;
	cliext::vector<String^> isOnStatus;

public:
	/* Constructors */
	Crate() {
		m_lstModules = gcnew List<Module^>();
		Modules = 0;
		Name = gcnew String("");
		Address = gcnew String("");
		Enable = false;
		Connected = false;
		voltageMeasurements = gcnew cliext::vector<Double>(16);
		voltageMeasurements.assign(16, 0.0);
		currentMeasurements = gcnew cliext::vector<Double>(16);
		currentMeasurements.assign(16, 0.0);
		isOnStatus = gcnew cliext::vector<String^>(16);
		isOnStatus.assign(16, "");
		pCrateCmdsTableId = gcnew CmdsId;
	}
	Crate(String^ nameValue, String^ dirValue) {
		Name = gcnew String(nameValue);
		Address = gcnew String(dirValue);
		Enable = false;
		Connected = false;
		voltageMeasurements = gcnew cliext::vector<Double>(16);
		voltageMeasurements.assign(16, 0.0);
		currentMeasurements = gcnew cliext::vector<Double>(16);
		currentMeasurements.assign(16, 0.0);
		isOnStatus = gcnew cliext::vector<String^>(16);
		isOnStatus.assign(16, "");
		pCrateCmdsTableId = gcnew CmdsId;
	}
	Crate(System::Collections::ICollection^ defaultModules) {
		Modules = defaultModules->Count;
		m_lstModules = gcnew List<Module^>();
	}
	/* Properties */
	property int Modules {
		int get() { return m_modulesNumber; }
		void set(int modulesValue) { if ((modulesValue > 0) && (modulesValue < MAX_MODULES)) m_modulesNumber = modulesValue; }
	}
	property int Channels {
		int get() { return m_channelsNumber; }
		void set(int channelsValue) { if ((channelsValue > 0) && (channelsValue < MAX_CHANNELS_X_CRATE)) m_channelsNumber = channelsValue; }
	}
	property int CrateNumber {
		int get() { return m_CrateNumber; }
		void set(int channelsValue) { if ((channelsValue > 0) && (channelsValue < MAX_CRATES)) m_CrateNumber = channelsValue; }
	}
	property int ModuleNumber {
		int get() { return m_ModuleNumber; }
		void set(int modValue) { if ((modValue > 0) && (modValue < MAX_MODULES)) m_ModuleNumber = modValue; }
	}
	property String^ FanSpeed {
		String^ get() { return m_ptrFanSpeed; }
		void set(String^ fsValue) {
			if (fsValue != nullptr) 	m_ptrFanSpeed = fsValue;
		}
	}
	property CmdsId^ pCrateCmdsTableId;
	property int VoltChnlsEnable;

	// Inherited via DeviceCommonInfo
	/*virtual int getChildIndexPos(int adress) override;
	int getChildIndexPos(int address) override {
		int modIndex = -1;
		if ((m_lstModules != nullptr) && (address >= 0)) {
			int nbrMod = m_lstModules->Count;
			for (int i = 0; i < nbrMod; i++) {
				if (System::Convert::ToInt32(m_lstModules[i]->Address) == address) {
					modIndex = i;
					break;
				}
			}
		}
		return modIndex;
	}*/
};

