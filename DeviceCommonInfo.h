#pragma once

#include "GlobalsHeader.h"

using namespace System;
public ref class DeviceCommonInfo
{
private:
	String^ name;
	int status;
	String^ address;
	String^ m_ptrFirmwareRelease;
	String^ m_ptrFirmwareName;
	String^ m_ptrArticle;
	String^ m_ptrSerialNumber;
	String^ m_ptrPowerOn;

public:	
	/* Properties for data members */
	property String^ Name {
		String^ get() { return name; }
		void set(String^ nameValue) { if (nameValue != nullptr) 	name = nameValue; 
		}
	}
	property String^ Address {
		String^ get() { return address; }
		void set(String^ dirValue) {	if (dirValue != nullptr)	address = dirValue;
		}
	}
	property bool Enable;
	property bool Connected;
	property bool Status {
		bool get() { return status; }
		void set(bool connectedValue) { status = connectedValue; }
	}
	property String^ FirmwareRelease {
		String^ get() { return m_ptrFirmwareRelease; }
		void set(String^ firmwRlseValue) {
			if (firmwRlseValue != nullptr) 	m_ptrFirmwareRelease = firmwRlseValue;
		}
	}
	property String^ FirmwareName {
		String^ get() { return m_ptrFirmwareName; }
		void set(String^ firmwNameValue) {
			if (firmwNameValue != nullptr) 	m_ptrFirmwareName = firmwNameValue;
		}
	}
	property String^ Article {
		String^ get() { return m_ptrArticle; }
		void set(String^ articleValue) {
			if (articleValue != nullptr) 	m_ptrArticle = articleValue;
		}
	}
	property String^ SerialNumber {
		String^ get() { return m_ptrSerialNumber; }
		void set(String^ snValue) {
			if (snValue != nullptr) 	m_ptrSerialNumber = snValue;
		}
	}
	property String^ PowerOn {
		String^ get() { return m_ptrPowerOn; }
		void set(String^ poValue) {
			if (poValue != nullptr) 	m_ptrPowerOn = poValue;
		}
	}
	

};

