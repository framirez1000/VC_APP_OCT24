#pragma once
#include "XML_ViewSettingsConf_Class.h"
using namespace System;

private ref class EntityPredicate {
	String^ SearchListItem;
public:
	EntityPredicate(String^ SearchTermIn) {
		SearchListItem = SearchTermIn;
	}
	bool Matched(String^ CompareEntity) {
		return CompareEntity == SearchListItem;
	}
	bool CrateMatched(XML_Classes::Crate^ CompareEntity) {
		return CompareEntity->CrateName == SearchListItem;
	}
	bool CrateMatchedObj(Crate^ ItemToCompare) {
		return (ItemToCompare->Name == SearchListItem);
	}
	bool ModMatchedObj(Module^ ItemToCompare) {
		return (ItemToCompare->Name == SearchListItem);
	}
	bool ChnlMatchedObj(Channel^ ItemToCompare) {
		return (ItemToCompare->Name == SearchListItem);
	}
	// 02/13/22
	bool ChnlMatchedObj(XML_Classes::Channel^ ItemToCompare) {
		return (ItemToCompare->ChannelName == SearchListItem);
	}
};