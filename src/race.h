/**
 * Simple Race container following the Vocations pattern.
 */

#ifndef FS_RACE_H_9A8C5E3D8BA44F7AAE6A8B1C2E3D4F5A
#define FS_RACE_H_9A8C5E3D8BA44F7AAE6A8B1C2E3D4F5A

#include "enums.h"
#include <map>
#include <string>

class Race
{
public:
	explicit Race(uint16_t id) : id(id) {}

	const std::string& getName() const { return name; }
	const std::string& getDescription() const { return description; }
	uint16_t getId() const { return id; }

protected:
	friend class Races;

	std::string name = "none";
	std::string description;
	uint16_t id = 0;
};

class Races
{
public:
	// lightweight loader that creates a few default races (no XML parser dependency here).
	bool loadDefaults();

	Race* getRace(uint16_t id);
	int32_t getRaceId(const std::string& name) const;

private:
	std::map<uint16_t, Race> racesMap;
};

#endif