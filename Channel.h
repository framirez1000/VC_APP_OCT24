#pragma once
#include "DeviceCommonInfo.h"
#include "GlobalsHeader.h"
#include "C:\Epics\base-3.16.2\include\cadef.h"

using namespace System;

ref class Channel :
	public DeviceCommonInfo
{
	double voltage, current, voltSetPointValue, currentSetPointValue;
	String^ error;
	CmdsId^  m_pChnlCmdsTableId;
	
public: Channel(){
		Name = gcnew String("");
		Address = gcnew String("");
		Enable = false;
		Connected = false;
		m_pChnlCmdsTableId = gcnew CmdsId;
	}
public: 
	Channel(String^ nameValue, String^ dirValue) {
		Name = gcnew String(nameValue);
		Address = gcnew String(dirValue);
		Enable = false;
		Connected = false;
	}

public:
	property int ChnlType;
	property String^ VoltageMeasure;
	property String^ CurrentMeasure;
	property String^ VoltageNominal;
	property String^ CurrentNominal;
	property String^ IsOn;
	property String^ TemperatureExternal;
	property String^ ControlSetOn;
	property String^ VoltageSet;
	property String^ CurrentSet;
	property String^ VoltageBounds;
	property String^ CurrentBounds;
	property String^ VctCoefficient;
	property String^ DelayedTripTime;
	property String^ InputError;
	property String^ isVoltageRamp;
	property String^ isEmergency;
	property String^ isCC;
	property String^ isCV;
	property String^ isCurrentBound;
	property String^ isVoltageBound;
	property String^ isExternalInhibit;
	property String^ isTrip;
	property String^ isCurrentLimit;
	property String^ isVoltageLimit;
	property String^ EventInputError;
	property String^ EOn2Off;
	property String^ EventEndOfRamp;
	property String^ EventEmergency;
	property String^ ECC;
	property String^ ECV;
	property String^ ECurrentBounds;
	property String^ EVVoltageBounds;
	property String^ EventExternalInhibit;
	property String^ EventTrip;
	property String^ EventCurrentLimit;
	property String^ EventVoltageLimit;
	property String^ VltgRamp;
	property String^ CrrntRamp;
	property String^ MaxVoltSP;
	property String^ MaxCurrntSP;

	property double Voltage {
		double get() { return voltage; }
	}
	property double Current {
		double get() { return current; }
	}
	property double VoltSetPointValue {
		double get() { return voltSetPointValue; }
	}
	property double CurrentSetPointValue {
		double get() { return currentSetPointValue; }
	}
	property CmdsId^ ChnlCmdsTableId {
		CmdsId^ get() {	return m_pChnlCmdsTableId; }
		void set(CmdsId^ TableId) {
			m_pChnlCmdsTableId = TableId;
		}
	}
	
};

