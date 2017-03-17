// Collection content:
// {number of units, sprite offset on texture, unused},
// {unit const, unit sprite offset, speed, range}

static const int hjmuArmyList[3][4] = {
	{2, 1},
	{HJMU_SOLDIER_UNIT, 1, 3, 4},
	{HJMU_HEAVY_UNIT, 0, 2, 6}
};

static const int mechsArmyList[3][4] = {
	{2, 3},
	{MECHS_SOLDIER_UNIT, 1, 3, 4},
	{MECHS_HEAVY_UNIT, 0, 2, 6}
};

static const int fedsArmyList[3][4] = {
	{2, 2},
	{FEDS_SOLDIER_UNIT, 1, 3, 4},
	{FEDS_HEAVY_UNIT, 0, 2, 6}
};