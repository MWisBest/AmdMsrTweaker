/*
 * Copyright (c) Martin Kinkelin
 *
 * See the "License.txt" file in the root directory for infos
 * about permitted and prohibited uses of this code.
 */

#pragma once

#include <vector>
#include "Info.h"


class Worker
{
public:

	Worker(const Info& info)
		: _info(&info)
		, _turbo(-1)
		, _apm(-1)
		, _pState(-1)
		, _NbPsi0Vid_VID(-1)
		, _boostEnAllCores(-1)
		, _ignoreBoostThresh(-1)
	{ }

	bool ParseParams(int argc, const char* argv[]);

	void ApplyChanges();


private:

	const Info* _info;
	std::vector<PStateInfo> _pStates;
	std::vector<NBPStateInfo> _nbPStates;
	int _turbo;  // enable (1)/disable (0) CPB
	int _apm;    // enable (1)/disable (0) APM
	int _pState; // hardware index of the P-state to be activated
	int _NbPsi0Vid_VID; // 
	int _boostEnAllCores;
	int _ignoreBoostThresh;
};
