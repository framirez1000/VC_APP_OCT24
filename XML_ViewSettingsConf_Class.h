#pragma once
#include <cliext/list>
#include <list>
//#include "GlobalsHeader.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;
using namespace System::IO;
using namespace System::Runtime::Serialization;

namespace XML_Classes {
	[Serializable]
	public ref class Group{
	public:
		String^ GroupName;
		Group() {
			GroupName = gcnew String("");
		};
	};
	[Serializable]
	public ref class Groups {
	public:
		List<XML_Classes::Group^>^ GroupsList;
		Groups() {
			GroupsList = gcnew List<XML_Classes::Group^>;
		}
	};
	[Serializable]
	public ref class Channel
	{
	public:
		property int ChnlType;     // 0: Virtual, 1: Normal/Physical
		[XmlAttribute("col")]
		property int col;
		[XmlAttribute("row")]
		property int row;
		property System::Drawing::Color ChnlColor;
		property String^ ChannelName;
		property int CrateDir;
		property int CrateLine;
		property int ModDir;
		property int ChnlDir;
		property bool Visible;
		property bool LoggingChnl;
		property int Col;
		property int Row;
		property String^ Active;
		property String^ Color;
		property String^ State;
		property String^ CurrentFall;
		property String^ CurrentRise;
		property String^ VoltageFall;
		property String^ VoltageRise;
		property String^ VoltageFormula;
		property String^ CurrentFormula;
		property bool UseCurrentFormula;
		property bool UseVoltageFormula;
		property String^ NominalPower;
		property String^ PowerControl;
		property String^ LimitCurrent;
		property String^ LimitVoltage;
		property String^ CurrentSet;
		property String^ VoltageSet;
		property String^ NomCurrent;
		property String^ NomVoltage;
		property String^ Group;
		property String^ ViewName;
		property int units; // 0:kilo, 1:regular, 2:milli, 3:micro
		property String^ VoltRampLimit;
		
	public:
		Channel() {
			ViewName    = gcnew String("N/A");
			ChannelName = gcnew String("N/A");
			Group = gcnew String("-");
			NomVoltage = gcnew String("N/A");
			NomCurrent = gcnew String("N/A");
			PowerControl = gcnew String("N/A");
			NominalPower = gcnew String("N/A");
			UseCurrentFormula = false;
			UseVoltageFormula = false;
			CurrentFormula = gcnew String(" ");
			VoltageFormula = gcnew String(" ");
			VoltageRise = gcnew String("N/A");
			VoltageFall = gcnew String("N/A");
			CurrentRise = gcnew String("N/A");
			CurrentFall = gcnew String("N/A");
			VoltageSet = gcnew String("N/A");
			CurrentSet = gcnew String("N/A");
			LimitVoltage = gcnew String("1000.0");
			LimitCurrent = gcnew String("100.0");
			State = gcnew String("N/A");
			Color = gcnew String("-984833");
			Active = gcnew String("N/A");
			Row               = -1;
			Col               = -1;
			Visible           = false;;
			LoggingChnl       = false;
			CrateDir          = -1;
			CrateLine         = -1;
			ModDir            = -1;
			ChnlDir           = -1;
			ChnlColor = System::Drawing::Color::AliceBlue;
			ChnlType          = 1;
			VoltRampLimit = gcnew String("100");
		};
		void cpyData(XML_Classes::Channel^ chnl){
			ViewName          = chnl->ViewName;
			ChannelName       = chnl->ChannelName;
			Group             = chnl->Group;
			NomVoltage        = chnl->NomVoltage;
			NomCurrent        = chnl->NomCurrent;
			PowerControl      = chnl->PowerControl;
			NominalPower      = chnl->NominalPower;
			UseCurrentFormula = chnl->UseCurrentFormula;
			UseVoltageFormula = chnl->UseVoltageFormula;
			CurrentFormula    = chnl->CurrentFormula;
			VoltageFormula    = chnl->VoltageFormula;
			VoltageRise       = chnl->VoltageRise;
			VoltageFall       = chnl->VoltageFall;
			CurrentRise       = chnl->CurrentRise;
			CurrentFall       = chnl->CurrentFall;
			VoltageSet        = chnl->VoltageSet;
			CurrentSet        = chnl->CurrentSet;
			LimitVoltage      = chnl->LimitVoltage;
			LimitCurrent      = chnl->LimitCurrent;
			State             = chnl->State;
			Color             = chnl->Color;
			Active            = chnl->Active;
			Row               = chnl->Row;
			Col               = chnl->Col;
			Visible           = chnl->Visible;
			LoggingChnl       = chnl->LoggingChnl;
			CrateDir          = chnl->CrateDir;
			CrateLine         = chnl->CrateLine;
			ModDir            = chnl->ModDir;
			ChnlDir           = chnl->ChnlDir;
			ChnlColor         = chnl->ChnlColor;
			ChnlType          = chnl->ChnlType;
			LimitVoltage      = (ChnlType == 0) ? "1000": chnl->LimitVoltage;
			units			  = 1; // normal Amp OR Volts
			VoltRampLimit     = chnl->VoltRampLimit;
		}
		String^ GetCrateName()
		{
			// TODO: insert return statement here
			System::Array^ strArray = ChannelName->Split(':');
			return (System::Convert::ToString(strArray->GetValue(0)) + ":" + System::Convert::ToString(strArray->GetValue(1)));
		}
		String^ GetModName()
		{
			// TODO: insert return statement here
			System::Array^ strArray = ChannelName->Split(':');
			if (strArray->Length > 3)
			return (System::Convert::ToString(strArray->GetValue(0)) 
				+ ":" + System::Convert::ToString(strArray->GetValue(1))
				+ ":" + System::Convert::ToString(strArray->GetValue(2))
				+ ":" + System::Convert::ToString(strArray->GetValue(3)));
		}
	};
	[Serializable]
	public ref class Channels
	{
	public:
		List<XML_Classes::Channel^>^ ChannelsList;
		Channels(){
			ChannelsList = gcnew List<XML_Classes::Channel^>;
		}
	};
	[Serializable]
	public ref class Crate
	{
	public:
		property String^ CrateName;
		Crate() {
			CrateName = gcnew String("");
		}
	};
	[Serializable]
	public ref class Data
	{
	public:
		property Groups^ ViewGroups;
		property Channels^ channels;
		property Double PercentageDeviationAllow;
		property Double VoltgDeviationAllow;
		property int TimeToRecordData;
		property String^ FilePathAndName;
		property bool SwitchAllChnlsOffAtStart;
		property bool SwitchAllChnlsOffAtEnd;
		property int SelectedRows;
		property int SelectedCols;
		property List<Crate^>^ CrateList;
		
		
		Data(){
			SelectedRows = 0;
			SelectedCols = 1;
			TimeToRecordData = 5;
			FilePathAndName = gcnew String("C:\\ProgramData\\VoltageControllerNew\\LOG\\dataFile.csv");
			SwitchAllChnlsOffAtStart = false;
			SwitchAllChnlsOffAtEnd = false;
			channels = gcnew Channels;
			CrateList = gcnew List<Crate^>;
			ViewGroups = gcnew Groups();
		}
	};
	[Serializable]
	public ref class VC_XML
	{
	public:
		XML_Classes::Data^ data;
		property String^ Mark;
		VC_XML(){
			Mark = "test";
			data = gcnew Data();
		}
	};
	[Serializable]
	public ref class CratesList
	{
	public:
		property List<Crate^>^ CrateList;
		CratesList() {
			CrateList = gcnew List<Crate^>;
		}
	};
}