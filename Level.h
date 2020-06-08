#include <vector>

#include "GameLevel.h"
#include "Block.h"
#include "World.h"

#include "Animation/Animation.h"
#include "Character.h"
#include "Clouds.h"


class Level : public GameLevel
{
public:
	Level(bool load, wstring path = L"");
	~Level();

	void Load() override;
	void Unload() override;
	void Render() override;
	void Update() override;

	enum {
		NewSave = false,
		LoadSave = true,
	};

private:
	Character* chr;
	bool load;
	wstring path;
};