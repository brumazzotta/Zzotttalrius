#include "otpch.h"
#include "race.h"
#include <algorithm>

bool Races::loadDefaults()
{
	racesMap.clear();

	// IDs chosen arbitrarily — keep consistent usage in your code/config.
	racesMap.emplace(static_cast<uint16_t>(RACE_HUMAN), Race(static_cast<uint16_t>(RACE_HUMAN)));
	racesMap[static_cast<uint16_t>(RACE_HUMAN)].name = "Human";
	racesMap[static_cast<uint16_t>(RACE_HUMAN)].description = "Versatile and adaptable.";

	racesMap.emplace(static_cast<uint16_t>(RACE_ORC), Race(static_cast<uint16_t>(RACE_ORC)));
	racesMap[static_cast<uint16_t>(RACE_ORC)].name = "Orc";
	racesMap[static_cast<uint16_t>(RACE_ORC)].description = "Strong and hardy.";

	racesMap.emplace(static_cast<uint16_t>(RACE_DWARF), Race(static_cast<uint16_t>(RACE_DWARF)));
	racesMap[static_cast<uint16_t>(RACE_DWARF)].name = "Dwarf";
	racesMap[static_cast<uint16_t>(RACE_DWARF)].description = "Stout miners and craftsmen.";

	racesMap.emplace(static_cast<uint16_t>(RACE_ELF), Race(static_cast<uint16_t>(RACE_ELF)));
	racesMap[static_cast<uint16_t>(RACE_ELF)].name = "Elf";
	racesMap[static_cast<uint16_t>(RACE_ELF)].description = "Agile and magically attuned.";

	racesMap.emplace(static_cast<uint16_t>(RACE_MINOTAUR), Race(static_cast<uint16_t>(RACE_MINOTAUR)));
	racesMap[static_cast<uint16_t>(RACE_MINOTAUR)].name = "Minotaur";
	racesMap[static_cast<uint16_t>(RACE_MINOTAUR)].description = "Powerful and intimidating.";

	return true;
}

Race* Races::getRace(uint16_t id)
{
	auto it = racesMap.find(id);
	if (it == racesMap.end()) {
		return nullptr;
	}
	return &it->second;
}

int32_t Races::getRaceId(const std::string& name) const
{
	for (const auto& it : racesMap) {
		if (strcasecmp(it.second.getName().c_str(), name.c_str()) == 0) {
			return static_cast<int32_t>(it.first);
		}
	}
	return -1;
}