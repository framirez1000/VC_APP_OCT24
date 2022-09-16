#pragma once
#include "DeviceCommonInfo.h"
#include "Channel.h"

using namespace System::Collections;

ref class Module :
	public DeviceCommonInfo
{
private:
	int m_channels, m_count, m_modNumberId;
	String^ m_VoltageLimit;
	String^ m_VoltageLimitNegative;
	String^ m_CurrentLimit;
	String^ m_Temperature;
	String^ m_DigitalFilter;
	String^ m_VltgRamp;
	String^ m_CrrntRamp;
	cliext::vector<Double> voltageMeasurements;
	cliext::vector<Double> currentMeasurements;
	cliext::vector<String^> isOnStatus;

public:
	List<Channel^>^ lstChannels;
	
public:
	/* Constructors */
	Module::Module() {
		Name = gcnew String("");
		Address = gcnew String("");
		Enable = false;
		Connected = false;
		Channels = 0;
		lstChannels = gcnew List<Channel^>;
		voltageMeasurements = gcnew cliext::vector<Double>(16);
		voltageMeasurements.assign(16, 0.0);
		currentMeasurements = gcnew cliext::vector<Double>(16);
		currentMeasurements.assign(16, 0.0);
		isOnStatus = gcnew cliext::vector<String^>(16);
		isOnStatus.assign(16, "");
		pModCmdsTableId = gcnew CmdsId;
	}
	Module::Module(System::Collections::ICollection ^defaultChannels) {
		Channels = defaultChannels->Count;
		lstChannels = gcnew List<Channel^>;
		voltageMeasurements = gcnew cliext::vector<Double>(16);
		voltageMeasurements.assign(16, 0.0);
		currentMeasurements = gcnew cliext::vector<Double>(16);
		currentMeasurements.assign(16, 0.0);
		isOnStatus = gcnew cliext::vector<String^>(16);
		isOnStatus.assign(16, "");
		pModCmdsTableId = gcnew CmdsId;
	}
	
	/* Properties */
	property int Channels {
		int get() { return m_channels; }
		void set(int channelsValue) { if ((channelsValue > 0) && (channelsValue < MAX_CHANNELS)) m_channels = channelsValue; }
	}
	property String^ VoltageLimit {
		String^ get() { return m_VoltageLimit; }
		void set(String^ channelsValue) { m_VoltageLimit = channelsValue; }
	}
	property String^ VoltageLimitNegative {
		String^ get() { return m_VoltageLimitNegative; }
		void set(String^ channelsValue) { m_VoltageLimitNegative = channelsValue; }
	}
	property String^ CurrentLimit {
		String^ get() { return m_CurrentLimit; }
		void set(String^ channelsValue) { m_CurrentLimit = channelsValue; }
	}
	property String^ Temperature {
		String^ get() { return m_Temperature; }
		void set(String^ channelsValue) { m_Temperature = channelsValue; }
	}
	property String^ DigitalFilter {
		String^ get() { return m_DigitalFilter; }
		void set(String^ channelsValue) { m_DigitalFilter = channelsValue; }
	}
	property String^ VoltageRamp {
		String^ get() { return m_VltgRamp; }
		void set(String^ vltgRamp) { m_VltgRamp = vltgRamp; }
	}
	property String^ CurrentRamp {
		String^ get() { return m_CrrntRamp; }
		void set(String^ crrntRamp) { m_CrrntRamp = crrntRamp; }
	}
	property CmdsId^ pModCmdsTableId;
};

